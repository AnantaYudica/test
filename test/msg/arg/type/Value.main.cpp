#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/arg/type/Value.h"
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

std::size_t Func1(unsigned long&& ul, int&& i)
{
    return gl_out_cstr1.Print("%lu%d", ul, i);
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
    auto ret = gl_out_cstr1.VPrint("%lu%d", args);
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

    std::size_t Func1(unsigned long&& ul, int&& i)
    {
        return gl_out_cstr1.Print("%lu%d", ul, i);
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
        auto ret = gl_out_cstr1.VPrint("%lu%d", args);
        va_end(args);
        return ret;
    }

};

int main()
{
    test::msg::Argument<test::msg::arg::type::Value<0>> arg_value0;
    test::msg::Argument<test::msg::arg::type::Value<2>,
        test::msg::arg::type::Value<0>> arg_value1;

    
    test::Variable<test::type::Value<int, -4000>, int,
        test::type::Value<unsigned long, 30000>> var1;

    test::out::CString<char> out_cstr1;

    auto res_a = out_cstr1.Print("%d", -4000);
    auto res_b = arg_value0.Call<std::size_t>(CaseA1{}, Func1, var1);
    auto res_c = arg_value0.Call<std::size_t>(CaseA1{}, Func2, var1, 1);
    auto res_d = arg_value0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    auto res_e = arg_value0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    Obj1 obj1;
    
    res_b = arg_value0.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_value0.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, 
        var1, 1);
    res_d = arg_value0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_value0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_value0.Get(test::type::Index<CaseA1, 0>{}, var1) == -4000);

    res_a = out_cstr1.Print("%lu%d", 30000UL, -4000);
    res_b = arg_value1.Call<std::size_t>(CaseA1{}, Func1, var1);
    res_c = arg_value1.Call<std::size_t>(CaseA1{}, Func3, var1, 2);
    res_d = arg_value1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    res_e = arg_value1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    res_b = arg_value1.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_value1.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, 
        var1, 2);
    res_d = arg_value1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_value1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_value1.Get(test::type::Index<CaseA1, 0>{}, var1) == 30000);

    return TEST::GetInstance().Status().Get();
}
