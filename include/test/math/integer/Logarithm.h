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
        Trait<TValue>::SizeType>
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

    for(TSize i = N; i > 0; --i)
    {
        auto elem = TraitType::GetElement(v, i - 1);
        if (elem == 0) continue;
        *elem_ptr = TraitType::LogElementValue(elem);
        *at_ptr = i - 1;
        value_out = *elem_ptr + (*at_ptr * element_max_exp);
        return test::math::integer::log::Flag::Ok;
    }

    *elem_ptr = 0;
    *at_ptr = 0;
    value_out = 0;
    return test::math::integer::log::Flag::ZeroValue;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_LOGARITHM_H_
