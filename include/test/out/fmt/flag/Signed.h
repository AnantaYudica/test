#ifndef TEST_OUT_FMT_FLAG_SIGNED_H_
#define TEST_OUT_FMT_FLAG_SIGNED_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Signed
{
public:
    constexpr Signed() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_SIGNED_DLEVEL

#define TEST_OUT_FMT_FLAG_SIGNED_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_SIGNED_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_SIGNED_DLEVEL, 
    "test::out::fmt::flag::Signed", test::out::fmt::flag::Signed);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Signed

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagSigned{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_SIGNED_H_
