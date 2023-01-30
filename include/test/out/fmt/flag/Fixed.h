#ifndef TEST_OUT_FMT_FLAG_FIXED_H_
#define TEST_OUT_FMT_FLAG_FIXED_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Fixed
{
public:
    constexpr Fixed() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_FIXED_DLEVEL

#define TEST_OUT_FMT_FLAG_FIXED_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_FIXED_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_FIXED_DLEVEL, 
    "test::out::fmt::flag::Fixed", test::out::fmt::flag::Fixed);

#endif //!TEST_OUT_FMT_FLAG_FIXED_H_
