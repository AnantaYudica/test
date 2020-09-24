#ifndef TEST_TYPE_NAME_POINTER_H_
#define TEST_TYPE_NAME_POINTER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"

#include <cstddef>
#include <type_traits>
#include <cwchar>

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
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static char no_ptr[] = "";
        return {no_ptr};
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
struct Pointer<T*>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T* Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(2 +
            (test::type::name::Pointer<T>::template CStr<char>().Size()),
            "%s*", *(test::type::name::Pointer<T>::template CStr<char>()));
        return {_ptr};
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
struct Pointer<T*const>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T*const Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::name::Pointer<T>::template CStr<char>().Size() + 7),
            "%s*const", *(test::type::name::Pointer<T>::
                template CStr<char>()));
        return {_ptr};
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
struct Pointer<T*volatile>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T*volatile Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::name::Pointer<T>::template CStr<char>().Size() + 10),
            "%s*volatile", *(test::type::name::Pointer<T>::
                template CStr<char>()));
        return {_ptr};
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
struct Pointer<T*const volatile>
{
    typedef typename Pointer<T>::SimpleType SimpleType;
    typedef T*const volatile Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::name::Pointer<T>::template CStr<char>().Size() + 16),
            "%s*const volatile", *(test::type::name::Pointer<T>::
                template CStr<char>()));
        return {_ptr};
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

template<typename T, typename TM>
struct Pointer<T TM::*>
{
    typedef T SimpleType;
    typedef T TM::* Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::Name<TM>::template CStr<char>().Size() + 4),
            "%s::*", *(test::type::Name<TM>::template CStr<char>()));
        return {_ptr};
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

template<typename T, typename TM>
struct Pointer<T TM::*const>
{
    typedef T SimpleType;
    typedef T TM::*const Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::Name<TM>::template CStr<char>().Size() + 9),
            "%s::*const", *(test::type::Name<TM>::template CStr<char>()));
        return {_ptr};
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

template<typename T, typename TM>
struct Pointer<T TM::*volatile>
{
    typedef T SimpleType;
    typedef T TM::*volatile Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::Name<TM>::template CStr<char>().Size() + 12),
            "%s::*volatile", *(test::type::Name<TM>::template CStr<char>()));
        return {_ptr};
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

template<typename T, typename TM>
struct Pointer<T TM::*const volatile>
{
    typedef T SimpleType;
    typedef T TM::*const volatile Type;
    template<typename TChar= char, typename std::enable_if<
        std::is_same<TChar, char>::value, int>::type = 1>
    static test::CString<const char> CStr()
    {
        static test::CString<char> _ptr = test::cstr::Format<char>(
            (test::type::Name<TM>::template CStr<char>().Size() + 18),
            "%s::*const volatile", *(test::type::Name<TM>::
                template CStr<char>()));
        return {_ptr};
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

#endif //!TEST_TYPE_NAME_POINTER_H_
