#ifndef TEST_OUT_FMT_FLAG_PREFIXSPACE_H_
#define TEST_OUT_FMT_FLAG_PREFIXSPACE_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class PrefixSpace
{
public:
    constexpr PrefixSpace() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL

#define TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL, 
    "test::out::fmt::flag::PrefixSpace", test::out::fmt::flag::PrefixSpace);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::PrefixSpace

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagPrefixSpace{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_PREFIXSPACE_H_
