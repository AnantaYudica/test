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

#ifndef TEST_OUT_FMT_FLAG_DEFINEL_DLEVEL

#define TEST_OUT_FMT_FLAG_DEFINEL_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_DEFINEL_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_FLAG_DEFINEL_DLEVEL, 
    "test::out::fmt::flag::Define", 
    test::out::fmt::flag::Define<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_OUT_FMT_FLAG_DEFINE_H_
