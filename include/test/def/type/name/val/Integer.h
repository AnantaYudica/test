#ifndef TEST_DEF_TYPE_NAME_VAL_INTEGER_H_
#define TEST_DEF_TYPE_NAME_VAL_INTEGER_H_

#include "../../../../CString.h"
#include "../../../../cstr/Format.h"
#include "../../../../type/name/val/Get.h"

#include <cstdint>
#include <cmath>
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

template<>
struct Get<short>
{
    template<short V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        const auto val = static_cast<unsigned short>(std::abs(V));
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : (V < 0 ? 
                (std::log10(val) + 3) : 2)), "%hd", V);
        return {_val};
    }
    template<short V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<unsigned short>
{
    template<unsigned short V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : 2), "%hu", V);
        return {_val};
    }
    template<unsigned short V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<int>
{
    template<int V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        const auto val = static_cast<unsigned int>(std::abs(V));
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : (V < 0 ? 
                (std::log10(val) + 3) : 2)), "%d", V);
        return {_val};
    }
    template<int V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<unsigned int>
{
    template<unsigned int V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : 2), "%u", V);
        return {_val};
    }
    template<unsigned int V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<long>
{
    template<long V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        const auto val = static_cast<unsigned long>(std::abs(V));
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : (V < 0 ? 
                (std::log10(val) + 3) : 2)), "%ld", V);
        return {_val};
    }
    template<long V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<unsigned long>
{
    template<unsigned long V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : 2), "%lu", V);
        return {_val};
    }
    template<unsigned long V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<long long>
{
    template<long long V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        const auto val = static_cast<unsigned long long>(std::abs(V));
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : (V < 0 ? 
                (std::log10(val) + 3) : 2)), "%lld", V);
        return {_val};
    }
    template<long long V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<unsigned long long>
{
    template<unsigned long long V, typename TChar= char,
        typename std::enable_if<std::is_same<TChar, char>::value,
            int>::type = 1>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : 2), "%llu", V);
        return {_val};
    }
    template<unsigned long long V, typename TChar = char, 
        typename std::enable_if<!std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

} //!val

} //!name

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_VAL_INTEGER_H_
