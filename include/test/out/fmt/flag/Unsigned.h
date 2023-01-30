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

#endif //!TEST_OUT_FMT_FLAG_UNSIGNED_H_
