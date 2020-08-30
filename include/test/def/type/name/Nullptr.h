#ifndef TEST_DEF_TYPE_NAME_NULLPTR_H_
#define TEST_DEF_TYPE_NAME_NULLPTR_H_

#include "../../../type/Name.h"

#include <cstddef>

namespace test
{
namespace type
{

template<>
struct Name<std::nullptr_t>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "std::nullptr_t";
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_NULLPTR_H_
