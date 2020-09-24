#ifndef TEST_TYPE_NAME_DECLARATOR_H_
#define TEST_TYPE_NAME_DECLARATOR_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "Pointer.h"
#include "Reference.h"
#include "Array.h"
#include "Function.h"
#include "Qualifier.h"
#include "Declarator.decl.h"
#include "decltor/Format.h"
#include "decltor/Parameter.h"

#include <cstddef>
#include <type_traits>
#include <cwchar>

namespace test
{
namespace type
{
namespace name
{

template<typename T, typename TB, typename... TArgs>
struct Declarator
{
    typedef T DefaultType;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        return {test::type::name::decltor::Format<T,
            typename test::type::name::Qualifier<TB>::SimpleType,
            test::type::name::decltor::Parameter<TArgs...>>::
                template CStr<char>()};
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
struct Declarator<T, typename test::type::name::Array<T>::Type, TArgs...>
{
    typedef T Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef typename test::type::name::Array<T>::SimpleType SimpleType;
        return {Declarator<SimpleType, SimpleType, 
            test::type::name::Array<T>, TArgs...>::template CStr<char>()};
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
struct Declarator<T, typename test::type::name::Function<T>::Type, TArgs...>
{
    typedef T Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef typename test::type::name::Function<T>::SimpleType SimpleType;
        return {Declarator<SimpleType, SimpleType, 
            test::type::name::Function<T>, TArgs...>::template CStr<char>()};
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
struct Declarator<T, typename test::type::name::Pointer<T>::Type, TArgs...>
{
    typedef T Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef typename test::type::name::Pointer<T>::SimpleType SimpleType;
        return {Declarator<SimpleType, SimpleType, 
            test::type::name::Pointer<T>, TArgs...>::template CStr<char>()};
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
struct Declarator<T, typename test::type::name::Reference<T>::Type, TArgs...>
{
    typedef T Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        typedef typename test::type::name::Reference<T>::SimpleType SimpleType;
        return {Declarator<SimpleType, SimpleType, 
            test::type::name::Reference<T>, TArgs...>::template CStr<char>()};
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

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLARATOR_H_
