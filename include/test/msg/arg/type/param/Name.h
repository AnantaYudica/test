#ifndef TEST_MSG_ARG_TYPE_PARAM_NAME_H_
#define TEST_MSG_ARG_TYPE_PARAM_NAME_H_

#include "../../../Argument.h"

#include "../../../../Variable.h"
#include "../../../../var/Element.h"
#include "../../../../type/Parameter.h"
#include "../../../../type/param/Name.h"
#include "../../../../type/param/Element.h"
#include "../../../../type/param/Size.h"
#include "../../../../CString.h"
#include "../../../../Forward.h"
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
private:
    template<std::size_t S, typename... TParamArgs>
    struct Pointer;
    template<typename... TParamArgs>
    struct Pointer<0, TParamArgs...>;
public:
    template<typename TVar>
    using ElementType = typename Argument<>::template ElementType<I, TVar>;
public:
    template<typename TVar>
    using CharType = typename std::remove_const<typename decltype(test::type::
        param::Name<ElementType<TVar>>::CStr())::CharType>::type;
public:
    template<typename TVar>
    using GetType = test::CString<CharType<TVar>>;
    template<typename TVar>
    using GetForwardType = typename test::Forward<GetType<TVar>>::Type;
public:
    template<std::size_t IAt, typename TRet, typename TDerived, 
        typename TVar, typename... TFuncMmbrArgs>
    using PointerFunctionMemberType = typename Pointer<test::type::param::
        Size<ElementType<TVar>>::Value>::template FunctionMemberType<IAt, TRet,
        TDerived, TVar, TFuncMmbrArgs...>;
    template<std::size_t IAt, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using PointerFunctionType = typename Pointer<test::type::param::
        Size<ElementType<TVar>>::Value>::template FunctionType<IAt, TRet, TVar,
        TFuncArgs...>;
public:
    Argument();
protected:
    template<std::size_t S, typename TRet, std::size_t IAt = S, 
        typename TFuncMmbr, typename TDerived, typename... TFuncMmbrArgs, 
        typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
    typename std::enable_if<IAt != 0, TRet>::type FillerAt(
        const test::type::Index<TCaseId, ICaseId>&, TFuncMmbr func_mmbr, 
        TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args);
    template<std::size_t S, typename TRet, std::size_t IAt = S, 
        typename TFuncMmbr, typename TDerived, typename... TFuncMmbrArgs, 
        typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
    typename std::enable_if<IAt == 0, TRet>::type FillerAt(
        const test::type::Index<TCaseId, ICaseId>&, TFuncMmbr func_mmbr, 
        TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args);
    template<std::size_t S, typename TRet, std::size_t IAt = S, 
        typename TFunc, typename... TFuncArgs, typename TCaseId, 
        std::size_t ICaseId, typename... TVarArgs>
    typename std::enable_if<IAt != 0, TRet>::type FillerAt(
        const test::type::Index<TCaseId, ICaseId>&, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args);
    template<std::size_t S, typename TRet, std::size_t IAt = S, 
        typename TFunc, typename... TFuncArgs, typename TCaseId, 
        std::size_t ICaseId, typename... TVarArgs>
    typename std::enable_if<IAt == 0, TRet>::type FillerAt(
        const test::type::Index<TCaseId, ICaseId>&, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args);
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
    template<std::size_t IAt, typename TCaseId, std::size_t ICaseId, 
        typename... TVarArgs, typename TGet = typename Argument<
        arg::type::param::Name<I>, TArgs...>::template 
        GetType<test::Variable<TVarArgs...>>> 
    TGet Get(const test::type::Index<TCaseId, ICaseId>&, 
        test::Variable<TVarArgs...>& var);
};

template<std::size_t I, typename... TArgs>
template<std::size_t S, typename... TParamArgs>
struct Argument<arg::type::param::Name<I>, TArgs...>::Pointer
{
    template<std::size_t ICaseId, typename TRet, typename TDerived, 
        typename TVar, typename... TFuncMmbrArgs>
    using FunctionMemberType = typename Pointer<S - 1, GetForwardType<TVar>&&,
        TParamArgs...>::template FunctionMemberType<ICaseId, TRet, TDerived, 
            TVar, TFuncMmbrArgs...>;
    template<std::size_t ICaseId, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using FunctionType = typename Pointer<S - 1, GetForwardType<TVar>&&,
        TParamArgs...>::template FunctionType<ICaseId, TRet, TVar, TFuncArgs...>;
};

template<std::size_t I, typename... TArgs>
template<typename... TParamArgs>
struct Argument<arg::type::param::Name<I>, TArgs...>::
    Pointer<0, TParamArgs...>
{
    template<std::size_t ICaseId, typename TRet, typename TDerived, 
        typename TVar, typename... TFuncMmbrArgs>
    using FunctionMemberType = typename Argument<TArgs...>::
        template PointerFunctionMemberType<ICaseId, TRet, TDerived, TVar, 
        TFuncMmbrArgs..., TParamArgs&&...>;
    template<std::size_t ICaseId, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using FunctionType = typename Argument<TArgs...>::
        template PointerFunctionType<ICaseId, TRet, TVar, TFuncArgs..., 
        TParamArgs&&...>;
};

template<std::size_t I, typename... TArgs>
Argument<arg::type::param::Name<I>, TArgs...>::Argument()
{}

template<std::size_t I, typename... TArgs>
template<std::size_t S, typename TRet, std::size_t IAt, 
    typename TFuncMmbr, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
typename std::enable_if<IAt != 0, TRet>::type 
    Argument<arg::type::param::Name<I>, TArgs...>::
        FillerAt(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
            TFuncMmbr func_mmbr, TDerived& d, 
            test::Variable<TVarArgs...>& var, 
            TFuncMmbrArgs&&... args)
{
    return FillerAt<S, TRet, IAt - 1>(i_case_id, func_mmbr, d, var,
        std::forward<TFuncMmbrArgs>(args)..., 
        std::move(Get<S - IAt>(i_case_id, var)));
}

template<std::size_t I, typename... TArgs>
template<std::size_t S, typename TRet, std::size_t IAt, 
    typename TFuncMmbr, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
typename std::enable_if<IAt == 0, TRet>::type 
    Argument<arg::type::param::Name<I>, TArgs...>::
        FillerAt(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
            TFuncMmbr func_mmbr, TDerived& d, 
            test::Variable<TVarArgs...>& var, 
            TFuncMmbrArgs&&... args)
{
    return Argument<TArgs...>:: template Filler<TRet>(i_case_id, func_mmbr, d, 
        var, std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<std::size_t S, typename TRet, std::size_t IAt, 
    typename TFunc, typename... TFuncArgs, typename TCaseId, 
    std::size_t ICaseId, typename... TVarArgs>
typename std::enable_if<IAt != 0, TRet>::type 
    Argument<arg::type::param::Name<I>, TArgs...>::
        FillerAt(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
            TFunc func, test::Variable<TVarArgs...>& var, 
            TFuncArgs&&... args)
{
    return FillerAt<S, TRet, IAt - 1>(i_case_id, func, var,
        std::forward<TFuncArgs>(args)..., 
        std::move(Get<S - IAt>(i_case_id, var)));
}

template<std::size_t I, typename... TArgs>
template<std::size_t S, typename TRet, std::size_t IAt, 
    typename TFunc, typename... TFuncArgs, typename TCaseId, 
    std::size_t ICaseId, typename... TVarArgs>
typename std::enable_if<IAt == 0, TRet>::type 
    Argument<arg::type::param::Name<I>, TArgs...>::
        FillerAt(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
            TFunc func, test::Variable<TVarArgs...>& var, 
            TFuncArgs&&... args)
{
    return Argument<TArgs...>:: template Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TFuncMmbr, typename TDerived, 
    typename... TFuncMmbrArgs, typename TCaseId, std::size_t ICaseId, 
    typename... TVarArgs>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args)
{
    return FillerAt<test::type::param::Size<ElementType<test::Variable<
        TVarArgs...>>>::Value, TRet>(i_case_id, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TFunc, typename... TFuncArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return FillerAt<test::type::param::Size<ElementType<test::Variable<
        TVarArgs...>>>::Value, TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
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
    Call(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var,
        TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(i_case_id, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId, 
    std::size_t ICaseId, typename... TVarArgs, typename TFunc>
TRet Argument<arg::type::param::Name<I>, TArgs...>::
    Call(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<std::size_t IAt, typename TCaseId, std::size_t ICaseId, 
    typename... TVarArgs, typename TGet>
TGet Argument<arg::type::param::Name<I>, TArgs...>::
    Get(const test::type::Index<TCaseId, ICaseId>&, 
        test::Variable<TVarArgs...>&)
{
    return std::move(test::type::Name<typename test::type::param::Element<IAt, 
        ElementType<test::Variable<TVarArgs...>>>::Type>::CStr());
}

} //!msg

} //!test

#endif //!TEST_MSG_ARG_TYPE_PARAM_NAME_H_
