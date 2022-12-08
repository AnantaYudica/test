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

#include "Definition.impl.h"

#endif //!TEST_SYS_DEFINITION_H_
