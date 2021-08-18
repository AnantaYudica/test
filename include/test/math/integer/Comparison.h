#ifndef TEST_MATH_INTEGER_COMPARISON_H_
#define TEST_MATH_INTEGER_COMPARISON_H_

#include <cstddef>
#include <type_traits>

namespace test
{
namespace math
{
namespace integer
{

template<typename TElementValue, typename TAValue, typename TBValue,
    typename TExpandValue, typename TSize, TSize NA, TSize NB, 
    TExpandValue(FGetAValue)(const TAValue&, const TSize&),
    TExpandValue(FGetBValue)(const TBValue&, const TSize&)>
static int Comparison(const TAValue& a, const TBValue& b, 
        const TSize& r_bg_a = NA, const TSize& r_ed_a = 0,
        const TSize& r_bg_b = NB, const TSize& r_ed_b = 0)
{
    const TSize size_a = r_bg_a - r_ed_a;
    const TSize size_b = r_bg_b - r_ed_b;
    const TSize diff_abs_ab = size_a > size_b ? size_a - size_b : size_b - size_a; 
    if (diff_abs_ab == 0)
    {
        for(TSize ri = r_bg_a, rj = r_bg_b; ri > r_ed_a; --ri, --rj)
        {
            const auto a_val = FGetAValue(a, ri - 1);
            const auto b_val = FGetBValue(b, rj - 1);
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
            const auto a_val = FGetAValue(a, ri - 1);
            if (a_val != 0) return 1;
        }
        for (TSize rj = r_bg_b; rj > r_ed_b; --ri, --rj)
        {
            const auto a_val = FGetAValue(a, ri - 1);
            const auto b_val = FGetBValue(b, rj - 1);
            if (a_val == b_val) continue;
            return a_val > b_val ? 1 : -1;
        }
        return 0;
    }
    const TSize rj_ed = r_ed_b + (size_b - diff_abs_ab);
    TSize rj = r_bg_b;
    for (; rj > rj_ed; --rj)
    {
        const auto b_val = FGetBValue(b, rj - 1);
        if (b_val != 0) return -1;
    }
    for (TSize ri = r_bg_a; ri > r_ed_a; --ri, --rj)
    {
        const auto a_val = FGetAValue(a, ri - 1);
        const auto b_val = FGetBValue(b, rj - 1);
        if (a_val == b_val) continue;
        return a_val > b_val ? 1 : -1;
    }
    return 0;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_COMPARISON_H_
