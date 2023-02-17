#ifndef TEST_DEF_CSTR_VAL_BOOLEAN_H_
#define TEST_DEF_CSTR_VAL_BOOLEAN_H_

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

struct Boolean
{
    template<typename TChar = char,typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static inline test::CString<const char> TrueCStr()
    {
        static char _val[] = "true";
        return {_val};
    };

    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static inline test::CString<const wchar_t> TrueCStr()
    {
        static wchar_t _val[] = L"true";
        return {_val};
    };

    template<typename TChar = char,typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 0>
    static inline test::CString<const char> FalseCStr()
    {
        static char _val[] = "false";
        return {_val};
    };

    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static inline test::CString<const wchar_t> FalseCStr()
    {
        static wchar_t _val[] = L"false";
        return {_val};
    };

    template<typename TChar>
    static inline test::CString<const TChar> CStr(bool val)
    {
        return val ? TrueCStr<TChar>() : FalseCStr<TChar>();
    };
};


} //!val

} //!cstr

} //!def

} //!test

#endif //!TEST_DEF_CSTR_VAL_BOOLEAN_H_
