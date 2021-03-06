#ifndef TEST_TYPE_PARAM_SIZE_H_
#define TEST_TYPE_PARAM_SIZE_H_

#include "../Parameter.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace param
{

template<typename T>
struct Size
{};

template<typename... TArgs>
struct Size<type::Parameter<TArgs...>>
{
    static constexpr std::size_t Value = sizeof...(TArgs);
};

template<template<typename...> class TTParam, typename... TArgs>
struct Size<TTParam<TArgs...>>
{
    static constexpr std::size_t Value = sizeof...(TArgs);
};

} //!param

} //!type

} //!test

#endif //!TEST_TYPE_PARAM_SIZE_H_
