#ifndef TEST_MATH_EXPONENTIAL_H_
#define TEST_MATH_EXPONENTIAL_H_

#include <cmath>
#include <cstddef>

namespace test
{
namespace math
{

template<typename TResult, typename TFP = long double, typename TValue>
static constexpr TResult Exponential(const TValue& x, std::size_t n, 
    TFP y, TFP a)
{
    return (y == (y + ((a * x) / (n + 1)))) ? y : 
        Exponential<TResult, TFP, TValue>(x, n + 1, 
            (y + ((a * x) / (n + 1))), ((a * x) / (n + 1)));
}

template<typename TResult, typename TFP = long double, typename TValue>
static constexpr TResult Exponential(const TValue& x)
{
    return x < 0 ? 1 / Exponential<TResult, TFP, TValue>(-x, 0, 1, 1) :
        Exponential<TResult, TFP, TValue>(x, 0, 1, 1);
}

} //!math

} //!test

#endif //!TEST_MATH_EXPONENTIAL_H_
