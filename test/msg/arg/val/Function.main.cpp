#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/arg/Value.h"
#include "test/msg/arg/val/Function.h"
#include "test/Variable.h"
#include "test/out/CString.h"

#include <cstddef>
#include <cassert>
#include <cstdarg>

struct CaseA1 {};

test::out::CString<char> gl_out_cstr1;

int CallFunc1()
{
    return 1;
}

double CallFunc2()
{
    return 3.14;
}

int CallFunc3(int val)
{
    return val;
}

double CallFunc4(double val)
{
    return val;
}

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
    test::msg::Argument<test::msg::arg::val::Function<0>> arg_func0;
    test::msg::Argument<test::msg::arg::val::Function<0>,
        test::msg::arg::val::Function<1>> arg_func1;
    test::msg::Argument<test::msg::arg::val::Function<0,
        test::msg::arg::Value<1>>> arg_func2;
    test::msg::Argument<test::msg::arg::val::Function<0,
        test::msg::arg::Value<2>>, test::msg::arg::val::Function<1,
        test::msg::arg::Value<3>>> arg_func3;

    test::Variable<test::val::Function<decltype(CallFunc1)>> var1{&CallFunc1};
    test::Variable<test::val::Function<decltype(CallFunc2)>,
        test::val::Function<decltype(CallFunc1)>> var2{&CallFunc2, &CallFunc1};
    test::Variable<test::val::Function<decltype(CallFunc3)>,
        test::Value<int>> var3{&CallFunc3, 40};
    test::Variable<test::val::Function<decltype(CallFunc4)>,
        test::val::Function<decltype(CallFunc3)>,
        test::Value<double>, test::Value<int>> var4{&CallFunc4, &CallFunc3, 
            6.28, 40};
     
    test::out::CString<char> out_cstr1;

    auto res_a = out_cstr1.Print("%d", 1);
    auto res_b = arg_func0.Call<std::size_t>(CaseA1{}, Func1, var1);
    auto res_c = arg_func0.Call<std::size_t>(CaseA1{}, Func2, var1, 1);
    auto res_d = arg_func0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    auto res_e = arg_func0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var1, 1);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    Obj1 obj1;
    
    res_b = arg_func0.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_func0.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, var1, 1);
    res_d = arg_func0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_func0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var1, 1);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);
    
    assert(arg_func0.Get(test::type::Index<CaseA1, 0>{}, var1) == 1);

    res_a = out_cstr1.Print("%f%d", 3.14, 1);
    res_b = arg_func1.Call<std::size_t>(CaseA1{}, Func1, var2);
    res_c = arg_func1.Call<std::size_t>(CaseA1{}, Func3, var2, 2);
    res_d = arg_func1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var2);
    res_e = arg_func1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var2, 2);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);
    
    res_b = arg_func1.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var2);
    res_c = arg_func1.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, var2, 2);
    res_d = arg_func1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var2);
    res_e = arg_func1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var2, 2);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(arg_func1.Get(test::type::Index<CaseA1, 0>{}, var2) == 3.14);

    res_a = out_cstr1.Print("%d", 40);
    res_b = arg_func2.Call<std::size_t>(CaseA1{}, Func1, var3);
    res_c = arg_func2.Call<std::size_t>(CaseA1{}, Func2, var3, 1);
    res_d = arg_func2.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var3);
    res_e = arg_func2.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var3, 1);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);
    
    res_b = arg_func2.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var3);
    res_c = arg_func2.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, var3, 1);
    res_d = arg_func2.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var3);
    res_e = arg_func2.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var3, 1);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(arg_func2.Get(test::type::Index<CaseA1, 0>{}, var3) == 40);

    res_a = out_cstr1.Print("%f%d", 6.28, 40);
    res_b = arg_func3.Call<std::size_t>(CaseA1{}, Func1, var4);
    res_c = arg_func3.Call<std::size_t>(CaseA1{}, Func3, var4, 2);
    res_d = arg_func3.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var4);
    res_e = arg_func3.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var4, 2);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);
    
    res_b = arg_func3.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var4);
    res_c = arg_func3.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, var4, 2);
    res_d = arg_func3.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var4);
    res_e = arg_func3.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var4, 2);
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(arg_func3.Get(test::type::Index<CaseA1, 0>{}, var4) == 6.28);
   
    return TEST::GetInstance().Status().Get();
}
