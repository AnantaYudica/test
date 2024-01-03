#ifndef TEST_OUT_FMT_FLAG_UPPER_H_
#define TEST_OUT_FMT_FLAG_UPPER_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Upper
{
public:
    constexpr Upper() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_UPPER_DLEVEL

#define TEST_OUT_FMT_FLAG_UPPER_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_UPPER_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_UPPER_DLEVEL, 
    "test::out::fmt::flag::Upper", test::out::fmt::flag::Upper);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Upper

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagUpper{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_UPPER_H_
