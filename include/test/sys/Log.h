#ifndef TEST_SYS_LOG_H_
#define TEST_SYS_LOG_H_

#include "out/Interface.h"
#include "Definition.h"
#include "Interface.h"
#include "Debug.h"

#include <cstdio>
#include <mutex>
#include <cstdarg>
#include <chrono>

namespace test
{
namespace sys
{

template<typename TStatus>
class Log;

} //!sys

} //!test

#ifndef TEST_SYS_LOG_DLEVEL

#define TEST_SYS_LOG_DLEVEL 2

#endif //!TEST_SYS_LOG_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TStatus>

template<typename TStatus>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_LOG_DLEVEL, 
    "test::sys::Log", 
    test::sys::Log<TStatus>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace sys
{

template<typename TStatus>
class Log : public test::sys::out::Interface<TStatus>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Log<TStatus>> _DebugType;
public:
    typedef TStatus StatusType;
    typedef typename test::sys::Definition::Status StatusEnumType;
    typedef typename test::sys::Definition::StatusIntegerType StatusIntegerType;
    typedef test::sys::Debug DebugType;
public:
    typedef typename test::sys::out::Interface<TStatus>::
        FormatDebugCallbackFunc FormatDebugCallbackFunc;
public:
    typedef typename test::sys::out::Interface<TStatus>::
        FormatCallbackFunc FormatCallbackFunc;
private:
    FILE* m_file;
public:
    Log(StatusType& status);
public:
    Log(const Log&) = delete;
    Log(Log&&) = delete;
public:
    virtual ~Log();
public:
    Log& operator=(const Log& cpy) = delete;
    Log& operator=(Log&& mov) = delete;
public:
    void SetFileOutput(FILE* fout);
protected:
    virtual int BufferOutput(char * buffer);
};

template<typename TStatus>
Log<TStatus>::Log(StatusType& status) :
    test::sys::out::Interface<TStatus>(status),
    m_file(NULL)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "Constructor(status=%p)", status);

}

template<typename TStatus>
Log<TStatus>::~Log()
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, "Destructor");
    
}

template<typename TStatus>
void Log<TStatus>::SetFileOutput(FILE* fout)
{
    TEST_SYS_DEBUG(SystemType, _DebugType, 1, this, 
        "SetFileOutput(fout=%p)", fout);
    
    if (fout == stdout)
    {
        m_file = NULL;
    }
    else
    {
        m_file = fout;
    }
}

template<typename TStatus>
int Log<TStatus>::BufferOutput(char * buffer)
{
    int res = 0;
    if(m_file == NULL)
    {
        res = fprintf(stdout, "%s\n", buffer);
    }
    else
    {
        res = fprintf(m_file, "%s\n", buffer);
    }
    return res;
}

} //!sys

} //!test

#endif //!TEST_SYS_LOG_H_
