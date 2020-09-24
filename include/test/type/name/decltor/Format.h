#ifndef TEST_TYPE_NAME_DECLTOR_FORMAT_H_
#define TEST_TYPE_NAME_DECLTOR_FORMAT_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "../../Name.h"
#include "../Qualifier.h"
#include "Parameter.h"

#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{
namespace decltor
{

template<typename TQ, typename TN, typename TParam>
struct Format
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char _fmt[] = "format undefined";
        return {_fmt};
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

template<typename TN>
struct Format<TN, TN, test::type::name::decltor::Parameter<>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _fmt = test::cstr::Format<char>(
            (test::type::Name<TN>::template CStr<char>().Size() + 1),
            "%s", *(test::type::Name<TN>::template CStr<char>()));
        return {_fmt};
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

template<typename TN, typename TArg, typename... TArgs>
struct Format<TN, TN, test::type::name::decltor::Parameter<TArg, TArgs...>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::decltor::Parameter<TArg, TArgs...> ParamType;
        static test::CString<char> _fmt = test::cstr::Format<char>(
            (test::type::Name<TN>::template CStr<char>().Size() +
                ParamType::template CStr<char>().Size() + 2),
            "%s %s", *(test::type::Name<TN>::template CStr<char>()),
            *(ParamType::template CStr<char>()));
        return {_fmt};
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

template<typename TQ, typename TN>
struct Format<TQ, TN, test::type::name::decltor::Parameter<>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _fmt = test::cstr::Format<char>(
            (test::type::name::Qualifier<TQ>::template CStr<char>().Size() +
                test::type::Name<TN>::template CStr<char>().Size() + 2),
            "%s %s", *(test::type::name::Qualifier<TQ>::
                template CStr<char>()),
            *(test::type::Name<TN>::template CStr<char>()));
        return {_fmt};
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

template<typename TQ, typename TN, typename TArg, typename... TArgs>
struct Format<TQ, TN, test::type::name::decltor::Parameter<TArg, TArgs...>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::decltor::Parameter<TArg, TArgs...> ParamType;
        static test::CString<char> _fmt = test::cstr::Format<char>(
            (test::type::name::Qualifier<TQ>::template CStr<char>().Size() +
                test::type::Name<TN>::template CStr<char>().Size() +
                ParamType::template CStr<char>().Size() + 3), "%s %s %s", 
            *(test::type::name::Qualifier<TQ>::template CStr<char>()),
            *(test::type::Name<TN>::template CStr<char>()),
            *(ParamType::template CStr<char>()));
        return {_fmt};
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

} //!decltor

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLTOR_FORMAT_H_
