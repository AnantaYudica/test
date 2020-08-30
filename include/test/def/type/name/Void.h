#ifndef TEST_DEF_TYPE_NAME_VOID_H_
#define TEST_DEF_TYPE_NAME_VOID_H_

#include "../../../type/Name.h"

namespace test
{
namespace type
{

template<>
struct Name<void>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "void";
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_VOID_H_
