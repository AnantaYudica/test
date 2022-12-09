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

namespace test
{
namespace sys
{

class Interface
{
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
protected:
    static inline bool CreateInstance(Interface* intf);
public:
    static Interface& GetInstance();
protected:
    Interface() = default;
public:
    virtual ~Interface() = default;
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
{}

inline Interface::Instance::~Instance()
{
    m_value = nullptr;
}

inline Interface::Instance::operator bool()
{
    return m_value != nullptr;
}

inline void Interface::Instance::Set(Interface* instance)
{
    m_value = instance;
}

inline Interface* Interface::Instance::Get()
{
    return m_value;
}

inline void Interface::RegisterSignal(SignalType*)
{}

inline void Interface::UnregisterSignal(SignalType*)
{}

inline typename Interface::Instance& Interface::_GetInstance()
{
    static Instance instance;
    return instance;
}

inline bool Interface::CreateInstance(Interface * intf)
{
    Instance& instance = _GetInstance();
    if ((bool)instance)
    {
        return false;
    }
    instance.Set(intf);
    return true;
}

Interface& Interface::GetInstance()
{
    Instance& instance = _GetInstance();
    static Interface default_value;
    if (!(bool)instance)
    {
        return default_value;
    }
    return *(instance.Get());
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
    va_list args;
    va_start(args, format);
    res = VOutput(format, args);
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
    return VOutput(format, args);
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

#include "Definition.impl.h"

#endif //!TEST_SYS_INTERFACE_H_
