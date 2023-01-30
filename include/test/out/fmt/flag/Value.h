#ifndef TEST_OUT_FMT_FLAG_VALUE_H_
#define TEST_OUT_FMT_FLAG_VALUE_H_

#include "../../../System.h"

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
private:
    bool m_default;
    T m_value;
public:
    constexpr Value();
    constexpr Value(const T& val);
public:
    constexpr bool IsDefault() const;
    constexpr T GetValue() const;
};

template<typename T>
constexpr Value<T>::Value() :
    m_default(true),
    m_value()
{}

template<typename T>
constexpr Value<T>::Value(const T& val) :
    m_default(false),
    m_value(val)
{}

template<typename T>
constexpr bool Value<T>::IsDefault() const
{
    return m_default;
}

template<typename T>
constexpr T Value<T>::GetValue() const
{
    return m_value;
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
