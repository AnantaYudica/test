#ifndef TEST_BYTE_OFF_MAKE_H_
#define TEST_BYTE_OFF_MAKE_H_

#include "../Offset.h"

#include <type_traits>
#include <cstddef>

namespace test
{
namespace byte
{
namespace off
{

template<typename TValue>
inline test::byte::Offset<typename std::remove_cv<
    typename std::remove_reference<TValue>::type>::type> 
Make(const std::size_t& size, TValue&& value)
{
    return {size, std::forward<TValue>(value)};
}

} //!off

} //!byte

} //!test

#endif //!TEST_BYTE_OFF_MAKE_H_
