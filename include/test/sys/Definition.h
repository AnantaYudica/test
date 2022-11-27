#ifndef TEST_SYS_DEFINITION_H_
#define TEST_SYS_DEFINITION_H_

#include <chrono>
#include <ctime>

#include <cstdio>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

namespace test
{
namespace sys
{

struct Definition
{
    typedef std::uint16_t StatusIntegerType;
    typedef std::chrono::microseconds TimestampDurationType;
    typedef decltype(TimestampDurationType().count()) TimestampType;
    typedef TimestampType DurationType;
    struct DateType
    {
        int Weekday;
        int Day;
        int Month;
        int Year;
    };

    struct TimeType
    {
        int Hour;
        int Minute;
        int Second;
        int Milisecond;
        int Microsecond;
        int UTC_Hour;
        int UTC_Minute;
    };

    struct DateTimeType : DateType, TimeType {};

    struct TimeDurationType : TimeType
    {
        int Day;
    };

    static constexpr const char * DayNames[] {
        "Sunday", "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday"
    };
    static constexpr const char * MonthNames[] {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };

    
    static inline TimestampType GetTimestampNow();
    
    template<typename TTimeDuration = TimestampDurationType>
    static inline TimeDurationType GetTimeDuration(const TimestampType& before,
        const TimestampType& after);

    template<typename TTimeDuration = TimestampDurationType>
    static inline TimeType GetTime(const TimestampType& timestamp);

    template<typename TTimeDuration = TimestampDurationType>
    static inline DateType GetDate(const TimestampType& timestamp);
    
    template<typename TTimeDuration = TimestampDurationType>
    static inline DateTimeType GetDateTime(const TimestampType& timestamp);

    enum class Status : StatusIntegerType 
    {
        sOk                                 = 0x0000,
        sUndefined                          = 0x0001,

        sSysAllocArgsFailed                 = 0x0100,

        sSignalsAllocFailed                 = 0x0200,
        sSignalsReallocFailed               = 0x0201,
        sSignalsReallocOverflow             = 0x0202,

        sMemoryReallocFailed                = 0x0300,
        sMemoryReferenceCountOverflow       = 0x0301,


        sMemRecordAllocFailed               = 0x0400,
        sMemRecordDuplicatePointer          = 0x0401,
        sMemRecordPointerNotFound           = 0x0402,
        sMemRecordSizeOverflow              = 0x0403,

        sUnknown                            = 0xFFFF
    };

    static inline const char* GetErrorName(Status code);
    static inline const char* GetErrorName(StatusIntegerType code);

};

inline typename Definition::TimestampType Definition::GetTimestampNow()
{
    return std::chrono::duration_cast<TimestampDurationType>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
    ).count();
}

template<typename TTimeDuration>
inline typename test::sys::Definition::TimeDurationType
Definition::GetTimeDuration(const TimestampType& before,
    const TimestampType& after)
{
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
        const auto local = localtime(&tm);

        local_time = mktime(local);

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
        const auto gmt = gmtime(&tm);
        const auto gmt_time = mktime(gmt);
        const auto diff_time = local_time - gmt_time;
        result.UTC_Hour = diff_time / 3600;
        result.UTC_Minute = diff_time - (result.UTC_Hour * 3600);
    }
    return result;
}

inline const char* Definition::GetErrorName(Status code)
{
    return GetErrorName(static_cast<StatusIntegerType>(code));
}

inline const char* Definition::GetErrorName(StatusIntegerType code)
{
    static const char unkown[] = "sUnknown"; 
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
    const char * errorName = unkown;
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

static inline bool operator==(typename Definition::Status status_enum,
    typename Definition::StatusIntegerType status_int)
{
    return static_cast<Definition::StatusIntegerType>(status_enum)
        == status_int;
}

static inline bool operator!=(typename Definition::Status status_enum,
    typename Definition::StatusIntegerType status_int)
{
    return static_cast<Definition::StatusIntegerType>(status_enum)
        != status_int;
}

static inline bool 
operator==(typename Definition::StatusIntegerType status_int,
    typename Definition::Status status_enum)
{
    return static_cast<Definition::StatusIntegerType>(status_enum)
        == status_int;
}

static inline bool 
operator!=(typename Definition::StatusIntegerType status_int,
    typename Definition::Status status_enum)
{
    return static_cast<Definition::StatusIntegerType>(status_enum)
        != status_int;
}

} //!sys

} //!test

#endif //!TEST_SYS_DEFINITION_H_
