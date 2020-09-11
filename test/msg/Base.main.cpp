#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/Variable.h"
#include "test/msg/arg/type/Name.h"
#include "test/msg/arg/type/Value.h"
#include "test/msg/arg/type/param/Name.h"
#include "test/msg/Base.h"
#include "test/def/type/Name.h"

#include "test/out/CString.h"

#include <cassert>
#include <utility>
#include <cstring>

struct TestA1 {};
struct TestA2 {};
struct TestA3 {};
struct TestA4 {};

typedef test::msg::Argument< 
    test::msg::arg::type::Name<0>> TypeName0Arg;

typedef test::msg::Argument< 
    test::msg::arg::type::Value<1>> TypeValue1Arg;
    
typedef test::msg::Argument< 
    test::msg::arg::Value<2>> Value2Arg;
typedef test::msg::Argument< 
    test::msg::arg::Value<3>> Value3Arg;
    
typedef test::msg::Argument< 
    test::msg::arg::type::Index<1,
        test::msg::arg::type::val::seq::At>> Index1AtArg;
typedef test::msg::Argument< 
    test::msg::arg::type::Index<2,
        test::msg::arg::type::val::seq::At>,
    test::msg::arg::Value<3>> Index2AtVal3Arg;

typedef test::msg::Case<TestA1, char, 
    test::msg::Tag<test::msg::tag::Debug, TypeValue1Arg>,
    test::msg::Tag<test::msg::tag::Info, TypeName0Arg>,
    test::msg::Tag<test::msg::tag::Error, Value2Arg>> CaseTestA1;
typedef test::msg::Case<TestA2, char, 
    test::msg::Tag<test::msg::tag::Debug, TypeValue1Arg>,
    test::msg::Tag<test::msg::tag::Info, TypeName0Arg>,
    test::msg::Tag<test::msg::tag::Error, Value2Arg>> CaseTestA2;
typedef test::msg::Case<TestA3, char, 
    test::msg::Tag<test::msg::tag::Debug, TypeValue1Arg>,
    test::msg::Tag<test::msg::tag::Info, TypeName0Arg>,
    test::msg::Tag<test::msg::tag::Error, Value2Arg>> CaseTestA3;
typedef test::msg::Case<TestA4, char,
    test::msg::Tag<test::msg::tag::Debug, Index1AtArg>,
    test::msg::Tag<test::msg::tag::Info, Index1AtArg>,
    test::msg::Tag<test::msg::tag::Error, Index1AtArg>,
    test::msg::Tag<test::type::Index<
        test::msg::tag::Debug, 1>, Index2AtVal3Arg>,
    test::msg::Tag<test::type::Index<
        test::msg::tag::Info, 1>, Index2AtVal3Arg>,
    test::msg::Tag<test::type::Index<
        test::msg::tag::Error, 1>, Index2AtVal3Arg>> CaseTestA4;

typedef test::msg::Base<char, CaseTestA1, CaseTestA2, CaseTestA3,
    CaseTestA4> MessageBase;

class TestA :
    public MessageBase
{
public:
    TestA()
    {
        test::msg::tag::Info info;
        test::msg::tag::Debug debug;
        test::msg::tag::Error error;
        test::type::Index<test::msg::tag::Info, 1> info1;
        test::type::Index<test::msg::tag::Debug, 1> debug1;
        test::type::Index<test::msg::tag::Error, 1> error1;
        TestA1 testa1;
        TestA2 testa2;
        TestA3 testa3;
        TestA4 testa4;
        test::msg::fmt::var::String<char> new_line{"\n"};

        test::msg::fmt::var::String<char> var_str_a1{"Test TestA1 : "};
        test::msg::Format<char> formatTestA1_i{
            var_str_a1,
            test::msg::fmt::var::String<char>{},
            new_line};
        test::msg::Format<char> formatTestA1_e{
            test::msg::fmt::var::String<char>{"Error msg "},
            test::msg::fmt::var::String<char>{},
            new_line};

        SetFormat(testa1, debug, 
            var_str_a1,
            test::msg::fmt::var::String<char>{"type "},
            test::msg::fmt::var::Integer<char>{},
            new_line);
        SetFormat(testa1, info, std::move(formatTestA1_i));
        SetFormat(testa1, error, formatTestA1_e);

        test::msg::fmt::var::String<char> var_str_a2{"Test TestA2 : "};
        test::msg::Format<char> formatTestA2_i{
            var_str_a2,
            test::msg::fmt::var::String<char>{},
            new_line};
        SetFormat(testa2, debug,  
            var_str_a2,
            test::msg::fmt::var::String<char>{"type "},
            test::msg::fmt::var::Integer<char>{},
            new_line);
        SetFormat(testa2, info, std::move(formatTestA2_i));
        SetFormat(testa2, error, formatTestA1_e);

        test::msg::fmt::var::String<char> var_str_a3{"Test TestA3 : "};
        test::msg::Format<char> formatTestA3_i{
            var_str_a3,
            test::msg::fmt::var::String<char>{},
            new_line};
        SetFormat(testa3, debug, 
            var_str_a3, 
            test::msg::fmt::var::String<char>{"type "},
            test::msg::fmt::var::Integer<char>{},
            new_line);
        SetFormat(testa3, info, std::move(formatTestA3_i));
        SetFormat(testa3, error, formatTestA1_e);

        test::msg::Format<char> formatTestA4_i{
            test::msg::fmt::var::String<char>{"Test TestA4 : "},
            test::msg::fmt::var::Integer<char>{},
            new_line};
        SetFormat(testa4, debug, 
            test::msg::fmt::var::String<char>{"debug type TestA4 "},
            test::msg::fmt::var::Integer<char>{}, new_line);
        SetFormat(testa4, info, std::move(formatTestA4_i));
        SetFormat(testa4, error, 
            test::msg::fmt::var::String<char>{"Error TestA4 msg "},
            test::msg::fmt::var::Integer<char>{}, new_line);

        test::msg::fmt::var::String<char> str{" str "};
        test::msg::Format<char> formatTestA4_i1{
            test::msg::fmt::var::String<char>{"info<1> Test TestA4 : "},
            test::msg::fmt::var::Integer<char>{},
            str, test::msg::fmt::var::String<char>{},
            new_line};
        SetFormat(testa4, debug1,  
            test::msg::fmt::var::String<char>{"debug<1> type TestA4 "},
            test::msg::fmt::var::Integer<char>{}, 
            str, test::msg::fmt::var::String<char>{},
            new_line);
        SetFormat(testa4, info1, std::move(formatTestA4_i1));
        SetFormat(testa4, error1, 
            test::msg::fmt::var::String<char>{"Error<1> TestA4 msg "},
            test::msg::fmt::var::Integer<char>{}, 
            str, test::msg::fmt::var::String<char>{}, new_line);
    }
};

int main()
{
    TestA testa;

    test::CString<char> cstr1("test");
    test::Variable<int, test::type::Value<int, 4>,
        test::Value<const char*>> var1(*cstr1);
    
    test::out::CString<char> out_cstr1, out_cstr2;

    TestA1 testa1;
    TestA2 testa2;
    TestA3 testa3;
    TestA4 testa4;
    test::type::Index<TestA4, 0> testa4_at0;
    test::type::Index<TestA4, 1> testa4_at1;
    test::type::Index<TestA4, 2> testa4_at2;
    test::msg::tag::Info info;
    test::msg::tag::Debug debug;
    test::msg::tag::Error error;
    test::type::Index<test::msg::tag::Info, 1> info1;
    test::type::Index<test::msg::tag::Debug, 1> debug1;
    test::type::Index<test::msg::tag::Error, 1> error1;
    {
        auto arg = testa.GetArgument(testa1, info);
        auto fmt = testa.GetFormat(testa1, info);
        auto ret_a = out_cstr1.Print("Test TestA1 : %s\n", "int");
        auto ret_b = arg.Call<std::size_t>(testa1, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa1, debug);
        auto fmt = testa.GetFormat(testa1, debug);
        auto ret_a = out_cstr1.Print("Test TestA1 : type %d\n", 4);
        auto ret_b = arg.Call<std::size_t>(testa1, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa1, error);
        auto fmt = testa.GetFormat(testa1, error);
        auto ret_a = out_cstr1.Print("Error msg %s\n", "test");
        auto ret_b = arg.Call<std::size_t>(testa1, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa2, info);
        auto fmt = testa.GetFormat(testa2, info);
        auto ret_a = out_cstr1.Print("Test TestA2 : %s\n", "int");
        auto ret_b = arg.Call<std::size_t>(testa2, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa2, debug);
        auto fmt = testa.GetFormat(testa2, debug);
        auto ret_a = out_cstr1.Print("Test TestA2 : type %d\n", 4);
        auto ret_b = arg.Call<std::size_t>(testa2, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa2, error);
        auto fmt = testa.GetFormat(testa2, error);
        auto ret_a = out_cstr1.Print("Error msg %s\n", "test");
        auto ret_b = arg.Call<std::size_t>(testa2, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa3, info);
        auto fmt = testa.GetFormat(testa3, info);
        auto ret_a = out_cstr1.Print("Test TestA3 : %s\n", "int");
        auto ret_b = arg.Call<std::size_t>(testa3, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa3, debug);
        auto fmt = testa.GetFormat(testa3, debug);
        auto ret_a = out_cstr1.Print("Test TestA3 : type %d\n", 4);
        auto ret_b = arg.Call<std::size_t>(testa3, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa3, error);
        auto fmt = testa.GetFormat(testa3, error);
        auto ret_a = out_cstr1.Print("Error msg %s\n", "test");
        auto ret_b = arg.Call<std::size_t>(testa3, 
            &test::msg::Format<char>::Output, fmt, var1,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    
    test::Variable<int, 
        test::type::val::Sequence<int, 14, 41, 444>,
        test::type::val::Sequence<int, 21, 14, 7>,
        test::Value<const char*>> var2(*cstr1);

    {
        auto arg = testa.GetArgument(testa4_at0, info);
        auto fmt = testa.GetFormat(testa4_at0, info);
        auto ret_a = out_cstr1.Print("Test TestA4 : %d\n", 14);
        auto ret_b = arg.Call<std::size_t>(testa4_at0, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at0, debug);
        auto fmt = testa.GetFormat(testa4_at0, debug);
        auto ret_a = out_cstr1.Print("debug type TestA4 %d\n", 14);
        auto ret_b = arg.Call<std::size_t>(testa4_at0, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at0, error);
        auto fmt = testa.GetFormat(testa4_at0, error);
        auto ret_a = out_cstr1.Print("Error TestA4 msg %d\n", 14);
        auto ret_b = arg.Call<std::size_t>(testa4_at0, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at1, info);
        auto fmt = testa.GetFormat(testa4_at1, info);
        auto ret_a = out_cstr1.Print("Test TestA4 : %d\n", 41);
        auto ret_b = arg.Call<std::size_t>(testa4_at1, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at1, debug);
        auto fmt = testa.GetFormat(testa4_at1, debug);
        auto ret_a = out_cstr1.Print("debug type TestA4 %d\n", 41);
        auto ret_b = arg.Call<std::size_t>(testa4_at1, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at1, error);
        auto fmt = testa.GetFormat(testa4_at1, error);
        auto ret_a = out_cstr1.Print("Error TestA4 msg %d\n", 41);
        auto ret_b = arg.Call<std::size_t>(testa4_at1, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at2, info);
        auto fmt = testa.GetFormat(testa4_at2, info);
        auto ret_a = out_cstr1.Print("Test TestA4 : %d\n", 444);
        auto ret_b = arg.Call<std::size_t>(testa4_at2, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at2, debug);
        auto fmt = testa.GetFormat(testa4_at2, debug);
        auto ret_a = out_cstr1.Print("debug type TestA4 %d\n", 444);
        auto ret_b = arg.Call<std::size_t>(testa4_at2, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at2, error);
        auto fmt = testa.GetFormat(testa4_at2, error);
        auto ret_a = out_cstr1.Print("Error TestA4 msg %d\n", 444);
        auto ret_b = arg.Call<std::size_t>(testa4_at2, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4, info1);
        auto fmt = testa.GetFormat(testa4, info1);
        auto ret_a = out_cstr1.Print("info<1> Test TestA4 : %d str %s\n",
            21, "test");
        auto ret_b = arg.Call<std::size_t>(testa4, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4, debug1);
        auto fmt = testa.GetFormat(testa4, debug1);
        auto ret_a = out_cstr1.Print("debug<1> type TestA4 %d str %s\n",
            21, "test");
        auto ret_b = arg.Call<std::size_t>(testa4, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4, error1);
        auto fmt = testa.GetFormat(testa4, error1);
        auto ret_a = out_cstr1.Print("Error<1> TestA4 msg %d str %s\n",
            21, "test");
        auto ret_b = arg.Call<std::size_t>(testa4, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    
    {
        auto arg = testa.GetArgument(testa4_at0, info1);
        auto fmt = testa.GetFormat(testa4_at0, info1);
        auto ret_a = out_cstr1.Print("info<1> Test TestA4 : %d str %s\n",
            21, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at0, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at0, debug1);
        auto fmt = testa.GetFormat(testa4_at0, debug1);
        auto ret_a = out_cstr1.Print("debug<1> type TestA4 %d str %s\n",
            21, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at0, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at0, error1);
        auto fmt = testa.GetFormat(testa4_at0, error1);
        auto ret_a = out_cstr1.Print("Error<1> TestA4 msg %d str %s\n",
            21, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at0, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    
    {
        auto arg = testa.GetArgument(testa4_at1, info1);
        auto fmt = testa.GetFormat(testa4_at1, info1);
        auto ret_a = out_cstr1.Print("info<1> Test TestA4 : %d str %s\n",
            14, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at1, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at1, debug1);
        auto fmt = testa.GetFormat(testa4_at1, debug1);
        auto ret_a = out_cstr1.Print("debug<1> type TestA4 %d str %s\n",
            14, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at1, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at1, error1);
        auto fmt = testa.GetFormat(testa4_at1, error1);
        auto ret_a = out_cstr1.Print("Error<1> TestA4 msg %d str %s\n",
            14, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at1, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at2, info1);
        auto fmt = testa.GetFormat(testa4_at2, info1);
        auto ret_a = out_cstr1.Print("info<1> Test TestA4 : %d str %s\n",
            7, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at2, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at2, debug1);
        auto fmt = testa.GetFormat(testa4_at2, debug1);
        auto ret_a = out_cstr1.Print("debug<1> type TestA4 %d str %s\n",
            7, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at2, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    {
        auto arg = testa.GetArgument(testa4_at2, error1);
        auto fmt = testa.GetFormat(testa4_at2, error1);
        auto ret_a = out_cstr1.Print("Error<1> TestA4 msg %d str %s\n",
            7, "test");
        auto ret_b = arg.Call<std::size_t>(testa4_at2, 
            &test::msg::Format<char>::Output, fmt, var2,
            (test::out::Interface<char>&)out_cstr2);
        fmt.Unset();
        assert(ret_a == ret_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()),
            out_cstr2.Size()) == 0);
    }
    return TEST::GetInstance().Status().Get();
}

