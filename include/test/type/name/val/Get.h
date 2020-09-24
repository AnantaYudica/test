#ifndef TEST_TYPE_NAME_VAL_GET_H_
#define TEST_TYPE_NAME_VAL_GET_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "Enumeration.h"

#include <cstdint>
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

template<typename T>
struct Get
{
    template<T V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr()
    {
        return {test::type::name::val::Enumeration<T, V>::template
            CStr<char>()};
    }
    template<T V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T>
struct Get<T&>
{
    template<T& V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (sizeof(int*) * 2) + 3, "%p", &V);
        return {_val};
    }
    template<T& V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T>
struct Get<T*>
{
    template<T* V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr()
    {
        test::CString<char> _val = test::cstr::Format<char>(
            (sizeof(int*) * 2) + 3, "%p", V);
        return {_val};
    }
    template<T* V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename TM>
struct Get<T TM::*>
{
    template<T TM::* V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<char> _val = test::cstr::Format<char>(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
    template<T TM::* V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename TM>
struct Get<T TM::*const>
{
    template<T TM::*const V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<char> _val = test::cstr::Format<char>(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
    template<T TM::*const V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename TM>
struct Get<T TM::*volatile>
{
    template<T TM::*volatile V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<char> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<char> _val = test::cstr::Format<char>(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
    template<T TM::*volatile V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<V, char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename TM>
struct Get<T TM::*const volatile>
{
    template<T TM::*const volatile V, typename TChar= char,
        typename std::enable_if<std::is_same<TChar, char>::value,
            int>::type = 1>
    static test::CString<char> CStr()
    {
        auto _v = static_cast<T TM::*>(V);
        auto p = reinterpret_cast<uintptr_t*>(&_v);
        test::CString<char> _val = test::cstr::Format<char>(
            (sizeof(uintptr_t*) * 2) + 3, "%p", (void*)*p);
        return {_val};
    }
    template<T TM::*const volatile V, typename TChar = char, 
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

#endif //!TEST_TYPE_NAME_VAL_GET_H_
