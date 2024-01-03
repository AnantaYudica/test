#ifndef TEST_OUT_FMT_FLAG_UNSIGNED_H_
#define TEST_OUT_FMT_FLAG_UNSIGNED_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Unsigned
{
public:
    constexpr Unsigned() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_UNSIGNED_DLEVEL

#define TEST_OUT_FMT_FLAG_UNSIGNED_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_UNSIGNED_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_UNSIGNED_DLEVEL, 
    "test::out::fmt::flag::Unsigned", test::out::fmt::flag::Unsigned);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Unsigned

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagUnsigned{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_UNSIGNED_H_
