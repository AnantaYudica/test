#ifndef TEST_TYPE_NAME_TMPL_GET_H_
#define TEST_TYPE_NAME_TMPL_GET_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "../Parameter.h"

namespace test
{
namespace type
{
namespace name
{
namespace tmpl
{

template<typename T>
struct Get
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar undefined[] = "parameter-undefined";
        return {undefined};
    }
};

template<typename... TArgs>
struct Get<test::type::name::Parameter<TArgs...>>
{
    template<typename TChar = char>
    static test::CString<TChar> CStr()
    {
        static test::CString<TChar> _param = test::cstr::Format(
            (test::type::name::Parameter<TArgs...>::CStr().Size() + 1),
            "%s", *(test::type::name::Parameter<TArgs...>::CStr()));
        return {_param};
    }
};

} //!tmpl

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_TMPL_GET_H_
