#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/arg/type/Index.h"
#include "test/msg/arg/type/param/name/At.h"
#include "test/msg/arg/type/val/seq/At.h"
#include "test/def/type/Name.h"
#include "test/Variable.h"
#include "test/out/CString.h"

#include <cstddef>
#include <cassert>
#include <cstdarg>
#include <cstring>

struct CaseA1 {};

test::out::CString<char> gl_out_cstr1;

std::size_t Func1(const char*&& s)
{
    return gl_out_cstr1.Print("%s", s);
}

std::size_t Func1(int&& i, const char*&& s)
{
    return gl_out_cstr1.Print("%d%s", i, s);
}

std::size_t Func2(int size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = gl_out_cstr1.VPrint("%s", args);
    va_end(args);
    return ret;
}

std::size_t Func3(int size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = gl_out_cstr1.VPrint("%d%s", args);
    va_end(args);
    return ret;
}

struct Obj1
{
        
    Obj1() = default;
    std::size_t Func1(const char*&& s)
    {
        return gl_out_cstr1.Print("%s", s);
    }

    std::size_t Func1(int&& i, const char*&& s)
    {
        return gl_out_cstr1.Print("%d%s", i, s);
    }

    std::size_t Func2(int size, ...)
    {
        va_list args;
        va_start(args, size);
        auto ret = gl_out_cstr1.VPrint("%s", args);
        va_end(args);
        return ret;
    }

    std::size_t Func3(int size, ...)
    {
        va_list args;
        va_start(args, size);
        auto ret = gl_out_cstr1.VPrint("%d%s", args);
        va_end(args);
        return ret;
    }

};

int main()
{
    test::msg::Argument<test::msg::arg::type::Index<0,
        test::msg::arg::type::param::name::At>> arg_index0;
    test::msg::Argument<test::msg::arg::type::Index<2,
            test::msg::arg::type::val::seq::At>,
        test::msg::arg::type::Index<0, 
            test::msg::arg::type::param::name::At>> arg_index1;
        
    test::Variable<test::type::Parameter<char, float, long double, int>,
        int, test::type::val::Sequence<int, 1, 2, 3, 4>> var1;

    test::out::CString<char> out_cstr1;

    auto res_a = out_cstr1.Print("%s", "char");
    auto res_b = arg_index0.Call<std::size_t>(CaseA1{}, Func1, var1);
    auto res_c = arg_index0.Call<std::size_t>(CaseA1{}, Func2, var1, 1);
    auto res_d = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    auto res_e = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    Obj1 obj1;
    
    res_b = arg_index0.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_index0.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, 
        var1, 1);
    res_d = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(strcmp(*(arg_index0.Get(test::type::Index<CaseA1, 0>{}, var1)),
        "char") == 0);
    
    res_a = out_cstr1.Print("%s", "int");
    res_d = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        Func1, var1);
    res_e = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        Func2, var1, 1);
    assert(res_d == res_a);
    assert(res_e == res_a);

    res_d = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_index0.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        &Obj1::Func2, obj1, var1, 1);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    assert(strcmp(*(arg_index0.Get(test::type::Index<CaseA1, 3>{}, var1)),
        "int") == 0);
    
    res_a = out_cstr1.Print("%d%s", 1, "char");
    res_b = arg_index1.Call<std::size_t>(CaseA1{}, Func1, var1);
    res_c = arg_index1.Call<std::size_t>(CaseA1{}, Func3, var1, 2);
    res_d = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    res_e = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    res_b = arg_index1.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_index1.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, 
        var1, 2);
    res_d = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_index1.Get(test::type::Index<CaseA1, 0>{}, var1) == 1);

    res_a = out_cstr1.Print("%d%s", 4, "int");
    res_d = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        Func1, var1);
    res_e = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        Func3, var1, 2);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    res_d = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_index1.Call<std::size_t>(test::type::Index<CaseA1, 3>{}, 
        &Obj1::Func3, obj1, var1, 2);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_index1.Get(test::type::Index<CaseA1, 3>{}, var1) == 4);

    return TEST::GetInstance().Status().Get();
}
