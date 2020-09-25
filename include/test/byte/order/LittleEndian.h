#ifndef TEST_BYTE_ORDER_LITTLEENDIAN_H_
#define TEST_BYTE_ORDER_LITTLEENDIAN_H_

#include "../Order.h"
#include "op/LittleEndian.h"

#include <utility>

namespace test
{
namespace byte
{
namespace order
{

template<typename... TArgs>
inline test::byte::Order LittleEndian(TArgs&&... args)
{
    return {test::byte::order::op::LittleEndian{}, std::forward<TArgs>(args)...};
}

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_LITTLEENDIAN_H_
