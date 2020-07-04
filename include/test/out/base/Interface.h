#ifndef TEST_OUT_BASE_INTERFACE_H_
#define TEST_OUT_BASE_INTERFACE_H_

#include "../../CString.h"
#include "../../Guard.h"

#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <utility>

#ifndef __ATTRIBUTE__
#ifdef __GNUC__
#define __ATTRIBUTE__(...) __attribute__(__VA_ARGS__)
#else
#define __ATTRIBUTE__(...)
#endif
#endif //!__ATTRIBUTE__

namespace test
{
namespace out
{
namespace base
{

template<typename TStatus>
class Interface
{
public:
    typedef std::size_t SizeType;
    typedef TStatus StatusType;
private:
    StatusType m_status;
protected:
    Interface();
    template<typename... TArgs>
    Interface(TArgs&&... args);
public:
    virtual ~Interface();
public:
    Interface(const Interface<TStatus>&) = delete;
    Interface(Interface<TStatus>&&) = delete;
public:
    Interface<TStatus>& operator=(const Interface<TStatus>&) = delete;
    Interface<TStatus>& operator=(Interface<TStatus>&&) = delete;
public:
    virtual bool Finalize(const std::intptr_t& id) = 0;
public:
    virtual bool _BeginRequestTask() = 0;
    virtual void _EndRequestTask() = 0;
public:
    virtual bool _BeginExecuteTask() = 0;
    virtual void _EndExecuteTask() = 0;
protected:
    virtual test::Guard<Interface<TStatus>> RequestTaskGuard() = 0;
    virtual test::Guard<Interface<TStatus>> ExecuteTaskGuard() = 0;
protected:
    virtual bool ExecuteTask(const std::intptr_t& id) = 0;
public:
    TStatus& GetStatus();
    TStatus GetStatus() const;
};

template<typename TStatus>
Interface<TStatus>::Interface() :
    m_status()
{}

template<typename TStatus>
template<typename... TArgs>
Interface<TStatus>::Interface(TArgs&&... args) :
    m_status(std::forward<TArgs>(args)...)
{}

template<typename TStatus>
Interface<TStatus>::~Interface()
{}

template<typename TStatus>
TStatus& Interface<TStatus>::GetStatus()
{
    return m_status;
}

template<typename TStatus>
TStatus Interface<TStatus>::GetStatus() const
{
    return {m_status};
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_INTERFACE_H_
