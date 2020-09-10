#ifndef TEST_TYPE_NAME_DECLTOR_FORMAT_H_
#define TEST_TYPE_NAME_DECLTOR_FORMAT_H_

#include "../../../CString.h"
#include "../../../cstr/Format.h"
#include "../../Name.h"
#include "../Qualifier.h"
#include "Parameter.h"

namespace test
{
namespace type
{
namespace name
{
namespace decltor
{

template<typename TQ, typename TN, typename TParam>
struct Format
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _fmt[] = "format undefined";
        return {_fmt};
    }
};

template<typename TN>
struct Format<TN, TN, test::type::name::decltor::Parameter<>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _fmt = test::cstr::Format(
            (test::type::Name<TN>::template CStr<TChar>().Size() + 1),
            "%s", *(test::type::Name<TN>::template CStr<TChar>()));
        return {_fmt};
    }
};

template<typename TN, typename TArg, typename... TArgs>
struct Format<TN, TN, test::type::name::decltor::Parameter<TArg, TArgs...>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef test::type::name::decltor::Parameter<TArg, TArgs...> ParamType;
        static test::CString<TChar> _fmt = test::cstr::Format(
            (test::type::Name<TN>::template CStr<TChar>().Size() +
                ParamType::template CStr<TChar>().Size() + 2),
            "%s %s", *(test::type::Name<TN>::template CStr<TChar>()),
            *(ParamType::template CStr<TChar>()));
        return {_fmt};
    }
};

template<typename TQ, typename TN>
struct Format<TQ, TN, test::type::name::decltor::Parameter<>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _fmt = test::cstr::Format(
            (test::type::name::Qualifier<TQ>::template CStr<TChar>().Size() +
                test::type::Name<TN>::template CStr<TChar>().Size() + 2),
            "%s %s", *(test::type::name::Qualifier<TQ>::
                template CStr<TChar>()),
            *(test::type::Name<TN>::template CStr<TChar>()));
        return {_fmt};
    }
};

template<typename TQ, typename TN, typename TArg, typename... TArgs>
struct Format<TQ, TN, test::type::name::decltor::Parameter<TArg, TArgs...>>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        typedef test::type::name::decltor::Parameter<TArg, TArgs...> ParamType;
        static test::CString<TChar> _fmt = test::cstr::Format(
            (test::type::name::Qualifier<TQ>::template CStr<TChar>().Size() +
                test::type::Name<TN>::template CStr<TChar>().Size() +
                ParamType::template CStr<TChar>().Size() + 3), "%s %s %s", 
            *(test::type::name::Qualifier<TQ>::template CStr<TChar>()),
            *(test::type::Name<TN>::template CStr<TChar>()),
            *(ParamType::template CStr<TChar>()));
        return {_fmt};
    }
};

} //!decltor

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_DECLTOR_FORMAT_H_
