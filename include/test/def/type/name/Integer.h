#ifndef TEST_DEF_TYPE_NAME_INTEGER_H_
#define TEST_DEF_TYPE_NAME_INTEGER_H_

#include "../../../type/Name.h"

namespace test
{
namespace type
{

template<>
struct Name<short>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "short";
        return {_name};
    }
};

template<>
struct Name<int>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "int";
        return {_name};
    }
};

template<>
struct Name<long>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "long";
        return {_name};
    }
};

template<>
struct Name<long long>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "long long";
        return {_name};
    }
};

template<>
struct Name<unsigned short>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "unsigned short";
        return {_name};
    }
};

template<>
struct Name<unsigned int>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "unsigned int";
        return {_name};
    }
};

template<>
struct Name<unsigned long>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] =  "unsigned long";
        return {_name};
    }
};

template<>
struct Name<unsigned long long>
{
    template<typename TChar = char>
    static test::CString<const TChar> CStr()
    {
        static TChar _name[] = "unsigned long long";
        return {_name};
    }
};

} //!type

} //!test

#endif //!TEST_DEF_TYPE_NAME_INTEGER_H_
