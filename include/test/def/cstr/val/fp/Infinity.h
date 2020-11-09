#ifndef TEST_DEF_CSTR_VAL_FP_INFINITY_H_
#define TEST_DEF_CSTR_VAL_FP_INFINITY_H_

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
namespace fp
{

struct Infinity
{
    template<typename TChar = char, bool BLower = true, 
        typename std::enable_if<std::is_same<TChar, char>::value &&
        BLower == true, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "inf";
        return {_val};
    };

    template<typename TChar = char, bool BLower = true, 
        typename std::enable_if<std::is_same<TChar, char>::value &&
        BLower == false, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "INF";
        return {_val};
    };

    template<typename TChar = char, bool BLower = true, 
        typename std::enable_if<!std::is_same<TChar, char>::value &&
            std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char, BLower>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    };
};

} //!fp

} //!val

} //!cstr

} //!def

} //!test

#endif //!TEST_DEF_CSTR_VAL_FP_INFINITY_H_
