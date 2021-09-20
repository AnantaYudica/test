#ifndef TEST_MATH_INTEGER_COMPARISON_H_
#define TEST_MATH_INTEGER_COMPARISON_H_

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
    TSize NA = test::math::integer::fmt::
        Trait<TAValue, TBValue>::Size,
    TSize NB = test::math::integer::fmt::
        Trait<TBValue, TAValue>::Size>
static int Comparison(const TAValue& a, const TBValue& b, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& r_bg_a = NA, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& r_ed_a = 0,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& r_bg_b = NB, 
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& r_ed_b = 0)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    const TSize size_a = r_bg_a - r_ed_a;
    const TSize size_b = r_bg_b - r_ed_b;
    const TSize diff_abs_ab = size_a > size_b ? size_a - size_b : 
        size_b - size_a; 

    if (diff_abs_ab == 0)
    {
        for(TSize ri = r_bg_a, rj = r_bg_b; ri > r_ed_a; --ri, --rj)
        {
            const auto a_val = TraitAType::GetElement(a, ri - 1);
            const auto b_val = TraitBType::GetElement(b, rj - 1);
            if (a_val == b_val) continue;
            return a_val > b_val ? 1 : -1;
        }
        return 0;
    }
    else if (size_a > size_b)
    {
        const TSize ri_ed = r_ed_a + (size_a - diff_abs_ab);
        TSize ri = r_bg_a;
        for (; ri > ri_ed; --ri)
        {
            const auto a_val = TraitAType::GetElement(a, ri - 1);
            if (a_val != 0) return 1;
        }
        for (TSize rj = r_bg_b; rj > r_ed_b; --ri, --rj)
        {
            const auto a_val = TraitAType::GetElement(a, ri - 1);
            const auto b_val = TraitBType::GetElement(b, rj - 1);
            if (a_val == b_val) continue;
            return a_val > b_val ? 1 : -1;
        }
        return 0;
    }
    const TSize rj_ed = r_ed_b + (size_b - diff_abs_ab);
    TSize rj = r_bg_b;
    for (; rj > rj_ed; --rj)
    {
        const auto b_val = TraitBType::GetElement(b, rj - 1);
        if (b_val != 0) return -1;
    }
    for (TSize ri = r_bg_a; ri > r_ed_a; --ri, --rj)
    {
        const auto a_val = TraitAType::GetElement(a, ri - 1);
        const auto b_val = TraitBType::GetElement(b, rj - 1);
        if (a_val == b_val) continue;
        return a_val > b_val ? 1 : -1;
    }
    return 0;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_COMPARISON_H_
