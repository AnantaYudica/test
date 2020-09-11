#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/arg/val/param/At.h"
#include "test/Variable.h"
#include "test/out/CString.h"

#include <cstddef>
#include <cassert>
#include <cstdarg>

struct CaseA1 {};

test::out::CString<char> gl_out_cstr1;

std::size_t Func1(int&& i)
{
    return gl_out_cstr1.Print("%d", i);
}

std::size_t Func1(double&& d, int&& i)
{
    return gl_out_cstr1.Print("%f%d", d, i);
}

std::size_t Func2(int size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = gl_out_cstr1.VPrint("%d", args);
    va_end(args);
    return ret;
}

std::size_t Func3(int size, ...)
{
    va_list args;
    va_start(args, size);
    auto ret = gl_out_cstr1.VPrint("%f%d", args);
    va_end(args);
    return ret;
}

struct Obj1
{
        
    Obj1() = default;
    std::size_t Func1(int&& i)
    {
        return gl_out_cstr1.Print("%d", i);
    }

    std::size_t Func1(double&& d, int&& i)
    {
        return gl_out_cstr1.Print("%f%d", d, i);
    }

    std::size_t Func2(int size, ...)
    {
        va_list args;
        va_start(args, size);
        auto ret = gl_out_cstr1.VPrint("%d", args);
        va_end(args);
        return ret;
    }

    std::size_t Func3(int size, ...)
    {
        va_list args;
        va_start(args, size);
        auto ret = gl_out_cstr1.VPrint("%f%d", args);
        va_end(args);
        return ret;
    }

};

int main()
{
    test::msg::Argument<test::msg::arg::val::param::At<0, 0>> arg_param0;
    test::msg::Argument<test::msg::arg::val::param::At<2, 0>,
        test::msg::arg::val::param::At<0, 1>> arg_param1;

    test::Variable<test::val::Parameter<int, int>, int,
        test::val::Parameter<double, int>> var1{22, -30, 3.14, 200};
     
    test::out::CString<char> out_cstr1;

    auto res_a = out_cstr1.Print("%d", 22);
    auto res_b = arg_param0.Call<std::size_t>(CaseA1{}, Func1, var1);
    auto res_c = arg_param0.Call<std::size_t>(CaseA1{}, Func2, var1, 1);
    auto res_d = arg_param0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    auto res_e = arg_param0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    Obj1 obj1;
    
    res_b = arg_param0.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_param0.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, 
        var1, 1);
    res_d = arg_param0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_param0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_param0.Get(test::type::Index<CaseA1, 0>{}, var1) == 22);

    res_a = out_cstr1.Print("%f%d", 3.14, -30);
    res_b = arg_param1.Call<std::size_t>(CaseA1{}, Func1, var1);
    res_c = arg_param1.Call<std::size_t>(CaseA1{}, Func3, var1, 2);
    res_d = arg_param1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    res_e = arg_param1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    res_b = arg_param1.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_param1.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, 
        var1, 2);
    res_d = arg_param1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_param1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_param1.Get(test::type::Index<CaseA1, 0>{}, var1) == 3.14);

    return TEST::GetInstance().Status().Get();
}
