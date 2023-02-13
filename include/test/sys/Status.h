#ifndef TEST_SYS_STATUS_H_
#define TEST_SYS_STATUS_H_

#include "Definition.h"
#include "Interface.h"
#include "Debug.h"

#include <cstdlib>
#include <utility>
#include <cstdint>
#include <atomic>

namespace test
{
namespace sys
{

class Status;

} //!sys

} //!test

#ifndef TEST_SYS_STATUS_DLEVEL

#define TEST_SYS_STATUS_DLEVEL 1

#endif //!TEST_SYS_STATUS_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_SYS_STATUS_DLEVEL, 
    "test::sys::Status", test::sys::Status);

namespace test
{
namespace sys
{

class Status
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::Status> DebugType;
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
    inline Status(const Status& cpy);
    inline Status(Status&& mov);
public:
    inline ~Status();
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
    inline const char* GetName() const;
public:
    inline StatusIntegerType GetCode() const;
public:
    inline TimestampType GetTimestamp() const;
public:
    inline void Termination(int sig);
public:
    inline int GetTerminationSignal() const;
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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Status::Status(const Status& cpy) :
    m_stat(cpy.m_stat.load()),
    m_signal(cpy.m_signal),
    m_start(cpy.m_start),
    m_end(cpy.m_end),
    m_terminate(cpy.m_terminate),
    m_timestamp(cpy.m_timestamp)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

inline Status::Status(Status&& mov) :
    m_stat(mov.m_stat.load()),
    m_signal(mov.m_signal),
    m_start(mov.m_start),
    m_end(mov.m_end),
    m_terminate(mov.m_terminate),
    m_timestamp(mov.m_timestamp)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(mov=%p)", &mov);
    
    mov.m_stat = static_cast<StatusIntegerType>(StatusEnumType::sOk);
    mov.m_signal = 0;
    mov.m_start = 0;
    mov.m_end = 0;
    mov.m_terminate = 0;
    mov.m_timestamp = 0;
}

inline Status::~Status()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_stat = static_cast<StatusIntegerType>(StatusEnumType::sOk);
    m_signal = 0;
    m_start = 0;
    m_end = 0;
    m_terminate = 0;
    m_timestamp = 0;
}

inline void Status::Start()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Start()");

    if (m_start != 0) return;
    m_start = test::sys::Definition::GetTimestampNow();
}

inline typename Status::TimestampType 
Status::GetStartTimestamp() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetStartTimestamp() const");
    
    return m_start;
}

inline void Status::End()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "End()");

    if (m_start == 0 || m_end != 0) return;
    m_end = test::sys::Definition::GetTimestampNow();
}

inline typename Status::TimestampType 
Status::GetEndTimestamp() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetEndTimestamp() const");
    
    return m_end;
}

inline void Status::Error(StatusEnumType code)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Error(code=%s)",
        test::sys::Definition::GetStatusName(code));

    return Error(static_cast<StatusIntegerType>(code));
}

inline void Status::Error(StatusIntegerType code)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Error(code=0x%x)", code);

    if (code == StatusEnumType::sOk) return;
    m_stat.store(code);
    m_timestamp = test::sys::Definition::GetTimestampNow();
}

inline const char* Status::GetName() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetName() const");
    
    return test::sys::Definition::GetStatusName(m_stat.load());
}

inline typename Status::StatusIntegerType 
Status::GetCode() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetCode() const");
    
    return m_stat.load();
}

inline typename Status::TimestampType 
Status::GetTimestamp() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetTimestamp() const");
    
    return m_timestamp;
}

inline void Status::Termination(int sig)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Termination(sig=%d)", sig);

    m_signal = sig;
    m_terminate = test::sys::Definition::GetTimestampNow();
}

inline int Status::GetTerminationSignal() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this,
        "GetTerminationSignal() const");
    
    return m_signal;
}

inline typename Status::TimestampType 
Status::GetTerminationTimestamp() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "GetTerminationTimestamp() const");
    
    return m_terminate;
}

inline bool Status::IsError() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsError() const");
    
    return m_stat.load() != StatusEnumType::sOk;
}

inline bool Status::IsStart() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsStart() const");
    
    return m_start != 0;
}

inline bool Status::IsEnd() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsEnd() const");
    
    return m_end != 0;
}

inline bool Status::IsTerminate() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsTerminate() const");
    
    return m_terminate != 0;
}

inline int Status::ReturnValue() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "ReturnValue() const");
    
    return m_stat.load() == StatusEnumType::sOk ? EXIT_SUCCESS : EXIT_FAILURE;
}

} //!sys

} //!test

#endif //!TEST_SYS_STATUS_H_
