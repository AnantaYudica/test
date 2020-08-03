#include "test/msg/fmt/val/flag/Nothing.h"
#include "test/out/Interface.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>

template<int Val>
struct NtFormat
{
    auto Output(test::out::Interface<char>& out) -> decltype(out.Print(""))
    {
        return 0;
    }
};

template<>
struct NtFormat<test::msg::fmt::val::flag::Nothing::define_char>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%hhn");
    }
};

template<>
struct NtFormat<test::msg::fmt::val::flag::Nothing::define_short>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%hn");
    }
};

template<>
struct NtFormat<test::msg::fmt::val::flag::Nothing::define_int>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%n");
    }
};

template<>
struct NtFormat<test::msg::fmt::val::flag::Nothing::define_long>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%ln");
    }
};

template<>
struct NtFormat<test::msg::fmt::val::flag::Nothing::define_long_long>
{
    static auto Output(test::out::Interface<char>& out) -> 
        decltype(out.Print("_"))
    {
        return out.Print("%s", "%lln");
    }
};

int main()
{
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt;
    {
        constexpr Nothing nt1{};

        assert(nt1.GetValue() == Nothing::define_int);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%n", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<char>{}};

        assert(nt1.GetValue() == Nothing::define_char);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%hhn", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<signed char>{}};

        assert(nt1.GetValue() == Nothing::define_char);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%hhn", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned char>{}};

        assert(nt1.GetValue() == Nothing::define_char);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%hhn", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<short>{}};

        assert(nt1.GetValue() == Nothing::define_short);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%hn", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned short>{}};

        assert(nt1.GetValue() == Nothing::define_short);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%hn", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<int>{}};

        assert(nt1.GetValue() == Nothing::define_int);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%n", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned int>{}};

        assert(nt1.GetValue() == Nothing::define_int);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%n", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<long>{}};

        assert(nt1.GetValue() == Nothing::define_long);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%ln", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long>{}};

        assert(nt1.GetValue() == Nothing::define_long);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%ln", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<long long>{}};

        assert(nt1.GetValue() == Nothing::define_long_long);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%lln", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long long>{}};

        assert(nt1.GetValue() == Nothing::define_long_long);

        test::out::CString<char> out_cstr1;

        NtFormat<nt1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%lln", 3) == 0);
    }
    {
        constexpr Nothing nt1{arg::Define<unsigned long long>{}};
        constexpr Nothing nt2{nt1};

        assert(nt2.GetValue() == Nothing::define_long_long);

        {
            test::out::CString<char> out_cstr1;

            NtFormat<nt2.GetValue()>::Output(out_cstr1);

            assert(strncmp(*(out_cstr1.Get()), "%lln", 3) == 0);
        }

        constexpr Nothing nt3{std::move(nt1)};
        
        assert(nt3.GetValue() == Nothing::define_long_long);
        {
            test::out::CString<char> out_cstr1;

            NtFormat<nt3.GetValue()>::Output(out_cstr1);

            assert(strncmp(*(out_cstr1.Get()), "%lln", 3) == 0);
        }
        
        Nothing nt4, nt5;
        nt4 = nt1;

        assert(nt4.GetValue() == Nothing::define_long_long);

        nt5 = std::move(nt1);
        
        assert(nt5.GetValue() == Nothing::define_long_long);

    }
    return 1;
}