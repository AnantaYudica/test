#ifndef TEST_TYPE_NAME_TMPL_PARAMETER_H_
#define TEST_TYPE_NAME_TMPL_PARAMETER_H_

#include "../Parameter.h"
#include "Define.h"

#include <type_traits>

namespace test
{
namespace type
{
namespace name
{
namespace tmpl
{

template<template <typename ...> class TT, typename... TArgs>
inline auto Parameter(TT<TArgs...>*) -> test::type::name::Parameter<TArgs...>;

template<typename T, 
    typename test::type::name::tmpl::Define<T>::ParameterType* = nullptr>
inline auto Parameter(T*) -> 
    typename test::type::name::tmpl::Define<T>::ParameterType;

template<typename T, 
    typename test::type::name::tmpl::Define<void(T)>::ParameterType* = nullptr>
inline auto Parameter(T*) -> 
    typename test::type::name::tmpl::Define<void(T)>::ParameterType;

inline auto Parameter(...) -> void;


} //!tmpl

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_TMPL_PARAMETER_H_