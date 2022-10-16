#ifndef TEST_SYS_SIGNALS_H_DEFN_
#define TEST_SYS_SIGNALS_H_DEFN_

#include "Signal.defn.h"
#include "Definition.h"
#include "Log.h"

#include <cstddef>
#include <mutex>
#include <chrono>

namespace test
{
namespace sys
{

template<typename TStatus>
class Signals
{
public:
    typedef TStatus StatusType;
    typedef typename test::sys::Definition::TimestampType TimestampType;
public:
    typedef test::sys::Log<TStatus> LogType;
    typedef test::sys::Signal SignalType;
private:
    int m_lastSig;
    std::size_t m_size;
    std::size_t m_alloc;
    SignalType** m_list;
    StatusType& m_status;
    LogType& m_log;
    std::mutex m_mutex;
public:
    Signals(StatusType& status, LogType& log);
public:
    Signals(const Signals&) = delete;
    Signals(Signals&&) = delete;
public:
    ~Signals();
private:
    void Allocation();
private:
    bool Reallocation();
public:
    bool Insert(SignalType* sig);
public:
    bool Remove(SignalType* sig);
public:
    void Clear();
public:
    std::size_t Size() const;
public:
    void Raise(int sig);
};

} //!sys

} //!test

#endif //!TEST_SYS_SIGNALS_H_DEFN_
