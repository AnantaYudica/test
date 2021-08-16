#ifndef TEST_MATH_INTEGER_MULTIPLICATION_H_
#define TEST_MATH_INTEGER_MULTIPLICATION_H_

#include "Addition.h"

#include <cstddef>

namespace test
{
namespace math
{
namespace integer
{

template<typename TElementValue, typename TAValue, typename TBValue, 
    typename TExpandValue, typename TSize, TSize NA, TSize NB, 
    TElementValue(FSetAValue)(TAValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetAValue)(const TAValue&, const TSize&),
    TExpandValue(FGetBValue)(const TBValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementDefault = 0>
static void Multiplication(TAValue& a, const TBValue& b)
{
    TAValue sum {0};
    for (TSize i = 0; i < NA; ++i)
    {
        const auto a_val = FGetAValue(a, i);

        if (a_val == 0) 
        {
            FSetAValue(a, i, (i < NA ? FGetAValue(sum, i) : 0));
            continue;
        }

        for (TSize j = 0; j < NB; ++j)
        {
            TExpandValue mul = FGetBValue(b, j);
            mul *= a_val;
            test::math::integer::Addition<TElementValue,
                TAValue, TExpandValue, TSize, NA,
                FSetAValue, FGetAValue, FSplitValue, 
                FElementValue, FCarryValue, 
                VElementDefault>(sum, mul, 0, i + j);
        }

        FSetAValue(a, i, FGetAValue(sum, i));
    }
}

template<typename TElementValue, typename TValue, 
    typename TExpandValue, typename TSize, TSize N, 
    TElementValue(FSetValue)(TValue&, const TSize&,
        const TElementValue&),
    TExpandValue(FGetValue)(const TValue&, const TSize&),
    TExpandValue(FSplitValue)(const TExpandValue&),
    TElementValue(FElementValue)(const TExpandValue&),
    TElementValue(FCarryValue)(const TExpandValue&),
    TElementValue VElementDefault = 0>
static void Multiplication(TValue& a, const TExpandValue& b)
{
    
    const TExpandValue split_b = FSplitValue(b);
    const TExpandValue elem_b0 = FElementValue(split_b);
    const TExpandValue elem_b1 = FCarryValue(split_b);
    const TExpandValue (&elem_b)[2] {elem_b0, elem_b1};
    
    TValue sum;
    for (TSize i = 0; i < N; ++i)
    {
        const auto a_val = FGetValue(a, i);
        
        if (a_val == 0) 
        {
            FSetValue(a, i, (i < N ? FGetValue(sum, i) : 0));
            continue;
        }
        
        for (TSize j = 0; j < 2; ++j)
        {
            TExpandValue mul = elem_b[j] * a_val;
            test::math::integer::Addition<TElementValue,
                TValue, TExpandValue, TSize, N,
                FSetValue, FGetValue, FSplitValue, 
                FElementValue, FCarryValue, 
                VElementDefault>(sum, mul, 0, i + j);
        }
        
        FSetValue(a, i, FGetValue(sum, i));
    }
} 

} //!integer

} //!math

} //!test

#endif //!TEST_MATH_INTEGER_MULTIPLICATION_H_
