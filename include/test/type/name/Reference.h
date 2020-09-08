#ifndef TEST_TYPE_NAME_REFERENCE_H_
#define TEST_TYPE_NAME_REFERENCE_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "Pointer.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Reference
{
    typedef T SimpleType;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar no_ref[] = "";
        return {no_ref};
    }
};

template<typename T>
struct Reference<T&>
{
    typedef typename test::type::name::Pointer<T>::SimpleType SimpleType;
    typedef T& Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ref = test::cstr::Format(
            (test::type::name::Pointer<T>::CStr().Size() + 2),
            "%s&", *(test::type::name::Pointer<T>::CStr()));
        return {_ref};
    }
};

template<typename T>
struct Reference<T&&>
{
    typedef typename test::type::name::Pointer<T>::SimpleType SimpleType;
    typedef T&& Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _ref = test::cstr::Format(
            (test::type::name::Pointer<T>::CStr().Size() + 3),
            "%s&&", *(test::type::name::Pointer<T>::CStr()));
        return {_ref};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_REFERENCE_H_
