#ifndef TEST_MATH_INTEGER_NEGATION_H_
#define TEST_MATH_INTEGER_NEGATION_H_

#include "fmt/Trait.h"

#include <cstddef>

namespace test
{
namespace math
{
namespace integer
{

template<typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType,
    typename = typename std::enable_if<test::math::integer::fmt::
        Trait<TValue>::Has, void>::type,
    TSize N = test::math::integer::fmt::Trait<TValue>::Size>
TElement Negation(TValue& v, 
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& c = 0,
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& bg = 0, 
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& ed = N)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    TElement carry = c;
    TExpand sum = 0;
    for (TSize i = bg; i < ed; ++i)
    {
        sum = TraitType::ExpandNegationValue(TraitType::GetElement(v, i), i);
        sum += carry;
        const auto split = TraitType::ExpandSplit(sum);
        TraitType::SetElement(v, i, TraitType::ExpandElementValue(split));
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
TElement Negation(typename test::math::integer::fmt::
        Trait<TValue>::ExpandType& v, 
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& c = 0, 
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& i = 0)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;
    
    TElement carry = c;
    TExpand sum = 0;

    sum = TraitType::ExpandNegationValue(v, i);
    sum += carry;
    const auto split = TraitType::ExpandSplit(sum);
    v = TraitType::ExpandElementValue(split);
    carry = TraitType::ExpandCarryValue(split);
    
    return carry;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_NEGATION_H_
