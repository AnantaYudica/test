#ifndef TEST_H_
#define TEST_H_

#include "test/Output.h"
#include "test/System.h"
#include "test/Base.h"
#include "test/Register.h"
#include "test/Trace.h"
#include "test/reg/Base.h"
#include "test/type/Name.h"
#include "test/type/name/Parameter.h"
#include "test/type/name/tmpl/Define.h"
#include "test/type/name/tmpl/Parameter.h"
#include "test/type/name/Template.h"
#include "test/cstr/Format.h"
#include "test/sys/Debug.h"
#include "test/sys/Status.h"

#include <cstdio>
#include <cwchar>
#include <cstdlib>
#include <utility>
#include <vector>
#include <stack>
#include <cstdarg>

#ifndef TEST_OUTPUT_FILENAME
#define TEST_OUTPUT_FILENAME_EMPTY
#endif //!TEST_OUTPUT_FILENAME

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

#ifndef TEST_SYS_DEF_STATUS
#error TEST_SYS_DEF_STATUS is not define
#endif //!TEST_SYS_DEF_STATUS

template<typename To>
class Test;

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<To>

template<typename To>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("Test", Test<To>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


template<typename To = test::Output<TEST_SYS_DEF_STATUS>>
class Test
{
private:
    typedef test::sys::Interface SysInterfaceType;
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::dbg::Type<Test<To>> _DebugType;
public:
    typedef typename test::System::StatusType StatusType;
    typedef To OutputType;
    typedef test::System SystemType;
    typedef test::sys::Memory MemoryType;
private:
    static Test<To>* ms_instance;
private:
    bool m_initialized;
    std::vector<test::reg::Base*>* m_list;
    std::stack<test::Trace>* m_traces;
    SystemType& m_system;
    StatusType& m_status;
    MemoryType& m_memory;
    OutputType m_output;
private:
    Test();
    Test(const Test<To>& cpy) = delete;
    Test(Test<To>&& mov);
public:
    ~Test();
public:
    Test<To>& operator=(const Test<To>& cpy) = delete;
    Test<To>& operator=(Test<To>&& mov) = delete;
public:
    static void Info(const char* info_msg_cstr, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 1, 2)));
    static void Debug(const char* debug_msg_cstr, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 1, 2)));
    static void Error(const char* err_msg_cstr, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 1, 2)));
    static bool Assert(bool test, const char* err_msg_cstr, 
        const char* file, const int& line);
public:
    static Test<To>& CreateInstance();
    static Test<To>& GetInstance();
public:
    static const int& Run();
private:
    void Clear();
public:
    void Push(const test::Trace& trace);
    void Pop();
    std::stack<test::Trace> GetTrace();
public:
    typename Test<To>::StatusType& System();
    typename Test<To>::StatusType& Status();
    typename Test<To>::OutputType& Output();
    typename Test<To>::MemoryType& Memory();
    std::vector<test::reg::Base*>& List();
    std::stack<test::Trace>& Traces();
};

template<typename To>
Test<To>* Test<To>::ms_instance;

template<typename To>
Test<To>::Test() :
    m_initialized(true),
    m_list(NULL),
    m_traces(NULL),
    m_system(test::System::GetInstance()),
    m_status(m_system.GetStatus()),
    m_memory(m_system.GetMemory()),
#ifdef TEST_OUTPUT_FILENAME_EMPTY
    m_output(m_status)
#else //!TEST_OUTPUT_FILENAME_EMPTY
    m_output(m_status, TEST_OUTPUT_FILENAME)
#endif
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 1, this, 
        "Default Constructor");

}

template<typename To>
Test<To>::Test(Test<To>&& mov) :
    m_initialized(true),
    m_list(std::move(mov.m_list)),
    m_traces(std::move(mov.m_traces)),
    m_system(std::move(mov.m_system)),
    m_status(std::move(mov.m_status)),
    m_memory(std::move(mov.m_memory)),
    m_output(std::move(mov.m_output))
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    m_output.Set(m_status);

    mov.m_list = NULL;
    mov.m_traces = NULL;
}

template<typename To>
Test<To>::~Test()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 1, this, "Destructor");
    
    assert(m_list == NULL);
    assert(m_traces == NULL);
}

template<typename To>
void Test<To>::Info(const char* info_msg_cstr, ...)
{
    va_list args;
    va_start(args, info_msg_cstr);
    GetInstance().Output().VInfo(info_msg_cstr, args);
    va_end(args);
}

template<typename To>
void Test<To>::Debug(const char* debug_msg_cstr, ...)
{
    va_list args;
    va_start(args, debug_msg_cstr);
    GetInstance().Output().VDebug(debug_msg_cstr, args);
    va_end(args);
}

template<typename To>
void Test<To>::Error(const char* err_msg_cstr, ...)
{
    va_list args;
    va_start(args, err_msg_cstr);
    GetInstance().Output().VError(err_msg_cstr, args);
    va_end(args);
    auto trace = GetInstance().GetTrace();
    while (!trace.empty())
    {
        GetInstance().Output().Error(" from file %s line %zi\n",
            trace.top().File, trace.top().Line);
        trace.pop();
    }
}

template<typename To>
bool Test<To>::Assert(bool test, const char* err_msg_cstr,
    const char* file, const int& line)
{
    if (!test)
        Error("error %s file %s line %i\n", err_msg_cstr, file, line);
    return test;
}

template<typename To>
Test<To>& Test<To>::CreateInstance()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 2, NULL, "CreateInstance()");
    
    assert(ms_instance == NULL);
    static Test<To> instance;
    ms_instance = &instance;
    return instance;
}

template<typename To>
Test<To>& Test<To>::GetInstance()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, NULL, "GetInstance()");
    
    if (ms_instance == NULL)
        CreateInstance();
    return *ms_instance;
}

template<typename To>
const int& Test<To>::Run()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 2, NULL, "Run()");
    
    std::size_t i = 0, s = GetInstance().List().size();
    for (auto t : GetInstance().List())
    {
        Debug("Test %zu of %zu : \n", i + 1, s);
        GetInstance().Push(test::Trace(t->File(), t->Line()));
        t->Run();
        GetInstance().Pop();
        ++i;
    }
    GetInstance().Clear();
    return GetInstance().Status().Get();
}

template<typename To>
void Test<To>::Clear()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 2, this, "Clear()");
    
    m_list->clear();
    delete m_list;
    m_list = NULL;
    delete m_traces;
    m_traces = NULL;
}

template<typename To>
void Test<To>::Push(const test::Trace& trace)
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, 
        "Push(trace={file=%s, line=%d})", 
        trace.File, trace.Line);

    Traces().push(trace);
}

template<typename To>
void Test<To>::Pop()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 2, this, "Pop()");
    
    Traces().pop();
}

template<typename To>
std::stack<test::Trace> Test<To>::GetTrace()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, "GetTrace()");
    
    if (m_traces == NULL)
        return {};
    return *m_traces;
}

template<typename To>
typename Test<To>::StatusType& Test<To>::Status()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, "Status()");
    
    return m_status;
}

template<typename To>
typename Test<To>::OutputType& Test<To>::Output()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, "Output()");
    
    return m_output;
}

template<typename To>
typename Test<To>::MemoryType& Test<To>::Memory()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, "Memory()");
    
    return m_memory;
}

template<typename To>
std::vector<test::reg::Base*>& Test<To>::List()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, "List()");
    
    if (m_list == NULL)
        m_list = new std::vector<test::reg::Base*>();
    return *m_list;
}

template<typename To>
std::stack<test::Trace>& Test<To>::Traces()
{
    TEST_SYS_DEBUG(SysInterfaceType, _DebugType, 3, this, "Traces()");
    
    if (m_traces == NULL)
        m_traces = new std::stack<test::Trace>();
    return *m_traces;
}

#ifndef TEST
#define TEST Test<>
#endif //!TEST

#ifdef USING_TEST_MEMORY
#include <new>

void* operator new(std::size_t sz)
{
    auto ptr = TEST::GetInstance().Memory().Allocate(sz);
    return ptr.Unlock();
}

void* operator new[]( std::size_t sz)
{
    auto ptr = TEST::GetInstance().Memory().Allocate(sz);
    return ptr.Unlock();
}

template<std::size_t N>
void* operator new(std::size_t sz, const char (&file)[N], const int& line) 
{
    auto ptr = TEST::GetInstance().Memory().Allocate(sz, file, line);
    return ptr.Unlock();
}

template<std::size_t N>
void* operator new[]( std::size_t sz, const char (&file)[N], const int& line)
{
    auto ptr = TEST::GetInstance().Memory().Allocate(sz, file, line);
    return ptr.Unlock();
}

template<std::size_t N>
void* operator new (std::size_t sz, void* ptr,
    const char (&)[N], const int&)
{
    auto p = ::operator new(sz, ptr);
    return p;
}

template<std::size_t N>
void* operator new[](std::size_t sz, void* ptr,
    const char (&)[N], const int& )
{
    auto p = ::operator new[](sz, ptr);
    return p;
}

void operator delete(void* p) noexcept
{
    TEST::GetInstance().Memory().Free(p);
}

void operator delete[](void* p) noexcept
{
    TEST::GetInstance().Memory().Free(p);
    std::free(p);
}

#ifndef _MSC_BUILD 
#define new(...) new(__VA_ARGS__, __FILE__, __LINE__)
#endif

#endif //!USING_TEST_MEMORY

#ifndef INFO
#define INFO(__INFO_MESSAGE__, ...)\
    TEST::Info(__INFO_MESSAGE__,##__VA_ARGS__)
#endif //!INFO

#ifndef DEBUG
#define DEBUG(__DEBUG_MESSAGE__, ...)\
    TEST::Debug(__DEBUG_MESSAGE__,##__VA_ARGS__)
#endif //!DEBUG

#ifndef ERROR
#define INFO(__INFO_MESSAGE__, ...)\
    TEST::Info(__INFO_MESSAGE__,##__VA_ARGS__)
#endif //!INFO

#ifndef ASSERT
#define ASSERT(__ERR_MESSAGE__, __TEST_BOOL__, ...)\
    TEST::Assert(__TEST_BOOL__,##__VA_ARGS__,\
        __ERR_MESSAGE__, __FILE__, __LINE__)
#endif //!ASSERT

#ifndef REGISTER_TEST
#define REGISTER_TEST(Name, Test, ...) auto Name =\
    test::reg::Make<TEST>(Test,##__VA_ARGS__, \
        __FILE__, __LINE__);
#endif //!REGISTER_TEST

#ifndef RUN_TEST
#define RUN_TEST() TEST::Run()
#endif //!RUN_TEST

#ifndef TEST_CONSTRUCT
#define TEST_CONSTRUCT TEST& __test_instance_ = \
    TEST::CreateInstance()
#endif //!TEST_CONSTRUCT

#define TEST_TYPE_NAME(__NAME__, __TYPE__, ...)\
template<>\
struct test::type::Name<__TYPE__,##__VA_ARGS__>\
{\
    template<typename TChar = char, typename std::enable_if<\
        std::is_same<TChar, char>::value, int>::type = 1>\
    static test::CString<const char> CStr()\
    {\
        static char _cstr[] = __NAME__;\
        return {_cstr};\
    }\
    template<typename TChar = char, typename std::enable_if<\
        !std::is_same<TChar, char>::value && \
        std::is_same<TChar, wchar_t>::value, int>::type = 1>\
    static test::CString<wchar_t> CStr()\
    {\
        const auto cstr = test::type::Name<__TYPE__,##__VA_ARGS__>::\
            template CStr<char>();\
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);\
    }\
}

#define TEST_TYPE_NAME_TEMPLATE(__NAME__, __TYPE__, ...)\
struct test::type::Name<__TYPE__,##__VA_ARGS__>\
{\
    template<typename TChar = char, typename std::enable_if<\
        std::is_same<TChar, char>::value, int>::type = 1>\
    static test::CString<const char> CStr()\
    {\
        typedef decltype(test::type::name::tmpl::Parameter(\
            std::declval<__TYPE__,##__VA_ARGS__*>())) ParamType;\
        typedef test::type::name::Template<__TYPE__,##__VA_ARGS__,\
            ParamType> TemplateType;\
        static test::CString<char> _name = test::cstr::Format<char>(\
            (sizeof(__NAME__) + TemplateType::template CStr<char>().Size()),\
            "%s%s", __NAME__, *(TemplateType::template CStr<char>()));\
        return {_name};\
    }\
    template<typename TChar = char, typename std::enable_if<\
        !std::is_same<TChar, char>::value && \
        std::is_same<TChar, wchar_t>::value, int>::type = 1>\
    static test::CString<wchar_t> CStr()\
    {\
        const auto cstr = test::type::Name<__TYPE__,##__VA_ARGS__>::\
            template CStr<char>();\
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);\
    }\
}

#define TEST_TYPE_NAME_TMPL_DEFINE(__TYPE__, __PARAM_TYPE__,...)\
struct test::type::name::tmpl::Define<void(__TYPE__)>\
{\
    typedef __PARAM_TYPE__,##__VA_ARGS__ ParameterType;\
}

#define TEST_TYPE_NAME_VAL_ENUMERATION(__NAME__, __TYPE__, __VALUE__, ...)\
template<>\
struct test::type::name::val::Enumeration<__TYPE__, __VALUE__,##__VA_ARGS__>\
{\
    template<typename TChar= char, typename std::enable_if<\
        std::is_same<TChar, char>::value, int>::type = 1>\
    static test::CString<char> CStr()\
    {\
        static TChar _val[] = __NAME__;\
        return {_val};\
    }\
    template<typename TChar = char, typename std::enable_if<\
        !std::is_same<TChar, char>::value && \
        std::is_same<TChar, wchar_t>::value, int>::type = 1>\
    static test::CString<wchar_t> CStr()\
    {\
        const auto cstr = test::type::name::val::Enumeration<\
            __TYPE__, __VALUE__,##__VA_ARGS__>::template CStr<char>();\
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);\
    }\
}

#endif //!TEST_H_
