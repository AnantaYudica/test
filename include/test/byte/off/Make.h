#ifndef TEST_BYTE_OFF_MAKE_H_
#define TEST_BYTE_OFF_MAKE_H_

#include "../../System.h"
#include "../Offset.h"

#include <type_traits>
#include <cstddef>

#ifndef TEST_BYTE_OFF_DLEVEL

#define TEST_BYTE_OFF_DLEVEL 2

#endif //!TEST_BYTE_OFF_DLEVEL

#ifndef TEST_BYTE_OFF_NAMESPACE_DEBUG
#define TEST_BYTE_OFF_NAMESPACE_DEBUG
TEST_SYS_DBG_NAMESPACE_LEVEL_DEFINE(TEST_BYTE_OFF_DLEVEL, "test::byte::off");
#endif //!TEST_BYTE_OFF_NAMESPACE_DEBUG

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
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::off"), 
            2, NULL, "Make<%s>(size=%zu, value=%s)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue), size,
        TEST_SYS_DEBUG_TARGS_VALUE_STR(value));

    return {size, std::forward<TValue>(value)};
}

} //!off

} //!byte

} //!test

#endif //!TEST_BYTE_OFF_MAKE_H_
