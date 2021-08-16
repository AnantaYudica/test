#ifndef TEST_MATH_INTEGER_ADDITION_H_
#define TEST_MATH_INTEGER_ADDITION_H_

#include <cstddef>

namespace test
{
namespace math
{
namespace integer
{

template<typename TElementValue, typename TAValue, typename TBValue,
    typename TExpandValue, typename TSize, TSize NA, TSize NB, 
    TElementValue(FSetAValue)(TAValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetAValue)(const TAValue&, const TSize&),
    TExpandValue(FGetBValue)(const TBValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementDefault = 0>
static TElementValue Addition(TAValue& a, const TBValue& b,
    const TElementValue& c = 0, const TSize& bg_a = 0, 
    const TSize& bg_b = 0)
{
    TElementValue carry = c;
    TExpandValue sum = 0;
    for (TSize i_a = bg_a, i_b = bg_b; i_a < NA; ++i_a, ++i_b)
    {
        sum = FGetAValue(a, i_a);
        if (i_b < NB)
            sum += FGetBValue(b, i_b);
        else
            sum += VElementDefault;
        sum += carry;
        const auto split = FSplitValue(sum);
        FSetAValue(a, i_a, FElementValue(split));
        carry = FCarryValue(split);
    }
    return carry;
}

template<typename TElementValue, typename TAValue, typename TBValue,
    typename TExpandValue, typename TSize, TSize NA, TSize NB, 
    TElementValue(FSetAValue)(TAValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetAValue)(const TAValue&, const TSize&),
    TExpandValue(FGetBValue)(const TBValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementDefault = 0>
static TElementValue Addition(TAValue& a, const TBValue& b,
    const TElementValue& c, const TSize& bg_a, const TSize& bg_b, 
    const TSize& ed_b)
{
    TElementValue carry = c;
    TExpandValue sum = 0;
    const TSize end_b = bg_b < ed_b ? (ed_b < NB ? ed_b : NB) : bg_b;
    for (TSize i_a = bg_a, i_b = bg_b; i_a < NA; ++i_a, ++i_b)
    {
        sum = FGetAValue(a, i_a);
        if (i_b < end_b)
            sum += FGetBValue(b, i_b);
        else
            sum += VElementDefault;
        sum += carry;
        const auto split = FSplitValue(sum);
        FSetAValue(a, i_a, FElementValue(split));
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
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementBDefault = 0>
static TElementValue Addition(TValue& a, const TExpandValue& b,
    const TElementValue& c = 0, const TSize& bg = 0)
{
    TElementValue carry = c;
    TSize i = bg;
    if (i < N)
    {
        TExpandValue sum = 0;
        const auto split_b = FSplitValue(b);
        const TExpandValue elem_b0 = FElementValue(split_b);
        const TExpandValue elem_b1 = FCarryValue(split_b);
        const TExpandValue (&elem_b)[2]{elem_b0, elem_b1};

        for (int j = 0; j < 2; ++j, ++i)
        {
            sum = FGetValue(a, i);
            sum += elem_b[j];
            sum += carry;
            
            auto split = FSplitValue(sum);
            FSetValue(a, i, FElementValue(split));
            carry = FCarryValue(split);
        }
        
        for (; (i < N && (carry != 0 || VElementBDefault != 0)); ++i)
        {
            sum = FGetValue(a, i);
            sum += VElementBDefault;
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
