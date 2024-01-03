#ifndef TEST_OUT_FMT_FLAG_SHORT_H_
#define TEST_OUT_FMT_FLAG_SHORT_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Short
{
public:
    constexpr Short() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_SHORT_DLEVEL

#define TEST_OUT_FMT_FLAG_SHORT_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_SHORT_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_SHORT_DLEVEL, 
    "test::out::fmt::flag::Short", test::out::fmt::flag::Short);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Short

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagShort{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_SHORT_H_
