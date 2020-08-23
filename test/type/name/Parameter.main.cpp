#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/type/name/Parameter.h"

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

int main()
{
    assert(strcmp(*(test::type::name::Parameter<int>::CStr()), "int") == 0);
    assert(strcmp(*(test::type::name::Parameter<int, int>::CStr()), 
        "int, int") == 0);
    assert(strcmp(*(test::type::name::Parameter<int, int, int>::CStr()), 
        "int, int, int") == 0);
    assert(strcmp(*(test::type::name::Parameter<
        test::type::name::Value<int, 10>>::CStr()), "(int) 10") == 0);
    assert(strcmp(*(test::type::name::Parameter<
        test::type::name::Value<int, 10>,
        test::type::name::Value<int, 0>>::CStr()), "(int) 10, (int) 0") == 0);
    assert(strcmp(*(test::type::name::Parameter<
        test::type::name::Value<int, 10>,
        test::type::name::Value<int, 0>,
        test::type::name::Value<int, -6>>::CStr()), 
        "(int) 10, (int) 0, (int) -6") == 0);
        
    return TEST::GetInstance().Status().Get();
}
