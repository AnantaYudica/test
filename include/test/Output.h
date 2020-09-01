#ifndef TEST_OUTPUT_H_
#define TEST_OUTPUT_H_

#include "Status.h"
#include "out/Base.h"

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstdarg>

#ifndef __ATTRIBUTE__
#ifdef __GNUC__
#define __ATTRIBUTE__(...) __attribute__(__VA_ARGS__)
#else
#define __ATTRIBUTE__(...)
#endif
#endif //!__ATTRIBUTE__

namespace test
{

template<typename Ts = Status>
class Output : protected test::out::Base<char>
{
private:
    bool m_enable;
    bool m_infoEnable;
    bool m_debugEnable;
    Ts* m_status;
public:
    Output(Ts& status);
    Output(Ts& status, const char* file_output);
public:
    Output(const Output<Ts>& cpy) = delete;
    Output(Output<Ts>&& mov);
public:
    ~Output();
public:
    Output<Ts>& operator=(const Output<Ts>& cpy) = delete;
    Output<Ts>& operator=(Output<Ts>&& mov) = delete;
public:
    void Set(Ts& status);
public:
    void VError(const char* format, va_list args) 
        __ATTRIBUTE__ ((__format__ (__printf__, 3, 0)));
    void VInfo(const char* format, va_list args) 
        __ATTRIBUTE__ ((__format__ (__printf__, 3, 0)));
    void VDebug(const char* format, va_list args)
        __ATTRIBUTE__((__format__ (__printf__, 3, 0)));
public:
    void Error(const char* format, ...) 
        __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
    void Info(const char* format, ...)
        __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
    void Debug(const char* format, ...)
        __ATTRIBUTE__((__format__ (__printf__, 2, 3)));
public:
    bool Enable();
    void Enable(bool enable);
    bool InfoEnable();
    void InfoEnable(bool info_enable);
    bool DebugEnable();
    void DebugEnable(bool debug_enable);
};

template<typename Ts>
Output<Ts>::Output(Ts& status) :
    test::out::Base<char>(),
    m_enable(true),
    m_infoEnable(true),
    m_debugEnable(true),
    m_status(&status)
{}

template<typename Ts>
Output<Ts>::Output(Ts& status, const char* file_output) :
    test::out::Base<char>(file_output, 
        test::out::Base<char>::FileType::mode_write),
    m_enable(true),
    m_infoEnable(true),
    m_debugEnable(true),
    m_status(&status)
{}

template<typename Ts>
Output<Ts>::Output(Output<Ts>&& mov) :
    test::out::Base<char>(std::move(mov)),
    m_enable(mov.m_enable),
    m_infoEnable(mov.m_infoEnable),
    m_debugEnable(mov.m_debugEnable),
    m_status(NULL)
{
    mov.m_status = NULL;
}

template<typename Ts>
Output<Ts>::~Output()
{}

template<typename Ts>
void Output<Ts>::Set(Ts& status)
{
    assert(m_status == NULL);
    m_status = &status;
}

template<typename Ts>
void Output<Ts>::VError(const char* format, va_list args)
{
    assert(m_status != NULL);
    m_status->Error();
    if (m_enable)
    {
        auto&& err = test::out::Base<char>::Error();
        err.VPrint(format, args);
    }
}

template<typename Ts>
void Output<Ts>::VInfo(const char* format, va_list args) 
{
    if (m_enable && m_infoEnable)
    {
        auto&& info = test::out::Base<char>::Info();
        info.VPrint(format, args);
    }
}

template<typename Ts>
void Output<Ts>::VDebug(const char* format, va_list args)
{
    if (m_enable && m_debugEnable)
    {
        auto&& debug = test::out::Base<char>::Debug();
        debug.VPrint(format, args);
    }
}

template<typename Ts>
void Output<Ts>::Error(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    VError(format, args);
    va_end(args);
}

template<typename Ts>
void Output<Ts>::Info(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    VInfo(format, args);
    va_end(args);
}

template<typename Ts>
void Output<Ts>::Debug(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    VDebug(format, args);
    va_end(args);
}

template<typename Ts>
bool Output<Ts>::Enable()
{
    return m_enable;
}

template<typename Ts>
void Output<Ts>::Enable(bool enable)
{
    m_enable = enable;
}

template<typename Ts>
bool Output<Ts>::InfoEnable()
{
    return m_infoEnable;
}

template<typename Ts>
void Output<Ts>::InfoEnable(bool info_enable)
{
    m_infoEnable = info_enable;
}

template<typename Ts>
bool Output<Ts>::DebugEnable()
{
    return m_debugEnable;
}

template<typename Ts>
void Output<Ts>::DebugEnable(bool debug_enable)
{
    m_debugEnable = debug_enable;
}

} //!test

#endif //!TEST_OUTPUT_H_
