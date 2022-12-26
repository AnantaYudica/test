#ifndef TEST_BYTE_RESIZE_H_
#define TEST_BYTE_RESIZE_H_

#include "../System.h"
#include "../Byte.h"

#include <algorithm>

#ifndef TEST_BYTE_NAMESPACE_DLEVEL

#define TEST_BYTE_NAMESPACE_DLEVEL 2

#endif //!TEST_BYTE_NAMESPACE_DLEVEL

#ifndef TEST_BYTE_NAMESPACE_DEBUG
#define TEST_BYTE_NAMESPACE_DEBUG
TEST_SYS_DBG_NAMESPACE_LEVEL_DEFINE(TEST_BYTE_NAMESPACE_DLEVEL, 
    "test::byte");
#endif //!TEST_BYTE_NAMESPACE_DEBUG

namespace test
{
namespace byte
{

template<std::size_t N, bool Sign = false, std::size_t RN, bool RSign>
inline test::Byte<N, Sign> Resize(const test::Byte<RN, RSign>& src, 
    const std::size_t& r_off = 0, const std::size_t& r_size = RN,
    const std::size_t& l_off = 0, const std::size_t& l_size = N)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte"), 
            2, NULL, "Resize<%s>(src=%p, r_off=%zu, r_size=%zu, "
                "l_off=%zu, l_size=%zu)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, N),
            TEST_SYS_DEBUG_TV_TYPE(bool, Sign),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &src, r_off,
        r_size, l_off, l_size);

    const std::size_t nr_size = std::min(r_size, RN);
    const std::size_t nl_size = std::min(l_size, N);
    const std::size_t r_end = r_size + r_off;
    const std::size_t l_end = l_size + l_off;
    const std::size_t min_size = std::min(std::min(nl_size, nr_size),
        std::min(r_end, l_end));
    test::Byte<N, Sign> res;
    std::size_t j = l_off;
    std::size_t k = r_off;
    for (std::size_t i = 0; i < min_size; ++i, ++j, ++k)
    {
        res[j] = src[k];
    }
    return res;
}

} //!byte

} //!test

#endif //!TEST_BYTE_RESIZE_H_
