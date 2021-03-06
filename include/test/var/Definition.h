#ifndef TEST_VAR_DEFINITION_H_
#define TEST_VAR_DEFINITION_H_

#include "../Variable.h"

#include <cstddef>

namespace test
{
namespace var
{

template<std::size_t I, typename TVar>
struct Definition
{};

template<std::size_t I, typename TArg, typename... TArgs>
struct Definition<I, test::Variable<TArg, TArgs...>>
{
    typedef typename Definition<I - 1, test::Variable<TArgs...>>::Type Type;
};

template<typename TArg, typename... TArgs>
struct Definition<0, test::Variable<TArg, TArgs...>>
{
    typedef test::Variable<TArg, TArgs...> Type;
};

template<typename... TArgs>
struct Definition<0, test::Variable<TArgs...>>
{
    typedef test::Variable<TArgs...> Type;
};


} //!var

} //!test

#endif //!TEST_VAR_DEFINITION_H_
