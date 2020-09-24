#ifndef TEST_TYPE_NAME_FUNCTION_H_
#define TEST_TYPE_NAME_FUNCTION_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "Parameter.h"

#include <type_traits>
#include <cstddef>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Function
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char no_func[] = "";
        return {no_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...)>
{
    typedef T SimpleType;
    typedef T Type(TArgs...);
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Parameter<TArgs...>::
                template CStr<char>().Size() + 3),
            "(%s)", *(test::type::name::Parameter<TArgs...>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...)>
{
    typedef T SimpleType;
    typedef T Type(...);
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char _func[] = "(...)";
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...)>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...);
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Parameter<TArg>::template 
                CStr<char>().Size() + 8),
            "(%s, ...)", *(test::type::name::Parameter<TArg>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...)>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...);
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Parameter<TArg, TArgs...>::
                template CStr<char>().Size() + 8),
            "(%s, ...)", *(test::type::name::Parameter<
                TArg, TArgs...>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) &>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 3),
            "%s &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) &>
{
    typedef T SimpleType;
    typedef T Type(...) &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 3),
            "%s &", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) &>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 3),
            "%s &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) &>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 3),
            "%s &", *(test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) &&>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) &&>
{
    typedef T SimpleType;
    typedef T Type(...) &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) const;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 7),
            "%s const", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) const>
{
    typedef T SimpleType;
    typedef T Type(...) const;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 7),
            "%s const", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) const>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) const;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 7),
            "%s const", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) const;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 7),
            "%s const", *(test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const &>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) const &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 9),
            "%s const &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) const &>
{
    typedef T SimpleType;
    typedef T Type(...) const &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 9),
            "%s const &", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) const &>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) const &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 9),
            "%s const &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const &>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) const &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 9),
            "%s const &", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const &&>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) const &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 10),
            "%s const &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) const &&>
{
    typedef T SimpleType;
    typedef T Type(...) const &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 10),
            "%s const &&", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) const &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) const &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 10),
            "%s const &&", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) const &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 10),
            "%s const &&", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) volatile>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 10),
            "%s volatile", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) volatile>
{
    typedef T SimpleType;
    typedef T Type(...) volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 10),
            "%s volatile", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) volatile>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 10),
            "%s volatile", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) volatile>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 10),
            "%s volatile", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) volatile &>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) volatile &>
{
    typedef T SimpleType;
    typedef T Type(...) volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) volatile &>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) volatile &>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) volatile &&>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) volatile &&>
{
    typedef T SimpleType;
    typedef T Type(...) volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) volatile &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) volatile &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const volatile>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) const volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) const volatile>
{
    typedef T SimpleType;
    typedef T Type(...) const volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) const volatile>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) const volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const volatile>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) const volatile;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const volatile &>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) const volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) const volatile &>
{
    typedef T SimpleType;
    typedef T Type(...) const volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) const volatile &>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) const volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const volatile &>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) const volatile &;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const volatile &&>
{
    typedef T SimpleType;
    typedef T Type(TArgs...) const volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<char>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<char>()));
        return {_func};
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
struct Function<T(...) const volatile &&>
{
    typedef T SimpleType;
    typedef T Type(...) const volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(...)>::
                template CStr<char>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<T(...)>::
                template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg>
struct Function<T(TArg, ...) const volatile &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, ...) const volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<char>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<
                T(TArg, ...)>::template CStr<char>()));
        return {_func};
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

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const volatile &&>
{
    typedef T SimpleType;
    typedef T Type(TArg, TArgs..., ...) const volatile &&;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _func = test::cstr::Format<char>(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<char>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<char>()));
        return {_func};
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

#endif //!TEST_TYPE_NAME_FUNCTION_H_
