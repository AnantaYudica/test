#ifndef TEST_SYS_DEFINITION_H_
#define TEST_SYS_DEFINITION_H_

#include <chrono>
#include <ctime>
#include <type_traits>

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
        sError                              = 0x0080,
        sSystem                             = sOk,
        sAllocationAgumentsFailed           = sError | 0x01,
        sUndefined                          = sError | 0x02,

        sSignals                            = 0x0100,
        sSignalsAllocationFailed            = sSignals | sError | 0x01,
        sSignalsReallocationFailed          = sSignals | sError | 0x02,
        sSignalsReallocationOutOfMemory     = sSignals | sError | 0x03,

        sMemory                             = 0x0200,
        sMemoryNotClearOnFinalize           = sMemory | sError | 0x01,

        sMemRecord                          = 0x0300,
        sMemRecordAllocationFailed          = sMemRecord | sError | 0x01,
        sMemRecordDuplicatePointer          = sMemRecord | sError | 0x02,
        sMemRecordPointerNotFound           = sMemRecord | sError | 0x03,
        sMemRecordSizeOverflow              = sMemRecord | sError | 0x04,

        sMemBlock                           = 0x0400,
        sMemBlockAllocationFailed           = sMemBlock | sError | 0x01,
        sMemBlockReallocationFailed         = sMemBlock | sError | 0x02,
        sMemBlockReferenceCountOverflow     = sMemBlock | sError | 0x03,

        sMemPointer                         = 0x0500,
        sMemPointerCastFailed               = sMemPointer | sError | 0x01,
        sMemPointerIndexOutOfBounds         = sMemPointer | sError | 0x02,

        sMemDummy                           = 0x0600,
        sMemDummyAllocationFailed           = sMemDummy | sError | 0x01,
        sMemDummyReallocationFailed         = sMemDummy | sError | 0x02,

        sUnknown                            = 0xFFFF
    };

    static constexpr const char* _StatusNames[] = {

        "sOk",

        "[Unknown]",
        "sUnknown",

        "[System]",
        "sAllocationAgumentsFailed",
        "sUndefined",

        "[sys][Signals]",
        "sSignalsAllocationFailed",
        "sSignalsReallocationFailed",
        "sSignalsReallocationOutOfMemory"

        "[sys][Memory]",
        "sMemoryNotClearOnFinalize",

        "[sys][mem][Record]",
        "sMemRecordAllocationFailed",
        "sMemRecordDuplicatePointer",
        "sMemRecordPointerNotFound",
        "sMemRecordSizeOverflow",

        "[sys][mem][Block]",
        "sMemBlockAllocationFailed",
        "sMemBlockReallocationFailed",
        "sMemBlockReferenceCountOverflow",

        "[sys][mem][Pointer]"
        "sMemPointerCastFailed",
        "sMemPointerIndexOutOfBounds",

        "[sys]][mem][Dummy]"
        "sMemDummyAllocationFailed",
        "sMemDummyReallocationFailed",
    };

    static constexpr std::size_t _StatusNamesSize = 
        sizeof(_StatusNames) / sizeof(const char*);
    
    static constexpr StatusIntegerType StatusTagMax = 6;

    static constexpr std::uint8_t _StatusErrorNameMaxIndexs[] = 
    {
        1, 2, 3, 1, 4, 3, 2, 2
    };
    static constexpr std::size_t _StatusErrorNameMaxIndexsSize = 
        sizeof(_StatusErrorNameMaxIndexs) / sizeof(std::uint8_t);

    static inline std::size_t SumStatusNames(std::uint8_t tag = StatusTagMax, 
        std::size_t sum = 0);

    template<std::size_t N = _StatusNamesSize, typename... TArgs>
    static inline typename std::enable_if<N == 0, const char**>::type 
        StatusNames(TArgs... args);
    template<std::size_t N = _StatusNamesSize, typename... TArgs>
    static inline typename std::enable_if<N != 0, const char**>::type 
        StatusNames(TArgs... args);

    template<std::size_t N = _StatusErrorNameMaxIndexsSize, 
        typename... TArgs>
    static inline typename std::enable_if<N == 0, std::uint8_t*>::type 
        StatusErrorNameMaxIndexs(TArgs... args);
    template<std::size_t N = _StatusErrorNameMaxIndexsSize, 
        typename... TArgs>
    static inline typename std::enable_if<N != 0, std::uint8_t*>::type 
        StatusErrorNameMaxIndexs(TArgs... args);


    static inline const char* GetStatusTagName(Status code);
    static inline const char* GetStatusTagName(StatusIntegerType code);

    static inline const char* GetStatusName(Status code);
    static inline const char* GetStatusName(StatusIntegerType code);

};

} //!sys

} //!test

static inline bool 
operator==(typename test::sys::Definition::Status status_enum,
    typename test::sys::Definition::StatusIntegerType status_int)
{
    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        == status_int;
}

static inline bool 
operator!=(typename test::sys::Definition::Status status_enum,
    typename test::sys::Definition::StatusIntegerType status_int)
{
    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        != status_int;
}

static inline bool 
operator==(typename test::sys::Definition::StatusIntegerType status_int,
    typename test::sys::Definition::Status status_enum)
{
    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        == status_int;
}

static inline bool 
operator!=(typename test::sys::Definition::StatusIntegerType status_int,
    typename test::sys::Definition::Status status_enum)
{
    return static_cast<test::sys::Definition::StatusIntegerType>(status_enum)
        != status_int;
}

namespace test
{
namespace sys
{

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

inline std::size_t Definition::SumStatusNames(std::uint8_t tag, 
    std::size_t sum)
{
    return (tag <= StatusTagMax) ? (tag == 0 ? 
        (sum + StatusErrorNameMaxIndexs<>()[0] + 2) : 
            SumStatusNames(tag - 1, sum + StatusErrorNameMaxIndexs<>()[tag] + 1)) :
        SumStatusNames(StatusTagMax); 
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N == 0, const char**>::type 
Definition::StatusNames(TArgs... args)
{
    static const char* names[] = {args...};
    return names;
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N != 0, const char**>::type 
Definition::StatusNames(TArgs... args)
{
    return StatusNames<N - 1>(args..., 
        _StatusNames[_StatusNamesSize - N]);
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N == 0, std::uint8_t*>::type 
Definition::StatusErrorNameMaxIndexs(TArgs... args)
{
    static std::uint8_t max_indexs[] = {args...};
    return max_indexs;
}

template<std::size_t N, typename... TArgs>
inline typename std::enable_if<N != 0, std::uint8_t*>::type 
Definition::StatusErrorNameMaxIndexs(TArgs... args)
{
    return StatusErrorNameMaxIndexs<N - 1>(args..., 
        _StatusErrorNameMaxIndexs[_StatusErrorNameMaxIndexsSize - N]);
}

inline const char* Definition::GetStatusTagName(Status code)
{
    return GetStatusTagName(static_cast<StatusIntegerType>(code));
}

inline const char* Definition::GetStatusTagName(StatusIntegerType code)
{
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
    return GetStatusName(static_cast<StatusIntegerType>(code));
}

inline const char* Definition::GetStatusName(StatusIntegerType code)
{
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

#endif //!TEST_SYS_DEFINITION_H_
