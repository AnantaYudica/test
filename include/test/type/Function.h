#ifndef TEST_TYPE_FUNCTION_H_
#define TEST_TYPE_FUNCTION_H_

#include "Parameter.h"

#include <utility>

namespace test
{
namespace type
{

template<typename TFunction, TFunction* FunctionPointer>
class Function
{};

template<typename TRet, typename... TArgs, TRet(*Func)(TArgs...)>
class Function<TRet(TArgs...), Func>
{
public:
    typedef TRet ReturnType;
    typedef TRet(*PointerType)(TArgs...);
    typedef test::type::Parameter<TArgs...> ParameterType;
public:
    typedef PointerType ConstGetType;
public:
    static constexpr PointerType Pointer = Func;
public:
    constexpr TRet Call(TArgs&&... args) const;
public:
    constexpr ConstGetType Get() const;
};

template<typename TRet, typename... TArgs, TRet(*Func)(TArgs...)>
constexpr TRet Function<TRet(TArgs...), Func>::Call(TArgs&&... args) const
{
    return Func(std::forward<TArgs>(args)...);
}

template<typename TRet, typename... TArgs, TRet(*Func)(TArgs...)>
constexpr typename Function<TRet(TArgs...), Func>::ConstGetType 
    Function<TRet(TArgs...), Func>::Get() const
{
    return Func;
}

} //!type

} //!test

#endif //!TEST_TYPE_FUNCTION_H_

