#ifndef TEST_MATH_EXPONENTIAL_H_
#define TEST_MATH_EXPONENTIAL_H_

#include <cmath>
#include <cstddef>

namespace test
{
namespace math
{

template<typename TResult, typename TFP = long double, typename TValue>
static constexpr TResult Exponential(const TValue& x, std::size_t _n = 0, 
    TFP _y = 1, TFP _a = 1)
{
    return x < 0 ? 1 / Exponential<TResult, TFP, TValue>(-x) : 
        ((_y == (_y + ((_a * x) / (_n + 1)))) ? _y : 
            Exponential<TResult, TFP, TValue>(x, _n + 1, 
                (_y + ((_a * x) / (_n + 1))), ((_a * x) / (_n + 1))));
}

} //!math

} //!test

#endif //!TEST_MATH_EXPONENTIAL_H_
