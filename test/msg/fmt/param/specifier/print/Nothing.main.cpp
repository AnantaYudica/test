#include "test/msg/fmt/param/specifier/print/Nothing.h"
#include "test/out/CString.h"

#include <cassert>

int main()
{
    using namespace test::msg::fmt::param;
    using namespace test::msg::fmt::param::specifier::print;

    char ch_val1 = 'B';
    short sh_val1 = 1;
    int in_val1 = 2;
    long lo_val1 = 3;
    long long lolo_val1 = 4;

    specifier::val::Nothing ch1 = {.char_value = &ch_val1};
    specifier::val::Nothing sh1 = {.short_value = &sh_val1};
    specifier::val::Nothing in1 = {.int_value = &in_val1};
    specifier::val::Nothing lo1 = {.long_value = &lo_val1};
    specifier::val::Nothing lolo1 = {.long_long_value = &lolo_val1};

    {
        constexpr flag::Nothing nt1{};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, in1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<char>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, ch1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<signed char>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, ch1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<unsigned char>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, ch1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<short>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, sh1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<unsigned short>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, sh1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<int>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, in1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<unsigned int>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, in1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<long>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, lo1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<unsigned long>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, lo1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<long long>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, lolo1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    {
        constexpr flag::Nothing nt1{flag::arg::Define<unsigned long long>{}};
        test::out::CString<char> out_cstr1;

        auto size = Nothing<char, nt1.GetValue()>::Print(out_cstr1, lolo1);
        assert(size == 0);
        assert(strncmp(*(out_cstr1.Get()), "", 1) == 0);
    }
    return 1;
}