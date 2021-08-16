#ifndef TEST_MATH_INTEGER_SUBTRACTION_H_
#define TEST_MATH_INTEGER_SUBTRACTION_H_

#include "Addition.h"
#include "Negation.h"

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
    TElementValue(FSetBValue)(TAValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetAValue)(const TAValue&, const TSize&),
    TExpandValue(FGetBValue)(const TBValue&, const TSize&),
    TExpandValue(FNegationValue)(const TExpandValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementBDefault = 0>
static TElementValue Subtraction(TAValue& a, const TBValue& b,
    const TElementValue& c = 0, const TSize& bg_a = 0, 
    const TSize& bg_b = 0, const TSize& ed_b = NB, 
    TElementValue c_b_in = 0, TElementValue * c_b_out = nullptr)
{
    TBValue b_cpy = b;
    TElementValue carry = c;
    TElementValue c_b_default;
    TElementValue & c_b = (c_b_out == nullptr ? c_b_default : *c_b_out);
    c_b = c_b_in;
    TExpandValue b_val;
    TExpandValue diff = 0;
    for(TSize i = 0, j = bg_b; i < NA; ++i, ++j)
    {
        if (j < ed_b)
        {
            if (j < NB)
            {   
                b_val = FGetBValue(b_cpy, j);
                c_b = test::math::integer::Negation<TElementValue,
                    TExpandValue, TSize, FNegationValue, FSplitValue,
                    FElementValue, FCarryValue>(b_val, c_b, j);
            }
            else
            {
                b_val = VElementBDefault;
                c_b = test::math::integer::Negation<TElementValue,
                    TExpandValue, TSize, FNegationValue, FSplitValue,
                    FElementValue, FCarryValue>(b_val, c_b, j);
            }
        }
        else
        {
            b_val = VElementBDefault;
        }

        diff = FGetAValue(a, i);
        diff += b_val;
        diff += carry;

        const auto split = FSplitValue(diff);
        FSetAValue(a, i, FElementValue(split));
        carry = FCarryValue(split);
    }

    return carry;
}

template<typename TElementValue, typename TValue,
    typename TExpandValue, typename TSize, TSize N, 
    TElementValue(FSetValue)(TValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetValue)(const TValue&, const TSize&),
    TExpandValue(FNegationValue)(const TExpandValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementBDefault = 0>
static TElementValue Subtraction(TValue& a, const TExpandValue& b,
    const TElementValue& c = 0, const TSize& bg = 0, 
    TElementValue c_b_in = 0, TElementValue * c_b_out = nullptr)
{
    TElementValue carry = c;
    TElementValue c_b_default;
    TElementValue & c_b = (c_b_out == nullptr ? c_b_default : *c_b_out);
    c_b = c_b_in;
    TSize i = bg, j = 0;
    if (i < N)
    {
        TExpandValue diff = 0;
        TExpandValue b_val;
        const TExpandValue split_b = FSplitValue(b);
        const TExpandValue elem_b0 = FElementValue(split_b);
        const TExpandValue elem_b1 = FCarryValue(split_b);
        const TExpandValue (&elem_b)[2]{elem_b0, elem_b1};

        for (; j < 2; ++j, ++i)
        {
            b_val = elem_b[j];
            c_b = test::math::integer::Negation<TElementValue,
                TExpandValue, TSize, FNegationValue, FSplitValue,
                FElementValue, FCarryValue>(b_val, c_b, j);

            diff = FGetValue(a, i);
            diff += b_val;
            diff += carry;
            
            auto split = FSplitValue(diff);
            FSetValue(a, i, FElementValue(split));
            carry = FCarryValue(split);
        }
        for (; i < N; ++i)
        {
            b_val = VElementBDefault;
            c_b = test::math::integer::Negation<TElementValue,
                TExpandValue, TSize, FNegationValue, FSplitValue,
                FElementValue, FCarryValue>(b_val, c_b, j);

            diff = FGetValue(a, i);
            diff += b_val;
            diff += carry;

            const auto split = FSplitValue(diff);
            FSetValue(a, i, FElementValue(split));
            carry = FCarryValue(split);
        }
    }
    return carry;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_SUBTRACTION_H_
