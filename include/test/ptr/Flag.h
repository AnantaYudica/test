#ifndef TEST_PTR_FLAG_H_
#define TEST_PTR_FLAG_H_

#include <cstdint>

namespace test
{
namespace ptr
{

typedef std::uint8_t FlagIntegerType;

enum Flag : std::uint8_t 
{
    empty = 0,
    default_initialization = 1,
    value_initialization = 2,
    array_allocation = 3
};

} //!ptr

} //!test

#endif //!TEST_PTR_FLAG_H_
