#ifndef TEST_SYS_MEM_BLOCK_POINTER_H_
#define TEST_SYS_MEM_BLOCK_POINTER_H_

#include "../Block.h"
#include "../../Interface.h"
#include "../../Debug.h"

#include <utility>
#include <new>
#include <cstring>
#include <type_traits>

#ifndef TEST_SYS_MEM_BLOCK_POINTER_DLEVEL

#define TEST_SYS_MEM_BLOCK_POINTER_DLEVEL 2

#endif //!TEST_SYS_MEM_BLOCK_POINTER_DLEVEL

namespace test::sys::mem::block
{
template<typename TBLock>
class Pointer;
}

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBLock>

template<typename TBLock>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_MEM_BLOCK_POINTER_DLEVEL, 
    "test::sys::mem::block::Pointer", 
    test::sys::mem::block::Pointer<TBLock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace sys
{
namespace mem
{
namespace block
{

template<typename TBLock>
class Pointer
{

};

template<typename... TDerives>
class Pointer<test::sys::mem::Block<TDerives...>>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<
        test::sys::mem::block::Pointer<
            test::sys::mem::Block<TDerives...>>> DebugType;
public:
    typedef test::sys::mem::Block<TDerives...> BlockType;
private:
    static BlockType* DefaultBlock();
private:
    BlockType* m_block;
public:
    Pointer();
    Pointer(BlockType* block);
public:
    Pointer(const Pointer<test::sys::mem::Block<TDerives...>>&) = delete;
    Pointer(Pointer<test::sys::mem::Block<TDerives...>>&& mov);
public:
    ~Pointer();
public:
    Pointer<test::sys::mem::Block<TDerives...>>& 
        operator=(const Pointer<test::sys::mem::Block<TDerives...>>&) = delete;
    Pointer<test::sys::mem::Block<TDerives...>>& 
        operator=(Pointer<test::sys::mem::Block<TDerives...>>&&);
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
public:
    operator bool();
    operator bool() const;
public:
    BlockType* operator->();
    BlockType& operator*();
    const BlockType* operator->() const;
    const BlockType& operator*() const;
public:
    bool operator==(const void* pointer) const;
    bool operator!=(const void* pointer) const;
public:
    bool operator==(const Pointer<
        test::sys::mem::Block<TDerives...>>& other) const;
    bool operator!=(const Pointer<
        test::sys::mem::Block<TDerives...>>& other) const;
public:
    template<typename TValue, typename TNull = decltype(NULL)>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
            operator==(const TValue& val) const;
    template<typename TValue, typename TNull = decltype(NULL)>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
            operator!=(const TValue& val) const;
};

template<typename... TDerives>
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType* 
Pointer<test::sys::mem::Block<TDerives...>>::DefaultBlock()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, NULL, "DefaultBlock()");

    constexpr std::size_t size = sizeof(test::sys::mem::Block<TDerives...>) + 1;
    static char instance[size] = {0};
    memset(instance, 0, size);
    return reinterpret_cast<BlockType*>(instance);
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::Pointer() :
    m_block(nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::Pointer(BlockType* block) :
    m_block(block)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(block=%p)", block);
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::
    Pointer(Pointer<test::sys::mem::Block<TDerives...>>&& mov) :
        m_block(mov.m_block)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_block = nullptr;
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::~Pointer()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    if (m_block != nullptr)
    {
        m_block->~BlockType();
        free(m_block);
        m_block = nullptr;
    }
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>& 
Pointer<test::sys::mem::Block<TDerives...>>::
    operator=(Pointer<test::sys::mem::Block<TDerives...>>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(%p)", &mov);

    if (m_block != nullptr)
    {
        m_block->~BlockType();
        free(m_block);
        m_block = nullptr;
    }
    m_block = mov.m_block;
    mov.m_block = nullptr;
    return *this;
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::operator bool()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator bool()");

    return m_block != nullptr;
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::operator bool() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator bool() const");

    return m_block != nullptr;
}

template<typename... TDerives>
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType* 
Pointer<test::sys::mem::Block<TDerives...>>::operator->()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->()");

    if (m_block == nullptr) return DefaultBlock();
    return m_block;
    
}

template<typename... TDerives>
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType& 
Pointer<test::sys::mem::Block<TDerives...>>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");

    if (m_block == nullptr) return *(DefaultBlock());
    return *m_block;
}

template<typename... TDerives>
const typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType* 
Pointer<test::sys::mem::Block<TDerives...>>::operator->() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->() const");

    if (m_block == nullptr) return DefaultBlock();
    return m_block;
}

template<typename... TDerives>
const typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType& 
Pointer<test::sys::mem::Block<TDerives...>>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    if (m_block == nullptr) return *(DefaultBlock());
    return *m_block;
}

template<typename... TDerives>
bool Pointer<test::sys::mem::Block<TDerives...>>::
    operator==(const void* pointer) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(pointer=%p) const", pointer);

    if (pointer == nullptr)
    {
        return m_block == nullptr || ((bool)(*m_block)) == false;
    }
    else
    {
        return m_block != nullptr && m_block->Pointer() == pointer;
    }
}

template<typename... TDerives>
bool Pointer<test::sys::mem::Block<TDerives...>>::
    operator!=(const void* pointer) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(pointer=%p) const", pointer);

    return !operator==(pointer);
}

template<typename... TDerives>
bool Pointer<test::sys::mem::Block<TDerives...>>::
    operator==(const Pointer<test::sys::mem::Block<TDerives...>>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    if (other.m_block == nullptr || (bool)*(other.m_block) == false)
    {
        return m_block == nullptr || (bool)(*m_block) == false;
    }
    else
    {
        return m_block != nullptr && *m_block == *other;
    }
}

template<typename... TDerives>
bool Pointer<test::sys::mem::Block<TDerives...>>::
    operator!=(const Pointer<test::sys::mem::Block<TDerives...>>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !operator==(other);
}

template<typename... TDerives>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<test::sys::mem::Block<TDerives...>>::
    operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", (void*)val);
    
    return *this == (const void*)val;
}
        
template<typename... TDerives>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<test::sys::mem::Block<TDerives...>>::
    operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", (void*)val);

    return *this != (const void*)val;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_POINTER_H_
