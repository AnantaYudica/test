#include "test/msg/fmt/val/specifier/print/String.h"
#include "test/out/CString.h"

#include <cwchar>
#include <cassert>

int main()
{
    using namespace test::msg::fmt::val::specifier;
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt::val;
    using namespace test::msg::fmt::var;

    const char * cstr = "test1234567890"; 
    const wchar_t * wcstr = L"1234567890test"; 
    val::String va1{.char_ptr_value=cstr};
    val::String va2{.wchar_ptr_value=wcstr};
    Width<char> wd1{14};
    Length<char> le1{6};
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{};
        
        out_cstr1_a.Print("%s", va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Width{}};
        
        out_cstr1_a.Print("%*s", wd1.GetValue(), va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Length{}};
        
        out_cstr1_a.Print("%.*s", le1.GetValue(), va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Width{}, arg::Length{}};
        
        out_cstr1_a.Print("%*.*s", wd1.GetValue(), le1.GetValue(), 
            va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    ///
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<char>{}};
        
        out_cstr1_a.Print("%s", va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<char>{},
            arg::Width{}};
        
        out_cstr1_a.Print("%*s", wd1.GetValue(), va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<char>{},
            arg::Length{}};
        
        out_cstr1_a.Print("%.*s", le1.GetValue(), va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<char>{},
            arg::Width{}, arg::Length{}};
        
        out_cstr1_a.Print("%*.*s", wd1.GetValue(), le1.GetValue(), 
            va1.char_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    ///
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<wchar_t>{}};
        
        out_cstr1_a.Print("%ls", va2.wchar_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va2);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<wchar_t>{},
            arg::Width{}};
        
        out_cstr1_a.Print("%*ls", wd1.GetValue(), va2.wchar_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va2);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<wchar_t>{},
            arg::Length{}};
        
        out_cstr1_a.Print("%.*ls", le1.GetValue(), va2.wchar_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va2);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr String st1{arg::Define<wchar_t>{},
            arg::Width{}, arg::Length{}};
        
        out_cstr1_a.Print("%*.*ls", wd1.GetValue(), le1.GetValue(), 
            va2.wchar_ptr_value);
        print::String<char, st1.GetValue()>::Print(out_cstr1_b, wd1, le1, va2);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    return 0;
}