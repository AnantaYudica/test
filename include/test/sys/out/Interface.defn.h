#ifndef TEST_SYS_OUT_INTERFACE_H_DEFN_
#define TEST_SYS_OUT_INTERFACE_H_DEFN_

#include "../Definition.h"
#include "../Debug.h"

#include <cstdio>
#include <mutex>
#include <cstdarg>
#include <chrono>

#ifndef TEST_SYS_OUTPUT_BUFFER
#define TEST_SYS_OUTPUT_BUFFER 1024
#endif //!TEST_SYS_OUTPUT_BUFFER

namespace test
{
namespace sys
{
namespace out
{

template<typename TStatus>
class Interface;

} //!out

} //!sys

} //!test

#ifndef TEST_SYS_OUT_INTERFACE_DLEVEL

#define TEST_SYS_OUT_INTERFACE_DLEVEL 2

#endif //!TEST_SYS_OUT_INTERFACE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>

template<typename TStatus>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_OUT_INTERFACE_DLEVEL, 
    "test::sys::out::Interface", 
    test::sys::out::Interface<TStatus>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace sys
{
namespace out
{

template<typename TStatus>
class Interface
{
public:
    typedef TStatus StatusType;
    typedef typename test::sys::Definition::Status StatusEnumType;
    typedef typename test::sys::Definition::StatusIntegerType StatusIntegerType;
    typedef test::sys::Debug DebugType;
public:
    typedef int(*FormatDebugCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
        const void * obj, const StatusType& status, 
        const char* msg);
public:
    typedef int(*FormatCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static int DefaultFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static int DefaultDebugFormat(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
        const void * obj, const StatusType& status, 
        const char* msg);
private:
    StatusType& m_status;
    std::mutex m_mutex;
    FormatCallbackFunc m_outFmtCb;
    FormatCallbackFunc m_infoFmtCb;
    FormatCallbackFunc m_errFmtCb;
    FormatDebugCallbackFunc m_debugFmtCb;
public:
    Interface(StatusType& status);
public:
    Interface(const Interface<TStatus>&) = delete;
    Interface(Interface<TStatus>&&) = delete;
public:
    virtual ~Interface();
public:
    Interface<TStatus>& operator=(const Interface<TStatus>& cpy) = delete;
    Interface<TStatus>& operator=(Interface<TStatus>&& mov) = delete;
public:
    void SetOutputFormatCallback(FormatCallbackFunc cb);
    void SetInfoFormatCallback(FormatCallbackFunc cb);
    void SetErrorFormatCallback(FormatCallbackFunc cb);
    void SetDebugFormatCallback(FormatDebugCallbackFunc cb);
protected:
    virtual int BufferOutput(char * buff) = 0;
public:
    int Output(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
public:
    int VOutput(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    int Info(const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
public:
    int VInfo(const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    int Debug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, ...)
            TEST_ATTRIBUTE((__format__ (__printf__, 5, 6)));
public:
    int VDebug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, va_list args)
            TEST_ATTRIBUTE ((__format__ (__printf__, 5, 0)));
public:
    int Error(StatusIntegerType code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    int Error(StatusEnumType code, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
public:
    int VError(StatusIntegerType code, const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    int VError(StatusEnumType code, const char* format, va_list args)
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
public:
    int OutputCallback(FormatCallbackFunc cb, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
public:
    int VOutputCallback(FormatCallbackFunc cb, const char* format, 
        va_list args) TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    int VOutputCallback(FormatDebugCallbackFunc cb, DebugType& dbg, 
        std::int8_t level, const void * obj, const char* format, 
        va_list args) TEST_ATTRIBUTE ((__format__ (__printf__, 6, 0)));
};

} //!out

} //!sys

} //!test

#endif //!TEST_SYS_OUT_INTERFACE_H_DEFN_
