#ifndef TEST_DEF_TYPE_NAME_QUALIFIER_H_
#define TEST_DEF_TYPE_NAME_QUALIFIER_H_

#include "../../../type/Name.h"
#include "../../../cstr/Format.h"

namespace test
{
namespace type
{

template<typename T, typename TT>
struct Name<const T, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 7 +
                test::type::name::Declarator<TT>::CStr().Size()),
            "const %s%s", *(test::type::Name<T>::CStr()),
                *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename T, typename TT>
struct Name<volatile T, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 10 +
                test::type::name::Declarator<TT>::CStr().Size()),
            "volatile %s%s", *(test::type::Name<T>::CStr()),
                *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename T, typename TT>
struct Name<const volatile T, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<T>::CStr().Size() + 16 +
                test::type::name::Declarator<TT>::CStr().Size()),
            "const volatile %s%s", *(test::type::Name<T>::CStr()),
                *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_QUALIFIER_H_
