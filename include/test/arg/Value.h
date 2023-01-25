#ifndef TEST_ARG_VALUE_H_
#define TEST_ARG_VALUE_H_

#include "../System.h"
#include "../Pointer.h"
#include "val/Const.h"

#include <cstddef>
#include <cstdint>

namespace test::arg
{

template<typename T, typename TBuffer>
class Value;

}

#ifndef TEST_ARG_VALUE_DLEVEL

#define TEST_ARG_VALUE_DLEVEL 2

#endif //!TEST_ARG_VALUE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TBuffer>

template<typename T, typename TBuffer>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_ARG_VALUE_DLEVEL, 
    "test::arg::Value", 
    test::arg::Value<T, TBuffer>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace arg
{

template<typename T, typename TBuffer = test::Pointer<std::uint8_t>>
class Value : public test::arg::val::Const<T, TBuffer>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::Value<T, TBuffer>> DebugType;
public:
    typedef test::arg::val::Const<T, TBuffer> ConstType;
public:
    typedef typename ConstType::HeaderType HeaderType;
    typedef typename ConstType::BlockType BlockType;
    typedef typename ConstType::BufferType BufferType;
public:
    Value();
    Value(const BlockType& block, BufferType buffer);
    ~Value();
public:
    Value(const Value<T, TBuffer>& cpy);
    Value(Value<T, TBuffer>&& mov);
public:
    Value<T, TBuffer>& operator=(const Value<T, TBuffer>& cpy);
    Value<T, TBuffer>& operator=(Value<T, TBuffer>&& mov);
    Value<T, TBuffer>& operator=(T&& val);
public:
    HeaderType Header() const;
public:
    std::size_t Size() const;
public:
    T operator*() const;
public:
    bool operator==(T&& other) const;
    bool operator!=(T&& other) const;
};

template<typename T, typename TBuffer>
Value<T, TBuffer>::Value() :
    ConstType()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename T, typename TBuffer>
Value<T, TBuffer>::Value(const BlockType& block, BufferType buffer) :
    ConstType(block, buffer)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(block=%p, buffer=%p)", &block, &buffer);
    
}

template<typename T, typename TBuffer>
Value<T, TBuffer>::~Value()
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename T, typename TBuffer>
Value<T, TBuffer>::Value(const Value<T, TBuffer>& cpy) :
    ConstType(cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename T, typename TBuffer>
Value<T, TBuffer>::Value(Value<T, TBuffer>&& mov) :
    ConstType(std::move(mov))
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename T, typename TBuffer>
Value<T, TBuffer>& 
Value<T, TBuffer>::operator=(const Value<T, TBuffer>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    ConstType::operator=(cpy);
    return *this;
}

template<typename T, typename TBuffer>
Value<T, TBuffer>& Value<T, TBuffer>::operator=(Value<T, TBuffer>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(cpy=%p)", &mov);

    ConstType::operator=(std::move(mov));
    return *this;
}

template<typename T, typename TBuffer>
Value<T, TBuffer>& Value<T, TBuffer>::operator=(T&& val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "operator=(val=%s)", TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    ConstType::m_block.template Set<T>(ConstType::m_buffer, 
        std::forward<T>(val));
    return *this;
}

template<typename T, typename TBuffer>
typename Value<T, TBuffer>::HeaderType
Value<T, TBuffer>::Header() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Header() const");

    return ConstType::Header();
}

template<typename T, typename TBuffer>
std::size_t Value<T, TBuffer>::Size() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Size() const");

    return ConstType::Size();
}

template<typename T, typename TBuffer>
T Value<T, TBuffer>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return ConstType::operator*();
}

template<typename T, typename TBuffer>
bool Value<T, TBuffer>::operator==(T&& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(%s) const", 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(other));

    return ConstType::operator==(std::forward<T>(other));
}

template<typename T, typename TBuffer>
bool Value<T, TBuffer>::operator!=(T&& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(%s) const", 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(other));
    
    return ConstType::operator!=(std::forward<T>(other));
}

} //!arg

} //!test

#endif //!TEST_ARG_VALUE_H_
