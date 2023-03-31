#ifndef TEST_SYS_DEFINITION_H_IMPL_
#define TEST_SYS_DEFINITION_H_IMPL_

#include "Definition.h"
#include "Debug.h"
#include "Interface.h"

#ifndef TEST_SYS_DEFINITION_DLEVEL

#define TEST_SYS_DEFINITION_DLEVEL 1

#endif //!TEST_SYS_DEFINITION_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(
    TEST_SYS_DEFINITION_DLEVEL, 
    "test::sys::Definition", 
    test::sys::Definition);

static inline bool 
operator==(typename test::sys::Definition::Status status_enum,
    typename test::sys::Definition::StatusIntegerType status_int)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "operator==(status_enum=%d, status_int=%d)",
            test::sys::Definition::StatusIntegerType(status_enum), status_int);

    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        == status_int;
}

static inline bool 
operator!=(typename test::sys::Definition::Status status_enum,
    typename test::sys::Definition::StatusIntegerType status_int)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "operator!=(status_enum=%d, status_int=%d)",
            test::sys::Definition::StatusIntegerType(status_enum), status_int);

    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        != status_int;
}

static inline bool 
operator==(typename test::sys::Definition::StatusIntegerType status_int,
    typename test::sys::Definition::Status status_enum)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "operator==(status_int=%d, status_enum=%d)", status_int,
            test::sys::Definition::StatusIntegerType(status_enum));

    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        == status_int;
}

static inline bool 
operator!=(typename test::sys::Definition::StatusIntegerType status_int,
    typename test::sys::Definition::Status status_enum)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "operator!=(status_int=%d, status_enum=%d)", status_int,
            test::sys::Definition::StatusIntegerType(status_enum));

    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        != status_int;
}

namespace test
{
namespace sys
{

inline typename Definition::TimestampType Definition::GetTimestampNow()
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, "GetTimestampNow()");

    return std::chrono::duration_cast<TimestampDurationType>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
    ).count();
}

template<typename TTimeDuration>
inline typename test::sys::Definition::TimeDurationType
Definition::GetTimeDuration(const TimestampType& before,
    const TimestampType& after)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "GetTimeDuration(before=%lld, after=%lld)", before, after);

    if (before >= after) return TimeDurationType();
    TTimeDuration duration(after - before);
    const auto count_inMicroSec = std::chrono::duration_cast<
        std::chrono::microseconds>(duration).count();
    const auto count_inMiliSec = count_inMicroSec / 1000;
    const auto count_inSec = count_inMiliSec / 1000;
    const auto count_inMin = count_inSec / 60;
    const auto count_inHour = count_inMin / 60;
    const auto count_inDay = count_inHour / 24;
    TimeDurationType result;
    result.Microsecond = count_inMicroSec - (count_inMiliSec * 1000);
    result.Milisecond = count_inMiliSec - (count_inSec * 1000);
    result.Second = count_inSec - (count_inMin * 60);
    result.Minute = count_inMin - (count_inHour * 60);
    result.Hour = count_inHour - (count_inDay * 24);
    result.Day = count_inDay;
    return result;
}


template<typename TTimeDuration>
inline typename test::sys::Definition::TimeType
Definition::GetTime(const TimestampType& timestamp)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "GetTime(timestamp=%lld)", timestamp);

    TTimeDuration duration(timestamp);
    const auto count_inMicroSec = std::chrono::duration_cast<
        std::chrono::microseconds>(duration).count();
    const auto count_inSec = std::chrono::duration_cast<
        std::chrono::seconds>(duration).count();
    const auto miliSec = count_inMicroSec - (count_inSec * 1000000);
    const std::chrono::system_clock::time_point tp(duration);
    const auto tm = std::chrono::system_clock::to_time_t(tp);
    
    time_t local_time = 0;
    TimeType result;
    {
        const auto local = localtime(&tm);
        
        local_time = mktime(local);

        result.Hour = local->tm_hour;
        result.Minute = local->tm_min;
        result.Second = local->tm_sec;
        result.Milisecond = miliSec / 1000;
        result.Microsecond = miliSec - (result.Milisecond * 1000);
    }
    {
        const auto gmt = gmtime(&tm);
        const auto gmt_time = mktime(gmt);
        const auto diff_time = local_time - gmt_time;
        result.UTC_Hour = diff_time / 3600;
        result.UTC_Minute = diff_time - (result.UTC_Hour * 3600);
    }
    return result;
}

template<typename TTimeDuration>
inline typename test::sys::Definition::DateType 
Definition::GetDate(const TimestampType& timestamp)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "GetDate(timestamp=%lld)", timestamp);

    TTimeDuration duration(timestamp);
    const std::chrono::system_clock::time_point tp(duration);
    const auto tm = std::chrono::system_clock::to_time_t(tp);
    const auto local = localtime(&tm);
    DateType result;
    result.Year = 1900 + local->tm_year;
    result.Month = local->tm_mon + 1;
    result.Weekday = local->tm_wday;
    result.Day = local->tm_mday;
    return result;
}

template<typename TTimeDuration>
inline typename test::sys::Definition::DateTimeType 
Definition::GetDateTime(const TimestampType& timestamp)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "GetDateTime(timestamp=%lld)", timestamp);

    TTimeDuration duration(timestamp);
    const auto count_inMicroSec = std::chrono::duration_cast<
        std::chrono::microseconds>(duration).count();
    const auto count_inSec = std::chrono::duration_cast<
        std::chrono::seconds>(duration).count();
    const auto miliSec = count_inMicroSec - (count_inSec * 1000000);
    const std::chrono::system_clock::time_point tp(duration);
    const auto tm = std::chrono::system_clock::to_time_t(tp);

    time_t local_time = 0;
    DateTimeType result;
    {
#if (defined(WIN32) && !defined(_CRT_SECURE_NO_WARNINGS))

        struct tm slocal;
        localtime_s(&slocal, &tm);
        struct tm* local = &slocal;

#elif defined(__STDC_LIB_EXT1__)

        struct tm slocal;
        localtime_s(&tm, &slocal);
        struct tm* local = &slocal;
#else
        const auto local = std::localtime(&tm);
#endif
        const auto local_time = mktime(local);

        result.Year = 1900 + local->tm_year;
        result.Month = local->tm_mon + 1;
        result.Weekday = local->tm_wday;
        result.Day = local->tm_mday;
        result.Hour = local->tm_hour;
        result.Minute = local->tm_min;
        result.Second = local->tm_sec;
        result.Milisecond = miliSec / 1000;
        result.Microsecond = miliSec - (result.Milisecond * 1000);
    }
    {

#if (defined(WIN32) && !defined(_CRT_SECURE_NO_WARNINGS))

        struct tm sgmt;
        gmtime_s(&sgmt, &tm);
        struct tm *gmt = &sgmt;
#elif defined(__STDC_LIB_EXT1__)

        struct tm sgmt;
        gmtime_s(&tm, &sgmt);
        struct tm* gmt = &sgmt;
#else
        const auto gmt = gmtime(&tm);
#endif
        
        const auto gmt_time = mktime(gmt);
        const auto diff_time = local_time - gmt_time;
        result.UTC_Hour = diff_time / 3600;
        result.UTC_Minute = diff_time - (result.UTC_Hour * 3600);
    }
    return result;
}

inline std::size_t Definition::SumStatusNames(std::uint8_t tag, 
    std::size_t sum)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    TEST_SYS_DEBUG_DEFAULT(DebugType, 3, NULL, 
        "SumStatusNames(tag=%hhu, sum=%zu)", tag, sum);

    return (tag <= StatusTagMax) ? (tag == 0 ? 
        (sum + StatusErrorNameMaxIndexs<>()[0] + 2) : 
            SumStatusNames(tag - 1, sum + StatusErrorNameMaxIndexs<>()[tag] + 1)) :
        SumStatusNames(StatusTagMax); 
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N == 0, const char**>::type 
Definition::StatusNames(TArgs... args)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StatusNames<%zu, %s>(args={%s})", N, 
            TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));

    static const char* names[] = {args...};
    return names;
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N != 0, const char**>::type 
Definition::StatusNames(TArgs... args)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StatusNames<%zu, %s>(args={%s})", N, 
            TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));


    return StatusNames<N - 1>(args..., 
        _StatusNames[_StatusNamesSize - N]);
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N == 0, std::uint8_t*>::type 
Definition::StatusErrorNameMaxIndexs(TArgs... args)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StatusNames<%zu, %s>(args={%s})", N, 
            TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));

    static std::uint8_t max_indexs[] = {args...};
    return max_indexs;
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N != 0, std::uint8_t*>::type 
Definition::StatusErrorNameMaxIndexs(TArgs... args)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StatusNames<%zu, %s>(args={%s})", N, 
            TEST_SYS_DEBUG_TARGS_NAME_STR(TArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(args...));

    return StatusErrorNameMaxIndexs<N - 1>(args..., 
        _StatusErrorNameMaxIndexs[_StatusErrorNameMaxIndexsSize - N]);
}

inline const char* Definition::GetStatusTagName(Status code)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;

    return GetStatusTagName(static_cast<StatusIntegerType>(code));
}

inline const char* Definition::GetStatusTagName(StatusIntegerType code)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;


    const uint8_t tag_code = code >> 8;
    const uint8_t num_code = 0x00FF & code;

    if (tag_code > StatusTagMax || tag_code < 0)
    {
        return StatusNames<>()[1];
    }
    const std::size_t name = SumStatusNames(tag_code);
    return StatusNames<>()[name];
}

inline const char* Definition::GetStatusName(Status code)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;


    return GetStatusName(static_cast<StatusIntegerType>(code));
}

inline const char* Definition::GetStatusName(StatusIntegerType code)
{
    typedef test::sys::dbg::Type<test::sys::Definition> DebugType;
    typedef test::sys::Interface SystemType;

    if (code == Status::sOk)
    {
        return StatusNames<>()[0];
    }

    const uint8_t tag_code = code >> 8;
    const uint8_t num_code = (StatusIntegerType)Status::sError ^ (0x00FF & code);
    
    if (tag_code > StatusTagMax || tag_code < 0)
    {
        return StatusNames<>()[2];
    }
    
    const StatusIntegerType max = StatusErrorNameMaxIndexs<>()[tag_code];
    if (num_code >= max || num_code == 0)
    {
        return StatusNames<>()[2];
    }
    const std::size_t name = SumStatusNames(tag_code);
    return StatusNames<>()[name + num_code];
}

} //!sys

} //!test

#endif //!TEST_SYS_DEFINITION_H_IMPL_
