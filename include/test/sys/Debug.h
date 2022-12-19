#ifndef TEST_SYS_DEBUG_H_
#define TEST_SYS_DEBUG_H_

#include "Debug.defn.h"

namespace test
{
namespace sys
{

inline typename Debug::CStrType& Debug::GetBufferT()
{
    static CStrType instance;
    *(instance.Buffer()) = '\0';
    return instance;
}

inline typename Debug::CStrType& Debug::GetBufferV()
{
    static CStrType instance;
    *(instance.Buffer()) = '\0';
    return instance;
}

inline std::size_t Debug::WriteTagName(char * tag_out, std::size_t n)
{
    return snprintf(tag_out, n, "unknown");
}

inline std::size_t Debug::WriteName(char * name_out, std::size_t n)
{
    return snprintf(name_out, n, "?");
}

inline Debug::Debug() :
    m_level(0xFF)
{}

inline Debug::Debug(std::int8_t level) :
    m_level(level)
{}

inline Debug::~Debug()
{}

inline void Debug::SetLevel(std::int8_t level)
{
    m_level = level;
}

inline std::int8_t Debug::GetLevel()
{
    return m_level;
}

inline std::size_t Debug::TagName(char * tag_out, std::size_t n)
{
    const std::size_t bg_size = snprintf(tag_out, n, "[");
    if (bg_size == n)
    {
        return bg_size;
    }
    const std::size_t t_size = 
        WriteTagName(tag_out + bg_size, n - bg_size) + bg_size;
    if (t_size == n)
    {
        return t_size;
    }
    return snprintf(tag_out + t_size, n - t_size, "]") + t_size;
}

inline std::size_t Debug::Name(char* name_out, std::size_t n)
{
    return WriteName(name_out, n);
}

inline typename Debug::CStrType& Debug::Name(CStrType& cstr)
{
    WriteName(cstr.Buffer(), cstr.BufferSize());
    return cstr;
}

} //!sys

} //!test

#include "dbg/type/param/Make.h"
#include "dbg/val/Parameter.h"
#include "dbg/Type.h"
#include "dbg/Function.h"

#define TEST_SYS_DEBUG_SET_LEVEL(VAL, ...)\
test::sys::dbg::Type<__VA_ARGS__>::GetInstance().SetLevel(VAL)

#define TEST_SYS_DEBUG(SYS_TYPE, DEBUG_TYPE, ...)\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__)

#define TEST_SYS_DEBUG_DEFAULT(DEBUG_TYPE, ...)\
do{\
    static test::sys::Interface& __intf_default__ = test::sys::Interface::DefaultInstance();\
    (__intf_default__).Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
} while(false)

#define TEST_SYS_DEBUG_T_TYPE(...)\
    test::sys::dbg::Type<__VA_ARGS__>

#define TEST_SYS_DEBUG_TV_TYPE(...)\
    test::sys::dbg::type::Value<__VA_ARGS__>

#define TEST_SYS_DEBUG_T_NAME_STR(...)\
    test::sys::dbg::Type<__VA_ARGS__>::GetInstance().Name(test::sys::Debug::GetBufferT()).Buffer()

#define TEST_SYS_DEBUG_TARGS_NAME_STR(...)\
    test::sys::dbg::type::param::Make<__VA_ARGS__>::Type::WriteName(test::sys::Debug::GetBufferT()).Buffer()

#define TEST_SYS_DEBUG_TARGS_VALUE_STR(...)\
    test::sys::dbg::val::Parameter(test::sys::Debug::GetBufferV(), __VA_ARGS__).Buffer()

#define TEST_SYS_DEBUG_F(SYS_TYPE, DLEVEL, NAME, ...)\
do\
{\
    typename test::sys::dbg::Function<sizeof(NAME)> __fun_debug__{NAME, DLEVEL};\
    SYS_TYPE::GetInstance().Debug(__fun_debug__, __VA_ARGS__);\
}\
while(false)

#define TEST_SYS_DEBU
#endif //!TEST_SYS_DEBUG_H_
