#ifndef TEST_TYPE_NAME_REFERENCE_H_
#define TEST_TYPE_NAME_REFERENCE_H_

#include "../../CString.h"

#include <cstddef>

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Reference
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar no_ref[] = "";
        return {no_ref};
    }
};

template<typename T>
struct Reference<T&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _ref[] = "&";
        return {_ref};
    }
};

template<typename T>
struct Reference<T&&>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _ref[] = "&&";
        return {_ref};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_REFERENCE_H_
