#ifndef TEST_MATH_NATURALLOGARITHM_H_
#define TEST_MATH_NATURALLOGARITHM_H_

#include "Exponential.h"

#include <cfloat>
#include <cmath>
#include <cstddef>

namespace test
{
namespace math
{

template<typename TResult, typename TFP = long double, typename TValue>
static constexpr TResult NaturalLogarithm(const TValue& x,
    TFP y, TFP e, TFP d, const bool& r)
{
    return (((((TFP)x > e) != r || (x - e) == d) ? y : 
        test::math::NaturalLogarithm<TResult, TFP, TValue>(x, 
            (y + (2 * ((x - e)/(x + e)))), test::math::Exponential<TFP, 
                TFP>(y + (2 * ((x - e)/(x + e)))), x - e, r)));
}

template<typename TResult, typename TFP = long double, typename TValue>
static constexpr TResult NaturalLogarithm(const TValue& x)
{
    return x == 1 ? 0 : 
        NaturalLogarithm<TResult, TFP, TValue>(x, 0, 
            test::math::Exponential<TFP, TFP>(0), 0,
                (TFP)x > test::math::Exponential<TFP, TFP>(0));
}

} //!math

} //!test

#endif //!TEST_MATH_NATURALLOGARITHM_H_
