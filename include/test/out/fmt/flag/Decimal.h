#ifndef TEST_OUT_FMT_FLAG_DECIMAL_H_
#define TEST_OUT_FMT_FLAG_DECIMAL_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Decimal
{
public:
    constexpr Decimal() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_DECIMAL_DLEVEL

#define TEST_OUT_FMT_FLAG_DECIMAL_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_DECIMAL_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_DECIMAL_DLEVEL, 
    "test::out::fmt::flag::Decimal", test::out::fmt::flag::Decimal);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Decimal

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagDecimal{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_DECIMAL_H_
