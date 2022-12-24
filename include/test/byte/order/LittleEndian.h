#ifndef TEST_BYTE_ORDER_LITTLEENDIAN_H_
#define TEST_BYTE_ORDER_LITTLEENDIAN_H_

#include "../../System.h"
#include "../Order.h"
#include "op/LittleEndian.h"

#include <utility>

#ifndef TEST_BYTE_ORDER_NAMESPACE_DLEVEL

#define TEST_BYTE_ORDER_NAMESPACE_DLEVEL 2

#endif //!TEST_BYTE_ORDER_NAMESPACE_DLEVEL

#ifndef TEST_BYTE_ORDER_NAMESPACE_DEBUG
#define TEST_BYTE_ORDER_NAMESPACE_DEBUG
TEST_SYS_DBG_NAMESPACE_LEVEL_DEFINE(TEST_BYTE_ORDER_NAMESPACE_DLEVEL, 
    "test::byte::order");
#endif //!TEST_BYTE_ORDER_NAMESPACE_DEBUG

namespace test
{
namespace byte
{
namespace order
{

template<typename... TArgs>
inline test::byte::Order LittleEndian(TArgs&&... args)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::order"), 
            2, NULL, "LittleEndian<%s>(args={%s})",
        TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...), 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));

    return {test::byte::order::op::LittleEndian{}, std::forward<TArgs>(args)...};
}

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_LITTLEENDIAN_H_
