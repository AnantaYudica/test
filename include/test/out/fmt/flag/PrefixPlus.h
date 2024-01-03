#ifndef TEST_OUT_FMT_FLAG_PREFIXPLUS_H_
#define TEST_OUT_FMT_FLAG_PREFIXPLUS_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class PrefixPlus
{
public:
    constexpr PrefixPlus() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PREFIXPLUS_DLEVEL

#define TEST_OUT_FMT_FLAG_PREFIXPLUS_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PREFIXPLUS_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PREFIXPLUS_DLEVEL, 
    "test::out::fmt::flag::PrefixPlus", test::out::fmt::flag::PrefixPlus);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::PrefixPlus

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagPrefixPlus{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_PREFIXPLUS_H_
