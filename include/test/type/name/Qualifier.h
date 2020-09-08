#ifndef TEST_TYPE_NAME_QUALIFIER_H_
#define TEST_TYPE_NAME_QUALIFIER_H_

#include "../../CString.h"
#include "../../cstr/Format.h"

namespace test
{
namespace type
{
namespace name
{

template<typename T>
struct Qualifier
{
    typedef T SimpleType;
    typedef T DefaultType;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar no_qualifier[] = "";
        return {no_qualifier};
    }
};

template<typename T>
struct Qualifier<const T>
{
    typedef T SimpleType;
    typedef const T Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _qualifier[] = "const";
        return {_qualifier};
    }
};

template<typename T>
struct Qualifier<volatile T>
{
    typedef T SimpleType;
    typedef volatile T Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _qualifier[] = "volatile";
        return {_qualifier};
    }
};

template<typename T>
struct Qualifier<const volatile T>
{
    typedef T SimpleType;
    typedef const volatile T Type;
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar _qualifier[] = "const volatile";
        return {_qualifier};
    }
};

} //!name

} //!type

} //!test

#endif //!TEST_TYPE_NAME_QUALIFIER_H_
