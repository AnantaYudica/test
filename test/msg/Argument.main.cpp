#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/Argument.h"
#include "test/msg/arg/type/Name.h"
#include "test/msg/arg/type/Value.h"
#include "test/msg/arg/type/Function.h"
#include "test/msg/arg/type/val/Sequence.h"
#include "test/msg/arg/type/val/seq/At.h"
#include "test/msg/arg/type/param/Name.h"
#include "test/msg/arg/type/param/name/At.h"
#include "test/msg/arg/Value.h"
#include "test/msg/arg/val/Function.h"
#include "test/msg/arg/val/Parameter.h"
#include "test/msg/arg/val/Sequence.h"
#include "test/msg/arg/val/param/At.h"
#include "test/msg/arg/val/seq/At.h"

#include "test/msg/arg/type/Index.h"
#include "test/type/Index.h"

#include "test/def/type/Name.h"
#include "test/CString.h"
#include "test/out/CString.h"

#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdarg>

struct TestA1 {};

test::out::CString<char> gl_out_cstr1;

class ATest
{
public:
    std::size_t Print1(test::out::CString<char>*)
    {
        return 0;
    }
    std::size_t VPrint1(test::out::CString<char>*, ...)
    {
        return 0;
    }
    template<typename... TArgs>
    std::size_t Print2(test::out::CString<char>* out, TArgs&&... args)
    {
        auto ret =  out->Print("n0: %s, n1: %s, n2: %s, pn3: [%s, %s, %s], "
        "pn3a0: %s, pn3a2: %s, tv4: %d, tv5: %c, tvs6: [%d, %d, %d, %d, %d], "
        "tvs6a0 : %d, tvs6a4: %d, tf7n2: %d, tf8tv4: %d, tf9v5: %d, "
        "v10: %d, vp11: [%d, %c], vp11a0: %d, vp11a1: %c, "
        "vs12: [%d, %d, %d, %d, %d], vs12a0: %d, vs12a4: %d, vf13pn3a1: %d, "
        "vf14v10: %d, vf14vp11a1: %d\n", std::forward<TArgs>(args)...);
        return ret;
    }
    std::size_t VPrint2(test::out::CString<char>* out, ...)
    {
        va_list args;
        va_start(args, out);
        auto ret =  out->VPrint("n0: %s, n1: %s, n2: %s, pn3: [%s, %s, %s], "
        "pn3a0: %s, pn3a2: %s, tv4: %d, tv5: %c, tvs6: [%d, %d, %d, %d, %d], "
        "tvs6a0 : %d, tvs6a4: %d, tf7n2: %d, tf8tv4: %d, tf9v5: %d, "
        "v10: %d, vp11: [%d, %c], vp11a0: %d, vp11a1: %c, "
        "vs12: [%d, %d, %d, %d, %d], vs12a0: %d, vs12a4: %d, vf13pn3a1: %d, "
        "vf14v10: %d, vf14vp11a1: %d\n", args);
        va_end(args);
        return ret;
    }
    std::size_t Print3(test::out::CString<char>* out, const char* && s,
        int&& i1 , char&& p, int&& i2)
    {
        return out->Print("%s, %d, %c, %d", s, i1, p, i2);
    }
    std::size_t Print3(test::out::CString<char>* out, const char* && s,
        int&& i1 , short&& p, int&& i2)
    {
        return out->Print("%s, %d, %hd, %d", s, i1, p, i2);
    }
    std::size_t Print3(test::out::CString<char>* out, const char* && s,
        int&& i1 , int&& p, int&& i2)
    {
        return out->Print("%s, %d, %d, %d", s, i1, p, i2);
    }
    std::size_t Print3(test::out::CString<char>* out, const char* && s,
        int&& i1 , long&& p, int&& i2)
    {
        return out->Print("%s, %d, %ld, %d", s, i1, p, i2);
    }
};

std::size_t Print1(test::out::CString<char>*)
{
    return 0;
}

std::size_t VPrint1(test::out::CString<char>*, ...)
{
    return 0;
}

template<typename... TArgs>
std::size_t Print2(test::out::CString<char>* out, TArgs&&... args)
{
    auto ret =  out->Print("n0: %s, n1: %s, n2: %s, pn3: [%s, %s, %s], "
        "pn3a0: %s, pn3a2: %s, tv4: %d, tv5: %c, tvs6: [%d, %d, %d, %d, %d], "
        "tvs6a0 : %d, tvs6a4: %d, tf7n2: %d, tf8tv4: %d, tf9v5: %d, "
        "v10: %d, vp11: [%d, %c], vp11a0: %d, vp11a1: %c, "
        "vs12: [%d, %d, %d, %d, %d], vs12a0: %d, vs12a4: %d, vf13pn3a1: %d, "
        "vf14v10: %d, vf14vp11a1: %d\n", std::forward<TArgs>(args)...);
    return ret;
}

std::size_t VPrint2(test::out::CString<char>* out, ...)
{
    va_list args;
    va_start(args, out);
    auto ret =  out->VPrint("n0: %s, n1: %s, n2: %s, pn3: [%s, %s, %s], "
    "pn3a0: %s, pn3a2: %s, tv4: %d, tv5: %c, tvs6: [%d, %d, %d, %d, %d], "
    "tvs6a0 : %d, tvs6a4: %d, tf7n2: %d, tf8tv4: %d, tf9v5: %d, "
    "v10: %d, vp11: [%d, %c], vp11a0: %d, vp11a1: %c, "
    "vs12: [%d, %d, %d, %d, %d], vs12a0: %d, vs12a4: %d, vf13pn3a1: %d, "
    "vf14v10: %d, vf14vp11a1: %d\n", args);
    va_end(args);
    return ret;
}

std::size_t Print3(test::out::CString<char>* out, const char* && s,
    int&& i1 , char&& p, int&& i2)
{
    return out->Print("%s, %d, %c, %d", s, i1, p, i2);
}
std::size_t Print3(test::out::CString<char>* out, const char* && s,
    int&& i1 , short&& p, int&& i2)
{
    return out->Print("%s, %d, %hd, %d", s, i1, p, i2);
}
std::size_t Print3(test::out::CString<char>* out, const char* && s,
    int&& i1 , int&& p, int&& i2)
{
    return out->Print("%s, %d, %d, %d", s, i1, p, i2);
}
std::size_t Print3(test::out::CString<char>* out, const char* && s,
    int&& i1 , long&& p, int&& i2)
{
    return out->Print("%s, %d, %ld, %d", s, i1, p, i2);
}

int Func1(const char* && cstr)
{
    return strlen(cstr);
}

int Func2(int&& i)
{
    return i;
}

int Func3(char&& c)
{
    return (int)c;
}

int main()
{
    test::out::CString<char> out_cstr1, out_cstr2, out_cstr3, out_cstr4;

    ATest a1;
    test::Variable<> var1;
    test::msg::Argument<> arg1;
    std::size_t res_a = 0;
    auto res_b = arg1.Call<std::size_t>(TestA1{}, &Print1, 
        var1, &out_cstr1);
    auto res_c = arg1.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &Print1, var1, &out_cstr2);
    auto res_d = arg1.Call<std::size_t>(TestA1{}, &ATest::Print1, a1,
        var1, &out_cstr3);
    auto res_e = arg1.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &ATest::Print1, a1, var1, &out_cstr4);

    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr1.Size());
    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr3.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr1.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr3.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
        
    res_a = 0;
    res_b = arg1.Call<std::size_t>(TestA1{}, &VPrint1, 
        var1, &out_cstr1);
    res_c = arg1.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &VPrint1, var1, &out_cstr2);
    res_d = arg1.Call<std::size_t>(TestA1{}, &ATest::VPrint1, a1,
        var1, &out_cstr3);
    res_e = arg1.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &ATest::VPrint1, a1, var1, &out_cstr4);

    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr1.Size());
    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr3.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr1.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr3.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
        
    test::Variable<int, char, double,
        test::type::Parameter<int, char, double>,
        test::type::Value<int, 1234>,
        test::type::Value<char, 'B'>,
        test::type::val::Sequence<int, 10, 11, 12, 13, 14>,
        test::type::Function<decltype(Func1), &Func1>,
        test::type::Function<decltype(Func2), &Func2>,
        test::type::Function<decltype(Func3), &Func3>,
        test::Value<int>,
        test::val::Parameter<int, char>,
        test::val::Sequence<int, 5>,
        test::val::Function<decltype(Func1)>,
        test::val::Function<decltype(Func2)>,
        test::val::Function<decltype(Func3)>> var2{5678, -3210, 'Y', 
            90, 91, 92, 93, 94, &Func1, &Func2, &Func3};

    test::msg::Argument<
        test::msg::arg::type::Name<0>,
        test::msg::arg::type::Name<1>,
        test::msg::arg::type::Name<2>,
        test::msg::arg::type::param::Name<3>,
        test::msg::arg::type::param::name::At<3, 0>,
        test::msg::arg::type::param::name::At<3, 2>,
        test::msg::arg::type::Value<4>,
        test::msg::arg::type::Value<5>,
        test::msg::arg::type::val::Sequence<6>,
        test::msg::arg::type::val::seq::At<6, 0>,
        test::msg::arg::type::val::seq::At<6, 4>,
        test::msg::arg::type::Function<7, 
            test::msg::arg::type::Name<2>>,
        test::msg::arg::type::Function<8,
            test::msg::arg::type::Value<4>>,
        test::msg::arg::type::Function<9,
            test::msg::arg::type::Value<5>>,
        test::msg::arg::Value<10>,
        test::msg::arg::val::Parameter<11>,
        test::msg::arg::val::param::At<11, 0>,
        test::msg::arg::val::param::At<11, 1>,
        test::msg::arg::val::Sequence<12>,
        test::msg::arg::val::seq::At<12, 0>,
        test::msg::arg::val::seq::At<12, 4>,
        test::msg::arg::val::Function<13,
            test::msg::arg::type::param::name::At<3, 1>>,
        test::msg::arg::val::Function<14,
            test::msg::arg::Value<10>>,
        test::msg::arg::val::Function<15,
            test::msg::arg::val::param::At<11, 1>>> arg2;
    
    res_a = Print2(&gl_out_cstr1, "int", "char", "double", "int", "char", 
        "double", "int", "double", 1234, 'B', 10, 11, 12, 13, 14, 10, 14, 
        (int)strlen("double"), 1234, (int)'B', 5678, -3210, 'Y', -3210, 'Y',
        90, 91, 92, 93, 94, 90, 94, (int)strlen("char"), 5678, (int)'Y');
    res_b = arg2.Call<std::size_t>(TestA1{}, &Print2, 
        var2, &out_cstr1);
    res_c = arg2.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &Print2, var2, &out_cstr2);
    res_d = arg2.Call<std::size_t>(TestA1{}, &ATest::Print2, a1,
        var2, &out_cstr3);
    res_e = arg2.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &ATest::Print2, a1, var2, &out_cstr4);
    
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr1.Size());
    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr3.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr1.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr3.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);

    res_a = Print2(&gl_out_cstr1, "int", "char", "double", "int", "char", 
        "double", "int", "double", 1234, 'B', 10, 11, 12, 13, 14, 10, 14, 
        (int)strlen("double"), 1234, (int)'B', 5678, -3210, 'Y', -3210, 'Y',
        90, 91, 92, 93, 94, 90, 94, (int)strlen("char"), 5678, (int)'Y');
    res_b = arg2.Call<std::size_t>(TestA1{}, &VPrint2, 
        var2, &out_cstr1);
    res_c = arg2.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &VPrint2, var2, &out_cstr2);
    res_d = arg2.Call<std::size_t>(TestA1{}, &ATest::VPrint2, a1,
        var2, &out_cstr3);
    res_e = arg2.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &ATest::VPrint2, a1, var2, &out_cstr4);
    
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr1.Size());
    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr3.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr1.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr3.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);

    test::Variable<test::type::Parameter<char, short, int, long>,
        test::type::val::Sequence<int, 0, 1, 2, 3>,
        test::val::Parameter<char, short, int, long>,
        test::val::Sequence<int, 4>> var3{'A', 1000, 2000, 3000,
            3, 2, 1, 0};
    
    test::msg::Argument<
        test::msg::arg::type::Index<0,
            test::msg::arg::type::param::name::At>,
        test::msg::arg::type::Index<1,
            test::msg::arg::type::val::seq::At>,
        test::msg::arg::type::Index<2,
            test::msg::arg::val::param::At>,
        test::msg::arg::type::Index<3,
            test::msg::arg::val::seq::At>> arg3;

    res_a = Print3(&gl_out_cstr1, "char", 0, 'A', 3);
    res_b = arg3.Call<std::size_t>(TestA1{}, &Print3, 
        var3, &out_cstr1);
    res_c = arg3.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &Print3, var3, &out_cstr2);
    res_d = arg3.Call<std::size_t>(TestA1{}, &ATest::Print3, a1,
        var3, &out_cstr3);
    res_e = arg3.Call<std::size_t>(test::type::Index<TestA1, 0>{},
        &ATest::Print3, a1, var3, &out_cstr4);
    
    assert(res_a == res_b);
    assert(res_a == res_c);
    assert(res_a == res_d);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr1.Size());
    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr3.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr1.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr3.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);

    res_a = Print3(&gl_out_cstr1, "short", 1, 1000, 2);
    res_c = arg3.Call<std::size_t>(test::type::Index<TestA1, 1>{},
        &Print3, var3, &out_cstr2);
    res_e = arg3.Call<std::size_t>(test::type::Index<TestA1, 1>{},
        &ATest::Print3, a1, var3, &out_cstr4);
    
    assert(res_a == res_c);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);

    res_a = Print3(&gl_out_cstr1, "int", 2, 2000, 1);
    res_c = arg3.Call<std::size_t>(test::type::Index<TestA1, 2>{},
        &Print3, var3, &out_cstr2);
    res_e = arg3.Call<std::size_t>(test::type::Index<TestA1, 2>{},
        &ATest::Print3, a1, var3, &out_cstr4);
    
    assert(res_a == res_c);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);

    res_a = Print3(&gl_out_cstr1, "long", 3, 3000, 0);
    res_c = arg3.Call<std::size_t>(test::type::Index<TestA1, 3>{},
        &Print3, var3, &out_cstr2);
    res_e = arg3.Call<std::size_t>(test::type::Index<TestA1, 3>{},
        &ATest::Print3, a1, var3, &out_cstr4);
    
    assert(res_a == res_c);
    assert(res_a == res_e);

    assert(gl_out_cstr1.Size() == out_cstr2.Size());
    assert(gl_out_cstr1.Size() == out_cstr4.Size());
    assert(strncmp(*(out_cstr2.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);
    assert(strncmp(*(out_cstr4.Get()), *(gl_out_cstr1.Get()),
        gl_out_cstr1.Size()) == 0);

    return TEST::GetInstance().Status().Get();
}

