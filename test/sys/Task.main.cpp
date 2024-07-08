#define TEST_SYS_DEBUG_ENABLE 1
#define TEST_SYS_TASK_DLEVEL 0x7f
#include "test/sys/Task.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

// #undef __STDCPP_THREADS__
// #define __STDCPP_THREADS__ 0

#if __STDCPP_THREADS__ > 0
#define NTHREAD 16
#else
#define NTHREAD 1
#endif

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cassert>

template<std::size_t N>
struct Runner
{
    std::size_t queue[N + 1];
    std::size_t begin, end;
    std::size_t jobCount[N];
    std::atomic_bool done;
    test::sys::Task* task[N];
    std::atomic_bool taskReady[N];
    std::atomic_int idleSize;
    std::mutex lock;
    Runner() :
        queue{},
        begin(0),
        end(0),
        done(false),
        task{},
        taskReady{},
        idleSize{0},
        lock{}
    {}
    std::size_t QueueSize() const
    {
        const std::size_t bg = begin;
        const std::size_t ed = end; 
        return (bg <= ed ? ed - bg: (ed + (N + 1)) - bg);
    }
    test::sys::Task* GetRequest(std::size_t index) const
    {
        if (taskReady[index].load())
        {
            auto* t = const_cast<Runner<NTHREAD>*>(this);
            --(t->idleSize);
            (t->jobCount[index])++;
            return task[index];
        }
        return NULL;
    }
    void Stop()
    {
        done.store(true);
    }
    void Request(std::size_t index)
    {
#if __STDCPP_THREADS__ > 0
        std::lock_guard<std::mutex> guard{lock};
        taskReady[index].store(false);
        const std::size_t last = end;
        queue[last] = index;
        end = ((last + 1) % (N + 1));
        ++idleSize;

#else

#endif
    }
    void Finalize(std::size_t index)
    {
        if (task[index] == NULL)
        {
            return;
        }
        task[index]->Finalize();
        delete task[index];
        task[index] = NULL;
    }
    void Job(test::sys::Task&& new_task)
    {
#if __STDCPP_THREADS__ > 0
        do
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } 
        while(QueueSize() == 0);
        const std::size_t bg = begin;
        const std::size_t index = queue[bg];
        task[index] = new test::sys::Task(std::move(new_task));
        begin = (bg + 1) % (N + 1);
        taskReady[index].store(true);
#else

        TEST_SYS_INFO("run task in thread-id %llu", std::this_thread::get_id());
        new_task.Initialize(std::this_thread::get_id());
        new_task.Run();
        new_task.Finalize();
#endif
    }
    std::size_t GetIdleSize() const
    {
        return idleSize.load();
    }
};

Runner<NTHREAD> runner;

void MainThread(void* obj, std::size_t index)
{
    Runner<NTHREAD>* runner_obj = (Runner<NTHREAD>*)(obj);
    while(runner_obj != NULL && !runner_obj->done.load())
    {
        runner_obj->Request(index);
        test::sys::Task* task;
        while((task = runner_obj->GetRequest(index)) == NULL
            && !runner_obj->done.load()) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if (runner_obj->done.load())
        {
            runner_obj->Finalize(index);
            break;
        }
        TEST_SYS_INFO("run task in thread-id %llu", std::this_thread::get_id());
        task->Initialize(std::this_thread::get_id(), index);
        task->Run();
        runner_obj->Finalize(index);
        task = NULL;
    }
    TEST_SYS_INFO("finish, total job %zu thread-id %llu", runner_obj->jobCount[index], 
        std::this_thread::get_id());
}

std::atomic_size_t n_task{0};

int main()
{
    std::srand(std::time(nullptr));
#if __STDCPP_THREADS__ > 0
    std::size_t main_hash = std::hash<std::thread::id>{}(std::this_thread::get_id());
    std::size_t or_hash = main_hash;
    std::size_t and_hash = main_hash;
    TEST_SYS_INFO("hash Thread Id %zu %zu", main_hash,
        std::hash<std::thread::id>{}(std::this_thread::get_id()));
    std::thread th[NTHREAD];
    std::size_t check[NTHREAD + 1];
    constexpr std::size_t key = 1021;
    check[0] = main_hash % key;
    std::size_t same = 0;
    for (std::size_t i = 0; i < NTHREAD; ++i)
    {
        runner.jobCount[i] = 0;
        th[i] = std::thread{MainThread, &runner, i};
        TEST_SYS_INFO("hash Thread Id %zu %zu %zu", main_hash - std::hash<std::thread::id>{}(th[i].get_id()),
            std::hash<std::thread::id>{}(th[i].get_id()),
            std::hash<std::thread::id>{}(th[i].get_id()) % 1021);
        or_hash |= std::hash<std::thread::id>{}(th[i].get_id());
        and_hash &= std::hash<std::thread::id>{}(th[i].get_id());
        const std::size_t ck = std::hash<std::thread::id>{}(th[i].get_id()) % key;
        check[i+1] = ck;
        for (std::size_t j = 0; j < (i + 1); ++j)
        {
            if (check[j] == ck)
            {
                ++same;
                break;
            }
        }
    }
#else
#endif
    {
        for (std::size_t i = 0; i < 1000; ++i)
        {
            test::sys::Task t{"test"};
            t.Main([](test::sys::Task& task){
                TEST_SYS_INFO("run task %zu in thread-id %llu", n_task++,
                    std::this_thread::get_id());
                const auto random = (std::rand() % 900) + 100;
                std::this_thread::sleep_for(std::chrono::milliseconds(random));
            });
            runner.Job(std::move(t));
        }
    }
#if __STDCPP_THREADS__ > 0
    do
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));        
    } 
    while(runner.GetIdleSize() != NTHREAD);
    runner.Stop();
    for (std::size_t i = 0; i < NTHREAD; ++i)
    {
        th[i].join();
    }
#endif
    TEST_SYS_INFO("total task = %zu", n_task.load());
    assert(n_task.load() == 1000);
    return 0;
}
