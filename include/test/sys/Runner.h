#ifndef TEST_SYS_RUNNER_H_
#define TEST_SYS_RUNNER_H_

#include "out/Interface.h"
#include "Definition.h"
#include "Interface.h"
#include "Task.h"
#include "runner/Index.h"
#include "runner/Key.h"
#include "runner/Reference.h"

#include <cstdlib>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <utility>

namespace test
{
namespace sys
{

template<typename TStatus, typename TBuffer, std::size_t N>
class Runner;

} //!sys

} //!test


#ifndef TEST_SYS_RUNNER_DLEVEL

#define TEST_SYS_RUNNER_DLEVEL 3

#endif //!TEST_SYS_RUNNER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>,\
    test::sys::dbg::Type<TBuffer>,\
    test::sys::dbg::type::Value<std::size_t, N>

template<typename TStatus, typename TBuffer, std::size_t N>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_RUNNER_DLEVEL, 
    "test::sys::Runner", 
    test::sys::Runner<TStatus, TBuffer, N>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS
namespace test
{
namespace sys
{

template<typename TStatus, typename TBuffer, std::size_t N>
class Runner
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::
        Runner<TStatus, TBuffer, N>> _DebugType;
    typedef test::sys::Definition DefinitionType;
public:
    typedef typename DefinitionType::TimestampType TimestampType;
public:
    typedef TStatus StatusType;
    typedef test::sys::out::Interface<TStatus> LogType;
    typedef TBuffer BufferType;
    typedef test::sys::runner::Reference ReferenceType;
public:
    typedef test::sys::Task TaskType;
    typedef typename TaskType::FormatBeginCallbackFunc 
        FormatTaskBeginCallbackFunc;
    typedef typename TaskType::FormatEndCallbackFunc 
        FormatTaskEndCallbackFunc;
    typedef typename TaskType::FormatAssertCallbackFunc 
        FormatTaskAssertCallbackFunc;
public:
    typedef test::sys::runner::Index<
                2,      3,      5,      7,     
        11,     13,     17,     19,     23,
        29,     31,     37,     41,     43, 
        47,     53,     59,     61,     67,
        71,     73,     79,     83,     89, 
        97,     101,    103,    107,    109, 
        113,    127,    131,    137,    139,
        149,    151,    157,    163,    167, 
        173,    179,    181,    191,    193, 
        197,    199,    211,    223,    227, 
        229,    233,    239,    241,    251, 
        257,    263,    269,    271,    277, 
        281,    283,    293,    307,    311, 
        313,    317,    331,    337,    347, 
        349,    353,    359,    367,    373, 
        379,    383,    389,    397,    401, 
        409,    419,    421,    431,    433, 
        439,    443,    449,    457,    461, 
        463,    467,    479,    487,    491, 
        499,    503,    509,    521,    523, 
        541,    547,    557,    563,    569, 
        571,    577,    587,    593,    599, 
        601,    607,    613,    617,    619, 
        631,    641,    643,    647,    653, 
        659,    661,    673,    677,    683, 
        691,    701,    709,    719,    727, 
        733,    739,    743,    751,    757, 
        761,    769,    773,    787,    797, 
        809,    811,    821,    823,    827, 
        829,    839,    853,    857,    859, 
        863,    877,    881,    883,    887, 
        907,    911,    919,    929,    937, 
        941,    947,    953,    967,    971, 
        977,    983,    991,    997,    1009, 
        1013,   1019,   1021,   1031,   1033 > IndexType;
    typedef test::sys::runner::Key KeyType;
private:
    static void MainFunction(void* obj, std::size_t index);
private:
    static KeyType InitializeKey(std::thread::id main_id, std::thread(&threads)[N],
        std::size_t(&index)[N + 1], std::size_t(&hids)[N + 1]);
private:
    static void InitializeBuffer(BufferType**& buffer, std::size_t*& indexs, 
        const KeyType& key, std::size_t(&index)[N + 1], StatusType& status);
private:
    static void FinalizeBuffer(BufferType**& buffer, std::size_t*& indexs, 
        const KeyType& key, std::size_t(&index)[N + 1]);
private:
    static void BeginRunTask(Runner<TStatus, TBuffer, N>* runner,
        std::size_t&& index);
    static void EndRunTask(Runner<TStatus, TBuffer, N>* runner,
        std::size_t&& index);
private:
    static void CallClear(void* ptr);
    static bool CallIsStop(void* ptr);
private:
    std::size_t m_queueBegin, m_queueEnd;
    std::size_t m_keyIndex;
    StatusType& m_status;
    LogType& m_log;
    KeyType m_key;
    std::atomic_bool m_failed, m_start, m_stop, m_finish;
    std::atomic_size_t m_idleCount, m_runCount, m_doneCount;
    FormatTaskBeginCallbackFunc m_beginTaskFmtCb;
    FormatTaskEndCallbackFunc m_endTaskFmtCb;
    FormatTaskAssertCallbackFunc m_assertTaskFmtCb;
    ReferenceType m_ref;
    std::thread m_threads[N];
    std::size_t m_queue[N + 1];
    std::size_t m_indexThreads[N + 1];
    std::size_t m_hidThreads[N + 1];
    std::mutex m_queueLock;
    std::atomic_bool m_tasksReady[N];
    std::atomic_bool m_tasksRun[N];
    test::sys::Task* m_tasks[N];
    BufferType** m_buffers;
    std::size_t* m_indexs;
public:
    Runner(StatusType& status, LogType& log);
public:
    ~Runner();
public:
    Runner(const Runner<TStatus, TBuffer, N>& cpy) = delete;
    Runner(Runner<TStatus, TBuffer, N>&& mov) = delete;
public:
    Runner<TStatus, TBuffer, N>& 
        operator=(const Runner<TStatus, TBuffer, N>& cpy) = delete;
    Runner<TStatus, TBuffer, N>& 
        operator=(Runner<TStatus, TBuffer, N>&& mov) = delete;
private:
    void Initialize();
private:
    void Finalize();
    void Finalize(const std::size_t& index, const bool& request);
private:
    void Clean(const std::size_t& index);
private:
    void Request(const std::size_t& index);
private:
    test::sys::Task* GetRequest(const std::size_t& index);
private:
    void PoolingLogBuffer(const std::size_t& thread_hid, 
        TimestampType begin, TimestampType end);
public:
    std::size_t QueueSize() const;
public:
    bool LogBufferOutput(const std::size_t& thread_hid, const char* msg);
public:
    bool ClearLogBuffer(const std::size_t& thread_hid);
public:
    std::size_t GetThreadIndex(const std::size_t& thread_hid);
public:
    void SetBeginTaskFormatCallback(FormatTaskBeginCallbackFunc func);
public:
    void SetEndTaskFormatCallback(FormatTaskEndCallbackFunc func);
public:
    void SetAssertTaskFormatCallback(FormatTaskAssertCallbackFunc func);
public:
    void Job(test::sys::Task&& task);
public:
    void Stop();
public:
    void Detach();
public:
    void WaitAndStop();
public:
    std::size_t IdleCount() const;
public:
    std::size_t RunCount() const;
public:
    bool IsStart() const;
public:
    bool IsStop() const;
public:
    bool IsFinish() const;
public:
    bool IsDone() const;
public:
    bool IsFailed() const;
public:
    bool IsRun(const std::size_t& thread_hid);
};

template<typename TStatus, typename TBuffer>
class Runner<TStatus, TBuffer, 0>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::
        Runner<TStatus, TBuffer, 0>> _DebugType;
    typedef test::sys::Definition DefinitionType;
public:
    typedef typename DefinitionType::TimestampType TimestampType;
public:
    typedef TStatus StatusType;
    typedef test::sys::out::Interface<TStatus> LogType;
    typedef TBuffer BufferType;
public:
    typedef test::sys::Task TaskType;
    typedef typename TaskType::FormatBeginCallbackFunc 
        FormatTaskBeginCallbackFunc;
    typedef typename TaskType::FormatEndCallbackFunc 
        FormatTaskEndCallbackFunc;
    typedef typename TaskType::FormatAssertCallbackFunc 
        FormatTaskAssertCallbackFunc;
private:
    static void BeginRunTask(Runner<TStatus, TBuffer, 0>* runner);
    static void EndRunTask(Runner<TStatus, TBuffer, 0>* runner);
private:
    bool m_run, m_failed, m_stop;
    StatusType& m_status;
    LogType& m_log;
    BufferType m_buffer;
    FormatTaskBeginCallbackFunc m_beginTaskFmtCb;
    FormatTaskEndCallbackFunc m_endTaskFmtCb;
    FormatTaskAssertCallbackFunc m_assertTaskFmtCb;
public:
    Runner(StatusType& status, LogType& log);
public:
    ~Runner();
public:
    Runner(const Runner<TStatus, TBuffer, 0>& cpy) = delete;
    Runner(Runner<TStatus, TBuffer, 0>&& mov) = delete;
public:
    Runner<TStatus, TBuffer, 0>& 
        operator=(const Runner<TStatus, TBuffer, 0>& cpy) = delete;
    Runner<TStatus, TBuffer, 0>& 
        operator=(Runner<TStatus, TBuffer, 0>&& mov) = delete;
private:
    void Initialize();
private:
    void Finalize();
    void Finalize(const std::size_t&, const bool&);
private:
    void Clear(const std::size_t&);
private:
    void Request(const std::size_t&);
private:
    test::sys::Task* GetRequest(const std::size_t&);
private:
    void PoolingLogBuffer(TimestampType begin, TimestampType end);
public:
    std::size_t QueueSize() const;
public:
    bool LogBufferOutput(const std::size_t& thread_hid, const char* msg);
public:
    bool ClearLogBuffer(const std::size_t& thread_hid);
public:
    std::size_t GetThreadIndex(const std::size_t& thread_hid);
public:
    inline void SetBeginTaskFormatCallback(FormatTaskBeginCallbackFunc func);
public:
    inline void SetEndTaskFormatCallback(FormatTaskEndCallbackFunc func);
public:
    inline void SetAssertTaskFormatCallback(FormatTaskAssertCallbackFunc func);
public:
    void Job(test::sys::Task&& task);
public:
    void Stop();
public:
    void Detach();
public:
    void WaitAndStop();
public:
    std::size_t IdleCount() const;
public:
    std::size_t RunCount() const;
public:
    bool IsStart() const;
public:
    bool IsStop() const;
public:
    bool IsFailed() const;
public:
    bool IsDone() const;
public:
    bool IsFinish() const;
public:
    bool IsRun(const std::size_t& thread_hid);
};

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::MainFunction(void* obj, std::size_t index)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
        "MainFunction(obj=%p, index=%zu)", obj, index);

    const std::size_t index_0 = index - 1;

    Runner<TStatus, TBuffer, N>* runner = (Runner<TStatus, TBuffer, N>*)(obj);
    const std::size_t thread_hid = DefinitionType::GetThisThreadHID();
    bool request = false;
    if (runner == NULL)
    {
        SystemType::GetInstance().Error(
            DefinitionType::Status::sRunnerNullPointer,
            "Object null pointer");
        return;
    }

    TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
        "Wait to Start");

    while(!runner->IsStart()) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    const std::size_t buffer_index = runner->m_key.Index(thread_hid);
    BufferType* buffer = runner->m_buffers[buffer_index];
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, "Start");

    runner->m_doneCount++;

    while(!runner->IsStop())
    {
        runner->Request(index_0);
        request = true;
        test::sys::Task* task = NULL;
        
        TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
            "Wait new Task");

        while(!runner->IsStop() && 
            (task = runner->GetRequest(index_0)) == NULL)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if (runner->IsStop())
        {
            if (task != NULL)
            {
                TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
                    "Task(%p) Not running beacuse Runner Stop", task);
                runner->Clean(index_0);
            }
            else 
            {    
                TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
                    "Runner Stop");
            }
            
            
            task = NULL;
            break;
        }
        TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
            "Task(%p) Start", task);
        request = false;
        task->Initialize(std::this_thread::get_id(), index_0);
        task->template Run<Runner<TStatus, TBuffer, N>, std::size_t>(runner, 
            &Runner<TStatus, TBuffer, N>::BeginRunTask,
            &Runner<TStatus, TBuffer, N>::EndRunTask, 
                std::size_t(index_0));
        if (task->IsDetach())
        {
            TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
                "Task(%p) Detach", task);
            typedef test::sys::Task TaskType;
            task->~TaskType();
            free(task);
            return;
        }
        if (task->IsFailed() && !runner->IsStop())
        {
            runner->m_failed.store(true);
            TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
                "Task(%p) Failed", task);
            runner->PoolingLogBuffer(thread_hid, 
                task->GetBeginLoggingTimeStamp(),
                task->GetEndLoggingTimeStamp());
            runner->Stop();
        } 
        else if (task->GetBeginLoggingTimeStamp() != 0 ||
            task->GetEndLoggingTimeStamp() != 0)
        {
            runner->PoolingLogBuffer(thread_hid, 
                task->GetBeginLoggingTimeStamp(),
                task->GetEndLoggingTimeStamp());
        }
        task->Finalize();
        TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
            "Task(%p) Finish", task);
        runner->Clean(index_0);
        buffer->Reset();
    }

    TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
        "Thread Finish");

    runner->Finalize(index_0, request);
    runner->m_doneCount--;
}

template<typename TStatus, typename TBuffer, std::size_t N>
typename Runner<TStatus, TBuffer, N>::KeyType 
Runner<TStatus, TBuffer, N>::InitializeKey(std::thread::id main_id, 
    std::thread(&threads)[N], std::size_t(&index)[N + 1], 
    std::size_t(&hids)[N + 1])
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, NULL, 
        "InitializeKey()");

    const std::size_t* key_ref = IndexType::Get(); 
    constexpr std::size_t size = IndexType::ConstSize();
    constexpr std::size_t bg_key = IndexType::ConstGetBegin<N>();
    std::hash<std::thread::id> hash{};
    std::size_t list_thread_id_hash[N] {};
    std::size_t main_id_hash = hash(main_id);
    std::size_t reducer = main_id_hash;
    std::size_t divisor = 0;
    for (std::size_t i = 0; i < N; ++i)
    {
        list_thread_id_hash[i] = hash(threads[i].get_id());
        if (reducer > list_thread_id_hash[i])
        {
            reducer = list_thread_id_hash[i];
        }
    }
    for (std::size_t i = bg_key; i < size; ++i)
    {
        if (i >= size)
        {
            break;
        }
        bool next = false;
        divisor = key_ref[i];
        hids[0] = main_id_hash;
        index[0] = (main_id_hash - reducer) % key_ref[i];
        for (std::size_t j = 1; j <= N; ++j)
        {
            hids[j] = list_thread_id_hash[j - 1];
            index[j] = (list_thread_id_hash[j - 1] - reducer) % 
                key_ref[i];
            for (std::size_t k = 0; k < j; ++k)
            {
                if (index[k] == index[j])
                {
                    next = true;
                    break;
                }
            }
            if (next)
            {
                break;
            }
        }
        if (!next)
        {
            break;
        }
    }
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, NULL, 
        "{reducer=%zu, divisor=%zu}", reducer, divisor);
    return {reducer, divisor};
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    InitializeBuffer(BufferType**& buffer, std::size_t*& indexs,
        const KeyType& key, std::size_t(&index)[N + 1], StatusType& status)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, NULL, 
        "InitializeBuffer()");

    buffer = (BufferType**)malloc(sizeof(BufferType*) * key.Size());
    if (buffer != NULL)
    {
        memset(buffer, 0, sizeof(BufferType*) * key.Size());
    } 
    else
    {
        SystemType::GetInstance().
            Error(DefinitionType::Status::sRunnerAllocationFailed,
                "Buffer memory allocation failed");
        return;
    }
    indexs = (std::size_t*)malloc(sizeof(std::size_t) * key.Size());
    if (indexs != NULL)
    {
        memset(indexs, 255, sizeof(std::size_t) * key.Size());
    } 
    else
    {
        SystemType::GetInstance().
            Error(DefinitionType::Status::sRunnerAllocationFailed,
                "Indexs memory allocation failed");
        return;
    }
    for (std::size_t i = 0; i < (N + 1); ++i)
    {
        buffer[index[i]] = (BufferType*)malloc(sizeof(BufferType));
        indexs[index[i]] = i;
        if (buffer[index[i]] != NULL)
        {
            new(buffer[index[i]]) BufferType(status);
        }
        else
        {
            SystemType::GetInstance().
            Error(DefinitionType::Status::sRunnerAllocationFailed,
                "Buffer[%zu] memory allocation failed", i);
            return;
        }
    }
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    FinalizeBuffer(BufferType**& buffer, std::size_t*& indexs, 
        const KeyType& key, std::size_t(&index)[N + 1])
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, NULL, 
        "FinalizeBuffer()");

    for (std::size_t i = 0; i < (N + 1); ++i)
    {
        indexs[index[i]] = 0;
        if(buffer[index[i]] != NULL)
        {
            buffer[index[i]]->~BufferType();
            free(buffer[index[i]]);
            buffer[index[i]] = NULL;
        }   
    }

    free(indexs);
    indexs = NULL;
    free(buffer);
    buffer = NULL;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    BeginRunTask(Runner<TStatus, TBuffer, N>* runner, std::size_t&& index)
{
    runner->m_tasksRun[index % N].store(true);
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    EndRunTask(Runner<TStatus, TBuffer, N>* runner, std::size_t&& index)
{
    runner->m_tasksRun[index % N].store(false);
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::CallClear(void* ptr)
{
    const std::size_t hid = DefinitionType::GetThisThreadHID();
    static_cast<Runner<TStatus, TBuffer, N>*>(ptr)->ClearLogBuffer(hid);
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::CallIsStop(void* ptr)
{
    return static_cast<Runner<TStatus, TBuffer, N>*>(ptr)->IsStop();
}

template<typename TStatus, typename TBuffer, std::size_t N>
Runner<TStatus, TBuffer, N>::Runner(StatusType& status, LogType& log) :
    m_failed(false),
    m_start(false),
    m_stop(false),
    m_finish(false),
    m_status(status),
    m_log(log),
    m_idleCount(0),
    m_runCount(0),
    m_doneCount(0),
    m_beginTaskFmtCb(test::sys::Task::DefaultFormatBegin),
    m_endTaskFmtCb(test::sys::Task::DefaultFormatEnd),
    m_assertTaskFmtCb(test::sys::Task::DefaultFormatAssert),
    m_ref(this, CallClear, CallIsStop),
    m_threads{},
    m_queue{0},
    m_indexThreads{0},
    m_hidThreads{0},
    m_queueBegin(0), 
    m_queueEnd(0),
    m_queueLock(),
    m_tasksReady{},
    m_tasksRun{},
    m_tasks{},
    m_buffers{NULL},
    m_indexs{NULL}
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Constructor(status=%p)", &status);

    this->Initialize();
}

template<typename TStatus, typename TBuffer, std::size_t N>
Runner<TStatus, TBuffer, N>::~Runner()
{   
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Destructor");

    this->Finalize();
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Initialize()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 2, this, 
        "Initialize()");

    m_indexThreads[0] = 0;
    m_hidThreads[0] = 0;
    for (std::size_t i = 0; i < N; ++i)
    {
        m_indexThreads[i + 1] = 0;
        m_hidThreads[i + 1] = 0;
        m_threads[i] = std::thread(MainFunction, this, i + 1);
        m_tasksReady[i].store(false);
        m_tasksRun[i].store(false);
        m_tasks[i] = NULL;
        
        TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
            "Create Thread %zx", DefinitionType::
            GetThreadHID(m_threads[i].get_id()));
    }
    m_key = InitializeKey(std::this_thread::get_id(), m_threads, 
        m_indexThreads, m_hidThreads);
    InitializeBuffer(m_buffers, m_indexs, m_key, m_indexThreads, m_status);
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "Start");
    m_start = true;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Finalize()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Finalize()");

    if(m_finish.load())
    {
        return;
    }

    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, "Stop");
    m_stop.store(true);
    FinalizeBuffer(m_buffers, m_indexs, m_key, m_indexThreads);
    for (std::size_t i = 0; i < N; ++i)
    {
        TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
            "Join Thread %zx", DefinitionType::
            GetThreadHID(m_threads[i].get_id()));

        if (m_threads[i].joinable())
        {
            m_threads[i].join();
        }
        else
        {
            m_tasks[i]->Detach();
            m_tasks[i] = NULL;
            m_threads[i].detach();
            --m_doneCount;
        }
        if (m_tasks[i] != NULL)
        {
            typedef test::sys::Task TaskType;
            m_tasks[i]->~TaskType();
            free(m_tasks[i]);
            m_tasks[i] = NULL;
        }
    }
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, "Finish");
    m_finish = true;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    Finalize(const std::size_t& index, const bool& request)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Finalize(index=%zu, request=%d)", index, request);

    if (request)
    {
        --m_idleCount;
    }
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Clean(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "Clean(index=%zu)", index);

    m_tasksReady[index].store(false);
    if (m_tasks[index] == NULL)
    {
        return;
    }
    typedef test::sys::Task TaskType;
    m_tasks[index]->~TaskType();
    free(m_tasks[index]);
    m_tasks[index] = NULL;
    --m_runCount;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Request(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "Request(index=%zu)", index);

    std::lock_guard<std::mutex> guard{m_queueLock};
    m_tasksReady[index].store(false);
    const std::size_t last = m_queueEnd;
    m_queue[last] = index;
    m_queueEnd = ((last + 1) % (N + 1));
    ++m_idleCount;
}

template<typename TStatus, typename TBuffer, std::size_t N>
test::sys::Task* Runner<TStatus, TBuffer, N>::
    GetRequest(const std::size_t& index)
{
    if (m_tasksReady[index].load())
    {    
        TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
            "GetRequest(index=%zu)", index);

        ++m_runCount;
        --m_idleCount;
        return m_tasks[index];
    }
    return NULL;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    PoolingLogBuffer(const std::size_t& thread_hid, TimestampType begin,
        TimestampType end)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "PoolingLogBuffer(thread_hid=%zu, begin=%zu, end=%zu)", 
            thread_hid, begin ,end);
    if (m_buffers == NULL)
    {
        return;
    }
    const std::size_t main_thread_hid = DefinitionType::GetMainThreadHID();
    const std::size_t main_thread_index = m_key.Index(main_thread_hid);
    const std::size_t thread_index = m_key.Index(thread_hid);
    BufferType* main_thread_buffer = m_buffers[main_thread_index];
    BufferType* thread_buffer = m_buffers[thread_index];
    std::size_t main_size = main_thread_buffer == NULL ? 0 :
        main_thread_buffer->Size();
    std::size_t thread_size = thread_buffer == NULL ? 0 :
        thread_buffer->Size();
    std::size_t mi = 0;
    std::size_t ti = 0;

    typedef TimestampType TmType;
    typedef bool (*LogCondFuncType)(const TmType&, const TmType&, 
        const TmType&);
    LogCondFuncType log_cond = [](const TmType&, const TmType&, const TmType&) 
    {
        return true;   
    };
    if (begin != 0 && end == 0)
    {
        log_cond = [](const TmType& tm, const TmType& bg, const TmType&) 
        {
            return tm >= bg;   
        };
    } 
    else if (begin == 0 && end != 0)
    {
        log_cond = [](const TmType& tm, const TmType& bg, const TmType& ed) 
        {
            return tm <= ed; 
        };
    }
    else if (begin != 0 && end != 0)
    {
        log_cond = [](const TmType& tm, const TmType& bg, const TmType& ed) 
        {
            return tm >= bg && tm <= ed; 
        };
    }
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "main_size %zu thread_size %zu", main_size, thread_size);
    if (main_size != 0 && thread_size != 0)
    {
        for (;main_size != 0 && thread_size != 0;)
        {
            const TimestampType main_tm = 
                (*main_thread_buffer)[mi].GetTimestamp();
            const TimestampType thread_tm = 
                (*thread_buffer)[ti].GetTimestamp();
            if(main_tm < thread_tm)
            {
                if (log_cond(main_tm, begin, end))
                    m_log.Output("%s", 
                        (*main_thread_buffer)[mi].GetMessage());
                --main_size;
                ++mi;
            }
            else
            {
                if (log_cond(thread_tm, begin, end))
                    m_log.Output("%s", 
                        (*thread_buffer)[ti].GetMessage());
                --thread_size;
                ++ti;
            }
        }
    }
    if (main_size != 0)
    {
        for (;mi < main_size; ++mi)
        {
            const TimestampType main_tm = 
                (*main_thread_buffer)[mi].GetTimestamp();
            if (log_cond(main_tm, begin, end))
                m_log.Output("%s", (*main_thread_buffer)[mi].GetMessage());
        }
    }
    if (thread_size != 0)
    {
        for (;ti < thread_size; ++ti)
        {
            const TimestampType thread_tm = 
                (*thread_buffer)[ti].GetTimestamp();

            if (log_cond(thread_tm, begin, end))
                m_log.Output("%s", (*thread_buffer)[ti].GetMessage());
        }
    }

    if (main_thread_buffer != NULL)
    {
        main_thread_buffer->Reset();
    }
    if (thread_buffer != NULL)
    {
        thread_buffer->Reset();
    }
}

template<typename TStatus, typename TBuffer, std::size_t N>
std::size_t Runner<TStatus, TBuffer, N>::QueueSize() const
{
    const std::size_t bg = m_queueBegin;
    const std::size_t ed = m_queueEnd; 
    return (bg <= ed ? ed - bg: (ed + (N + 1)) - bg);
}


template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    SetBeginTaskFormatCallback(FormatTaskBeginCallbackFunc func)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 4, this, 
        "SetBeginTaskFormatCallback(func=%p)", func);

    m_beginTaskFmtCb = func;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    SetEndTaskFormatCallback(FormatTaskEndCallbackFunc func)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 4, this, 
        "SetEndTaskFormatCallback(func=%p)", func);
    
    m_endTaskFmtCb = func;
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::
    SetAssertTaskFormatCallback(FormatTaskAssertCallbackFunc func)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 4, this, 
        "SetAssertTaskFormatCallback(func=%p)", func);
    
    m_assertTaskFmtCb = func;
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::
    LogBufferOutput(const std::size_t& thread_hid, const char* msg)
{
    const std::size_t thread_index = m_key.Index(thread_hid);
    BufferType* thread_buffer = m_buffers[thread_index];
    const std::size_t index = m_indexs[thread_index];
    if (thread_buffer == NULL)
    {
        return false;
    }
    const std::size_t hid = m_hidThreads[index % (N + 1)];
    if (hid != thread_hid)
    {
        return false;
    }
    thread_buffer->Output("%s", msg);
    return true;
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::
    ClearLogBuffer(const std::size_t& thread_hid)
{
    const std::size_t thread_index = m_key.Index(thread_hid);
    BufferType* thread_buffer = m_buffers[thread_index];
    const std::size_t index = m_indexs[thread_index];
    if (thread_buffer == NULL)
    {
        return false;
    }
    const std::size_t hid = m_hidThreads[index % (N + 1)];
    if (hid != thread_hid)
    {
        return false;
    }
    thread_buffer->Reset();
    return true;
}

template<typename TStatus, typename TBuffer, std::size_t N>
std::size_t Runner<TStatus, TBuffer, N>::
    GetThreadIndex(const std::size_t& thread_hid)
{
    const std::size_t thread_index = m_key.Index(thread_hid);
    const std::size_t index = m_indexs[thread_index];
    const std::size_t hid = m_hidThreads[index % (N + 1)];
    if (hid != thread_hid)
    {
        return N + 1;
    }
    return m_indexs[thread_index];
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Job(test::sys::Task&& task)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 2, this, 
        "Job(task=%p, name=%s)", &task, task.GetName());
    if (IsStop())
    {
        TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
            "Job(task=%p, name=%s) Skip", &task, task.GetName());
        return;
    }
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "Job(task=%p, name=%s) Wait", &task, task.GetName());
    do
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } 
    while(QueueSize() == 0 && !IsStop());
    
    if (IsStop())
    {
        TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
            "Job(task=%p, name=%s) Skip", &task, task.GetName());
        return;
    }
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "Job(task=%p, name=%s)", &task, task.GetName());

    const std::size_t bg = m_queueBegin;
    const std::size_t index = m_queue[bg];
    m_tasks[index] = (test::sys::Task*) malloc(sizeof(test::sys::Task));
    if (m_tasks[index] == NULL)
    {
        SystemType::GetInstance().
        Error(DefinitionType::Status::sRunnerAllocationFailed,
            "task[%zu] memory allocation failed", index);
        return;
    }
    new(m_tasks[index]) test::sys::Task(std::move(task));

    m_tasks[index]->SetBeginFormatCallback(m_beginTaskFmtCb);
    m_tasks[index]->SetEndFormatCallback(m_endTaskFmtCb);
    m_tasks[index]->SetAssertFormatCallback(m_assertTaskFmtCb);
    m_tasks[index]->SetReference(m_ref);
    m_queueBegin = (bg + 1) % (N + 1);
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 4, this, 
        "New Task = %p", m_tasks[index]);

    m_tasksReady[index].store(true);
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Stop()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, "Stop()");

    return m_stop.store(true);
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::Detach()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, "Detach()");

    Stop();

    if (m_finish.load()) 
    {
        return;
    }
    for (std::size_t i = 0; i < N; ++i)
    {
        m_tasks[i]->Detach();
        m_tasks[i] = NULL;
        m_threads[i].detach();
        --m_doneCount;
    }
    m_finish.store(true);
}

template<typename TStatus, typename TBuffer, std::size_t N>
void Runner<TStatus, TBuffer, N>::WaitAndStop()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "WaitAndStop()");
    if (m_finish.load())
    {
        return;
    }
    
    TEST_SYS_DEBUG(SystemType, _DebugType, 2, this, 
        "Wait runCount %zu runner_queueSize %zu idleCount %zu",
        m_runCount.load(), QueueSize(), m_idleCount.load());
    do
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } 
    while((m_runCount.load() != 0 ? QueueSize() != N : false) || 
        (m_idleCount.load() != 0 ? m_idleCount.load() != N : false));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    Stop();
}

template<typename TStatus, typename TBuffer, std::size_t N>
std::size_t Runner<TStatus, TBuffer, N>::IdleCount() const
{
    return m_idleCount.load();
}

template<typename TStatus, typename TBuffer, std::size_t N>
std::size_t Runner<TStatus, TBuffer, N>::RunCount() const
{
    return m_runCount.load();
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::IsStart() const
{
    return m_start.load();
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::IsStop() const
{
    return m_stop.load();
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::IsFinish() const
{
    return m_finish.load();
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::IsDone() const
{
    return m_doneCount.load() == 0;
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::IsFailed() const
{
    return m_failed.load();
}

template<typename TStatus, typename TBuffer, std::size_t N>
bool Runner<TStatus, TBuffer, N>::
    IsRun(const std::size_t& thread_hid)
{
    const std::size_t thread_index = m_key.Index(thread_hid);
    const std::size_t index = m_indexs[thread_index];
    const std::size_t hid = m_hidThreads[index % (N + 1)];
    if (hid != thread_hid)
    {
        return false;
    }
    return m_tasksRun[(index - 1) % N].load();
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::
    BeginRunTask(Runner<TStatus, TBuffer, 0>* runner)
{
    runner->m_run = true;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::
    EndRunTask(Runner<TStatus, TBuffer, 0>* runner)
{
    runner->m_run = false;
}

template<typename TStatus, typename TBuffer>
Runner<TStatus, TBuffer, 0>::Runner(StatusType& status, LogType& log) :
    m_run(false),
    m_failed(false),
    m_stop(false),
    m_status(status),
    m_log(log),
    m_buffer(status),
    m_beginTaskFmtCb(test::sys::Task::DefaultFormatBegin),
    m_endTaskFmtCb(test::sys::Task::DefaultFormatEnd),
    m_assertTaskFmtCb(test::sys::Task::DefaultFormatAssert)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Constructor(status=%p)", &status);
}

template<typename TStatus, typename TBuffer>
Runner<TStatus, TBuffer, 0>::~Runner()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Destructor");
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Initialize()
{}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Finalize()
{}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Finalize(const std::size_t&, const bool&)
{}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Clear(const std::size_t&)
{}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Request(const std::size_t&)
{}

template<typename TStatus, typename TBuffer>
test::sys::Task* Runner<TStatus, TBuffer, 0>::GetRequest(const std::size_t&)
{
    return NULL;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::
    PoolingLogBuffer(TimestampType begin, TimestampType end)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
        "PoolingLogBuffer(begin=%zu, end=%zu)", begin ,end);

    typedef TimestampType TmType;
    typedef bool (*LogCondFuncType)(const TmType&, const TmType&, 
        const TmType&);
    LogCondFuncType log_cond = [](const TmType&, const TmType&, const TmType&) 
    {
        return true;   
    };
    if (begin != 0 && end == 0)
    {
        log_cond = [](const TmType& tm, const TmType& bg, const TmType&) 
        {
            return tm >= bg;   
        };
    } 
    else if (begin == 0 && end != 0)
    {
        log_cond = [](const TmType& tm, const TmType& bg, const TmType& ed) 
        {
            return tm <= ed; 
        };
    }
    else if (begin != 0 && end != 0)
    {
        log_cond = [](const TmType& tm, const TmType& bg, const TmType& ed) 
        {
            return tm >= bg && tm <= ed; 
        };
    }
    
    for (std::size_t i = 0;i < m_buffer.Size(); ++i)
    {
        const TimestampType thread_tm = m_buffer[i].GetTimestamp();
        if (log_cond(thread_tm, begin, end))
            m_log.Output("%s", m_buffer[i].GetMessage());
    }

    m_buffer.Reset();
}

template<typename TStatus, typename TBuffer>
std::size_t Runner<TStatus, TBuffer, 0>::QueueSize() const
{
    return 0;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::LogBufferOutput(const std::size_t&, 
    const char* msg)
{
    m_buffer.Output("%s", msg);
    return true;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::ClearLogBuffer(const std::size_t&)
{
    return m_buffer.Reset();
}

template<typename TStatus, typename TBuffer>
std::size_t Runner<TStatus, TBuffer, 0>::
    GetThreadIndex(const std::size_t&)
{
    return 0;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::
    SetBeginTaskFormatCallback(FormatTaskBeginCallbackFunc func)
{
    m_beginTaskFmtCb = func;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::
    SetEndTaskFormatCallback(FormatTaskEndCallbackFunc func)
{
    m_endTaskFmtCb = func;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::
    SetAssertTaskFormatCallback(FormatTaskAssertCallbackFunc func)
{
    m_assertTaskFmtCb = func;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Job(test::sys::Task&& task)
{
    if (!m_stop)
    {
        TEST_SYS_DEBUG(SystemType, _DebugType, 3, this, 
            "Job(task=%p)", &task);

        task.Initialize(std::this_thread::get_id(), 0);
        task.SetBeginFormatCallback(m_beginTaskFmtCb);
        task.SetEndFormatCallback(m_endTaskFmtCb);
        task.SetAssertFormatCallback(m_assertTaskFmtCb);
        task.template Run<Runner<TStatus, TBuffer, 0>>(this, 
            Runner<TStatus, TBuffer, 0>::BeginRunTask,
            Runner<TStatus, TBuffer, 0>::EndRunTask);
        if (task.IsFailed() && !IsStop())
        {
            m_failed = true;
            TEST_SYS_DEBUG(SystemType, _DebugType, 4, NULL, 
                "Task(%p) Failed", &task);
            PoolingLogBuffer(task.GetBeginLoggingTimeStamp(),
                task.GetEndLoggingTimeStamp());
            Stop();
        }
        else if (task.GetBeginLoggingTimeStamp() != 0 ||
            task.GetEndLoggingTimeStamp() != 0)
        {
            PoolingLogBuffer(task.GetBeginLoggingTimeStamp(),
                task.GetEndLoggingTimeStamp());
        }
        m_buffer.Reset();
        task.Finalize();
    }
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Stop()
{
    m_stop = true;
}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::Detach()
{}

template<typename TStatus, typename TBuffer>
void Runner<TStatus, TBuffer, 0>::WaitAndStop()
{
    Stop();
}

template<typename TStatus, typename TBuffer>
std::size_t Runner<TStatus, TBuffer, 0>::IdleCount() const
{
    return m_run ? 0 : 1;
}

template<typename TStatus, typename TBuffer>
std::size_t Runner<TStatus, TBuffer, 0>::RunCount() const
{
    return m_run ? 1 : 0;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::IsStart() const
{
    return true;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::IsStop() const
{
    return m_stop;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::IsFinish() const
{
    return !m_run;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::IsDone() const
{
    return !m_run;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::IsFailed() const
{
    return m_failed;
}

template<typename TStatus, typename TBuffer>
bool Runner<TStatus, TBuffer, 0>::IsRun(const std::size_t&)
{
    return m_run;
}

} //!sys

} //!test


#endif //!TEST_SYS_RUNNER_H_
