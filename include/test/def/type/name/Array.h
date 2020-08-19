#ifndef TEST_DEF_TYPE_NAME_ARRAY_H_
#define TEST_DEF_TYPE_NAME_ARRAY_H_

#include "../../../type/Name.h"
#include "../../../type/name/Declarator.h"
#include "../../../type/name/Reference.h"
#include "../../../cstr/Format.h"

#include <cmath>

namespace test
{
namespace type
{

template<typename T, std::size_t N>
struct Name<T[N], test::type::name::Declarator<T[N]>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 
                static_cast<std::size_t>(log10(N)) + 4),
            "%s[%d]", *(test::type::Name<T>::CStr()), N);
        return {_name};
    }
};

template<typename T, std::size_t N, typename TT>
struct Name<T[N], test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 
                static_cast<std::size_t>(log10(N)) + 
                test::type::name::Declarator<TT>::CStr().Size() + 6),
            "%s(%s)[%d]", *(test::type::Name<T>::CStr()),
            *(test::type::name::Declarator<TT>::CStr()), N);
        return {_name};
    }
};

template<typename T>
struct Name<T[], test::type::name::Declarator<T[]>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 3), 
            "%s[]", *(test::type::Name<T>::CStr()));
        return {_name};
    }
};

template<typename T, typename TT>
struct Name<T[], test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 
                test::type::name::Declarator<TT>::CStr().Size() + 5), 
            "%s(%s)[]", *(test::type::Name<T>::CStr()), 
            *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_ARRAY_H_
