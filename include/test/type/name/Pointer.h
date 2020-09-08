#ifndef TEST_TYPE_NAME_POINTER_H_
#define TEST_TYPE_NAME_POINTER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"

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
    typedef T SimpleType;
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
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T* Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(2 +
            (test::type::name::Pointer<T>::template CStr<TChar>().Size()),
            "%s*", *(test::type::name::Pointer<T>::template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T>
struct Pointer<T*const>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T*const Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::template CStr<TChar>().Size() + 7),
            "%s*const", *(test::type::name::Pointer<T>::
                template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T>
struct Pointer<T*volatile>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T*volatile Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::template CStr<TChar>().Size() + 10),
            "%s*volatile", *(test::type::name::Pointer<T>::
                template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T>
struct Pointer<T*const volatile>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T*const volatile Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::name::Pointer<T>::template CStr<TChar>().Size() + 16),
            "%s*const volatile", *(test::type::name::Pointer<T>::
                template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T, typename TM>
struct Pointer<T TM::*>
{
    typedef T SimpleType;
    typedef T TM::* Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::Name<TM>::template CStr<TChar>().Size() + 4),
            "%s::*", *(test::type::Name<TM>::template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T, typename TM>
struct Pointer<T TM::*const>
{
    typedef T SimpleType;
    typedef T TM::*const Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::Name<TM>::template CStr<TChar>().Size() + 9),
            "%s::*const", *(test::type::Name<TM>::template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T, typename TM>
struct Pointer<T TM::*volatile>
{
    typedef T SimpleType;
    typedef T TM::*volatile Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::Name<TM>::template CStr<TChar>().Size() + 12),
            "%s::*volatile", *(test::type::Name<TM>::template CStr<TChar>()));
        return {_ptr};
    }
};

template<typename T, typename TM>
struct Pointer<T TM::*const volatile>
{
    typedef T SimpleType;
    typedef T TM::*const volatile Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ptr = test::cstr::Format(
            (test::type::Name<TM>::template CStr<TChar>().Size() + 18),
            "%s::*const volatile", *(test::type::Name<TM>::
                template CStr<TChar>()));
        return {_ptr};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_POINTER_H_
