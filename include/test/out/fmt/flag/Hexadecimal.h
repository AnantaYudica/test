#ifndef TEST_OUT_FMT_FLAG_HEXADECIMAL_H_
#define TEST_OUT_FMT_FLAG_HEXADECIMAL_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Hexadecimal
{
public:
    constexpr Hexadecimal() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_HEXADECIMAL_DLEVEL

#define TEST_OUT_FMT_FLAG_HEXADECIMAL_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_HEXADECIMAL_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_HEXADECIMAL_DLEVEL, 
    "test::out::fmt::flag::Hexadecimal", test::out::fmt::flag::Hexadecimal);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Hexadecimal

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagHexadecimal{&=%p}", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_HEXADECIMAL_H_
