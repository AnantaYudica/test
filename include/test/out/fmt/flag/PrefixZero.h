#ifndef TEST_OUT_FMT_FLAG_PREFIXZERO_H_
#define TEST_OUT_FMT_FLAG_PREFIXZERO_H_

#include "../../../System.h"

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class PrefixZero
{
public:
    constexpr PrefixZero() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL

#define TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PREFIXZERO_DLEVEL, 
    "test::out::fmt::flag::PrefixZero", test::out::fmt::flag::PrefixZero);

#endif //!TEST_OUT_FMT_FLAG_PREFIXZERO_H_
