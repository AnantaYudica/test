#ifndef TEST_OUT_FMT_FLAG_LENGTH_H_
#define TEST_OUT_FMT_FLAG_LENGTH_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Length
{
private:
    bool m_default;
    int m_value;
public:
    inline constexpr Length();
    inline constexpr explicit Length(const int& val);
public:
    inline constexpr bool IsDefault() const;
    inline constexpr int GetValue() const;
};

inline constexpr Length::Length() :
    m_default(true),
    m_value(0)
{}

inline constexpr Length::Length(const int& val) :
    m_default(false),
    m_value(val)
{}

inline constexpr bool Length::IsDefault() const
{
    return m_default;
}

inline constexpr int Length::GetValue() const
{
    return m_value;
}

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_LENGTH_DLEVEL

#define TEST_OUT_FMT_FLAG_LENGTH_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_LENGTH_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_LENGTH_DLEVEL, 
    "test::out::fmt::flag::Length", test::out::fmt::flag::Length);

#endif //!TEST_OUT_FMT_FLAG_LENGTH_H_
