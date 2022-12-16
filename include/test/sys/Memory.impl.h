#ifndef TEST_SYS_MEMORY_H_IMPL_
#define TEST_SYS_MEMORY_H_IMPL_

#include "Memory.h"
#include "mem/ptr/Const.h"
#include "mem/Pointer.h"

namespace test
{
namespace sys
{

inline Memory& Memory::GetInstance()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "GetInstance()");
    
    static auto& dbg_mem_block_base = test::sys::dbg::Type<
        test::sys::mem::block::Base>::GetInstance();
    static auto& dbg_mem_block_fileline = test::sys::dbg::Type<
        test::sys::mem::block::FileLine>::GetInstance();
    static auto& dbg_mem_block_pointer = test::sys::dbg::Type<
        test::sys::mem::block::Pointer<BlockType>>::GetInstance();

    static auto& dbg_mem_block_ptr_const = test::sys::dbg::Type<
        test::sys::mem::ptr::Const<BlockType>>::GetInstance();

    static auto& dbg_mem_rec_node = test::sys::dbg::Type<
        test::sys::mem::rec::Node<BlockType>>::GetInstance();
    static auto& dbg_mem_rec_iterator = test::sys::dbg::Type<
        test::sys::mem::rec::Iterator<BlockType>>::GetInstance();

    static auto& dbg_mem_block = 
        test::sys::dbg::Type<BlockType>::GetInstance();
    static auto& dbg_mem_dummy = test::sys::dbg::Type<
        test::sys::mem::Dummy>::GetInstance();
    static auto& dbg_mem_pointer = test::sys::dbg::Type<
        test::sys::mem::Pointer<BlockType>>::GetInstance();
    static auto& dbg_mem_record = test::sys::dbg::Type<
        test::sys::mem::Record<BlockType>>::GetInstance();

    static Memory instance;
    return instance;
}

inline bool Memory::Deallocator(StatusIntegerType status, DataType data)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, 
        "Deallocator(status=0x%hx, data={id=%zu, pointer=%p, size=%zu})", 
            status, data.id, data.pointer, data.size);
    
    if (data.pointer != nullptr)
    {
        std::free(data.pointer);
        return true;
    }
    return false;
}

inline Memory::Memory() :
    m_countId(1),
    m_record(),
    m_lock()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Memory::~Memory()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    if (m_record.Size() != 0)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
            "Memory not clear on finalize {size=%zu}", m_record.Size());
        m_record.ForEach([&](BlockType* block){
            if (block->Line() != -1)
            {
                
                TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
                    "Memory Block {addr=%p, size=%zu byte,} in "
                    "file=%s, line=%d", block->Pointer(), block->Size(),
                        block->File(), block->Line());
            }
            else 
            {
                TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
                    "Memory Block {addr=%p, size=%zu byte}", 
                        block->Pointer(), block->Size());
            }
        });
        SystemType::GetInstance().Error(
            Definition::Status::sMemoryNotClearOnFinalize,
            "Memory not clear on finalize {size=%zu}", m_record.Size());
    }
}

template<std::size_t N>
inline typename Memory::PointerType Memory::Allocate(const std::size_t& s,
    const char (&f)[N], const int& l)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Allocate<%zu>(s=%zu, f=%s, l=%d)", N, s, f, l);
    
    auto p = std::malloc(s);

    if (p == NULL)
    {
        SystemType::GetInstance().Error(
            Definition::Status::sMemBlockAllocationFailed,
            "Allocation memory failed");
        return {};
    }
    
    {
        std::lock_guard<std::mutex> guard{m_lock};
        BlockType * block_ptr = nullptr;

        auto res = m_record.Register(
            [&](BlockType* block) -> void 
            {
                block->SetDeallocator(Deallocator);
                block_ptr = block;
                ++m_countId;
            }, 
            [&](int status) -> void
            {
                std::free(p);
                p = NULL;
            }, p, s, m_countId, f, l);

        if (res != RecordType::sOk)
        {
            return {};
        }
        
        return {block_ptr};
    }
}

inline typename Memory::PointerType Memory::Allocate(const std::size_t& s)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Allocate(s=%zu)", s);
    
    return std::move(Allocate(s, __FILE__, __LINE__));
}

inline bool Memory::Reallocate(void* p, const std::size_t& s)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Reallocate(p=%p, s=%zu)", p, s);
        
    std::lock_guard<std::mutex> guard{m_lock};

    auto* block = m_record[p];
    if (block == nullptr)
    {
        return false;
    }
    bool need_repos = false;
    bool res = block->Reallocate([&](void*& p)->std::size_t{
        void* alloc = std::realloc(p, s);
        if (alloc == NULL)
        {
            SystemType::GetInstance().Error(
                Definition::Status::sMemBlockReallocationFailed,
                "Memory realocation failed {pointer=%p, size=%zu}", p, s);
            return 0;
        }
        if (alloc != p)
        {
            need_repos = true;
            p = alloc;
        }
        return s;
    });
    if (need_repos)
    {
        m_record.Reposition(p);
    }
    return res;
}

inline bool Memory::Reallocate(PointerType p, const std::size_t& s)
{
    TEST_SYS_DEBUG_V(SystemType, DebugType, 2, this, 
        "Reallocate(p=%s, s=%zu)", 
            TEST_SYS_DEBUG_TARGS_VALUE_STR(p), s);

    std::lock_guard<std::mutex> guard{m_lock};

    auto* block = m_record[p];
    if (block == nullptr)
    {
        return false;
    }
    bool need_repos = false;
    bool res = block->Reallocate([&](void*& p)->std::size_t{
        void* alloc = std::realloc(p, s);
        if (alloc == NULL)
        {
            SystemType::GetInstance().Error(
                Definition::Status::sMemBlockReallocationFailed,
                "Memory realocation failed {pointer=%p, size=%zu}", p, s);
            return 0;
        }
        if (alloc != p)
        {
            need_repos = true;
            p = alloc;
        }
        return s;
    });
    if (need_repos)
    {
        m_record.Reposition(p);
    }
    return res;
}

inline bool Memory::Free(void* p, bool force)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Free(p=%p, force=%s)", p, (force?"true":"false"));

    std::lock_guard<std::mutex> guard{m_lock};

    test::sys::mem::block::Pointer<BlockType> removed;
    auto res = m_record.Unregister(std::move(p), &removed, force);
    
    if (res == RecordType::sOk)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
            "Remove pointer(id=%zu, p=%p, size=%zu)", removed->ID(),
                removed->Pointer(), removed->Size());
        
        removed->Release();
    }
    return res;
}

inline bool Memory::Free(PointerType& p, bool force)
{
    TEST_SYS_DEBUG_V(SystemType, DebugType, 2, this, 
        "Free(p=%s, force=%s)", 
            TEST_SYS_DEBUG_TARGS_VALUE_STR(p), (force?"true":"false"));

    std::lock_guard<std::mutex> guard{m_lock};

    test::sys::mem::block::Pointer<BlockType> removed;
    auto res = m_record.Unregister(std::move(p), &removed, force);
    
    if (res == RecordType::sOk)
    {
        TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
            "Remove pointer(id=%zu, p=%p, size=%zu)", removed->ID(),
                removed->Pointer(), removed->Size());
        
        removed->Release();
    }
    return res;
}

inline std::size_t Memory::OverheadSize() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "OverheadSize() const");

    Memory* cast = const_cast<Memory*>(this);
    std::lock_guard<std::mutex> guard{cast->m_lock};

    return cast->m_record.AllocationSize(); 
}

inline std::size_t Memory::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");
    
    Memory* cast = const_cast<Memory*>(this);
    std::lock_guard<std::mutex> guard{cast->m_lock};

    std::size_t sum = 0;

    cast->m_record.ForEach([&](BlockType* block){
        std::size_t old_sum = sum;
        sum += block->Size();
        if (sum < old_sum)
        {
            sum = (std::size_t) -1;
        }
    });

    return sum;
}

#include "mem/Pointer.h"
#include "mem/ptr/Const.h"


} //!sys

} //!test

#endif //!TEST_SYS_MEMORY_H_IMPL_
