#ifndef TEST_SYSTEM_H_
#define TEST_SYSTEM_H_

#include "sys/Definition.h"
#include "sys/Signal.defn.h"
#include "sys/Status.h"
#include "sys/Log.h"
#include "sys/Signals.defn.h"

#include <cstddef>
#include <cstdlib>
#include <csignal>
#include <chrono>
#include <functional>
#include <limits>
#include <cstring>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

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

namespace test
{

class System
{
public:
    typedef test::sys::Signal SignalType;
    typedef TEST_SYS_DEF_STATUS StatusType;
    typedef typename StatusType::StatusIntegerType StatusIntegerType;
    typedef test::sys::Log<StatusType> LogType;
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
    inline void RegisterSignal(SignalType* signal);
public:
    inline void UnregisterSignal(SignalType* signal);
public:
    inline const char* GetErrorName();
public:
    inline int Info(const char * format, ...) 
        TEST_ATTRIBUTE((__format__ (__printf__, 2, 3)));
    inline int Error(StatusIntegerType code, const char * format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 3, 4)));
public:
    inline bool IsRunning() const;
    inline bool IsDone() const;
    inline bool IsError() const;
    inline bool IsTerminate() const;
};

} //!test

#include "sys/Signal.h"
#include "sys/Signals.h"

namespace test
{

inline void System::SignalHandler(int sig)
{
    System::GetInstance().m_status.Termination(sig);
    System::GetInstance().m_signals.Raise(sig);
    System::GetInstance().Termination();
}

inline System& System::GetInstance()
{
    static System instance;
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
    return LogFormat(buffer, buffer_size, status, msg, "INFO");
}

inline int System::ErrorFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg)
{
    return LogFormat(buffer, buffer_size, status, msg, "ERROR");
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
            "[%d Days %02d:%02d:%02d.%03d%03d][%s] : %s",
            dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, tag, msg);
    }
    else if (dur.Hour > 0)
    {
        return snprintf(buffer, buffer_size,
            "[%d:%02d:%02d.%03d%03d][%s] : %s",
            dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, tag, msg);
    }
    else if(dur.Minute > 0)
    {
        return snprintf(buffer, buffer_size,
            "[%d:%02d.%03d%03d][%s] : %s",
            dur.Minute, dur.Second, dur.Milisecond,
            dur.Microsecond, tag, msg);
    }

    return snprintf(buffer, buffer_size,
        "[%d.%03d%03d][%s] : %s",
        dur.Second, dur.Milisecond,
        dur.Microsecond, tag, msg);
}

inline System::System() :
    m_retValue(0),
    m_argSize(0),
    m_argValue(nullptr),
    m_status(),
    m_log(m_status),
    m_signals(m_status, m_log),
    m_out(NULL),
    m_outFilename(NULL)
{
    Initialization();
}

inline System::~System()
{
    Finalization();
    m_retValue = 0;
}

inline bool System::SetOutputFile(const char * outFilename)
{
    if (m_status.IsStart()) return false;
    m_out = fopen(outFilename, "w");
    if (m_out == NULL)
    {
        return false;
    }
    const auto size = strlen(outFilename);
    m_outFilename = (char *) malloc(size + 1);
    strncpy(m_outFilename, outFilename, size);
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
        "Start Timestamp : %d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n",
            output, dtime.Year, dtime.Month, dtime.Day, dtime.Hour, 
            dtime.Minute, dtime.Second, dtime.Milisecond, 
            dtime.Microsecond, dtime.UTC_Hour, dtime.UTC_Minute);

}

inline void System::PrintArguments()
{
    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_DASH_LINE_STR "\n"
        "Arguments size : %d\n",
        m_argSize);

    for (int i = 0; i < m_argSize; ++i)
    {
        m_log.OutputCallback(&EntryFormat, 
            "Argument[%d]: %s\n", i,
            m_argValue[i] == NULL ? "(null)": m_argValue[i]);
    }

    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_DASH_LINE_STR "\n");
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
        "End Timestamp : %d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n",
            dtime.Year, dtime.Month, dtime.Day, 
            dtime.Hour, dtime.Minute, dtime.Second, 
            dtime.Milisecond, dtime.Microsecond, 
            dtime.UTC_Hour, dtime.UTC_Minute);
    
    m_log.OutputCallback(&EntryFormat, 
        "Duration : %d Days %02d:%02d:%02d.%03d%03d\n",
        dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
        dur.Microsecond);

    m_log.OutputCallback(&EntryFormat, 
        "Retrun Value : %d\n", m_status.ReturnValue());
}

inline void System::PrintTerminateFooter()
{
    const auto start_timestamp = m_status.GetStartTimestamp();
    const auto term_timestamp = m_status.GetTerminationTimestamp();
    auto dtime = test::sys::Definition::GetDateTime(term_timestamp);
    auto dur = test::sys::Definition::GetTimeDuration(start_timestamp,
        term_timestamp);
    m_log.OutputCallback(&EntryFormat, 
        TEST_SYSTEM_DEF_ENTRY_LINE_STR "\n"
        "Terminate Timestamp : "
        "%d-%d-%d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n",
            dtime.Year, dtime.Month, dtime.Day, 
            dtime.Hour, dtime.Minute, dtime.Second, 
            dtime.Milisecond, dtime.Microsecond, 
            dtime.UTC_Hour, dtime.UTC_Minute);
    
    m_log.OutputCallback(&EntryFormat, 
        "Duration : %d Days %02d:%02d:%02d.%03d%03d\n",
        dur.Day, dur.Hour, dur.Minute, dur.Second, dur.Milisecond,
        dur.Microsecond);
    
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
    const int sig = m_status.GetTerminationSignal();
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
            "Terminate Signal : %d \n", sig);
    }
    else 
    {
        m_log.OutputCallback(&EntryFormat, 
            "Terminate Signal : %d (%s)\n", sig, sig_name);
    }
}

inline bool System::CopyArguments(int argc, char *argv[])
{
    const auto max_size = 
        std::numeric_limits<decltype(strlen(""))>::max();

    m_argSize = argc;
    m_argValue = (char**)malloc(sizeof(char*) * argc);
    if (m_argValue == NULL)
    {
        m_status.Error(test::sys::Status::sSysAllocArgsFailed);
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
            m_status.Error(test::sys::Status::sSysAllocArgsFailed);
            m_log.OutputCallback(&ErrorFormat, 
                "System allocation arguments failed");
            return false;
        }
        strncpy(m_argValue[i], argv[i], size);
        m_argValue[i][size] = '\0';
    }
    return true;
}

inline void System::FreeArguments()
{
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
    PrintTerminateFooter();
    Finalization();
}

inline bool System::EntryPoint()
{
    if (m_status.IsStart()) return false;

    m_argSize = 0;
    m_argValue = NULL;
    
    m_status.Start();
    PrintTitle();
    PrintArguments();
    return true;
}

inline bool System::EntryPoint(int argc, char *argv[])
{
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
    if (m_status.IsEnd()) return m_retValue;
    m_status.End();
    
    FreeArguments();
    
    PrintFooter();

    return m_retValue;
}

inline int System::ArgumentSize()
{
    return m_argSize;
}

inline const char* System::Argument(const std::size_t& i)
{
    return m_argValue[i];
}

inline void System::RegisterSignal(SignalType* signal)
{
    if (signal == nullptr)
    {
        return;
    }

    m_signals.Insert(signal);
}

inline void System::UnregisterSignal(SignalType* signal)
{
    if (signal == nullptr)
    {
        return;
    }
    m_signals.Remove(signal);
}

inline const char* System::GetErrorName()
{
    return m_status.GetErrorName();
}

inline int System::Info(const char * format, ...) 
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    res = m_log.VOutputCallback(&InfoFormat, format, vlist);
    va_end(vlist);
    return res;
}

inline int System::Error(StatusIntegerType code, const char * format, ...)
{
    va_list vlist;
    int res = 0;
    va_start(vlist, format);
    m_status.Error(code);
    res = m_log.VOutputCallback(&ErrorFormat, format, vlist);
    va_end(vlist);
    return res;
}

inline bool System::IsRunning() const
{
    return m_status.IsStart();
}

inline bool System::IsDone() const
{
    return m_status.IsStart() && m_status.IsEnd();
}

inline bool System::IsError() const
{
    return m_status.IsError();
}

inline bool System::IsTerminate() const
{
    return m_status.IsTerminate();
}

} //!test

#endif //!TEST_SYSTEM_H_
