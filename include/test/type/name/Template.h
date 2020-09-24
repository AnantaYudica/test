#ifndef TEST_TYPE_NAME_TEMPLATE_H_
#define TEST_TYPE_NAME_TEMPLATE_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "Value.h"
#include "Parameter.h"
#include "tmpl/Get.h"
#include "tmpl/Parameter.h"

#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename T, typename TP = 
    decltype(test::type::name::tmpl::Parameter(std::declval<T*>()))>
struct Template
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _tmpl = test::cstr::Format<char>((3 +
            test::type::name::tmpl::Get<TP>::template CStr<char>().Size()),
            "<%s>", *( test::type::name::tmpl::Get<TP>::template
                CStr<char>()));
        return {_tmpl};
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

#endif //!TEST_TYPE_NAME_TEMPLATE_H_
