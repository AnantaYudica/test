#ifndef TEST_TYPE_NAME_H_
#define TEST_TYPE_NAME_H_

#include "../CString.h"
#include "name/Declarator.h"

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

} //!type

} //!test

#endif //!TEST_TYPE_NAME_H_
