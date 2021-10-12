#ifndef TEST_MATH_INTEGER_SHIFT_H_
#define TEST_MATH_INTEGER_SHIFT_H_

#include "fmt/Trait.h"

#include <cstddef>

namespace test
{
namespace math
{
namespace integer
{

namespace shift
{

struct Right;
struct Left;

} //!shift

template<typename TTag, typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType>
static typename std::enable_if<test::math::integer::fmt::
    Trait<TValue>::Has && std::is_same<TTag,
        test::math::integer::shift::Right>::value, void>::type
Shift(TValue& a,
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& n,
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& end_pattern = 0)
{
    typedef typename test::math::integer::fmt::Trait<TValue> TraitType;
    const TSize size = TraitType::Size;
    constexpr TSize elem_max_e = TraitType::ElementMaxExponent;
    const TSize elem_shift_n = n % elem_max_e;
    const TSize inv_elem_shift_n = elem_max_e - elem_shift_n;
    const TSize shift_n = n / elem_max_e;
    TSize l = shift_n > size ? 0 : size - shift_n;

    for(TSize i = 0; i < l; ++i)
    {
        const TSize curr_pos = shift_n + i;
        const TSize next_pos = curr_pos + 1;
        auto curr = TraitType::GetElement(a, curr_pos);
        auto next = end_pattern;
        if (next_pos < size)
            next = TraitType::GetElement(a, next_pos);

        TElement val = TraitType::ShiftRightElementValue(curr, elem_shift_n);
        val |= TraitType::ShiftLeftElementValue(next, inv_elem_shift_n);
        TraitType::SetElement(a, i, val);
    }
    for (TSize i = 0; i < shift_n; ++i)
    {
        TElement val = TraitType::ShiftRightElementValue(end_pattern, 
            elem_shift_n);
        val |= TraitType::ShiftLeftElementValue(end_pattern, inv_elem_shift_n);
        TraitType::SetElement(a, l + i, val);
    }
}

template<typename TTag, typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType>
static typename std::enable_if<test::math::integer::fmt::
    Trait<TValue>::Has && std::is_same<TTag,
        test::math::integer::shift::Left>::value, void>::type
Shift(TValue& a,
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& n,
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& end_pattern = 0)
{
    typedef typename test::math::integer::fmt::Trait<TValue> TraitType;
    const TSize size = TraitType::Size;
    constexpr TSize elem_max_e = TraitType::ElementMaxExponent;
    const TSize elem_shift_n = n % elem_max_e;
    const TSize inv_elem_shift_n = elem_max_e - elem_shift_n;
    const TSize shift_n = n / elem_max_e;
    TSize l = shift_n > size ? 0 : size - shift_n;

    for(TSize i = 1; i <= l; ++i)
    {
        const TSize curr_pos = l - i;
        const TSize next_pos = curr_pos - 1;
        auto curr = TraitType::GetElement(a, curr_pos);
        auto next = end_pattern;
        if (curr_pos > 0)
            next = TraitType::GetElement(a, next_pos);

        TElement val = TraitType::ShiftLeftElementValue(curr, elem_shift_n);
        val |= TraitType::ShiftRightElementValue(next, inv_elem_shift_n);
        TraitType::SetElement(a, size - i, val);
    }
    for (TSize i = 1; i <= shift_n; ++i)
    {
        TElement val = TraitType::ShiftLeftElementValue(end_pattern, 
            elem_shift_n);
        val |= TraitType::ShiftRightElementValue(end_pattern, inv_elem_shift_n);
        TraitType::SetElement(a, shift_n - i, val);
    }
}

template<typename TTag, typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType>
static typename std::enable_if<test::math::integer::fmt::
    Trait<TValue>::Has && std::is_same<TTag,
        test::math::integer::shift::Right>::value, void>::type
Shift(TValue& a_upper, TValue& a_lower,
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& n,
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& end_pattern = 0)
{
    typedef typename test::math::integer::fmt::Trait<TValue> TraitType;
    const TSize size = TraitType::Size;
    const TSize double_size = size * 2;
    constexpr TSize elem_max_e = TraitType::ElementMaxExponent;
    const TSize elem_shift_n = n % elem_max_e;
    const TSize inv_elem_shift_n = elem_max_e - elem_shift_n;
    const TSize shift_n = n / elem_max_e;
    TSize l = shift_n > double_size ? 0 : double_size - shift_n;
    TValue* (a_map)[2] {&a_lower, &a_upper};
    
    for(TSize i = 0; i < l; ++i)
    {
        const TSize curr_pos = shift_n + i;
        const TSize next_pos = curr_pos + 1;
        const TSize curr_map_pos = curr_pos / size;
        const TSize next_map_pos = next_pos / size;
        const TSize index_map_pos = i / size;
        const TSize curr_real_pos = curr_pos % size;
        const TSize next_real_pos = next_pos % size;
        const TSize index_real_pos = i % size;
        TElement curr = TraitType::GetElement(*(a_map[curr_map_pos]), curr_real_pos);
        TElement next = end_pattern;
        if (next_pos < double_size)
            next = TraitType::GetElement(*(a_map[next_map_pos]), next_real_pos);

        TElement val = TraitType::ShiftRightElementValue(curr, elem_shift_n);
        val |= TraitType::ShiftLeftElementValue(next, inv_elem_shift_n);
        TraitType::SetElement(*(a_map[index_map_pos]), index_real_pos, val);
    }
    for (TSize i = 0; i < shift_n; ++i)
    {
        TElement val = TraitType::ShiftRightElementValue(end_pattern, 
            elem_shift_n);
        val |= TraitType::ShiftLeftElementValue(end_pattern, inv_elem_shift_n);
        const TSize rem = l + i;
        const TSize rem_map_pos = rem / size;
        const TSize rem_real_pos = rem % size;
        TraitType::SetElement(*(a_map[rem_map_pos]), rem_real_pos, val);
    }
}

template<typename TTag, typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType>
static typename std::enable_if<test::math::integer::fmt::
    Trait<TValue>::Has && std::is_same<TTag,
        test::math::integer::shift::Left>::value, void>::type
Shift(TValue& a_upper, TValue& a_lower,
    const typename test::math::integer::fmt::
        Trait<TValue>::SizeType& n,
    const typename test::math::integer::fmt::
        Trait<TValue>::ElementType& end_pattern = 0)
{
    typedef typename test::math::integer::fmt::Trait<TValue> TraitType;
    const TSize size = TraitType::Size;
    const TSize double_size = size * 2;
    constexpr TSize elem_max_e = TraitType::ElementMaxExponent;
    const TSize elem_shift_n = n % elem_max_e;
    const TSize inv_elem_shift_n = elem_max_e - elem_shift_n;
    const TSize shift_n = n / elem_max_e;
    TSize l = shift_n > double_size ? 0 : double_size - shift_n;
    TValue* (a_map)[2] {&a_lower, &a_upper};

    for(TSize i = 1; i <= l; ++i)
    {
        const TSize curr_pos = l - i;
        const TSize next_pos = curr_pos - 1;
        const TSize curr_map_pos = curr_pos / size;
        const TSize next_map_pos = next_pos / size;
        const TSize index = double_size - i;
        const TSize index_map_pos = index / size;
        const TSize curr_real_pos = curr_pos % size;
        const TSize next_real_pos = next_pos % size;
        const TSize index_real_pos = index % size;
        TElement curr = TraitType::GetElement(*(a_map[curr_map_pos]), curr_real_pos);
        TElement next = end_pattern;
        if (curr_pos > 0)
            next = TraitType::GetElement(*(a_map[next_map_pos]), next_real_pos);

        TElement val = TraitType::ShiftLeftElementValue(curr, elem_shift_n);
        val |= TraitType::ShiftRightElementValue(next, inv_elem_shift_n);
        TraitType::SetElement(*(a_map[index_map_pos]), index_real_pos, val);
    }
    for (TSize i = 1; i <= shift_n; ++i)
    {
        TElement val = TraitType::ShiftLeftElementValue(end_pattern, 
            elem_shift_n);
        val |= TraitType::ShiftRightElementValue(end_pattern, inv_elem_shift_n);
        const TSize rem = shift_n - i;
        const TSize rem_map_pos = rem / size;
        const TSize rem_real_pos = rem % size;
        TraitType::SetElement(*(a_map[rem_map_pos]), rem_real_pos, val);
    }
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_SHIFT_H_
