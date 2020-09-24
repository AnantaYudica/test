#ifndef TEST_TYPE_NAME_TMPL_GET_H_
#define TEST_TYPE_NAME_TMPL_GET_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "../Parameter.h"

#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{
namespace tmpl
{

template<typename T>
struct Get
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char undefined[] = "parameter-undefined";
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

template<typename... TArgs>
struct Get<test::type::name::Parameter<TArgs...>>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _param = test::cstr::Format<char>(
            (test::type::name::Parameter<TArgs...>::
                template CStr<char>().Size() + 1),
            "%s", *(test::type::name::Parameter<TArgs...>::
                template CStr<char>()));
        return {_param};
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

} //!tmpl

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_TMPL_GET_H_
