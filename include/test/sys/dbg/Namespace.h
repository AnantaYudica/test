#ifndef TEST_SYS_DBG_NAMESPACE_H_
#define TEST_SYS_DBG_NAMESPACE_H_

#include "../Debug.defn.h"
#include "nmspc/Definition.h"
#include "nmspc/Index.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace sys
{
namespace dbg
{

template<std::uint64_t... TIndexs>
class Namespace : public test::sys::Debug
{
public:
    typedef typename test::sys::Debug::CStrType CStrType;
public:
    inline static test::sys::Debug& GetInstance()
    {
        static Namespace<TIndexs...> instance;
        return instance;
    }
protected:
    inline Namespace() = default;
public:
    inline virtual ~Namespace() = default;
};

} //!dbg

} //!sys

} //!test

#define TEST_SYS_DBG_NAMESPACE_LEVEL_DEFINE(LEVEL, NAME)\
template<>\
class test::sys::dbg::Namespace<\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<0>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<1>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<2>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<3>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<4>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<5>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<6>(),\
    test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<7>()> : public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static test::sys::dbg::Namespace<\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<0>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<1>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<2>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<3>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<4>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<5>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<6>(),\
            test::sys::dbg::nmspc::Index<sizeof(NAME)>{NAME}.Value<7>()> instance;\
        return instance;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        return snprintf(name_out, n, NAME);\
    }\
public:\
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)\
    {\
        char name[] = NAME;\
        const std::size_t name_size = sizeof(name);\
        std::size_t i = 0;\
        std::size_t j = 0;\
        bool is_bg = false;\
        while(i < name_size && j < n)\
        {\
            if (name[i] == ':')\
            {\
                if (is_bg)\
                {\
                    tag_out[j++] = ']';\
                    is_bg = false;\
                }\
                ++i; continue;\
            }\
            if (!is_bg)\
            {\
                tag_out[j++] = '[';\
                is_bg = true;\
                if (j >= n) break;\
            }\
            tag_out[j++] = name[i++];\
        }\
        if (j == n)\
        {\
            return j;\
        }\
        if (j != 0)\
        {\
            j -= 1;\
        }\
        if (is_bg)\
        {\
            return snprintf(tag_out + j, n - j, "]") + j;\
        }\
        return j;\
    }\
public:\
    static inline std::size_t WritePrefixName(char * name_out, std::size_t n)\
    {\
        return WriteName(name_out, n);\
    }\
public:\
    static inline std::size_t WriteSufixName(char * name_out, std::size_t n)\
    {\
        return 0;\
    }\
public:\
    static inline std::size_t WriteInfixName(char * name_out, std::size_t n)\
    {\
        return 0;\
    }\
protected:\
    inline Namespace() : test::sys::Debug((std::int8_t)LEVEL) {};\
public:\
    inline virtual ~Namespace() = default;\
public:\
    virtual inline std::size_t TagName(char * tag_out, std::size_t n)\
    {\
        return WriteTagName(tag_out, n);\
    }\
public:\
    virtual inline std::size_t Name(char * name_out, std::size_t n)\
    {\
        return WriteName(name_out, n);\
    }\
public:\
    virtual inline typename test::sys::Debug::CStrType&\
        Name(CStrType& cstr)\
    {\
        WriteName(cstr.Buffer(), cstr.BufferSize());\
        return cstr;\
    }\
}

#define TEST_SYS_DBG_NAMESPACE_DEFINE(NAME)\
    TEST_SYS_DBG_NAMESPACE_LEVEL_DEFINE(0x7F, NAME)
    
#include "../Debug.h"

#endif //!TEST_SYS_DBG_NAMESPACE_H_
