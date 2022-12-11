#ifndef TEST_SYS_MEMORY_H_
#define TEST_SYS_MEMORY_H_

#ifndef TEST_SYS_MEMORY_DEBUG_ALLOC
#define TEST_SYS_MEMORY_DEBUG_ALLOC 0
#endif //!TEST_SYS_MEMORY_DEBUG_ALLOC
#ifndef TEST_SYS_MEMORY_DEBUG_DEALLOC
#define TEST_SYS_MEMORY_DEBUG_DEALLOC 0
#endif //!TEST_SYS_MEMORY_DEBUG_DEALLOC

#include "Definition.h"
#include "Interface.h"
#include "Debug.h"

#include "mem/Block.h"
#include "mem/ptr/Const.defn.h"
#include "mem/Pointer.defn.h"
#include "mem/Record.h"

#include <cstdio>
#include <thread>
#include <mutex>
#include <atomic>
#include <functional>

namespace test::sys
{
class Memory;
}

TEST_SYS_DBG_TYPE_DEFINE("test::sys::Memory", test::sys::Memory);

namespace test
{
namespace sys
{

class Memory final
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Memory> DebugType;
    typedef test::sys::mem::block::Base::Data DataType;
    typedef test::sys::mem::block::Base::StatusIntegerType StatusIntegerType;
public:
#ifdef USING_TEST_MEMORY
    typedef test::sys::mem::Block<test::sys::mem::block::Base,
        test::sys::mem::block::FileLine> BlockType;
#else
    typedef test::sys::mem::Block<test::sys::mem::block::Base> BlockType;
#endif 
public:
    typedef test::sys::mem::Pointer<BlockType> PointerType;
    typedef test::sys::mem::ptr::Const<BlockType> PointerConstType;
public:
    typedef test::sys::mem::Record<BlockType> RecordType;
public:
    static inline Memory& GetInstance();
private:
    static inline bool Deallocator(StatusIntegerType status, DataType data);
private:
    std::size_t m_countId;
    RecordType m_record;
    std::mutex m_lock;
private:
    inline Memory();
public:
    inline Memory(const Memory&) = delete;
    inline Memory(Memory&&) = delete;
public:
    inline ~Memory();
public:
    inline Memory& operator=(const Memory&) = delete;
    inline Memory& operator=(Memory&&) = delete;
public:
    inline void* operator new (std::size_t) = delete;
    inline void* operator new[] (std::size_t) = delete;
    inline void operator delete(void*) = delete;
    inline void operator delete[](void*) = delete;
public:
    inline bool HasRegister(const void * p);
    inline bool HasRegister(const PointerConstType& p);
public:
    template<std::size_t N>
    inline PointerType Allocate(const std::size_t& s,
        const char (&f)[N], const int& l);
    inline PointerType Allocate(const std::size_t& s);
public:
    inline bool Reallocate(void* p, const std::size_t& s);
    inline bool Reallocate(PointerType p, const std::size_t& s);
public:
    inline bool Free(void* p, bool force = false);
    inline bool Free(PointerType& p, bool force = false);
public:
    inline std::size_t OverheadSize() const;
public:
    inline std::size_t Size() const;
};

} //!sys

} //!test

#ifndef TEST_SYS_MEMORY_H_IMPL_LATER

#include "Memory.impl.h"

#endif //!TEST_SYS_MEMORY_H_IMPL_LATER

#endif //!TEST_SYS_MEMORY_H_
