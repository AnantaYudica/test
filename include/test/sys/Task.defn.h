#ifndef TEST_SYS_TASK_H_DEFN_
#define TEST_SYS_TASK_H_DEFN_

#include "Definition.h"
#include "Debug.h"
#include "out/Interface.defn.h"

#include <atomic>
#include <thread>
#include <functional>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

namespace test
{
namespace sys
{

class Task;

} //!sys

} //!task

#ifndef TEST_SYS_TASK_DLEVEL

#define TEST_SYS_TASK_DLEVEL 1

#endif //!TEST_SYS_TASK_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_SYS_TASK_DLEVEL, 
    "test::sys::Task", test::sys::Task);

namespace test
{
namespace sys
{

class Task
{
public:
    typedef test::sys::Definition DefinitionType;
    typedef typename DefinitionType::TimestampType TimestampType;
    typedef typename DefinitionType::TimeDurationType TimeDurationType;
public:
    typedef int(*FormatBeginCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, Task& task);
    typedef int(*FormatEndCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, Task& task);
    typedef int(*FormatAssertCallbackFunc)(char* buffer, 
        const std::size_t& buffer_size, Task& task, const char* cond_str,
        const char* file, const int& line, const char* variables);
public:
    static inline int DefaultFormatBegin(char* buffer, 
        const std::size_t& buffer_size, Task& task);
    static inline int DefaultFormatEnd(char* buffer, 
        const std::size_t& buffer_size, Task& task);
    static inline int DefaultFormatAssert(char* buffer, 
        const std::size_t& buffer_size, Task& task, const char* cond_str, 
        const char* file, const int& line, const char* variables);
private:
    bool m_error;
    std::atomic_bool m_start, m_stop, m_done;
    std::size_t m_threadHID;
    std::size_t m_index;
    char * m_name;
    TimestampType m_beginTimestamp, m_endTimestamp;
    FormatBeginCallbackFunc m_beginFmtCb;
    FormatEndCallbackFunc m_endFmtCb;
    FormatAssertCallbackFunc m_assertFmtCb;
    std::function<void(test::sys::Task&)> m_func;
public:
    template<std::size_t N>
    inline Task(const char(&name)[N]);
public:
    inline ~Task();
public:
    inline Task(const Task& cpy) = delete;
    inline Task(Task&& mov);
public:
    inline Task& operator=(const Task& cpy) = delete;
    inline Task& operator=(Task&& mov);
private:
    inline void BeforeRun();
private:
    inline void AfterRun();
public:
    inline void Initialize(typename std::thread::id id, 
        const std::size_t& index);
public:
    inline void Finalize();
public:
    inline void Run();
public:
    inline void Stop();
public:
    inline void Main(std::function<void(test::sys::Task&)> func);
public:
    inline void SetBeginFormatCallback(FormatBeginCallbackFunc func);
public:
    inline void SetEndFormatCallback(FormatEndCallbackFunc func);
public:
    inline void SetAssertFormatCallback(FormatAssertCallbackFunc func);
public:
    inline void VAssert(const bool& cond, const char* cond_str, 
        const char* file, const int& line, const char* format, va_list args)
        TEST_ATTRIBUTE((__format__ (__printf__, 6, 0)));
    inline void Assert(const bool& cond, const char* cond_str,
        const char* file, const int& line, const char* format, ...)
        TEST_ATTRIBUTE((__format__ (__printf__, 6, 7)));
public:
    inline const char* GetName() const; 
public:
    inline std::size_t GetThreadHID() const;
public:
    inline std::size_t GetThreadIndex() const;
public:
    inline TimestampType GetBeginTimeStamp() const;
public:
    inline TimestampType GetEndTimeStamp() const;
public:
    inline TimeDurationType GetRunTimeDuration() const;
public:
    inline bool IsStart() const;
public:
    inline bool IsRun() const;
public:
    inline bool IsStop() const;
public:
    inline bool IsFinish() const;
public:
    inline bool IsFailed() const;
};

} //!sys

} //!test

#endif //!TEST_SYS_TASK_H_DEFN_
