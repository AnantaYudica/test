#ifndef TEST_MSG_ARG_TYPE_FUNCTION_H_
#define TEST_MSG_ARG_TYPE_FUNCTION_H_

#include "../../Argument.h"

#include "../../../Variable.h"
#include "../../../var/type/Function.h"
#include "../../../var/At.h"
#include "../../../var/Element.h"
#include "../../../type/Function.h"
#include "../../../Forward.h"

#include <cstddef>

namespace test
{
namespace msg
{
namespace arg
{
namespace type
{
template<std::size_t I, typename... TArgArgs>
struct Function{};

} //!type

} //!arg

template<std::size_t I, typename... TArgArgs, typename... TArgs>
class Argument<arg::type::Function<I, TArgArgs...>, TArgs...> :
    public Argument<TArgs...>
{
public:
    template<typename TVar>
    using ElementType = typename Argument<>::template ElementType<I, TVar>;
public:
    template<typename TVar>
    using GetType = typename ElementType<TVar>::ReturnType;
    template<typename TVar>
    using GetForwardType = typename test::Forward<GetType<TVar>>::Type;
public:
    template<std::size_t IAt, typename TRet, typename TDerived, typename TVar, 
        typename... TFuncMmbrArgs>
    using PointerFunctionMemberType = typename Argument<TArgs...>::
        template PointerFunctionMemberType<IAt, TRet, TDerived, TVar, 
            TFuncMmbrArgs..., GetForwardType<TVar>&&>;
    template<std::size_t IAt, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using PointerFunctionType = typename Argument<TArgs...>::
        template PointerFunctionType<IAt, TRet, TVar, TFuncArgs..., 
            GetForwardType<TVar>&&>;
public:
    Argument();
protected:
    template<typename TRet, typename TFuncMmbr, typename TDerived, 
        typename... TFuncMmbrArgs, typename TCaseId, std::size_t ICaseId, 
        typename... TVarArgs>
    TRet Filler(const test::type::Index<TCaseId, ICaseId>&, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args);
    template<typename TRet, typename TFunc, typename... TFuncArgs, 
        typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
    TRet Filler(const test::type::Index<TCaseId, ICaseId>&, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args);
public:
    template<typename TRet, typename TDerived, typename... TFuncMmbrArgs,
        typename TCaseId, typename... TVarArgs, 
        typename TFuncMmbr = PointerFunctionMemberType<0, TRet, TDerived, 
            test::Variable<TVarArgs...>, TFuncMmbrArgs...>,
        typename std::enable_if<!decltype(Argument<>::
            IsCaseIdIndex(std::declval<TCaseId>()))::value, int>::type = 0>
    TRet Call(const TCaseId&, TFuncMmbr func_mmbr, TDerived& d,
        test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args);
    template<typename TRet, typename... TFuncArgs, typename TCaseId, 
        typename... TVarArgs, typename TFunc = PointerFunctionType<0, TRet, 
            test::Variable<TVarArgs...>, TFuncArgs...>,
        typename std::enable_if<!decltype(Argument<>::
            IsCaseIdIndex(std::declval<TCaseId>()))::value, int>::type = 0>
    TRet Call(const TCaseId&, TFunc func, test::Variable<TVarArgs...>& var,
        TFuncArgs&&... args);
public:
    template<typename TRet, typename TDerived, typename... TFuncMmbrArgs, 
        typename TCaseId, std::size_t ICaseId, typename... TVarArgs,
        typename TFuncMmbr = PointerFunctionMemberType<ICaseId, TRet, TDerived,
            test::Variable<TVarArgs...>, TFuncMmbrArgs...>>
    TRet Call(const test::type::Index<TCaseId, ICaseId>&, TFuncMmbr func_mmbr,
        TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args);
    template<typename TRet, typename... TFuncArgs, typename TCaseId, 
        std::size_t ICaseId, typename... TVarArgs, 
        typename TFunc = PointerFunctionType<ICaseId, TRet, 
            test::Variable<TVarArgs...>, TFuncArgs...>>
    TRet Call(const test::type::Index<TCaseId, ICaseId>&, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args);
public:
    template<typename TCaseId, std::size_t ICaseId, typename... TVarArgs,
        typename TGet = typename Argument<arg::type::Function<I, TArgArgs...>,
            TArgs...>::template GetType<test::Variable<TVarArgs...>>>
    TGet Get(const test::type::Index<TCaseId, ICaseId>&, 
        test::Variable<TVarArgs...>& var);
};

template<std::size_t I, typename... TArgArgs, typename... TArgs>
Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::Argument()
{}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TRet, typename TFuncMmbr, typename TDerived, 
    typename... TFuncMmbrArgs, typename TCaseId, std::size_t ICaseId, 
    typename... TVarArgs>
TRet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args)
{
    return Argument<TArgs...>:: template Filler<TRet>(i_case_id, func_mmbr, d, 
        var, std::forward<TFuncMmbrArgs>(args)..., 
        std::move(Get(i_case_id, var)));
}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TRet, typename TFunc, typename... TFuncArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
TRet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Argument<TArgs...>:: template Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)..., 
        std::move(Get(i_case_id, var)));
}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs,
    typename TCaseId, typename... TVarArgs, typename TFuncMmbr,
    typename std::enable_if<!decltype(Argument<>::IsCaseIdIndex(
        std::declval<TCaseId>()))::value, int>::type>
TRet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Call(const TCaseId&, TFuncMmbr func_mmbr, TDerived& d, 
        test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId,
    typename... TVarArgs, typename TFunc, typename std::enable_if<!decltype(
        Argument<>::IsCaseIdIndex(std::declval<TCaseId>()))::value, int>::type>
TRet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Call(const TCaseId&, TFunc func, test::Variable<TVarArgs...>& var,
        TFuncArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
    typename TFuncMmbr>
TRet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Call(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(i_case_id, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId, 
    std::size_t ICaseId, typename... TVarArgs, typename TFunc>
TRet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Call(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgArgs, typename... TArgs>
template<typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
    typename TGet>
TGet Argument<arg::type::Function<I, TArgArgs...>, TArgs...>::
    Get(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        test::Variable<TVarArgs...>& var)
{
    return std::move(Argument<TArgArgs...>{}.template Call<
        GetType<test::Variable<TVarArgs...>>>(i_case_id,
            test::var::At<I>(var).Get().Get(), var));
}


} //!msg

} //!test

#endif //!TEST_MSG_ARG_TYPE_FUNCTION_H_
