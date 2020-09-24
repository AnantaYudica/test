#ifndef TEST_DEF_TYPE_NAME_INTEGER_H_
#define TEST_DEF_TYPE_NAME_INTEGER_H_

#include "../../../type/Name.h"
#include "../../../cstr/Format.h"

#include <cwchar>
#include <type_traits>

namespace test
{
namespace type
{

template<>
struct Name<short>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "short";
        return {_name};
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

template<>
struct Name<int>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "int";
        return {_name};
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

template<>
struct Name<long>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "long";
        return {_name};
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

template<>
struct Name<long long>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "long long";
        return {_name};
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

template<>
struct Name<unsigned short>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "unsigned short";
        return {_name};
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

template<>
struct Name<unsigned int>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "unsigned int";
        return {_name};
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

template<>
struct Name<unsigned long>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] =  "unsigned long";
        return {_name};
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

template<>
struct Name<unsigned long long>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "unsigned long long";
        return {_name};
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

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_INTEGER_H_
