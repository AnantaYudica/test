#ifndef TEST_OUT_FMT_FLAG_PREFIXZERO_H_
#define TEST_OUT_FMT_FLAG_PREFIXZERO_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class PrefixZero
{
public:
    constexpr PrefixZero() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL

#define TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL, 
    "test::out::fmt::flag::PrefixZero", test::out::fmt::flag::PrefixZero);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::PrefixZero

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagPrefixZero{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_PREFIXZERO_H_
