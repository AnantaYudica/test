#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Value.h"

#include <cmath>
#include <cstring>
#include <cassert>

enum EObj1
{
    value_a,
    value_b
};

template<>
struct test::type::Name<int>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar name[] = "int";
        return {name};
    }
}; 

template<>
struct test::type::Name<bool>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar name[] = "bool";
        return {name};
    }
}; 

template<>
struct test::type::Name<EObj1>
{
    template<typename TChar= char>
    static test::CString<const TChar> CStr()
    {
        static TChar name[] = "EObj1";
        return {name};
    }
}; 

template<>
struct test::type::name::val::Get<int>
{
    template<int V, typename TChar = char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            (V > 0 ? (log10(V) + 1) : (V < 0 ? (log10(abs(V)) + 2) : 1)) + 1, 
            "%d", V);
        return {_val};
    }
};

template<>
struct test::type::name::val::Get<bool>
{
    template<bool V, typename TChar = char>
    static test::CString<TChar> CStr()
    {
        test::CString<TChar> _val = test::cstr::Format(
            V ? 5 : 6 , "%s", V ? "true" : "false");
        return {_val};
    }
};

template<>
struct test::type::name::val::Enumeration<EObj1, EObj1::value_a>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar _val[] = "value_a";
        return {_val};
    }
};

template<>
struct test::type::name::val::Enumeration<EObj1, EObj1::value_b>
{
    template<typename TChar= char>
    static test::CString<TChar> CStr()
    {
        static TChar _val[] = "value_b";
        return {_val};
    }
};

int main()
{
    assert(strcmp(*(test::type::name::Value<int, 40>::CStr()), 
        "(int) 40") == 0);
    assert(strcmp(*(test::type::name::Value<int, -120>::CStr()), 
        "(int) -120") == 0);
    assert(strcmp(*(test::type::name::Value<int, 0>::CStr()), 
        "(int) 0") == 0);
    assert(strcmp(*(test::type::name::Value<bool, true>::CStr()), 
        "(bool) true") == 0);
    assert(strcmp(*(test::type::name::Value<bool, false>::CStr()), 
        "(bool) false") == 0);
    assert(strcmp(*(test::type::name::Value<EObj1, EObj1::value_a>::CStr()), 
        "(EObj1) value_a") == 0);
    assert(strcmp(*(test::type::name::Value<EObj1, EObj1::value_b>::CStr()), 
        "(EObj1) value_b") == 0);

    return TEST::GetInstance().Status().Get();
}

