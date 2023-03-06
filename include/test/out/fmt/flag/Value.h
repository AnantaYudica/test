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
    constexpr Value();
    explicit Value(const Type& val);
public:
    constexpr bool IsDefault() const;
    constexpr Type GetValue() const;
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
    (reinterpret_cast<Type&>(*m_value)) = val;
}

template<typename T>
constexpr bool Value<T>::IsDefault() const
{
    return m_default;
}

template<typename T>
constexpr typename Value<T>::Type Value<T>::GetValue() const
{
    return reinterpret_cast<const Type&>(*m_value);
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

#endif //!TEST_OUT_FMT_FLAG_VALUE_H_
