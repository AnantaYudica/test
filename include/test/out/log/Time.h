#ifndef TEST_OUT_LOG_TIME_H_
#define TEST_OUT_LOG_TIME_H_

#include "../../CString.h"
#include "../../cstr/fmt/Time.h"
#include "../../cstr/Format.h"
#include "../../out/Standard.h"

#include <cstddef>
#include <cwchar>
#include <ctime>
#include <chrono>

namespace test
{
namespace out
{
namespace log
{

class Time
{
public:
    typedef std::chrono::time_point<std::chrono::system_clock> TimestampType;
public:
    static inline int Year(const struct tm& timeinfo);
    static inline int Month(const struct tm& timeinfo);
    static inline int Day(const struct tm& timeinfo);
    static inline int Hour(const struct tm& timeinfo);
    static inline int Minute(const struct tm& timeinfo);
    static inline int Second(const struct tm& timeinfo);
public: 
    static inline struct tm GetInfo(const TimestampType& timestamp);
public:
    static inline int Year(const TimestampType& timestamp);
    static inline int Month(const TimestampType& timestamp);
    static inline int Day(const TimestampType& timestamp);
    static inline int Hour(const TimestampType& timestamp);
    static inline int Minute(const TimestampType& timestamp);
    static inline int Second(const TimestampType& timestamp);
    static inline int Millisecond(const TimestampType& timestamp);
public:
    template<typename TChar, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static inline test::CString<char> CStr(const TimestampType& timestamp);
    template<typename TChar, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 1>
    static inline test::CString<wchar_t> CStr(const TimestampType& timestamp);
public:
    Time() = delete;
};

inline int Time::Year(const struct tm& timeinfo)
{
    return 1900 + timeinfo.tm_year;
}

inline int Time::Month(const struct tm& timeinfo)
{
    return timeinfo.tm_mon + 1;
}

inline int Time::Day(const struct tm& timeinfo)
{
    return timeinfo.tm_mday;
}

inline int Time::Hour(const struct tm& timeinfo)
{
    return timeinfo.tm_hour;
}

inline int Time::Minute(const struct tm& timeinfo)
{
    return timeinfo.tm_min;
}

inline int Time::Second(const struct tm& timeinfo)
{
    return timeinfo.tm_sec;
}

inline struct tm Time::GetInfo(const TimestampType& timestamp)
{
    auto time = std::chrono::system_clock::to_time_t(timestamp);
    return *(std::localtime (&time));
}

inline int Time::Year(const TimestampType& timestamp)
{
    return Year(GetInfo(timestamp));
}

inline int Time::Month(const TimestampType& timestamp)
{
    return Month(GetInfo(timestamp));
}

inline int Time::Day(const TimestampType& timestamp)
{
    return Day(GetInfo(timestamp));
}

inline int Time::Hour(const TimestampType& timestamp)
{
    return Hour(GetInfo(timestamp));
}

inline int Time::Minute(const TimestampType& timestamp)
{
    return Minute(GetInfo(timestamp));
}

inline int Time::Second(const TimestampType& timestamp)
{
    return Second(GetInfo(timestamp));
}

inline int Time::Millisecond(const TimestampType& timestamp)
{
    using namespace std::chrono;
    auto tp_msec = time_point_cast<milliseconds>(timestamp);
    auto d_msec = duration_cast<milliseconds>(tp_msec.time_since_epoch());
    auto tp_sec = time_point_cast<seconds>(timestamp);
    auto d_sec = duration_cast<seconds>(tp_sec.time_since_epoch());
    std::chrono::milliseconds::rep msec = d_msec.count() - 
        std::chrono::milliseconds::rep(d_sec.count() * 1000);
    return (int)msec;
}

template<typename TChar, typename std::enable_if<
std::is_same<TChar, char>::value, int>::type>
inline test::CString<char> Time::CStr(const TimestampType& timestamp)
{
    auto info = GetInfo(timestamp);
    auto tm_cstr = test::cstr::fmt::Time<char>(20, "%F %X", &info);
    return test::cstr::Format<char>(25, "%s.%03u", 
        *tm_cstr, (unsigned int)Millisecond(timestamp));
}

template<typename TChar, typename std::enable_if<
    !std::is_same<TChar, char>::value &&
    std::is_same<TChar, wchar_t>::value, int>::type>
inline test::CString<wchar_t> Time::CStr(const TimestampType& timestamp)
{
    const auto cstr = CStr<char>(timestamp);
    return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
}

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_TIME_H_
