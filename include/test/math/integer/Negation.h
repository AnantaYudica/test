#ifndef TEST_MATH_INTEGER_NEGATION_H_
#define TEST_MATH_INTEGER_NEGATION_H_

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
    TExpandValue(FNegationValue)(const TExpandValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&)>
TElementValue Negation(TValue& v, const TElementValue& c = 0,
    const TSize& bg = 0, const TSize& ed = N)
{
    TElementValue carry = c;
    TExpandValue sum = 0;
    for (TSize i = bg; i < ed; ++i)
    {
        sum = FNegationValue(FGetValue(v, i), i);
        sum += carry;
        const auto split = FSplitValue(sum);
        FSetValue(v, i, FElementValue(split));
        carry = FCarryValue(split);
    }
    return carry;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_NEGATION_H_