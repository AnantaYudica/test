#ifndef TEST_MSG_FMT_VAR_ARG_WIDTH_H_
#define TEST_MSG_FMT_VAR_ARG_WIDTH_H_

namespace test
{
namespace msg
{
namespace fmt
{
namespace var
{
namespace arg
{

class Width
{
private:
    bool m_default;
    int m_value;
public:
    inline constexpr Width();
    inline constexpr Width(const int& val);
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

} //!arg

} //!var

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAR_ARG_WIDTH_H_
