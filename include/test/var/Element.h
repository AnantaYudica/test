#ifndef TEST_VAR_ELEMENT_H_
#define TEST_VAR_ELEMENT_H_

#include "../Variable.h"

#include <cstddef>

namespace test
{
namespace var
{

template<std::size_t I, typename T>
struct Element
{};

template<std::size_t I, typename TArg, typename... TArgs>
struct Element<I, test::Variable<TArg, TArgs...>>
{
    using Type = typename Element<I - 1, 
        test::Variable<TArgs...>>::Type;
};

template<typename TArg, typename... TArgs>
struct Element<0, test::Variable<TArg, TArgs...>>
{
    using Type = TArg;
};

} //!var

} //!test

#endif //!TEST_VAR_ELEMENT_H_
