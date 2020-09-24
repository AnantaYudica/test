#ifndef TEST_TYPE_NAME_ARRAY_H_
#define TEST_TYPE_NAME_ARRAY_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"

#include <cstddef>
#include <cmath>
#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Array
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char no_arr[] = "";
        return {no_arr};
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
struct Array<T[]>
{
    typedef T SimpleType;
    typedef T Type[];
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char _arr[] = "[]";
        return {_arr};
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

template<typename T, std::size_t N>
struct Array<T[N]>
{
    typedef T SimpleType;
    typedef T Type[N];
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _arr = test::cstr::Format<char>(
            (static_cast<std::size_t>(log10(N)) + 4), "[%zd]", N);
        return {_arr};
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

template<typename T, std::size_t N, std::size_t M>
struct Array<T[N][M]>
{
    typedef typename Array<T[M]>::SimpleType SimpleType;
    typedef T Type[N][M];
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _arr = test::cstr::Format<char>(
            (static_cast<std::size_t>(log10(N)) +
                Array<T[M]>::template CStr<char>().Size() + 4), "[%zd]%s", 
            N, *(Array<T[M]>::template CStr<char>()));
        return {_arr};
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


#endif //!TEST_TYPE_NAME_ARRAY_H_
