#include "test/msg/fmt/val/specifier/Character.h"
#include "test/msg/fmt/val/flag/Character.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cwchar>

template<typename T>
std::size_t Load(T& obj, std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto ret = obj.VLoad(size, 0, args);
    va_end(args);
    return ret;
}

int main()
{
    using namespace test::msg::fmt::val::specifier;
    using namespace test::msg::fmt::val;
    using namespace test::msg::fmt::var;
    {
        Character<char> ch1;
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        test::out::CString<char> out_cstr3;

        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Output(out_cstr1);
        assert(len == 1);
        assert(strncmp(*(out_cstr1.Get()), "\0", 2) == 0);
        assert(ch1.IsGood() == false);
        assert(ch1.IsBad() == true);
        assert(ch1.GetBadCode() == Character<char>::StatusType::value_not_set);

        len = ch1.Load(1, 'N');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'N');
        assert(ch1.GetValue().wchar_value == 'N');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr2);
        assert(len == 1);
        assert(strncmp(*(out_cstr2.Get()), "N", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);

        ch1.Reset();
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(1, 'B');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'B');
        assert(ch1.GetValue().wchar_value == 'B');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = Load(ch1, 1, 'D');
        assert(len == 0);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'B');
        assert(ch1.GetValue().wchar_value == 'B');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr3);
        assert(len == 1);
        assert(strncmp(*(out_cstr3.Get()), "B", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
    }
    {
        Character<char> ch1{'A'};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'A');
        assert(ch1.GetValue().wchar_value == 'A');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Output(out_cstr1);
        assert(len == 1);
        assert(strncmp(*(out_cstr1.Get()), "A", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(1, 'B');
        assert(len == 0);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'A');
        assert(ch1.GetValue().wchar_value == 'A');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'A');
        assert(ch1.GetValue().wchar_value == 'A');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = Load(ch1, 1, 'D');
        assert(len == 0);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'A');
        assert(ch1.GetValue().wchar_value == 'A');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr2);
        assert(len == 1);
        assert(strncmp(*(out_cstr2.Get()), "A", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{arg::Define<char>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Load(1, 'B');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'B');
        assert(ch1.GetValue().wchar_value == 'B');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr1);
        assert(len == 1);
        assert(strncmp(*(out_cstr1.Get()), "B", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Load(1, 'D');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'D');
        assert(ch1.GetValue().wchar_value == 'D');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr2);
        assert(len == 1);
        assert(strncmp(*(out_cstr2.Get()), "D", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{arg::Define<wchar_t>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Load(1, 'B');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'B');
        assert(ch1.GetValue().wchar_value == 'B');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr1);
        assert(len == 1);
        assert(strncmp(*(out_cstr1.Get()), "B", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(1, 'R');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'R');
        assert(ch1.GetValue().wchar_value == 'R');
        assert(ch1.GetWidth() == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr2);
        assert(len == 1);
        assert(strncmp(*(out_cstr2.Get()), "R", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{'D', arg::Define<char>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'D');
        assert(ch1.GetValue().wchar_value == 'D');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Output(out_cstr1);
        assert(len == 1);
        assert(strncmp(*(out_cstr1.Get()), "D", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();

        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'D');
        assert(ch1.GetValue().wchar_value == 'D');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 1);
        assert(strncmp(*(out_cstr2.Get()), "D", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{'K', arg::Define<wchar_t>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'K');
        assert(ch1.GetValue().wchar_value == 'K');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Output(out_cstr1);
        assert(len == 1);
        assert(strncmp(*(out_cstr1.Get()), "K", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        ch1.Unset();
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'K');
        assert(ch1.GetValue().wchar_value == 'K');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 1);
        assert(strncmp(*(out_cstr2.Get()), "K", 2) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
    }
    {
        Character<char> ch1{arg::Width{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Load(2, 5, 'Z');
        assert(len == 2);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'Z');
        assert(ch1.GetValue().wchar_value == 'Z');
        assert(ch1.GetWidth() == 5);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr1);
        assert(len == 5);
        assert(strncmp(*(out_cstr1.Get()), "    Z", 6) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        ch1.Unset();
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(2, -5, 'J');
        assert(len == 2);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'J');
        assert(ch1.GetValue().wchar_value == 'J');
        assert(ch1.GetWidth() == -5);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr2);
        assert(len == 5);
        assert(strncmp(*(out_cstr2.Get()), "J    ", 6) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{arg::Width{10}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Load(2, 'Z', 4);
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'Z');
        assert(ch1.GetValue().wchar_value == 'Z');
        assert(ch1.GetWidth() == 10);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr1);
        assert(len == 10);
        assert(strncmp(*(out_cstr1.Get()), "         Z", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();

        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(2, 'K', 4);
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'K');
        assert(ch1.GetValue().wchar_value == 'K');
        assert(ch1.GetWidth() == 10);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Output(out_cstr2);
        assert(len == 10);
        assert(strncmp(*(out_cstr2.Get()), "         K", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
    }
    {
        Character<char> ch1{arg::Width{}, arg::Define<wchar_t>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Load(2, 4, 'P');
        assert(len == 2);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'P');
        assert(ch1.GetValue().wchar_value == 'P');
        assert(ch1.GetWidth() == 4);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr1);
        assert(len == 4);
        assert(strncmp(*(out_cstr1.Get()), "   P", 5) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(2, -4, 'T');
        assert(len == 2);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'T');
        assert(ch1.GetValue().wchar_value == 'T');
        assert(ch1.GetWidth() == -4);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 4);
        assert(strncmp(*(out_cstr2.Get()), "T   ", 5) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{arg::Width{10}, arg::Define<wchar_t>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Load(2, 'P');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'P');
        assert(ch1.GetValue().wchar_value == 'P');
        assert(ch1.GetWidth() == 10);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr1);
        assert(len == 10);
        assert(strncmp(*(out_cstr1.Get()), "         P", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();

        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        len = ch1.Load(2, 'Q');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'Q');
        assert(ch1.GetValue().wchar_value == 'Q');
        assert(ch1.GetWidth() == 10);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 10);
        assert(strncmp(*(out_cstr2.Get()), "         Q", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
    }
    {
        Character<char> ch1{'L', arg::Width{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Load(2, 3, 'P');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == 3);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr1);
        assert(len == 3);
        assert(strncmp(*(out_cstr1.Get()), "  L", 4) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();

        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Load(2, -3, 'P');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == -3);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 3);
        assert(strncmp(*(out_cstr2.Get()), "L  ", 4) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
    }
    {
        Character<char> ch1{'N', arg::Width{-10}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'N');
        assert(ch1.GetValue().wchar_value == 'N');
        assert(ch1.GetWidth() == -10);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Output(out_cstr1);
        assert(len == 10);
        assert(strncmp(*(out_cstr1.Get()), "N         ", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        ch1.Unset();

        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'N');
        assert(ch1.GetValue().wchar_value == 'N');
        assert(ch1.GetWidth() == -10);
        assert(ch1.GetFlag() == flag::Character::w_char_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 10);
        assert(strncmp(*(out_cstr2.Get()), "N         ", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    
    {
        Character<char> ch1{'L', arg::Width{},
            arg::Define<wchar_t>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Load(2, -3, 'P');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == -3);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr1);
        assert(len == 3);
        assert(strncmp(*(out_cstr1.Get()), "L  ", 4) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Load(2, 3, 'P');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'L');
        assert(ch1.GetValue().wchar_value == 'L');
        assert(ch1.GetWidth() == 3);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 3);
        assert(strncmp(*(out_cstr2.Get()), "  L", 4) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{'N', arg::Width{10},
            arg::Define<wchar_t>{}};
        test::out::CString<char> out_cstr1;
        test::out::CString<char> out_cstr2;
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'N');
        assert(ch1.GetValue().wchar_value == 'N');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        auto len = ch1.Output(out_cstr1);
        assert(len == 10);
        assert(strncmp(*(out_cstr1.Get()), "         N", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        ch1.Unset();
        
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'N');
        assert(ch1.GetValue().wchar_value == 'N');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);
        
        len = ch1.Output(out_cstr2);
        assert(len == 10);
        assert(strncmp(*(out_cstr2.Get()), "         N", 11) == 0);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

    }
    {
        Character<char> ch1{'N', arg::Width{10},
            arg::Define<wchar_t>{}};
            
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'N');
        assert(ch1.GetValue().wchar_value == 'N');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch2{ch1};

        assert(ch2.IsSet() == true);
        assert(ch2.GetValue().char_value == 'N');
        assert(ch2.GetValue().wchar_value == 'N');
        assert(ch2.GetWidth() == 10);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch3{std::move(ch2)};

        assert(ch3.IsSet() == true);
        assert(ch3.GetValue().char_value == 'N');
        assert(ch3.GetValue().wchar_value == 'N');
        assert(ch3.GetWidth() == 10);
        assert(ch3.GetFlag() == flag::Character::w_wchar_format);
        assert(ch3.IsGood() == true);
        assert(ch3.IsBad() == false);
        assert(ch3.GetBadCode() == Character<char>::StatusType::good);

        assert(ch2.IsSet() == true);
        assert(ch2.GetValue().char_value == 'N');
        assert(ch2.GetValue().wchar_value == 'N');
        assert(ch2.GetWidth() == 10);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch4;
        ch4 = ch3;
        
        assert(ch4.IsSet() == true);
        assert(ch4.GetValue().char_value == 'N');
        assert(ch4.GetValue().wchar_value == 'N');
        assert(ch4.GetWidth() == 10);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch5;
        ch5 = std::move(ch4);
        
        assert(ch5.IsSet() == true);
        assert(ch5.GetValue().char_value == 'N');
        assert(ch5.GetValue().wchar_value == 'N');
        assert(ch5.GetWidth() == 10);
        assert(ch5.GetFlag() == flag::Character::w_wchar_format);
        assert(ch5.IsGood() == true);
        assert(ch5.IsBad() == false);
        assert(ch5.GetBadCode() == Character<char>::StatusType::good);

        assert(ch4.IsSet() == true);
        assert(ch4.GetValue().char_value == 'N');
        assert(ch4.GetValue().wchar_value == 'N');
        assert(ch4.GetWidth() == 10);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
    }
    {
        Character<char> ch1{arg::Width{10},
            arg::Define<wchar_t>{}};
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Load(1, 'W');
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'W');
        assert(ch1.GetValue().wchar_value == 'W');
        assert(ch1.GetWidth() == 10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch2{ch1};

        assert(ch2.IsSet() == true);
        assert(ch2.GetValue().char_value == 'W');
        assert(ch2.GetValue().wchar_value == 'W');
        assert(ch2.GetWidth() == 10);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch3{std::move(ch2)};

        assert(ch3.IsSet() == true);
        assert(ch3.GetValue().char_value == 'W');
        assert(ch3.GetValue().wchar_value == 'W');
        assert(ch3.GetWidth() == 10);
        assert(ch3.GetFlag() == flag::Character::w_wchar_format);
        assert(ch3.IsGood() == true);
        assert(ch3.IsBad() == false);
        assert(ch3.GetBadCode() == Character<char>::StatusType::good);

        assert(ch2.IsSet() == false);
        assert(ch2.GetValue().char_value == '\0');
        assert(ch2.GetValue().wchar_value == '\0');
        assert(ch2.GetWidth() == 10);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch4;
        ch4 = ch3;
        
        assert(ch4.IsSet() == true);
        assert(ch4.GetValue().char_value == 'W');
        assert(ch4.GetValue().wchar_value == 'W');
        assert(ch4.GetWidth() == 10);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch5;
        ch5 = std::move(ch4);
        
        assert(ch5.IsSet() == true);
        assert(ch5.GetValue().char_value == 'W');
        assert(ch5.GetValue().wchar_value == 'W');
        assert(ch5.GetWidth() == 10);
        assert(ch5.GetFlag() == flag::Character::w_wchar_format);
        assert(ch5.IsGood() == true);
        assert(ch5.IsBad() == false);
        assert(ch5.GetBadCode() == Character<char>::StatusType::good);

        assert(ch4.IsSet() == false);
        assert(ch4.GetValue().char_value == '\0');
        assert(ch4.GetValue().wchar_value == '\0');
        assert(ch4.GetWidth() == 10);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
    }
    {
        Character<char> ch1{'G', arg::Width{},
            arg::Define<wchar_t>{}};
            
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == 'G');
        assert(ch1.GetValue().wchar_value == 'G');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Load(1, 4);
        assert(len == 1);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'G');
        assert(ch1.GetValue().wchar_value == 'G');
        assert(ch1.GetWidth() == 4);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch2{ch1};

        assert(ch2.IsSet() == true);
        assert(ch2.GetValue().char_value == 'G');
        assert(ch2.GetValue().wchar_value == 'G');
        assert(ch2.GetWidth() == 4);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch3{std::move(ch2)};

        assert(ch3.IsSet() == true);
        assert(ch3.GetValue().char_value == 'G');
        assert(ch3.GetValue().wchar_value == 'G');
        assert(ch3.GetWidth() == 4);
        assert(ch3.GetFlag() == flag::Character::w_wchar_format);
        assert(ch3.IsGood() == true);
        assert(ch3.IsBad() == false);
        assert(ch3.GetBadCode() == Character<char>::StatusType::good);

        assert(ch2.IsSet() == false);
        assert(ch2.GetValue().char_value == 'G');
        assert(ch2.GetValue().wchar_value == 'G');
        assert(ch2.GetWidth() == 0);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch4;
        ch4 = ch3;
        
        assert(ch4.IsSet() == true);
        assert(ch4.GetValue().char_value == 'G');
        assert(ch4.GetValue().wchar_value == 'G');
        assert(ch4.GetWidth() == 4);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch5;
        ch5 = std::move(ch4);
        
        assert(ch5.IsSet() == true);
        assert(ch5.GetValue().char_value == 'G');
        assert(ch5.GetValue().wchar_value == 'G');
        assert(ch5.GetWidth() == 4);
        assert(ch5.GetFlag() == flag::Character::w_wchar_format);
        assert(ch5.IsGood() == true);
        assert(ch5.IsBad() == false);
        assert(ch5.GetBadCode() == Character<char>::StatusType::good);

        assert(ch4.IsSet() == false);
        assert(ch4.GetValue().char_value == 'G');
        assert(ch4.GetValue().wchar_value == 'G');
        assert(ch4.GetWidth() == 0);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
    }
    {
         Character<char> ch1{arg::Width{},
            arg::Define<wchar_t>{}};
        
        assert(ch1.IsSet() == false);
        assert(ch1.GetValue().char_value == '\0');
        assert(ch1.GetValue().wchar_value == '\0');
        assert(ch1.GetWidth() == 0);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        auto len = ch1.Load(2, -10, 'B');
        assert(len == 2);
        assert(ch1.IsSet() == true);
        assert(ch1.GetValue().char_value == 'B');
        assert(ch1.GetValue().wchar_value == 'B');
        assert(ch1.GetWidth() == -10);
        assert(ch1.GetFlag() == flag::Character::w_wchar_format);
        assert(ch1.IsGood() == true);
        assert(ch1.IsBad() == false);
        assert(ch1.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch2{ch1};

        assert(ch2.IsSet() == true);
        assert(ch2.GetValue().char_value == 'B');
        assert(ch2.GetValue().wchar_value == 'B');
        assert(ch2.GetWidth() == -10);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch3{std::move(ch2)};

        assert(ch3.IsSet() == true);
        assert(ch3.GetValue().char_value == 'B');
        assert(ch3.GetValue().wchar_value == 'B');
        assert(ch3.GetWidth() == -10);
        assert(ch3.GetFlag() == flag::Character::w_wchar_format);
        assert(ch3.IsGood() == true);
        assert(ch3.IsBad() == false);
        assert(ch3.GetBadCode() == Character<char>::StatusType::good);

        assert(ch2.IsSet() == false);
        assert(ch2.GetValue().char_value == '\0');
        assert(ch2.GetValue().wchar_value == '\0');
        assert(ch2.GetWidth() == 0);
        assert(ch2.GetFlag() == flag::Character::w_wchar_format);
        assert(ch2.IsGood() == true);
        assert(ch2.IsBad() == false);
        assert(ch2.GetBadCode() == Character<char>::StatusType::good);

        Character<char> ch4;
        ch4 = ch3;
        
        assert(ch4.IsSet() == true);
        assert(ch4.GetValue().char_value == 'B');
        assert(ch4.GetValue().wchar_value == 'B');
        assert(ch4.GetWidth() == -10);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
        
        Character<char> ch5;
        ch5 = std::move(ch4);
        
        assert(ch5.IsSet() == true);
        assert(ch5.GetValue().char_value == 'B');
        assert(ch5.GetValue().wchar_value == 'B');
        assert(ch5.GetWidth() == -10);
        assert(ch5.GetFlag() == flag::Character::w_wchar_format);
        assert(ch5.IsGood() == true);
        assert(ch5.IsBad() == false);
        assert(ch5.GetBadCode() == Character<char>::StatusType::good);

        assert(ch4.IsSet() == false);
        assert(ch4.GetValue().char_value == '\0');
        assert(ch4.GetValue().wchar_value == '\0');
        assert(ch4.GetWidth() == 0);
        assert(ch4.GetFlag() == flag::Character::w_wchar_format);
        assert(ch4.IsGood() == true);
        assert(ch4.IsBad() == false);
        assert(ch4.GetBadCode() == Character<char>::StatusType::good);
    }
    
    return 0;
}
