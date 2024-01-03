#ifndef TEST_OUT_FMT_FLAG_DEFINE_H_
#define TEST_OUT_FMT_FLAG_DEFINE_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

template<typename T>
class Define
{
public:
    constexpr Define() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_DEFINE_DLEVEL

#define TEST_OUT_FMT_FLAG_DEFINE_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_DEFINE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_FLAG_DEFINE_DLEVEL, 
    "test::out::fmt::flag::Define", 
    test::out::fmt::flag::Define<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::out::fmt::flag::Define<T>

template<typename T>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("TestOutFmtFlagDefine<%s>{&=%p}", 
    TEST_SYS_DEBUG_T_NAME_STR(T), &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#endif //!TEST_OUT_FMT_FLAG_DEFINE_H_
