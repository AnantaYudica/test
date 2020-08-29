#ifndef TEST_TYPE_NAME_TMPL_PARAMETER_H_
#define TEST_TYPE_NAME_TMPL_PARAMETER_H_

#include "../Parameter.h"

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

inline auto Parameter(...) -> void;

} //!tmpl

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_TMPL_PARAMETER_H_