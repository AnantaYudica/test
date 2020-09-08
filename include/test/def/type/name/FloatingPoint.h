#ifndef TEST_DEF_TYPE_NAME_FLOATINGPOINT_H_
#define TEST_DEF_TYPE_NAME_FLOATINGPOINT_H_

#include "../../../type/Name.h"

namespace test
{
namespace type
{

template<>
struct Name<float>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "float";
        return {_name};
    }
};

template<>
struct Name<double>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "double";
        return {_name};
    }
};

template<>
struct Name<long double>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "long double";
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_ARRAY_H_
