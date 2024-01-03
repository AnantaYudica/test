#ifndef TEST_OUT_FMT_FLAG_PRECISION_H_
#define TEST_OUT_FMT_FLAG_PRECISION_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Precision
{
private:
    bool m_default;
    int m_value;
public:
    inline constexpr Precision();
    inline constexpr explicit Precision(const int& val);
public:
    inline constexpr bool IsDefault() const;
    inline constexpr int GetValue() const;
};

inline constexpr Precision::Precision() :
    m_default(true),
    m_value(0)
{}

inline constexpr Precision::Precision(const int& val) :
    m_default(false),
    m_value(val)
{}

inline constexpr bool Precision::IsDefault() const
{
    return m_default;
}

inline constexpr int Precision::GetValue() const
{
    return m_value;
}

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PRECISION_DLEVEL

#define TEST_OUT_FMT_FLAG_PRECISION_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PRECISION_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PRECISION_DLEVEL, 
    "test::out::fmt::flag::Precision", test::out::fmt::flag::Precision);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Precision

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE(
    "TestOutFmtFlagPrecision{default=%s, v=%d, &=%p}", 
        (val.IsDefault() ? "true" : "false"), val.GetValue(), &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_PRECISION_H_
