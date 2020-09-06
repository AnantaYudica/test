#include "test/msg/fmt/val/flag/String.h"
#include "test/out/CString.h"

#include <cassert>
#include <utility>
#include <cstring>

template<int Val>
struct StFormat
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print(""))
    {
        return 0;
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_char>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%s");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_wchar>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%ls");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_char |
    test::msg::fmt::val::flag::String::width>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%*s");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_wchar |
    test::msg::fmt::val::flag::String::width>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%*ls");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_char |
    test::msg::fmt::val::flag::String::length>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%.*s");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_wchar |
    test::msg::fmt::val::flag::String::length>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%.*ls");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_char |
    test::msg::fmt::val::flag::String::width |
    test::msg::fmt::val::flag::String::length>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%*.*s");
    }
};

template<>
struct StFormat<test::msg::fmt::val::flag::String::define_wchar|
    test::msg::fmt::val::flag::String::width |
    test::msg::fmt::val::flag::String::length>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%*.*ls");
    }
};

int main()
{
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt::var;
    {
        constexpr String st1{};

        assert(st1.GetValue() == String::define_char);

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%s", 3) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == String::define_char);

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%s%s", 5) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == String::define_char);

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%s%s%s", 7) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == String::define_char);
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == String::define_char);
    }
    {
        constexpr String st1{arg::Width{}};
        
        assert(st1.GetValue() == (String::define_char |
            String::width));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*s", 4) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_char |
            String::width));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*s%*s", 7) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_char |
            String::width));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*s%*s%*s", 10) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_char |
            String::width));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_char |
            String::width));
    }
    {
        constexpr String st1{arg::Length{}};
        
        assert(st1.GetValue() == (String::define_char |
            String::length));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*s", 4) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_char |
            String::length));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*s%.*s", 7) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_char |
            String::length));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*s%.*s%.*s", 10) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_char |
            String::length));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_char |
            String::length));
    }
    {
        constexpr String st1{arg::Width{}, arg::Length{}};
        
        assert(st1.GetValue() == (String::define_char |
            String::width | String::length));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*s", 6) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_char |
            String::width | String::length));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*s%*.*s", 11) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_char |
            String::width | String::length));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*s%*.*s%*.*s", 16) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_char |
            String::width | String::length));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_char |
            String::width | String::length));
    }
    {
        constexpr String st1{arg::Define<char>{}};

        assert(st1.GetValue() == String::define_char);

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%s", 3) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == String::define_char);

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%s%s", 5) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == String::define_char);

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%s%s%s", 7) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == String::define_char);
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == String::define_char);

    }
    {
        constexpr String st1{arg::Define<char>{},
            arg::Width{}};
        
        assert(st1.GetValue() == (String::define_char |
            String::width));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*s", 4) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_char |
            String::width));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*s%*s", 7) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_char |
            String::width));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*s%*s%*s", 10) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_char |
            String::width));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_char |
            String::width));
    }
    {
        constexpr String st1{arg::Define<char>{},
            arg::Length{}};
        
        assert(st1.GetValue() == (String::define_char |
            String::length));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*s", 4) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_char |
            String::length));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*s%.*s", 7) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_char |
            String::length));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*s%.*s%.*s", 10) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_char |
            String::length));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_char |
            String::length));
    }
    {
        constexpr String st1{arg::Define<char>{},
            arg::Width{}, arg::Length{}};
        
        assert(st1.GetValue() == (String::define_char |
            String::width | String::length));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*s", 6) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_char |
            String::width | String::length));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*s%*.*s", 11) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_char |
            String::width | String::length));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*s%*.*s%*.*s", 16) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_char |
            String::width | String::length));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_char |
            String::width | String::length));
    }
    {
        constexpr String st1{arg::Define<wchar_t>{}};

        assert(st1.GetValue() == String::define_wchar);

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%ls", 4) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == String::define_wchar);

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%ls%ls", 7) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == String::define_wchar);

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%ls%ls%ls", 10) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == String::define_wchar);
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == String::define_wchar);

    }
    {
        constexpr String st1{arg::Define<wchar_t>{},
            arg::Width{}};
        
        assert(st1.GetValue() == (String::define_wchar |
            String::width));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*ls", 5) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_wchar |
            String::width));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*ls%*ls", 9) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_wchar |
            String::width));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*ls%*ls%*ls", 13) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_wchar |
            String::width));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_wchar |
            String::width));
    }
    {
        constexpr String st1{arg::Define<wchar_t>{},
            arg::Length{}};
        
        assert(st1.GetValue() == (String::define_wchar |
            String::length));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*ls", 6) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_wchar |
            String::length));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*ls%.*ls", 11) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_wchar |
            String::length));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%.*ls%.*ls%.*ls", 16) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_wchar |
            String::length));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_wchar |
            String::length));
    }
    {
        constexpr String st1{arg::Define<wchar_t>{},
            arg::Width{}, arg::Length{}};
        
        assert(st1.GetValue() == (String::define_wchar |
            String::width | String::length));

        test::out::CString<char> out_cstr1;

        StFormat<st1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*ls", 7) == 0);

        constexpr String st2{st1};

        assert(st2.GetValue() == (String::define_wchar |
            String::width | String::length));

        StFormat<st2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*ls%*.*ls", 13) == 0);

        constexpr String st3{std::move(st2)};
        
        assert(st3.GetValue() == (String::define_wchar |
            String::width | String::length));

        StFormat<st3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*.*ls%*.*ls%*.*ls", 19) == 0);

        String st4;
        st4 = st3;
        
        assert(st4.GetValue() == (String::define_wchar |
            String::width | String::length));
        
        String st5;
        st5 = std::move(st4);
        
        assert(st5.GetValue() == (String::define_wchar |
            String::width | String::length));
    }
    return 0;
}