#ifndef TEST_SYS_DEBUG_H_
#define TEST_SYS_DEBUG_H_

#include "Definition.h"
#include "dbg\CStr.h"

#include <cstring>
#include <cstdint>

#define TEST_SYS_DEBUG_T_NAME_BUFF_SIZE 255

namespace test
{
namespace sys
{

class Debug
{
private:
    typedef test::sys::Definition DefinitionType;
public:
    typedef test::sys::dbg::CStr<TEST_SYS_DEBUG_T_NAME_BUFF_SIZE> CStrType;
public:
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n);
public:
    static inline std::size_t WriteName(char * name_out, std::size_t n);
private:
    std::int8_t m_level;
protected:
    inline Debug();
public:
    virtual inline ~Debug();
public:
    inline void SetLevel(std::int8_t level);
public:
    inline std::int8_t GetLevel();
public:
    virtual inline std::size_t TagName(char * tag_out, std::size_t n);
public:
    virtual inline std::size_t Name(char * name_out, std::size_t n);
public:
    virtual inline CStrType& Name(CStrType& cstr);
};

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

#include "dbg/Type.h"

#define TEST_SYS_DEBUG_SET_LEVEL(VAL, ...)\
test::sys::dbg::Type<__VA_ARGS__>::GetInstance().SetLevel(VAL)

#define TEST_SYS_DEBUG(SYS_TYPE, DEBUG_TYPE, ...)\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__)

#define TEST_SYS_DEBUG_T_NAME_STR(...)\
    test::sys::dbg::Type<__VA_ARGS__>::GetInstance().Name(__t_name_cstr__).Buffer()

#define TEST_SYS_DEBUG_T(SYS_TYPE, DEBUG_TYPE, ...)\
do\
{\
    typename test::sys::Debug::CStrType __t_name_cstr__;\
    SYS_TYPE::GetInstance().Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
}\
while(false)

#endif //!TEST_SYS_DEBUG_H_
