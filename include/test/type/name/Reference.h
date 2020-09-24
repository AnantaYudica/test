#ifndef TEST_TYPE_NAME_REFERENCE_H_
#define TEST_TYPE_NAME_REFERENCE_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "Pointer.h"

#include <cstddef>
#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Reference
{
    typedef T SimpleType;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char no_ref[] = "";
        return {no_ref};
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

template<typename T>
struct Reference<T&>
{
    typedef typename test::type::name::Pointer<T>::SimpleType SimpleType;
    typedef T& Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ref = test::cstr::Format<char>(
            (test::type::name::Pointer<T>::template CStr<char>().Size() + 2),
            "%s&", *(test::type::name::Pointer<T>::template CStr<char>()));
        return {_ref};
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

template<typename T>
struct Reference<T&&>
{
    typedef typename test::type::name::Pointer<T>::SimpleType SimpleType;
    typedef T&& Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ref = test::cstr::Format<char>(
            (test::type::name::Pointer<T>::template CStr<char>().Size() + 3),
            "%s&&", *(test::type::name::Pointer<T>::template CStr<char>()));
        return {_ref};
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

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_REFERENCE_H_
