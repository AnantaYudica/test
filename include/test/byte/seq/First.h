#ifndef TEST_BYTE_SEQ_FIRST_H_
#define TEST_BYTE_SEQ_FIRST_H_

#include "../../System.h"
#include "../Sequence.h"
#include "../Iterator.h"

#ifndef TEST_BYTE_SEQ_NAMESPACE_DLEVEL

#define TEST_BYTE_SEQ_NAMESPACE_DLEVEL 2

#endif //!TEST_BYTE_SEQ_NAMESPACE_DLEVEL

#ifndef TEST_BYTE_SEQ_NAMESPACE_DEBUG
#define TEST_BYTE_SEQ_NAMESPACE_DEBUG
TEST_SYS_DBG_NAMESPACE_LEVEL_DEFINE(TEST_BYTE_SEQ_NAMESPACE_DLEVEL, 
    "test::byte::seq");
#endif //!TEST_BYTE_SEQ_NAMESPACE_DEBUG

namespace test
{
namespace byte
{
namespace seq
{

template<typename T>
inline test::byte::Sequence<test::byte::seq::Flag::first, T> First(T&& rval)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First<%s>(rval=%p)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), &rval);

    return {std::move(rval)};
}

template<typename T>
inline test::byte::Sequence<test::byte::seq::Flag::first, T> First(T& lval)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First<%s>(lval=%p)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), &lval);

    return {std::forward<T>(lval)};
}

template<typename T>
inline test::byte::Sequence<test::byte::seq::Flag::first, T>
    First(T&& rval, const std::size_t& off)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First<%s>(rval=%p, off=%zu)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), &rval, off);

    return {std::move(rval), off};
}

template<typename T>
inline test::byte::Sequence<test::byte::seq::Flag::first, T>
    First(T& lval, const std::size_t& off)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First<%s>(lval=%p, off=%zu)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(T), &lval, off);
    
    return {std::forward<T>(lval), off};
}

inline test::byte::Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>
First(test::byte::Iterator<const std::uint8_t*>&& begin,
    test::byte::Iterator<const std::uint8_t*>&& end)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First(begin=%p, end=%p)", &begin, &end);
    
    return {std::move(begin), std::move(end)};
}

inline test::byte::Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>
First(test::byte::Iterator<const std::uint8_t*>& begin,
    test::byte::Iterator<const std::uint8_t*>& end)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First(begin=%p, end=%p)", &begin, &end);
    
    typedef test::byte::Iterator<const std::uint8_t*> ConstIteratorType;
    return {std::forward<ConstIteratorType>(begin), 
        std::forward<ConstIteratorType>(end)};
}

inline test::byte::Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>
First(test::byte::Iterator<const std::uint8_t*>&& begin,
    test::byte::Iterator<const std::uint8_t*>&& end,
    const std::size_t& off)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First(begin=%p, end=%p, off=%zu)", &begin, &end, off);
    
    return {std::move(begin), std::move(end), off};
}

inline test::byte::Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>
First(test::byte::Iterator<const std::uint8_t*>& begin,
    test::byte::Iterator<const std::uint8_t*>& end,
    const std::size_t& off)
{
    TEST_SYS_DEBUG(test::sys::Interface, 
        TEST_SYS_DEBUG_NAMESPACE_TYPE("test::byte::seq"), 
            2, NULL, "First(begin=%p, end=%p, off=%zu)", &begin, &end, off);
    
    typedef test::byte::Iterator<const std::uint8_t*> ConstIteratorType;
    return {std::forward<ConstIteratorType>(begin), 
        std::forward<ConstIteratorType>(end), off};
}

} //!seq

} //!byte

} //!test


#endif //!TEST_BYTE_SEQ_FIRST_H_
