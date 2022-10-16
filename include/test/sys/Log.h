#ifndef TEST_SYS_LOG_H_
#define TEST_SYS_LOG_H_

#include "Definition.h"

#include <cstdio>
#include <mutex>
#include <cstdarg>
#include <chrono>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

#ifndef TEST_SYS_LOG_OUTPUT_BUFFER
#define TEST_SYS_LOG_OUTPUT_BUFFER 1024
#endif //!TEST_SYS_LOG_OUTPUT_BUFFER

namespace test
{
namespace sys
{

template<typename TStatus>
class Log
{
public:
    typedef TStatus StatusType;
public:
    typedef int(*FormatCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static inline int DefaultFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    FILE* m_file;
    StatusType& m_status;
    std::mutex m_mutex;
    FormatCallbackFunc m_fmtCb;
public:
    Log(StatusType& status);
public:
    Log(const Log&) = delete;
    Log(Log&&) = delete;
public:
    ~Log();
public:
    Log& operator=(const Log& cpy) = delete;
    Log& operator=(Log&& mov) = delete;
public:
    void SetFileOutput(FILE* fout);
    void SetFormatCallback(FormatCallbackFunc cb);
public:
    int Output(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
public:
    int VOutput(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    int OutputCallback(FormatCallbackFunc cb, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
public:
    int VOutputCallback(FormatCallbackFunc cb, const char* format, 
        va_list args) TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
};

template<typename TStatus>
int Log<TStatus>::DefaultFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType&, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "%s\n", msg);
}

template<typename TStatus>
Log<TStatus>::Log(StatusType& status) :
    m_file(NULL),
    m_status(status),
    m_mutex(),
    m_fmtCb(&DefaultFormat)
{}

template<typename TStatus>
Log<TStatus>::~Log()
{}

template<typename TStatus>
void Log<TStatus>::SetFileOutput(FILE* fout)
{
    std::lock_guard<std::mutex> guard(m_mutex);
    if (fout == stdout)
    {
        m_file = NULL;
    }
    else
    {
        m_file = fout;
    }
}

template<typename TStatus>
void Log<TStatus>::SetFormatCallback(FormatCallbackFunc cb)
{
    std::lock_guard<std::mutex> guard(m_mutex);
    if (cb == nullptr)
    {
        m_fmtCb = &DefaultFormat;
    }
    else
    {
        m_fmtCb = cb;
    }
}

template<typename TStatus>
int Log<TStatus>::Output(const char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VOutput(format, vlist);
    va_end(vlist);
    return res;
}

template<typename TStatus>
int Log<TStatus>::VOutput(const char* format, va_list args)
{
    return VOutputCallback(m_fmtCb, format, args);
}

template<typename TStatus>
int Log<TStatus>::OutputCallback(FormatCallbackFunc cb, const 
    char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VOutputCallback(cb, format, vlist);
    va_end(vlist);
    return res;
}

template<typename TStatus>
int Log<TStatus>::VOutputCallback(FormatCallbackFunc cb, const char* format, 
    va_list args)
{
    char * msg_buff = (char*)malloc(TEST_SYS_LOG_OUTPUT_BUFFER + 1);
    char * buff = (char*)malloc(TEST_SYS_LOG_OUTPUT_BUFFER + 1);
    msg_buff[TEST_SYS_LOG_OUTPUT_BUFFER] = '\0';
    buff[TEST_SYS_LOG_OUTPUT_BUFFER] = '\0';

    vsnprintf(msg_buff, 1024, format, args);
    int res = 0;
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        FormatCallbackFunc call_fn;
        if (cb == nullptr)
        {
            call_fn = m_fmtCb;
        }
        else
        {
            call_fn = cb;
        }

        res = call_fn(buff, TEST_SYS_LOG_OUTPUT_BUFFER, m_status, msg_buff);
        if(m_file == NULL)
        {
            fprintf(stdout, "%s", buff);
        }
        else
        {
            fprintf(m_file, "%s", buff);
        }
    }
    free(msg_buff);
    free(buff);
    return res;
}

} //!sys

} //!test

#endif //!TEST_SYS_LOG_H_