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
#include "sys/Task.h"
#include "sys/Buffer.h"
#include "sys/Runner.h"

#include <cstddef>
#include <cstdlib>
#include <csignal>
#include <chrono>
#include <functional>
#include <limits>
#include <cstring>
#include <thread>

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

#ifndef TEST_SYS_DEBUG_BUFFER
#define TEST_SYS_DEBUG_BUFFER 1024
#endif //!TEST_SYS_DEBUG_BUFFER

#ifndef TEST_SYS_DEBUG_BUFFER_LINE
#define TEST_SYS_DEBUG_BUFFER_LINE 1024
#endif //!TEST_SYS_DEBUG_BUFFER_LINE

#ifndef TEST_SYS_ENABLE_THREAD
#define TEST_SYS_IS_ENABLE_THREAD true
#else
#define TEST_SYS_IS_ENABLE_THREAD false
#endif //!TEST_SYS_ENABLE_THREAD

#ifndef TEST_SYS_THREAD_SIZE
#define TEST_SYS_THREAD_SIZE 4
#endif //!TEST_SYS_THREAD_SIZE

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
    typedef test::sys::Task TaskType;
    typedef test::sys::Buffer<StatusType, TEST_SYS_DEBUG_BUFFER_LINE,
        TEST_SYS_DEBUG_BUFFER> BufferType;
#if TEST_SYS_IS_ENABLE_THREAD
    typedef test::sys::Runner<StatusType, BufferType, TEST_SYS_THREAD_SIZE>
        RunnerType;
#else
    typedef test::sys::Runner<StatusType, BufferType, 0>
        RunnerType;
#endif
    typedef typename DefinitionType::TimeDurationType TimeDurationType;
public:
    static constexpr std::size_t ThreadIDBuffer = TEST_SYS_THREAD_SIZE;
public:
    static inline void SignalHandler(int sig);
public:
    static inline System& GetInstance(); 
private:
    static inline int EntryFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static inline int InfoPrefixFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status);
private:
    static inline int InfoFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static inline int ErrorPrefixFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status);
private:
    static inline int ErrorFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg);
private:
    static inline int DebugPrefixFormat(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, 
        std::int8_t level, const void * obj, 
        const StatusType& status);
private:
    static inline int DebugFormat(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, 
        std::int8_t level, const void * obj, 
        const StatusType& status, 
        const char* msg);
private:
    static inline int ThreadFormat(char* buffer,
        const std::size_t& buffer_size, const std::size_t& hid);
private:
    static inline int TimeDurationFormat(char* buffer,
        const std::size_t& buffer_size, TimeDurationType time_dur);
private:
    static inline int LogPrefixFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char * tag);
private:
    static inline int LogFormat(char* buffer, 
        const std::size_t& buffer_size, const StatusType& status, 
        const char* msg, const char * tag);
private:
    static inline int TaskBeginFormat(char* buffer, 
        const std::size_t& buffer_size, TaskType& task);
private:
    static inline int TaskEndFormat(char* buffer, 
        const std::size_t& buffer_size, TaskType& task);
private:
    static inline int TaskAssertFormat(char* buffer, 
        const std::size_t& buffer_size, TaskType& task, const char* cond_str, 
        const char* file, const int& line, const char* variables);
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
    RunnerType m_runner;
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
protected:
    virtual inline void SetError(Status code) override;
    virtual inline void SetError(StatusIntegerType code) override;
public:
    virtual inline int PrefixFormatInfo(char* buffer, 
        const std::size_t& buffer_size) override;
public:
    virtual inline int PrefixFormatDebug(char* buffer, 
        const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
        const void * obj) override;
public:
    virtual inline int PrefixFormatError(char* buffer, 
        const std::size_t& buffer_size, Status code) override;
    virtual inline int PrefixFormatError(char* buffer, 
        const std::size_t& buffer_size, StatusIntegerType code) override;
public:
    virtual inline int PrefixFormatThread(char* buffer, 
        const std::size_t& buffer_size, const std::size_t& hid) override;
public:
    virtual inline int VOutput(const std::size_t& thread_hid, 
        const char* prefix, const char* format, va_list args) override
        TEST_ATTRIBUTE ((__format__ (__printf__, 4, 0)));
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
    inline void RegisterTask(test::sys::Task&& task) override;
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

inline int System::InfoPrefixFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status)
{
    return LogPrefixFormat(buffer, buffer_size, status, "[INFO]");
}

inline int System::InfoFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg)
{
    constexpr std::size_t tag_buffsize = TEST_SYS_OUTPUT_BUFFER;
    char tag[tag_buffsize + 1];
    InfoPrefixFormat(tag, tag_buffsize, status);
    tag[TEST_SYS_OUTPUT_BUFFER] = '\0';
    return LogFormat(buffer, buffer_size, status, msg, tag);
}

inline int System::ErrorPrefixFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status)
{
    return LogPrefixFormat(buffer, buffer_size, status, "[ERROR]");
}

inline int System::ErrorFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg)
{
    constexpr std::size_t tag_buffsize = TEST_SYS_OUTPUT_BUFFER;
    char tag[tag_buffsize + 1];
    ErrorPrefixFormat(tag, tag_buffsize, status);
    tag[TEST_SYS_OUTPUT_BUFFER] = '\0';
    return LogFormat(buffer, buffer_size, status, msg, tag);
}

inline int System::DebugPrefixFormat(char* buffer, 
    const std::size_t& buffer_size, DebugType& dbg, 
    std::int8_t level, const void * obj, 
    const StatusType& status)
{
    constexpr std::size_t tag_buffsize = TEST_SYS_OUTPUT_BUFFER;
    char tag[tag_buffsize + 1];
    const std::size_t dbg_size = snprintf(tag, tag_buffsize, "[DEBUG]");
    if (dbg_size >= tag_buffsize)
    {
        return LogPrefixFormat(buffer, buffer_size, status, tag);
    }
    const std::size_t tsize = dbg.TagName(tag + dbg_size, 
        tag_buffsize - dbg_size) + dbg_size;
    if (tsize >= tag_buffsize)
    {
        return LogPrefixFormat(buffer, buffer_size, status, tag);
    }
    const std::size_t osize = (obj == NULL ?
        snprintf(tag + tsize, tag_buffsize - tsize, "[Static]") :
        snprintf(tag + tsize, tag_buffsize - tsize, "[%p]", obj)) + 
            tsize;
    
    return LogPrefixFormat(buffer, buffer_size, status, tag);
}

inline int System::DebugFormat(char* buffer, 
    const std::size_t& buffer_size, DebugType& dbg, 
    std::int8_t level, const void * obj, 
    const StatusType& status, 
    const char* msg)
{
    constexpr std::size_t tag_buffsize = TEST_SYS_OUTPUT_BUFFER;
    char tag[tag_buffsize + 1];
    DebugPrefixFormat(tag, tag_buffsize, dbg, level, obj, status);
    tag[TEST_SYS_OUTPUT_BUFFER] = '\0';
    return LogFormat(buffer, buffer_size, status, msg, tag);
}

inline int System::ThreadFormat(char* buffer,
    const std::size_t& buffer_size, const std::size_t&)
{
#if TEST_SYS_IS_ENABLE_THREAD
    const std::size_t main_hid = DefinitionType::GetMainThreadHID();
    const std::size_t hid = DefinitionType::GetThisThreadHID();
    SystemType& system = GetInstance();
    const std::size_t index = system.m_runner.GetThreadIndex(hid);
    if (main_hid == hid)
    {
        return snprintf(buffer, buffer_size, "[MainThread][%zx]", 
            hid);
    }
    else if(index != (TEST_SYS_THREAD_SIZE + 1))
    {
        return snprintf(buffer, buffer_size, "[Thread-%zu][%zx]", 
            index, hid);
    }
    else
    {
        return snprintf(buffer, buffer_size, "[%zx]", 
            hid);
    }
#else
    return 0;
#endif
}

inline int System::TimeDurationFormat(char* buffer,
    const std::size_t& buffer_size, TimeDurationType time_dur)
{
    if (time_dur.Day > 0)
    {
        return snprintf(buffer, buffer_size, 
            "%d Days %02d:%02d:%02d.%03d%03d",
            time_dur.Day, time_dur.Hour, time_dur.Minute, 
            time_dur.Second, time_dur.Milisecond,
            time_dur.Microsecond);
    }
    else if (time_dur.Hour > 0)
    {
        return snprintf(buffer, buffer_size,
            "%d:%02d:%02d.%03d%03d",
            time_dur.Hour, time_dur.Minute, time_dur.Second, 
            time_dur.Milisecond, time_dur.Microsecond);
    }
    else if(time_dur.Minute > 0)
    {
        return snprintf(buffer, buffer_size,
            "%d:%02d.%03d%03d",
            time_dur.Minute, time_dur.Second, time_dur.Milisecond,
            time_dur.Microsecond);
    }

    return snprintf(buffer, buffer_size,
        "%d.%03d%03d",
        time_dur.Second, time_dur.Milisecond,
        time_dur.Microsecond);
}

inline int System::LogPrefixFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char * tag)
{
    const auto start = status.GetStartTimestamp();
    if (start == 0)
    {
        return 0;
    }
    constexpr int time_dur_size = 100;
    char time_dur[time_dur_size + 1]; 
    const auto now = test::sys::Definition::GetTimestampNow();
    const auto dur = test::sys::Definition::GetTimeDuration(start, now);
    time_dur[time_dur_size] = '\0';
    TimeDurationFormat(time_dur, time_dur_size, dur);
    return snprintf(buffer, buffer_size, "[%s]%s", time_dur, tag);
}

inline int System::LogFormat(char* buffer, 
    const std::size_t& buffer_size, const StatusType& status, 
    const char* msg, const char * tag)
{
    return snprintf(buffer, buffer_size, "%s: %s", tag, msg);
}

inline int System::TaskBeginFormat(char* buffer, 
    const std::size_t& buffer_size, TaskType& task)
{
#if TEST_SYS_IS_ENABLE_THREAD
    SystemType& system = GetInstance();
    const std::size_t hid = DefinitionType::GetThisThreadHID();
    const std::size_t index = system.m_runner.GetThreadIndex(hid);
    return snprintf(buffer, buffer_size, "Task{%s} Start at Thread-%zu(%zx) ...", 
        task.GetName(), index, hid);
#else
    return snprintf(buffer, buffer_size, "Task{%s} Start ...", task.GetName());

#endif
}

inline int System::TaskEndFormat(char* buffer, 
    const std::size_t& buffer_size, TaskType& task)
{
    constexpr int time_dur_size = 100;
    char time_dur[time_dur_size + 1]; 
    const auto start = task.GetBeginTimeStamp();
    const auto end = task.GetEndTimeStamp();

#if TEST_SYS_IS_ENABLE_THREAD

    SystemType& system = GetInstance();
    const std::size_t hid = DefinitionType::GetThisThreadHID();
    const std::size_t index = system.m_runner.GetThreadIndex(hid);

    if (end == 0)
    {    
        return snprintf(buffer, buffer_size, "Task{%s} End "
            "at Thread-%zu(%zx) ...", task.GetName(), index, hid);
    }
    const auto dur = test::sys::Definition::GetTimeDuration(start, end);
    TimeDurationFormat(time_dur, time_dur_size, dur);
    time_dur[time_dur_size] = '\0';
    return snprintf(buffer, buffer_size, 
        "Task{%s} End at Thread-%zu(%zx) ... (Time Duration: %s)", 
        task.GetName(), index, hid, time_dur);
#else

    if (end == 0)
    {    
        return snprintf(buffer, buffer_size, "Task{%s} End ...", 
            task.GetName());
    }
    const auto dur = test::sys::Definition::GetTimeDuration(start, end);
    TimeDurationFormat(time_dur, time_dur_size, dur);
    time_dur[time_dur_size] = '\0';
    return snprintf(buffer, buffer_size, 
        "Task{%s} End ... (Time Duration: %s)", 
        task.GetName(), time_dur);
#endif
}

inline int System::TaskAssertFormat(char* buffer, 
    const std::size_t& buffer_size, TaskType& task, const char* cond_str, 
    const char* file, const int& line, const char* variables)
{
    return snprintf(buffer, buffer_size, 
        "Assertion \"%s\" failed: file %s, line %zu, info %s",
        cond_str, file, line, variables);
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
    m_runner(m_status, m_log)
{
    TEST_SYS_DEBUG_SYS_INSTANCE((*m_interface), _DebugType, 1, this, 
        "Default Constructor");
    
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
#if TEST_SYS_IS_ENABLE_THREAD
        "Task Thread : %d\n"
#endif
        "Start Timestamp : %d-%02d-%02d, %02d:%02d:%02d.%03d%03d "
            "UTC%+03d:%02d", output, 
#if TEST_SYS_IS_ENABLE_THREAD
            TEST_SYS_THREAD_SIZE,
#endif
            dtime.Year, dtime.Month, dtime.Day, dtime.Hour, 
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
        "End Timestamp : %d-%02d-%02d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n"
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
            "%d-%02d-%02d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n"
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
            "%d-%02d-%02d, %02d:%02d:%02d.%03d%03d UTC%+03d:%02d\n"
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

inline void System::SetError(Status code)
{
    m_status.Error(code);
}

inline void System::SetError(StatusIntegerType code)
{
    m_status.Error(code);
}

inline int System::PrefixFormatInfo(char* buffer, 
    const std::size_t& buffer_size)
{
    return InfoPrefixFormat(buffer, buffer_size, m_status);
}

inline int System::PrefixFormatDebug(char* buffer, 
    const std::size_t& buffer_size, DebugType& dbg, std::int8_t level, 
    const void * obj)
{
    return DebugPrefixFormat(buffer, buffer_size, dbg, level, obj, m_status);
}

inline int System::PrefixFormatError(char* buffer, 
    const std::size_t& buffer_size, Status code)
{
    return ErrorPrefixFormat(buffer, buffer_size, m_status);
}

inline int System::PrefixFormatError(char* buffer, 
    const std::size_t& buffer_size, StatusIntegerType code)
{
    return ErrorPrefixFormat(buffer, buffer_size, m_status);
}

inline int System::PrefixFormatThread(char* buffer, 
    const std::size_t& buffer_size, const std::size_t& hid)
{
    return ThreadFormat(buffer, buffer_size, hid);
}

inline int System::VOutput(const std::size_t& thread_hid, 
    const char* prefix, const char* format, va_list args)
{
    const std::size_t main_hid = DefinitionType::GetMainThreadHID();
    constexpr std::size_t msg_buffsize = TEST_SYS_OUTPUT_BUFFER;
    char msg[msg_buffsize + 1];
    vsnprintf(msg, msg_buffsize, format, args);
    msg[msg_buffsize] = '\0';
    int res = 0;
#if TEST_SYS_IS_ENABLE_THREAD
    if (thread_hid == main_hid || !m_runner.IsRun(thread_hid))
    {
        res = m_log.Output("%s: %s", prefix, msg);
    }
    else
    {
        constexpr std::size_t buffsize = TEST_SYS_OUTPUT_BUFFER;
        char buff[buffsize + 1];
        res = snprintf(buff, buffsize, "%s: %s", prefix, msg);
        buff[buffsize] = '\0';
        if (!m_runner.LogBufferOutput(DefinitionType::GetThisThreadHID(),
            buff))
        {
            res = m_log.Output("%s: %s", prefix, msg);
        }
    }
#else
    if (!m_runner.IsRun(thread_hid))
    {
        res = m_log.Output("%s: %s", prefix, msg);
    }
    else
    {
        constexpr std::size_t buffsize = TEST_SYS_OUTPUT_BUFFER;
        char buff[buffsize + 1];
        res = snprintf(buff, buffsize, "%s: %s", prefix, msg);
        buff[buffsize] = '\0';
        m_runner.LogBufferOutput(DefinitionType::GetThisThreadHID(), buff);
    }

#endif
    return res;
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

inline void System::RegisterTask(test::sys::Task&& task)
{
    return m_runner.Job(std::move(task));
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

} //!test

#undef TEST_SYS_DEBUG_SYS_INSTANCE

#endif //!TEST_SYSTEM_H_
