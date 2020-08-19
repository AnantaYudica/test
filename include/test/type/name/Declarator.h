#ifndef TEST_TYPE_NAME_DECLARATOR_H_
#define TEST_TYPE_NAME_DECLARATOR_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "Pointer.h"
#include "Reference.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Declarator
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        return {test::type::name::Pointer<T>::template CStr<TChar>()};
    }
};

template<typename T>
struct Declarator<T&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _declarator = test::cstr::Format(
            (test::type::name::Pointer<T>::template CStr<TChar>().Size() + 1 +
                test::type::name::Reference<T&>::template CStr<TChar>().Size()),
            "%s%s", *(test::type::name::Pointer<T>::template CStr<TChar>()),
                *(test::type::name::Reference<T&>::template CStr<TChar>()));
        return {_declarator};
    }
};

template<typename T>
struct Declarator<T&&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<char> _declarator = test::cstr::Format(
            (test::type::name::Pointer<T>::template CStr<TChar>().Size() + 1 +
                test::type::name::Reference<T&&>::template CStr<TChar>().Size()),
            "%s%s", *(test::type::name::Pointer<T>::template CStr<TChar>()),
                *(test::type::name::Reference<T&&>::template CStr<TChar>()));
        return {_declarator};
    }
};



} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLARATOR_H_
