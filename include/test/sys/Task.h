#ifndef TEST_SYS_TASK_H_
#define TEST_SYS_TASK_H_

#include "Interface.h"
#include "Task.defn.h"
#include "out/Interface.h"

namespace test
{
namespace sys
{

inline int Task::DefaultFormatBegin(char* buffer, 
    const std::size_t& buffer_size, Task& task)
{
    return 0;
}

inline int Task::DefaultFormatEnd(char* buffer, 
    const std::size_t& buffer_size, Task& task)
{
    return 0;
}

inline int Task::DefaultFormatAssert(char* buffer, 
    const std::size_t& buffer_size, Task& task, const char* cond_str, 
    const char* file, const int& line, const char* variables)
{
    return snprintf(buffer, buffer_size, 
        "Assertion \"%s\" failed: file %s, line %zu, info %s",
        cond_str, file, line, variables);
}

template<std::size_t N>
inline Task::Task(const char(&name)[N]) :
    m_error(false),
    m_start(false),
    m_stop(false),
    m_done(false),
    m_threadHID(0),
    m_index(0),
    m_name((char*)malloc(N + 1)),
    m_beginTimestamp(0),
    m_endTimestamp(0),
    m_beginFmtCb(DefaultFormatBegin),
    m_endFmtCb(DefaultFormatEnd),
    m_assertFmtCb(DefaultFormatAssert),
    m_func(nullptr)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 1, this, 
        "Constructor(name=%s)", name);

    if (m_name != NULL) 
    {
        
#ifdef __STDC_LIB_EXT1__
        memcpy_s(m_name, N, name, N);
#else
        memcpy(m_name, name, N);
#endif 
        m_name[N] = '\0';
    }
    else 
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sTaskAllocationFailed,
            "Buffers allocation failed");
    }
}

inline Task::~Task()
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 1, this, 
        "Destructor");

    if (m_name != NULL)
    {
        free(m_name);
        m_name = NULL;
    }
}

inline Task::Task(Task&& mov) :
    m_error(mov.m_error),
    m_start(mov.m_start.load()),
    m_stop(mov.m_stop.load()),
    m_done(mov.m_done.load()),
    m_threadHID(mov.m_threadHID),
    m_index(mov.m_index),
    m_name(mov.m_name),
    m_beginTimestamp(mov.m_beginTimestamp),
    m_endTimestamp(mov.m_endTimestamp),
    m_beginFmtCb(mov.m_beginFmtCb),
    m_endFmtCb(mov.m_endFmtCb),
    m_assertFmtCb(mov.m_assertFmtCb),
    m_func(mov.m_func)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 1, this, 
        "Move Constructor(move=%p)", &mov);

    mov.m_error = false;
    mov.m_start = false;
    mov.m_stop = false;
    mov.m_done = false;
    mov.m_threadHID = 0;
    mov.m_index = 0;
    mov.m_name = NULL;
    mov.m_beginTimestamp = 0;
    mov.m_endTimestamp = 0;
    mov.m_beginFmtCb = DefaultFormatBegin;
    mov.m_endFmtCb = DefaultFormatEnd;
    mov.m_assertFmtCb = DefaultFormatAssert;
    mov.m_func = nullptr;
}

inline Task& Task::operator=(Task&& mov)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 1, this, 
        "Move Assignment(move=%p)", &mov);

    m_error = mov.m_error;
    m_start = mov.m_start.load();
    m_stop = mov.m_stop.load();
    m_done = mov.m_done.load();
    m_threadHID = mov.m_threadHID;
    m_index = mov.m_index;
    m_name = mov.m_name;
    m_beginTimestamp = mov.m_beginTimestamp;
    m_endTimestamp = mov.m_endTimestamp;
    m_beginFmtCb = mov.m_beginFmtCb;
    m_endFmtCb = mov.m_endFmtCb;
    m_assertFmtCb = mov.m_assertFmtCb;
    m_func = mov.m_func;

    mov.m_error = false;
    mov.m_start = false;
    mov.m_stop = false;
    mov.m_done = false;
    mov.m_threadHID = 0;
    mov.m_index = 0;
    mov.m_name = NULL;
    mov.m_beginTimestamp = 0;
    mov.m_endTimestamp = 0;
    mov.m_beginFmtCb = DefaultFormatBegin;
    mov.m_endFmtCb = DefaultFormatEnd;
    mov.m_assertFmtCb = DefaultFormatAssert;
    mov.m_func = nullptr;

    return *this;
}

inline void Task::BeforeRun()
{
    typedef test::sys::Interface SystemType;
    char buffer[TEST_SYS_OUTPUT_BUFFER + 1];
    buffer[0] = '\0';
    const int res = m_beginFmtCb(buffer, TEST_SYS_OUTPUT_BUFFER, *this);
    buffer[TEST_SYS_OUTPUT_BUFFER] = '\0';
    if (res == 0)
    {
        return;
    }
    SystemType::GetInstance().Info(DefinitionType::GetMainThreadHID(),
        "%s", buffer);
}

inline void Task::AfterRun()
{
    typedef test::sys::Interface SystemType;
    char buffer[TEST_SYS_OUTPUT_BUFFER + 1];
    buffer[0] = '\0';
    const int res = m_endFmtCb(buffer, TEST_SYS_OUTPUT_BUFFER, *this);
    buffer[TEST_SYS_OUTPUT_BUFFER] = '\0';
    if (res == 0)
    {
        return;
    }
    SystemType::GetInstance().Info(DefinitionType::GetMainThreadHID(),
        "%s", buffer);
}

inline void Task::Initialize(typename std::thread::id id, 
    const std::size_t& index)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 3, this, 
        "Initialize(id=%zu, index=%zu)", DefinitionType::GetThreadHID(id),
            index);

    m_threadHID = DefinitionType::GetThreadHID(id);
    m_index = index;
}

inline void Task::Finalize()
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 3, this, "Finalize()");

    m_stop.store(true);
    m_done.store(true);
}

inline void Task::Run()
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, "Run()");

    if (m_start.load()) 
    {
        TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, 
            "Run when Start");
        return;
    }
    m_start.store(true);
    if (m_func)
    {
        m_beginTimestamp = DefinitionType::GetTimestampNow();
        BeforeRun();
        m_func(*this);
        m_endTimestamp = DefinitionType::GetTimestampNow();
        AfterRun();
    }
}

inline void Task::Stop()
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, "Stop()");

    if (!m_start.load() && m_stop.load())
    {
        return;
    }
    m_stop.store(true);
}

inline void Task::Main(std::function<void(test::sys::Task&)> func)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, 
        "Main(func=%p)", &func);

    if (m_func != nullptr) 
    {
        return;
    }
    m_func = func;
}

inline void Task::SetBeginFormatCallback(FormatBeginCallbackFunc func)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, 
        "SetBeginFormatCallback(func=%p)", func);

    if (IsRun())
    {
        return;
    }

    if (func != nullptr)
    {
        m_beginFmtCb = func;
    }
}

inline void Task::SetEndFormatCallback(FormatEndCallbackFunc func)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, 
        "SetEndFormatCallback(func=%p)", func);

    if (IsRun())
    {
        return;
    }

    if (func != nullptr)
    {
        m_endFmtCb = func;
    }
}

inline void Task::SetAssertFormatCallback(FormatAssertCallbackFunc func)
{
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Task> _DebugType;
    TEST_SYS_DEBUG_MAIN_THREAD(SystemType, _DebugType, 4, this, 
        "SetAssertFormatCallback(func=%p)", func);

    if (IsRun())
    {
        return;
    }

    if (func != nullptr)
    {
        m_assertFmtCb = func;
    }
}

inline void Task::VAssert(const bool& cond, const char* cond_str,
    const char* file, const int& line, const char* format, va_list args)
{
    typedef test::sys::Interface SystemType;
    if (cond == true)
    {
        return;
    }
    m_error = true;
    char buffer[TEST_SYS_OUTPUT_BUFFER + 1];
    char variables[TEST_SYS_OUTPUT_BUFFER + 1];
    vsnprintf(variables, TEST_SYS_OUTPUT_BUFFER, format, args);
    variables[TEST_SYS_OUTPUT_BUFFER] = '\0';

    m_assertFmtCb(buffer, TEST_SYS_OUTPUT_BUFFER, *this, 
        cond_str, file, line, variables);
    buffer[TEST_SYS_OUTPUT_BUFFER] = '\0';

    SystemType::GetInstance().
        Error(DefinitionType::Status::sTaskFailed,
            "%s", buffer);
}

inline void Task::Assert(const bool& cond, const char* cond_str,
    const char* file, const int& line, const char* format, ...)
{
    va_list vlist;
    va_start(vlist, format);
    VAssert(cond, cond_str, file, line, format, vlist);
    va_end(vlist);
}

inline const char * Task::GetName() const
{
    return m_name;
}

inline std::size_t Task::GetThreadHID() const
{
    return m_threadHID;
}

inline std::size_t Task::GetThreadIndex() const
{
    return m_index;
}

inline typename Task::TimestampType Task::GetBeginTimeStamp() const
{
    return m_beginTimestamp;
}

inline typename Task::TimestampType Task::GetEndTimeStamp() const
{
    return m_endTimestamp;
}

inline typename Task::TimeDurationType Task::GetRunTimeDuration() const
{
    return DefinitionType::GetTimeDuration(m_beginTimestamp, m_endTimestamp);
}

inline bool Task::IsStart() const
{
    return m_start.load();
}

inline bool Task::IsRun() const
{
    return m_start.load() && !m_stop.load();
}

inline bool Task::IsStop() const
{
    return m_start.load() && m_stop.load();
}

inline bool Task::IsFinish() const
{
    return m_start.load() && m_stop.load() && m_done.load();
}

inline bool Task::IsFailed() const
{
    return m_error;
}

} //!sys

} //!test

#endif //!TEST_SYS_TASK_H_
