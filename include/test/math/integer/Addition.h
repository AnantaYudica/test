#ifndef TEST_MATH_INTEGER_ADDITION_H_
#define TEST_MATH_INTEGER_ADDITION_H_

#include "fmt/Trait.h"

#include <cstddef>
#include <type_traits>

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
        Trait<TBValue>::Has, void>::type>
static TElement Addition(TAValue& a, const TBValue& b,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType& c = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_a = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_b = 0)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    constexpr TSize NA = TraitAType::Size;
    constexpr TSize NB = TraitBType::Size;
    
    TElement carry = c;
    TExpand sum = 0;
    if (bg_b >= NB) return carry;
    for (TSize i_a = bg_a, i_b = bg_b; i_a < NA; ++i_a, ++i_b)
    {
        sum = TraitAType::GetElement(a, i_a);
        if (i_b < NB)
            sum += TraitBType::GetElement(b, i_b);
        sum += carry;
        const auto split = TraitType::ExpandSplit(sum);
        TraitAType::SetElement(a, i_a, TraitType::ExpandElementValue(split));
        carry = TraitType::ExpandCarryValue(split);
    }
    return carry;
}

template<typename TAValue, typename TBValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType,
    typename = typename std::enable_if<test::math::integer::fmt::
        Trait<TBValue>::Has, void>::type>
static TElement Addition(TAValue& a, const TBValue& b,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType& c, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_a, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_b, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& ed_b)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;
    
    constexpr TSize NA = TraitAType::Size;
    constexpr TSize NB = TraitBType::Size;

    TElement carry = c;
    TExpand sum = 0;
    const TSize end_b = bg_b < ed_b ? (ed_b < NB ? ed_b : NB) : bg_b;
    if (bg_b >= end_b) return carry;
    for (TSize i_a = bg_a, i_b = bg_b; i_a < NA; ++i_a, ++i_b)
    {
        sum = TraitAType::GetElement(a, i_a);
        if (i_b < end_b)
            sum += TraitBType::GetElement(b, i_b);
        sum += carry;
        const auto split = TraitType::ExpandSplit(sum);
        TraitAType::SetElement(a, i_a, TraitType::ExpandElementValue(split));
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
        test::math::integer::fmt::Trait<TValue>::Has, void>::type>
static TElement Addition(TValue& a, 
    const typename test::math::integer::fmt::
        Trait<TValue>::ExpandType& b,
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& c = 0, 
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& bg = 0)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    constexpr TSize N = TraitType::Size;

    TSize i = bg;
    if (i > N) return c;

    TElement carry = c;
    TExpand sum = 0;
    const auto split_b = TraitType::ExpandSplit(b);
    const TExpand elem_b0 = TraitType::ExpandElementValue(split_b);
    const TExpand elem_b1 = TraitType::ExpandCarryValue(split_b);
    const TExpand (&elem_b)[2]{elem_b0, elem_b1};

    for (int j = 0; j < 2; ++j, ++i)
    {
        if (i < N) sum = TraitType::GetElement(a, i);
        else sum = 0;
        sum += elem_b[j];
        sum += carry;

        auto split = TraitType::ExpandSplit(sum);
        carry = TraitType::ExpandCarryValue(split);
        if (i < N) 
            TraitType::SetElement(a, i, TraitType::ExpandElementValue(split));
        else if (j == 0)
            return (carry += TraitType::ExpandElementValue(split));
        else
            return TraitType::ExpandElementValue(split);
    }
    for (; (i < N && carry != 0); ++i)
    {
        sum = TraitType::GetElement(a, i);
        sum += carry;
        const auto split = TraitType::ExpandSplit(sum);
        TraitType::SetElement(a, i, TraitType::ExpandElementValue(split));
        carry = TraitType::ExpandCarryValue(split);
    }
    return carry;
}

template<typename TAValue, typename TBValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType,
    TSize NA = test::math::integer::fmt::
        Trait<TAValue, TBValue>::Size,
    TSize NB = test::math::integer::fmt::
        Trait<TBValue, TAValue>::Size,
    typename = typename std::enable_if<test::math::integer::fmt::
        Trait<TBValue>::Has, void>::type>
static TElement Addition(TAValue& a_upper, TAValue& a_lower, const TBValue& b,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::ElementType& c = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_a = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& bg_b = 0, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& ed_b = NB)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;
    
    TElement carry = c;
    if (bg_a >= NA)
    {
        return test::math::integer::Addition(a_upper, b, carry, 
            bg_a - NA, bg_b, ed_b);
    }
    carry = test::math::integer::Addition(a_lower, b, carry, bg_a, bg_b, ed_b);
    const TSize size_a_lower = NA - bg_a;
    const TSize size_b = bg_b >= ed_b ? 0 : ed_b - bg_b;
    if (size_a_lower > size_b)
        return carry;
    else if (size_a_lower == size_b)
        return test::math::integer::Addition(a_upper, carry);
    return test::math::integer::Addition(a_upper, b, carry, 0, 
        bg_b + size_a_lower, ed_b);
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_ADDITION_H_
