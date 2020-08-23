#ifndef TEST_TYPE_NAME_VAL_GET_H_
#define TEST_TYPE_NAME_VAL_GET_H_

#include "../../../CString.h"

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<typename T>
struct Get
{
    template<typename TChar= char>
    static test::CString<TChar> CStr(T)
    {
        static TChar undefined[] = "value-undefined";
        return {undefined};
    }
};

} //!val

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VAL_GET_H_