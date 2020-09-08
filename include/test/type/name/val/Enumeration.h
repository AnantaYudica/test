#ifndef TEST_TYPE_NAME_VAL_ENUMERATION_H_
#define TEST_TYPE_NAME_VAL_ENUMERATION_H_

#include "../../../CString.h"

#include <type_traits>

namespace test
{
namespace type
{
namespace name
{
namespace val
{

template<typename T, T V, bool = std::is_enum<T>::value>
struct Enumeration
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar undefined[] = "value-get-undefined";
        return {undefined};
    }
};
template<typename T, T V>
struct Enumeration<T, V, true>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar undefined[] = "value-enumeration-undefined";
        return {undefined};
    }
};

} //!val

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_VAL_ENUMERATION_H_
