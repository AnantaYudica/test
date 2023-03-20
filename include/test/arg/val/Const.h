#ifndef TEST_ARG_VAL_CONST_H_
#define TEST_ARG_VAL_CONST_H_

#include "../../System.h"
#include "../../Pointer.h"
#include "../Header.h"
#include "../Block.h"
#include "../Type.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace arg
{
namespace val
{

template<typename T, typename TBuffer>
class Const;

} //!val

} //!arg

} //!test

#ifndef TEST_ARG_VAL_CONST_DLEVEL

#define TEST_ARG_VAL_CONST_DLEVEL 2

#endif //!TEST_ARG_VAL_CONST_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TBuffer>

template<typename T, typename TBuffer>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_ARG_VAL_CONST_DLEVEL, 
    "test::arg::val::Const", 
    test::arg::val::Const<T, TBuffer>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace arg
{
namespace val
{

template<typename T, typename TBuffer = typename test::arg::Block::BufferType>
class Const
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::val::Const<T, TBuffer>> DebugType;
public:
    typedef test::arg::Header HeaderType;
    typedef test::arg::Block BlockType;
    typedef TBuffer BufferType;
public:
    typedef typename test::arg::Type<T>::RValueType ValueType;
protected:
    BlockType m_block;
    BufferType m_buffer;
public:
    Const();
    Const(const BlockType& block, BufferType buffer);
    ~Const();
public:
    Const(const Const<T, TBuffer>& cpy);
    Const(Const<T, TBuffer>&& mov);
public:
    Const<T, TBuffer>& operator=(const Const<T, TBuffer>& cpy);
    Const<T, TBuffer>& operator=(Const<T, TBuffer>&& mov);
public:
    HeaderType Header() const;
public:
    std::size_t Size() const;
public:
    ValueType operator*() const;
public:
    bool operator==(T&& other) const;
    bool operator!=(T&& other) const;
};

template<typename T, typename TBuffer>
Const<T, TBuffer>::Const() :
    m_block(),
    m_buffer()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename T, typename TBuffer>
Const<T, TBuffer>::Const(const BlockType& block, BufferType buffer) :
    m_block(block),
    m_buffer(buffer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(block=%p, buffer=%p)", &block, &buffer);
    
}

template<typename T, typename TBuffer>
Const<T, TBuffer>::~Const()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename T, typename TBuffer>
Const<T, TBuffer>::Const(const Const<T, TBuffer>& cpy) :
    m_block(cpy.m_block),
    m_buffer(cpy.m_buffer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename T, typename TBuffer>
Const<T, TBuffer>::Const(Const<T, TBuffer>&& mov) :
    m_block(std::move(mov.m_block)),
    m_buffer(std::move(mov.m_buffer))
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename T, typename TBuffer>
Const<T, TBuffer>& 
Const<T, TBuffer>::operator=(const Const<T, TBuffer>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_block = cpy.m_block;
    m_buffer = cpy.m_buffer;
    return *this;
}

template<typename T, typename TBuffer>
Const<T, TBuffer>& 
Const<T, TBuffer>::operator=(Const<T, TBuffer>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_block = std::move(mov.m_block);
    m_buffer = std::move(mov.m_buffer);
    return *this;
}

template<typename T, typename TBuffer>
typename Const<T, TBuffer>::HeaderType
Const<T, TBuffer>::Header() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Header() const");

    return m_block.GetHeader();
}

template<typename T, typename TBuffer>
std::size_t Const<T, TBuffer>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");

    return m_block.GetSize();
}

template<typename T, typename TBuffer>
typename Const<T, TBuffer>::ValueType Const<T, TBuffer>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return m_block.template Get<T>(m_buffer);
}

template<typename T, typename TBuffer>
bool Const<T, TBuffer>::operator==(T&& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(%s) const", 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(other));

    return m_block.template Get<T>(m_buffer) == other;
}

template<typename T, typename TBuffer>
bool Const<T, TBuffer>::operator!=(T&& other) const
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(%s) const", 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(other));
    
    return m_block.template Get<T>(m_buffer) != other;
}

} //!val

} //!arg

} //!test

#endif //!TEST_ARG_VALUE_H_
