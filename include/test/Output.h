#ifndef BASIC_TEST_OUTPUT_H_
#define BASIC_TEST_OUTPUT_H_

#include "Status.h"

#include <iostream>
#include <cstdlib>
#include <cassert>

#include "out/Argument.h"
#include "cstr/out/Argument.h"

namespace basic
{
namespace test
{

template<typename Ts = Status>
class Output
{
private:
    bool m_enable;
    bool m_infoEnable;
    bool m_debugEnable;
    FILE* m_outputFile;
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
    template<typename... Targs>
    void Error(const char* format, Targs&&... args);
    template<typename... Targs>
    void Info(const char* format, Targs&&... args);
    template<typename... Targs>
    void Debug(const char* format, Targs&&... args);
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
    m_outputFile(stdout),
    m_enable(true),
    m_infoEnable(true),
    m_debugEnable(true),
    m_status(&status)
{}

template<typename Ts>
Output<Ts>::Output(Ts& status, const char* file_output) :
    m_enable(true),
    m_infoEnable(true),
    m_debugEnable(true),
    m_status(&status)
{
#if ((defined(_WIN32) || defined(_WIN64)) && !defined(_CRT_SECURE_NO_WARNINGS))
    fopen_s(&m_outputFile, file_output, "w"); 
#else 
    m_outputFile = fopen(file_output, "w");
#endif 
    assert(m_outputFile != NULL);
}

template<typename Ts>
Output<Ts>::Output(Output<Ts>&& mov) :
    m_outputFile(mov.m_outputFile),
    m_enable(mov.m_enable),
    m_infoEnable(mov.m_infoEnable),
    m_debugEnable(mov.m_debugEnable),
    m_status(NULL)
{
    mov.m_outputFile = NULL;
    mov.m_status = NULL;
}

template<typename Ts>
Output<Ts>::~Output()
{
    if (m_outputFile != NULL)
    {
        fclose(m_outputFile);
        m_outputFile = NULL;
    }
}

template<typename Ts>
void Output<Ts>::Set(Ts& status)
{
    assert(m_status == NULL);
    m_status = &status;
}

template<typename Ts>
template<typename... Targs>
void Output<Ts>::Error(const char* format, Targs&&... args)
{
    assert(m_status != NULL);
    m_status->Error();
    if (m_enable)
    {
        assert(m_outputFile != NULL);
        fprintf(m_outputFile, format, 
            test::out::Argument<Targs>::Value(args)...);
        fflush(m_outputFile);
    }
}

template<typename Ts>
template<typename... Targs>
void Output<Ts>::Info(const char* format, Targs&&... args)
{
    if (m_enable && m_infoEnable)
    {
        assert(m_outputFile != NULL);
        fprintf(m_outputFile, format, 
            test::out::Argument<Targs>::Value(args)...);
        fflush(m_outputFile);
    }
}

template<typename Ts>
template<typename... Targs>
void Output<Ts>::Debug(const char* format, Targs&&... args)
{
    if (m_enable && m_debugEnable)
    {
        assert(m_outputFile != NULL);
        fprintf(m_outputFile, format, 
            test::out::Argument<Targs>::Value(args)...);
        fflush(m_outputFile);
    }
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

} //!basic

#endif //!BASIC_TEST_OUTPUT_H_
