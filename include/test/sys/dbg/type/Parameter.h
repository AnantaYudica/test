#ifndef TEST_SYS_DBG_TYPE_PARAMETER_H_
#define TEST_SYS_DBG_TYPE_PARAMETER_H_

#include "../CStr.h"

#include <cstring>

#define TEST_SYS_DBG_TYPE_PARAMETER_NAME_LENGTH 8

namespace test
{
namespace sys
{
namespace dbg
{
namespace type
{

template<typename ... TArgs>
class Parameter
{
public:
    static constexpr bool IsEnd = true;
public:
    static inline std::size_t WriteTagName(char * name_out, std::size_t n)
    {
        if (n == 0) return 0;
        name_out[0] = '\0';
        return 0;
    }
public:
    static inline std::size_t WriteName(char * tag_out, std::size_t n, int len = 0)
    {
        if (n == 0) return 0;
        tag_out[0] = '\0';
        return 0;
    }
public:
    template<std::size_t N>
    static inline test::sys::dbg::CStr<N>& 
        WriteName(test::sys::dbg::CStr<N>& cstr)
    {
        return cstr;
    }
public:
    inline Parameter() = delete;
public:
    inline ~Parameter() = delete;
};

template<typename TArg, typename ... TArgs>
class Parameter<TArg, TArgs...>
{
public:
    static constexpr bool IsEnd = false;
public:
    static inline std::size_t WriteName(char * name_out, std::size_t n, int len = 0)
    {
        const std::size_t t_size = TArg::WriteName(name_out, n);
        if (t_size == n)
        {
            return n;
        }
        std::size_t conj_ch_size = 0;
        if (!Parameter<TArgs...>::IsEnd)
        {
            if ((len + 1) >= TEST_SYS_DBG_TYPE_PARAMETER_NAME_LENGTH)
            {
                conj_ch_size = snprintf(name_out + t_size, n - t_size, ", ...");
                return t_size + conj_ch_size;
            }
            else
            {
                conj_ch_size = snprintf(name_out + t_size, n - t_size, ", ");
            }
        }
        const std::size_t before_size = t_size + conj_ch_size;
        if (before_size == n)
        {
            return n;
        }
        return Parameter<TArgs...>::WriteName(name_out + before_size,
            n - before_size, len + 1) + before_size;
         
    }
public:
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)
    {
        return WriteName(tag_out, n);
    }
public:
    template<std::size_t N>
    static inline test::sys::dbg::CStr<N>& 
        WriteName(test::sys::dbg::CStr<N>& cstr)
    {
        WriteName(cstr.Buffer(), cstr.BufferSize());
        return cstr;
    }
public:
    inline Parameter() = delete;
public:
    inline ~Parameter() = delete;
};

template<>
class Parameter<>
{
public:
    static constexpr bool IsEnd = true;
public:
    static inline std::size_t WriteTagName(char *, std::size_t)
    {
        return 0;
    }
public:
    static inline std::size_t WriteName(char *, std::size_t, int len = 0)
    {
        return 0;
    }
public:
    template<std::size_t N>
    static inline test::sys::dbg::CStr<N>& 
        WriteName(test::sys::dbg::CStr<N>& cstr)
    {
        return cstr;
    }
public:
    inline Parameter() = delete;
public:
    inline ~Parameter() = delete;
};

} //!type

} //!dbg

} //!sys

} //!test

#endif //!TEST_SYS_DBG_TYPE_PARAMETER_H_
