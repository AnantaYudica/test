#ifndef TEST_SYS_STATUS_H_
#define TEST_SYS_STATUS_H_

#include "Definition.h"

#include <cstdlib>
#include <utility>
#include <cstdint>
#include <atomic>

namespace test
{
namespace sys
{

class Status
{
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
    typedef typename test::sys::Definition::StatusIntegerType 
        StatusIntegerType;
    typedef typename test::sys::Definition::Status StatusEnumType;
    typedef std::atomic<StatusIntegerType> StatusType;
private:
    StatusType m_stat;
    int m_signal;
    TimestampType m_start;
    TimestampType m_end;
    TimestampType m_terminate;
    TimestampType m_timestamp;
public:
    inline Status();
public:
    inline Status(const Status& cpy) = delete;
    inline Status(Status&& mov) = delete;
public:
    inline Status& operator=(const Status& cpy) = delete;
    inline Status& operator=(Status&& mov) = delete;
public:
    inline void Start();
public:
    inline TimestampType GetStartTimestamp() const;
public:
    inline void End();
public:
    inline TimestampType GetEndTimestamp() const;
public:
    inline void Error(StatusEnumType code);
    inline void Error(StatusIntegerType code);
public:
    inline const char* GetErrorName() const;
public:
    inline StatusIntegerType GetErrorCode() const;
public:
    inline TimestampType GetErrorTimestamp() const;
public:
    inline void Termination(int sig);
public:
    inline int GetTerminationSignal();
public:
    inline TimestampType GetTerminationTimestamp() const;
public:
    inline bool IsError() const;
    inline bool IsStart() const;
    inline bool IsEnd() const;
    inline bool IsTerminate() const;
public:
    inline int ReturnValue() const;
};

inline Status::Status() :
    m_stat(static_cast<StatusIntegerType>(StatusEnumType::sOk)),
    m_signal(0),
    m_start(0),
    m_end(0),
    m_terminate(0),
    m_timestamp(0)
{}

inline void Status::Start()
{
    if (m_start != 0) return;
    m_start = test::sys::Definition::GetTimestampNow();
}

inline typename Status::TimestampType 
Status::GetStartTimestamp() const
{
    return m_start;
}

inline void Status::End()
{
    if (m_start == 0 || m_end != 0) return;
    m_end = test::sys::Definition::GetTimestampNow();
}

inline typename Status::TimestampType 
Status::GetEndTimestamp() const
{
    return m_end;
}

inline void Status::Error(StatusEnumType code)
{
    return Error(static_cast<StatusIntegerType>(code));
}

inline void Status::Error(StatusIntegerType code)
{
    if (code == StatusEnumType::sOk) return;
    m_stat.store(code);
    m_timestamp = test::sys::Definition::GetTimestampNow();
}

inline const char* Status::GetErrorName() const
{
    return test::sys::Definition::GetErrorName(m_stat.load());
}

inline typename Status::StatusIntegerType 
Status::GetErrorCode() const
{
    return m_stat.load();
}

inline typename Status::TimestampType 
Status::GetErrorTimestamp() const
{
    return m_timestamp;
}

inline void Status::Termination(int sig)
{
    m_signal = sig;
    m_terminate = test::sys::Definition::GetTimestampNow();
}

inline int Status::GetTerminationSignal()
{
    return m_signal;
}

inline typename Status::TimestampType 
Status::GetTerminationTimestamp() const
{
    return m_terminate;
}

inline bool Status::IsError() const
{
    return m_stat.load() != StatusEnumType::sOk;
}

inline bool Status::IsStart() const
{
    return m_start != 0;
}

inline bool Status::IsEnd() const
{
    return m_end != 0;
}

inline bool Status::IsTerminate() const
{
    return m_terminate != 0;
}

inline int Status::ReturnValue() const
{
    return m_stat.load() == StatusEnumType::sOk ? EXIT_SUCCESS : EXIT_FAILURE;
}

} //!sys

} //!test

#endif //!TEST_SYS_STATUS_H_
