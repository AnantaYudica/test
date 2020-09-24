#ifndef TEST_DEF_TYPE_NAME_NULLPTR_H_
#define TEST_DEF_TYPE_NAME_NULLPTR_H_

#include "../../../type/Name.h"
#include "../../../cstr/Format.h"

#include <cstddef>
#include <cwchar>
#include <type_traits>

namespace test
{
namespace type
{

template<>
struct Name<std::nullptr_t>
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _name[] = "std::nullptr_t";
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

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_NULLPTR_H_
