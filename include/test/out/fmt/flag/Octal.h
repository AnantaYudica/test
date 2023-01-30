#ifndef TEST_OUT_FMT_FLAG_OCTAL_H_
#define TEST_OUT_FMT_FLAG_OCTAL_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Octal
{
public:
    constexpr Octal() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_OCTAL_DLEVEL

#define TEST_OUT_FMT_FLAG_OCTAL_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_OCTAL_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_OCTAL_DLEVEL, 
    "test::out::fmt::flag::Octal", test::out::fmt::flag::Octal);

#endif //!TEST_OUT_FMT_FLAG_OCTAL_H_
