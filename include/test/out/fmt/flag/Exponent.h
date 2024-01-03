#ifndef TEST_OUT_FMT_FLAG_EXPONENT_H_
#define TEST_OUT_FMT_FLAG_EXPONENT_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Exponent
{
public:
    constexpr Exponent() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_EXPONENT_DLEVEL

#define TEST_OUT_FMT_FLAG_EXPONENT_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_EXPONENT_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_EXPONENT_DLEVEL, 
    "test::out::fmt::flag::Exponent", test::out::fmt::flag::Exponent);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Exponent

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagExponent{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_EXPONENT_H_
