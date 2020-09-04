#ifndef TEST_CSTR_LENGTH_H_
#define TEST_CSTR_LENGTH_H_

#include "../CString.h"

#include <cstring>
#include <cwchar>
#include <utility>
#include <type_traits>

namespace test
{
namespace cstr
{

template<typename TChar, typename T>
struct Length
{
};

template<std::size_t N>
struct Length<wchar_t, wchar_t[N]>
{
    static std::size_t Value(const wchar_t *)
    {
        return N - 1;
    }
};

template<std::size_t N>
struct Length<char, char[N]>
{
    static std::size_t Value(const char *)
    {
        return N - 1;
    }
};

template<>
struct Length<wchar_t, wchar_t*>
{
    static std::size_t Value(const wchar_t * str)
    {
        return wcslen(str);
    }
};

template<>
struct Length<char, char*>
{
    static std::size_t Value(const char * str)
    {
        return strlen(str);
    }
};

template<typename TChar, typename T>
struct Length<TChar, T*>
{
    static std::size_t Value(const TChar * str)
    {
        return Length<TChar, 
            typename std::remove_cv<T>::type*>::Value(str);
    }
};

template<typename TChar, typename T>
struct Length<TChar, T&>
{
    static std::size_t Value(const TChar * str)
    {
        return Length<TChar, 
            typename std::remove_cv<T>::type>::Value(str);
    }
};

template<typename TChar, typename T>
struct Length<TChar, T&&>
{
    static std::size_t Value(const TChar * str)
    {
        return Length<TChar, 
            typename std::remove_cv<T>::type>::Value(str);
    }
};

} //!cstr

} //!test

#endif //!TEST_CSTR_LENGTH_H_