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
    typedef test::ptr::FlagIntegerType FlagIntegerType;

    typedef void(DestructorFuncType)(void *);

    test::ptr::FlagIntegerType flag;
    DestructorFuncType* destructor;
    std::size_t type_size;
    std::size_t data_size;
};

} //!block

} //!ptr

} //!test

#endif //!TEST_PTR_BLOCK_HEADER_H_