#ifndef TEST_SYS_MEM_BLOCK_POINTER_H_
#define TEST_SYS_MEM_BLOCK_POINTER_H_

#include "../Block.h"

#include <utility>
#include <new>

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
    BlockType* operator->();
    BlockType& operator*();
};

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
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType* 
Pointer<test::sys::mem::Block<TDerives...>>::operator->()
{
    return m_block;
}

template<typename... TDerives>
typename Pointer<test::sys::mem::Block<TDerives...>>::BlockType& 
Pointer<test::sys::mem::Block<TDerives...>>::operator*()
{
    return *m_block;
}

} //!block

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_BLOCK_POINTER_H_
