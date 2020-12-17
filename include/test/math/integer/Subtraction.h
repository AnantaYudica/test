#ifndef TEST_MATH_INTEGER_SUBTRACTION_H_
#define TEST_MATH_INTEGER_SUBTRACTION_H_

#include "Addition.h"

#include <cstddef>

namespace test
{
namespace math
{
namespace integer
{

template<typename TElementValue, typename TValue,
    typename TExpandValue, typename TSize, TSize N, 
    TElementValue(FSetValue)(TValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetValue)(const TValue&, const TSize&),
    TExpandValue(FNegationValue)(const TValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&)>
static TElementValue Subtraction(TValue& a, const TValue& b,
    const TSize& bg = 0, const TElementValue& c = 1)
{
    return test::math::integer::Addition<TElementValue, TValue, 
        TExpandValue, TSize, N, FSetValue, FGetValue, FSplitValue, 
        FElementValue, FCarryValue, FNegationValue>(a, b, bg, c);
}

template<typename TElementValue, typename TValue,
    typename TExpandValue, typename TSize, TSize N, 
    TElementValue(FSetValue)(TValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetValue)(const TValue&, const TSize&),
    TExpandValue(FNegationValue)(const TExpandValue&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementBDefault>
static TElementValue Subtraction(TValue& a, const TExpandValue& b,
    const TSize& bg = 0, const TElementValue& c = 1)
{
    return Addition<TElementValue, TValue, TExpandValue, TSize, N, 
        FSetValue, FGetValue, FSplitValue, FElementValue, 
        FCarryValue, VElementBDefault>(a, FNegationValue(b), bg, c);
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_SUBTRACTION_H_
