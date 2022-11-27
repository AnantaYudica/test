#ifndef TEST_SYS_INTERFACE_H_
#define TEST_SYS_INTERFACE_H_

#include "Definition.h"

#include <cstdio>
#include <cstdarg>

namespace test
{
namespace sys
{

class Interface
{
public:
    typedef typename test::sys::Definition::StatusIntegerType 
        StatusIntegerType;
    typedef typename test::sys::Definition::Status Status; 
public:
    Interface() = default;
public:
    virtual ~Interface() = default;
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
    virtual inline int Error(Status code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    virtual inline int Error(StatusIntegerType code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    virtual inline int VError(Status code, const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    virtual inline int VError(StatusIntegerType code, const char* format, 
        va_list args) TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
};

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
    return vprintf(format, args);
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

#endif //!TEST_SYS_INTERFACE_H_
