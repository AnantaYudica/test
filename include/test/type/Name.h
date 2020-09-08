#ifndef TEST_TYPE_NAME_H_
#define TEST_TYPE_NAME_H_

#include "../CString.h"
#include "../trait/type/name/decltor/Enable.decl.h"
#include "name/Declarator.decl.h"

#include <cstddef>

namespace test
{
namespace type
{

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
struct Name<T, typename test::trait::type::name::decltor::Enable<T>::Type>
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
#include "../trait/type/name/decltor/Enable.h"

#endif //!TEST_TYPE_NAME_H_
