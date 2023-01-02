#ifndef TEST_SYS_DEBUG_H_DEFN_
#define TEST_SYS_DEBUG_H_DEFN_

#include "dbg/CStr.h"
#include "Debug.decl.h"

#include <cstring>
#include <cstdint>
#include <cstdio>

#define TEST_SYS_DEBUG_T_NAME_BUFF_SIZE 1028

namespace test
{
namespace sys
{

class Debug
{
public:
    typedef test::sys::dbg::CStr<TEST_SYS_DEBUG_T_NAME_BUFF_SIZE> CStrType;
public:
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n);
public:
    static inline std::size_t WriteName(char * name_out, std::size_t n);
public:
    static inline CStrType& GetBufferT();
    static inline CStrType& GetBufferV();
    template<std::size_t ID>
    static inline CStrType& GetBufferID();
private:
    std::int8_t m_level;
protected:
    inline Debug();
    inline Debug(std::int8_t level);
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


} //!sys

} //!test

#endif //!TEST_SYS_DEBUG_H_DEFN_
