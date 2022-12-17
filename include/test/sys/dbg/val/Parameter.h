#ifndef TEST_SYS_DBG_VAL_PARAMETER_H_
#define TEST_SYS_DBG_VAL_PARAMETER_H_

#include "../Value.h"
#include "../CStr.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <type_traits>

#define TEST_SYS_DBG_VAL_PARAMETER_LENGTH 8

namespace test
{
namespace sys
{
namespace dbg
{
namespace val
{

template<int LEN = 0>
static std::size_t Parameter(char * buff_out, std::size_t n)
{
    return 0;
}

template<int LEN = 0, typename TArg, typename... TArgs, 
    typename TPrimary = typename std::remove_all_extents<
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type>::type>
static typename std::enable_if<!std::is_pointer<
    typename std::remove_reference<TArg>::type>::value  ||
    std::is_same<char, TPrimary>::value, std::size_t>::type  
Parameter(char * buff_out, std::size_t n, TArg&& arg, TArgs&&... args);

template<int LEN = 0, typename TArg, typename... TArgs,
    typename TPrimary = typename std::remove_all_extents<
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type>::type>
static typename std::enable_if<std::is_pointer<
    typename std::remove_reference<TArg>::type>::value &&
    !std::is_same<char, TPrimary>::value, std::size_t>::type  
Parameter(char * buff_out, std::size_t n, TArg&& arg, TArgs&&... args);

template<int LEN , typename TArg, typename... TArgs, typename TPrimary>
static typename std::enable_if<!std::is_pointer<
    typename std::remove_reference<TArg>::type>::value ||
    std::is_same<char, TPrimary>::value, std::size_t>::type  
Parameter(char * buff_out, std::size_t n, TArg&& arg, TArgs&&... args)
{
    std::size_t size = test::sys::dbg::Value<TPrimary>::Write(buff_out, n, 
        std::forward<TArg>(arg));
    if (size == n)
    {
        return size;
    }
    if (sizeof...(args) != 0)
    {   
        if ((LEN + 1) > TEST_SYS_DBG_VAL_PARAMETER_LENGTH)
        {
            return snprintf(buff_out + size, n - size, ", ...") + size;
        }
        size = snprintf(buff_out + size, n - size, ", ") + size;
        if (size == n)
        {
            return size;
        }
    }
    return test::sys::dbg::val::Parameter<LEN + 1>(buff_out + size, 
        n - size, std::forward<TArgs>(args)...) + size;
}

template<int LEN, typename TArg, typename... TArgs, typename TPrimary>
static typename std::enable_if<std::is_pointer<
    typename std::remove_reference<TArg>::type>::value &&
    !std::is_same<char, TPrimary>::value, std::size_t>::type  
Parameter(char * buff_out, std::size_t n, TArg&& arg, TArgs&&... args)
{
    std::size_t size = test::sys::dbg::Value<void>::Write(buff_out, n, 
        std::forward<TArg>(arg));
    if (size == n)
    {
        return size;
    }
    if (sizeof...(args) != 0)
    {
        if ((LEN + 1) > TEST_SYS_DBG_VAL_PARAMETER_LENGTH)
        {
            return snprintf(buff_out + size, n - size, ", ...") + size;
        }
        size = snprintf(buff_out + size, n - size, ", ") + size;
        if (size == n)
        {
            return size;
        }
    }
    return test::sys::dbg::val::Parameter<LEN + 1>(buff_out + size, 
        n - size, std::forward<TArgs>(args)...) + size;
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
