#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/def/type/Name.h"
#include "test/Register.h"

#include "test/Message.h"
#include "test/out/CString.h"

#include <utility>
#include <cassert>

struct TestA1 {};
struct TestA2 {};
struct TestA3 {};
struct TestA4 {};

typedef test::msg::Argument< 
    test::msg::arg::type::Name<0>> TName0;

typedef test::msg::Argument< 
    test::msg::arg::type::Value<1>> TValue1;
    
typedef test::msg::Argument< 
    test::msg::arg::Value<2>> Value2;

typedef test::msg::Argument< 
    test::msg::arg::type::Index<1,
        test::msg::arg::type::val::seq::At>> TIndex1;

typedef test::msg::Case<TestA1, char, 
    test::msg::Tag<test::msg::tag::Info, TName0>,
    test::msg::Tag<test::msg::tag::Debug, TValue1>, 
    test::msg::Tag<test::msg::tag::Error, Value2>,
    test::msg::Tag<test::type::Index<test::msg::tag::Info, 1>, TName0>,
    test::msg::Tag<test::type::Index<test::msg::tag::Debug, 1>, TValue1>, 
    test::msg::Tag<test::type::Index<test::msg::tag::Error, 1>, Value2>
    > CaseTestA1;
typedef test::msg::Case<TestA2, char, 
    test::msg::Tag<test::msg::tag::Info, TName0>,
    test::msg::Tag<test::msg::tag::Debug, TValue1>, 
    test::msg::Tag<test::msg::tag::Error, Value2>,
    test::msg::Tag<test::type::Index<test::msg::tag::Info, 1>, TName0>,
    test::msg::Tag<test::type::Index<test::msg::tag::Debug, 1>, TValue1>, 
    test::msg::Tag<test::type::Index<test::msg::tag::Error, 1>, Value2>> 
        CaseTestA2;
typedef test::msg::Case<TestA3, char, 
    test::msg::Tag<test::msg::tag::Info, TName0>,
    test::msg::Tag<test::msg::tag::Debug, TValue1>, 
    test::msg::Tag<test::msg::tag::Error, Value2>,
    test::msg::Tag<test::type::Index<test::msg::tag::Info, 1>, TName0>,
    test::msg::Tag<test::type::Index<test::msg::tag::Debug, 1>, TValue1>, 
    test::msg::Tag<test::type::Index<test::msg::tag::Error, 1>, Value2>> 
        CaseTestA3;
typedef test::msg::Case<TestA4, char, 
    test::msg::Tag<test::msg::tag::Info, TIndex1>,
    test::msg::Tag<test::msg::tag::Debug, TIndex1>, 
    test::msg::Tag<test::msg::tag::Error, TIndex1>,
    test::msg::Tag<test::type::Index<test::msg::tag::Info, 1>, TIndex1>,
    test::msg::Tag<test::type::Index<test::msg::tag::Debug, 1>, TIndex1>, 
    test::msg::Tag<test::type::Index<test::msg::tag::Error, 1>, TIndex1>> 
        CaseTestA4;

typedef test::msg::Base<char, CaseTestA1, CaseTestA2, CaseTestA3, 
    CaseTestA4> MessageBase;

class TestA :
    public MessageBase,
    public test::Message<TEST, TestA>
{
public:
    TestA() :
        test::Message<TEST, TestA>(*this)
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

        test::msg::fmt::var::String<char> var_str_a1{"Test TestA1 : "};

        test::msg::Format<char> formatTestA1_i{
            var_str_a1,
            test::msg::fmt::var::String<char>{}};
        SetFormat(testa1, debug, var_str_a1, 
            test::msg::fmt::var::String<char>{"type "},
            test::msg::fmt::var::Integer<char>{});
        SetFormat(testa1, info, std::move(formatTestA1_i));
        SetFormat(testa1, error, 
            test::msg::fmt::var::String<char>{"Error TestA1 msg "},
            test::msg::fmt::var::String<char>{});
        
        test::msg::Format<char> formatEmptyTestA1{
            test::msg::fmt::var::Nothing<char>{},
        };
        SetFormat(testa1, debug1, formatEmptyTestA1);
        SetFormat(testa1, info1, formatEmptyTestA1);
        SetFormat(testa1, error1, formatEmptyTestA1);

        test::msg::fmt::var::String<char> var_str_a2{"Test TestA2 : "};
        
        test::msg::Format<char> formatTestA2_i(var_str_a2,
            test::msg::fmt::var::String<char>{});
        SetFormat(testa2, debug, var_str_a2,
            test::msg::fmt::var::String<char>{"type "},
            test::msg::fmt::var::Integer<char>{});
        SetFormat(testa2, info, std::move(formatTestA2_i));
        SetFormat(testa2, error, 
            test::msg::fmt::var::String<char>{"Error TestA2 msg "},
            test::msg::fmt::var::String<char>{});
        
        SetFormat(testa2, debug1, formatEmptyTestA1);
        SetFormat(testa2, info1, formatEmptyTestA1);
        SetFormat(testa2, error1, formatEmptyTestA1);
        
        test::msg::fmt::var::String<char> var_str_a3{"Test TestA3 : "};
        
        test::msg::Format<char> formatTestA3_i(var_str_a3,
            test::msg::fmt::var::String<char>{});
        SetFormat(testa3, debug, var_str_a3,
            test::msg::fmt::var::String<char>{"type "},
            test::msg::fmt::var::Integer<char>{});
        SetFormat(testa3, info, std::move(formatTestA3_i));
        SetFormat(testa3, error,
            test::msg::fmt::var::String<char>{"Error TestA3 msg "},
            test::msg::fmt::var::String<char>{});
        
        SetFormat(testa3, debug1, formatEmptyTestA1);
        SetFormat(testa3, info1, formatEmptyTestA1);
        SetFormat(testa3, error1, formatEmptyTestA1);
        
        test::msg::fmt::var::String<char> var_str_a4{"Test TestA4 : "};

        test::msg::Format<char> formatTestA4_i(var_str_a4,
            test::msg::fmt::var::Integer<char>{});
        SetFormat(testa4, debug, 
            test::msg::fmt::var::String<char>{"debug type "},
            var_str_a4, test::msg::fmt::var::Integer<char>{});
        SetFormat(testa4, info, std::move(formatTestA4_i));
        SetFormat(testa4, error, 
            test::msg::fmt::var::String<char>{"error type "},
            var_str_a4, test::msg::fmt::var::Integer<char>{});

        SetFormat(testa4, debug1, formatEmptyTestA1);
        SetFormat(testa4, info1, formatEmptyTestA1);
        SetFormat(testa4, error1, formatEmptyTestA1);
    }
};

int main()
{
    TestA a;
    
    test::CString<char> cstr1("test");
    test::Variable<int, test::type::Value<int, 4>,
        test::Value<const char*>> var1(*cstr1);
    
    test::Variable<int, 
        test::type::val::Sequence<int, 143, -141, 30044>,
        test::Value<const char*>> var2(*cstr1);

    auto empty_info_a1 = a.IndexInfo<1>(TestA1(), var1);
    auto empty_debug_a1 = a.IndexDebug<1>(TestA1(), var1);
    auto empty_error_a1 = a.IndexError<1>(TestA1(), var1);
    auto empty_info_a2 = a.IndexInfo<1>(TestA2(), var1);
    auto empty_debug_a2 = a.IndexDebug<1>(TestA2(), var1);
    auto empty_error_a2 = a.IndexError<1>(TestA2(), var1);
    auto empty_info_a3 = a.IndexInfo<1>(TestA3(), var1);
    auto empty_debug_a3 = a.IndexDebug<1>(TestA3(), var1);
    auto empty_error_a3 = a.IndexError<1>(TestA3(), var1);
    auto empty_info_a4 = a.IndexInfo<1>(TestA4(), var2);
    auto empty_debug_a4 = a.IndexDebug<1>(TestA4(), var2);
    auto empty_error_a4 = a.IndexError<1>(TestA4(), var2);
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA1 : %s", "int");
        auto res_b = a.Info(TestA1(), var1);
        assert(res_b == (empty_info_a1 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA1 : type %d", 4);
        auto res_b = a.Debug(TestA1(), var1);
        assert(res_b == (empty_debug_a1 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("Error TestA1 msg %s", "test");
        auto res_b = a.Error(TestA1(), var1);
        assert(res_b == (empty_error_a1 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA2 : %s", "int");
        auto res_b = a.Info(TestA2(), var1);
        assert(res_b == (empty_info_a2 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA2 : type %d", 4);
        auto res_b = a.Debug(TestA2(), var1);
        assert(res_b == (empty_debug_a2 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("Error TestA2 msg %s", "test");
        auto res_b = a.Error(TestA2(), var1);
        assert(res_b == (empty_error_a2 + res_a));
    }
    
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA3 : %s", "int");
        auto res_b = a.Info(TestA3(), var1);
        assert(res_b == (empty_info_a3 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA3 : type %d", 4);
        auto res_b = a.Debug(TestA3(), var1);
        assert(res_b == (empty_debug_a3 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("Error TestA3 msg %s", "test");
        auto res_b = a.Error(TestA3(), var1);
        assert(res_b == (empty_error_a3 + res_a));
    }

    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA4 : %d", 143);
        auto res_b = a.Info(TestA4(), var2);
        assert(res_b == (empty_info_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("debug type Test TestA4 : %d", 143);
        auto res_b = a.Debug(TestA4(), var2);
        assert(res_b == (empty_debug_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("error type Test TestA4 : %d", 143);
        auto res_b = a.Error(TestA4(), var2);
        assert(res_b == (empty_error_a4 + res_a));
    }
    
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA4 : %d", 143);
        auto res_b = a.Info(test::type::Index<TestA4, 0>(), var2);
        assert(res_b == (empty_info_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("debug type Test TestA4 : %d", 143);
        auto res_b = a.Debug(test::type::Index<TestA4, 0>(), var2);
        assert(res_b == (empty_debug_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("error type Test TestA4 : %d", 143);
        auto res_b = a.Error(test::type::Index<TestA4, 0>(), var2);
        assert(res_b == (empty_error_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA4 : %d", -141);
        auto res_b = a.Info(test::type::Index<TestA4, 1>(), var2);
        assert(res_b == (empty_info_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("debug type Test TestA4 : %d", -141);
        auto res_b = a.Debug(test::type::Index<TestA4, 1>(), var2);
        assert(res_b == (empty_debug_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("error type Test TestA4 : %d", -141);
        auto res_b = a.Error(test::type::Index<TestA4, 1>(), var2);
        assert(res_b == (empty_error_a4 + res_a));
    }
    
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("Test TestA4 : %d", 30044);
        auto res_b = a.Info(test::type::Index<TestA4, 2>(), var2);
        assert(res_b == (empty_info_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;

        auto res_a = out_cstr1.Print("debug type Test TestA4 : %d", 30044);
        auto res_b = a.Debug(test::type::Index<TestA4, 2>(), var2);
        assert(res_b == (empty_debug_a4 + res_a));
    }
    {
        test::out::CString<char> out_cstr1;
        auto res_a = out_cstr1.Print("error type Test TestA4 : %d", 30044);
        auto res_b = a.Error(test::type::Index<TestA4, 2>(), var2);
        assert(res_b == (empty_error_a4 + res_a));
    }
    TEST::GetInstance().Output().InfoEnable(false);
    {
        test::out::CString<char> out_cstr1;

        auto res_b = a.Info(TestA1(), var1);
        assert(res_b == 0);
    }
    TEST::GetInstance().Output().DebugEnable(false);
    {
        test::out::CString<char> out_cstr1;

        auto res_b = a.Debug(TestA1(), var1);
        assert(res_b == 0);
    }
    TEST::GetInstance().Output().DebugEnable(false);
    {
        test::out::CString<char> out_cstr1;

        auto res_b = a.Debug(TestA1(), var1);
        assert(res_b == 0);
    }
    TEST::GetInstance().Output().Enable(false);
    {
        test::out::CString<char> out_cstr1;

        auto res_b = a.Error(TestA1(), var1);
        assert(res_b == 0);
    }
   
    return TEST::GetInstance().Status().Get();
}
