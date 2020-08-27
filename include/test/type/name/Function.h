#ifndef TEST_TYPE_NAME_FUNCTION_H_
#define TEST_TYPE_NAME_FUNCTION_H_

#include "../../CString.h"
#include "../../cstr/Format.h"
#include "../Name.h"
#include "Parameter.h"

#include <type_traits>
#include <cstddef>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Function
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar no_func[] = "";
        return {no_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...)>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Parameter<TArgs...>::
                template CStr<TChar>().Size() + 3),
            "(%s)", *(test::type::name::Parameter<TArgs...>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...)>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _func[] = "(...)";
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...)>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Parameter<TArg>::template 
                CStr<TChar>().Size() + 8),
            "(%s, ...)", *(test::type::name::Parameter<TArg>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...)>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Parameter<TArg, TArgs...>::
                template CStr<TChar>().Size() + 8),
            "(%s, ...)", *(test::type::name::Parameter<
                TArg, TArgs...>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 3),
            "%s &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 3),
            "%s &", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 3),
            "%s &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 3),
            "%s &", *(test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 4),
            "%s &&", *(test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 7),
            "%s const", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) const>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 7),
            "%s const", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) const>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 7),
            "%s const", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 7),
            "%s const", *(test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 9),
            "%s const &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) const &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 9),
            "%s const &", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) const &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 9),
            "%s const &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 9),
            "%s const &", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 10),
            "%s const &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) const &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 10),
            "%s const &&", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) const &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 10),
            "%s const &&", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 10),
            "%s const &&", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 10),
            "%s volatile", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 10),
            "%s volatile", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 10),
            "%s volatile", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 10),
            "%s volatile", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 12),
            "%s volatile &", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 13),
            "%s volatile &&", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) const volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) const volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const volatile>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 16),
            "%s const volatile", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) const volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) const volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const volatile &>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 18),
            "%s const volatile &", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename... TArgs>
struct Function<T(TArgs...) const volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<T(TArgs...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T>
struct Function<T(...) const volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(...)>::
                template CStr<TChar>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<T(...)>::
                template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg>
struct Function<T(TArg, ...) const volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, ...)>::
                template CStr<TChar>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<
                T(TArg, ...)>::template CStr<TChar>()));
        return {_func};
    }
};

template<typename T, typename TArg, typename... TArgs>
struct Function<T(TArg, TArgs..., ...) const volatile &&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static test::CString<TChar> _func = test::cstr::Format(
            (test::type::name::Function<T(TArg, TArgs..., ...)>::
                template CStr<TChar>().Size() + 19),
            "%s const volatile &&", *(test::type::name::Function<
                T(TArg, TArgs..., ...)>::template CStr<TChar>()));
        return {_func};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_FUNCTION_H_