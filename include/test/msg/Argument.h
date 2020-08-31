#ifndef TEST_MSG_ARGUMENT_H_
#define TEST_MSG_ARGUMENT_H_

#include "../Variable.h"
#include "../var/Element.h"
#include "../type/Index.h"
#include "../Forward.h"
#include "../cstr/Forward.h"

#include <cstddef>
#include <type_traits>
#include <utility>

namespace test
{
namespace msg
{

template<typename... TArgs>
class Argument
{
public:
    template<std::size_t I, typename TVar>
    using ElementType = typename test::var::Element<I, TVar>::Type;
public:
    template<std::size_t IAt, typename TRet, typename TDerived, typename TVar, 
        typename... TFuncMmbrArgs>
    using PointerFunctionMemberType = TRet(TDerived::*)(TFuncMmbrArgs...);
    template<std::size_t IAt, typename TRet, typename TVar, 
        typename... TFuncArgs>
    using PointerFunctionType = TRet(*)(TFuncArgs...);
public:
    template<typename TCaseId, std::size_t ICaseId>
    static constexpr std::true_type 
        IsCaseIdIndex(const test::type::Index<TCaseId, ICaseId>&);
    static constexpr std::false_type IsCaseIdIndex(...);
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
            test::Variable<TVarArgs...>, TFuncMmbrArgs...>>
    TRet Call(const TCaseId&, TFuncMmbr func_mmbr, TDerived& d,
        test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args);
    template<typename TRet, typename... TFuncArgs, typename TCaseId,
        typename... TVarArgs, typename TFunc = PointerFunctionType<0, TRet, 
            test::Variable<TVarArgs...>, TFuncArgs...>>
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
    template<typename TRet, typename... TFuncArgs, 
        typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
        typename TFunc = PointerFunctionType<ICaseId, TRet, 
            test::Variable<TVarArgs...>, TFuncArgs...>>
    TRet Call(const test::type::Index<TCaseId, ICaseId>&, TFunc func,
        test::Variable<TVarArgs...>& var, TFuncArgs&&... args);
};

template<typename... TArgs>
Argument<TArgs...>::Argument()
{};

template<typename... TArgs>
template<typename TRet, typename TFuncMmbr, typename TDerived, 
    typename... TFuncMmbrArgs, typename TCaseId, std::size_t ICaseId, 
    typename... TVarArgs>
TRet Argument<TArgs...>::Filler(const test::type::Index<TCaseId, ICaseId>&, 
    TFuncMmbr func_mmbr, TDerived& d, test::Variable<TVarArgs...>&, 
    TFuncMmbrArgs&&... args)
{
    return (d.*func_mmbr)(test::Forward<TFuncMmbrArgs>::Value(args)...);
}

template<typename... TArgs>
template<typename TRet, typename TFunc, typename... TFuncArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs>
TRet Argument<TArgs...>::Filler(const test::type::Index<TCaseId, ICaseId>&, 
    TFunc func, test::Variable<TVarArgs...>&, TFuncArgs&&... args)
{
    return func(test::Forward<TFuncArgs>::Value(args)...);
}

template<typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs,
    typename TCaseId, typename... TVarArgs, typename TFuncMmbr>
TRet Argument<TArgs...>::Call(const TCaseId&, TFuncMmbr func_mmbr,
    TDerived& d, test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId,
    typename... TVarArgs, typename TFunc>
TRet Argument<TArgs...>::Call(const TCaseId&, TFunc func,
    test::Variable<TVarArgs...>& var, TFuncArgs&&... args)
{
    return Filler<TRet>(test::type::Index<TCaseId, 0>{}, func, var, 
        std::forward<TFuncArgs>(args)...);
}

template<typename... TArgs>
template<typename TRet, typename TDerived, typename... TFuncMmbrArgs, 
    typename TCaseId, std::size_t ICaseId, typename... TVarArgs, 
    typename TFuncMmbr>
TRet Argument<TArgs...>::Call(const test::type::Index<TCaseId, 
    ICaseId>& i_case_id, TFuncMmbr func_mmbr, TDerived& d, 
    test::Variable<TVarArgs...>& var, TFuncMmbrArgs&&... args)
{
    return Filler<TRet>(i_case_id, func_mmbr, d, var, 
        std::forward<TFuncMmbrArgs>(args)...);
}

template<typename... TArgs>
template<typename TRet, typename... TFuncArgs, typename TCaseId, 
    std::size_t ICaseId, typename... TVarArgs, typename TFunc>
TRet Argument<TArgs...>::Call(const test::type::Index<TCaseId, 
    ICaseId>& i_case_id, TFunc func, test::Variable<TVarArgs...>& var, 
    TFuncArgs&&... args)
{
    return Filler<TRet>(i_case_id, func, var, 
        std::forward<TFuncArgs>(args)...);
}

} //!msg

} //!test

#endif //!TEST_MSG_ARGUMENT_H_
