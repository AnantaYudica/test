#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/arg/val/seq/At.h"
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

std::size_t Func1(int&& i1, int&& i2)
{
    return gl_out_cstr1.Print("%d%d", i1, i2);
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
    auto ret = gl_out_cstr1.VPrint("%d%d", args);
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

    std::size_t Func1(int&& i1, int&& i2)
    {
        return gl_out_cstr1.Print("%d%d", i1, i2);
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
        auto ret = gl_out_cstr1.VPrint("%d%d", args);
        va_end(args);
        return ret;
    }

};

int main()
{
    test::msg::Argument<test::msg::arg::val::seq::At<0, 3>> arg_seq0;
    test::msg::Argument<test::msg::arg::val::seq::At<2, 0>,
        test::msg::arg::val::seq::At<0, 1>> arg_seq1;
    
    test::Variable<test::val::Sequence<int, 4>, int,
        test::val::Sequence<int, 2>> var1{-1, 2, 40, -2, 4, 9};

    test::out::CString<char> out_cstr1;

    auto res_a = out_cstr1.Print("%d", -2);
    auto res_b = arg_seq0.Call<std::size_t>(CaseA1{}, Func1, var1);
    auto res_c = arg_seq0.Call<std::size_t>(CaseA1{}, Func2, var1, 1);
    auto res_d = arg_seq0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    auto res_e = arg_seq0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func2, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    Obj1 obj1;
    
    res_b = arg_seq0.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_seq0.Call<std::size_t>(CaseA1{}, &Obj1::Func2, obj1, 
        var1, 1);
    res_d = arg_seq0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_seq0.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func2, obj1, var1, 1);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_seq0.Get(test::type::Index<CaseA1, 0>{}, var1) == -2);

    res_a = out_cstr1.Print("%d%d", 4, 2);
    res_b = arg_seq1.Call<std::size_t>(CaseA1{}, Func1, var1);
    res_c = arg_seq1.Call<std::size_t>(CaseA1{}, Func3, var1, 2);
    res_d = arg_seq1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func1, var1);
    res_e = arg_seq1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        Func3, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);
    
    res_b = arg_seq1.Call<std::size_t>(CaseA1{}, &Obj1::Func1, obj1, var1);
    res_c = arg_seq1.Call<std::size_t>(CaseA1{}, &Obj1::Func3, obj1, 
        var1, 2);
    res_d = arg_seq1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func1, obj1, var1);
    res_e = arg_seq1.Call<std::size_t>(test::type::Index<CaseA1, 0>{}, 
        &Obj1::Func3, obj1, var1, 2);
    assert(res_a == res_b);
    assert(res_c == res_a);
    assert(res_d == res_a);
    assert(res_e == res_a);

    assert(arg_seq1.Get(test::type::Index<CaseA1, 0>{}, var1) == 4);

    return TEST::GetInstance().Status().Get();
}
