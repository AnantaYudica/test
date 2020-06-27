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
protected:
    inline Interface() = default;
public:
    virtual ~Interface() = default;
public:
    Interface(const Interface<TStatus> &) = delete;
    Interface(Interface<TStatus> &&) = delete;
public:
    Interface<TStatus>& operator=(const Interface<TStatus>&) = delete;
    Interface& operator=(Interface<TStatus>&&) = delete;
protected:
    virtual TStatus& GetStatus() = 0;
    virtual TStatus GetStatus() const = 0;
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

} //!base

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_BASE_INTERFACE_H_