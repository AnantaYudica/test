#ifndef TEST_SYS_DBG_VAL_PARAMETER_H_
#define TEST_SYS_DBG_VAL_PARAMETER_H_

#include "../Value.h"
#include "../CStr.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <type_traits>

namespace test
{
namespace sys
{
namespace dbg
{
namespace val
{

static std::size_t Parameter(char * buff_out, std::size_t n)
{
    return 0;
}

template<typename TArg, typename... TArgs, typename TPrimary = 
    typename std::remove_all_extents<
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type>::type>
static std::size_t Parameter(char * buff_out, std::size_t n, TArg&& arg, TArgs&&... args)
{
    std::size_t size = test::sys::dbg::Value<TPrimary>::Write(buff_out, n, arg);
    if (size == n)
    {
        return size;
    }
    if (sizeof...(args) != 0)
    {
        size = snprintf(buff_out + size, n - size, ", ") + size;
        if (size == n)
        {
            return size;
        }
    }
    return test::sys::dbg::val::Parameter(buff_out + size, n - size, 
        std::forward<TArgs>(args)...) + size;
}

template<typename TArg, typename... TArgs, typename TPrimary = 
    typename std::remove_all_extents<
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type>::type>
static std::size_t Parameter(char * buff_out, std::size_t n, TArg*&& arg, TArgs&&... args)
{
    std::size_t size = 0;
    if (std::is_same<TPrimary, char>::value || std::is_integral<TPrimary>::value ||
        std::is_floating_point<TPrimary>::value)
    {
        size = test::sys::dbg::Value<TPrimary>::Write(buff_out, n, arg);
    }
    else
    {
        size = test::sys::dbg::Value<void>::Write(buff_out, n, arg);
    }
    if (size == n)
    {
        return size;
    }
    if (sizeof...(args) != 0)
    {
        size = snprintf(buff_out + size, n - size, ", ") + size;
        if (size == n)
        {
            return size;
        }
    }
    return test::sys::dbg::val::Parameter(buff_out + size, n - size, 
        std::forward<TArgs>(args)...) + size;
}

template<std::size_t N, typename TArg, typename... TArgs, typename TPrimary = 
    typename std::remove_all_extents<
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type>::type>
static std::size_t Parameter(char * buff_out, std::size_t n, TArg(&& arg)[N], TArgs&&... args)
{
    std::size_t size = 0;
    if (std::is_same<TPrimary, char>::value)
    {
        size = test::sys::dbg::Value<TPrimary>::Write(buff_out, n, arg);
    }
    else
    {
        for (std::size_t i = 0; i < N && i < TEST_SYS_DBG_VALUE_ARRAY_LENGTH; ++i)
        {
            size = test::sys::dbg::Value<TPrimary>::Write(buff_out, n, arg[0]);
        }
    }
    if (size == n)
    {
        return size;
    }
    if (sizeof...(args) != 0)
    {
        size = snprintf(buff_out + size, n - size, ", ") + size;
        if (size == n)
        {
            return size;
        }
    }
    return test::sys::dbg::val::Parameter(buff_out + size, n - size, 
        std::forward<TArgs>(args)...) + size;
}

template<std::size_t N, typename... TArgs>
static test::sys::dbg::CStr<N>& 
    Parameter(test::sys::dbg::CStr<N>& cstr, TArgs&&... args)
{
    Parameter(cstr.Buffer(), cstr.BufferSize(), std::forward<TArgs>(args)...);
    return cstr;
}

} //!val

} //dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_VAL_PARAMETER_H_
