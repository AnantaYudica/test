#include "test/msg/fmt/param/flag/Character.h"
#include "test/out/CString.h"

#include <cassert>
#include <utility>
#include <cstring>

template<int Val>
struct ChFormat
{
    auto Output(test::out::Interface<char>& out) -> decltype(out.Print(""))
    {
        return 0;
    }
};

template<>
struct ChFormat<test::msg::fmt::param::flag::Character::length_char>
{
    static auto Output(test::out::Interface<char>& out) -> decltype(out.Print("_"))
    {
        return out.Print("%s", "%c");
    }
};

template<>
struct ChFormat<test::msg::fmt::param::flag::Character::length_char
    | test::msg::fmt::param::flag::Character::width>
{
    static auto Output(test::out::Interface<char>& out) -> decltype(out.Print("_"))
    {
        return out.Print("%s", "%*c");
    }
};


template<>
struct ChFormat<test::msg::fmt::param::flag::Character::length_wchar>
{
    static auto Output(test::out::Interface<char>& out) -> decltype(out.Print("_"))
    {
        return out.Print("%s", "%lc");
    }
};

template<>
struct ChFormat<test::msg::fmt::param::flag::Character::length_wchar
    | test::msg::fmt::param::flag::Character::width>
{
    static auto Output(test::out::Interface<char>& out) -> decltype(out.Print("_"))
    {
        return out.Print("%s", "%*lc");
    }
};

int main()
{
    using namespace test::msg::fmt::param::flag;

    constexpr Character ch1{};

    assert(ch1.GetValue() == Character::length_char);

    test::out::CString<char> out_cstr1;

    ChFormat<ch1.GetValue()>::Output(out_cstr1);

    assert(strncmp(*(out_cstr1.Get()), "%c", 3) == 0);

    constexpr Character ch2{arg::Width{}};

    assert(ch2.GetValue() == (Character::length_char | Character::width));
    
    test::out::CString<char> out_cstr2;

    ChFormat<ch2.GetValue()>::Output(out_cstr2);

    assert(strncmp(*(out_cstr2.Get()), "%*c", 4) == 0);
    
    constexpr Character ch3{arg::Length<std::wint_t>{}};

    assert(ch3.GetValue() == Character::length_wchar);
    
    test::out::CString<char> out_cstr3;

    ChFormat<ch3.GetValue()>::Output(out_cstr3);

    assert(strncmp(*(out_cstr3.Get()), "%lc", 4) == 0);

    constexpr Character ch4{arg::Length<std::wint_t>{}, arg::Width{}};

    assert(ch4.GetValue() == (Character::length_wchar | Character::width));
    
    test::out::CString<char> out_cstr4;

    ChFormat<ch4.GetValue()>::Output(out_cstr4);

    assert(strncmp(*(out_cstr4.Get()), "%*lc", 5) == 0);

    constexpr Character ch5{ch2};
    
    assert(ch5.GetValue() == (Character::length_char | Character::width));
    
    test::out::CString<char> out_cstr5;

    ChFormat<ch5.GetValue()>::Output(out_cstr5);

    assert(strncmp(*(out_cstr5.Get()), "%*c", 4) == 0);

    constexpr Character ch6{std::move(ch2)};

    assert(ch6.GetValue() == (Character::length_char | Character::width));
    
    test::out::CString<char> out_cstr6;

    ChFormat<ch6.GetValue()>::Output(out_cstr6);

    assert(strncmp(*(out_cstr6.Get()), "%*c", 4) == 0);

    return 1;
}