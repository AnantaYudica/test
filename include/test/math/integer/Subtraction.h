#ifndef TEST_MATH_INTEGER_SUBTRACTION_H_
#define TEST_MATH_INTEGER_SUBTRACTION_H_

#include "Negation.h"
#include "fmt/Trait.h"

#include <cstddef>

namespace test
{
namespace math
{
namespace integer
{

template<typename TAValue, typename TBValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType,
    typename = typename std::enable_if<test::math::integer::fmt::
        Trait<TBValue>::Has, void>::type,
    TSize NA = test::math::integer::fmt::
        Trait<TAValue, TBValue>::Size,
    TSize NB = test::math::integer::fmt::
        Trait<TBValue, TAValue>::Size>
static TElement Subtraction(TAValue& a, const TBValue& b,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType& c = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_a = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_b = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& ed_b = NB, 
    typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType c_b_in = 0, 
    typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType * c_b_out = nullptr)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    TBValue b_cpy = b;
    TElement carry = c;
    TElement c_b_default;
    TElement & c_b = (c_b_out == nullptr ? c_b_default : *c_b_out);
    c_b = c_b_in;
    TExpand b_val;
    TExpand diff = 0;
    for(TSize i = 0, j = bg_b; i < NA; ++i, ++j)
    {
        if (j < ed_b)
        {
            if (j < NB)
            {   
                b_val = TraitBType::GetElement(b_cpy, j);
                c_b = test::math::integer::Negation<TAValue>(b_val, c_b, j);
            }
            else
            {
                b_val = 0;
                c_b = test::math::integer::Negation<TAValue>(b_val, c_b, j);
            }
        }
        else
        {
            b_val = 0;
        }

        diff = TraitAType::GetElement(a, i);
        diff += b_val;
        diff += carry;

        const auto split = TraitType::ExpandSplit(diff);
        TraitAType::SetElement(a, i, TraitType::ExpandElementValue(split));
        carry = TraitType::ExpandCarryValue(split);
    }

    return carry;
}

template<typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType,
    typename = typename std::enable_if<std::is_same<TExpand, 
        typename test::math::integer::fmt::
            Trait<TValue>::ExpandType>::value &&
        test::math::integer::fmt::Trait<TValue>::Has, void>::type,
    TSize N = test::math::integer::fmt::
        Trait<TValue>::Size>
static TElement Subtraction(TValue& a, 
    const typename test::math::integer::fmt::
        Trait<TValue>::ExpandType& b,
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& c = 0, 
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& bg = 0, 
    typename test::math::integer::fmt::
        Trait<TValue>::ElementType c_b_in = 0, 
    typename test::math::integer::fmt::
        Trait<TValue>::ElementType * c_b_out = nullptr)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    TElement carry = c;
    TElement c_b_default;
    TElement & c_b = (c_b_out == nullptr ? c_b_default : *c_b_out);
    c_b = c_b_in;
    TSize i = bg, j = 0;
    if (i < N)
    {
        TExpand diff = 0;
        TExpand b_val;
        const TExpand split_b = TraitType::ExpandSplit(b);
        const TExpand elem_b0 = TraitType::ExpandElementValue(split_b);
        const TExpand elem_b1 = TraitType::ExpandCarryValue(split_b);
        const TExpand (&elem_b)[2]{elem_b0, elem_b1};

        for (; j < 2; ++j, ++i)
        {
            b_val = elem_b[j];
            c_b = test::math::integer::Negation<TraitType>(b_val, c_b, j);

            diff = TraitType::GetElement(a, i);
            diff += b_val;
            diff += carry;
            
            auto split = TraitType::ExpandSplit(diff);
            TraitType::SetElement(a, i, TraitType::ExpandElementValue(split));
            carry = TraitType::ExpandCarryValue(split);
        }
        for (; i < N; ++i)
        {
            b_val = 0;
            c_b = test::math::integer::Negation<TraitType>(b_val, c_b, j);

            diff = TraitType::GetElement(a, i);
            diff += b_val;
            diff += carry;

            const auto split = TraitType::ExpandSplit(diff);
            TraitType::SetElement(a, i, TraitType::ExpandElementValue(split));
            carry = TraitType::ExpandCarryValue(split);
        }
    }
    return carry;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_SUBTRACTION_H_
