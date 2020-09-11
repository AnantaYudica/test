#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/arg/type/param/Name.h"
#include "test/def/type/Name.h"
#include "test/Variable.h"
#include "test/out/CString.h"

#include <cstddef>
#include <cassert>
#include <cstdarg>
#include <cstring>

struct CaseA1 {};

test::out::CString<char> gl_out_cstr1;

std::size_t Func1(const char*&& s1, const char*&& s2, 
    const char*&& s3, const char*&& s4)
{
    return gl_out_cstr1.Print("%s%s%s%s", s1, s2, s3, s4);
}

std::size_t Func1(const char*&& s1, const char*&& s2, 
    const char*&& s3, const char*&& s4, const char*&& s5,
    const char*&& s6, const char*&& s7)
{
    return gl_out_cstr1.Print("%s%s%s%s%s%s%s", s1, s2, s3, s4, s5, s6, s7);
}

std::size_t Func2(int size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = gl_out_cstr1.VPrint("%s%s%s%s", args);
    va_end(args);
    return ret;
}

std::size_t Func3(int size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = gl_out_cstr1.VPrint("%s%s%s%s%s%s%s", args);
    va_end(args);
    return ret;
}

struct Obj1
{
        
    Obj1() = default;
    std::size_t Func1(const char*&& s1, const char*&& s2, 
        const char*&& s3, const char*&& s4)
    {
        return gl_out_cstr1.Print("%s%s%s%s", s1, s2, s3, s4);
    }

    std::size_t Func1(const char*&& s1, const char*&& s2, 
        const char*&& s3, const char*&& s4, const char*&& s5,
        const char*&& s6, const char*&& s7)
    {
        return gl_out_cstr1.Print("%s%s%s%s%s%s%s", 
            s1, s2, s3, s4, s5, s6, s7);
    }

    std::size_t Func2(int size, ...)
    {
        va_list args;
        va_start(args, size);
        auto ret = gl_out_cstr1.VPrint("%s%s%s%s", args);
        va_end(args);
        return ret;
    }

    std::size_t Func3(int size, ...)
    {
        va_list args;
        va_start(args, size);
        auto ret = gl_out_cstr1.VPrint("%s%s%s%s%s%s%s", args);
        va_end(args);
        return ret;
    }

};

int main()
{
    test::msg::Argument<test::msg::arg::type::param::Name<0>> arg_name0;
    test::msg::Argument<test::msg::arg::type::param::Name<2>,
        test::msg::arg::type::param::Name<0>> arg_name1;
    
    test::Variable<test::type::Parameter<char, float, long double, int>,
        int, test::type::Parameter<unsigned char, signed char, long long>> var1;

    test::out::CString<char> out_cstr1;

    auto res_a = out_cstr1.Print("charfloatlong doubleint");
    auto res_b = arg_name0.Call<std::size_t>(CaseA1{}, Func1, var1);
    auto res_c = arg_name0.Call<std::size_t>(CaseA1{}, Func2, var1, 4);
    auto res_d = arg_name0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    auto res_e = arg_name0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var1, 4);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    Obj1 obj1;
    
    res_b = arg_name0.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_name0.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, var1, 4);
    res_d = arg_name0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_name0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var1, 4);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);
    
    assert(strcmp(*(arg_name0.Get<0>(test::type::Index<CaseA1, 0>{}, var1)), 
        "char")== 0);
    assert(strcmp(*(arg_name0.Get<1>(test::type::Index<CaseA1, 0>{}, var1)), 
        "float")== 0);
    assert(strcmp(*(arg_name0.Get<2>(test::type::Index<CaseA1, 0>{}, var1)), 
        "long double")== 0);
    assert(strcmp(*(arg_name0.Get<3>(test::type::Index<CaseA1, 0>{}, var1)), 
        "int")== 0);

    res_a = out_cstr1.Print("%s%s", "unsigned charsigned charlong long",
        "charfloatlong doubleint");
    res_b = arg_name1.Call<std::size_t>(CaseA1{}, Func1, var1);
    res_c = arg_name1.Call<std::size_t>(CaseA1{}, Func3, var1, 7);
    res_d = arg_name1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    res_e = arg_name1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var1, 7);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    res_b = arg_name1.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_name1.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, 
        var1, 7);
    res_d = arg_name1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_name1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var1, 7);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(strcmp(*(arg_name1.Get<0>(test::type::Index<CaseA1, 0>{}, var1)), 
        "unsigned char")== 0);
    assert(strcmp(*(arg_name1.Get<1>(test::type::Index<CaseA1, 0>{}, var1)), 
        "signed char")== 0);
    assert(strcmp(*(arg_name1.Get<2>(test::type::Index<CaseA1, 0>{}, var1)), 
        "long long")== 0);
        
    return TEST::GetInstance().Status().Get();
}
