#ifndef TEST_SYS_INTERFACE_H_
#define TEST_SYS_INTERFACE_H_

#ifndef TEST_SYS_DEBUG_ENABLE
#define TEST_SYS_DEBUG_ENABLE 0
#endif //!TEST_SYS_DEBUG_ENABLE

#include "Definition.h"
#include "Signal.defn.h"
#include "Debug.h"
#include "Task.defn.h"

#include <cstdio>
#include <cstdarg>
#include <thread>

#if TEST_SYS_DEBUG_ENABLE

#define TEST_SYS_DEBUG_SYS_INSTANCE(SYS_INSTANCE, DEBUG_TYPE, ...)\
    SYS_INSTANCE.Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__)

#else

#define TEST_SYS_DEBUG_SYS_INSTANCE(...)

#endif 

#ifndef TEST_SYS_ENABLE_THREAD
#define TEST_SYS_IS_ENABLE_THREAD true
#else
#define TEST_SYS_IS_ENABLE_THREAD false
#endif //!TEST_SYS_ENABLE_THREAD

namespace test
{
namespace sys
{

class Interface;

} //!sys

} //!test

#ifndef TEST_SYS_INTERFACE_DLEVEL

#define TEST_SYS_INTERFACE_DLEVEL 2

#endif //!TEST_SYS_INTERFACE_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(
    TEST_SYS_INTERFACE_DLEVEL, 
    "test::sys::Interface", 
    test::sys::Interface);

namespace test
{
namespace sys
{

class Interface
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Interface> _DebugType;
    typedef test::sys::Definition DefinitionType;
private:
    class Instance
    {
    private:
        Interface* m_value;
        Interface* m_default;
    public:
        inline Instance();
        inline ~Instance();
    public:
        inline void Set(Interface* instance);
        inline Interface* Get();
    };
public:
    typedef test::sys::Signal SignalType;
    typedef typename test::sys::Definition::StatusIntegerType 
        StatusIntegerType;
    typedef typename test::sys::Definition::Status Status;
public:
    typedef typename test::sys::Debug DebugType;
private:
    static inline typename Interface::Instance& _GetInstance();
public:
    static inline Interface& DefaultInstance();
protected:
    static inline bool SetInstance(Interface* intf);
public:
    static Interface& GetInstance();
protected:
    inline Interface() = default;
public:
    virtual inline ~Interface() = default;
public:
    virtual inline void RegisterSignal(SignalType* signal);
public:
    virtual inline void UnregisterSignal(SignalType* signal);
public:
    virtual inline void RegisterTask(test::sys::Task&& task);
protected:
    virtual inline void SetError(Status code);
    virtual inline void SetError(StatusIntegerType code);
public:
    virtual inline int PrefixFormatInfo(char* buffer, 
        const std::size_t& buffer_size);
public:
    virtual inline int PrefixFormatDebug(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
        const void * obj);
public:
    virtual inline int PrefixFormatError(char* buffer, 
        const std::size_t& buffer_size, Status code);
    virtual inline int PrefixFormatError(char* buffer, 
        const std::size_t& buffer_size, StatusIntegerType code);
public:
    virtual inline int PrefixFormatThread(char* buffer, 
        const std::size_t& buffer_size, const std::size_t& hid);
public:
    inline int Output(const std::size_t& thread_hid, const char* prefix, 
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 4, 5)));
    virtual inline int VOutput(const std::size_t& thread_hid, 
        const char* prefix, const char* format, va_list args) 
        TEST_ATTRIBUTE ((__format__ (__printf__, 4, 0)));
public:
    inline int Output(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    inline int VOutput(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    inline int Output(const std::size_t& thread_hid, 
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    inline int VOutput(const std::size_t& thread_hid, 
        const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
public:
    inline int Info(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    inline int VInfo(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
    inline int Info(const std::size_t& thread_hid, 
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    inline int VInfo(const std::size_t& thread_hid, 
        const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
public:
    inline int Debug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 5, 6)));
    inline int VDebug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 5, 0)));
    inline int Debug(const std::size_t& thread_hid, DebugType& dbg, 
        std::int8_t level, const void * obj,
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 6, 7)));
    inline int VDebug(const std::size_t& thread_hid, DebugType& dbg, 
        std::int8_t level, const void * obj,
        const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 6, 0)));
public:
    inline int Error(Status code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    inline int Error(StatusIntegerType code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    inline int VError(Status code, const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    inline int VError(StatusIntegerType code, const char* format, 
        va_list args) TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    inline int Error(const std::size_t& thread_hid, Status code, 
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 4, 5)));
    inline int Error(const std::size_t& thread_hid, StatusIntegerType code, 
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 4, 5)));
    inline int VError(const std::size_t& thread_hid, Status code, 
        const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 4, 0)));
    inline int VError(const std::size_t& thread_hid, StatusIntegerType code, 
        const char* format, va_list args) 
        TEST_ATTRIBUTE ((__format__ (__printf__, 4, 0)));
};

inline Interface::Instance::Instance() :
    m_value(&Interface::DefaultInstance()),
    m_default(&Interface::DefaultInstance())
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_default),
        _DebugType, 1, this, 
        "Default Constructor Interface::Instance");
}

inline Interface::Instance::~Instance()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_default),
        _DebugType, 1, this, 
        "Destructor Interface::Instance");
    
    m_value = nullptr;
}

inline void Interface::Instance::Set(Interface* instance)
{
    m_value = instance;
    
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_default),
        _DebugType, 2, this, 
        "Instance::Set(instance=%p)", instance);
}

inline Interface* Interface::Instance::Get()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_default),
        _DebugType, 3, this, 
        "Instance::Get()");
    
    return m_value;
}

inline typename Interface::Instance& Interface::_GetInstance()
{
    static Instance instance;
    return instance;
}

inline Interface& Interface::DefaultInstance()
{
    static Interface value;

    TEST_SYS_DEBUG_SYS_INSTANCE(value,
        _DebugType, 1, NULL, "DefaultInstance()");

    return value;
}

inline bool Interface::SetInstance(Interface * intf)
{
    Instance& instance = _GetInstance();
    if (intf == nullptr)
    {
        return false;
    }

    TEST_SYS_DEBUG_SYS_INSTANCE((intf == NULL ? DefaultInstance() : *intf) ,
        _DebugType, 1, NULL, "SetInstance(intf=%p)", intf);

    instance.Set(intf);
    return true;
}

inline Interface& Interface::GetInstance()
{
    Instance& instance = _GetInstance();

    TEST_SYS_DEBUG_DEFAULT(_DebugType, 3, NULL, "GetInstance()");

    return *(instance.Get());
}

inline void Interface::RegisterSignal(SignalType* sig)
{
    TEST_SYS_DEBUG_SYS_INSTANCE(DefaultInstance(),
        _DebugType, 2, this, 
        "Instance::RegisterSignal(sig=%p)", sig);
    
}

inline void Interface::UnregisterSignal(SignalType* sig)
{
    TEST_SYS_DEBUG_SYS_INSTANCE(DefaultInstance(),
        _DebugType, 2, this, 
        "Instance::RegisterSignal(sig=%p)", sig);
    
}

inline void Interface::RegisterTask(test::sys::Task&& task)
{   
    TEST_SYS_DEBUG_SYS_INSTANCE(DefaultInstance(),
        _DebugType, 2, this, 
        "Instance::RegisterTask(task=%p)", &task);
}

inline void Interface::SetError(Status)
{}

inline void Interface::SetError(StatusIntegerType)
{}

inline int Interface::PrefixFormatInfo(char* buffer, 
    const std::size_t& buffer_size)
{
    return snprintf(buffer, buffer_size, "[INFO]");
}

inline int Interface::PrefixFormatDebug(char* buffer, 
    const std::size_t& buffer_size, DebugType& dbg, 
    std::int8_t level, const void * obj)
{   
    char buff[TEST_SYS_OUTPUT_BUFFER + 1];
    dbg.TagName(buff, TEST_SYS_OUTPUT_BUFFER);
    buff[TEST_SYS_OUTPUT_BUFFER] = '\0';
    if (obj == NULL)
    {   
        return snprintf(buffer, buffer_size, "[DEBUG]%s[STATIC]", buff);
    }
    else
    {
#if TEST_SYS_IS_ENABLE_THREAD
    return snprintf(buffer, buffer_size, "[DEBUG]%s[%p]", buff, obj);
#else
    return snprintf(buffer, buffer_size, "[DEBUG]%s[%p]", buff, obj);
#endif
    }
}

inline int Interface::PrefixFormatError(char* buffer, 
    const std::size_t& buffer_size, Status code)
{
    return snprintf(buffer, buffer_size, "[ERROR]");
}

inline int Interface::PrefixFormatError(char* buffer, 
    const std::size_t& buffer_size, StatusIntegerType code)
{
    return snprintf(buffer, buffer_size, "[ERROR]");
}

inline int Interface::PrefixFormatThread(char* buffer, 
    const std::size_t& buffer_size, const std::size_t& hid)
{
    const std::size_t main_hid = DefinitionType::GetMainThreadHID();
    const std::size_t thread_hid = DefinitionType::GetThisThreadHID();
    if (main_hid == thread_hid)
    {
        return snprintf(buffer, buffer_size, "[MN][%zx]", 
            thread_hid);
    }
    else
    {
        return snprintf(buffer, buffer_size, "[%zx]", 
            thread_hid);
    }
}

inline int Interface::Output(const std::size_t& thread_hid, 
    const char* prefix, const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(thread_hid, prefix, format, args);
    va_end(args);
    return res;
}

inline int Interface::VOutput(const std::size_t&, 
    const char* prefix, const char* format, va_list args)
{
    char msg[TEST_SYS_OUTPUT_BUFFER + 1];
    vsnprintf(msg, TEST_SYS_OUTPUT_BUFFER, format, args);
    msg[TEST_SYS_OUTPUT_BUFFER] = '\0';
    if (prefix != NULL && prefix[0] != '\0')
    {
        return printf("%s: %s\n", prefix, msg);
    }
    else
    {
        return printf("%s\n", msg);
    }
}

inline int Interface::Output(const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(DefinitionType::GetThisThreadHID(), format, args);
    va_end(args);
    return res;
}

inline int Interface::VOutput(const char* format, va_list args)
{
    return VOutput(DefinitionType::GetThisThreadHID(), format, args);
}

inline int Interface::Output(const std::size_t& thread_hid, 
    const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(thread_hid, format, args);
    va_end(args);
    return res;
}

inline int Interface::VOutput(const std::size_t& thread_hid, 
    const char* format, va_list args)
{
    return VOutput(thread_hid, "", format, args);
}

inline int Interface::Info(const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VInfo(DefinitionType::GetThisThreadHID(), format, args);
    va_end(args);
    return res;
}

inline int Interface::VInfo(const char* format, va_list args)
{
    return VInfo(DefinitionType::GetThisThreadHID(), format, args);
}

inline int Interface::Info(const std::size_t& thread_hid, 
    const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VInfo(thread_hid, format, args);
    va_end(args);
    return res;
}

inline int Interface::VInfo(const std::size_t& thread_hid, 
    const char* format, va_list args)
{
    char prefix[TEST_SYS_OUTPUT_BUFFER + 1];
    int len = PrefixFormatInfo(prefix, TEST_SYS_OUTPUT_BUFFER);
    prefix[TEST_SYS_OUTPUT_BUFFER] = '\0';

#if TEST_SYS_IS_ENABLE_THREAD
    
    PrefixFormatThread(prefix + len, TEST_SYS_OUTPUT_BUFFER - len, 
        thread_hid);
    return VOutput(thread_hid, prefix, format, args);
#else

    return VOutput(thread_hid, prefix, format, args);
#endif
}

inline int Interface::Debug(DebugType& dbg, std::int8_t level, 
    const void * obj, const char* format, ...)
{
#if TEST_SYS_DEBUG_ENABLE
    if (level > dbg.GetLevel()) return 0;
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VDebug(DefinitionType::GetThisThreadHID(), dbg, level, 
        obj, format, args);
    va_end(args);
    return res;
#else

    return 0;
#endif
}

inline int Interface::VDebug(DebugType& dbg, std::int8_t level, 
    const void * obj, const char* format, va_list args)
{
    return VDebug(DefinitionType::GetThisThreadHID(), dbg, level, obj, 
        format, args);
}

inline int Interface::Debug(const std::size_t& thread_hid, DebugType& dbg, 
    std::int8_t level, const void * obj, const char* format, ...)
{
#if TEST_SYS_DEBUG_ENABLE
    if (level > dbg.GetLevel()) return 0;
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VDebug(thread_hid, dbg, level, obj, format, args);
    va_end(args);
    return res;
#else

    return 0;
#endif
}

inline int Interface::VDebug(const std::size_t& thread_hid, DebugType& dbg, 
    std::int8_t level, const void * obj, const char* format, va_list args)
{
#if TEST_SYS_DEBUG_ENABLE
    if (level > dbg.GetLevel()) return 0;
    
    char prefix[TEST_SYS_OUTPUT_BUFFER + 1];
    int len = PrefixFormatDebug(prefix, TEST_SYS_OUTPUT_BUFFER,
        dbg, level, obj);
    prefix[TEST_SYS_OUTPUT_BUFFER] = '\0';
#if TEST_SYS_IS_ENABLE_THREAD
    
    PrefixFormatThread(prefix + len, TEST_SYS_OUTPUT_BUFFER - len, 
        thread_hid);
    return VOutput(thread_hid, prefix, format, args);
#else

    return VOutput(thread_hid, prefix, format, args);
#endif
#else
    return 0;
#endif
}

inline int Interface::Error(Status code, const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VError(DefinitionType::GetThisThreadHID(), code, format, args);
    va_end(args);
    return res;
}

inline int Interface::Error(StatusIntegerType code, const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VError(DefinitionType::GetThisThreadHID(), code, format, args);
    va_end(args);
    return res;
}

inline int Interface::VError(Status code, const char* format, va_list args)
{  
    return VError(DefinitionType::GetThisThreadHID(), code, format, args);
}

inline int Interface::VError(StatusIntegerType code, const char* format, 
    va_list args)
{
    return VError(DefinitionType::GetThisThreadHID(), code, format, args);
}

inline int Interface::Error(const std::size_t& thread_hid, Status code, 
    const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VError(thread_hid, code, format, args);
    va_end(args);
    return res;
}

inline int Interface::Error(const std::size_t& thread_hid, 
    StatusIntegerType code, const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VError(thread_hid, code, format, args);
    va_end(args);
    return res;
}

inline int Interface::VError(const std::size_t& thread_hid, Status code, 
    const char* format, va_list args)
{
    SetError(code);
    char prefix[TEST_SYS_OUTPUT_BUFFER + 1];
    int len = PrefixFormatError(prefix, TEST_SYS_OUTPUT_BUFFER, code);
    prefix[TEST_SYS_OUTPUT_BUFFER] = '\0';

#if TEST_SYS_IS_ENABLE_THREAD
    
    PrefixFormatThread(prefix + len, TEST_SYS_OUTPUT_BUFFER - len, 
        thread_hid);
    return VOutput(thread_hid, prefix, format, args);
#else

    return VOutput(thread_hid, prefix, format, args);
#endif
}

inline int Interface::VError(const std::size_t& thread_hid, 
    StatusIntegerType code, const char* format, va_list args)
{
    SetError(code);
    char prefix[TEST_SYS_OUTPUT_BUFFER + 1];
    int len = PrefixFormatError(prefix, TEST_SYS_OUTPUT_BUFFER, code);
    prefix[TEST_SYS_OUTPUT_BUFFER] = '\0';

#if TEST_SYS_IS_ENABLE_THREAD
    
    PrefixFormatThread(prefix + len, TEST_SYS_OUTPUT_BUFFER - len, 
        thread_hid);
    return VOutput(thread_hid, prefix, format, args);
#else

    return VOutput(thread_hid, prefix, format, args);
#endif
}

} //!sys

} //!test

#undef TEST_SYS_DEBUG_SYS_INSTANCE

#include "Definition.impl.h"
#include "Task.h"

#define TEST_SYS_INFO(...)\
    test::sys::Interface::GetInstance().Info(__VA_ARGS__)
    
#define TEST_SYS_ERROR(...)\
    test::sys::Interface::GetInstance().Error(__VA_ARGS__)

#endif //!TEST_SYS_INTERFACE_H_
