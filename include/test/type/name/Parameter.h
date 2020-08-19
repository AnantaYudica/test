#ifndef TEST_TYPE_NAME_PARAMETER_H_
#define TEST_TYPE_NAME_PARAMETER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"

namespace test
{
namespace type
{
namespace name
{

template<typename... TArgs>
struct Parameter
{
    static test::CString<const char> CStr()
    {
        static char _name[] = "";
        return {_name};
    }
};

template<typename TArg>
struct Parameter<TArg>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<TArg>::CStr().Size() + 1),
            "%s", *(test::type::Name<TArg>::CStr()));
        return {_name};
    }
};

template<typename TArg0, typename TArg1, typename... TArgs>
struct Parameter<TArg0, TArg1, TArgs...>
{
    static test::CString<const char> CStr()
    {
        static test::CString<char> _name = test::cstr::Format(
            (test::type::Name<TArg0>::CStr().Size() + 3 +
                test::type::name::Parameter<TArg1, TArgs...>::CStr().Size()),
            "%s, %s", *(test::type::Name<TArg0>::CStr()),
                *(test::type::Name<TArg1, TArgs...>::CStr()));
        return {_name};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_PARAMETER_H_
