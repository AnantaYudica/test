#ifndef TEST_DEF_OUT_CSTR_FP_PRECISION_H_
#define TEST_DEF_OUT_CSTR_FP_PRECISION_H_

#include <cstddef>
#include <cfloat>
#include <type_traits>

namespace test
{
namespace def
{
namespace out
{
namespace cstr
{
namespace fp
{

struct Precision
{

    template<typename TFloat, std::size_t NBase = 10,
        typename std::enable_if<NBase == 10 &&
            std::is_same<TFloat, float>::value &&
            !std::is_same<TFloat, double>::value &&
            !std::is_same<TFloat, long double>::value , int>::type = 0>
    static constexpr std::size_t Size()
    {
        return 6;
    }

    template<typename TFloat, std::size_t NBase = 10,
        typename std::enable_if<NBase == 10 &&
            !std::is_same<TFloat, float>::value &&
            std::is_same<TFloat, double>::value &&
            !std::is_same<TFloat, long double>::value , int>::type = 0>
    static constexpr std::size_t Size()
    {
        return 6;
    }

    template<typename TFloat, std::size_t NBase = 10,
        typename std::enable_if<NBase == 10 &&
            !std::is_same<TFloat, float>::value &&
            !std::is_same<TFloat, double>::value &&
            std::is_same<TFloat, long double>::value , int>::type = 0>
    static constexpr std::size_t Size()
    {
        return 6;
    }

    template<typename TFloat, std::size_t NBase>
    static constexpr bool IsRound()
    {
        return true;
    }
};

} //!fp

} //!cstr

} //!out

} //!def

} //!test

#endif //!TEST_DEF_OUT_CSTR_FP_PRECISION_H_
