#ifndef TEST_SYS_DBG_TYPE_VALUE_H_
#define TEST_SYS_DBG_TYPE_VALUE_H_

#include "../Type.defn.h"

#include <cstring>
#include <cstdio>

namespace test
{
namespace sys
{
namespace dbg
{
namespace type
{

template<typename T, T V>
class Value
{
public:
   static inline std::size_t WriteTagName(char *, std::size_t)
    {
        return 0;
    }
public:
    static inline std::size_t WriteName(char *, std::size_t)
    {
        return 0;
    }
public:
    inline Value() = delete;
public:
    inline ~Value() = delete;
};


template<typename T, T& V>
class Value<T&, V>
{
public:
   static inline std::size_t WriteTagName(char *, std::size_t)
    {
        return 0;
    }
public:
    static inline std::size_t WriteName(char * name_out, std::size_t n)
    {
        const std::size_t bg_size = snprintf(name_out, n, "(");
        if (bg_size == n)
        {
            return bg_size;
        }
        const std::size_t t_size = test::sys::dbg::Type<T&>::WriteName(name_out + bg_size, 
            n - bg_size);
        const std::size_t before_size = t_size + bg_size;
        if (before_size == n)
        {
            return before_size;
        }
        return snprintf(name_out + before_size, n - before_size, ") %p", 
            &V) + before_size;
    }
public:
    inline Value() = delete;
public:
    inline ~Value() = delete;
};

} //!type

} //!dbg

} //!sys

} //!test


#define TEST_SYS_DBG_TYPE_VALUE_DEFINE(FMT, ...)\
template<__VA_ARGS__ V>\
class test::sys::dbg::type::Value<__VA_ARGS__, V>\
{\
public:\
   static inline std::size_t WriteTagName(char *, std::size_t)\
    {\
        return 0;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        return snprintf(name_out, n , FMT,  V);\
    }\
public:\
    inline Value() = delete;\
public:\
    inline ~Value() = delete;\
}

TEST_SYS_DBG_TYPE_VALUE_DEFINE("%c", char);

TEST_SYS_DBG_TYPE_VALUE_DEFINE("%hhd", signed char);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%hd", short);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%d", int);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%ld", long);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%lld", long long);

TEST_SYS_DBG_TYPE_VALUE_DEFINE("%hhu", unsigned char);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%hu", unsigned short);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%u", unsigned int);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%lu", unsigned long);
TEST_SYS_DBG_TYPE_VALUE_DEFINE("%llu", unsigned long long);

#endif //!TEST_SYS_DBG_TYPE_VALUE_H_
