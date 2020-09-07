#ifndef TEST_TYPE_NAME_DECLTOR_ENABLE_H_
#define TEST_TYPE_NAME_DECLTOR_ENABLE_H_

#include "../Qualifier.h"
#include "../Declarator.h"

namespace test
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

} //!test

#endif //!TEST_TYPE_NAME_DECLTOR_ENABLE_H_