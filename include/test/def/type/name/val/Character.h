#ifndef TEST_DEF_TYPE_NAME_VAL_CHARACTER_H_
#define TEST_DEF_TYPE_NAME_VAL_CHARACTER_H_

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
struct Get<signed char>
{
    template<signed char V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        const auto val = static_cast<unsigned char>(std::abs(V));
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : (V < 0 ? 
                (std::log10(val) + 3) : 2)), "%hhd", V);
        return {_val};
    }
    template<signed char V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<char>
{
    template<char V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(2, "%c", V);
        return {_val};
    }
    template<char V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<>
struct Get<unsigned char>
{
    template<unsigned char V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (V > 0 ? (std::log10(V) + 2) : 2), "%hhu", V);
        return {_val};
    }
    template<unsigned char V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
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

#endif //!TEST_DEF_TYPE_NAME_VAL_CHARACTER_H_
