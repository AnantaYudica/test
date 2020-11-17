#ifndef TEST_MATH_LOGARITHM_H_
#define TEST_MATH_LOGARITHM_H_

#include "NaturalLogarithm.h"

#include <cstddef>

namespace test
{
namespace math
{

template<typename TResult, std::size_t NBase, typename TFP = long double, 
    typename TValue>
static constexpr TResult Logarithm(const TValue& x)
{
    return test::math::NaturalLogarithm<TResult, TFP, TValue>(x) /
        test::math::NaturalLogarithm<TResult, TFP>(NBase);
}

} //!math

} //!test

#endif //!TEST_MATH_LOGARITHM_H_
