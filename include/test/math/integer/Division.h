#ifndef TEST_MATH_INTEGER_DIVISION_H_
#define TEST_MATH_INTEGER_DIVISION_H_

#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Logarithm.h"
#include "Comparison.h"
#include "Shift.h"

#include <cstdint>

namespace test
{
namespace math
{
namespace integer
{

namespace div
{

enum class Flag : int
{
    Ok = 0,
    DivByZero,
    DivByOne,
    OutOfMaxLoopError,
};

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
static test::math::integer::div::Flag Division(TAValue& a, const TBValue& b,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& max_loop = UINT8_MAX)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    constexpr TSize NA = TraitAType::Size;
    constexpr TSize NB = TraitBType::Size;

    constexpr TSize val_a_max_exp = NA * TraitAType::ElementMaxExponent;

    TSize exp_a = 0, exp_b = 0;
    const auto diff = test::math::integer::Comparison(a, b); 
    const auto res_a = test::math::integer::Logarithm(a, exp_a);
    const auto res_b = test::math::integer::Logarithm(b, exp_b);

    if (exp_b == 0)
    {
        const TElement b_elem = TraitBType::GetElement(b, 0);
        if (res_b == test::math::integer::log::Flag::ZeroValue) 
        {
            for (TSize i = 0; i < NA; ++i)
                TAValue::SetElement(a, i, 0);
            return test::math::integer::div::Flag::DivByZero;
        }
        else if(b_elem == 1)
            return test::math::integer::div::Flag::DivByOne; 
    }
    if (diff <= 0)
    {
        for (TSize i = 0; i < NA; ++i)
            TAValue::SetElement(a, i, 0);
        if (diff == 0)
            TAValue::SetElement(a, 0, 1);
        return test::math::integer::div::Flag::Ok;
    }

    TAValue zero;
    TAValue one;
    TraitAType::SetElement(one, 0, 1);

    TAValue& a_upper = a;
    TAValue a_lower;
    TAValue b_upper, b_prev_upper;
    TAValue b_lower, b_prev_lower;
    TAValue f_upper;
    TAValue f_lower;

    for (TSize i = 0; i < NA && i < NB; ++i)
    {
        TAValue::SetElement(b_lower, i, TBValue::GetElement(b, i));
    }
    
    test::math::integer::Shift<test::math::integer::shift::Right>(a_upper, 
        a_lower, val_a_max_exp);

    // Division used goldschmidt's algorithm
    TSize count;
    bool found = false;
    for (count = 0; count < max_loop && !found; ++count)
    {
        TAValue of1;
        TAValue of2;
        
        f_upper = one;
        f_lower = zero;
        
        // F = 2 - D
        {
            test::math::integer::Subtraction(f_upper, f_lower, b_lower);
            
            TAValue::SetElement(f_upper, 0, 1);
        }

        // N^ = N * F
        test::math::integer::Multiplication(a_upper, a_lower, f_upper, 
            f_lower, nullptr, &of1);

        // D^ = D * F
        test::math::integer::Multiplication(b_upper, b_lower, f_upper, 
            f_lower);
        

        // Break condition
        {
            if (count != 0)
            {
                auto diff = test::math::integer::Comparison(b_prev_upper, 
                    b_upper); 
                if (diff == 0)
                {
                    diff = test::math::integer::Comparison(b_prev_lower, 
                        b_lower); 
                    found = diff == 0;
                }
            }

            b_prev_upper = b_upper;
            b_prev_lower = b_lower;
        }
        
        // Normalize 
        {
            test::math::integer::Logarithm(b_upper, b_lower, exp_b);

            if (exp_b >= val_a_max_exp)
            {
                const TSize n_shift = (exp_b-val_a_max_exp) + 1;
                test::math::integer::Shift<test::math::integer::shift::
                    Right>(b_upper, b_lower, n_shift);
                test::math::integer::Shift<test::math::integer::shift::
                    Right>(of1, a_upper, a_lower, n_shift);

            }
        }

    }

    if (!found)
    {
        return test::math::integer::div::Flag::OutOfMaxLoopError;
    }

    return test::math::integer::div::Flag::Ok;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_DIVISION_H_
