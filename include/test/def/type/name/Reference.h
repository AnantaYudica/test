#ifndef TEST_DEF_TYPE_NAME_REFERENCE_H_
#define TEST_DEF_TYPE_NAME_REFERENCE_H_

#include "../../../type/Name.h"
#include "../../../cstr/Format.h"

namespace test
{
namespace type
{

template<typename T, typename TT>
struct Name<T&, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        return {test::type::Name<T, 
            test::type::name::Declarator<TT>>::CStr()};
    }
};

template<typename T, typename TT>
struct Name<T&&, test::type::name::Declarator<TT>>
{
    static test::CString<const char> CStr()
    {
        return {test::type::Name<T, 
            test::type::name::Declarator<TT>>::CStr()};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_REFERENCE_H_
