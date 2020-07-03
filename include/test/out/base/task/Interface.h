#ifndef TEST_OUT_BASE_TASK_INTERFACE_H_
#define TEST_OUT_BASE_TASK_INTERFACE_H_

#include "../../CString.h"
#include "../../../Guard.h"
#include "Buffer.h"

#include <utility>
#include <cstdint>

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TChar, typename TStatus>
class Interface
{
public:
    typedef TStatus StatusType;
    typedef test::out::base::task::Buffer<TChar,
        test::out::base::task::Interface<TChar, TStatus>> BufferType;
private:
    StatusType m_status;
protected:
    Interface();
    template<typename... TArgs>
    Interface(TArgs&&... args);
public:
    virtual ~Interface();
public:
    Interface(const Interface<TChar, TStatus>&) = delete;
    Interface(Interface<TChar, TStatus>&& mov);
public:
    Interface<TChar, TStatus>& 
        operator=(const Interface<TChar, TStatus>&) = delete;
    Interface<TChar, TStatus>& 
        operator=(Interface<TChar, TStatus>&&) = delete;
public:
    virtual bool _BeginExecute() = 0;
    virtual void _EndExecute() = 0;
public:
    virtual bool _BeginAssign() = 0;
    virtual void _EndAssign() = 0;
public:
    virtual bool _BeginRelease() = 0;
    virtual void _EndRelease() = 0;
public:
    virtual bool _BeginBuffer() = 0;
    virtual void _EndBuffer() = 0;
public:
    virtual bool Execute(test::out::Interface& out) = 0;
public:
    virtual bool Assign(const std::intptr_t& deleg_id) = 0;
public:
    virtual bool Release(const std::intptr_t& deleg_id) = 0;
public:
    virtual BufferType Buffer(const std::intptr_t& deleg_id) = 0;
public:
    virtual test::Guard<test::out::base::task::Interface<TChar, TStatus>>
        ExecuteGuard() = 0;
    virtual test::Guard<test::out::base::task::Interface<TChar, TStatus>>
        AssignGuard() = 0;
    virtual test::Guard<test::out::base::task::Interface<TChar, TStatus>>
        ReleaseGuard() = 0;
    virtual test::Guard<test::out::base::task::Interface<TChar, TStatus>>
        BufferGuard() = 0;
public:
    StatusType& GetStatus();
    StatusType GetStatus() const;
};

template<typename TChar, typename TStatus>
Interface<TChar, TStatus>::Interface() :
    m_status()
{}

template<typename TChar, typename TStatus>
template<typename... TArgs>
Interface<TChar, TStatus>::Interface(TArgs&&... args) :
    m_status(std::forward<TArgs>(args)...)
{}

template<typename TChar, typename TStatus>
Interface<TChar, TStatus>::~Interface()
{}

template<typename TChar, typename TStatus>
Interface<TChar, TStatus>::Interface(Interface<TChar, TStatus>&& mov) :
    m_status(std::move(mov.m_status))
{}

template<typename TChar, typename TStatus>
typename Interface<TChar, TStatus>::StatusType& 
Interface<TChar, TStatus>::GetStatus()
{
    return m_status;
}

template<typename TChar, typename TStatus>
typename Interface<TChar, TStatus>::StatusType 
Interface<TChar, TStatus>::GetStatus() const
{
    return {m_status};
}

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_INTERFACE_H_
