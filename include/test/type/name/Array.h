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
    typedef T SimpleType;
    typedef T Type[];
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
    typedef T SimpleType;
    typedef T Type[N];
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _arr = test::cstr::Format(
            (static_cast<std::size_t>(log10(N)) + 4), "[%d]", N);
        return {_arr};
    }
};

template<typename T, std::size_t N, std::size_t M>
struct Array<T[N][M]>
{
    typedef typename Array<T[M]>::SimpleType SimpleType;
    typedef T Type[N][M];
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _arr = test::cstr::Format(
            (static_cast<std::size_t>(log10(N)) +
                Array<T[M]>::template CStr<TChar>().Size() + 4), "[%d]%s", 
            N, *(Array<T[M]>::template CStr<TChar>()));
        return {_arr};
    }
};

} //!name

} //!type

} //!test


#endif //!TEST_TYPE_NAME_ARRAY_H_
