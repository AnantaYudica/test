#ifndef TEST_CSTR_FORMAT_H_
#define TEST_CSTR_FORMAT_H_

#include "../CString.h"

#include <cstring>
#include <utility>
#include <type_traits>

namespace basic
{
namespace test
{
namespace cstr
{

template<typename TChar = char, typename... TArgs>
test::CString<typename std::remove_const<TChar>::type> 
    Format(const std::size_t& size, const char* format, TArgs&&... args)
{
    if (size != 0)
    {
        auto* cstr = new typename std::remove_const<TChar>::type[size];
        int res = snprintf(cstr, size, format, std::forward<TArgs>(args)...);
        if (res < 0 || (std::size_t)res >= size)
            cstr[size - 1] = '\0';
        return {std::move(cstr), size};
    }
    return {""};
}

} //!cstr

} //!test

} //!basic

#endif //!TEST_CSTR_FORMAT_H_

