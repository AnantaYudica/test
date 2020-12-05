#ifndef TEST_MATH_INTEGER_ADDITION_H_
#define TEST_MATH_INTEGER_ADDITION_H_

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
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&)>
static TElementValue Addition(TValue& a, const TValue& b,
    const TSize& begin = 0)
{
    TElementValue carry = 0;
    TExpandValue sum = 0;
    for (TSize i = begin; i < N; ++i)
    {
        sum = FGetValue(a, i);
        sum += FGetValue(b, i);
        sum += carry;
        const auto split = FSplitValue(sum);
        FSetValue(a, i, FElementValue(split));
        carry = FCarryValue(split);
    }
    return carry;
}

template<typename TElementValue, typename TValue,
    typename TExpandValue, typename TSize, TSize N, 
    TElementValue(FSetValue)(TValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetValue)(const TValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&)>
static TElementValue Addition(TValue& a, const TExpandValue& b,
    const TSize& begin = 0)
{
    TElementValue carry = 0;
    TSize i = begin;
    if (i < N)
    {
        TExpandValue sum = 0;
        const auto split_b = FSplitValue(b);
        TElementValue elem_b[2]{FElementValue(split_b), FCarryValue(split_b)};

        for (int j = 0; j < 2; ++j, ++i)
        {
            sum = FGetValue(a, i);
            sum += elem_b[j];
            sum += carry;
            
            auto split = FSplitValue(sum);
            FSetValue(a, i, FElementValue(split));
            carry = FCarryValue(split);
        }
        
        for (; (i < N && carry != 0); ++i)
        {
            sum = FGetValue(a, i);
            sum += carry;
            const auto split = FSplitValue(sum);
            FSetValue(a, i, FElementValue(split));
            carry = FCarryValue(split);
        }
    }
    return carry;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_ADDITION_H_
