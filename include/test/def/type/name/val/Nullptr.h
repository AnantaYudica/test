#ifndef TEST_DEF_TYPE_NAME_VAL_NULLPTR_H_
#define TEST_DEF_TYPE_NAME_VAL_NULLPTR_H_

#include "../../../../CString.h"
#include "../../../../type/name/val/Get.h"
#include "../../../../type/name/val/Get.h"

#include <cstddef>
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

template<>
struct Get<std::nullptr_t>
{
    template<std::nullptr_t V, typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<char> CStr()
    {
        static char _val[] = "nullptr";
        return {_val};
    }
    template<std::nullptr_t V, typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
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


#endif //!TEST_DEF_TYPE_NAME_VAL_NULLPTR_H_
