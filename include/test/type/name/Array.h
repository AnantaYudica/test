#ifndef TEST_TYPE_NAME_ARRAY_H_
#define TEST_TYPE_NAME_ARRAY_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"

#include <cstddef>
#include <cmath>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Array
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar no_arr[] = "";
        return {no_arr};
    }
};

template<typename T>
struct Array<T[]>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _arr[] = "[]";
        return {_arr};
    }
};

template<typename T, std::size_t N>
struct Array<T[N]>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _arr = test::cstr::Format(
            (static_cast<std::size_t>(log10(N)) + 4), "[%d]", N);
        return {_arr};
    }
};

} //!name

} //!type

} //!test


#endif //!TEST_TYPE_NAME_ARRAY_H_
