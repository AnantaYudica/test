#ifndef TEST_SYS_MEM_BLOCK_POINTER_H_
#define TEST_SYS_MEM_BLOCK_POINTER_H_

#include "../Block.h"

#include <utility>
#include <new>
#include <cstring>
#include <type_traits>

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
    constexpr std::size_t size = sizeof(test::sys::mem::Block<TDerives...>) + 1;
    static char instance[size] = {0};
    memset(instance, 0, size);
    return reinterpret_cast<BlockType*>(instance);
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::Pointer() :
    m_block(nullptr)
{}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::Pointer(BlockType* block) :
    m_block(block)
{}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::
    Pointer(Pointer<test::sys::mem::Block<TDerives...>>&& mov) :
        m_block(mov.m_block)
{
    mov.m_block = nullptr;
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::~Pointer()
{
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
    return m_block != nullptr;
}

template<typename... TDerives>
Pointer<test::sys::mem::Block<TDerives...>>::operator bool() const
{
    return m_block != nullptr;
}

template<typename... TDerives>
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType* 
Pointer<test::sys::mem::Block<TDerives...>>::operator->()
{
    if (m_block == nullptr) return DefaultBlock();
    return m_block;
    
}

template<typename... TDerives>
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType& 
Pointer<test::sys::mem::Block<TDerives...>>::operator*()
{
    if (m_block == nullptr) return *(DefaultBlock());
    return *m_block;
}

template<typename... TDerives>
const typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType* 
Pointer<test::sys::mem::Block<TDerives...>>::operator->() const
{
    if (m_block == nullptr) return DefaultBlock();
    return m_block;
}

template<typename... TDerives>
const typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType& 
Pointer<test::sys::mem::Block<TDerives...>>::operator*() const
{
    if (m_block == nullptr) return *(DefaultBlock());
    return *m_block;
}

template<typename... TDerives>
bool Pointer<test::sys::mem::Block<TDerives...>>::
    operator==(const void* pointer) const
{
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
    return !operator==(pointer);
}

template<typename... TDerives>
bool Pointer<test::sys::mem::Block<TDerives...>>::
    operator==(const Pointer<test::sys::mem::Block<TDerives...>>& other) const
{
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
    return !operator==(other);
}

template<typename... TDerives>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<test::sys::mem::Block<TDerives...>>::
    operator==(const TValue& val) const
{
    return *this == (const void*)val;
}
        
template<typename... TDerives>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Pointer<test::sys::mem::Block<TDerives...>>::
    operator!=(const TValue& val) const
{
    return *this != (const void*)val;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_POINTER_H_
