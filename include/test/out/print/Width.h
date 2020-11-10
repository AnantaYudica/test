#ifndef TEST_OUT_PRINT_WIDTH_H_
#define TEST_OUT_PRINT_WIDTH_H_

#include "../fmt/Flag.h"
#include "../../CString.h"
#include "../../cstr/Format.h"

#include <cmath>
#include <cwchar>
#include <cstddef>
#include <type_traits>

namespace test
{
namespace out
{
namespace print
{

struct Width
{
    typedef test::out::fmt::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value ||
            std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, ...)
    {
        return val_cstr;
    }

    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<std::is_same<TChar, char>::value &&
            FlagType{IFormat}.IsSpecifierSubWidth(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const int& size)
    {
        const int size_cstr = std::abs(size) < val_cstr.Size() ? 
            val_cstr.Size() : std::abs(size);
        return test::cstr::Format<TChar>(size_cstr + 1, "%*s", 
                size, *val_cstr);
    }
    
    template<typename TChar = char, IntegerValueType IFormat = 0,
        typename std::enable_if<!std::is_same<TChar, char>::value &&
            std::is_same<TChar, wchar_t>::value &&
            FlagType{IFormat}.IsSpecifierSubWidth(), int>::type = 0>
    static test::CString<TChar> CStr(const test::CString<TChar>& val_cstr, 
        const int& size)
    {
        const int size_cstr = std::abs(size) < val_cstr.Size() ? 
            val_cstr.Size() : std::abs(size);
        return test::cstr::Format<TChar>(size_cstr + 1, L"%*ls", 
                size, *val_cstr);
    }
};

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_WIDTH_H_
