#ifndef TEST_TYPE_NAME_DECLTOR_PARAMETER_H_
#define TEST_TYPE_NAME_DECLTOR_PARAMETER_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "../Array.h"
#include "../Function.h"
#include "../Pointer.h"
#include "../Reference.h"

#include <type_traits>
#include <cwchar>

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
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char _decltor[] = "";
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T>
struct Parameter<test::type::name::Array<T>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (test::type::name::Array<T>::template CStr<char>().Size() + 1),
            "%s", *(test::type::name::Array<T>::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Array<T>, TArgs...>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::Array<T> ArrayType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (ParamType::template CStr<char>().Size() + 
                ArrayType::template CStr<char>().Size() + 3),
            "(%s)%s", *(ParamType::template CStr<char>()), 
            *(ArrayType::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T>
struct Parameter<test::type::name::Function<T>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (test::type::name::Function<T>::template CStr<char>().Size() + 1),
            "%s", *(test::type::name::Function<T>::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Function<T>, TArgs...>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::Function<T> FunctionType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (ParamType::template CStr<char>().Size() + 
                FunctionType::template CStr<char>().Size() + 3),
            "(%s)%s", *(ParamType::template CStr<char>()), 
            *(FunctionType::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T>
struct Parameter<test::type::name::Pointer<T>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (test::type::name::Pointer<T>::template CStr<char>().Size() + 1),
            "%s", *(test::type::name::Pointer<T>::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Pointer<T>, TArgs...>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::Pointer<T> PointerType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (PointerType::template CStr<char>().Size() + 
                ParamType::template CStr<char>().Size() + 1),
            "%s%s", *(PointerType::template CStr<char>()), 
            *(ParamType::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T1, typename T2, typename... TArgs>
struct Parameter<test::type::name::Pointer<T1>, 
    test::type::name::Pointer<T2>, TArgs...>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::Pointer<T1> PointerType;
        typedef test::type::name::decltor::Parameter<
            test::type::name::Pointer<T2>, TArgs...> ParamType;
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (PointerType::template CStr<char>().Size() + 
                ParamType::template CStr<char>().Size() + 2),
            "%s %s", *(PointerType::template CStr<char>()), 
            *(ParamType::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T>
struct Parameter<test::type::name::Reference<T>>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (test::type::name::Reference<T>::template CStr<char>().Size()) +
                1, "%s", 
            *(test::type::name::Reference<T>::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

template<typename T, typename... TArgs>
struct Parameter<test::type::name::Reference<T>, TArgs...>
{
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef test::type::name::Reference<T> ReferenceType;
        typedef test::type::name::decltor::Parameter<TArgs...> ParamType;
        static test::CString<char> _decltor = test::cstr::Format<char>(
            (ReferenceType::template CStr<char>().Size() + 
                ParamType::template CStr<char>().Size() + 1),
            "%s%s", *(ReferenceType::template CStr<char>()), 
            *(ParamType::template CStr<char>()));
        return {_decltor};
    }
    template<typename TChar = char, typename std::enable_if<
        !std::is_same<TChar, char>::value &&
        std::is_same<TChar, wchar_t>::value, int>::type = 0>
    static test::CString<wchar_t> CStr()
    {
        const auto cstr = CStr<char>();
        return test::cstr::Format<wchar_t>(cstr.Size() + 1, L"%s", *cstr);
    }
};

} //!decltor

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLTOR_PARAMETER_H_
