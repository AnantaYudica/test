#ifndef TEST_OUT_FILE_BASE_INTERFACE_H_
#define TEST_OUT_FILE_BASE_INTERFACE_H_

#include "../../../Guard.h"

namespace test
{
namespace out
{
namespace file
{
namespace base
{

template<typename TStatus>
class Interface
{
private:
    TStatus m_status;
protected:
    Interface();
    template<typename... TArgs>
    Interface(TArgs &&... args);
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<TStatus> &) = delete;
    Interface(Interface<TStatus> &&) = delete;
public:
    Interface<TStatus>& operator=(const Interface<TStatus>&) = delete;
    Interface<TStatus>& operator=(Interface<TStatus>&&) = delete;
protected:
    TStatus& GetStatus();
    TStatus GetStatus() const;
public:
    virtual bool _BeginPrint() = 0;
    virtual void _EndPrint() = 0;
public:
    virtual bool _BeginPuts() = 0;
    virtual void _EndPuts() = 0;
public:
    virtual bool _BeginLastOutput() = 0;
    virtual void _EndLastOutput() = 0;
protected:
    virtual test::Guard<Interface<TStatus>> PrintGuard() = 0;
    virtual test::Guard<Interface<TStatus>> PutsGuard() = 0;
    virtual test::Guard<Interface<TStatus>> LastOutputGuard() = 0;
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

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_BASE_INTERFACE_H_