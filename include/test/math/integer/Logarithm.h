#ifndef TEST_MATH_INTEGER_LOGARITHM_H_
#define TEST_MATH_INTEGER_LOGARITHM_H_

#include "fmt/Trait.h"

#include <cstdint>

namespace test
{
namespace math
{
namespace integer
{

namespace log
{
    
enum class Flag : int
{
    Ok = 0,
    ZeroValue
};

} //!log

template<std::size_t NElementMaxExponent = -1, typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType,
    typename = typename std::enable_if<test::math::integer::fmt::
        Trait<TValue>::Has, void>::type>
static test::math::integer::log::Flag Logarithm(const TValue& v, 
    typename test::math::integer::fmt::
        Trait<TValue>::SizeType& value_out, 
    typename test::math::integer::fmt::
        Trait<TValue>::ElementType* elem_out = nullptr, 
    typename test::math::integer::fmt::
        Trait<TValue>::SizeType* at_out = nullptr)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    constexpr TElement element_max_exp = 
        NElementMaxExponent >= TraitType::ElementMaxExponent ? 
            TraitType::ElementMaxExponent : NElementMaxExponent;    
    constexpr TSize N = TraitType::Size;

    TElement elem_def;
    TSize at_def;

    TElement* elem_ptr = elem_out != nullptr ? elem_out : &elem_def;
    TSize* at_ptr = at_out != nullptr ? at_out : &at_def;

    for(TSize i = 1; i <= N; ++i)
    {
        auto elem = TraitType::GetElement(v, N - i);
        if (elem == 0) continue;
        *elem_ptr = TraitType::LogElementValue(elem);
        *at_ptr = N - i;
        value_out = *elem_ptr + (*at_ptr * element_max_exp);
        return test::math::integer::log::Flag::Ok;
    }

    *elem_ptr = 0;
    *at_ptr = 0;
    value_out = 0;
    return test::math::integer::log::Flag::ZeroValue;
}

template<std::size_t NElementMaxExponent = -1, typename TValue,
    typename TElement = typename test::math::integer::fmt::
        Trait<TValue>::ElementType,
    typename TExpand = typename test::math::integer::fmt::
        Trait<TValue>::ExpandType,
    typename TSize = typename test::math::integer::fmt::
        Trait<TValue>::SizeType,
    typename = typename std::enable_if<test::math::integer::fmt::
        Trait<TValue>::Has, void>::type>
static test::math::integer::log::Flag Logarithm(const TValue& v_upper,
    const TValue& v_lower,
    typename test::math::integer::fmt::
        Trait<TValue>::SizeType& value_out, 
    typename test::math::integer::fmt::
        Trait<TValue>::ElementType* elem_out = nullptr, 
    typename test::math::integer::fmt::
        Trait<TValue>::SizeType* at_out = nullptr,
    typename test::math::integer::fmt::
        Trait<TValue>::SizeType* v_at_out = nullptr)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    constexpr TElement element_max_exp = 
        NElementMaxExponent >= TraitType::ElementMaxExponent ? 
            TraitType::ElementMaxExponent : NElementMaxExponent;    
    constexpr TSize N = TraitType::Size;
    const TSize value_max_exp = N * element_max_exp;
    constexpr TSize size = N;
    constexpr TSize double_size = size * 2;

    TElement elem_def;
    TSize at_def;
    TSize v_at_def;

    TElement* elem_ptr = elem_out != nullptr ? elem_out : &elem_def;
    TSize* at_ptr = at_out != nullptr ? at_out : &at_def;
    TSize* v_at_ptr = v_at_out != nullptr ? v_at_out : &v_at_def;
    const TValue* (v_map)[2] {&v_lower, &v_upper};
    for(TSize i = 1; i <= double_size; ++i)
    {
        const TSize index_pos = double_size - i;
        const TSize index_map_pos = index_pos / size;
        const TSize index_real_pos = index_pos % size;

        auto elem = TraitType::GetElement(*(v_map[index_map_pos]), 
            index_real_pos);
        if (elem == 0) continue;
        *elem_ptr = TraitType::LogElementValue(elem);
        *at_ptr = (double_size - i) % size;
        *v_at_ptr = 1 - index_map_pos;
        value_out = *elem_ptr + (*at_ptr * element_max_exp) +
            (index_map_pos * value_max_exp);
        return test::math::integer::log::Flag::Ok;
    }

    *elem_ptr = 0;
    *at_ptr = 0;
    *v_at_ptr = 1;
    value_out = 0;
    return test::math::integer::log::Flag::ZeroValue;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_LOGARITHM_H_
