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
    DivByZero = -1,
    DivByOne = 1,
    ReachMaxLoopsPredError = -2,
    ReachMaxLoopsNPredError = -3
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
    typename std::remove_pointer<TAValue>::type * rem_out = nullptr,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& max_loops_pred = UINT8_MAX,
    const typename test::math::integer::fmt::
        Trait<TAValue, TBValue>::SizeType& max_loops_n_pred = 4)
{
    
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    constexpr TSize NA = TraitAType::Size;
    constexpr TSize NB = TraitBType::Size;

    constexpr TSize val_a_max_exp = NA * TraitAType::ElementMaxExponent;

    TAValue rem_def{0};
    TAValue& rem = (rem_out == nullptr) ? rem_def : *rem_out;

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
                TraitAType::SetElement(a, i, 0);
            return test::math::integer::div::Flag::DivByZero;
        }
        else if(b_elem == 1)
            return test::math::integer::div::Flag::DivByOne; 
    }
    
    if (diff < 0)
    {
        rem = a;
        for (TSize i = 0; i < NA; ++i)
            TraitAType::SetElement(a, i, 0);
        return test::math::integer::div::Flag::Ok;
    }
    else if(diff == 0)
    {
        for (TSize i = 0; i < NA; ++i)
            TraitAType::SetElement(a, i, 0);
        TraitAType::SetElement(a, 0, 1);
        return test::math::integer::div::Flag::Ok;
    }

    TAValue zero;
    TAValue one;
    TraitAType::SetElement(one, 0, 1);

    rem = a;

    TAValue pred = a;
    a = zero;
    TSize count_pred;
    int direction = 0;

    for (count_pred = 0; count_pred < max_loops_n_pred; ++count_pred)
    {
        TAValue& a_upper = pred;
        TAValue a_lower;
        TAValue b_upper, b_prev_upper;
        TAValue b_lower;
        TAValue f_upper;
        TAValue f_lower;
        
        test::math::integer::Shift<test::math::integer::shift::Right>(a_upper, 
            a_lower, val_a_max_exp);

        for (TSize i = 0; i < NA && i < NB; ++i)
        {
            TraitAType::SetElement(b_lower, i, TraitBType::GetElement(b, i));
        }
        
        // Division used goldschmidt's algorithm
        TSize count;
        bool found = false;
        
        for (count = 0; count < max_loops_pred && !found; ++count)
        {
            TAValue of1;
            TAValue of2;
            
            f_upper = one;
            f_lower = zero;
            
            // F = 2 - D
            {
                test::math::integer::Subtraction(f_upper, f_lower, b_lower);
                TraitAType::SetElement(f_upper, 0, 1);
            }

            // N^ = N * F
            test::math::integer::Multiplication(a_upper, a_lower, f_upper, 
                f_lower, nullptr, &of1);

            // D^ = D * F
            test::math::integer::Multiplication(b_upper, b_lower, f_upper, 
                f_lower, nullptr, &of2);

            // Break condition
            {
                if (count != 0)
                {
                    auto diff = test::math::integer::Comparison(b_prev_upper, 
                        b_upper); 
                    found = diff == 0;
                }

                b_prev_upper = b_upper;
            }
            
            // Normalize 
            {
                const auto check = test::math::integer::Logarithm(of2, 
                    b_upper, exp_b);

                if (exp_b >= val_a_max_exp)
                {
                    const TSize n_shift = exp_b + 1;
                    test::math::integer::Shift<test::math::integer::shift::
                        Right>(of2, b_upper, b_lower, n_shift);
                    test::math::integer::Shift<test::math::integer::shift::
                        Right>(of1, a_upper, a_lower, n_shift);

                }
                else if (check != test::math::integer::log::Flag::ZeroValue)
                {
                    const TSize n_shift = exp_b + 1;
                    test::math::integer::Shift<test::math::integer::shift::
                        Right>(b_upper, b_lower, n_shift);
                    test::math::integer::Shift<test::math::integer::shift::
                        Right>(of1, a_upper, a_lower, n_shift);
                }
            }
        }

        if (!found)
        {
            return test::math::integer::div::Flag::ReachMaxLoopsPredError;
        }

        TAValue of3;
        TAValue pred_a = pred;
        if (direction == 0)
        {
            pred_a = pred;
            a = pred;
        }
        else if (direction < 0)
        {
            test::math::integer::Subtraction(a, pred);
            pred_a = a;
        }
        else
        {
            test::math::integer::Addition(a, pred);
            pred_a = a;
        }
            
        test::math::integer::Multiplication(pred_a, b, &of3);
        const auto diff_zero = test::math::integer::Comparison(of3, zero); 
        const auto diff_rem = test::math::integer::Comparison(pred_a, rem); 

        if (diff_zero > 0 || diff_rem > 0)
        {
            direction = -1;

            test::math::integer::Subtraction(of3, pred_a, rem);
            const auto diff_b = test::math::integer::Comparison(pred_a, b); 
            
            if (diff_b <= 0)
            {
                test::math::integer::Subtraction(a, 1);
                pred_a = a;
                test::math::integer::Multiplication(pred_a, b);
                test::math::integer::Subtraction(rem, pred_a);
                return test::math::integer::div::Flag::Ok;
            }
            
            pred = pred_a;
            continue;
        }
        else if (diff_rem == 0)
        {
            test::math::integer::Subtraction(rem, pred_a);
            return test::math::integer::div::Flag::Ok;
        }
        else
        {
            direction = 1;

            TAValue diff = rem;
            test::math::integer::Subtraction(diff, pred_a);
            const auto diff_b = test::math::integer::Comparison(diff, b); 
            
            if (diff_b < 0)
            {
                test::math::integer::Subtraction(rem, pred_a);
                return test::math::integer::div::Flag::Ok;
            }
            else if (diff_b == 0)
            {
                test::math::integer::Addition(a, 1);
                pred_a = a;
                test::math::integer::Multiplication(pred_a, b);
                test::math::integer::Subtraction(rem, pred_a);
                return test::math::integer::div::Flag::Ok;
            }
            
            pred = diff;
            continue;
        }
    }

    return test::math::integer::div::Flag::ReachMaxLoopsNPredError;
}

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_DIVISION_H_
