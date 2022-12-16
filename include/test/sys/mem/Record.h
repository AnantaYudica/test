#ifndef TEST_SYS_MEM_RECORD_H_
#define TEST_SYS_MEM_RECORD_H_

#include "rec/Node.h"
#include "rec/Iterator.h"
#include "../Definition.h"
#include "../Interface.h"
#include "../../Guard.h"
#include "block/Pointer.h"
#include "../Debug.h"

#include "ptr/Const.defn.h"
#include "Pointer.defn.h"

#include <cstddef>
#include <cstdlib>
#include <mutex>
#include <utility>
#include <chrono>
#include <atomic>
#include <cstring>

namespace test::sys::mem
{
template<typename TBlock>
class Record;
}

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBlock>

template<typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::sys::mem::Record", 
    test::sys::mem::Record<TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

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
    typedef test::sys::dbg::Type<test::sys::mem::Record<TBlock>> DebugType;
public:
    typedef typename TBlock::TimestampType TimestampType; 
    typedef test::sys::mem::block::Pointer<TBlock> BlockPointerType;
public:
    typedef test::sys::mem::rec::Node<TBlock> NodeType;
    typedef test::sys::mem::rec::Iterator<TBlock> IteratorType;
    template<typename T>
    using FindConditionFuncType = int(*)(T, NodeType*);
public:
    typedef test::sys::mem::Pointer<TBlock> PointerType;
    typedef test::sys::mem::ptr::Const<TBlock> PointerConstType;
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
    template<typename T>
    static int FindCondition(T pointer, NodeType* node);
private:
    static TBlock* ReleaseNode(NodeType* node);
private:
    template<typename T>
    static NodeType* _Find(NodeType *& head, NodeType *& tail, 
        FindConditionFuncType<T> f, T& pointer);
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
    template<typename T>
    NodeType* Find(FindConditionFuncType<T> f, T& pointer);
private:
    bool Insert(NodeType *node);
private:
    NodeType* Remove(NodeType* node);
private:
    TBlock* Clear(NodeType* node);
    void ClearAll();
public:
    template<typename... TArgs>
    int Register(std::function<void(TBlock*)> on_success, 
        std::function<void(int)> on_failed, 
        void * pointer, TArgs&&... args);
private:
    int Unregister(NodeType * node, BlockPointerType* block = nullptr, 
        bool force = false);
public:
    int Unregister(void * pointer, BlockPointerType* block = nullptr, 
        bool force = false);
    int Unregister(PointerType pointer, BlockPointerType* block = nullptr, 
        bool force = false);
private:
    bool HasRegister(NodeType * node);
public:
    bool HasRegister(void * pointer);
    bool HasRegister(PointerConstType pointer);
public:
    std::size_t AllocationSize();
public:
    std::size_t Size();
public:
    TBlock* operator[](void * pointer);
    TBlock* operator[](PointerType pointer);
public:
    std::size_t ForEach(std::function<void(TBlock*)> op);
private:
    void Reposition(NodeType * node);
public:
    void Reposition(void* pointer);
    void Reposition(PointerType pointer);
};

template<typename TBlock>
template<typename T>
int Record<TBlock>::FindCondition(T pointer, NodeType* node)
{
    TEST_SYS_DEBUG_T_V(SystemType, DebugType, 2, NULL, 
        "FindCondition<%s>(pointer=%s, node=%p)", 
            TEST_SYS_DEBUG_T_NAME_STR(T),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(pointer), node);

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
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "ReleaseNode(node=%p)", node);

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
template<typename T>
typename Record<TBlock>::NodeType* 
Record<TBlock>::_Find(NodeType *& head, 
    NodeType *&, FindConditionFuncType<T> f, T& pointer)
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 2, NULL, 
        "_Find<%s>(head=%p, NodeType *&, f=%p, pointer=%p)", 
            TEST_SYS_DEBUG_TARGS_NAME_STR(T), head, f, pointer);
    
    if (f && head != nullptr)
    {
        IteratorType it{head};
        while(it != nullptr)
        {
            const auto res = f(pointer, &(*it));
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
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "MakeBlock(instance=%p)", &instance);
    
    TBlock default_block;
    TBlock* block = (TBlock*)malloc(sizeof(TBlock));
    if (block == nullptr) 
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordAllocationFailed, 
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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TBlock>
Record<TBlock>::~Record()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    if (m_size > 0)
    {
        ClearAll();
    }
}

template<typename TBlock>
template<typename T>
typename Record<TBlock>::NodeType* 
Record<TBlock>::Find(FindConditionFuncType<T> f, T& pointer)
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 2, this, "Find<%s>(f=%p, pointer=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), f, pointer);

    return _Find(m_head, m_tail, f, pointer);
}

template<typename TBlock>
bool Record<TBlock>::Insert(NodeType *node)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Insert(node=%p)", node);

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
typename Record<TBlock>::NodeType* Record<TBlock>::Remove(NodeType *node)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Remove(node=%p)", node);

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
    return node;
}

template<typename TBlock>
TBlock* Record<TBlock>::Clear(NodeType *node)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Clear(node=%p)", node);

    Remove(node);

    return ReleaseNode(node);
}

template<typename TBlock>
void Record<TBlock>::ClearAll()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "ClearAll()");

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
int Record<TBlock>::Register(std::function<void(TBlock*)> on_success, 
    std::function<void(int)> on_failed, 
    void * pointer, TArgs&&... args)
{
    TEST_SYS_DEBUG_T_V(SystemType, DebugType, 2, this, 
        "Register<%s>(on_success=%p, on_failed=%p, pointer=%p, args={%s})", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...), on_success, on_failed,
        pointer, TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));

    if (pointer == nullptr)
    {
        return sRegisterWithNullPointer;
    }
    
    TBlock* block = MakeBlock(TBlock(pointer, 
        std::forward<TArgs>(args)...));
    
    if (block == nullptr)
    {
        if (on_failed)
        {
            on_failed(sRegisterAllocationMemoryFailed);
        }
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordAllocationFailed, 
            "Block Allocation is failed");
        return sRegisterAllocationMemoryFailed;
    }

    NodeType* instance = (NodeType*)malloc(sizeof(NodeType));

    if (instance == nullptr)
    {
        if (on_failed)
        {
            on_failed(sRegisterAllocationMemoryFailed);
        }
        SystemType::GetInstance().Error(
            DefinitionType::Status::sMemRecordAllocationFailed, 
            "Node Allocation is failed");
        return sRegisterAllocationMemoryFailed;
    }

    NodeType node(block);
    memcpy(instance, (void*)&node, sizeof(NodeType));

    {
        std::lock_guard<std::mutex> guard(m_lock);

        if (!Insert(instance))
        {
            if (on_failed)
            {
                on_failed(sRegisterDuplicatePointer);
            }
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
                if (on_failed)
                {
                    on_failed(sRegisterSizeOverflow);
                }
                SystemType::GetInstance().Error(
                    DefinitionType::Status::sMemRecordSizeOverflow, 
                    "Size Overflow");
                return sRegisterSizeOverflow;
            }
        }
    }

    if (on_success != nullptr)
    {   
        on_success(&*node);
    }

    return sRegisterOk;
}

template<typename TBlock>
int Record<TBlock>::Unregister(NodeType * node, 
    BlockPointerType* block, bool force)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Unregister(node=%p, block=%p, force=%s)", 
        node, block, (force?"true":"false"));
    
    if ((*node)->ReferenceCount() <= 1 || force)
    {
        auto* block_removed = Clear(node);
        if (block_removed == nullptr)
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordPointerNotFound, 
                "Pointer(%p) not registered", (*node)->Pointer());
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
    
    return sUnregisterOk;
}

template<typename TBlock>
int Record<TBlock>::Unregister(void * pointer, 
    BlockPointerType* block, bool force)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Unregister(pointer=%p, block=%p, force=%s)", 
        pointer, block, (force?"true":"false"));

    if (pointer == nullptr)
    {
        return sUnregisterWithNullPointer;
    }
    int res = sUnregisterOk;
    {
        std::lock_guard<std::mutex> guard(m_lock);

        auto found = Find(&FindCondition<void*>, pointer);
        
        if (found == nullptr)
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordPointerNotFound, 
                "Pointer(%p) not registered", pointer);
            return sUnregisterPointerNotFound;
        }
        res = Unregister(found , block, force);
    }
    return res;
}

template<typename TBlock>
int Record<TBlock>::Unregister(PointerType pointer, 
    BlockPointerType* block, bool force)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Unregister(pointer=%p, block=%p, force=%s)", 
        pointer, block, (force?"true":"false"));

    if (pointer == nullptr)
    {
        return sUnregisterWithNullPointer;
    }
    int res = sUnregisterOk;
    {
        std::lock_guard<std::mutex> guard(m_lock);

        auto found = Find(&FindCondition<PointerType>, pointer);
        
        if (found == nullptr)
        {
            SystemType::GetInstance().Error(
                DefinitionType::Status::sMemRecordPointerNotFound, 
                "Pointer(id=%zu, size=%zu) not registered", 
                    pointer.ID(), pointer.Size());
            return sUnregisterPointerNotFound;
        }
        res = Unregister(found , block, force);
    }
    return res;
}

template<typename TBlock>
bool Record<TBlock>::HasRegister(NodeType * node)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "HasRegister(node=%p)", node);
    
    return node != nullptr;
}

template<typename TBlock>
bool Record<TBlock>::HasRegister(void * pointer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "HasRegister(pointer=%p)", pointer);

    if (pointer == nullptr)
    {
        return false;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);

    auto found = Find(&FindCondition<void*>, pointer);
    
    return HasRegister(found);
}

template<typename TBlock>
bool Record<TBlock>::HasRegister(PointerConstType pointer)
{
    TEST_SYS_DEBUG_V(SystemType, DebugType, 3, this, 
        "HasRegister(pointer=%s)", TEST_SYS_DEBUG_TARGS_VALUE_STR(pointer));

    if (pointer == nullptr)
    {
        return false;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);

    auto found = Find(&FindCondition<PointerConstType>, pointer);
    
    return HasRegister(found);
}

template<typename TBlock>
std::size_t Record<TBlock>::AllocationSize()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "AllocationSize()");
    
    std::lock_guard<std::mutex> guard(m_lock);
    std::size_t sum = (sizeof(NodeType) + sizeof(TBlock)) * m_size;

    IteratorType it(m_head);
    while(it != nullptr)
    {
        std::size_t old_sum = sum;
        sum += (*it)->FileAllocationSize();
        if (sum < old_sum)
        {
            sum = (std::size_t)-1;
        }
        ++it;
    }
    return sum;
}

template<typename TBlock>
std::size_t Record<TBlock>::Size()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size()");
    
    std::lock_guard<std::mutex> guard(m_lock);
    return m_size;
}

template<typename TBlock>
TBlock* Record<TBlock>::operator[](void * pointer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](pointer=%p)", pointer);
    
    if (pointer == nullptr)
    {
        return nullptr;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);
    
    auto found = Find(FindCondition<void*>, pointer);
    if (found == nullptr) return nullptr;
    return &**found;
}

template<typename TBlock>
TBlock* Record<TBlock>::operator[](PointerType pointer)
{
    TEST_SYS_DEBUG_V(SystemType, DebugType, 3, this, 
        "operator[](pointer=%s)", TEST_SYS_DEBUG_TARGS_VALUE_STR(pointer));
    
    if (pointer == nullptr)
    {
        return nullptr;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);
    
    auto found = Find(FindCondition<PointerType>, pointer);
    if (found == nullptr) return nullptr;
    return &**found;
}

template<typename TBlock>
std::size_t Record<TBlock>::ForEach(std::function<void(TBlock*)> op)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "ForEach(op=%p)", op);
    
    if (op == nullptr)
    {
        return 0;
    }

    std::lock_guard<std::mutex> guard(m_lock);

    std::size_t count = 0;

    IteratorType it(m_head);
    while(it != nullptr)
    {
        op((TBlock*)*it);
        ++it;
        ++count;
    }
    return count;
}

template<typename TBlock>
void Record<TBlock>::Reposition(NodeType* node)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Reposition(node=%p)", node);
        
    if (!(bool)node)
    {
        return;
    }

    if(Remove(node) == nullptr)
    {
        return;
    }

    Insert(node);
}
template<typename TBlock>
void Record<TBlock>::Reposition(void* pointer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Reposition(pointer=%p)", pointer);
    
    if (pointer == nullptr)
    {
        return;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);
    
    auto found = Find(FindCondition<void*>, pointer);

    Reposition(found);
}

template<typename TBlock>
void Record<TBlock>::Reposition(PointerType pointer)
{
    
    TEST_SYS_DEBUG_V(SystemType, DebugType, 3, this, 
        "Reposition(pointer=%s)", TEST_SYS_DEBUG_TARGS_VALUE_STR(pointer));
    
    if (pointer == nullptr)
    {
        return;
    }
    
    std::lock_guard<std::mutex> guard(m_lock);
    
    auto found = Find(FindCondition<PointerType>, pointer);
    
    Reposition(found);
}

} //!mem

} //!sys

} //!test

#ifndef TEST_SYS_MEMORY_H_

#include "ptr/Const.h"
#include "Pointer.h"

#endif //!TEST_SYS_MEMORY_H_

#endif //!TEST_SYS_MEM_RECORD_H_
