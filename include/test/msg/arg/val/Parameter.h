#ifndef TEST_MSG_ARG_VAL_PARAMETER_H_
#define TEST_MSG_ARG_VAL_PARAMETER_H_

#include "../../Argument.h"

#include "../../../Variable.h"
#include "../../../var/val/Parameter.h"
#include "../../../var/Element.h"
#include "../../../var/At.h"
#include "../../../val/Parameter.h"
#include "../../../type/param/Size.h"
#include "../../../type/param/Element.h"
#include "../../../Forward.h"
#include "../../../trait/type/index/IsBaseOf.h"

#include <cstddef>

namespace test
{
namespace msg
{
namespace arg
{
namespace val
{

template<std::size_t>
struct Parameter{};

} //!val

} //!arg

template<std::size_t I, typename... TArgs>
class Argument<arg::val::Parameter<I>, TArgs...> :
    public Argument<TArgs...>
{
private:
    template<typename TVar>
    struct Pointer;
    template<typename... TParamArgs>
    struct Pointer<test::val::Parameter<TParamArgs...>>;
public:
    template<typename TVar>
    using ElementType = typename Argument<>::template ElementType<I, TVar>;
public:
    template<std::size_t IAt, typename TVar>
    using GetType = typename test::type::param::Element<IAt, 
        ElementType<TVar>>::Type;
    template<std::size_t IAt, typename TVar>
    using GetForwardType = typename test::Forward<GetType<IAt, TVar>>::Type;
public:
    template<std::size_t IAt, typename TRet, typename TDerived, 
        typename TVar, typename... TFuncMmbrArgs>
    using PointerFunctionMemberType = typename Pointer<ElementType<TVar>>::
        template FunctionMemberType<IAt, TRet, TDerived, TVar, 
            TFuncMmbrArgs...>;
    template<std::size_t IAt, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using PointerFunctionType = typename Pointer<ElementType<TVar>>::
        template FunctionType<IAt, TRet, TVar, TFuncArgs...>;
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
        typename std::enable_if<!test::trait::type::index::IsBaseOf<TCaseId>::
            Value, int>::type = 0>
    TRet Call(const TCaseId&, TFuncMmbr func_mmbr, TDerived& d,
        test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args);
    template<typename TRet, typename... TFuncArgs, typename TCaseId, 
        typename... TVarArgs, typename TFunc = PointerFunctionType<0, TRet, 
            test::Variable<TVarArgs...>, TFuncArgs...>,
        typename std::enable_if<!test::trait::type::index::IsBaseOf<TCaseId>::
            Value, int>::type = 0>
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
        arg::val::Parameter<I>, TArgs...>::template GetType<IAt, 
        test::Variable<TVarArgs...>>>
    TGet Get(const test::type::Index<TCaseId, ICaseId>&, 
        test::Variable<TVarArgs...>& var);
};

template<std::size_t I, typename... TArgs>
template<typename TVar>
struct Argument<arg::val::Parameter<I>, TArgs...>::Pointer
{};

template<std::size_t I, typename... TArgs>
template<typename... TParamArgs>
struct Argument<arg::val::Parameter<I>, TArgs...>::
    Pointer<test::val::Parameter<TParamArgs...>>
{
    template<std::size_t ICaseId, typename TRet, typename TDerived, 
        typename TVar, typename... TFuncMmbrArgs>
    using FunctionMemberType = typename Argument<TArgs...>::
        template PointerFunctionMemberType<ICaseId, TRet, TDerived, TVar, 
        TFuncMmbrArgs..., typename test::Forward<TParamArgs>::Type&&...>;
    template<std::size_t ICaseId, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using FunctionType = typename Argument<TArgs...>::
        template PointerFunctionType<ICaseId, TRet, TVar, TFuncArgs..., 
        typename test::Forward<TParamArgs>::Type&&...>;
};

template<std::size_t I, typename... TArgs>
Argument<arg::val::Parameter<I>, TArgs...>::Argument()
{}

template<std::size_t I, typename... TArgs>
template<std::size_t S, typename TRet, std::size_t IAt, 
    typename TFuncMmbr, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
typename std::enable_if<IAt != 0, TRet>::type 
    Argument<arg::val::Parameter<I>, TArgs...>::
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
    Argument<arg::val::Parameter<I>, TArgs...>::
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
    Argument<arg::val::Parameter<I>, TArgs...>::
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
    Argument<arg::val::Parameter<I>, TArgs...>::
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
TRet Argument<arg::val::Parameter<I>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, 
        TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>& var, 
        TFuncMmbrArgs&&... args)
{
    return FillerAt<test::type::param::Size<ElementType<test::
        Variable<TVarArgs...>>>::Value, TRet>(i_case_id, func_mmbr, d, var, 
            std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TFunc, typename... TFuncArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
TRet Argument<arg::val::Parameter<I>, TArgs...>::
    Filler(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func, 
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return FillerAt<test::type::param::Size<ElementType<test::
        Variable<TVarArgs...>>>::Value, TRet>(i_case_id, func, var, 
            std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs,
    typename TCaseId, typename... TVarArgs, typename TFuncMmbr,
    typename std::enable_if<!test::trait::type::index::IsBaseOf<TCaseId>::
    Value, int>::type>
TRet Argument<arg::val::Parameter<I>, TArgs...>::
    Call(const TCaseId&, TFuncMmbr func_mmbr, TDerived& d,
        test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId,
    typename... TVarArgs, typename TFunc, typename std::enable_if<
    !test::trait::type::index::IsBaseOf<TCaseId>::Value, int>::type>
TRet Argument<arg::val::Parameter<I>, TArgs...>::
    Call(const TCaseId&, TFunc func, test::Variable<TVarArgs...>& var,
        TFuncArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
    typename TFuncMmbr>
TRet Argument<arg::val::Parameter<I>, TArgs...>::
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
TRet Argument<arg::val::Parameter<I>, TArgs...>::
    Call(const test::type::Index<TCaseId, ICaseId>& i_case_id, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<std::size_t I, typename... TArgs>
template<std::size_t IAt, typename TCaseId, std::size_t ICaseId,
    typename... TVarArgs, typename TGet>
TGet Argument<arg::val::Parameter<I>, TArgs...>::
    Get(const test::type::Index<TCaseId, ICaseId>&, 
        test::Variable<TVarArgs...>& var)
{
    return std::move(test::var::At<I>(var).Get().template At<IAt>());
}

} //!msg

} //!test

#endif //!TEST_MSG_ARG_VAL_PARAMETER_H_
