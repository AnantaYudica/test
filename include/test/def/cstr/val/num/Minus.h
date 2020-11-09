#ifndef TEST_DEF_CSTR_VAL_NUM_MINUS_H_
#define TEST_DEF_CSTR_VAL_NUM_MINUS_H_

#include "../../../../CString.h"
#include "../../../../cstr/Format.h"

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
namespace num
{

struct Minus
{
    template<typename TChar = char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "-";
        return {_val};
    };
    
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    };
};

} //!num

} //!val

} //!cstr

} //!def

} //!test

#endif //!TEST_DEF_CSTR_VAL_NUM_MINUS_H_
