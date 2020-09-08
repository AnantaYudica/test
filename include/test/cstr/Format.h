#ifndef TEST_CSTR_FORMAT_H_
#define TEST_CSTR_FORMAT_H_

#include "../CString.h"

#include <cstring>
#include <utility>
#include <type_traits>

#ifndef __ATTRIBUTE__
#ifdef __GNUC__
#define __ATTRIBUTE__(...) __attribute__(__VA_ARGS__)
#else
#define __ATTRIBUTE__(...)
#endif
#endif //!__ATTRIBUTE__

namespace test
{
namespace cstr
{

template<typename TChar = char>
test::CString<typename std::remove_const<TChar>::type> 
    Format(const std::size_t& size, const char* format, ...)
        __ATTRIBUTE__((format(printf, 2, 3)));

template<typename TChar>
test::CString<typename std::remove_const<TChar>::type> 
    Format(const std::size_t& size, const char* format, ...)
{
    if (size != 0)
    {
        va_list args;
        va_start(args, format);
        auto* cstr = new typename std::remove_const<TChar>::type[size];
        int res = vsnprintf(cstr, size, format, args);
        va_end(args);
        if (res < 0 || (std::size_t)res >= size)
            cstr[size - 1] = '\0';
        return {std::move(cstr), size - 1};
    }
    return {""};
}

} //!cstr

} //!test

#endif //!TEST_CSTR_FORMAT_H_

