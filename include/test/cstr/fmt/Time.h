#ifndef TEST_CSTR_FMT_TIME_H_
#define TEST_CSTR_FMT_TIME_H_

#include "../../CString.h"

#include <ctime>
#include <cwchar>
#include <type_traits>
#include <utility>

#ifndef TEST_ATTRIBUTE
#ifdef __GNUC__
#define TEST_ATTRIBUTE(...) __attribute__(__VA_ARGS__)
#else
#define TEST_ATTRIBUTE(...)
#endif
#endif //!TEST_ATTRIBUTE

namespace test
{
namespace cstr
{
namespace fmt
{

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type = 1>
inline test::CString<typename std::remove_const<TChar>::type> 
    Time(const std::size_t& size, const char* format, const struct tm* timeptr)
        TEST_ATTRIBUTE((format(strftime, 2, 0)));

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type = 1>
inline test::CString<typename std::remove_const<TChar>::type> 
    Time(const std::size_t& size, const wchar_t* format, 
        const struct tm* timeptr);

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, char>::value, int>::type>
inline test::CString<typename std::remove_const<TChar>::type> 
    Time(const std::size_t& size, const char* format, const struct tm* timeptr)
{
    std::size_t alloc_size = 16;
    if (size != 0) alloc_size = size;
    char * tmp = new char[alloc_size];
    const auto actual_size = strftime(tmp, alloc_size, format, timeptr);
    if (actual_size >= alloc_size)
    {
        delete[] tmp;
        tmp = new char[actual_size + 1];
        strftime(tmp, actual_size + 1, format, timeptr);
    }
    return {std::move(tmp), actual_size};
}

template<typename TChar, typename std::enable_if<
    std::is_same<TChar, wchar_t>::value, int>::type>
inline test::CString<typename std::remove_const<TChar>::type> 
    Time(const std::size_t& size, const wchar_t* format, 
        const struct tm* timeptr)
{
    std::size_t alloc_size = 16;
    if (size != 0) alloc_size = size;
    wchar_t * tmp = new wchar_t[alloc_size];
    const auto actual_size = wcsftime(tmp, alloc_size, format, timeptr);
    if (actual_size >= alloc_size)
    {
        delete[] tmp;
        tmp = new wchar_t[actual_size + 1];
        wcsftime(tmp, actual_size + 1, format, timeptr);
    }
    return {std::move(tmp), actual_size};
}

} //!fmt

} //!cstr

} //!test

#endif //!TEST_CSTR_FMT_TIME_H_
