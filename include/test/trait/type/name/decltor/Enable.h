#ifndef TEST_TRAIT_TYPE_NAME_DECLTOR_ENABLE_H_
#define TEST_TRAIT_TYPE_NAME_DECLTOR_ENABLE_H_

#include "Enable.decl.h"
#include "../../../../type/name/Qualifier.h"
#include "../../../../type/name/Declarator.h"

namespace test
{
namespace trait
{
namespace type
{
namespace name
{
namespace decltor
{

template<typename T, typename TQ, typename TD>
struct Enable
{};

template<typename T>
struct Enable<T, typename test::type::name::Qualifier<T>::Type, 
    typename test::type::name::Declarator<T>::Type>
{
    typedef test::type::name::Declarator<T> Type;
};

template<typename T>
struct Enable<T, typename test::type::name::Qualifier<T>::Type, 
    typename test::type::name::Declarator<T>::DefaultType>
{
    typedef test::type::name::Declarator<T> Type;
};

template<typename T>
struct Enable<T, typename test::type::name::Qualifier<T>::DefaultType, 
    typename test::type::name::Declarator<T>::Type>
{
    typedef test::type::name::Declarator<T> Type;
};

} //!decltor

} //!name

} //!type

} //!trait

} //!test

#endif //!TEST_TRAIT_TYPE_NAME_DECLTOR_ENABLE_H_
