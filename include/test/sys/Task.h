#ifndef TEST_SYS_TASK_H_
#define TEST_SYS_TASK_H_

#include "Debug.h"

#include <atomic>
#include <thread>
#include <functional>
#include <utility>
#include <cstdlib>
#include <cstring>

namespace test
{
namespace sys
{

class Task;

} //!sys

} //!task

#ifndef TEST_SYS_STATUS_DLEVEL

#define TEST_SYS_STATUS_DLEVEL 1

#endif //!TEST_SYS_STATUS_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_SYS_STATUS_DLEVEL, 
    "test::sys::Task", test::sys::Task);

namespace test
{
namespace sys
{

class Task
{
private:
    std::atomic_bool m_start, m_stop, m_done;
    typename std::thread::id m_id;
    std::size_t m_index;
    char * m_name;
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
    inline typename std::thread::id GetThreadID() const;
public:
    inline std::size_t GetThreadIndex() const;
public:
    inline bool IsStart() const;
public:
    inline bool IsRun() const;
public:
    inline bool IsStop() const;
public:
    inline bool IsFinish() const;
public:
    inline bool IsDone() const;
};

template<std::size_t N>
inline Task::Task(const char(&name)[N]) :
    m_start(false),
    m_stop(false),
    m_done(false),
    m_id(0),
    m_index(0),
    m_name((char*)malloc(N + 1)),
    m_func(nullptr)
{
    if (m_name != NULL) 
    {
        
#ifdef __STDC_LIB_EXT1__
        memcpy_s(m_name, N, name, N);
#else
        memcpy(m_name, name, N);
#endif 
        m_name[N] = '\0';
    }
}

inline Task::~Task()
{
    if (m_name != NULL)
    {
        free(m_name);
        m_name = NULL;
    }
}

inline Task::Task(Task&& mov) :
    m_start(mov.m_start.load()),
    m_stop(mov.m_stop.load()),
    m_done(mov.m_done.load()),
    m_id(mov.m_id),
    m_index(mov.m_index),
    m_name(mov.m_name),
    m_func(mov.m_func)
{
    mov.m_start = false;
    mov.m_stop = false;
    mov.m_done = false;
    mov.m_index = 0;
    mov.m_name = NULL;
    mov.m_func = nullptr;
}

inline Task& Task::operator=(Task&& mov)
{
    m_start = mov.m_start.load();
    m_stop = mov.m_stop.load();
    m_done = mov.m_done.load();
    m_id = mov.m_id;
    m_index = mov.m_index;
    m_name = mov.m_name;
    m_func = mov.m_func;

    mov.m_start = false;
    mov.m_stop = false;
    mov.m_done = false;
    mov.m_index = 0;
    mov.m_name = NULL;
    mov.m_func = nullptr;

    return *this;
}

inline void Task::Initialize(typename std::thread::id id,
    const std::size_t& index)
{
    m_id = id;
}

inline void Task::Finalize()
{
    m_stop.store(true);
    m_done.store(true);
}

inline void Task::Run()
{
    if (m_start.load()) 
    {
        return;
    }
    m_start.store(true);
    if (m_func)
    {
        m_func(*this);
    }
}

inline void Task::Stop()
{
    if (!m_start.load() && m_stop.load())
    {
        return;
    }
    m_stop.store(true);
}

inline void Task::Main(std::function<void(test::sys::Task&)> func)
{
    if (m_func != nullptr) 
    {
        return;
    }
    m_func = func;
}

inline typename std::thread::id Task::GetThreadID() const
{
    return m_id;
}

inline std::size_t Task::GetThreadIndex() const
{
    return m_index;
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

} //!sys

} //!test

#endif //!TEST_SYS_TASK_H_
