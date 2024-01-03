#ifndef TEST_OUT_FMT_FLAG_VALUE_H_
#define TEST_OUT_FMT_FLAG_VALUE_H_

#include "../../../System.h"

#include <type_traits>
#include <cstring>

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

template<typename T>
class Value
{
public:
    typedef typename std::remove_cv<typename std::remove_reference<T>::
        type>::type Type;
private:
    bool m_default;
    char m_value[sizeof(Type)];
public:
    constexpr Value() ;
    explicit Value(const Type& val);
public:
    Value(const Value<T>& cpy);
    Value(Value<T>&& mov);
public:
    Value<T>& operator=(const Value<T>& cpy) = delete;
    Value<T>& operator=(Value<T>&& mov) = delete;
public:
    constexpr bool IsDefault() const;
    const Type& GetValue() &&;
};

template<typename T>
constexpr Value<T>::Value() :
    m_default(true),
    m_value{}
{}

template<typename T>
Value<T>::Value(const Type& val) :
    m_default(false),
    m_value{}
{
    std::memset(m_value, 0, sizeof(Type));
    auto ptr = reinterpret_cast<const char*>(&val);
    std::memcpy(m_value, ptr, sizeof(Type));
}

template<typename T>
Value<T>::Value(const Value<T>& cpy) :
    m_default(cpy.m_default),
    m_value{}
{
    std::memcpy(m_value, cpy.m_value, sizeof(Type));
}

template<typename T>
Value<T>::Value(Value<T>&& mov) :
    m_default(mov.m_default),
    m_value{}
{
    std::memcpy(m_value, mov.m_value, sizeof(Type));
}

template<typename T>
constexpr bool Value<T>::IsDefault() const
{
    return m_default;
}

template<typename T>
const typename Value<T>::Type& Value<T>::GetValue() &&
{
    return *(reinterpret_cast<const Type*>(m_value));
}

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_VALUE_DLEVEL

#define TEST_OUT_FMT_FLAG_VALUE_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_VALUE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_FLAG_VALUE_DLEVEL, 
    "test::out::fmt::flag::Value", 
    test::out::fmt::flag::Value<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Value<T>

template<typename T>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagValue<%s>{&=%p}", 
    TEST_SYS_DEBUG_T_NAME_STR(T), &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_VALUE_H_
