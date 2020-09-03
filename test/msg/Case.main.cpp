#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/Case.h"
#include "test/msg/Tag.h"
#include "test/msg/Format.h"
#include "test/msg/Argument.h"
#include "test/Variable.h"
#include "test/def/type/Name.h"
#include "test/out/CString.h"

#include <utility>
#include <cassert>
#include <cstring>

struct CaseA1 {};

typedef test::msg::Argument< 
    test::msg::arg::type::Name<0>> TypeName0Arg;
typedef test::msg::Argument< 
    test::msg::arg::Value<1>> Value1Arg;

typedef test::msg::Argument< 
    test::msg::arg::type::Name<0>,  
    test::msg::arg::Value<1>>  TypeName0Value1Arg;

typedef test::msg::Argument< 
    test::msg::arg::type::Name<0>,  
    test::msg::arg::Value<1>,
    test::msg::arg::type::val::Sequence<2>> TypeName0Value1TypeValSeq2Arg;

typedef test::msg::Argument<
    test::msg::arg::type::Index<3,
        test::msg::arg::type::param::name::At>> TypeIndex3Arg;

typedef test::msg::Case<CaseA1, char, 
    test::msg::TagInfoIndex<9, TypeName0Value1TypeValSeq2Arg>,
    test::msg::TagInfo<TypeName0Arg>,
    test::msg::TagInfoIndex<0, Value1Arg>,
    test::msg::TagInfoIndex<1, TypeName0Value1Arg>,
    test::msg::TagDebugIndex<0, TypeIndex3Arg>> CaseA1Base;

class TestA : 
    public CaseA1Base
{
public:
   using CaseA1Base::SetFormat;
   using CaseA1Base::GetArgument;
   using CaseA1Base::GetFormat;
public:
    TestA() 
    {
        test::msg::tag::Info info{};
        test::type::Index<test::msg::tag::Info, 0> info_0{};
        test::type::Index<test::msg::tag::Info, 1> info_1{};
        test::type::Index<test::msg::tag::Info, 9> info_9{};
        test::type::Index<test::msg::tag::Debug, 0> debug_0{};

        auto format1 = test::msg::Format<char>{
            test::msg::fmt::var::String<char>{},
            test::msg::fmt::var::Integer<char>{}};

        auto format2 = test::msg::Format<char>{
            test::msg::fmt::var::String<char>{},
            test::msg::fmt::var::Integer<char>{},
            test::msg::fmt::var::Integer<char>{},
            test::msg::fmt::var::Integer<char>{},
            test::msg::fmt::var::Integer<char>{}};
        
        SetFormat(info, test::msg::fmt::var::String<char>{});
        SetFormat(info_0, test::msg::fmt::var::Integer<char>{});
        SetFormat(info_1, format1);
        SetFormat(info_9, std::move(format2));
        SetFormat(debug_0, test::msg::fmt::var::String<char>{});
    }
};

int main()
{
    TestA test_a;
    CaseA1 case_a1;
    test::type::Index<CaseA1, 0> case_a1_i0;
    test::type::Index<CaseA1, 1> case_a1_i1;
    test::type::Index<CaseA1, 2> case_a1_i2;


    test::Variable<int, 
        test::Value<int>,
        test::type::val::Sequence<int, 10, 20 ,30>,
        test::type::Parameter<float, double, long double>> var1{-46};
    
    {
        test::msg::tag::Info info{};
        auto arg_info = test_a.GetArgument(info);
        auto fmt_info = test_a.GetFormat(info);

        test::out::CString<char> out_cstr1, out_cstr2;

        auto ret_a = out_cstr1.Print("int");
        auto ret_b = arg_info.Call<std::size_t>(case_a1, 
            &test::msg::Format<char>::Output, fmt_info, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);

        fmt_info.Unset();
    }
    
    {
        test::type::Index<test::msg::tag::Info, 0> info_0{};
        auto arg_info = test_a.GetArgument(info_0);
        auto fmt_info = test_a.GetFormat(info_0);

        test::out::CString<char> out_cstr1, out_cstr2;

        auto ret_a = out_cstr1.Print("%d", -46);
        auto ret_b = arg_info.Call<std::size_t>(case_a1, 
            &test::msg::Format<char>::Output, fmt_info, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
        fmt_info.Unset();

    }
    
    {
        test::type::Index<test::msg::tag::Info, 1> info_1{};
        auto arg_info = test_a.GetArgument(info_1);
        auto fmt_info = test_a.GetFormat(info_1);

        test::out::CString<char> out_cstr1, out_cstr2;

        auto ret_a = out_cstr1.Print("int%d", -46);
        auto ret_b = arg_info.Call<std::size_t>(case_a1, 
            &test::msg::Format<char>::Output, fmt_info, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
        fmt_info.Unset();

    }
    
    {
        test::type::Index<test::msg::tag::Info, 9> info_9{};
        auto arg_info = test_a.GetArgument(info_9);
        auto fmt_info = test_a.GetFormat(info_9);

        test::out::CString<char> out_cstr1, out_cstr2;

        auto ret_a = out_cstr1.Print("int%d%d%d%d", -46, 10, 20 ,30);
        auto ret_b = arg_info.Call<std::size_t>(case_a1, 
            &test::msg::Format<char>::Output, fmt_info, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
        fmt_info.Unset();

    }

    {
        test::msg::tag::Debug debug{};
        auto arg_debug = test_a.GetArgument(debug);
        auto fmt_debug = test_a.GetFormat(debug);

        test::out::CString<char> out_cstr1, out_cstr2;

        auto ret_a = out_cstr1.Print("float");
        auto ret_b = arg_debug.Call<std::size_t>(case_a1, 
            &test::msg::Format<char>::Output, fmt_debug, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);

        fmt_debug.Unset();
        ret_a = out_cstr1.Print("float");
        ret_b = arg_debug.Call<std::size_t>(case_a1_i0, 
            &test::msg::Format<char>::Output, fmt_debug, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);

        fmt_debug.Unset();
        ret_a = out_cstr1.Print("double");
        ret_b = arg_debug.Call<std::size_t>(case_a1_i1, 
            &test::msg::Format<char>::Output, fmt_debug, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);

        fmt_debug.Unset();
        ret_a = out_cstr1.Print("long double");
        ret_b = arg_debug.Call<std::size_t>(case_a1_i2, 
            &test::msg::Format<char>::Output, fmt_debug, var1,
            (test::out::Interface<char>&)out_cstr2);
        assert(ret_a == ret_b);
        
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
        fmt_debug.Unset();

    }
    
    return TEST::GetInstance().Status().Get();
}