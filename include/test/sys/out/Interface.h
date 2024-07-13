#ifndef TEST_SYS_OUT_INTERFACE_H_
#define TEST_SYS_OUT_INTERFACE_H_

#include "Interface.defn.h"
#include "../Interface.h"

namespace test
{
namespace sys
{
namespace out
{

template<typename TStatus>
int Interface<TStatus>::DefaultFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType&, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "%s", msg);
}

template<typename TStatus>
int Interface<TStatus>::DefaultDebugFormat(char* buffer, 
    const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
    const void * obj, const StatusType& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "%s", msg);
}

template<typename TStatus>
Interface<TStatus>::Interface(StatusType& status) :
    m_status(status),
    m_mutex(),
    m_outFmtCb(&DefaultFormat),
    m_infoFmtCb(nullptr),
    m_errFmtCb(nullptr)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::out::
        Interface<TStatus>> _DebugType;
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Constructor(status=%p)", &status);

}

template<typename TStatus>
Interface<TStatus>::~Interface()
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::out::
        Interface<TStatus>> _DebugType;
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Destructor");
    
}

template<typename TStatus>
void Interface<TStatus>::SetOutputFormatCallback(FormatCallbackFunc cb)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::out::
        Interface<TStatus>> _DebugType;
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "SetOutputFormatCallback(cb=%p)", cb);
    
    std::lock_guard<std::mutex> guard(m_mutex);
    if (cb == nullptr)
    {
        m_outFmtCb = &DefaultFormat;
    }
    else
    {
        m_outFmtCb = cb;
    }
}

template<typename TStatus>
void Interface<TStatus>::SetInfoFormatCallback(FormatCallbackFunc cb)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::out::
        Interface<TStatus>> _DebugType;
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "SetInfoFormatCallback(cb=%p)", cb);

    std::lock_guard<std::mutex> guard(m_mutex);
    if (cb == nullptr)
    {
        m_infoFmtCb = &DefaultFormat;
    }
    else
    {
        m_infoFmtCb = cb;
    }
}

template<typename TStatus>
void Interface<TStatus>::SetErrorFormatCallback(FormatCallbackFunc cb)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::out::
        Interface<TStatus>> _DebugType;
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "SetErrorFormatCallback(cb=%p)", cb);
    
    std::lock_guard<std::mutex> guard(m_mutex);
    if (cb == nullptr)
    {
        m_errFmtCb = &DefaultFormat;
    }
    else
    {
        m_errFmtCb = cb;
    }
}

template<typename TStatus>
void Interface<TStatus>::SetDebugFormatCallback(FormatDebugCallbackFunc cb)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::out::
        Interface<TStatus>> _DebugType;
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "SetDebugFormatCallback(cb=%p)", cb);
    
    std::lock_guard<std::mutex> guard(m_mutex);
    if (cb == nullptr)
    {
        m_debugFmtCb = &DefaultDebugFormat;
    }
    else
    {
        m_debugFmtCb = cb;
    }
}

template<typename TStatus>
int Interface<TStatus>::Output(const char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VOutput(format, vlist);
    va_end(vlist);
    return res;
}

template<typename TStatus>
int Interface<TStatus>::VOutput(const char* format, va_list args)
{
    return VOutputCallback(m_outFmtCb, format, args);
}


template<typename TStatus>
int Interface<TStatus>::Info(const char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VInfo(format, vlist);
    va_end(vlist);
    return res;
}

template<typename TStatus>
int Interface<TStatus>::VInfo(const char* format, va_list args)
{
    if (m_infoFmtCb == nullptr)
    {
        return VOutputCallback(m_outFmtCb, format, args);
    }
    return VOutputCallback(m_infoFmtCb, format, args);
}

template<typename TStatus>
int Interface<TStatus>::Debug(DebugType& dbg, std::int8_t level, const void * obj,
    const char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VDebug(dbg, level, obj, format, vlist);
    va_end(vlist);
    return res;
}

template<typename TStatus>
int Interface<TStatus>::VDebug(DebugType& dbg, std::int8_t level, const void * obj,
    const char* format, va_list args)
{
    if (level > dbg.GetLevel())
    {
        return 0;
    }
    if (m_infoFmtCb == nullptr)
    {
        return VOutputCallback(m_outFmtCb, format, args);
    }
    return VOutputCallback(m_debugFmtCb, dbg, level, obj, format, args);
}

template<typename TStatus>
int Interface<TStatus>::Error(StatusIntegerType code, const char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VError(code, format, vlist);
    va_end(vlist);
    return res;
}
    
template<typename TStatus>
int Interface<TStatus>::Error(StatusEnumType code, const char* format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = VError(static_cast<StatusIntegerType>(code), format, vlist);
    va_end(vlist);
    return res;
}

template<typename TStatus>
int Interface<TStatus>::VError(StatusIntegerType code, const char* format, 
    va_list args)
{
    m_status.Error(code);
    if (m_errFmtCb == nullptr)
    {
        return VOutputCallback(m_outFmtCb, format, args);
    }
    return VOutputCallback(m_errFmtCb, format, args);
}

template<typename TStatus>
int Interface<TStatus>::VError(StatusEnumType code, const char* format, 
    va_list args)
{
    m_status.Error(code);
    if (m_errFmtCb == nullptr)
    {
        return VOutputCallback(m_outFmtCb, format, args);
    }
    return VOutputCallback(m_errFmtCb, format, args);
}

template<typename TStatus>
int Interface<TStatus>::OutputCallback(FormatCallbackFunc cb, const 
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
int Interface<TStatus>::VOutputCallback(FormatCallbackFunc cb, 
    const char* format, va_list args)
{
    char * msg_buff = (char*)malloc(TEST_SYS_OUTPUT_BUFFER + 1);
    char * buff = (char*)malloc(TEST_SYS_OUTPUT_BUFFER + 1);
    msg_buff[TEST_SYS_OUTPUT_BUFFER] = '\0';
    buff[TEST_SYS_OUTPUT_BUFFER] = '\0';

    vsnprintf(msg_buff, 1024, format, args);
    msg_buff[TEST_SYS_OUTPUT_BUFFER] = '\0';
    int res = 0;
    FormatCallbackFunc call_fn;
    if (cb == nullptr)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        call_fn = m_outFmtCb;
    }
    else
    {
        call_fn = cb;
    }

    res = call_fn(buff, TEST_SYS_OUTPUT_BUFFER, m_status, msg_buff);
    buff[TEST_SYS_OUTPUT_BUFFER] = '\0';

    BufferOutput(buff);

    free(msg_buff);
    free(buff);
    return res;
}

template<typename TStatus>
int Interface<TStatus>::VOutputCallback(FormatDebugCallbackFunc cb,
    DebugType& dbg, std::int8_t level, const void * obj, const char* format, 
    va_list args)
{
    char * msg_buff = (char*)malloc(TEST_SYS_OUTPUT_BUFFER + 1);
    char * buff = (char*)malloc(TEST_SYS_OUTPUT_BUFFER + 1);
    msg_buff[TEST_SYS_OUTPUT_BUFFER] = '\0';
    buff[TEST_SYS_OUTPUT_BUFFER] = '\0';

    vsnprintf(msg_buff, 1024, format, args);
    msg_buff[TEST_SYS_OUTPUT_BUFFER] = '\0';
    int res = 0;
    if (cb == nullptr)
    {
        FormatCallbackFunc fun;
        {
            std::lock_guard<std::mutex> guard(m_mutex);
            fun = m_outFmtCb;
        }
        res = fun(buff, TEST_SYS_OUTPUT_BUFFER, m_status, msg_buff);
    }
    else
    {
        res = cb(buff, TEST_SYS_OUTPUT_BUFFER, dbg, level, obj, m_status, msg_buff);
    }
    buff[TEST_SYS_OUTPUT_BUFFER] = '\0';

    BufferOutput(buff);
    
    free(msg_buff);
    free(buff);
    return res;
}

} //!out

} //!sys

} //!test

#endif //!TEST_SYS_OUT_INTERFACE_H_
