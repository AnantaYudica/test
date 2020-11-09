#ifndef TEST_DEF_CSTR_VAL_NUM_PREFIX_H_
#define TEST_DEF_CSTR_VAL_NUM_PREFIX_H_

#include "../../../../CString.h"
#include "../../../../cstr/Format.h"
#include "../Empty.h"

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

struct Prefix
{
    template<typename TChar = char, std::size_t NBase = 10,
        bool BLower = true, typename std::enable_if<
            std::is_same<TChar, char>::value && NBase == 10, int>::type = 0>
    static test::CString<const char> CStr()
    {
        return test::def::cstr::val::Empty::CStr<TChar>();
    };
    
    template<typename TChar = char, std::size_t NBase = 10,
        bool BLower = true, typename std::enable_if<
            std::is_same<TChar, char>::value && NBase == 16 &&
            BLower == true, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "0x";
        return {_val};
    };
    
    template<typename TChar = char, std::size_t NBase = 10,
        bool BLower = true, typename std::enable_if<
            std::is_same<TChar, char>::value && NBase == 16 &&
            BLower == false, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "0X";
        return {_val};
    };

    template<typename TChar = char, std::size_t NBase = 10,
        bool BLower = true, typename std::enable_if<
            std::is_same<TChar, char>::value && NBase == 8, int>::type = 0>
    static test::CString<const char> CStr()
    {
        static char _val[] = "0";
        return {_val};
    };
    
    template<typename TChar = char, std::size_t NBase = 10,
        bool BLower = true, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char, NBase, BLower>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    };
};

} //!num

} //!val

} //!cstr

} //!def

} //!test

#endif //!TEST_DEF_CSTR_VAL_NUM_PREFIX_H_
