#ifndef TEST_OUT_FMT_FLAG_LOWER_H_
#define TEST_OUT_FMT_FLAG_LOWER_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class Lower
{
public:
    constexpr Lower() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_LOWER_DLEVEL

#define TEST_OUT_FMT_FLAG_LOWER_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_LOWER_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_LOWER_DLEVEL, 
    "test::out::fmt::flag::Lower", test::out::fmt::flag::Lower);

#endif //!TEST_OUT_FMT_FLAG_LOWER_H_
