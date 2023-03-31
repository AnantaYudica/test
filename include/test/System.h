#ifndef TEST_SYSTEM_H_
#define TEST_SYSTEM_H_

#include "sys/Definition.h"
#include "sys/Signal.defn.h"
#include "sys/Status.h"
#include "sys/Log.h"
#include "sys/Signals.defn.h"
#include "sys/Memory.h"
#include "sys/Interface.h"
#include "sys/Debug.h"

#include <cstddef>
#include <cstdlib>
#include <csignal>
#include <chrono>
#include <functional>
#include <limits>
#include <cstring>
#include <thread>

#ifndef TEST_SYSTEM_THREAD_ID_BUFFER
#define TEST_SYSTEM_THREAD_ID_BUFFER 4
#endif //!TEST_SYSTEM_THREAD_ID_BUFFER

#ifndef TEST_SYS_DEF_STATUS
#define TEST_SYS_DEF_STATUS test::sys::Status
#endif //!TEST_SYS_DEF_STATUS

#ifndef TEST_SYSTEM_DEF_ENTRY_LINE_STR
#define TEST_SYSTEM_DEF_ENTRY_LINE_STR \
"======================================="\
"======================================="
#endif //!TEST_SYS_DEF_ENTRY_LINE_STR
#ifndef TEST_SYSTEM_DEF_DASH_LINE_STR
#define TEST_SYSTEM_DEF_DASH_LINE_STR \
"---------------------------------------"\
"---------------------------------------"
#endif //!TEST_SYS_DEF_ENTRY_LINE_STR

#if TEST_SYS_DEBUG_ENABLE

#define TEST_SYS_DEBUG_SYS_INSTANCE(SYS_INSTANCE, DEBUG_TYPE, ...)\
    SYS_INSTANCE.Debug(DEBUG_TYPE::GetInstance(), __VA_ARGS__)

#else

#define TEST_SYS_DEBUG_SYS_INSTANCE(...)

#endif 
namespace test
{
class System;
}

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(2, "test::System", test::System);

namespace test
{

class System final : public test::sys::Interface
{
private:
    typedef test::System SystemType;
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::dbg::Type<test::System> _DebugType;
public:
    typedef test::sys::Signal SignalType;
    typedef TEST_SYS_DEF_STATUS StatusType;
    typedef typename StatusType::StatusIntegerType StatusIntegerType;
    typedef test::sys::Log<StatusType> LogType;
    typedef test::sys::Debug DebugType;
    typedef test::sys::Memory MemoryType;
    typedef test::sys::Interface InterfaceType;
public:
    static constexpr std::size_t ThreadIDBuffer = TEST_SYSTEM_THREAD_ID_BUFFER;
public:
    static inline void SignalHandler(int sig);
public:
    static inline System& GetInstance(); 
private:
    static inline int EntryFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
    static inline int InfoFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
    static inline int ErrorFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
    static inline int DebugFormat(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, 
        std::int8_t level, const void * obj, 
        const StatusType& status, 
        const char* msg);
    static inline int LogFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg, const char * tag);
private:
    int m_retValue;
    int m_argSize;
    char** m_argValue;
    StatusType m_status;
    LogType m_log;
    test::sys::Signals<StatusType> m_signals;
    FILE* m_out;
    char * m_outFilename;
    InterfaceType* m_interface;
    std::mutex m_logLock;
    typename std::thread::id m_logIDs[ThreadIDBuffer];
private:
    inline System();
public:
    System(const System&) = delete;
    System(System&&) = delete;
public:
    inline ~System();
public:
    System& operator=(const System&) = delete;
    System& operator=(System&&) = delete;
private:
    inline bool LockOutput();
private:
    inline void UnlockOutput();
public:
    inline bool SetOutputFile(const char * outFilename);
private:
    inline void PrintTitle();
    inline void PrintArguments();
    inline void PrintFooter();
    inline void PrintTerminateFooter();
private:
    inline bool CopyArguments(int argc, char *argv[]);
    inline void FreeArguments();
private:
    inline bool Initialization();
private:
    inline void Finalization();
private:
    inline void Termination();
public:
    inline bool EntryPoint();
    inline bool EntryPoint(int argc, char *argv[]);
public:
    inline int ReturnPoint();
public:
    inline int ArgumentSize();
    inline const char* Argument(const std::size_t& i);
public:
    inline void RegisterSignal(SignalType* signal) override;
public:
    inline void UnregisterSignal(SignalType* signal) override;
public:
    inline StatusType& GetStatus();
    inline const StatusType& GetStatus() const;
public:
    inline MemoryType& GetMemory();
public:
    inline bool IsRunning() const;
    inline bool IsDone() const;
    inline bool IsError() const;
    inline bool IsTerminate() const;
public:
    inline int Output(const char* format, ...) override
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    inline int VOutput(const char* format, va_list args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    inline int Info(const char* format, ...) override
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    inline int VInfo(const char* format, va_list args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 2, 0)));
public:
    inline int Debug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, ...) override
        TEST_ATTRIBUTE((__format__ (__printf__, 5, 6)));
    inline int VDebug(DebugType& dbg, std::int8_t level, const void * obj,
        const char* format, va_list args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 5, 0)));
public:
    inline int Error(Status code, const char* format, ...) override
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    inline int Error(StatusIntegerType code, const char* format, ...) override
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
    inline int VError(Status code, const char* format, va_list args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
    inline int VError(StatusIntegerType code, const char* format, 
        va_list args) override 
        TEST_ATTRIBUTE ((__format__ (__printf__, 3, 0)));
};

} //!test

#include "sys/Signal.h"
#include "sys/Signals.h"

namespace test
{

inline void System::SignalHandler(int sig)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 2, NULL, 
        "SignalHandler(sig=%d)", sig);
    
    System::GetInstance().m_status.Termination(sig);
    System::GetInstance().m_signals.Raise(sig);
    System::GetInstance().Termination();
}

inline System& System::GetInstance()
{
    static System instance;
    
    TEST_SYS_DEBUG_SYS_INSTANCE((*(instance.m_interface)), _DebugType, 3, NULL, 
        "GetInstance()");
    
    return instance;
} 

inline int System::EntryFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg)
{
    return snprintf(buffer, buffer_size, "%s", msg);
}

inline int System::InfoFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg)
{
    return LogFormat(buffer, buffer_size, status, msg, "[INFO]");
}

inline int System::ErrorFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg)
{
    return LogFormat(buffer, buffer_size, status, msg, "[ERROR]");
}

inline int System::DebugFormat(char* buffer, 
    const std::size_t& buffer_size, DebugType& dbg, 
    std::int8_t level, const void * obj, 
    const StatusType& status, 
    const char* msg)
{
    constexpr std::size_t tag_buffsize = TEST_SYS_LOG_OUTPUT_BUFFER + 1;
    char tag[tag_buffsize];
    const std::size_t dbg_size = snprintf(tag, tag_buffsize, "[DEBUG]");
    if (dbg_size == tag_buffsize) return (int)dbg_size;
    const std::size_t tsize = dbg.TagName(tag + dbg_size, 
        tag_buffsize - dbg_size) + dbg_size;
    tag[tag_buffsize] = '\0';
    if (tsize == tag_buffsize) return tag_buffsize;
    if (obj == NULL)
    {
        snprintf(tag + tsize, tag_buffsize - tsize, "[STATIC]");
    }
    else
    {
        snprintf(tag + tsize, tag_buffsize - tsize, "[%p]", obj);
    }
    tag[tag_buffsize] = '\0';
    return LogFormat(buffer, buffer_size, status, msg, tag);
}

inline int System::LogFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg, const char * tag)
{
    const auto start = status.GetStartTimestamp();
    const auto now = test::sys::Definition::GetTimestampNow();
    const auto dur = test::sys::Definition::GetTimeDuration(start, now);
    if (dur.Day > 0)
    {
        return snprintf(buffer, buffer_size, 
            "[%d Days %02d:%02d:%02d.%03d%03d]%s: %s",
            dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, tag, msg);
    }
    else if (dur.Hour > 0)
    {
        return snprintf(buffer, buffer_size,
            "[%d:%02d:%02d.%03d%03d]%s: %s",
            dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, tag, msg);
    }
    else if(dur.Minute > 0)
    {
        return snprintf(buffer, buffer_size,
            "[%d:%02d.%03d%03d]%s: %s",
            dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, tag, msg);
    }

    return snprintf(buffer, buffer_size,
        "[%d.%03d%03d]%s: %s",
        dur.Second, dur.Milisecond,
        dur.Microsecond, tag, msg);
}

inline System::System() :
    m_retValue(0),
    m_argSize(0),
    m_argValue(nullptr),
    m_status(),
    m_log(m_status),
    m_signals(m_status),
    m_out(NULL),
    m_outFilename(NULL),
    m_interface(&test::sys::Interface::GetInstance()),
    m_logLock(),
    m_logIDs()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 1, this, 
        "Default Constructor");
    {
        std::lock_guard<std::mutex> lock(m_logLock);
        for (std::size_t i = 0; i < ThreadIDBuffer; ++i)
        {
            m_logIDs[i] = std::thread::id();
        }
    }
    
    Initialization();
}

inline System::~System()
{
    m_interface = &InterfaceType::DefaultInstance();
    InterfaceType::SetInstance(m_interface);
    
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 1, this, 
        "Destructor");
    
    Finalization();
    m_retValue = 0;
}

inline bool System::LockOutput()
{
    std::lock_guard<std::mutex> lock(m_logLock);
    std::size_t index = ThreadIDBuffer;
    for (std::size_t i = 0; i < ThreadIDBuffer; ++i)
    {
        if (m_logIDs[i] == std::this_thread::get_id())
        {
            return false;
        }
        else if (m_logIDs[i] == std::thread::id() &&
            index == ThreadIDBuffer)
        {
            index = i;
        }
    }
    if (index == ThreadIDBuffer)
    {
        return false;
    }
    m_logIDs[index] = std::this_thread::get_id();
    return true;
}

inline void System::UnlockOutput()
{
    std::lock_guard<std::mutex> lock(m_logLock);
    for (std::size_t i = 0; i < ThreadIDBuffer; ++i)
    {
        if (m_logIDs[i] == std::this_thread::get_id())
        {
            m_logIDs[i] = std::thread::id();
            return;
        }
    }
}

inline bool System::SetOutputFile(const char * outFilename)
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "SetOutputFile(outFilename=%s)", outFilename);
    
    if (m_status.IsStart()) return false;
   
#if (defined(WIN32) && !defined(_CRT_SECURE_NO_WARNINGS)) || \
    defined(__STDC_LIB_EXT1__)

    const auto err = fopen_s(&m_out, outFilename, "w");
    if (err > 0)
    {
        return false;
    }
#else
    m_out = fopen(outFilename, "w");
    if (m_out == NULL)
    {
        return false;
    }
#endif
    
    const auto size = strlen(outFilename);
    m_outFilename = (char *) malloc(size + 1);

#if (defined(WIN32) && !defined(_CRT_SECURE_NO_WARNINGS)) || \
        defined(__STDC_LIB_EXT1__)
    strncpy_s(m_outFilename, size, outFilename, size);
#else
    strncpy(m_outFilename, outFilename, size);
#endif
    m_outFilename[size] = '\0';

    m_log.SetFileOutput(m_out);

    return true;
}

inline void System::PrintTitle()
{
    const auto start_timestamp = m_status.GetStartTimestamp();
    const auto dtime = test::sys::Definition::GetDateTime(start_timestamp);
    const char * output = m_outFilename == NULL ? "stdio" : m_outFilename;
    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_ENTRY_LINE_STR "\n"
        "Log Test::System\n"
        "Output : %s\n"
        "Start Timestamp : %d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d",
            output, dtime.Year, dtime.Month, dtime.Day, dtime.Hour, 
            dtime.Minute, dtime.Second, dtime.Milisecond, 
            dtime.Microsecond, dtime.UTC_Hour, dtime.UTC_Minute);

}

inline void System::PrintArguments()
{
    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_DASH_LINE_STR "\n"
        "Arguments size : %d",
        m_argSize);

    for (int i = 0; i < m_argSize; ++i)
    {
        m_log.OutputCallback(&EntryFormat, 
            "\nArgument[%d]: %s", i,
            m_argValue[i] == NULL ? "(null)": m_argValue[i]);
    }

    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_DASH_LINE_STR);
}

inline void System::PrintFooter()
{
    const auto start_timestamp = m_status.GetStartTimestamp();
    const auto end_timestamp = m_status.GetEndTimestamp();
    auto dtime = test::sys::Definition::GetDateTime(end_timestamp);
    auto dur = test::sys::Definition::GetTimeDuration(start_timestamp,
        end_timestamp);
    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_ENTRY_LINE_STR "\n"
        "End Timestamp : %d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n"
        "Duration : %d Days %02d:%02d:%02d.%03d%03d\n"
        "Retrun Value : %d",
            dtime.Year, dtime.Month, dtime.Day, 
            dtime.Hour, dtime.Minute, dtime.Second, 
            dtime.Milisecond, dtime.Microsecond, 
            dtime.UTC_Hour, dtime.UTC_Minute,
            dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, m_status.ReturnValue());
}

inline void System::PrintTerminateFooter()
{
    const int sig = m_status.GetTerminationSignal();
    const auto start_timestamp = m_status.GetStartTimestamp();
    const auto term_timestamp = m_status.GetTerminationTimestamp();
    auto dtime = test::sys::Definition::GetDateTime(term_timestamp);
    auto dur = test::sys::Definition::GetTimeDuration(start_timestamp,
        term_timestamp);
    
    static const char * signal_names[]
    {
        "SIGINT", // interrupt
        "SIGILL", // illegal instruction - invalid function image
        "SIGFPE", // floating point exception
        "SIGSEGV", // segment violation
        "SIGTERM", // Software termination signal from kill
        "SIGABRT", // abnormal termination triggered by abort call
    };
    static int signal_name_indexes[]
    {
        SIGINT, SIGILL, SIGFPE, SIGSEGV, SIGTERM, SIGABRT
    };
    const char * sig_name = NULL;
    for (int i = 0; i < sizeof(signal_name_indexes); ++i)
    {
        if (sig == signal_name_indexes[i])
        {
            sig_name = signal_names[i];
        }
    }
    if (sig_name == NULL)
    {
        m_log.OutputCallback(&EntryFormat, 
            TEST_SYSTEM_DEF_ENTRY_LINE_STR "\n"
            "Terminate Timestamp : "
            "%d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n"
            "Duration : %d Days %02d:%02d:%02d.%03d%03d\n"
            "Terminate Signal : %d",
                dtime.Year, dtime.Month, dtime.Day, 
                dtime.Hour, dtime.Minute, dtime.Second, 
                dtime.Milisecond, dtime.Microsecond, 
                dtime.UTC_Hour, dtime.UTC_Minute, 
                dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
                dur.Microsecond, sig);
    }
    else 
    {
        m_log.OutputCallback(&EntryFormat, 
            TEST_SYSTEM_DEF_ENTRY_LINE_STR "\n"
            "Terminate Timestamp : "
            "%d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n"
            "Duration : %d Days %02d:%02d:%02d.%03d%03d\n"
            "Terminate Signal : %d (%s)",
                dtime.Year, dtime.Month, dtime.Day, 
                dtime.Hour, dtime.Minute, dtime.Second, 
                dtime.Milisecond, dtime.Microsecond, 
                dtime.UTC_Hour, dtime.UTC_Minute, 
                dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
                dur.Microsecond, sig, sig_name);
    }
}

inline bool System::CopyArguments(int argc, char *argv[])
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "CopyArguments(argc=%d, argv=%p)", argc, argv);
    
    const auto max_size = 
        std::numeric_limits<decltype(strlen(""))>::max();

    m_argSize = argc;
    m_argValue = (char**)malloc(sizeof(char*) * argc);
    if (m_argValue == NULL)
    {
        m_status.Error(DefinitionType::Status::sAllocationAgumentsFailed);
        m_log.OutputCallback(&ErrorFormat, 
            "System allocation arguments failed");
        return false;
    }
    for (int i = 0; i < m_argSize; ++i)
    {
        m_argValue[i] = NULL;
    }
    for (int i = 0; i < m_argSize; ++i)
    {
        const auto size = strlen(argv[i]);
        m_argValue[i] = (char *)malloc(size + 1);
        if (m_argValue[i] == NULL)
        {
            m_status.Error(DefinitionType::Status::sAllocationAgumentsFailed);
            m_log.OutputCallback(&ErrorFormat, 
                "System allocation arguments failed");
            return false;
        }

#if (defined(WIN32) && !defined(_CRT_SECURE_NO_WARNINGS)) || \
    defined(__STDC_LIB_EXT1__)

        strncpy_s(m_argValue[i], size, argv[i], size);
#else
        strncpy(m_argValue[i], argv[i], size);
#endif
        m_argValue[i][size] = '\0';
    }
    return true;
}

inline void System::FreeArguments()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "FreeArguments()");
    
    if (m_argValue == NULL) 
    {
        return;
    }

    for (int i = 0; i < m_argSize; ++i)
    {
        if (m_argValue[i] != NULL)
        {
            free(m_argValue[i]);
            m_argValue[i] = NULL;
        }

    }
    free(m_argValue);
    m_argValue = NULL;
    m_argSize = 0;
}

inline bool System::Initialization()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "Initialization()");
    
    std::signal(SIGTERM, SignalHandler);
    std::signal(SIGSEGV, SignalHandler);
    std::signal(SIGINT, SignalHandler);
    std::signal(SIGILL, SignalHandler);
    std::signal(SIGABRT, SignalHandler);
    std::signal(SIGFPE, SignalHandler);
    return true;
}

inline void System::Finalization()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "Finalization()");

    InterfaceType::SetInstance(&InterfaceType::DefaultInstance());
    
    FreeArguments();
    if (m_out != NULL)
    {
        fclose(m_out);
        m_out = NULL;
    }
    if (m_outFilename != NULL)
    {
        free(m_outFilename);
        m_outFilename = NULL;
    }
}

inline void System::Termination()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "Termination()");
    
    PrintTerminateFooter();
    
    m_interface = &InterfaceType::DefaultInstance();
    InterfaceType::SetInstance(m_interface);
    
    Finalization();
}

inline bool System::EntryPoint()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "EntryPoint()");
    
    if (m_status.IsStart()) return false;

    m_argSize = 0;
    m_argValue = NULL;
    
    m_status.Start();
    PrintTitle();
    PrintArguments();
    
    m_log.SetInfoFormatCallback(InfoFormat);
    m_log.SetErrorFormatCallback(ErrorFormat);
    m_log.SetDebugFormatCallback(DebugFormat);
    InterfaceType::SetInstance(this);
    m_interface = this;

    return true;
}

inline bool System::EntryPoint(int argc, char *argv[])
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "EntryPoint(argc=%d, argv=%p)", argc, argv);
    
    if (m_status.IsStart()) return false;

    m_status.Start();
    PrintTitle();

    if (!CopyArguments(argc, argv))
    {
        return false;
    }
    
    PrintArguments();

    return true;
}

inline int System::ReturnPoint()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "ReturnPoint()");
    
    if (m_status.IsEnd()) return m_retValue;
    m_status.End();
    
    FreeArguments();
    
    PrintFooter();

    return m_retValue;
}

inline int System::ArgumentSize()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "ArgumentSize()");
    
    return m_argSize;
}

inline const char* System::Argument(const std::size_t& i)
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "Argument(i=%zu)", i);
    
    return m_argValue[i];
}

inline void System::RegisterSignal(SignalType* signal)
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "RegisterSignal(signal=%p)", signal);
    
    if (signal == nullptr)
    {
        return;
    }

    m_signals.Insert(signal);
}

inline void System::UnregisterSignal(SignalType* signal)
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 2, this, 
        "UnregisterSignal(signal=%p)", signal);
    
    if (signal == nullptr)
    {
        return;
    }
    m_signals.Remove(signal);
}

inline typename System::StatusType& System::GetStatus()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), 
        _DebugType, 3, this, "GetStatus()");

    return m_status;
}

inline const typename System::StatusType& System::GetStatus() const
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*(const_cast<System&>(*this).m_interface)), 
        _DebugType, 3, this, "GetStatus() const");

    return m_status;
}

inline typename System::MemoryType& System::GetMemory()
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 3, this, 
        "GetMemory()");

    return test::sys::Memory::GetInstance();
}

inline bool System::IsRunning() const
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*(const_cast<System&>(*this).m_interface)), 
        _DebugType, 3, this, "IsRunning() const");
    
    return m_status.IsStart();
}

inline bool System::IsDone() const
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*(const_cast<System&>(*this).m_interface)), 
        _DebugType, 3, this, "IsDone() const");
    
    return m_status.IsStart() && m_status.IsEnd();
}

inline bool System::IsError() const
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*(const_cast<System&>(*this).m_interface)), 
        _DebugType, 3, this, "IsError() const");
    
    return m_status.IsError();
}

inline bool System::IsTerminate() const
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*(const_cast<System&>(*this).m_interface)), 
        _DebugType, 3, this, "IsTerminate() const");
    
    return m_status.IsTerminate();
}

inline int System::Output(const char* format, ...)
{
    const bool is_lock = LockOutput();
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    if (!is_lock)
    {
        res = test::sys::Interface::VOutput(format, vlist);
    }
    else
    {
        res = m_log.VOutput(format, vlist);
        UnlockOutput();
    }
    va_end(vlist);
    return res;
}

inline int System::VOutput(const char* format, va_list args)
{
    const bool is_lock = LockOutput();
    if (!is_lock)
    {
        return test::sys::Interface::VOutput(format, args);
    }
    const int res = m_log.VOutput(format, args);
    UnlockOutput();
    return res;
}

inline int System::Info(const char* format, ...)
{
    const bool is_lock = LockOutput();
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    if (!is_lock)
    {
        res = test::sys::Interface::VInfo(format, vlist);
    }
    else
    {
        res = m_log.VOutputCallback(&InfoFormat, format, vlist);
        UnlockOutput();
    }
    va_end(vlist);
    return res;
}

inline int System::VInfo(const char* format, va_list args)
{
    const bool is_lock = LockOutput();
    if (!is_lock)
    {
        return test::sys::Interface::VInfo(format, args);
    }
    const int res = m_log.VOutputCallback(&InfoFormat, format, args);
    UnlockOutput();
    return res;
}

inline int System::Debug(DebugType& dbg, std::int8_t level, const void * obj,
    const char* format, ...)
{
    const bool is_lock = LockOutput();
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    if (!is_lock)
    {
        res = test::sys::Interface::VDebug(dbg, level, obj, format, vlist);
    }
    else if (level > dbg.GetLevel()) 
    {
        UnlockOutput();
    }
    else
    {
        res = m_log.VOutputCallback(&DebugFormat, dbg, level, obj, format, vlist);
        UnlockOutput();
    }
    va_end(vlist);
    return res;
}

inline int System::VDebug(DebugType& dbg, std::int8_t level, const void * obj,
    const char* format, va_list args)
{
    const bool is_lock = LockOutput();
    if (!is_lock)
    {
        return test::sys::Interface::VDebug(dbg, level, obj, format, args);
    }
    else if (level > dbg.GetLevel()) 
    {
        UnlockOutput();
        return 0;
    }
    const int res = m_log.VOutputCallback(&DebugFormat, dbg, level, 
        obj, format, args);
    UnlockOutput();
    return res;
}

inline int System::Error(Status code, const char* format, ...)
{
    const bool is_lock = LockOutput();
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    m_status.Error(code);
    if (!is_lock)
    {
        res = test::sys::Interface::VError(code, format, vlist);
    }
    else
    {
        res = m_log.VOutputCallback(&ErrorFormat, format, vlist);
        UnlockOutput();
    }
    va_end(vlist);
    return res;
}

inline int System::Error(StatusIntegerType code, const char* format, ...)
{
    const bool is_lock = LockOutput();
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    m_status.Error(code);
    if (!is_lock)
    {
        res = test::sys::Interface::VError(code, format, vlist);
    }
    else
    {
        res = m_log.VOutputCallback(&ErrorFormat, format, vlist);
        UnlockOutput();
    }
    va_end(vlist);
    return res;
}

inline int System::VError(Status code, const char* format, va_list args)
{
    const bool is_lock = LockOutput();
    m_status.Error(code);
    if (!is_lock)
    {
        return test::sys::Interface::VError(code, format, args);
    }
    const int res = m_log.VOutputCallback(&ErrorFormat, format, args);
    UnlockOutput();
    return res;
}

inline int System::VError(StatusIntegerType code, const char* format, 
    va_list args)
{
    const bool is_lock = LockOutput();
    m_status.Error(code);
    if (!is_lock)
    {
        return test::sys::Interface::VError(code, format, args);
    }
    const int res = m_log.VOutputCallback(&ErrorFormat, format, args);
    UnlockOutput();
    return res;
}

} //!test

#undef TEST_SYS_DEBUG_SYS_INSTANCE

#endif //!TEST_SYSTEM_H_
