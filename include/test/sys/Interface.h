#ifndef TEST_SYS_INTERFACE_H_
#define TEST_SYS_INTERFACE_H_

#ifndef TEST_SYS_DEBUG_ENABLE
#define TEST_SYS_DEBUG_ENABLE 0
#endif //!TEST_SYS_DEBUG_ENABLE

#include "Definition.h"
#include "Signal.defn.h"
#include "Debug.h"
#include "dbg/Type.h"

#include <cstdio>
#include <cstdarg>

#ifdef TEST_SYS_DEBUG_ENABLE

#define TEST_SYS_DEBUG_SYS_INSTANCE_IF(CONDITION, SYS_INSTANCE_TRUE,\
    SYS_INSTANCE_FALSE, DEBUG_TYPE, ...)\
do{\
if (CONDITION)\
{\
    SYS_INSTANCE_TRUE.Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
}\
else\
{\
    SYS_INSTANCE_FALSE.Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__);\
}\
} while(false)

#define TEST_SYS_DEBUG_SYS_INSTANCE(SYS_INSTANCE, DEBUG_TYPE, ...)\
    SYS_INSTANCE.Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__)

#else

#define TEST_SYS_DEBUG_SYS_INSTANCE_IF(...)

#define TEST_SYS_DEBUG_SYS_INSTANCE(...)

#endif 

namespace test::sys
{
class Interface;
}

TEST_SYS_DBG_TYPE_DEFINE("test::sys::Interface", test::sys::Interface);

namespace test
{
namespace sys
{

class Interface
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Interface> _DebugType;
private:
    class Instance
    {
    private:
        Interface* m_value;
    public:
        inline Instance();
        inline ~Instance();
    public:
        inline operator bool();
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
private:
    static inline Interface& DefaultInstance();
protected:
    static inline bool CreateInstance(Interface* intf);
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
    virtual inline int Output(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    virtual inline int VOutput(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    virtual inline int Info(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    virtual inline int VInfo(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    virtual inline int Debug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 5, 6)));
    virtual inline int VDebug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 5, 0)));
public:
    virtual inline int Error(Status code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    virtual inline int Error(StatusIntegerType code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    virtual inline int VError(Status code, const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    virtual inline int VError(StatusIntegerType code, const char* format, 
        va_list args) TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
};

inline Interface::Instance::Instance() :
    m_value(nullptr)
{
    TEST_SYS_DEBUG_SYS_INSTANCE_IF(m_value == nullptr, 
        DefaultInstance(),
        (*m_value),
        _DebugType, 1, this, 
        "Default Constructor Interface::Instance");
}

inline Interface::Instance::~Instance()
{
    TEST_SYS_DEBUG_SYS_INSTANCE_IF(m_value == nullptr, 
        DefaultInstance(),
        (*m_value),
        _DebugType, 1, this, 
        "Destructor Interface::Instance");
    
    m_value = nullptr;
}

inline Interface::Instance::operator bool()
{
    TEST_SYS_DEBUG_SYS_INSTANCE_IF(m_value == nullptr, 
        DefaultInstance(),
        (*m_value),
        _DebugType, 3, this, 
        "Instance::operator bool()");
    
    return m_value != nullptr;
}

inline void Interface::Instance::Set(Interface* instance)
{
    m_value = instance;
    
    TEST_SYS_DEBUG_SYS_INSTANCE_IF(m_value == nullptr, 
        DefaultInstance(),
        (*m_value),
        _DebugType, 3, this, 
        "Instance::Set(instance=%p)", instance);
}

inline Interface* Interface::Instance::Get()
{
    TEST_SYS_DEBUG_SYS_INSTANCE_IF(m_value == nullptr, 
        DefaultInstance(),
        (*m_value),
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
        _DebugType, 1, NULL, "GetInstance()");

    return value;
}

inline bool Interface::CreateInstance(Interface * intf)
{
    Instance& instance = _GetInstance();
    if ((bool)instance)
    {
        return false;
    }

    TEST_SYS_DEBUG_SYS_INSTANCE((intf == NULL ? DefaultInstance() : *intf) ,
        _DebugType, 1, NULL, "CreateInstance(intf=%p)", intf);

    instance.Set(intf);
    return true;
}

inline Interface& Interface::GetInstance()
{
    Instance& instance = _GetInstance();
    if (!(bool)instance)
    {
        TEST_SYS_DEBUG_SYS_INSTANCE(DefaultInstance(),
            _DebugType, 1, NULL, "GetInstance()");

        return DefaultInstance();
    }
    
    TEST_SYS_DEBUG_SYS_INSTANCE((*(instance.Get())),
        _DebugType, 1, NULL, "GetInstance()");

    return *(instance.Get());
}

inline void Interface::RegisterSignal(SignalType* sig)
{
    TEST_SYS_DEBUG_SYS_INSTANCE(DefaultInstance(),
        _DebugType, 3, this, 
        "Instance::RegisterSignal(sig=%p)", sig);
    
}

inline void Interface::UnregisterSignal(SignalType* sig)
{
    TEST_SYS_DEBUG_SYS_INSTANCE(DefaultInstance(),
        _DebugType, 3, this, 
        "Instance::RegisterSignal(sig=%p)", sig);
    
}

inline int Interface::Output(const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(format, args);
    va_end(args);
    return res;
}

inline int Interface::VOutput(const char* format, va_list args)
{
    return vprintf(format, args) + printf("\n");
}

inline int Interface::Info(const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(format, args);
    va_end(args);
    return res;
}

inline int Interface::VInfo(const char* format, va_list args)
{
    return VOutput(format, args);
}

inline int Interface::Debug(DebugType& dbg, std::int8_t level, const void * obj,
    const char* format, ...)
{
#if TEST_SYS_DEBUG_ENABLE
    int res = 0;
    char buff[1025];
    dbg.TagName(buff, 1024);
    buff[1024] = '\0';
    res += printf("%s: ", buff);
    va_list args;
    va_start(args, format);
    res += VOutput(format, args);
    va_end(args);
    return res;
#else
    return 0;
#endif
}

inline int Interface::VDebug(DebugType& dbg, std::int8_t level, const void * obj,
    const char* format, va_list args)
{
#if TEST_SYS_DEBUG_ENABLE
    int res = 0;
    char buff[1025];
    dbg.TagName(buff, 1024);
    buff[1024] = '\0';
    res += printf("%s: ", buff);
    return VOutput(format, args) + res;
#else
    return 0;
#endif
}

inline int Interface::Error(Status, const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(format, args);
    va_end(args);
    return res;
}

inline int Interface::Error(StatusIntegerType, const char* format, ...)
{
    int res = 0;
    va_list args;
    va_start(args, format);
    res = VOutput(format, args);
    va_end(args);
    return res;
}

inline int Interface::VError(Status, const char* format, va_list args)
{
    return VOutput(format, args);
}

inline int Interface::VError(StatusIntegerType code, const char* format, 
    va_list args)
{
    return VOutput(format, args);
}

} //!sys

} //!test

#undef TEST_SYS_DEBUG_SYS_INSTANCE_IF
#undef TEST_SYS_DEBUG_SYS_INSTANCE

#include "Definition.impl.h"

#endif //!TEST_SYS_INTERFACE_H_
