#ifndef TEST_TYPE_NAME_DECLTOR_PARAMETER_H_
#define TEST_TYPE_NAME_DECLTOR_PARAMETER_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "../Array.h"
#include "../Function.h"
#include "../Pointer.h"
#include "../Reference.h"

namespace test
{
namespace type
{
namespace name
{
namespace decltor
{

template<typename... TArgs>
struct Parameter
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _decltor[] = "";
        return {_decltor};
    }
};

template<typename T>
struct Parameter<test::type::name::Array<T>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _decltor = test::cstr::Format(
            (test::type::name::Array<T>::template CStr<TChar>().Size() + 1),
            "%s", *(test::type::name::Array<T>::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Array<T>, TArgs...>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef test::type::name::Array<T> ArrayType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<TChar> _decltor = test::cstr::Format(
            (ParamType::template CStr<TChar>().Size() + 
                ArrayType::template CStr<TChar>().Size() + 3),
            "(%s)%s", *(ParamType::template CStr<TChar>()), 
            *(ArrayType::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T>
struct Parameter<test::type::name::Function<T>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _decltor = test::cstr::Format(
            (test::type::name::Function<T>::template CStr<TChar>().Size() + 1),
            "%s", *(test::type::name::Function<T>::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Function<T>, TArgs...>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef test::type::name::Function<T> FunctionType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<TChar> _decltor = test::cstr::Format(
            (ParamType::template CStr<TChar>().Size() + 
                FunctionType::template CStr<TChar>().Size() + 3),
            "(%s)%s", *(ParamType::template CStr<TChar>()), 
            *(FunctionType::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T>
struct Parameter<test::type::name::Pointer<T>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _decltor = test::cstr::Format(
            (test::type::name::Pointer<T>::template CStr<TChar>().Size() + 1),
            "%s", *(test::type::name::Pointer<T>::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Pointer<T>, TArgs...>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef test::type::name::Pointer<T> PointerType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<TChar> _decltor = test::cstr::Format(
            (PointerType::template CStr<TChar>().Size() + 
                ParamType::template CStr<TChar>().Size() + 1),
            "%s%s", *(PointerType::template CStr<TChar>()), 
            *(ParamType::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T>
struct Parameter<test::type::name::Reference<T>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _decltor = test::cstr::Format(1 +
            (test::type::name::Reference<T>::template CStr<TChar>().Size()),
            "%s", *(test::type::name::Reference<T>::template CStr<TChar>()));
        return {_decltor};
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Reference<T>, TArgs...>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef test::type::name::Reference<T> ReferenceType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<TChar> _decltor = test::cstr::Format(
            (ReferenceType::template CStr<TChar>().Size() + 
                ParamType::template CStr<TChar>().Size() + 1),
            "%s%s", *(ReferenceType::template CStr<TChar>()), 
            *(ParamType::template CStr<TChar>()));
        return {_decltor};
    }
};

} //!decltor

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLTOR_PARAMETER_H_
