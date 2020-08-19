#ifndef TEST_DEF_TYPE_NAME_FLOATINGPOINT_H_
#define TEST_DEF_TYPE_NAME_FLOATINGPOINT_H_

#include "../../../type/Name.h"
#include "../../../cstr/Format.h"

namespace test
{
namespace type
{

template<typename TT>
struct Name<float, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 6),
            "float%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<double, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 7),
            "double%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

template<typename TT>
struct Name<long double, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::name::Declarator<TT>::CStr().Size() + 12),
            "long double%s", *(test::type::name::Declarator<TT>::CStr()));
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_ARRAY_H_
