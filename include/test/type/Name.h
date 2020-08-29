#ifndef TEST_TYPE_NAME_H_
#define TEST_TYPE_NAME_H_

#include "../CString.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace name
{

template<typename T, typename TB = T, typename... TArgs>
struct Declarator;

namespace decltor
{

template<typename T, typename TQ = T, typename TD = T>
struct Enable;

} //!decltor

} //!name

template<typename T, typename TDeclarator = test::type::name::Declarator<T>>
struct Name
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar undefined[] = "undefined";
        return {undefined};
    }
};

template<typename T>
struct Name<T, typename test::type::name::decltor::Enable<T>::Type>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        return {test::type::name::Declarator<T>::template CStr<TChar>()};
    }
};

} //!type

} //!test

#include "name/Declarator.h"
#include "name/decltor/Enable.h"

#endif //!TEST_TYPE_NAME_H_
