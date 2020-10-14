#ifndef TEST_BIT_INDEX_BIG_H_
#define TEST_BIT_INDEX_BIG_H_

#include <cstddef>
#include <cstdint>

namespace test
{
namespace bit
{
namespace index
{

template<typename TValue>
constexpr std::size_t Big(TValue val, 
    std::size_t size_bit_value = sizeof(TValue) * 8, TValue bit_one = 1)
{
    return (size_bit_value == 0 || (val & (bit_one << (size_bit_value - 1))) ? 
        size_bit_value - 1 : Big(val, size_bit_value - 1, bit_one));
}

} //!index

} //!bit

} //!test

#endif //!TEST_BIT_INDEX_BIG_H_
