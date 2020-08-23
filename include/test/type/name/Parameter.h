#ifndef TEST_TYPE_NAME_PARAMETER_H_
#define TEST_TYPE_NAME_PARAMETER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "Value.h"

namespace test
{
namespace type
{
namespace name
{

template<typename... TArgs>
struct Parameter
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "";
        return {_name};
    }
};

template<typename TArg>
struct Parameter<TArg>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _name = test::cstr::Format(
            (test::type::Name<TArg>::template CStr<TChar>().Size() + 1),
            "%s", *(test::type::Name<TArg>::template CStr<TChar>()));
        return {_name};
    }
};

template<typename TArg0, typename TArg1, typename... TArgs>
struct Parameter<TArg0, TArg1, TArgs...>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _name = test::cstr::Format(
            (test::type::Name<TArg0>::template CStr<TChar>().Size() + 3 +
                test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<TChar>().Size()),
            "%s, %s", *(test::type::Name<TArg0>::template CStr<TChar>()),
            *(test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<TChar>()));
        return {_name};
    }
};

template<typename T, T V>
struct Parameter<test::type::name::Value<T, V>>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        return {test::type::name::Value<T, V>::template CStr<TChar>()};
    }
};

template<typename T, T V, typename TArg1, typename... TArgs>
struct Parameter<test::type::name::Value<T, V>, TArg1, TArgs...>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _name = test::cstr::Format(
            (test::type::name::Value<T, V>::template CStr<TChar>().Size() + 3 +
                test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<TChar>().Size()),
            "%s, %s", *(test::type::name::Value<T, V>::template CStr<TChar>()),
            *(test::type::name::Parameter<TArg1, TArgs...>::
                template CStr<TChar>()));
        return {_name};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_PARAMETER_H_
