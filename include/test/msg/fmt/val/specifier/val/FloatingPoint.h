#ifndef TEST_MSG_FMT_VAL_SPECIFIER_VAL_FLOATINGPOINT_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_VAL_FLOATINGPOINT_H_

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{
namespace specifier
{
namespace val
{

union FloatingPoint
{
    static_assert(
        sizeof(long double) == 10 || sizeof(long double) == 12 ||
        sizeof(long double) == 16 , "Not Support long double size");

    template<typename TRet>
    static inline TRet CastTo(const FloatingPoint& val);

    float float_value;
    double double_value;
    long double long_double_value;
    struct 
    {
        std::uint32_t value;
        std::uint32_t double_padding;
        typename std::conditional<sizeof(long double) == 10, std::uint16_t,
            typename std::conditional<sizeof(long double) == 12, std::uint32_t,
            std::uint64_t>::type>::type long_double_padding;
    } _float_aligned;

};

template<typename TRet>
inline TRet FloatingPoint::CastTo(const FloatingPoint& val)
{
    if (val._float_aligned.double_padding == 0 && 
        val._float_aligned.long_double_padding == 0)
    {
        return (TRet)val.float_value;
    }
    else if (val._float_aligned.double_padding != 0 &&
        val._float_aligned.long_double_padding == 0)
    {
        return (TRet)val.double_value;
    }
    return (TRet)val.long_double_value;
}

} //!val

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_VAL_FLOATINGPOINT_H_
