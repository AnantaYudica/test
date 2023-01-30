#ifndef TEST_OUT_FMT_FLAG_PREFIXSPACE_H_
#define TEST_OUT_FMT_FLAG_PREFIXSPACE_H_

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

class PrefixSpace
{
public:
    constexpr PrefixSpace() = default;
};

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL

#define TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_FLAG_PREFIXSPACE_DLEVEL, 
    "test::out::fmt::flag::PrefixSpace", test::out::fmt::flag::PrefixSpace);

#endif //!TEST_OUT_FMT_FLAG_PREFIXSPACE_H_
