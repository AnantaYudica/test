#ifndef TEST_SYS_DEBUG_H_
#define TEST_SYS_DEBUG_H_

#include "Debug.defn.h"

namespace test
{
namespace sys
{

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
    return WriteTagName(tag_out, n);
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

#define TEST_SYS_DEBUG_SET_LEVEL(VAL, ...)\
test::sys::dbg::Type<__VA_ARGS__>::GetInstance().SetLevel(VAL)

#define TEST_SYS_DEBUG(SYS_TYPE, DEBUG_TYPE, ...)\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__)

#define TEST_SYS_DEBUG_DEFAULT(DEBUG_TYPE, ...)\
do{\
    static test::sys::Interface& __intf_default__ = test::sys::Interface::DefaultInstance();\
    (__intf_default__).Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
} while(false)

#define TEST_SYS_DEBUG_T_NAME_STR(...)\
    test::sys::dbg::Type<__VA_ARGS__>::GetInstance().Name(__t_name_cstr__).Buffer()

#define TEST_SYS_DEBUG_TARGS_NAME_STR(...)\
    test::sys::dbg::type::param::Make<__VA_ARGS__>::Type::WriteName(__t_name_cstr__).Buffer()

#define TEST_SYS_DEBUG_TARGS_VALUE_STR(...)\
    test::sys::dbg::val::Parameter(__t_value_cstr__, __VA_ARGS__).Buffer()

#define TEST_SYS_DEBUG_T(SYS_TYPE, DEBUG_TYPE, ...)\
do\
{\
    typename test::sys::Debug::CStrType __t_name_cstr__;\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
}\
while(false)

#define TEST_SYS_DEBUG_V(SYS_TYPE, DEBUG_TYPE, ...)\
do\
{\
    typename test::sys::Debug::CStrType __t_value_cstr__;\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
}\
while(false)

#define TEST_SYS_DEBUG_T_V(SYS_TYPE, DEBUG_TYPE, ...)\
do\
{\
    typename test::sys::Debug::CStrType __t_name_cstr__;\
    typename test::sys::Debug::CStrType __t_value_cstr__;\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
}\
while(false)

#endif //!TEST_SYS_DEBUG_H_
