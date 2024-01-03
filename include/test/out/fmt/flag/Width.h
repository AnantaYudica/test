#ifndef TEST_OUT_FMT_FLAG_WIDTH_H_
#define TEST_OUT_FMT_FLAG_WIDTH_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Width
{
private:
    bool m_default;
    int m_value;
public:
    inline constexpr Width();
    inline constexpr explicit Width(const int& val);
public:
    inline constexpr bool IsDefault() const;
    inline constexpr int GetValue() const;
};

inline constexpr Width::Width() :
    m_default(true),
    m_value(0)
{}

inline constexpr Width::Width(const int& val) :
    m_default(false),
    m_value(val)
{}

inline constexpr bool Width::IsDefault() const
{
    return m_default;
}

inline constexpr int Width::GetValue() const
{
    return m_value;
}

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_WIDTH_DLEVEL

#define TEST_OUT_FMT_FLAG_WIDTH_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_WIDTH_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_WIDTH_DLEVEL, 
    "test::out::fmt::flag::Width", test::out::fmt::flag::Width);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Width

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE(
    "TestOutFmtFlagWidth{default=%s, v=%d, &=%p}", 
        (val.IsDefault() ? "true" : "false"), val.GetValue(), &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_WIDTH_H_
