#ifndef TEST_TYPE_NAME_H_
#define TEST_TYPE_NAME_H_

#include "../CString.h"
#include "../trait/type/name/decltor/Enable.decl.h"
#include "name/Declarator.decl.h"

#include <cstddef>

namespace test
{
namespace type
{

template<typename T, typename TDeclarator = test::type::name::Declarator<T>>
struct Name
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char undefined[] = "undefined";
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

template<typename T>
struct Name<T, typename test::trait::type::name::decltor::Enable<T>::Type>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        return {test::type::name::Declarator<T>::template CStr<char>()};
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

#include "name/Declarator.h"
#include "../trait/type/name/decltor/Enable.h"

#endif //!TEST_TYPE_NAME_H_
