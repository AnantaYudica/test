#ifndef TEST_OUT_FMT_FLAG_PREFIX_H_
#define TEST_OUT_FMT_FLAG_PREFIX_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Prefix
{
public:
    constexpr Prefix() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PREFIX_DLEVEL

#define TEST_OUT_FMT_FLAG_PREFIX_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PREFIX_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PREFIX_DLEVEL, 
    "test::out::fmt::flag::Prefix", test::out::fmt::flag::Prefix);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Prefix

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagPrefix{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_PREFIX_H_
