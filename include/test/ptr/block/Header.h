#ifndef TEST_PTR_BLOCK_HEADER_H_
#define TEST_PTR_BLOCK_HEADER_H_

#include "../Flag.h"

#include <cstdint>

namespace test
{
namespace ptr
{
namespace block
{

struct Header
{
    test::ptr::FlagIntegerType flag;
    std::size_t size;
};

} //!block

} //!ptr

} //!test

#endif //!TEST_PTR_BLOCK_HEADER_H_