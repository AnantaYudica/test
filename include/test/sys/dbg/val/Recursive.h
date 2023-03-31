#ifndef TEST_SYS_DBG_VAL_RECURSIVE_H_
#define TEST_SYS_DBG_VAL_RECURSIVE_H_

#include "../Value.h"
#include "../CStr.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <type_traits>

#define TEST_SYS_DBG_VAL_RECURSIVE_MAXIMUM 8

namespace test
{
namespace sys
{
namespace dbg
{
namespace val
{

template<typename TDerive>
struct Recursive
{
    template<std::size_t N = 0, typename TVal>
    static std::size_t Write(char * buff_out, std::size_t n, TVal&& val)
    {
        return 0;
    }
    
    template<std::size_t N, typename TVal>
    static test::sys::dbg::CStr<N>& 
        Write(test::sys::dbg::CStr<N>& cstr, TVal&& val)
    {
        return cstr;
    }
};

} //!val

} //dbg

} //!sys

} //!test

#define TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE(FORMAT, CONJ, ...)\
struct test::sys::dbg::val::Recursive<\
    TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_DERIVED>\
{\
    template<std::size_t N = 0, typename TVal,\
        typename TDerived = TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_DERIVED,\
        typename TBase = TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_BASE,\
        typename TNext = TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_NEXT,\
        typename TCond = std::is_same<TDerived, TBase>,\
        typename std::enable_if<!TCond::value, int>::type = 1>\
    static std::size_t Write(char * buff_out, std::size_t n,\
        TVal&& val)\
    {\
        std::size_t size = snprintf(buff_out, n, FORMAT, ##__VA_ARGS__);\
        if ((N + 1) >= TEST_SYS_DBG_VAL_RECURSIVE_MAXIMUM)\
        {\
            return snprintf(buff_out + size, n - size, CONJ "...") + size;\
        }\
        size = snprintf(buff_out + size, n - size, CONJ) + size;\
        if (size == n)\
        {\
            return size;\
        }\
        return test::sys::dbg::val::Recursive<TNext>::\
            template Write<N+1>(buff_out + size, n,\
            TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_NEXT_CAST) + size;\
    }\
\
    template<std::size_t N = 0, typename TVal,\
        typename TDerived = TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_DERIVED,\
        typename TBase = TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_BASE,\
        typename TNext = TEST_SYS_DBG_VALUE_RECURSIVE_DEFINE_T_NEXT,\
        typename TCond = std::is_same<TDerived, TBase>,\
        typename std::enable_if<TCond::value, int>::type = 0>\
    static std::size_t Write(char * buff_out, std::size_t n,\
        TVal&& val)\
    {\
        return snprintf(buff_out, n, FORMAT, ##__VA_ARGS__);\
    }\
\
    template<std::size_t N, typename TVal>\
    static test::sys::dbg::CStr<N>& \
        Write(test::sys::dbg::CStr<N>& cstr, TVal&& val)\
    {\
        Write(cstr.Buffer(), cstr.BufferSize(), std::forward<TVal>(val));\
        return cstr;\
    }\
}

#endif //!TEST_SYS_DBG_VAL_PARAMETER_H_
