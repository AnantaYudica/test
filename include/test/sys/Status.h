#ifndef TEST_SYS_STATUS_H_
#define TEST_SYS_STATUS_H_

#include "Definition.h"

#include <cstdlib>
#include <utility>
#include <cstdint>

#define TEST_SYS_STATUS_DEF_ERR_CODE(name, val)\
static constexpr StatusIntegerType name = val

namespace test
{
namespace sys
{

class Status
{
public:
    typedef typename test::sys::Definition::TimestampType TimestampType;
    typedef std::uint16_t StatusIntegerType;
public:
    TEST_SYS_STATUS_DEF_ERR_CODE(sOk,                                  0x0000);
    TEST_SYS_STATUS_DEF_ERR_CODE(sUndefined,                           0x0001);
    TEST_SYS_STATUS_DEF_ERR_CODE(sSysAllocArgsFailed,                  0x0100);
    TEST_SYS_STATUS_DEF_ERR_CODE(sSignalsAllocFailed,                  0x0200);
    TEST_SYS_STATUS_DEF_ERR_CODE(sSignalsReallocFailed,                0x0201);
    TEST_SYS_STATUS_DEF_ERR_CODE(sSignalsReallocOverflow,              0x0202);
    TEST_SYS_STATUS_DEF_ERR_CODE(sMemoryReallocFailed,                 0x0300);
    TEST_SYS_STATUS_DEF_ERR_CODE(sMemoryReferenceCountOverflow,        0x0301);
    TEST_SYS_STATUS_DEF_ERR_CODE(sMemRecordAllocFailed,                0x0400);
    TEST_SYS_STATUS_DEF_ERR_CODE(sMemRecordDuplicatePointer,           0x0401);
    TEST_SYS_STATUS_DEF_ERR_CODE(sMemRecordPointerNotFound,            0x0402);
    TEST_SYS_STATUS_DEF_ERR_CODE(sMemRecordSizeOverflow,               0x0403);

private:
    static inline const char* _GetErrorName(StatusIntegerType code);
private:
    StatusIntegerType m_stat;
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

inline const char* Status::_GetErrorName(StatusIntegerType code)
{
    static const char* error_names[] = {
        // 00
        "sOk",
        "sUndefined",
        // 01
        "sSysAllocArgsFailed",
        // 02
        "sSignalsAllocFailed",
        "sSignalsReallocFailed",
        "sSignalsReallocOverflow",
        // 03
        "sMemoryReallocFailed",
        "sMemoryReferenceCountOverflow",
        // 04
        "sMemRecordAllocFailed",
        "sMemRecordDuplicatePointer",
        "sMemRecordPointerNotFound",
        "sMemRecordSizeOverflow"
    };
    static const std::uint8_t error_max[] = {
        2, 1, 3, 2, 4
    };
    const uint8_t obj_code = code >> 8;
    const uint8_t num_code = 0x00FF & code;
    auto errorName = error_names[1];
    if (obj_code < sizeof(error_max))
    {
        if (num_code < error_max[obj_code])
        {
            std::uint16_t index = 0; 
            for (int i = 0; i < sizeof(error_max); ++i)
            {
                if (i == obj_code)
                {
                    break;
                }
                index += error_max[i];
            }
            errorName = error_names[index + code];
        }
    }
    return errorName;
}

inline Status::Status() :
    m_stat(sOk),
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

inline void Status::Error(StatusIntegerType code)
{
    if (code == sOk) return;
    m_stat = code;
    m_timestamp = test::sys::Definition::GetTimestampNow();
}

inline const char* Status::GetErrorName() const
{
    return _GetErrorName(m_stat);
}

inline typename Status::StatusIntegerType 
Status::GetErrorCode() const
{
    return m_stat;
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
    return m_stat != sOk;
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
    return m_stat == sOk ? EXIT_SUCCESS : EXIT_FAILURE;
}

} //!sys

} //!test

#endif //!TEST_SYS_STATUS_H_
