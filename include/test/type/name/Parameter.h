#ifndef TEST_TYPE_NAME_PARAMETER_H_
#define TEST_TYPE_NAME_PARAMETER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "Value.h"

#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename... TArgs>
struct Parameter
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char _name[] = "";
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

template<typename TArg>
struct Parameter<TArg>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format<char>(
            (test::type::Name<TArg>::template CStr<char>().Size() + 1),
            "%s", *(test::type::Name<TArg>::template CStr<char>()));
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

template<typename TArg0, typename TArg1, typename... TArgs>
struct Parameter<TArg0, TArg1, TArgs...>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format<char>(
            (test::type::Name<TArg0>::template CStr<char>().Size() + 3 +
                test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<char>().Size()),
            "%s, %s", *(test::type::Name<TArg0>::template CStr<char>()),
            *(test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<char>()));
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

template<typename T, T V>
struct Parameter<test::type::name::Value<T, V>>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        return {test::type::name::Value<T, V>::template CStr<char>()};
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

template<typename T, T V, typename TArg1, typename... TArgs>
struct Parameter<test::type::name::Value<T, V>, TArg1, TArgs...>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format<char>(
            (test::type::name::Value<T, V>::template CStr<char>().Size() + 3 +
                test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<char>().Size()),
            "%s, %s", *(test::type::name::Value<T, V>::template CStr<char>()),
            *(test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<char>()));
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

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_PARAMETER_H_
