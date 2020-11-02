#ifndef TEST_DEF_CSTR_VAL_FP_EXPONENT_H_
#define TEST_DEF_CSTR_VAL_FP_EXPONENT_H_

#include "../../../../CString.h"

#include <cwchar>
#include <type_traits>
#include <cstddef>

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

struct Exponent
{
    template<typename TChar = char, std::size_t NBase = 10, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
        BLower == true && NBase == 10, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "e";
        return {_val};
    };

    template<typename TChar = char, std::size_t NBase = 10, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
        BLower == true && NBase == 2, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "p";
        return {_val};
    };

     template<typename TChar = char, std::size_t NBase = 10, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
        BLower == false && NBase == 10, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "E";
        return {_val};
    };

    template<typename TChar = char, std::size_t NBase = 10, bool BLower = true,
        typename std::enable_if<std::is_same<TChar, char>::value &&
        BLower == false && NBase == 2, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "P";
        return {_val};
    };

    template<typename TChar = char, std::size_t NBase = 10, bool BLower = true,
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

#endif //!TEST_DEF_CSTR_VAL_FP_EXPONENT_H_
