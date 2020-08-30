#ifndef TEST_DEF_TYPE_NAME_VAL_INTEGER_H_
#define TEST_DEF_TYPE_NAME_VAL_INTEGER_H_

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
struct Get<short>
{
    template<short V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : (V < 0 ? (log10(fabs(V)) + 3) : 2)), 
            "%hd", V);
        return {_val};
    }
};

template<>
struct Get<unsigned short>
{
    template<unsigned short V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : 2), "%hu", V);
        return {_val};
    }
};

template<>
struct Get<int>
{
    template<int V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : (V < 0 ? (log10(fabs(V)) + 3) : 2)), 
            "%d", V);
        return {_val};
    }
};

template<>
struct Get<unsigned int>
{
    template<unsigned int V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : 2), "%u", V);
        return {_val};
    }
};

template<>
struct Get<long>
{
    template<long V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : (V < 0 ? (log10(fabs(V)) + 3) : 2)), 
            "%ld", V);
        return {_val};
    }
};

template<>
struct Get<unsigned long>
{
    template<unsigned long V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : 2), "%lu", V);
        return {_val};
    }
};

template<>
struct Get<long long>
{
    template<long long V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
       test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : (V < 0 ? (log10(fabs(V)) + 3) : 2)), 
            "%lld", V);
        return {_val};
    }
};

template<>
struct Get<unsigned long long>
{
    template<unsigned long long V, typename TChar= char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 2) : 2), "%llu", V);
        return {_val};
    }
};


} //!val

} //!name

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_VAL_INTEGER_H_