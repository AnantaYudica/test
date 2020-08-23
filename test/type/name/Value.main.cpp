#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Value.h"

#include <cmath>
#include <cstring>
#include <cassert>

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
struct test::type::name::val::Get<int>
{
    template<typename TChar = char>
    static test::CString<TChar> CStr(int v)
    {
        test::CString<TChar> _val = test::cstr::Format(
            (v > 0 ? (log10(v) + 1) : (v < 0 ? (log10(abs(v)) + 2) : 1)) + 1, 
            "%d", v);
        return {_val};
    }
};

template<>
struct test::type::name::val::Get<bool>
{
    template<typename TChar = char>
    static test::CString<TChar> CStr(bool v)
    {
        test::CString<TChar> _val = test::cstr::Format(
            v ? 5 : 6 , "%s", v ? "true" : "false");
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

    return TEST::GetInstance().Status().Get();
}
