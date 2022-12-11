#ifndef TEST_SYS_DBG_TYPE_H_
#define TEST_SYS_DBG_TYPE_H_

#include "type/Value.h"
#include "type/Parameter.h"
#include "Type.defn.h"

#include <cstring>
#include <type_traits>

#define TEST_SYS_DBG_TYPE_DEFINE(NAME, ...)\
template<>\
class test::sys::dbg::Type<__VA_ARGS__> : public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = false;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<__VA_ARGS__> instance;\
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
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
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

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE(NAME, ...)\
class test::sys::dbg::Type<__VA_ARGS__> : public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = false;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<__VA_ARGS__> instance;\
        return instance;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        const std::size_t t_size = snprintf(name_out, n, NAME);\
        if (t_size == n)\
        {\
            return t_size;\
        }\
        const std::size_t bg_param = snprintf(name_out + t_size, n - t_size, "<") + t_size;\
        if (bg_param == n)\
        {\
            return bg_param;\
        }\
        const std::size_t param = test::sys::dbg::type::Parameter<TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS>::\
            WriteName(name_out + bg_param, n - bg_param) + bg_param;\
        if (param == n)\
        {\
            return param;\
        }\
        return snprintf(name_out + param, n - param, ">") + param;\
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
        const std::size_t bg_param = snprintf(tag_out + j, n - j, "<") + j;\
        if (bg_param == n)\
        {\
            return bg_param;\
        }\
        const std::size_t param = test::sys::dbg::type::Parameter<TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS>::\
            WriteName(tag_out + bg_param, n - bg_param) + bg_param;\
        if (param == n)\
        {\
            return param;\
        }\
        if (is_bg)\
        {\
            return snprintf(tag_out + param, n - param, ">]") + param;\
        }\
        else\
        {\
            return snprintf(tag_out + param, n - param, ">") + param;\
        }\
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
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
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

#define TEST_SYS_DBG_TYPE_T_QUALIFIER(TPRE, PRE)\
template<typename T>\
class test::sys::dbg::Type<TPRE> : public Type<T>\
{\
public:\
    typedef typename Type<T>::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = Type<T>::HasSuffix;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<TPRE> instance;\
        return instance;\
    }\
public:\
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)\
    {\
        return Type<T>::WriteTagName(tag_out, n);\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        const std::size_t size = snprintf(name_out, n, PRE);\
        if (size == n)\
        {\
            return size;\
        }\
        return Type<T>::WriteName(name_out + size, n - size) + size;\
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
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
public:\
    inline std::size_t TagName(char * tag_out, std::size_t n) override\
    {\
        return WriteTagName(tag_out, n);\
    }\
public:\
    inline std::size_t Name(char* name_out, std::size_t n) override\
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

TEST_SYS_DBG_TYPE_T_QUALIFIER(const T, "const ");
TEST_SYS_DBG_TYPE_T_QUALIFIER(volatile T, "volatile ");
TEST_SYS_DBG_TYPE_T_QUALIFIER(const volatile T, "const volatile ");

#undef TEST_SYS_DBG_TYPE_PREFIX

#define TEST_SYS_DBG_TYPE_T_PTR_REF(TDEF, STR)\
template<typename T>\
class test::sys::dbg::Type<TDEF> : public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = Type<T>::HasSuffix;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<TDEF> instance;\
        return instance;\
    }\
public:\
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)\
    {\
        return Type<T>::WriteTagName(tag_out, n);\
    }\
public:\
    static inline std::size_t WritePrefixName(char * name_out, std::size_t n)\
    {\
        return Type<T>::WritePrefixName(name_out, n);\
    }\
public:\
    static inline std::size_t WriteSufixName(char * name_out, std::size_t n)\
    {\
        return Type<T>::WriteSufixName(name_out, n);\
    }\
public:\
    static inline std::size_t WriteInfixName(char * name_out, std::size_t n)\
    {\
        const std::size_t infix =  Type<T>::WriteInfixName(name_out, n);\
        if (infix == n)\
        {\
            return infix;\
        }\
       return snprintf(name_out + infix, n - infix, STR) + infix;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        const std::size_t prefix = WritePrefixName(name_out, n);\
        if (prefix == n)\
        {\
            return prefix;\
        }\
        std::size_t i = 0;\
        if (HasSuffix)\
        {\
            const std::size_t bg = snprintf(name_out + prefix, n - prefix, "(") + prefix;\
            if (bg == n)\
            {\
                return bg;\
            }\
            const std::size_t infix = WriteInfixName(name_out + bg, n - bg) + bg;\
            if (infix == n)\
            {\
                return infix;\
            }\
            i = snprintf(name_out + infix, n - infix, ")") + infix - prefix;\
        }\
        else\
        {\
            i = WriteInfixName(name_out + prefix, n - prefix);\
        }\
        const std::size_t size = prefix + i;\
        if (size == n)\
        {\
            return size;\
        }\
        return WriteSufixName(name_out + size, n - size) + size;\
    }\
protected:\
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
    inline std::size_t TagName(char * tag_out, std::size_t n) override\
    {\
        return WriteTagName(tag_out, n);\
    }\
    inline std::size_t Name(char * name_out, std::size_t n) override\
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

TEST_SYS_DBG_TYPE_T_PTR_REF(T*, "*");
TEST_SYS_DBG_TYPE_T_PTR_REF(T*const, "*const");
TEST_SYS_DBG_TYPE_T_PTR_REF(T*volatile, "*volatile");
TEST_SYS_DBG_TYPE_T_PTR_REF(T*const volatile, "*const volatile");

TEST_SYS_DBG_TYPE_T_PTR_REF(T&, "&");
TEST_SYS_DBG_TYPE_T_PTR_REF(T&&, "&&");

#undef TEST_SYS_DBG_TYPE_T_PTR_REF

#define TEST_SYS_DBG_TYPE_T_PTR_MEM(TDEF, STR)\
template<typename T, typename TM>\
class test::sys::dbg::Type<TDEF> : public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = Type<T>::HasSuffix;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<TDEF> instance;\
        return instance;\
    }\
public:\
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)\
    {\
        return Type<T>::WriteTagName(tag_out, n);\
    }\
public:\
    static inline std::size_t WritePrefixName(char * name_out, std::size_t n)\
    {\
        return Type<T>::WritePrefixName(name_out, n);\
    }\
public:\
    static inline std::size_t WriteSufixName(char * name_out, std::size_t n)\
    {\
        return Type<T>::WriteSufixName(name_out, n);\
    }\
public:\
    static inline std::size_t WriteInfixName(char * name_out, std::size_t n)\
    {\
        const std::size_t tm =  Type<TM>::WriteName(name_out, n);\
        if (tm == n)\
        {\
            return tm;\
        }\
        const std::size_t tm_conj = snprintf(name_out + tm, n - tm, STR) + tm;\
        if (tm_conj == n)\
        {\
            return tm_conj;\
        }\
        return Type<T>::WriteInfixName(name_out + tm_conj, n + tm_conj) + tm_conj;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        const std::size_t prefix = WritePrefixName(name_out, n);\
        if (prefix == n)\
        {\
            return prefix;\
        }\
        std::size_t i = 0;\
        if (HasSuffix)\
        {\
            const std::size_t bg = snprintf(name_out + prefix, n - prefix, "(") + prefix;\
            if (bg == n)\
            {\
                return bg;\
            }\
            const std::size_t infix = WriteInfixName(name_out + bg, n - bg) + bg;\
            if (infix == n)\
            {\
                return infix;\
            }\
            i = snprintf(name_out + infix, n - infix, ")") + infix - prefix;\
        }\
        else\
        {\
            i = WriteInfixName(name_out + prefix, n - prefix);\
        }\
        const std::size_t size = prefix + i;\
        if (size == n)\
        {\
            return size;\
        }\
        return WriteSufixName(name_out + size, n - size) + size;\
    }\
protected:\
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
    inline std::size_t TagName(char * tag_out, std::size_t n) override\
    {\
        return WriteTagName(tag_out, n);\
    }\
    inline std::size_t Name(char * name_out, std::size_t n) override\
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


TEST_SYS_DBG_TYPE_T_PTR_MEM(T TM::*, "::*");
TEST_SYS_DBG_TYPE_T_PTR_MEM(T TM::*const, "::*const");
TEST_SYS_DBG_TYPE_T_PTR_MEM(T TM::*volatile, "::*volatile");
TEST_SYS_DBG_TYPE_T_PTR_MEM(T TM::*const volatile, "::*const volatile");

#undef TEST_SYS_DBG_TYPE_T_PTR_MEM

#define TEST_SYS_DBG_TYPE_T_ARRAY(TDEF, PRE, IS_BOUNDED, ...)\
template<__VA_ARGS__>\
class test::sys::dbg::Type<TDEF> :public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = true;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<TDEF> instance;\
        return instance;\
    }\
public:\
    template<std::size_t L, std::size_t I = 0>\
    static inline typename std::enable_if<I != L, std::size_t>::type \
    WriteNameExtents(char * name_out, std::size_t n)\
    {\
        std::size_t n_size = 0;\
        if (I == 0 && !IS_BOUNDED)\
        {\
            n_size = snprintf(name_out, n, "[]");\
        }\
        else\
        {\
            const std::size_t ival = std::extent<TDEF, I>::value;\
            n_size = snprintf(name_out, n, "[%zu]", ival);\
        }\
        if (n_size == n)\
        {\
            return n_size;\
        }\
        const std::size_t m_size = \
            WriteNameExtents<L, I + 1>(name_out + n_size, n - n_size);\
        return n_size + m_size;\
    }\
    template<std::size_t L, std::size_t I = 0>\
    static inline typename std::enable_if<I == L, std::size_t>::type\
    WriteNameExtents(char * name_out, std::size_t n)\
    {\
        return 0;\
    }\
public:\
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)\
    {\
        return Type<T>::WriteTagName(tag_out, n);\
    }\
public:\
    static inline std::size_t WritePrefixName(char * name_out, std::size_t n)\
    {\
        const char pre[] = PRE;\
        const std::size_t pre_size = sizeof(pre);\
        std::size_t pre_count = 0;\
        if (pre_size > 1)\
        {\
            pre_count = snprintf(name_out, n, "%s", pre);\
        }\
        if (pre_count == n)\
        {\
            return pre_count;\
        }\
        typedef typename std::remove_all_extents<T>::type RemovedType;\
        return Type<RemovedType>::WriteName(name_out + pre_count, n - pre_count) + pre_count;\
    }\
public:\
    static inline std::size_t WriteSufixName(char * name_out, std::size_t n)\
    {\
        constexpr std::size_t rank = std::rank<TDEF>::value;\
        return WriteNameExtents<rank>(name_out, n);\
    }\
public:\
    static inline std::size_t WriteInfixName(char * name_out, std::size_t n)\
    {\
        return 0;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        const std::size_t prefix = WritePrefixName(name_out, n);\
        if (prefix == n)\
        {\
            return prefix;\
        }\
        return WriteSufixName(name_out + prefix, n - prefix) + prefix;\
    }\
protected:\
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
    inline std::size_t TagName(char * tag_out, std::size_t n) override\
    {\
        return WriteTagName(tag_out, n);\
    }\
    inline std::size_t Name(char * name_out, std::size_t n) override\
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

TEST_SYS_DBG_TYPE_T_ARRAY(T[], "", false, typename T);
TEST_SYS_DBG_TYPE_T_ARRAY(const T[], "const ", false, typename T);
TEST_SYS_DBG_TYPE_T_ARRAY(volatile T[], "volatile ", false, typename T);
TEST_SYS_DBG_TYPE_T_ARRAY(const volatile T[], "const volatile ", false, typename T);

TEST_SYS_DBG_TYPE_T_ARRAY(T[N], "", true, typename T, std::size_t N);
TEST_SYS_DBG_TYPE_T_ARRAY(const T[N], "const ", true, typename T, std::size_t N);
TEST_SYS_DBG_TYPE_T_ARRAY(volatile T[N], "volatile ", true, typename T, std::size_t N);
TEST_SYS_DBG_TYPE_T_ARRAY(const volatile T[N], "const volatile ", true, typename T, std::size_t N);

#undef TEST_SYS_DBG_TYPE_T_ARRAY

#define TEST_SYS_DBG_TYPE_T_FUNCTION(TDEF, CLOSE_BRACKET)\
template<typename T, typename... TArgs>\
class test::sys::dbg::Type<TDEF> : public test::sys::Debug\
{\
public:\
    typedef typename test::sys::Debug::CStrType CStrType;\
public:\
    static constexpr bool HasSuffix = true;\
public:\
    inline static test::sys::Debug& GetInstance()\
    {\
        static Type<TDEF> instance;\
        return instance;\
    }\
public:\
    static inline std::size_t WriteTagName(char * tag_out, std::size_t n)\
    {\
        return Type<T>::WriteTagName(tag_out, n);\
    }\
public:\
    static inline std::size_t WritePrefixName(char * name_out, std::size_t n)\
    {\
        return Type<T>::WriteName(name_out, n);\
    }\
public:\
    static inline std::size_t WriteSufixName(char * name_out, std::size_t n)\
    {\
        const char close_bracket[] = CLOSE_BRACKET;\
        const std::size_t close_bracket_size = sizeof(close_bracket);\
        const std::size_t bg_size = snprintf(name_out, n, "(");\
        if (bg_size == n)\
        {\
            return bg_size;\
        }\
        const std::size_t p_size = test::sys::dbg::type::Parameter<\
            test::sys::dbg::Type<TArgs>...>::WriteName(name_out + bg_size,\
                n - bg_size);\
        const std::size_t pbg_size = p_size + bg_size;\
        if (pbg_size == n)\
        {\
            return pbg_size;\
        }\
        std::size_t i = 0;\
        for (;i < close_bracket_size && (pbg_size + i) < n; ++i)\
        {\
            name_out[pbg_size + i] = close_bracket[i];\
        }\
        return pbg_size + i;\
    }\
public:\
    static inline std::size_t WriteInfixName(char * name_out, std::size_t n)\
    {\
        return 0;\
    }\
public:\
    static inline std::size_t WriteName(char * name_out, std::size_t n)\
    {\
        const std::size_t prefix = WritePrefixName(name_out, n);\
        if (prefix == n)\
        {\
            return prefix;\
        }\
        return WriteSufixName(name_out + prefix, n - prefix) + prefix;\
    }\
protected:\
    inline Type() = default;\
public:\
    inline virtual ~Type() = default;\
    inline std::size_t TagName(char * tag_out, std::size_t n) override\
    {\
        return WriteTagName(tag_out, n);\
    }\
    inline std::size_t Name(char * name_out, std::size_t n) override\
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

TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...), ")");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...), " ...)");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)&, ") &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)&, " ...) &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)&&, ") &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)&&, " ...) &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)const, ") const");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)const, " ...) const");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)const &, ") const &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)const &, " ...) const &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)const &&, ") const &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)const &&, " ...) const &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)volatile, ") volatile");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)volatile, " ...) volatile");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)volatile &, ") volatile &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)volatile &, " ...) volatile &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)volatile &&, ") volatile &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)volatile &&, " ...) volatile &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)const volatile, ") const volatile");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...) const volatile, " ...) const volatile");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)const volatile &, ") const volatile &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)const volatile &, " ...) const volatile &");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs...)const volatile &&, ") const volatile &&");
TEST_SYS_DBG_TYPE_T_FUNCTION(T(TArgs... ...)const volatile &&," ...) const volatile &&");

#undef TEST_SYS_DBG_TYPE_T_FUNCTION

TEST_SYS_DBG_TYPE_DEFINE("void", void);

TEST_SYS_DBG_TYPE_DEFINE("char", char);
TEST_SYS_DBG_TYPE_DEFINE("signed char", signed char);
TEST_SYS_DBG_TYPE_DEFINE("short", short);
TEST_SYS_DBG_TYPE_DEFINE("int", int);
TEST_SYS_DBG_TYPE_DEFINE("long", long);
TEST_SYS_DBG_TYPE_DEFINE("long long", long long);
TEST_SYS_DBG_TYPE_DEFINE("unsigned char", unsigned char);
TEST_SYS_DBG_TYPE_DEFINE("unsigned short", unsigned short);
TEST_SYS_DBG_TYPE_DEFINE("unsigned int", unsigned int);
TEST_SYS_DBG_TYPE_DEFINE("unsigned long", unsigned long);
TEST_SYS_DBG_TYPE_DEFINE("unsigned long long", unsigned long long);

TEST_SYS_DBG_TYPE_DEFINE("float", float);
TEST_SYS_DBG_TYPE_DEFINE("double", double);
TEST_SYS_DBG_TYPE_DEFINE("long double", long double);

#include <string>

TEST_SYS_DBG_TYPE_DEFINE("wchar_t", wchar_t);
TEST_SYS_DBG_TYPE_DEFINE("char16_t", char16_t);
TEST_SYS_DBG_TYPE_DEFINE("char32_t", char32_t);

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TChar>

template<typename TChar>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::char_traits",std::char_traits<TChar>);

template<typename TChar>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::allocator",std::allocator<TChar>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TChar>,  test::sys::dbg::Type<TTraits>, test::sys::dbg::Type<TAllocator>

template<typename TChar, typename TTraits, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::basic_string", std::basic_string<TChar, TTraits, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <array>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::type::Value<std::size_t, N>

template<typename T, std::size_t N>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::array", std::array<T, N>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <vector>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TAllocator>

template<typename T, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::vector", std::vector<T, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <deque>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TAllocator>

template<typename T, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::deque", std::deque<T, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <forward_list>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TAllocator>

template<typename T, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::forward_list", std::forward_list<T, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <list>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TAllocator>

template<typename T, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::list", std::list<T, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <set>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::equal_to", std::equal_to<T>);
template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::less", std::less<T>);
template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::greater", std::greater<T>);

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::hash", std::hash<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TCompare>, test::sys::dbg::Type<TAllocator>

template<typename T, typename TCompare, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::set", std::set<T, TCompare, TAllocator>);

template<typename T, typename TCompare, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::multiset", std::multiset<T, TCompare, TAllocator>);
    
#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <map>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TKey>,  test::sys::dbg::Type<T>

template<typename TKey, typename T>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::pair", std::pair<TKey, T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TKey>,  test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TCompare>, test::sys::dbg::Type<TAllocator>

template<typename TKey, typename T, typename TCompare, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::map", std::map<TKey, T, TCompare, TAllocator>);

template<typename TKey, typename T, typename TCompare, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::multimap", std::multimap<TKey, T, TCompare, TAllocator>);
    
#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <unordered_set>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TKey>,  test::sys::dbg::Type<THash>,\
    test::sys::dbg::Type<TKeyEqual>, test::sys::dbg::Type<TAllocator>

template<typename TKey, typename THash, typename TKeyEqual, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::unordered_set", std::unordered_set<TKey, THash, TKeyEqual, TAllocator>);
template<typename TKey, typename THash, typename TKeyEqual, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::unordered_multiset", std::unordered_multiset<TKey, THash, TKeyEqual, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <unordered_map>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TKey>, test::sys::dbg::Type<T>, test::sys::dbg::Type<THash>,\
    test::sys::dbg::Type<TKeyEqual>, test::sys::dbg::Type<TAllocator>

template<typename TKey, typename T, typename THash, typename TKeyEqual, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::unordered_map", std::unordered_map<TKey, T, THash, TKeyEqual, TAllocator>);
template<typename TKey, typename T, typename THash, typename TKeyEqual, typename TAllocator>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::unordered_multimap", std::unordered_multimap<TKey, T, THash, TKeyEqual, TAllocator>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include <stack>
#include <queue>

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TContainer>

template<typename T, typename TContainer>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::stack", std::stack<T, TContainer>);
template<typename T, typename TContainer>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::queue", std::queue<T, TContainer>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>, test::sys::dbg::Type<TContainer>, test::sys::dbg::Type<TCompare>

template<typename T, typename TContainer, typename TCompare>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("std::priority_queue", std::priority_queue<T, TContainer, TCompare>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include "../Debug.h"

#endif //!TEST_SYS_DBG_TYPE_H_
