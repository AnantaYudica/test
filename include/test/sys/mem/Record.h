#ifndef TEST_SYS_MEM_RECORD_H_
#define TEST_SYS_MEM_RECORD_H_

#include "rec/Node.h"
#include "rec/Iterator.h"
#include "../Definition.h"
#include "../Interface.h"
#include "../../Guard.h"
#include "block/Pointer.h"

#include <cstddef>
#include <cstdlib>
#include <mutex>
#include <utility>
#include <functional>
#include <chrono>
#include <atomic>
#include <cstring>

namespace test
{
namespace sys
{
namespace mem
{

template<typename TBlock>
class Record
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
public:
    typedef typename TBlock::TimestampType TimestampType; 
    typedef test::sys::mem::block::Pointer<TBlock> BlockPointerType;
public:
    typedef test::sys::mem::rec::Node<TBlock> NodeType;
    typedef test::sys::mem::rec::Iterator<TBlock> IteratorType;
    typedef std::function<int(NodeType*)> FindConditionFuncType;
    typedef void (*RemoveFuncType)(NodeType* node, Record<TBlock>& obj);
public:
    static constexpr int sOk = 0;
public:
    static constexpr int sRegisterOk = sOk;
    static constexpr int sRegisterWithNullPointer = -1;
    static constexpr int sRegisterDuplicatePointer = -2;
    static constexpr int sRegisterAllocationMemoryFailed = -3;
    static constexpr int sRegisterSizeOverflow = -4;
public:
    static constexpr int sUnregisterOk = sOk;
    static constexpr int sUnregisterWithNullPointer = -1;
    static constexpr int sUnregisterPointerNotFound = -2;
    static constexpr int sUnregisterFailed = -3;
private:
    static int FindCondition(void* pointer, NodeType* node);
private:
    static TBlock* ReleaseNode(NodeType* node);
private:
    static NodeType* _Find(NodeType *& head, NodeType *& tail, 
        FindConditionFuncType f);
private:
    static TBlock* MakeBlock(TBlock&& instance);
private:
    NodeType *m_head, *m_tail;
    std::size_t m_size;
    std::mutex m_lock;
public:
    Record();
public:
    Record(const Record<TBlock>&) = delete;
    Record(Record<TBlock>&&) = delete;
public:
    ~Record();
public:
    Record<TBlock>& operator=(const Record<TBlock>&) = delete;
    Record<TBlock>& operator=(Record<TBlock>&&) = delete;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
private:
    NodeType* Find(FindConditionFuncType f);
private:
    bool Insert(NodeType *node);
private:
    TBlock* Remove(NodeType* node);
    void RemoveAll();
public:
    template<typename... TArgs>
    int Register(void * pointer, TArgs&&... args);
    int Unregister(void * pointer, BlockPointerType* block = nullptr, 
        bool force = false);
    bool HasRegister(void * pointer);
public:
    std::size_t AllocationSize();
public:
    std::size_t Size();
public:
    TBlock* operator[](void * pointer);
};

template<typename TBlock>
int Record<TBlock>::FindCondition(void* pointer, NodeType* node)
{
    void* curr_ptr = (*node)->Pointer();
    if (pointer == curr_ptr)
    {
        return 0;
    }
    else if (pointer < curr_ptr)
    {
        return 1;
    }
    
    return -1;
}

template<typename TBlock>
TBlock* Record<TBlock>::ReleaseNode(NodeType* node)
{
    TBlock* block = (TBlock*)*node;
    if (block != nullptr)
    {
        *node = nullptr;
    }
    node->Next(nullptr);
    node->Prev(nullptr);
    node->~NodeType();
    free(node);
    return block;
}


template<typename TBlock>
typename Record<TBlock>::NodeType* 
Record<TBlock>::_Find(NodeType *& head, 
    NodeType *&, FindConditionFuncType f)
{
    if (f && head != nullptr)
    {
        IteratorType it{head};
        while(it != nullptr)
        {
            const auto res = f(&(*it));
            if (res == 0)
            {
                return &*it;
            }
            else if (res == 1)
            {
                ++it;
            }
            else 
            {
                break;
            }
        }
    }
    return nullptr;
}

template<typename TBlock>
TBlock* Record<TBlock>::MakeBlock(TBlock&& instance)
{
    TBlock default_block;
    TBlock* block = (TBlock*)malloc(sizeof(TBlock));
    if (block == nullptr) 
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordAllocFailed, 
            "Memory allocation is failed");
        return nullptr;
    }
    memcpy(block, (void*)&default_block, sizeof(TBlock));
    *block = std::move(instance);
    return block;
}

template<typename TBlock>
Record<TBlock>::Record() :
    m_head(nullptr),
    m_tail(nullptr),
    m_size(0),
    m_lock()
{}

template<typename TBlock>
Record<TBlock>::~Record()
{
    if (m_size > 0)
    {
        RemoveAll();
    }
}

template<typename TBlock>
typename Record<TBlock>::NodeType* 
Record<TBlock>::Find(FindConditionFuncType f)
{
    return _Find(m_head, m_tail, f);
}

template<typename TBlock>
bool Record<TBlock>::Insert(NodeType *node)
{
    if (m_head == nullptr)
    {
        m_head = m_tail = node;
        return true;
    }
    IteratorType it(m_head);
    const auto * pointer = (*node)->Pointer();
    while(it != nullptr)
    {
        auto curr = &*it;
        const auto * curr_ptr = (*curr)->Pointer();
        if (pointer > curr_ptr)
        {
            if (curr == m_head)
            {
                node->Next(m_head);
                m_head->Prev(node);
                m_head = node;
                return true;
            }
            curr->Prev()->Next(node);
            node->Prev(curr->Prev());
            curr->Prev(node);
            node->Next(curr);
            return true;
        }
        else if (curr_ptr == pointer)
        {
            return false;
        }
        ++it;
    }

    node->Prev(m_tail);
    m_tail->Next(node);
    m_tail = node;
    return true;
}

template<typename TBlock>
TBlock* Record<TBlock>::Remove(NodeType *node)
{
    if (m_head == nullptr)
    {
        return nullptr;
    }

    auto*& head = this->m_head;
    auto*& tail = this->m_tail;
    std::size_t& size = this->m_size;

    if (head == node && tail == node)
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (head == node)
    {
        head = node->Next();
        head->Prev(nullptr);
        node->Next(nullptr);
    }
    else if (tail == node)
    {
        tail = node->Prev();
        tail->Next(nullptr);
        node->Prev(nullptr);
    }
    else
    {
        NodeType* prev = node->Prev();
        NodeType* next = node->Next();   
        prev->Next(next);
        next->Prev(prev);
        node->Next(nullptr);
        node->Prev(nullptr); 
    }
    
    return ReleaseNode(node);
}

template<typename TBlock>
void Record<TBlock>::RemoveAll()
{
    NodeType * curr = m_head;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    while (curr != nullptr)
    {
        NodeType* next = curr->Next();
        BlockPointerType block_ptr{ReleaseNode(curr)};
        curr = next;
    }
}

template<typename TBlock>
template<typename... TArgs>
int Record<TBlock>::Register(void * pointer, 
    TArgs&&... args)
{
    if (pointer == nullptr)
    {
        return sRegisterWithNullPointer;
    }
    
    TBlock* block = MakeBlock(TBlock(pointer, 
        std::forward<TArgs>(args)...));
    
    if (block == nullptr)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordAllocFailed, 
            "Block Allocation is failed");
        return sRegisterAllocationMemoryFailed;
    }

    NodeType* instance = (NodeType*)malloc(sizeof(NodeType));

    if (instance == nullptr)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordAllocFailed, 
            "Node Allocation is failed");
        return sRegisterAllocationMemoryFailed;
    }

    NodeType node(block);
    memcpy(instance, (void*)&node, sizeof(NodeType));

    {
        std::lock_guard<std::mutex> guard(m_lock);

        if (!Insert(instance))
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordDuplicatePointer, 
                "Pointer(%p) registered", pointer);
            return sRegisterDuplicatePointer;
        }
        else
        {
            const auto size = m_size++;
            if (size >= m_size)
            {
                SystemType::GetInstance().Error(
                    DefinitionType::Status::sMemRecordAllocFailed, 
                    "Size Overflow");
                return sRegisterSizeOverflow;
            }
        }
    }

    return sRegisterOk;
}

template<typename TBlock>
int Record<TBlock>::Unregister(void * pointer, 
    BlockPointerType* block, bool force)
{
    if (pointer == nullptr)
    {
        return sUnregisterWithNullPointer;
    }
    {
        std::lock_guard<std::mutex> guard(m_lock);

        auto found = Find(std::bind(FindCondition, pointer, 
            std::placeholders::_1));
        if (found == nullptr)
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordPointerNotFound, 
                "Pointer(%p) not registered", pointer);
            return sUnregisterPointerNotFound;
        }

        if ((*found)->ReferenceCount() <= 1 || force)
        {
            auto* block_removed = Remove(found);
            if (block_removed == nullptr)
            {
                SystemType::GetInstance().Error(
                    DefinitionType::Status::sMemRecordPointerNotFound, 
                    "Pointer(%p) not registered", pointer);
                return sUnregisterPointerNotFound;
            }
            else
            {
                BlockPointerType block_ptr{block_removed};
                if (block != nullptr)
                {
                    *block = std::move(block_ptr);
                }
                --m_size;
            }
        }
        else
        {
            return sUnregisterFailed;
        }
    }
    return sUnregisterOk;
}

template<typename TBlock>
bool Record<TBlock>::HasRegister(void * pointer)
{
    if (pointer == nullptr)
    {
        return false;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);

    auto found = Find(std::bind(FindCondition, pointer, 
        std::placeholders::_1));
    return found != nullptr;
}

template<typename TBlock>
std::size_t Record<TBlock>::AllocationSize()
{
    std::lock_guard<std::mutex> guard(m_lock);
    return sizeof(NodeType) * m_size;
}

template<typename TBlock>
std::size_t Record<TBlock>::Size()
{
    std::lock_guard<std::mutex> guard(m_lock);
    return m_size;
}

template<typename TBlock>
TBlock* Record<TBlock>::operator[](void * pointer)
{
    if (pointer == nullptr)
    {
        return nullptr;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);
    
    auto found = Find(std::bind(FindCondition, pointer, 
        std::placeholders::_1));
    if (found == nullptr) return nullptr;
    return &**found;
}

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_RECORD_H_
