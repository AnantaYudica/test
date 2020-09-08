#ifndef TEST_OUT_BASE_TASK_BASE_INTERFACE_H_
#define TEST_OUT_BASE_TASK_BASE_INTERFACE_H_

#include "../../../../Guard.h"

#include <utility>

namespace test
{
namespace out
{
namespace base
{
namespace task
{
namespace base
{

template<typename TStatus>
class Interface 
{
public:
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
    Interface(Interface<TStatus>&& mov);
public:
    Interface<TStatus>& operator=(const Interface<TStatus>&) = delete;
    Interface<TStatus>& operator=(Interface<TStatus>&&) = delete;
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
protected:
    virtual test::Guard<test::out::base::task::base::Interface<TStatus>>
        ExecuteGuard() = 0;
    virtual test::Guard<test::out::base::task::base::Interface<TStatus>>
        AssignGuard() = 0;
    virtual test::Guard<test::out::base::task::base::Interface<TStatus>>
        ReleaseGuard() = 0;
    virtual test::Guard<test::out::base::task::base::Interface<TStatus>>
        BufferGuard() = 0;
protected:
    StatusType& GetStatus();
    StatusType GetStatus() const;
};

template<typename TStatus>
Interface<TStatus>::Interface() :
    m_status()
{}

template<typename TStatus>
template<typename... TArgs>
Interface<TStatus>::Interface(TArgs &&... args) :
    m_status(std::forward<TArgs>(args)...)
{}

template<typename TStatus>
Interface<TStatus>::~Interface()
{}

template<typename TStatus>
Interface<TStatus>::Interface(Interface<TStatus>&& mov) :
    m_status(std::move(mov.m_status))
{}

template<typename TStatus>
typename Interface<TStatus>::StatusType& 
Interface<TStatus>::GetStatus()
{
    return m_status;
}

template<typename TStatus>
typename Interface<TStatus>::StatusType 
Interface<TStatus>::GetStatus() const
{
    return {m_status};
}

} //!base

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_BASE_INTERFACE_H_
