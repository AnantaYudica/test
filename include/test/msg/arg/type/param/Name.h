#ifndef TEST_MSG_ARG_TYPE_PARAM_NAME_H_
#define TEST_MSG_ARG_TYPE_PARAM_NAME_H_

#include "../../../Argument.h"

#include "../../../../Variable.h"
#include "../../../../var/Element.h"
#include "../../../../type/Parameter.h"
#include "../../../../type/param/Name.h"
#include "../../../../CString.h"
#include <cstddef>

namespace test
{
namespace msg
{
namespace arg
{
namespace type
{
namespace param
{

template<std::size_t>
struct Name{};

} //!param

} //!type

} //!arg

template<std::size_t I, typename... TArgs>
class Argument<arg::type::param::Name<I>, TArgs...> :
    public Argument<TArgs...>
{
public:
    template<typename TVar>
    using ElementType = typename Argument<>::template ElementType<I, TVar>;
public:
    template<typename TVar>
    using CharType = typename std::remove_const<typename decltype(type::param::
        Name<ElementType<TVar>>::CStr())::CharType>::type;
public:
    template<typename TVar>
    using GetType = const CharType<TVar> *;
    template<typename TVar>
    using GetPassType = test::CString<CharType<TVar>>;
public:
    template<std::size_t IAt, typename TRet, typename TDerived, 
        typename TVar, typename... TFuncMmbrArgs>
    using PointerFunctionMemberType = typename Argument<TArgs...>::
        template PointerFunctionMemberType<IAt, TRet, TDerived, TVar, 
        TFuncMmbrArgs..., GetType<TVar>&&>;
    template<std::size_t IAt, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using PointerFunctionType = typename Argument<TArgs...>::
        template PointerFunctionType<IAt, TRet, TVar, TFuncArgs...,
        GetType<TVar>&&>;
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
    TRet Call(const type::Index<TCaseId, ICaseId>&, TFuncMmbr func_mmbr,
        TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args);
    template<typename TRet, typename... TFuncArgs, typename TCaseId, 
        std::size_t ICaseId, typename... TVarArgs, 
        typename TFunc = PointerFunctionType<ICaseId, TRet, 
            test::Variable<TVarArgs...>, TFuncArgs...>>
    TRet Call(const type::Index<TCaseId, ICaseId>&, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args);
public:
    template<typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
        typename TGet = typename Argument<arg::type::param::Name<I>, 
        TArgs...>::template GetPassType<test::Variable<TVarArgs...>>> 
    TGet Get(const type::Index<TCaseId, ICaseId>&, 
        test::Variable<TVarArgs...>& var);
};

template<std::size_t I, typename... TArgs>
Argument<arg::type::param::Name<I>, TArgs...>::Argument()
{}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TFuncMmbr, typename TDerived, 
    typename... TFuncMmbrArgs, typename TCaseId, std::size_t ICaseId, 
    typename... TVarArgs>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args)
{
    return Argument<TArgs...>:: template Filler<TRet>(i_case_id, func_mmbr, d,
        var, std::forward<TFuncMmbrArgs>(args)..., 
        std::move(Get(i_case_id, var)));
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TFunc, typename... TFuncArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Argument<TArgs...>:: template Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)..., std::move(Get(i_case_id, var)));
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs,
    typename TCaseId, typename... TVarArgs, typename TFuncMmbr,
    typename std::enable_if<!decltype(Argument<>::IsCaseIdIndex(
        std::declval<TCaseId>()))::value, int>::type>
TRet Argument<arg::type::param::Name<I>, TArgs...>::Call(const TCaseId&, 
    TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
    TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId,
    typename... TVarArgs, typename TFunc, typename std::enable_if<!decltype(
        Argument<>::IsCaseIdIndex(std::declval<TCaseId>()))::value, int>::type>
TRet Argument<arg::type::param::Name<I>, TArgs...>::Call(const TCaseId&, 
    TFunc func, test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
    typename TFuncMmbr>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Call(const type::Index<TCaseId, ICaseId>& i_case_id, TFuncMmbr func_mmbr,
        TDerived& d, test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(i_case_id, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId, 
    std::size_t ICaseId, typename... TVarArgs, typename TFunc>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Call(const type::Index<TCaseId, ICaseId>& i_case_id, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
    typename TGet>
TGet Argument<arg::type::param::Name<I>, TArgs...>::
    Get(const type::Index<TCaseId, ICaseId>&, test::Variable<TVarArgs...>&)
{
    return std::move(type::param::Name<typename Argument<>::
        template ElementType<I, test::Variable<TVarArgs...>>>::CStr());
}

} //!msg

} //!test

#endif //!TEST_MSG_ARG_TYPE_PARAM_NAME_H_
