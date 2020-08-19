#ifndef TEST_TYPE_NAME_POINTER_H_
#define TEST_TYPE_NAME_POINTER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Pointer
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar no_ptr[] = "";
        return {no_ptr};
    }
};

template<typename T>
struct Pointer<T*>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::CStr().Size() + 2),
            "%s*", *(test::type::name::Pointer<T>::CStr()));
        return {_ptr};
    }
};

template<typename T>
struct Pointer<T*const>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::CStr().Size() + 7),
            "%s*const", *(test::type::name::Pointer<T>::CStr()));
        return {_ptr};
    }
};

template<typename T>
struct Pointer<T*volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::CStr().Size() + 10),
            "%s*volatile", *(test::type::name::Pointer<T>::CStr()));
        return {_ptr};
    }
};

template<typename T>
struct Pointer<T*const volatile>
{
    template<typename TChar= char>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::CStr().Size() + 16),
            "%s*const volatile", *(test::type::name::Pointer<T>::CStr()));
        return {_ptr};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_POINTER_H_
