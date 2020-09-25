#ifndef TEST_BYTE_ORDER_BIGENDIAN_H_
#define TEST_BYTE_ORDER_BIGENDIAN_H_

#include "../Order.h"
#include "op/BigEndian.h"

#include <utility>

namespace test
{
namespace byte
{
namespace order
{

template<typename... TArgs>
inline test::byte::Order BigEndian(TArgs&&... args)
{
    return {test::byte::order::op::BigEndian{}, std::forward<TArgs>(args)...};
}

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_BIGENDIAN_H_
