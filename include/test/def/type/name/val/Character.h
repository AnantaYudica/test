#ifndef TEST_DEF_TYPE_NAME_VAL_CHARACTER_H_
#define TEST_DEF_TYPE_NAME_VAL_CHARACTER_H_

#include "../../../../CString.h"
#include "../../../../cstr/Format.h"
#include "../../../../type/name/val/Get.h"

#include <cstdint>
#include <cmath>

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<>
struct Get<signed char>
{
    template<signed char V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : (V < 0 ? (log10(fabs(V)) + 3) : 2)), 
            "%hhd", V);
        return {_val};
    }
};

template<>
struct Get<char>
{
    template<char V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(2, "%c", V);
        return {_val};
    }
};

template<>
struct Get<unsigned char>
{
    template<unsigned char V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : 2), "%hhu", V);
        return {_val};
    }
};

} //!val

} //!name

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_VAL_CHARACTER_H_