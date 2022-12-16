#ifndef TEST_SYS_SIGNALS_H_DEFN_
#define TEST_SYS_SIGNALS_H_DEFN_

#include "Signal.defn.h"
#include "Definition.h"
#include "Interface.h"
#include "Debug.h"

#include <cstddef>
#include <mutex>
#include <chrono>

namespace test::sys
{
template<typename TStatus>
class Signals;
}

#ifndef TEST_SYS_SIGNALS_DLEVEL

#define TEST_SYS_SIGNALS_DLEVEL 2

#endif //!TEST_SYS_SIGNALS_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>

template<typename TStatus>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_SIGNALS_DLEVEL, 
    "test::sys::Signals", 
    test::sys::Signals<TStatus>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace sys
{

template<typename TStatus>
class Signals
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Signals<TStatus>> DebugType;
public:
    typedef TStatus StatusType;
    typedef typename test::sys::Definition::TimestampType TimestampType;
    typedef test::sys::Signal SignalType;
private:
    int m_lastSig;
    std::size_t m_size;
    std::size_t m_alloc;
    SignalType** m_list;
    StatusType& m_status;
    std::mutex m_mutex;
public:
    Signals(StatusType& status);
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
