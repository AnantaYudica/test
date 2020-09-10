#ifndef TEST_DEF_CSTR_VAL_NULLPTR_H_
#define TEST_DEF_CSTR_VAL_NULLPTR_H_

#include "../../../CString.h"

#include <cwchar>
#include <type_traits>

namespace test
{
namespace def
{
namespace cstr
{
namespace val
{

struct Nullptr
{
    template<typename TChar = char,typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const TChar> CStr()
    {
        static char _val[] = "(null)";
        return {_val};
    };

    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<const TChar> CStr()
    {
        static wchar_t _val[] = L"(null)";
        return {_val};
    };
};


} //!val

} //!cstr

} //!def

} //!test

#endif //!TEST_DEF_CSTR_VAL_NULLPTR_H_