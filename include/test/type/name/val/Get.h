#ifndef TEST_TYPE_NAME_VAL_GET_H_
#define TEST_TYPE_NAME_VAL_GET_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<typename T>
struct Get
{
    template<typename TChar= char>
    static test::CString<TChar> CStr(T)
    {
        static TChar undefined[] = "value-undefined";
        return {undefined};
    }
};

template<typename T>
struct Get<T&>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr(T& v)
    {
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(int*) * 2) + 3, "%p", &v);
        return {_val};
    }
};

template<typename T>
struct Get<T*>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr(T* v)
    {
        test::CString<TChar> _val = test::cstr::Format(
            (sizeof(int*) * 2) + 3, "%p", v);
        return {_val};
    }
};

} //!val

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VAL_GET_H_