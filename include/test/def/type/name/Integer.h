#ifndef TEST_DEF_TYPE_NAME_INTEGER_H_
#define TEST_DEF_TYPE_NAME_INTEGER_H_

#include "../../../type/Name.h"
#include "../../../cstr/Format.h"

namespace test
{
namespace type
{

template<typename TT>
struct Name<signed char, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 12),
            "signed char%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<char, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 5),
            "char%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<short, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 6),
            "short%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<int, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 4),
            "int%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<long, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 5),
            "long%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<long long, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 10),
            "long long%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<unsigned char, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 14),
            "unsigned char%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<unsigned short, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 15),
            "unsigned short%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<unsigned int, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 13),
            "unsigned int%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<unsigned long, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 14),
            "unsigned long%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<unsigned long long, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 19),
            "unsigned long long%s", 
            *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_INTEGER_H_
