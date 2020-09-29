#ifndef TEST_FP_FMT_DEFINITION_H_
#define TEST_FP_FMT_DEFINITION_H_

#include "../Format.h"

#include <cfloat>
#include <type_traits>

namespace test
{
namespace fp
{
namespace fmt
{

template<typename T>
struct Definition
{};

template<>
struct Definition<float>
{
#if FLT_MANT_DIG == 24
    typedef test::fp::Format<32> Type;
#elif FLT_MANT_DIG == 53
    typedef test::fp::Format<64> Type;
#elif FLT_MANT_DIG == 64
    typedef test::fp::Format<80> Type;
#else
    #error "FLT_MANT_DIG no condition"
#endif
};

template<>
struct Definition<double>
{
#if DBL_MANT_DIG == 24
    typedef test::fp::Format<32> Type;
#elif DBL_MANT_DIG == 53
    typedef test::fp::Format<64> Type;
#elif DBL_MANT_DIG == 64
    typedef test::fp::Format<80> Type;
#else
    #error "DBL_MANT_DIG no condition"
#endif
};

template<>
struct Definition<long double>
{
#if LDBL_MANT_DIG == 24
    typedef test::fp::Format<32> Type;
#elif LDBL_MANT_DIG == 53
    typedef test::fp::Format<64> Type;
#elif LDBL_MANT_DIG == 64
    typedef test::fp::Format<80> Type;
#else
    #error "LDBL_MANT_DIG no condition"
#endif
};

} //!fmt

} //!fp

} //!test

#endif //!TEST_FP_FMT_DEFINITION_H_
