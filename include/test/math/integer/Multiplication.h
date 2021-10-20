#ifndef TEST_MATH_INTEGER_MULTIPLICATION_H_
#define TEST_MATH_INTEGER_MULTIPLICATION_H_

#include "Addition.h"
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
        Trait<TBValue>::Has, void>::type>
static void Multiplication(TAValue& a, const TBValue& b)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    constexpr TSize NA = TraitAType::Size;
    constexpr TSize NB = TraitBType::Size;

    TAValue sum {0};
    for (TSize i = 0; i < NA; ++i)
    {
        const auto a_val = TraitAType::GetElement(a, i);

        if (a_val == 0) 
        {
            TraitAType::SetElement(a, i, (i < NA ? 
                TraitAType::GetElement(sum, i) : 0));
            continue;
        }

        for (TSize j = 0; j < NB; ++j)
        {
            TExpand mul = TraitBType::GetElement(b, j);
            mul *= a_val;
            test::math::integer::Addition(sum, mul, 0, i + j);
        }

        TraitAType::SetElement(a, i, TraitAType::GetElement(sum, i));
    }
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
static void Multiplication(TAValue& a, const TBValue& b,
    TAValue* overflow_out)
{
    typedef test::math::integer::fmt::Trait<TAValue, TBValue> TraitType;
    typedef test::math::integer::fmt::Trait<TAValue> TraitAType;
    typedef test::math::integer::fmt::Trait<TBValue> TraitBType;

    constexpr TSize NA = TraitAType::Size;
    constexpr TSize NB = TraitBType::Size;

    if (overflow_out == nullptr)
    {
        return test::math::integer::Multiplication(a, b);
    }

    TAValue sum {0};
    for (TSize i = 0; i < NA; ++i)
    {
        const auto a_val = TraitAType::GetElement(a, i);

        if (a_val == 0) 
        {
            TraitAType::SetElement(a, i, (i < NA ? 
                TraitAType::GetElement(sum, i) : 0));
            continue;
        }

        for (TSize j = 0; j < NB; ++j)
        {
            TExpand mul = TraitBType::GetElement(b, j);
            mul *= a_val;
            const TSize ij = i + j;
            if (ij < NA)
            {
                auto c = test::math::integer::Addition(sum, mul, 0, ij);
                if (c != 0)
                    test::math::integer::Addition(*overflow_out, 0, c, 0);
            }
            else
            {
                test::math::integer::Addition(*overflow_out, mul, 0, ij - NA);
            }

        }

        TraitAType::SetElement(a, i, TraitAType::GetElement(sum, i));
    }
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
static void Multiplication(TValue& a, 
    const  typename test::math::integer::fmt::
        Trait<TValue>::ExpandType& b)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    constexpr TSize N = TraitType::Size;

    const TExpand split_b = TraitType::ExpandSplit(b);
    const TExpand elem_b0 = TraitType::ExpandElementValue(split_b);
    const TExpand elem_b1 = TraitType::ExpandCarryValue(split_b);
    const TExpand (&elem_b)[2] {elem_b0, elem_b1};
    
    TValue sum;
    for (TSize i = 0; i < N; ++i)
    {
        const auto a_val = TraitType::GetElement(a, i);
        
        if (a_val == 0) 
        {
            TraitType::SetElement(a, i, (i < N ? 
                TraitType::GetElement(sum, i) : 0));
            continue;
        }
        
        for (TSize j = 0; j < 2; ++j)
        {
            TExpand mul = elem_b[j] * a_val;
            test::math::integer::Addition(sum, mul, 0, i + j);
        }
        
        TraitType::SetElement(a, i, TraitType::GetElement(sum, i));
    }
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
static void Multiplication(TValue& a, 
    const  typename test::math::integer::fmt::
        Trait<TValue>::ExpandType& b,
    TValue* overflow_out)
{
    typedef test::math::integer::fmt::Trait<TValue> TraitType;

    constexpr TSize N = TraitType::Size;
    
    if (overflow_out == nullptr)
    {
        return test::math::integer::Multiplication(a, b);
    }

    const TExpand split_b = TraitType::ExpandSplit(b);
    const TExpand elem_b0 = TraitType::ExpandElementValue(split_b);
    const TExpand elem_b1 = TraitType::ExpandCarryValue(split_b);
    const TExpand (&elem_b)[2] {elem_b0, elem_b1};
    
    TValue sum;
    for (TSize i = 0; i < N; ++i)
    {
        const auto a_val = TraitType::GetElement(a, i);
        
        if (a_val == 0) 
        {
            TraitType::SetElement(a, i, (i < N ? 
                TraitType::GetElement(sum, i) : 0));
            continue;
        }
        
        for (TSize j = 0; j < 2; ++j)
        {
            TExpand mul = elem_b[j] * a_val;
            
            const TSize ij = i + j;
            if (ij < N)
            {
                auto c = test::math::integer::Addition(sum, mul, 0, ij);
                if (c != 0)
                    test::math::integer::Addition(*overflow_out, 0, c, 0);
            }
            else
            {
                 test::math::integer::Addition(*overflow_out, mul, 0, ij - N);
            }
            
        }
        
        TraitType::SetElement(a, i, TraitType::GetElement(sum, i));
    }
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
static void Multiplication(TAValue& a_upper, TAValue& a_lower, 
    const TBValue& b)
{
    TAValue overflow{0};
    test::math::integer::Multiplication(a_lower, b, &overflow);
    test::math::integer::Multiplication(a_upper, b);
    test::math::integer::Addition(a_upper, overflow);
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
static void Multiplication(TAValue& a_upper, TAValue& a_lower, 
    const TBValue& b, TAValue* overflow_out)
{
    if (overflow_out == nullptr)
    {
        return test::math::integer::Multiplication(a_upper, a_lower, b);
    }
    TAValue overflow{0};
    test::math::integer::Multiplication(a_lower, b, &overflow);
    test::math::integer::Multiplication(a_upper, b, overflow_out);
    TElement carry = test::math::integer::Addition(a_upper, overflow);
    test::math::integer::Addition(*overflow_out, carry);
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
static void Multiplication(TAValue& a_upper, TAValue& a_lower, 
    const TBValue& b_upper, const TBValue& b_lower, 
    typename std::remove_pointer<TAValue>::type * overflow_upper_out = nullptr,
    typename std::remove_pointer<TAValue>::type * overflow_lower_out = nullptr)
{
    TAValue overflow_1{0};
    TAValue overflow_2{0};
    TAValue overflow_3{0};
    TAValue overflow_upper_def{0};
    TAValue overflow_lower_def{0};
    TAValue* overflow_upper_ptr = overflow_upper_out == nullptr ?
        &overflow_upper_def : overflow_upper_out;
    TAValue* overflow_lower_ptr = overflow_lower_out == nullptr ?
        &overflow_lower_def : overflow_lower_out;
    TAValue a_lower_cpy = a_lower;
    *overflow_lower_ptr = a_upper;

    test::math::integer::Multiplication(a_lower, b_lower, &overflow_1);
    test::math::integer::Multiplication(a_upper, b_lower, &overflow_2);
    test::math::integer::Multiplication(a_lower_cpy, b_upper, &overflow_3);
    test::math::integer::Multiplication(*overflow_lower_ptr, b_upper, 
        overflow_upper_ptr);

    TElement carry = test::math::integer::Addition(a_upper, overflow_1);
    carry += test::math::integer::Addition(a_upper, a_lower_cpy);

    carry = test::math::integer::Addition(*overflow_lower_ptr, overflow_2, 
        carry);
    carry += test::math::integer::Addition(*overflow_lower_ptr, overflow_2);
    
    test::math::integer::Addition(*overflow_upper_ptr, 0, carry);
}


} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_MULTIPLICATION_H_
