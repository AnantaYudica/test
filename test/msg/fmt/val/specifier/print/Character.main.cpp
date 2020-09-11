#include "test/msg/fmt/val/specifier/print/Character.h"
#include "test/msg/fmt/val/specifier/val/Character.h"
#include "test/msg/fmt/val/flag/Character.h"
#include "test/msg/fmt/val/Width.h"
#include "test/out/CString.h"

#include <cassert>

int main()
{
    using namespace test::msg::fmt::val::specifier::print;
    test::msg::fmt::val::Width<char> wd1{4};
    test::msg::fmt::val::Width<char> wd2{-4};
    test::msg::fmt::val::specifier::val::Character val1{.char_value = 'Z'};
    test::msg::fmt::val::specifier::val::Character val2{.wchar_value = 'K'};

    constexpr int char_format = 
        test::msg::fmt::val::flag::Character::char_format;
    constexpr int w_char_format = 
        test::msg::fmt::val::flag::Character::w_char_format;
    constexpr int wchar_format = 
        test::msg::fmt::val::flag::Character::wchar_format;
    constexpr int w_wchar_format = 
        test::msg::fmt::val::flag::Character::w_wchar_format;

    test::out::CString<char> out_cstr1;
    auto size = Character<char, 0>::Print(out_cstr1, wd1, val1);
    assert(size == 0);
    assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    
    test::out::CString<char> out_cstr2;
    size = Character<char, char_format>::Print(out_cstr2, wd1, val1);
    assert(size == 1);
    assert(strncmp(*(out_cstr2.Get()), "Z", 2) == 0);
    
    test::out::CString<char> out_cstr3;
    size = Character<char, w_char_format>::Print(out_cstr3, wd1, val1);
    assert(size == 4);
    assert(strncmp(*(out_cstr3.Get()), "   Z", 5) == 0);
    
    test::out::CString<char> out_cstr4;
    size = Character<char, wchar_format>::Print(out_cstr4, wd2, val2);
    assert(size == 1);
    assert(strncmp(*(out_cstr4.Get()), "K", 2) == 0);

    test::out::CString<char> out_cstr5;
    size = Character<char, w_wchar_format>::Print(out_cstr5, wd2, val2);
    assert(size == 4);
    assert(strncmp(*(out_cstr5.Get()), "K   ", 5) == 0);
}
