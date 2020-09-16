#ifndef TEST_OUT_FMT_FLAG_PRECISION_H_
#define TEST_OUT_FMT_FLAG_PRECISION_H_

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
    inline constexpr Precision(const int& val);
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

#endif //!TEST_OUT_FMT_FLAG_PRECISION_H_
