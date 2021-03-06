#ifndef TEST_TYPE_PARAM_FILLER_H_
#define TEST_TYPE_PARAM_FILLER_H_

#include "../Parameter.h"

#include <utility>

namespace test
{
namespace type
{
namespace param
{

template<typename T>
class Filler
{};

template<typename... TArgs>
class Filler<type::Parameter<TArgs...>>
{
public:
    template<template<typename...> class TT>
    using Type = TT<TArgs...>;
};

} //!param

} //!type

} //!test

#endif //!TEST_TYPE_PARAM_FILLER_H_
