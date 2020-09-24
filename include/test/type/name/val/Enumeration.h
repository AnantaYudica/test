#ifndef TEST_TYPE_NAME_VAL_ENUMERATION_H_
#define TEST_TYPE_NAME_VAL_ENUMERATION_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"

#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<typename T, T V, bool = std::is_enum<T>::value>
struct Enumeration
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char undefined[] = "value-get-undefined";
        return {undefined};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};
template<typename T, T V>
struct Enumeration<T, V, true>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char undefined[] = "value-enumeration-undefined";
        return {undefined};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

} //!val

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VAL_ENUMERATION_H_
