#ifndef TEST_SYS_DBG_VALUE_H_
#define TEST_SYS_DBG_VALUE_H_

#include "CStr.h"

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <type_traits>
#include <algorithm>

#define TEST_SYS_DBG_VALUE_STRING_LENGTH 128 
#define TEST_SYS_DBG_VALUE_ARRAY_LENGTH 8

namespace test
{
namespace sys
{
namespace dbg
{

template<typename T>
struct Value
{
    static std::size_t Write(char * buff_out, std::size_t n, T&& val)
    {
        return snprintf(buff_out, n, "{...}");
    }
    static std::size_t Write(char * buff_out, std::size_t n, const T&& val)
    {
        return snprintf(buff_out, n, "{...}");
    }
};

template<>
struct Value<void>
{
    static std::size_t Write(char * buff_out, std::size_t n, void*& val)
    {
       return snprintf(buff_out, n, "%p", val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, void*&& val)
    {
       return snprintf(buff_out, n, "%p", val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, const void*& val)
    {
       return snprintf(buff_out, n, "%p", val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, const void*&& val)
    {
       return snprintf(buff_out, n, "%p", val);
    }
};

template<>
struct Value<char>
{
    static std::size_t Write(char * buff_out, std::size_t n, const char& val)
    {
       return snprintf(buff_out, n, "%c", val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, char&& val)
    {
       return snprintf(buff_out, n, "%c", val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, const char*& val)
    {
        const std::size_t max = std::max(n, (std::size_t)TEST_SYS_DBG_VALUE_STRING_LENGTH);
        const std::size_t min = std::min(n, (std::size_t)TEST_SYS_DBG_VALUE_STRING_LENGTH);
        if (min == TEST_SYS_DBG_VALUE_STRING_LENGTH)
        {
            const std::size_t len = snprintf(buff_out, max, "%s", val);
            if (len == TEST_SYS_DBG_VALUE_STRING_LENGTH)
            {
                const std::size_t last = TEST_SYS_DBG_VALUE_STRING_LENGTH - 3;
                snprintf(buff_out + last, n - last, "...");
            }
            return len;
        }
        return snprintf(buff_out, n, "%s", val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, char*& val)
    {
       return Write(buff_out, n, val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, const char*&& val)
    {
       return Write(buff_out, n, val);
    }
    static std::size_t Write(char * buff_out, std::size_t n, char*&& val)
    {
       return Write(buff_out, n, val);
    }
    template<std::size_t N>
    static std::size_t Write(char * buff_out, std::size_t n, char(&val)[N])
    {
       return Write(buff_out, n, val);
    }
    template<std::size_t N>
    static std::size_t Write(char * buff_out, std::size_t n, const char(&val)[N])
    {
       return Write(buff_out, n, val);
    }
};

} //!dbg

} //!sys

} //!test

#define TEST_SYS_DBG_VALUE_DEFINE(TFORMAT, TDEF)\
template<>\
struct test::sys::dbg::Value<TDEF>\
{\
    static std::size_t Write(char * buff_out, std::size_t n, const TDEF& val)\
    {\
        return snprintf(buff_out, n, TFORMAT, val);\
    }\
    static std::size_t Write(char * buff_out, std::size_t n, TDEF&& val)\
    {\
        return snprintf(buff_out, n, TFORMAT, val);\
    }\
}

TEST_SYS_DBG_VALUE_DEFINE("%hhd", signed char);

TEST_SYS_DBG_VALUE_DEFINE("%hd", short);

TEST_SYS_DBG_VALUE_DEFINE("%d", int);

TEST_SYS_DBG_VALUE_DEFINE("%ld", long);

TEST_SYS_DBG_VALUE_DEFINE("%lld", long long);

TEST_SYS_DBG_VALUE_DEFINE("%hhu", unsigned char);

TEST_SYS_DBG_VALUE_DEFINE("%hu", unsigned short);

TEST_SYS_DBG_VALUE_DEFINE("%u", unsigned int);

TEST_SYS_DBG_VALUE_DEFINE("%lu", unsigned long);

TEST_SYS_DBG_VALUE_DEFINE("%llu", unsigned long long);

TEST_SYS_DBG_VALUE_DEFINE("%f", float);

TEST_SYS_DBG_VALUE_DEFINE("%f", double);

TEST_SYS_DBG_VALUE_DEFINE("%Lf", long double);

#undef TEST_SYS_DBG_VALUE_DEFINE


#endif //!TEST_SYS_DBG_VALUE_H_
