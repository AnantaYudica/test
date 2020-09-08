#ifndef TEST_DEF_TYPE_NAME_CHARACTER_H_
#define TEST_DEF_TYPE_NAME_CHARACTER_H_

#include "../../../type/Name.h"

namespace test
{
namespace type
{

template<>
struct Name<signed char>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "signed char";
        return {_name};
    }
};

template<>
struct Name<char>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "char";
        return {_name};
    }
};

template<>
struct Name<unsigned char>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "unsigned char";
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_CHARACTER_H_
