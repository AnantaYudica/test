#include "test/msg/fmt/val/specifier/Integer.h"
#include "test/out/CString.h"

#include <climits>
#include <cassert>
#include <cstring>
#include <cstdarg>

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

    signed char sch1 = SCHAR_MIN, sch2 = SCHAR_MAX, sch3 = (SCHAR_MAX/ 2);
    char ch1 = 'A', ch2 = 'Z', ch3 = 'M';
    short sh1 = SHRT_MIN, sh2 = SHRT_MAX, sh3 = (SHRT_MAX/2);
    int in1 = INT_MIN, in2 = INT_MAX, in3 = (INT_MAX / 2);
    long lo1 = LONG_MIN, lo2 = LONG_MAX, lo3=(LONG_MAX/2);
    long long lolo1 = LLONG_MIN, lolo2 = LLONG_MAX, lolo3 = (LLONG_MAX/2);
    unsigned char uch1 = (UCHAR_MAX / 2), uch2 = UCHAR_MAX,
        uch3 = (UCHAR_MAX/3);
    unsigned short ush1 = (USHRT_MAX / 2), ush2 = USHRT_MAX,
        ush3 = (USHRT_MAX/3);
    unsigned int uin1 = (UINT_MAX / 2), uin2 = UINT_MAX, uin3 = (UINT_MAX/3);
    unsigned long ulo1 = (ULONG_MAX / 2), ulo2 = ULONG_MAX,
        ulo3 = (ULONG_MAX/3);
    unsigned long long ulolo1 = (ULLONG_MAX / 2), ulolo2 = ULLONG_MAX,
        ulolo3 = (ULLONG_MAX/3);

    const int wd1 = 10, wd2 = 14, wd3 = -10;
    const int ln1 = 8, ln2 = 15, ln3 = 9;

    {
        Integer<char> i1{};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%i", i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%i", i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(1, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%i", i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%X", i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%X", i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(1, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%X", i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Width{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::w_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*i", 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, wd2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd2);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*i", wd2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, wd3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, wd2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*i", wd3, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::w_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*X", 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, wd2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd2);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*X", wd2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, wd3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, wd2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*X", wd3, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Width{wd1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::w_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*i", wd1, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*i", wd1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, wd2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*i", wd1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::w_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*X", wd1, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*X", wd1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, wd2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*X", wd1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::l_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*i", 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, ln2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*i", ln2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, ln3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*i", ln3, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::l_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*X", 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, ln2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*X", ln2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, ln3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*X", ln3, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::l_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*i", 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, ln2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*i", ln2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, ln3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*i", ln3, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::l_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*X", 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, ln2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*X", ln2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, ln3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*X", ln3, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Length{ln1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.GetFlag() == flag::Integer::l_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*i", ln1, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*i", ln1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*i", ln1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.GetFlag() == flag::Integer::l_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*X", ln1, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*X", ln1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*X", ln1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Width{},
            arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::wl_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*i", 0, 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(3, wd2, ln2, in2);
        assert(len == 3);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd2);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*i", wd2, ln2, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 3, wd3, ln3, in3);
        assert(len == 3);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*i", wd3, ln3, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::wl_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*X", 0, 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(3, wd2, ln2, in2);
        assert(len == 3);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd2);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*X", wd2, ln2,
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 3, wd3, ln3, in3);
        assert(len == 3);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*X", wd3, ln3, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Width{wd1},
            arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::wl_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*i", wd1, 0, i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, ln2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*i", wd1, ln2, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, ln3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*i", wd1, ln3, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.GetFlag() == flag::Integer::wl_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*X", wd1, 0, 
            i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, ln2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln2);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*X", wd1, ln2, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, ln3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln3);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*X", wd1, ln3, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Width{},
            arg::Length{ln1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.GetFlag() == flag::Integer::wl_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*i", 0, ln1, 
            i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, wd2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd2);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*i", wd2, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, wd3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln3, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*i", wd3, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.GetFlag() == flag::Integer::wl_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*X", 0, ln1, 
            i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(2, wd2, in2);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd2);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*X", wd2, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 2, wd3, in3);
        assert(len == 2);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd3);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*X", wd3, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == 0);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Width{wd1},
            arg::Length{ln1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.GetFlag() == flag::Integer::wl_lds_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*i", wd1, ln1, 
            i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*i", wd1, ln1, i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*i", wd1, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    {
        Integer<char> i1{arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.GetFlag() == flag::Integer::wl_uhu_int_format);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*X", wd1, ln1, 
            i1.GetValue().int_value);
        auto len_b = i1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(i1.IsGood() == false);
        assert(i1.IsBad() == true);
        assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);

        auto len = i1.Load(1, in2);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in2);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*X", wd1, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr2_b);
        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        i1.Unset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = Load(i1, 1, in3);
        assert(len == 1);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        len = i1.Load(3, wd2, ln2, in2);
        assert(len == 0);
        assert(i1.IsSet() == true);
        assert(i1.GetValue().int_value == in3);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*X", wd1, ln1, 
            i1.GetValue().int_value);
        len_b = i1.Output(out_cstr3_b);
        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
        
        i1.Reset();
        assert(i1.IsSet() == false);
        assert(i1.GetValue().int_value == 0);
        assert(i1.GetWidth() == wd1);
        assert(i1.GetLength() == ln1);
        assert(i1.IsGood() == true);
        assert(i1.IsBad() == false);
        assert(i1.GetBadCode() == Integer<char>::StatusType::good);
    }
    ////
    {
        Integer<char> i1{arg::Define<char>{}};
        Integer<char> i2{arg::Define<signed char>{}};
        Integer<char> i3{arg::Define<short>{}};
        Integer<char> i4{arg::Define<int>{}};
        Integer<char> i5{arg::Define<long>{}};
        Integer<char> i6{arg::Define<long long>{}};
        Integer<char> i7{arg::Define<unsigned char>{}};
        Integer<char> i8{arg::Define<unsigned short>{}};
        Integer<char> i9{arg::Define<unsigned int>{}};
        Integer<char> i10{arg::Define<unsigned long>{}};
        Integer<char> i11{arg::Define<unsigned long long>{}};

        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == 0);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == 0);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == 0);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == 0);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == 0);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == 0UL);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == 0ULL);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%hhi", i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%hhi", i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%hi", i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%i", i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%li", i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%lli", i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%hhi", i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%hi", i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%i", i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%li", i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%lli", i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        {
            auto len = i1.Load(1, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch2);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(1, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch2);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(1, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh2);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(1, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in2);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(1, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo2);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(1, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo2);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(1, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch2);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(1, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush2);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(1, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin2);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(1, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo2);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(1, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo2);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%hhi", i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%hhi", i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%hi", i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%i", i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%li", i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%lli", i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%hhi", i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%hi", i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%i", i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%li", i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%lli", i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == 0);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == 0);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == 0);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == 0);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == 0);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == 0UL);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == 0ULL);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 1, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch3);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 1, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch3);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 1, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh3);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 1, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in3);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 1, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo3);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 1, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo3);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 1, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch3);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 1, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush3);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 1, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin3);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 1, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo3);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 1, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo3);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch3);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch3);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh3);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in3);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo3);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo3);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch3);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush3);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin3);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo3);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo3);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%hhi", i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%hhi", i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%hi", i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%i", i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%li", i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%lli", i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%hhi", i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%hi", i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%i", i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%li", i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%lli", i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == 0);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == 0);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == 0);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == 0);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == 0);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == 0UL);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == 0ULL);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i2{arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i3{arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i4{arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i5{arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i6{arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i7{arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i8{arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i9{arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i10{arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i11{arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == 0L);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == 0LL);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == 0);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == 0);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == 0);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == 0UL);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == 0ULL);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%hhX", 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%hhX", i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhX", i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(1, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch2);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(1, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch2);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(1, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh2);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(1, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in2);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(1, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo2);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(1, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo2);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(1, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch2);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(1, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush2);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(1, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin2);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(1, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo2);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(1, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo2);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%hhX", i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%hhX", i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%hX", i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%X", i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%lX", i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%llX", 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%hhX", i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%hX", i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%X", i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%lX", i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%llX", 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == 0L);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == 0LL);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == 0);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == 0);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == 0);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == 0UL);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == 0ULL);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 1, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch3);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 1, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch3);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 1, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh3);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 1, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in3);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 1, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo3);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 1, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo3);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 1, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch3);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 1, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush3);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 1, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin3);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 1, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo3);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 1, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo3);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch3);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch3);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh3);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in3);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo3);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo3);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch3);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush3);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin3);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo3);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo3);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%hhX", i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%hhX", i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%hX", i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%X", i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%lX", i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%llX", 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%hhX", i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%hX", i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%X", i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%lX", i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%llX", 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == 0L);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == 0LL);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == 0);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == 0);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == 0);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == 0UL);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == 0ULL);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{}};
        Integer<char> i3{sh1,
            arg::Define<short>{}};
        Integer<char> i4{in1,
            arg::Define<int>{}};
        Integer<char> i5{lo1,
            arg::Define<long>{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%hhi", i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%hhi", i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%hi", i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%i", i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%li", i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%lli", i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%hhi", i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%hi", i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%i", i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%li", i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%lli", i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(1, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(1, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(1, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(1, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(1, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(1, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(1, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(1, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(1, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(1, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(1, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%hhi", i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%hhi", i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%hi", i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%i", i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%li", i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%lli", i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%hhi", i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%hi", i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%i", i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%li", i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%lli", i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 1, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 1, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 1, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 1, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 1, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 1, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 1, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 1, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 1, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 1, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 1, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%hhi", i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%hhi", i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%hi", i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%i", i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%li", i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%lli", i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%hhi", i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%hi", i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%i", i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%li", i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%lli", i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%hhX", 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%hhX", i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%hhX", i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%hX", i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%X", i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%lX", i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%llX", 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(1, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(1, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(1, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(1, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(1, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(1, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(1, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(1, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(1, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(1, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(1, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%hhX", i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%hhX", i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%hX", i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%X", i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%lX", i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%llX", 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%hhX", i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%hX", i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%X", i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%lX", i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%llX", 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 1, sch1);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 1, ch1);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 1, sh1);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 1, in1);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 1, lo1);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 1, lolo1);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 1, uch1);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 1, ush1);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 1, uin1);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 1, ulo1);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 1, ulolo1);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%hhX", i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%hhX", i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%hX", i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%X", i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%lX", i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%llX", 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%hhX", i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%hX", i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%X", i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%lX", i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%llX", 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Width{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Width{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Width{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Width{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Width{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Width{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Width{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Width{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Width{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Width{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Width{}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::w_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::w_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::w_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::w_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::w_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::w_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::w_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::w_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::w_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::w_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::w_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*hhi", 0, i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*hhi", 0, i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*hi", 0, i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*i", 0, i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*li", 0, i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*lli", 0, i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", 0, i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*hi", 0, i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*i", 0, i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*li", 0, i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*lli", 0, i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, wd2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd2);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, wd2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd2);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, wd2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd2);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, wd2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd2);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, wd2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd2);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, wd2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd2);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, wd2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd2);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, wd2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, wd2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, wd2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd2);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, wd2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd2);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*hhi", wd2, i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*hhi", wd2, i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*hi", wd2, i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*i", wd2, i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*li", wd2, i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*lli", wd2, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%*hhi", wd2, i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*hi", wd2, i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*i", wd2, i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*li", wd2, i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*lli", wd2, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, wd3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, wd3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, wd3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, wd3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, wd3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, wd3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, wd3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, wd3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, wd3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, wd3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, wd3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*hhi", wd3, i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*hhi", wd3, i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*hi", wd3, i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*i", wd3, i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*li", wd3, i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*lli", wd3, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%*hhi", wd3, i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*hi", wd3, i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*i", wd3, i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*li", wd3, i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*lli", wd3, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::w_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::w_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::w_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::w_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::w_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::w_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::w_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::w_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::w_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::w_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::w_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*hhX", 0, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hhX", 0, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", 0, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", 0, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", 0, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", 0, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhX", 0, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", 0, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", 0, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", 0, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", 0, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, wd2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd2);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, wd2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd2);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, wd2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd2);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, wd2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd2);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, wd2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd2);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, wd2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd2);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, wd2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd2);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, wd2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, wd2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, wd2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd2);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, wd2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd2);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*hhX", wd2, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*hhX", wd2, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*hX", wd2, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*X", wd2, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*lX", wd2, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*llX", wd2, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%*hhX", wd2, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*hX", wd2, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*X", wd2, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*lX", wd2, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*llX", wd2, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, wd3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, wd3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, wd3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, wd3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, wd3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, wd3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, wd3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, wd3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, wd3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, wd3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, wd3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*hhX", wd3,
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*hhX", wd3,
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*hX", wd3,
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*X", wd3,
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*lX", wd3,
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*llX", wd3,
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%*hhX", wd3,
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*hX", wd3,
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*X", wd3,
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*lX", wd3,
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*llX", wd3,
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Width{wd1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Width{wd1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Width{wd1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Width{wd1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Width{wd1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Width{wd1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Width{wd1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Width{wd1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Width{wd1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Width{wd1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Width{wd1}};

        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::w_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::w_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::w_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::w_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::w_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::w_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::w_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::w_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::w_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::w_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::w_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*hhi", wd1, 
            i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*hhi", wd1, 
            i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*hi", wd1, 
            i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*i", wd1, 
            i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*li", wd1, 
            i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*lli", wd1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%*hhi", wd1, 
            i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*hi", wd1, 
            i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*i", wd1, 
            i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*li", wd1, 
            i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*lli", wd1, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(2, wd2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, wd2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, wd2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, wd2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, wd2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, wd2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, wd2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, wd2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, wd2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, wd2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, wd2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*hhi", wd1, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*hhi", wd1, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*hi", wd1, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*i", wd1, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*li", wd1, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*lli", wd1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%*hhi", wd1, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*hi", wd1, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*i", wd1, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*li", wd1, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*lli", wd1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, wd3, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, wd3, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, wd3, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, wd3, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, wd3, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, wd3, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, wd3, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, wd3, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, wd3, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, wd3, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, wd3, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*hhi", wd1, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*hhi", wd1, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*hi", wd1, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*i", wd1, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*li", wd1, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*lli", wd1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%*hhi", wd1, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*hi", wd1, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*i", wd1, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*li", wd1, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*lli", wd1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::w_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::w_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::w_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::w_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::w_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::w_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::w_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::w_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::w_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::w_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::w_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*hhX", wd1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hhX", wd1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", wd1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", wd1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", wd1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", wd1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*hhX", wd1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*hX", wd1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*X", wd1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*lX", wd1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*llX", wd1, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(2, wd2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, wd2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, wd2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, wd2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, wd2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, wd2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, wd2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, wd2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, wd2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, wd2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, wd2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*hhX", wd1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*hhX", wd1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*hX", wd1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*X", wd1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*lX", wd1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*llX", wd1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%*hhX", wd1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*hX", wd1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*X", wd1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*lX", wd1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*llX", wd1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, wd3, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, wd3, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, wd3, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, wd3, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, wd3, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, wd3, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, wd3, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, wd3, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, wd3, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, wd3, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, wd3, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*hhX", wd1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*hhX", wd1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*hX", wd1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*X", wd1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*lX", wd1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*llX", wd1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%*hhX", wd1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*hX", wd1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*X", wd1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*lX", wd1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*llX", wd1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Length{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Length{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Length{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Length{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Length{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Length{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Length{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Length{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Length{}};
        
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::l_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::l_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::l_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::l_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::l_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::l_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::l_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::l_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::l_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::l_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::l_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*hhi", 0, i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%.*hhi", 0, i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%.*hi", 0, i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%.*i", 0, i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%.*li", 0, i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%.*lli", 0, i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", 0, i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%.*hi", 0, i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%.*i", 0, i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%.*li", 0, i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%.*lli", 0, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, ln2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln2);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, ln2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln2);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, ln2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln2);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, ln2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln2);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, ln2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln2);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, ln2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln2);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, ln2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln2);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, ln2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, ln2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln2);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, ln2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln2);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*hhi", ln2, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%.*hhi", ln2, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%.*hi", ln2, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%.*i", ln2, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%.*li", ln2, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%.*lli", ln2, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%.*hhi", ln2, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%.*hi", ln2, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%.*i", ln2, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%.*li", ln2, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%.*lli", ln2, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, ln3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, ln3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, ln3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, ln3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, ln3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, ln3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, ln3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, ln3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, ln3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, ln3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, ln3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*hhi", ln3, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%.*hhi", ln3, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%.*hi", ln3, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%.*i", ln3, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%.*li", ln3, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%.*lli", ln3, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%.*hhi", ln3, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%.*hi", ln3, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%.*i", ln3, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%.*li", ln3, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%.*lli", ln3, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::l_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::l_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::l_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::l_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::l_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::l_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::l_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == flag::Integer::l_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::l_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == flag::Integer::l_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::l_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*hhX", 0,
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hhX", 0,
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", 0,
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", 0,
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", 0,
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", 0,
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhX", 0,
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", 0,
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", 0,
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", 0,
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", 0,
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, ln2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln2);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, ln2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln2);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, ln2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln2);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, ln2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln2);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, ln2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln2);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, ln2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln2);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, ln2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln2);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, ln2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, ln2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln2);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, ln2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln2);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*hhX", ln2, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%.*hhX", ln2, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%.*hX", ln2, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%.*X", ln2, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%.*lX", ln2, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%.*llX", ln2, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%.*hhX", ln2, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%.*hX", ln2, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%.*X", ln2, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%.*lX", ln2, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%.*llX", ln2, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, ln3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, ln3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, ln3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, ln3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, ln3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, ln3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, ln3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, ln3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, ln3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, ln3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, ln3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*hhX", ln3, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%.*hhX", ln3, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%.*hX", ln3, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%.*X", ln3, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%.*lX", ln3, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%.*llX", ln3, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%.*hhX", ln3, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%.*hX", ln3, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%.*X", ln3, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%.*lX", ln3, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%.*llX", ln3, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Length{ln1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Length{ln1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Length{ln1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Length{ln1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Length{ln1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Length{ln1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Length{ln1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.GetFlag() == flag::Integer::l_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.GetFlag() == flag::Integer::l_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::l_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::l_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.GetFlag() == flag::Integer::l_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.GetFlag() == flag::Integer::l_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == flag::Integer::l_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.GetFlag() == flag::Integer::l_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == flag::Integer::l_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.GetFlag() == flag::Integer::l_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::l_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*hhi", ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%.*hhi", ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%.*hi", ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%.*i", ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%.*li", ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%.*lli", ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%.*hhi", ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%.*hi", ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%.*i", ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%.*li", ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%.*lli", ln1, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*hhi", ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%.*hhi", ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%.*hi", ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%.*i", ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%.*li", ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%.*lli", ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%.*hhi", ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%.*hi", ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%.*i", ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%.*li", ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%.*lli", ln1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, ln3, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, ln3, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, ln3, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, ln3, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, ln3, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, ln3, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, ln3, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, ln3, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, ln3, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, ln3, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, ln3, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*hhi", ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%.*hhi", ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%.*hi", ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%.*i", ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%.*li", ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%.*lli", ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%.*hhi", ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%.*hi", ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%.*i", ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%.*li", ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%.*lli", ln1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.GetFlag() == flag::Integer::l_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.GetFlag() == flag::Integer::l_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::l_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::l_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.GetFlag() == flag::Integer::l_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.GetFlag() == flag::Integer::l_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == flag::Integer::l_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.GetFlag() == flag::Integer::l_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == flag::Integer::l_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.GetFlag() == flag::Integer::l_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::l_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%.*hhX", ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hhX", ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%.*hhX", ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%.*hX", ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%.*X", ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%.*lX", ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%.*llX", ln1, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%.*hhX", ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%.*hhX", ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%.*hX", ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%.*X", ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%.*lX", ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%.*llX", ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%.*hhX", ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%.*hX", ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%.*X", ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%.*lX", ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%.*llX", ln1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, ln3, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, ln3, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, ln3, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, ln3, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, ln3, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, ln3, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, ln3, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, ln3, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, ln3, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, ln3, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, ln3, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%.*hhX", ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%.*hhX", ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%.*hX", ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%.*X", ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%.*lX", ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%.*llX", ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%.*hhX", ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%.*hX", ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%.*X", ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%.*lX", ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%.*llX", ln1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Width{wd1},
            arg::Length{}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::wl_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::wl_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::wl_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::wl_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::wl_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == 
                flag::Integer::wl_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::wl_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhi", wd1, 0, 
            i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hhi", wd1, 0, 
            i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", wd1, 0, 
            i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", wd1, 0, 
            i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", wd1, 0, 
            i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", wd1, 0, 
            i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", wd1, 0, 
            i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", wd1, 0, 
            i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", wd1, 0, 
            i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", wd1, 0, 
            i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", wd1, 0, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, ln2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln2);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, ln2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln2);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, ln2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln2);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, ln2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln2);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, ln2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln2);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, ln2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln2);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, ln2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln2);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, ln2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, ln2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln2);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, ln2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln2);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhi", wd1, ln2, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd1, ln2, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd1, ln2, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd1, ln2, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd1, ln2, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd1, ln2, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd1, ln2, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd1, ln2, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd1, ln2, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd1, ln2, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd1, ln2, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, ln3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, ln3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, ln3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, ln3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, ln3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, ln3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, ln3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, ln3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, ln3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, ln3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, ln3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhi", wd1, ln3, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd1, ln3, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd1, ln3, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd1, ln3, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd1, ln3, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd1, ln3, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd1, ln3, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd1, ln3, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd1, ln3, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd1, ln3, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd1, ln3, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::wl_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::wl_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::wl_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::wl_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::wl_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::wl_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhX", wd1, 0, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hhX", wd1, 0, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", wd1, 0, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", wd1, 0, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", wd1, 0, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", wd1, 0, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhX", wd1, 0, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", wd1, 0, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", wd1, 0, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", wd1, 0, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", wd1, 0, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, ln2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln2);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, ln2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln2);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, ln2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln2);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, ln2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln2);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, ln2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln2);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, ln2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln2);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, ln2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln2);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, ln2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, ln2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln2);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, ln2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln2);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhX", wd1, ln2, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd1, ln2, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd1, ln2, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd1, ln2, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd1, ln2, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd1, ln2, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd1, ln2, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd1, ln2, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd1, ln2, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd1, ln2, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd1, ln2, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, ln3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, ln3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, ln3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, ln3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, ln3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, ln3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, ln3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, ln3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, ln3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, ln3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, ln3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhX", wd1, ln3, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd1, ln3, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd1, ln3, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd1, ln3, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd1, ln3, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd1, ln3, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd1, ln3, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd1, ln3, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd1, ln3, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd1, ln3, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd1, ln3, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Width{},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::wl_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::wl_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.GetFlag() == flag::Integer::wl_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.GetFlag() == flag::Integer::wl_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == flag::Integer::wl_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.GetFlag() == 
                flag::Integer::wl_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == flag::Integer::wl_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhi", 0, ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 0, ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 0, ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", 0, ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", 0, ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 0, ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 0, ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 0, ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", 0, ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", 0, ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 0, ln1, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, wd2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd2);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, wd2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd2);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, wd2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd2);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, wd2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd2);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, wd2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd2);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, wd2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd2);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, wd2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd2);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, wd2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, wd2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, wd2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd2);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, wd2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd2);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhi", wd2, ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd2, ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd2, ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd2, ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd2, ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd2, ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd2, ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd2, ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd2, ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd2, ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd2, ln1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, wd3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, wd3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, wd3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, wd3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, wd3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, wd3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, wd3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, wd3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, wd3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, wd3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, wd3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhi", wd3, ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd3, ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd3, ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd3, ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd3, ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd3, ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd3, ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd3, ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd3, ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd3, ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd3, ln1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::wl_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::wl_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.GetFlag() == flag::Integer::wl_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.GetFlag() == flag::Integer::wl_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == flag::Integer::wl_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == flag::Integer::wl_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhX", 0, ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hhX", 0, ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 0, ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 0, ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 0, ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 0, ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhX", 0, ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 0, ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 0, ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 0, ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 0, ln1, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(2, wd2, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd2);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(2, wd2, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd2);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(2, wd2, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd2);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(2, wd2, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd2);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(2, wd2, lo2);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd2);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(2, wd2, lolo2);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd2);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(2, wd2, uch2);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd2);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(2, wd2, ush2);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(2, wd2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, wd2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd2);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(2, wd2, ulolo2);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd2);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhX", wd2, ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd2, ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd2, ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd2, ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd2, ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd2, ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd2, ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd2, ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd2, ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd2, ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd2, ln1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 2, wd3, sch3);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 2, wd3, ch3);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 2, wd3, sh3);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 2, wd3, in3);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 2, wd3, lo3);
            assert(len == 1);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 2, wd3, lolo3);
            assert(len == 1);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 2, wd3, uch3);
            assert(len == 1);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 2, wd3, ush3);
            assert(len == 1);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 2, wd3, uin3);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 2, wd3, ulo3);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 2, wd3, ulolo3);
            assert(len == 1);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhX", wd3, ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd3, ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd3, ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd3, ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd3, ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd3, ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd3, ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd3, ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd3, ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd3, ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd3, ln1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Width{},
            arg::Length{}};
        
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::wl_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::wl_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::wl_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::wl_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::wl_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == 
                flag::Integer::wl_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::wl_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhi", 0, 0, 
            i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 0, 0, 
            i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 0, 0, 
            i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", 0, 0, 
            i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", 0, 0, 
            i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 0, 0, 
            i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", 0, 0, 
            i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", 0, 0, 
            i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", 0, 0, 
            i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", 0, 0, 
            i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", 0, 0, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 2);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd2);
            assert(i1.GetLength() == ln2);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 2);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd2);
            assert(i2.GetLength() == ln2);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 2);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd2);
            assert(i3.GetLength() == ln2);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 2);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd2);
            assert(i4.GetLength() == ln2);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 2);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd2);
            assert(i5.GetLength() == ln2);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 2);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd2);
            assert(i6.GetLength() == ln2);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 2);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd2);
            assert(i7.GetLength() == ln2);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 2);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 2);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == ln2);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 2);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd2);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 2);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd2);
            assert(i11.GetLength() == ln2);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhi", wd2, ln2, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd2, ln2, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd2, ln2, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd2, ln2, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd2, ln2, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd2, ln2, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd2, ln2, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd2, ln2, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd2, ln2, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd2, ln2, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd2, ln2, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 3, wd3, ln3, sch3);
            assert(len == 2);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 3, wd3, ln3, ch3);
            assert(len == 2);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 3, wd3, ln3, sh3);
            assert(len == 2);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 3, wd3, ln3, in3);
            assert(len == 2);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 3, wd3, ln3, lo3);
            assert(len == 2);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 3, wd3, ln3, lolo3);
            assert(len == 2);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 3, wd3, ln3, uch3);
            assert(len == 2);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 3, wd3, ln3, ush3);
            assert(len == 2);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 3, wd3, ln3, uin3);
            assert(len == 2);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 3, wd3, ln3, ulo3);
            assert(len == 2);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 3, wd3, ln3, ulolo3);
            assert(len == 2);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhi", wd3, ln3, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd3, ln3, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd3, ln3, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd3, ln3, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd3, ln3, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd3, ln3, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd3, ln3, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd3, ln3, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd3, ln3, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd3, ln3, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd3, ln3, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.GetFlag() == flag::Integer::wl_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.GetFlag() == flag::Integer::wl_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::wl_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::wl_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.GetFlag() == flag::Integer::wl_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.GetFlag() == flag::Integer::wl_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhX", 0, 0, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hhX", 0, 0, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 0, 0, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 0, 0, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 0, 0, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 0, 0, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhX", 0, 0, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", 0, 0, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", 0, 0, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", 0, 0, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", 0, 0, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == false);
            assert(i1.IsBad() == true);
            assert(i1.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i2.IsGood() == false);
            assert(i2.IsBad() == true);
            assert(i2.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i3.IsGood() == false);
            assert(i3.IsBad() == true);
            assert(i3.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i4.IsGood() == false);
            assert(i4.IsBad() == true);
            assert(i4.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i5.IsGood() == false);
            assert(i5.IsBad() == true);
            assert(i5.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i6.IsGood() == false);
            assert(i6.IsBad() == true);
            assert(i6.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i7.IsGood() == false);
            assert(i7.IsBad() == true);
            assert(i7.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i8.IsGood() == false);
            assert(i8.IsBad() == true);
            assert(i8.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i9.IsGood() == false);
            assert(i9.IsBad() == true);
            assert(i9.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i10.IsGood() == false);
            assert(i10.IsBad() == true);
            assert(i10.GetBadCode() == Integer<char>::StatusType::value_not_set);
           
            assert(i11.IsGood() == false);
            assert(i11.IsBad() == true);
            assert(i11.GetBadCode() == Integer<char>::StatusType::value_not_set);
        }

        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 2);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd2);
            assert(i1.GetLength() == ln2);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 2);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd2);
            assert(i2.GetLength() == ln2);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 2);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd2);
            assert(i3.GetLength() == ln2);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 2);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd2);
            assert(i4.GetLength() == ln2);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 2);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd2);
            assert(i5.GetLength() == ln2);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 2);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd2);
            assert(i6.GetLength() == ln2);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 2);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd2);
            assert(i7.GetLength() == ln2);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 2);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 2);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == ln2);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 2);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd2);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 2);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd2);
            assert(i11.GetLength() == ln2);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhX", wd2, ln2, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd2, ln2, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd2, ln2, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd2, ln2, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd2, ln2, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd2, ln2, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd2, ln2, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd2, ln2, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd2, ln2, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd2, ln2, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd2, ln2, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 3, wd3, ln3, sch3);
            assert(len == 2);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 3, wd3, ln3, ch3);
            assert(len == 2);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 3, wd3, ln3, sh3);
            assert(len == 2);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 3, wd3, ln3, in3);
            assert(len == 2);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 3, wd3, ln3, lo3);
            assert(len == 2);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 3, wd3, ln3, lolo3);
            assert(len == 2);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 3, wd3, ln3, uch3);
            assert(len == 2);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 3, wd3, ln3, ush3);
            assert(len == 2);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 3, wd3, ln3, uin3);
            assert(len == 2);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 3, wd3, ln3, ulo3);
            assert(len == 2);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 3, wd3, ln3, ulolo3);
            assert(len == 2);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd3);
            assert(i1.GetLength() == ln3);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd3);
            assert(i2.GetLength() == ln3);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd3);
            assert(i3.GetLength() == ln3);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd3);
            assert(i4.GetLength() == ln3);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd3);
            assert(i5.GetLength() == ln3);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd3);
            assert(i6.GetLength() == ln3);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd3);
            assert(i7.GetLength() == ln3);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd3);
            assert(i8.GetLength() == ln3);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd3);
            assert(i9.GetLength() == ln3);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd3);
            assert(i10.GetLength() == ln3);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd3);
            assert(i11.GetLength() == ln3);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhX", wd3, ln3, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd3, ln3, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd3, ln3, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd3, ln3, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd3, ln3, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd3, ln3, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd3, ln3, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd3, ln3, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd3, ln3, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd3, ln3, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd3, ln3, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == 0);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == 0);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == 0);
            assert(i4.GetLength() == 0);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == false);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == false);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == 0);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == false);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == 0);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == 0);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == 0);
            assert(i10.GetLength() == 0);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == false);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == 0);
            assert(i11.GetLength() == 0);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Width{wd1},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.GetFlag() == flag::Integer::wl_lds_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::wl_lds_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::wl_lds_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.GetFlag() == flag::Integer::wl_lds_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.GetFlag() == flag::Integer::wl_lds_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == flag::Integer::wl_lds_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.GetFlag() == 
                flag::Integer::wl_lds_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == flag::Integer::wl_lds_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::wl_lds_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhi", wd1, ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hhi", wd1, ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", wd1, ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", wd1, ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", wd1, ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", wd1, ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhi", wd1, ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr1_a.Print("%*.*hi", wd1, ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr1_a.Print("%*.*i", wd1, ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr1_a.Print("%*.*li", wd1, ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr1_a.Print("%*.*lli", wd1, ln1, 
            i11.GetValue().long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhi", wd1, ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd1, ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd1, ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd1, ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd1, ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd1, ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhi", wd1, ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr2_a.Print("%*.*hi", wd1, ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr2_a.Print("%*.*i", wd1, ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr2_a.Print("%*.*li", wd1, ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr2_a.Print("%*.*lli", wd1, ln1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 3, wd3, ln3, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 3, wd3, ln3, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 3, wd3, ln3, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 3, wd3, ln3, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 3, wd3, ln3, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 3, wd3, ln3, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 3, wd3, ln3, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 3, wd3, ln3, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 3, wd3, ln3, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 3, wd3, ln3, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 3, wd3, ln3, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhi", wd1, ln1, 
            i1.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd1, ln1, 
            i2.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd1, ln1, 
            i3.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd1, ln1, 
            i4.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd1, ln1, 
            i5.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd1, ln1, 
            i6.GetValue().long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhi", wd1, ln1, 
            i7.GetValue().char_value);
        len_a += out_cstr3_a.Print("%*.*hi", wd1, ln1, 
            i8.GetValue().short_value);
        len_a += out_cstr3_a.Print("%*.*i", wd1, ln1, 
            i9.GetValue().int_value);
        len_a += out_cstr3_a.Print("%*.*li", wd1, ln1, 
            i10.GetValue().long_value);
        len_a += out_cstr3_a.Print("%*.*lli", wd1, ln1, 
            i11.GetValue().long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }
    {
        Integer<char> i1{sch1,
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i2{ch1,
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i3{sh1,
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i4{in1,
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i6{lolo1,
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i7{uch1,
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i9{uin1,
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i11{ulolo1,
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.GetFlag() == flag::Integer::wl_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::wl_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::wl_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.GetFlag() == flag::Integer::wl_uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.GetFlag() == flag::Integer::wl_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == flag::Integer::wl_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == flag::Integer::wl_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::wl_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto len_a = out_cstr1_a.Print("%*.*hhX", wd1, ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hhX", wd1, ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", wd1, ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", wd1, ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", wd1, ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", wd1, ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr1_a.Print("%*.*hhX", wd1, ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr1_a.Print("%*.*hX", wd1, ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr1_a.Print("%*.*X", wd1, ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr1_a.Print("%*.*lX", wd1, ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr1_a.Print("%*.*llX", wd1, ln1, 
            i11.GetValue().unsigned_long_long_value);

        auto len_b = i1.Output(out_cstr1_b);
        len_b += i2.Output(out_cstr1_b);
        len_b += i3.Output(out_cstr1_b);
        len_b += i4.Output(out_cstr1_b);
        len_b += i5.Output(out_cstr1_b);
        len_b += i6.Output(out_cstr1_b);
        len_b += i7.Output(out_cstr1_b);
        len_b += i8.Output(out_cstr1_b);
        len_b += i9.Output(out_cstr1_b);
        len_b += i10.Output(out_cstr1_b);
        len_b += i11.Output(out_cstr1_b);

        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        test::out::CString<char> out_cstr2_a, out_cstr2_b;
        len_a = out_cstr2_a.Print("%*.*hhX", wd1, ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd1, ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd1, ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd1, ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd1, ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd1, ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr2_a.Print("%*.*hhX", wd1, ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr2_a.Print("%*.*hX", wd1, ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr2_a.Print("%*.*X", wd1, ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr2_a.Print("%*.*lX", wd1, ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr2_a.Print("%*.*llX", wd1, ln1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr2_b);
        len_b += i2.Output(out_cstr2_b);
        len_b += i3.Output(out_cstr2_b);
        len_b += i4.Output(out_cstr2_b);
        len_b += i5.Output(out_cstr2_b);
        len_b += i6.Output(out_cstr2_b);
        len_b += i7.Output(out_cstr2_b);
        len_b += i8.Output(out_cstr2_b);
        len_b += i9.Output(out_cstr2_b);
        len_b += i10.Output(out_cstr2_b);
        len_b += i11.Output(out_cstr2_b);

        assert(len_a == len_b);
        assert(out_cstr2_a.Size() == out_cstr2_b.Size());
        assert(strncmp(*(out_cstr2_a.Get()), *(out_cstr2_b.Get()), 
            out_cstr2_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        {
            i1.Unset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            i2.Unset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Unset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Unset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Unset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Unset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Unset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Unset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Unset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Unset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Unset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = Load(i1, 3, wd3, ln3, sch3);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = Load(i2, 3, wd3, ln3, ch3);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i3, 3, wd3, ln3, sh3);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i4, 3, wd3, ln3, in3);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i5, 3, wd3, ln3, lo3);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i6, 3, wd3, ln3, lolo3);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i7, 3, wd3, ln3, uch3);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i8, 3, wd3, ln3, ush3);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i9, 3, wd3, ln3, uin3);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i10, 3, wd3, ln3, ulo3);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = Load(i11, 3, wd3, ln3, ulolo3);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            auto len = i1.Load(3, wd2, ln2, sch2);
            assert(len == 0);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);

            len = i2.Load(3, wd2, ln2, ch2);
            assert(len == 0);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);

            len = i3.Load(3, wd2, ln2, sh2);
            assert(len == 0);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);

            len = i4.Load(3, wd2, ln2, in2);
            assert(len == 0);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);

            len = i5.Load(3, wd2, ln2, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);

            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);

            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);

            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 0);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 0);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            len = i10.Load(3, wd2, ln2, ulo2);
            assert(len == 0);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }

        test::out::CString<char> out_cstr3_a, out_cstr3_b;
        len_a = out_cstr3_a.Print("%*.*hhX", wd1, ln1, 
            i1.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd1, ln1, 
            i2.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd1, ln1, 
            i3.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd1, ln1, 
            i4.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd1, ln1, 
            i5.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd1, ln1, 
            i6.GetValue().unsigned_long_long_value);
        len_a += out_cstr3_a.Print("%*.*hhX", wd1, ln1, 
            i7.GetValue().unsigned_char_value);
        len_a += out_cstr3_a.Print("%*.*hX", wd1, ln1, 
            i8.GetValue().unsigned_short_value);
        len_a += out_cstr3_a.Print("%*.*X", wd1, ln1, 
            i9.GetValue().unsigned_int_value);
        len_a += out_cstr3_a.Print("%*.*lX", wd1, ln1, 
            i10.GetValue().unsigned_long_value);
        len_a += out_cstr3_a.Print("%*.*llX", wd1, ln1, 
            i11.GetValue().unsigned_long_long_value);

        len_b = i1.Output(out_cstr3_b);
        len_b += i2.Output(out_cstr3_b);
        len_b += i3.Output(out_cstr3_b);
        len_b += i4.Output(out_cstr3_b);
        len_b += i5.Output(out_cstr3_b);
        len_b += i6.Output(out_cstr3_b);
        len_b += i7.Output(out_cstr3_b);
        len_b += i8.Output(out_cstr3_b);
        len_b += i9.Output(out_cstr3_b);
        len_b += i10.Output(out_cstr3_b);
        len_b += i11.Output(out_cstr3_b);

        assert(len_a == len_b);
        assert(out_cstr3_a.Size() == out_cstr3_b.Size());
        assert(strncmp(*(out_cstr3_a.Get()), *(out_cstr3_b.Get()), 
            out_cstr3_b.Size()) == 0);
        {
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
           
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        
        {
            i1.Reset();
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch1);
            assert(i1.GetWidth() == wd1);
            assert(i1.GetLength() == ln1);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            i2.Reset();
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch1);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == ln1);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            i3.Reset();
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh1);
            assert(i3.GetWidth() == wd1);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            i4.Reset();
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in1);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            i5.Reset();
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == wd1);
            assert(i5.GetLength() == ln1);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            i6.Reset();
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == ln1);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            i7.Reset();
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == wd1);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            i8.Reset();
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd1);
            assert(i8.GetLength() == ln1);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            i9.Reset();
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd1);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            i10.Reset();
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln1);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            i11.Reset();
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
    }

    {
        
        Integer<char> i1{
            arg::Prefix{},
            arg::Define<char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i2{
            arg::Prefix{},
            arg::Define<signed char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i3{
            arg::Prefix{},
            arg::Define<short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i4{
            arg::Prefix{},
            arg::Define<int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        Integer<char> i5{lo1,
            arg::Prefix{},
            arg::Define<long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{}};
        Integer<char> i6{lolo1,
            arg::Prefix{},
            arg::Define<long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1}};
        Integer<char> i7{uch1,
            arg::Prefix{},
            arg::Define<unsigned char>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Length{ln1}};
        Integer<char> i8{ush1,
            arg::Prefix{},
            arg::Define<unsigned short>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{}};
        Integer<char> i9{uin1,
            arg::Prefix{},
            arg::Define<unsigned int>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{},
            arg::Length{ln1}};
        Integer<char> i10{ulo1,
            arg::Prefix{},
            arg::Define<unsigned long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{}};
        Integer<char> i11{ulolo1,
            arg::Prefix{},
            arg::Define<unsigned long long>{},
            arg::Unsigned{},
            arg::Hexadecimal{},
            arg::Upper{},
            arg::Width{wd1},
            arg::Length{ln1}};
        
        {
            assert(i1.IsSet() == false);
            assert(i1.GetValue().char_value == 0);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2.IsSet() == false);
            assert(i2.GetValue().char_value == 0);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3.IsSet() == false);
            assert(i3.GetValue().short_value == 0);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4.IsSet() == false);
            assert(i4.GetValue().int_value == 0);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8.IsSet() == false);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == 0);
            assert(i8.GetLength() == 0);
            assert(i8.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9.IsSet() == false);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == 0);
            assert(i9.GetLength() == ln1);
            assert(i9.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10.IsSet() == false);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == 0);
            assert(i10.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i1.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i2.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i3.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i4.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i5.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i6.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i7.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i8.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i9.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i10.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i11.GetValue().unsigned_long_long_value);

            auto len_b = i1.Output(out_cstr1_b);
            len_b += i2.Output(out_cstr1_b);
            len_b += i3.Output(out_cstr1_b);
            len_b += i4.Output(out_cstr1_b);
            len_b += i5.Output(out_cstr1_b);
            len_b += i6.Output(out_cstr1_b);
            len_b += i7.Output(out_cstr1_b);
            len_b += i8.Output(out_cstr1_b);
            len_b += i9.Output(out_cstr1_b);
            len_b += i10.Output(out_cstr1_b);
            len_b += i11.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i1.IsGood() == false);
                assert(i1.IsBad() == true);
                assert(i1.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i2.IsGood() == false);
                assert(i2.IsBad() == true);
                assert(i2.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i3.IsGood() == false);
                assert(i3.IsBad() == true);
                assert(i3.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i4.IsGood() == false);
                assert(i4.IsBad() == true);
                assert(i4.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i5.IsGood() == true);
                assert(i5.IsBad() == false);
                assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i6.IsGood() == true);
                assert(i6.IsBad() == false);
                assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i7.IsGood() == true);
                assert(i7.IsBad() == false);
                assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i8.IsGood() == false);
                assert(i8.IsBad() == true);
                assert(i8.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i9.IsGood() == false);
                assert(i9.IsBad() == true);
                assert(i9.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i10.IsGood() == false);
                assert(i10.IsBad() == true);
                assert(i10.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i11.IsGood() == true);
                assert(i11.IsBad() == false);
                assert(i11.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            auto len = i1.Load(1, sch2);
            assert(len == 1);
            assert(i1.IsSet() == true);
            assert(i1.GetValue().char_value == sch2);
            assert(i1.GetWidth() == 0);
            assert(i1.GetLength() == 0);
            assert(i1.IsGood() == true);
            assert(i1.IsBad() == false);
            assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i2.Load(1, ch2);
            assert(len == 1);
            assert(i2.IsSet() == true);
            assert(i2.GetValue().char_value == ch2);
            assert(i2.GetWidth() == wd1);
            assert(i2.GetLength() == 0);
            assert(i2.IsGood() == true);
            assert(i2.IsBad() == false);
            assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i3.Load(1, sh2);
            assert(len == 1);
            assert(i3.IsSet() == true);
            assert(i3.GetValue().short_value == sh2);
            assert(i3.GetWidth() == 0);
            assert(i3.GetLength() == ln1);
            assert(i3.IsGood() == true);
            assert(i3.IsBad() == false);
            assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i4.Load(1, in2);
            assert(len == 1);
            assert(i4.IsSet() == true);
            assert(i4.GetValue().int_value == in2);
            assert(i4.GetWidth() == wd1);
            assert(i4.GetLength() == ln1);
            assert(i4.IsGood() == true);
            assert(i4.IsBad() == false);
            assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i5.Load(1, lo2);
            assert(len == 0);
            assert(i5.IsSet() == true);
            assert(i5.GetValue().long_value == lo1);
            assert(i5.GetWidth() == 0);
            assert(i5.GetLength() == 0);
            assert(i5.IsGood() == true);
            assert(i5.IsBad() == false);
            assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i6.Load(3, wd2, ln2, lolo2);
            assert(len == 0);
            assert(i6.IsSet() == true);
            assert(i6.GetValue().long_long_value == lolo1);
            assert(i6.GetWidth() == wd1);
            assert(i6.GetLength() == 0);
            assert(i6.IsGood() == true);
            assert(i6.IsBad() == false);
            assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i7.Load(3, wd2, ln2, uch2);
            assert(len == 0);
            assert(i7.IsSet() == true);
            assert(i7.GetValue().unsigned_char_value == uch1);
            assert(i7.GetWidth() == 0);
            assert(i7.GetLength() == ln1);
            assert(i7.IsGood() == true);
            assert(i7.IsBad() == false);
            assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i8.Load(3, wd2, ln2, ush2);
            assert(len == 2);
            assert(i8.IsSet() == true);
            assert(i8.GetValue().unsigned_short_value == ush1);
            assert(i8.GetWidth() == wd2);
            assert(i8.GetLength() == ln2);
            assert(i8.IsGood() == true);
            assert(i8.IsBad() == false);
            assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i9.Load(3, wd2, ln2, uin2);
            assert(len == 1);
            assert(i9.IsSet() == true);
            assert(i9.GetValue().unsigned_int_value == uin1);
            assert(i9.GetWidth() == wd2);
            assert(i9.GetLength() == ln1);
            assert(i9.IsGood() == true);
            assert(i9.IsBad() == false);
            assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i10.Load(2, ln2, ulo2);
            assert(len == 1);
            assert(i10.IsSet() == true);
            assert(i10.GetValue().unsigned_long_value == ulo1);
            assert(i10.GetWidth() == wd1);
            assert(i10.GetLength() == ln2);
            assert(i10.IsGood() == true);
            assert(i10.IsBad() == false);
            assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
            len = i11.Load(3, wd2, ln2, ulolo2);
            assert(len == 0);
            assert(i11.IsSet() == true);
            assert(i11.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11.GetWidth() == wd1);
            assert(i11.GetLength() == ln1);
            assert(i11.IsGood() == true);
            assert(i11.IsBad() == false);
            assert(i11.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i1.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i2.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i3.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i4.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i5.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i6.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i7.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", wd2, ln2, 
                i8.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd2, ln1, 
                i9.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, ln2, 
                i10.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i11.GetValue().unsigned_long_long_value);

            auto len_b = i1.Output(out_cstr1_b);
            len_b += i2.Output(out_cstr1_b);
            len_b += i3.Output(out_cstr1_b);
            len_b += i4.Output(out_cstr1_b);
            len_b += i5.Output(out_cstr1_b);
            len_b += i6.Output(out_cstr1_b);
            len_b += i7.Output(out_cstr1_b);
            len_b += i8.Output(out_cstr1_b);
            len_b += i9.Output(out_cstr1_b);
            len_b += i10.Output(out_cstr1_b);
            len_b += i11.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i1.IsGood() == true);
                assert(i1.IsBad() == false);
                assert(i1.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i2.IsGood() == true);
                assert(i2.IsBad() == false);
                assert(i2.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i3.IsGood() == true);
                assert(i3.IsBad() == false);
                assert(i3.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i4.IsGood() == true);
                assert(i4.IsBad() == false);
                assert(i4.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i5.IsGood() == true);
                assert(i5.IsBad() == false);
                assert(i5.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i6.IsGood() == true);
                assert(i6.IsBad() == false);
                assert(i6.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i7.IsGood() == true);
                assert(i7.IsBad() == false);
                assert(i7.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i8.IsGood() == true);
                assert(i8.IsBad() == false);
                assert(i8.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i9.IsGood() == true);
                assert(i9.IsBad() == false);
                assert(i9.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i10.IsGood() == true);
                assert(i10.IsBad() == false);
                assert(i10.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i11.IsGood() == true);
                assert(i11.IsBad() == false);
                assert(i11.GetBadCode() == Integer<char>::StatusType::good);
            }
        }

        Integer<char> i12{i1};
        Integer<char> i13{i2};
        Integer<char> i14{i3};
        Integer<char> i15{i4};
        Integer<char> i16{i5};
        Integer<char> i17{i6};
        Integer<char> i18{i7};
        Integer<char> i19{i8};
        Integer<char> i20{i9};
        Integer<char> i21{i10};
        Integer<char> i22{i11};

        {
            assert(i12.IsSet() == true);
            assert(i12.GetValue().char_value == sch2);
            assert(i12.GetWidth() == 0);
            assert(i12.GetLength() == 0);
            assert(i12.IsGood() == true);
            assert(i12.IsBad() == false);
            assert(i12.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i13.IsSet() == true);
            assert(i13.GetValue().char_value == ch2);
            assert(i13.GetWidth() == wd1);
            assert(i13.GetLength() == 0);
            assert(i13.IsGood() == true);
            assert(i13.IsBad() == false);
            assert(i13.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i14.IsSet() == true);
            assert(i14.GetValue().short_value == sh2);
            assert(i14.GetWidth() == 0);
            assert(i14.GetLength() == ln1);
            assert(i14.IsGood() == true);
            assert(i14.IsBad() == false);
            assert(i14.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i15.IsSet() == true);
            assert(i15.GetValue().int_value == in2);
            assert(i15.GetWidth() == wd1);
            assert(i15.GetLength() == ln1);
            assert(i15.IsGood() == true);
            assert(i15.IsBad() == false);
            assert(i15.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i16.IsSet() == true);
            assert(i16.GetValue().long_value == lo1);
            assert(i16.GetWidth() == 0);
            assert(i16.GetLength() == 0);
            assert(i16.IsGood() == true);
            assert(i16.IsBad() == false);
            assert(i16.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i17.IsSet() == true);
            assert(i17.GetValue().long_long_value == lolo1);
            assert(i17.GetWidth() == wd1);
            assert(i17.GetLength() == 0);
            assert(i17.IsGood() == true);
            assert(i17.IsBad() == false);
            assert(i17.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i18.IsSet() == true);
            assert(i18.GetValue().unsigned_char_value == uch1);
            assert(i18.GetWidth() == 0);
            assert(i18.GetLength() == ln1);
            assert(i18.IsGood() == true);
            assert(i18.IsBad() == false);
            assert(i18.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i19.IsSet() == true);
            assert(i19.GetValue().unsigned_short_value == ush1);
            assert(i19.GetWidth() == wd2);
            assert(i19.GetLength() == ln2);
            assert(i19.IsGood() == true);
            assert(i19.IsBad() == false);
            assert(i19.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i20.IsSet() == true);
            assert(i20.GetValue().unsigned_int_value == uin1);
            assert(i20.GetWidth() == wd2);
            assert(i20.GetLength() == ln1);
            assert(i20.IsGood() == true);
            assert(i20.IsBad() == false);
            assert(i20.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i21.IsSet() == true);
            assert(i21.GetValue().unsigned_long_value == ulo1);
            assert(i21.GetWidth() == wd1);
            assert(i21.GetLength() == ln2);
            assert(i21.IsGood() == true);
            assert(i21.IsBad() == false);
            assert(i21.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i22.IsSet() == true);
            assert(i22.GetValue().unsigned_long_long_value == ulolo1);
            assert(i22.GetWidth() == wd1);
            assert(i22.GetLength() == ln1);
            assert(i22.IsGood() == true);
            assert(i22.IsBad() == false);
            assert(i22.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i12.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i13.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i14.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i15.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i16.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i17.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i18.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", wd2, ln2, 
                i19.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd2, ln1, 
                i20.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, ln2, 
                i21.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i22.GetValue().unsigned_long_long_value);

            auto len_b = i12.Output(out_cstr1_b);
            len_b += i13.Output(out_cstr1_b);
            len_b += i14.Output(out_cstr1_b);
            len_b += i15.Output(out_cstr1_b);
            len_b += i16.Output(out_cstr1_b);
            len_b += i17.Output(out_cstr1_b);
            len_b += i18.Output(out_cstr1_b);
            len_b += i19.Output(out_cstr1_b);
            len_b += i20.Output(out_cstr1_b);
            len_b += i21.Output(out_cstr1_b);
            len_b += i22.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i12.IsGood() == true);
                assert(i12.IsBad() == false);
                assert(i12.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i13.IsGood() == true);
                assert(i13.IsBad() == false);
                assert(i13.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i14.IsGood() == true);
                assert(i14.IsBad() == false);
                assert(i14.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i15.IsGood() == true);
                assert(i15.IsBad() == false);
                assert(i15.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i16.IsGood() == true);
                assert(i16.IsBad() == false);
                assert(i16.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i17.IsGood() == true);
                assert(i17.IsBad() == false);
                assert(i17.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i18.IsGood() == true);
                assert(i18.IsBad() == false);
                assert(i18.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i19.IsGood() == true);
                assert(i19.IsBad() == false);
                assert(i19.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i20.IsGood() == true);
                assert(i20.IsBad() == false);
                assert(i20.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i21.IsGood() == true);
                assert(i21.IsBad() == false);
                assert(i21.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i22.IsGood() == true);
                assert(i22.IsBad() == false);
                assert(i22.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            i12.Unset();
            assert(i12.IsSet() == false);
            assert(i12.GetValue().char_value == 0);
            assert(i12.GetWidth() == 0);
            assert(i12.GetLength() == 0);
            assert(i12.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i12.IsGood() == true);
            assert(i12.IsBad() == false);
            assert(i12.GetBadCode() == Integer<char>::StatusType::good);
            
            i13.Unset();
            assert(i13.IsSet() == false);
            assert(i13.GetValue().char_value == 0);
            assert(i13.GetWidth() == wd1);
            assert(i13.GetLength() == 0);
            assert(i13.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i13.IsGood() == true);
            assert(i13.IsBad() == false);
            assert(i13.GetBadCode() == Integer<char>::StatusType::good);
            
            i14.Unset();
            assert(i14.IsSet() == false);
            assert(i14.GetValue().short_value == 0);
            assert(i14.GetWidth() == 0);
            assert(i14.GetLength() == ln1);
            assert(i14.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i14.IsGood() == true);
            assert(i14.IsBad() == false);
            assert(i14.GetBadCode() == Integer<char>::StatusType::good);
            
            i15.Unset();
            assert(i15.IsSet() == false);
            assert(i15.GetValue().int_value == 0);
            assert(i15.GetWidth() == wd1);
            assert(i15.GetLength() == ln1);
            assert(i15.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i15.IsGood() == true);
            assert(i15.IsBad() == false);
            assert(i15.GetBadCode() == Integer<char>::StatusType::good);
            
            i16.Unset();
            assert(i16.IsSet() == true);
            assert(i16.GetValue().long_value == lo1);
            assert(i16.GetWidth() == 0);
            assert(i16.GetLength() == 0);
            assert(i16.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i16.IsGood() == true);
            assert(i16.IsBad() == false);
            assert(i16.GetBadCode() == Integer<char>::StatusType::good);
            
            i17.Unset();
            assert(i17.IsSet() == true);
            assert(i17.GetValue().long_long_value == lolo1);
            assert(i17.GetWidth() == wd1);
            assert(i17.GetLength() == 0);
            assert(i17.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i17.IsGood() == true);
            assert(i17.IsBad() == false);
            assert(i17.GetBadCode() == Integer<char>::StatusType::good);
            
            i18.Unset();
            assert(i18.IsSet() == true);
            assert(i18.GetValue().unsigned_char_value == uch1);
            assert(i18.GetWidth() == 0);
            assert(i18.GetLength() == ln1);
            assert(i18.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i18.IsGood() == true);
            assert(i18.IsBad() == false);
            assert(i18.GetBadCode() == Integer<char>::StatusType::good);
            
            i19.Unset();
            assert(i19.IsSet() == false);
            assert(i19.GetValue().unsigned_short_value == ush1);
            assert(i19.GetWidth() == 0);
            assert(i19.GetLength() == 0);
            assert(i19.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i19.IsGood() == true);
            assert(i19.IsBad() == false);
            assert(i19.GetBadCode() == Integer<char>::StatusType::good);

            i20.Unset();
            assert(i20.IsSet() == false);
            assert(i20.GetValue().unsigned_int_value == uin1);
            assert(i20.GetWidth() == 0);
            assert(i20.GetLength() == ln1);
            assert(i20.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i20.IsGood() == true);
            assert(i20.IsBad() == false);
            assert(i20.GetBadCode() == Integer<char>::StatusType::good);

            i21.Unset();
            assert(i21.IsSet() == false);
            assert(i21.GetValue().unsigned_long_value == ulo1);
            assert(i21.GetWidth() == wd1);
            assert(i21.GetLength() == 0);
            assert(i21.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i21.IsGood() == true);
            assert(i21.IsBad() == false);
            assert(i21.GetBadCode() == Integer<char>::StatusType::good);

            i22.Unset();
            assert(i22.IsSet() == true);
            assert(i22.GetValue().unsigned_long_long_value == ulolo1);
            assert(i22.GetWidth() == wd1);
            assert(i22.GetLength() == ln1);
            assert(i22.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i22.IsGood() == true);
            assert(i22.IsBad() == false);
            assert(i22.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i12.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i13.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i14.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i15.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i16.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i17.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i18.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i19.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i20.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i21.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i22.GetValue().unsigned_long_long_value);

            auto len_b = i12.Output(out_cstr1_b);
            len_b += i13.Output(out_cstr1_b);
            len_b += i14.Output(out_cstr1_b);
            len_b += i15.Output(out_cstr1_b);
            len_b += i16.Output(out_cstr1_b);
            len_b += i17.Output(out_cstr1_b);
            len_b += i18.Output(out_cstr1_b);
            len_b += i19.Output(out_cstr1_b);
            len_b += i20.Output(out_cstr1_b);
            len_b += i21.Output(out_cstr1_b);
            len_b += i22.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i12.IsGood() == false);
                assert(i12.IsBad() == true);
                assert(i12.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i13.IsGood() == false);
                assert(i13.IsBad() == true);
                assert(i13.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i14.IsGood() == false);
                assert(i14.IsBad() == true);
                assert(i14.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i15.IsGood() == false);
                assert(i15.IsBad() == true);
                assert(i15.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i16.IsGood() == true);
                assert(i16.IsBad() == false);
                assert(i16.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i17.IsGood() == true);
                assert(i17.IsBad() == false);
                assert(i17.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i18.IsGood() == true);
                assert(i18.IsBad() == false);
                assert(i18.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i19.IsGood() == false);
                assert(i19.IsBad() == true);
                assert(i19.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i20.IsGood() == false);
                assert(i20.IsBad() == true);
                assert(i20.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i21.IsGood() == false);
                assert(i21.IsBad() == true);
                assert(i21.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i22.IsGood() == true);
                assert(i22.IsBad() == false);
                assert(i22.GetBadCode() == Integer<char>::StatusType::good);
            }
        }

        Integer<char> i1_c{i1};
        Integer<char> i2_c{i2};
        Integer<char> i3_c{i3};
        Integer<char> i4_c{i4};
        Integer<char> i5_c{i5};
        Integer<char> i6_c{i6};
        Integer<char> i7_c{i7};
        Integer<char> i8_c{i8};
        Integer<char> i9_c{i9};
        Integer<char> i10_c{i10};
        Integer<char> i11_c{i11};

        Integer<char> i23{std::move(i1_c)};
        Integer<char> i24{std::move(i2_c)};
        Integer<char> i25{std::move(i3_c)};
        Integer<char> i26{std::move(i4_c)};
        Integer<char> i27{std::move(i5_c)};
        Integer<char> i28{std::move(i6_c)};
        Integer<char> i29{std::move(i7_c)};
        Integer<char> i30{std::move(i8_c)};
        Integer<char> i31{std::move(i9_c)};
        Integer<char> i32{std::move(i10_c)};
        Integer<char> i33{std::move(i11_c)};

        {
            assert(i23.IsSet() == true);
            assert(i23.GetValue().char_value == sch2);
            assert(i23.GetWidth() == 0);
            assert(i23.GetLength() == 0);
            assert(i23.IsGood() == true);
            assert(i23.IsBad() == false);
            assert(i23.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i24.IsSet() == true);
            assert(i24.GetValue().char_value == ch2);
            assert(i24.GetWidth() == wd1);
            assert(i24.GetLength() == 0);
            assert(i24.IsGood() == true);
            assert(i24.IsBad() == false);
            assert(i24.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i25.IsSet() == true);
            assert(i25.GetValue().short_value == sh2);
            assert(i25.GetWidth() == 0);
            assert(i25.GetLength() == ln1);
            assert(i25.IsGood() == true);
            assert(i25.IsBad() == false);
            assert(i25.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i26.IsSet() == true);
            assert(i26.GetValue().int_value == in2);
            assert(i26.GetWidth() == wd1);
            assert(i26.GetLength() == ln1);
            assert(i26.IsGood() == true);
            assert(i26.IsBad() == false);
            assert(i26.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i27.IsSet() == true);
            assert(i27.GetValue().long_value == lo1);
            assert(i27.GetWidth() == 0);
            assert(i27.GetLength() == 0);
            assert(i27.IsGood() == true);
            assert(i27.IsBad() == false);
            assert(i27.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i28.IsSet() == true);
            assert(i28.GetValue().long_long_value == lolo1);
            assert(i28.GetWidth() == wd1);
            assert(i28.GetLength() == 0);
            assert(i28.IsGood() == true);
            assert(i28.IsBad() == false);
            assert(i28.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i29.IsSet() == true);
            assert(i29.GetValue().unsigned_char_value == uch1);
            assert(i29.GetWidth() == 0);
            assert(i29.GetLength() == ln1);
            assert(i29.IsGood() == true);
            assert(i29.IsBad() == false);
            assert(i29.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i30.IsSet() == true);
            assert(i30.GetValue().unsigned_short_value == ush1);
            assert(i30.GetWidth() == wd2);
            assert(i30.GetLength() == ln2);
            assert(i30.IsGood() == true);
            assert(i30.IsBad() == false);
            assert(i30.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i31.IsSet() == true);
            assert(i31.GetValue().unsigned_int_value == uin1);
            assert(i31.GetWidth() == wd2);
            assert(i31.GetLength() == ln1);
            assert(i31.IsGood() == true);
            assert(i31.IsBad() == false);
            assert(i31.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i32.IsSet() == true);
            assert(i32.GetValue().unsigned_long_value == ulo1);
            assert(i32.GetWidth() == wd1);
            assert(i32.GetLength() == ln2);
            assert(i32.IsGood() == true);
            assert(i32.IsBad() == false);
            assert(i32.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i33.IsSet() == true);
            assert(i33.GetValue().unsigned_long_long_value == ulolo1);
            assert(i33.GetWidth() == wd1);
            assert(i33.GetLength() == ln1);
            assert(i33.IsGood() == true);
            assert(i33.IsBad() == false);
            assert(i33.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i23.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i24.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i25.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i26.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i27.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i28.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i29.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", wd2, ln2, 
                i30.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd2, ln1, 
                i31.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, ln2, 
                i32.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i33.GetValue().unsigned_long_long_value);

            auto len_b = i23.Output(out_cstr1_b);
            len_b += i24.Output(out_cstr1_b);
            len_b += i25.Output(out_cstr1_b);
            len_b += i26.Output(out_cstr1_b);
            len_b += i27.Output(out_cstr1_b);
            len_b += i28.Output(out_cstr1_b);
            len_b += i29.Output(out_cstr1_b);
            len_b += i30.Output(out_cstr1_b);
            len_b += i31.Output(out_cstr1_b);
            len_b += i32.Output(out_cstr1_b);
            len_b += i33.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i23.IsGood() == true);
                assert(i23.IsBad() == false);
                assert(i23.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i24.IsGood() == true);
                assert(i24.IsBad() == false);
                assert(i24.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i25.IsGood() == true);
                assert(i25.IsBad() == false);
                assert(i25.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i26.IsGood() == true);
                assert(i26.IsBad() == false);
                assert(i26.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i27.IsGood() == true);
                assert(i27.IsBad() == false);
                assert(i27.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i28.IsGood() == true);
                assert(i28.IsBad() == false);
                assert(i28.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i29.IsGood() == true);
                assert(i29.IsBad() == false);
                assert(i29.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i30.IsGood() == true);
                assert(i30.IsBad() == false);
                assert(i30.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i31.IsGood() == true);
                assert(i31.IsBad() == false);
                assert(i31.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i32.IsGood() == true);
                assert(i32.IsBad() == false);
                assert(i32.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i33.IsGood() == true);
                assert(i33.IsBad() == false);
                assert(i33.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            i23.Unset();
            assert(i23.IsSet() == false);
            assert(i23.GetValue().char_value == 0);
            assert(i23.GetWidth() == 0);
            assert(i23.GetLength() == 0);
            assert(i23.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i23.IsGood() == true);
            assert(i23.IsBad() == false);
            assert(i23.GetBadCode() == Integer<char>::StatusType::good);
            
            i24.Unset();
            assert(i24.IsSet() == false);
            assert(i24.GetValue().char_value == 0);
            assert(i24.GetWidth() == wd1);
            assert(i24.GetLength() == 0);
            assert(i24.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i24.IsGood() == true);
            assert(i24.IsBad() == false);
            assert(i24.GetBadCode() == Integer<char>::StatusType::good);
            
            i25.Unset();
            assert(i25.IsSet() == false);
            assert(i25.GetValue().short_value == 0);
            assert(i25.GetWidth() == 0);
            assert(i25.GetLength() == ln1);
            assert(i25.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i25.IsGood() == true);
            assert(i25.IsBad() == false);
            assert(i25.GetBadCode() == Integer<char>::StatusType::good);
            
            i26.Unset();
            assert(i26.IsSet() == false);
            assert(i26.GetValue().int_value == 0);
            assert(i26.GetWidth() == wd1);
            assert(i26.GetLength() == ln1);
            assert(i26.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i26.IsGood() == true);
            assert(i26.IsBad() == false);
            assert(i26.GetBadCode() == Integer<char>::StatusType::good);
            
            i27.Unset();
            assert(i27.IsSet() == true);
            assert(i27.GetValue().long_value == lo1);
            assert(i27.GetWidth() == 0);
            assert(i27.GetLength() == 0);
            assert(i27.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i27.IsGood() == true);
            assert(i27.IsBad() == false);
            assert(i27.GetBadCode() == Integer<char>::StatusType::good);
            
            i28.Unset();
            assert(i28.IsSet() == true);
            assert(i28.GetValue().long_long_value == lolo1);
            assert(i28.GetWidth() == wd1);
            assert(i28.GetLength() == 0);
            assert(i28.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i28.IsGood() == true);
            assert(i28.IsBad() == false);
            assert(i28.GetBadCode() == Integer<char>::StatusType::good);
            
            i29.Unset();
            assert(i29.IsSet() == true);
            assert(i29.GetValue().unsigned_char_value == uch1);
            assert(i29.GetWidth() == 0);
            assert(i29.GetLength() == ln1);
            assert(i29.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i29.IsGood() == true);
            assert(i29.IsBad() == false);
            assert(i29.GetBadCode() == Integer<char>::StatusType::good);
            
            i30.Unset();
            assert(i30.IsSet() == false);
            assert(i30.GetValue().unsigned_short_value == ush1);
            assert(i30.GetWidth() == 0);
            assert(i30.GetLength() == 0);
            assert(i30.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i30.IsGood() == true);
            assert(i30.IsBad() == false);
            assert(i30.GetBadCode() == Integer<char>::StatusType::good);

            i31.Unset();
            assert(i31.IsSet() == false);
            assert(i31.GetValue().unsigned_int_value == uin1);
            assert(i31.GetWidth() == 0);
            assert(i31.GetLength() == ln1);
            assert(i31.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i31.IsGood() == true);
            assert(i31.IsBad() == false);
            assert(i31.GetBadCode() == Integer<char>::StatusType::good);

            i32.Unset();
            assert(i32.IsSet() == false);
            assert(i32.GetValue().unsigned_long_value == ulo1);
            assert(i32.GetWidth() == wd1);
            assert(i32.GetLength() == 0);
            assert(i32.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i32.IsGood() == true);
            assert(i32.IsBad() == false);
            assert(i32.GetBadCode() == Integer<char>::StatusType::good);

            i33.Unset();
            assert(i33.IsSet() == true);
            assert(i33.GetValue().unsigned_long_long_value == ulolo1);
            assert(i33.GetWidth() == wd1);
            assert(i33.GetLength() == ln1);
            assert(i33.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i33.IsGood() == true);
            assert(i33.IsBad() == false);
            assert(i33.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i23.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i24.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i25.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i26.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i27.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i28.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i29.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i30.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i31.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i32.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i33.GetValue().unsigned_long_long_value);

            auto len_b = i23.Output(out_cstr1_b);
            len_b += i24.Output(out_cstr1_b);
            len_b += i25.Output(out_cstr1_b);
            len_b += i26.Output(out_cstr1_b);
            len_b += i27.Output(out_cstr1_b);
            len_b += i28.Output(out_cstr1_b);
            len_b += i29.Output(out_cstr1_b);
            len_b += i30.Output(out_cstr1_b);
            len_b += i31.Output(out_cstr1_b);
            len_b += i32.Output(out_cstr1_b);
            len_b += i33.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i23.IsGood() == false);
                assert(i23.IsBad() == true);
                assert(i23.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i24.IsGood() == false);
                assert(i24.IsBad() == true);
                assert(i24.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i25.IsGood() == false);
                assert(i25.IsBad() == true);
                assert(i25.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i26.IsGood() == false);
                assert(i26.IsBad() == true);
                assert(i26.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i27.IsGood() == true);
                assert(i27.IsBad() == false);
                assert(i27.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i28.IsGood() == true);
                assert(i28.IsBad() == false);
                assert(i28.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i29.IsGood() == true);
                assert(i29.IsBad() == false);
                assert(i29.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i30.IsGood() == false);
                assert(i30.IsBad() == true);
                assert(i30.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i31.IsGood() == false);
                assert(i31.IsBad() == true);
                assert(i31.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i32.IsGood() == false);
                assert(i32.IsBad() == true);
                assert(i32.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i33.IsGood() == true);
                assert(i33.IsBad() == false);
                assert(i33.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            assert(i1_c.IsSet() == false);
            assert(i1_c.GetValue().char_value == 0);
            assert(i1_c.GetWidth() == 0);
            assert(i1_c.GetLength() == 0);
            assert(i1_c.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i1_c.IsGood() == true);
            assert(i1_c.IsBad() == false);
            assert(i1_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2_c.IsSet() == false);
            assert(i2_c.GetValue().char_value == 0);
            assert(i2_c.GetWidth() == wd1);
            assert(i2_c.GetLength() == 0);
            assert(i2_c.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i2_c.IsGood() == true);
            assert(i2_c.IsBad() == false);
            assert(i2_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3_c.IsSet() == false);
            assert(i3_c.GetValue().short_value == 0);
            assert(i3_c.GetWidth() == 0);
            assert(i3_c.GetLength() == ln1);
            assert(i3_c.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i3_c.IsGood() == true);
            assert(i3_c.IsBad() == false);
            assert(i3_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4_c.IsSet() == false);
            assert(i4_c.GetValue().int_value == 0);
            assert(i4_c.GetWidth() == wd1);
            assert(i4_c.GetLength() == ln1);
            assert(i4_c.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i4_c.IsGood() == true);
            assert(i4_c.IsBad() == false);
            assert(i4_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5_c.IsSet() == true);
            assert(i5_c.GetValue().long_value == lo1);
            assert(i5_c.GetWidth() == 0);
            assert(i5_c.GetLength() == 0);
            assert(i5_c.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i5_c.IsGood() == true);
            assert(i5_c.IsBad() == false);
            assert(i5_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6_c.IsSet() == true);
            assert(i6_c.GetValue().long_long_value == lolo1);
            assert(i6_c.GetWidth() == wd1);
            assert(i6_c.GetLength() == 0);
            assert(i6_c.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i6_c.IsGood() == true);
            assert(i6_c.IsBad() == false);
            assert(i6_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7_c.IsSet() == true);
            assert(i7_c.GetValue().unsigned_char_value == uch1);
            assert(i7_c.GetWidth() == 0);
            assert(i7_c.GetLength() == ln1);
            assert(i7_c.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i7_c.IsGood() == true);
            assert(i7_c.IsBad() == false);
            assert(i7_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8_c.IsSet() == false);
            assert(i8_c.GetValue().unsigned_short_value == ush1);
            assert(i8_c.GetWidth() == 0);
            assert(i8_c.GetLength() == 0);
            assert(i8_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i8_c.IsGood() == true);
            assert(i8_c.IsBad() == false);
            assert(i8_c.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9_c.IsSet() == false);
            assert(i9_c.GetValue().unsigned_int_value == uin1);
            assert(i9_c.GetWidth() == 0);
            assert(i9_c.GetLength() == ln1);
            assert(i9_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i9_c.IsGood() == true);
            assert(i9_c.IsBad() == false);
            assert(i9_c.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10_c.IsSet() == false);
            assert(i10_c.GetValue().unsigned_long_value == ulo1);
            assert(i10_c.GetWidth() == wd1);
            assert(i10_c.GetLength() == 0);
            assert(i10_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i10_c.IsGood() == true);
            assert(i10_c.IsBad() == false);
            assert(i10_c.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11_c.IsSet() == true);
            assert(i11_c.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11_c.GetWidth() == wd1);
            assert(i11_c.GetLength() == ln1);
            assert(i11_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i11_c.IsGood() == true);
            assert(i11_c.IsBad() == false);
            assert(i11_c.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i1_c.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i2_c.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i3_c.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i4_c.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i5_c.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i6_c.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i7_c.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i8_c.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i9_c.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i10_c.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i11_c.GetValue().unsigned_long_long_value);

            auto len_b = i1_c.Output(out_cstr1_b);
            len_b += i2_c.Output(out_cstr1_b);
            len_b += i3_c.Output(out_cstr1_b);
            len_b += i4_c.Output(out_cstr1_b);
            len_b += i5_c.Output(out_cstr1_b);
            len_b += i6_c.Output(out_cstr1_b);
            len_b += i7_c.Output(out_cstr1_b);
            len_b += i8_c.Output(out_cstr1_b);
            len_b += i9_c.Output(out_cstr1_b);
            len_b += i10_c.Output(out_cstr1_b);
            len_b += i11_c.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i1_c.IsGood() == false);
                assert(i1_c.IsBad() == true);
                assert(i1_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i2_c.IsGood() == false);
                assert(i2_c.IsBad() == true);
                assert(i2_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i3_c.IsGood() == false);
                assert(i3_c.IsBad() == true);
                assert(i3_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i4_c.IsGood() == false);
                assert(i4_c.IsBad() == true);
                assert(i4_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i5_c.IsGood() == true);
                assert(i5_c.IsBad() == false);
                assert(i5_c.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i6_c.IsGood() == true);
                assert(i6_c.IsBad() == false);
                assert(i6_c.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i7_c.IsGood() == true);
                assert(i7_c.IsBad() == false);
                assert(i7_c.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i8_c.IsGood() == false);
                assert(i8_c.IsBad() == true);
                assert(i8_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i9_c.IsGood() == false);
                assert(i9_c.IsBad() == true);
                assert(i9_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i10_c.IsGood() == false);
                assert(i10_c.IsBad() == true);
                assert(i10_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i11_c.IsGood() == true);
                assert(i11_c.IsBad() == false);
                assert(i11_c.GetBadCode() == Integer<char>::StatusType::good);
            }
        }

        Integer<char> i34;
        Integer<char> i35;
        Integer<char> i36;
        Integer<char> i37;
        Integer<char> i38;
        Integer<char> i39;
        Integer<char> i40;
        Integer<char> i41;
        Integer<char> i42;
        Integer<char> i43;
        Integer<char> i44;

        i34 = i1;
        i35 = i2;
        i36 = i3;
        i37 = i4;
        i38 = i5;
        i39 = i6;
        i40 = i7;
        i41 = i8;
        i42 = i9;
        i43 = i10;
        i44 = i11;

        {
            assert(i34.IsSet() == true);
            assert(i34.GetValue().char_value == sch2);
            assert(i34.GetWidth() == 0);
            assert(i34.GetLength() == 0);
            assert(i34.IsGood() == true);
            assert(i34.IsBad() == false);
            assert(i34.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i35.IsSet() == true);
            assert(i35.GetValue().char_value == ch2);
            assert(i35.GetWidth() == wd1);
            assert(i35.GetLength() == 0);
            assert(i35.IsGood() == true);
            assert(i35.IsBad() == false);
            assert(i35.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i36.IsSet() == true);
            assert(i36.GetValue().short_value == sh2);
            assert(i36.GetWidth() == 0);
            assert(i36.GetLength() == ln1);
            assert(i36.IsGood() == true);
            assert(i36.IsBad() == false);
            assert(i36.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i37.IsSet() == true);
            assert(i37.GetValue().int_value == in2);
            assert(i37.GetWidth() == wd1);
            assert(i37.GetLength() == ln1);
            assert(i37.IsGood() == true);
            assert(i37.IsBad() == false);
            assert(i37.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i38.IsSet() == true);
            assert(i38.GetValue().long_value == lo1);
            assert(i38.GetWidth() == 0);
            assert(i38.GetLength() == 0);
            assert(i38.IsGood() == true);
            assert(i38.IsBad() == false);
            assert(i38.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i39.IsSet() == true);
            assert(i39.GetValue().long_long_value == lolo1);
            assert(i39.GetWidth() == wd1);
            assert(i39.GetLength() == 0);
            assert(i39.IsGood() == true);
            assert(i39.IsBad() == false);
            assert(i39.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i40.IsSet() == true);
            assert(i40.GetValue().unsigned_char_value == uch1);
            assert(i40.GetWidth() == 0);
            assert(i40.GetLength() == ln1);
            assert(i40.IsGood() == true);
            assert(i40.IsBad() == false);
            assert(i40.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i41.IsSet() == true);
            assert(i41.GetValue().unsigned_short_value == ush1);
            assert(i41.GetWidth() == wd2);
            assert(i41.GetLength() == ln2);
            assert(i41.IsGood() == true);
            assert(i41.IsBad() == false);
            assert(i41.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i42.IsSet() == true);
            assert(i42.GetValue().unsigned_int_value == uin1);
            assert(i42.GetWidth() == wd2);
            assert(i42.GetLength() == ln1);
            assert(i42.IsGood() == true);
            assert(i42.IsBad() == false);
            assert(i42.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i43.IsSet() == true);
            assert(i43.GetValue().unsigned_long_value == ulo1);
            assert(i43.GetWidth() == wd1);
            assert(i43.GetLength() == ln2);
            assert(i43.IsGood() == true);
            assert(i43.IsBad() == false);
            assert(i43.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i44.IsSet() == true);
            assert(i44.GetValue().unsigned_long_long_value == ulolo1);
            assert(i44.GetWidth() == wd1);
            assert(i44.GetLength() == ln1);
            assert(i44.IsGood() == true);
            assert(i44.IsBad() == false);
            assert(i44.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i34.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i35.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i36.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i37.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i38.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i39.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i40.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", wd2, ln2, 
                i41.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd2, ln1, 
                i42.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, ln2, 
                i43.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i44.GetValue().unsigned_long_long_value);

            auto len_b = i34.Output(out_cstr1_b);
            len_b += i35.Output(out_cstr1_b);
            len_b += i36.Output(out_cstr1_b);
            len_b += i37.Output(out_cstr1_b);
            len_b += i38.Output(out_cstr1_b);
            len_b += i39.Output(out_cstr1_b);
            len_b += i40.Output(out_cstr1_b);
            len_b += i41.Output(out_cstr1_b);
            len_b += i42.Output(out_cstr1_b);
            len_b += i43.Output(out_cstr1_b);
            len_b += i44.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i34.IsGood() == true);
                assert(i34.IsBad() == false);
                assert(i34.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i35.IsGood() == true);
                assert(i35.IsBad() == false);
                assert(i35.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i36.IsGood() == true);
                assert(i36.IsBad() == false);
                assert(i36.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i37.IsGood() == true);
                assert(i37.IsBad() == false);
                assert(i37.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i38.IsGood() == true);
                assert(i38.IsBad() == false);
                assert(i38.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i39.IsGood() == true);
                assert(i39.IsBad() == false);
                assert(i39.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i40.IsGood() == true);
                assert(i40.IsBad() == false);
                assert(i40.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i41.IsGood() == true);
                assert(i41.IsBad() == false);
                assert(i41.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i42.IsGood() == true);
                assert(i42.IsBad() == false);
                assert(i42.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i43.IsGood() == true);
                assert(i43.IsBad() == false);
                assert(i43.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i44.IsGood() == true);
                assert(i44.IsBad() == false);
                assert(i44.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            i34.Unset();
            assert(i34.IsSet() == false);
            assert(i34.GetValue().char_value == 0);
            assert(i34.GetWidth() == 0);
            assert(i34.GetLength() == 0);
            assert(i34.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i34.IsGood() == true);
            assert(i34.IsBad() == false);
            assert(i34.GetBadCode() == Integer<char>::StatusType::good);
            
            i35.Unset();
            assert(i35.IsSet() == false);
            assert(i35.GetValue().char_value == 0);
            assert(i35.GetWidth() == wd1);
            assert(i35.GetLength() == 0);
            assert(i35.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i35.IsGood() == true);
            assert(i35.IsBad() == false);
            assert(i35.GetBadCode() == Integer<char>::StatusType::good);
            
            i36.Unset();
            assert(i36.IsSet() == false);
            assert(i36.GetValue().short_value == 0);
            assert(i36.GetWidth() == 0);
            assert(i36.GetLength() == ln1);
            assert(i36.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i36.IsGood() == true);
            assert(i36.IsBad() == false);
            assert(i36.GetBadCode() == Integer<char>::StatusType::good);
            
            i37.Unset();
            assert(i37.IsSet() == false);
            assert(i37.GetValue().int_value == 0);
            assert(i37.GetWidth() == wd1);
            assert(i37.GetLength() == ln1);
            assert(i37.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i37.IsGood() == true);
            assert(i37.IsBad() == false);
            assert(i37.GetBadCode() == Integer<char>::StatusType::good);
            
            i38.Unset();
            assert(i38.IsSet() == true);
            assert(i38.GetValue().long_value == lo1);
            assert(i38.GetWidth() == 0);
            assert(i38.GetLength() == 0);
            assert(i38.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i38.IsGood() == true);
            assert(i38.IsBad() == false);
            assert(i38.GetBadCode() == Integer<char>::StatusType::good);
            
            i39.Unset();
            assert(i39.IsSet() == true);
            assert(i39.GetValue().long_long_value == lolo1);
            assert(i39.GetWidth() == wd1);
            assert(i39.GetLength() == 0);
            assert(i39.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i39.IsGood() == true);
            assert(i39.IsBad() == false);
            assert(i39.GetBadCode() == Integer<char>::StatusType::good);
            
            i40.Unset();
            assert(i40.IsSet() == true);
            assert(i40.GetValue().unsigned_char_value == uch1);
            assert(i40.GetWidth() == 0);
            assert(i40.GetLength() == ln1);
            assert(i40.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i40.IsGood() == true);
            assert(i40.IsBad() == false);
            assert(i40.GetBadCode() == Integer<char>::StatusType::good);
            
            i41.Unset();
            assert(i41.IsSet() == false);
            assert(i41.GetValue().unsigned_short_value == ush1);
            assert(i41.GetWidth() == 0);
            assert(i41.GetLength() == 0);
            assert(i41.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i41.IsGood() == true);
            assert(i41.IsBad() == false);
            assert(i41.GetBadCode() == Integer<char>::StatusType::good);

            i42.Unset();
            assert(i42.IsSet() == false);
            assert(i42.GetValue().unsigned_int_value == uin1);
            assert(i42.GetWidth() == 0);
            assert(i42.GetLength() == ln1);
            assert(i42.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i42.IsGood() == true);
            assert(i42.IsBad() == false);
            assert(i42.GetBadCode() == Integer<char>::StatusType::good);

            i43.Unset();
            assert(i43.IsSet() == false);
            assert(i43.GetValue().unsigned_long_value == ulo1);
            assert(i43.GetWidth() == wd1);
            assert(i43.GetLength() == 0);
            assert(i43.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i43.IsGood() == true);
            assert(i43.IsBad() == false);
            assert(i43.GetBadCode() == Integer<char>::StatusType::good);

            i44.Unset();
            assert(i44.IsSet() == true);
            assert(i44.GetValue().unsigned_long_long_value == ulolo1);
            assert(i44.GetWidth() == wd1);
            assert(i44.GetLength() == ln1);
            assert(i44.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i44.IsGood() == true);
            assert(i44.IsBad() == false);
            assert(i44.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i34.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i35.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i36.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i37.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i38.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i39.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i40.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i41.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i42.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i43.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i44.GetValue().unsigned_long_long_value);

            auto len_b = i34.Output(out_cstr1_b);
            len_b += i35.Output(out_cstr1_b);
            len_b += i36.Output(out_cstr1_b);
            len_b += i37.Output(out_cstr1_b);
            len_b += i38.Output(out_cstr1_b);
            len_b += i39.Output(out_cstr1_b);
            len_b += i40.Output(out_cstr1_b);
            len_b += i41.Output(out_cstr1_b);
            len_b += i42.Output(out_cstr1_b);
            len_b += i43.Output(out_cstr1_b);
            len_b += i44.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i34.IsGood() == false);
                assert(i34.IsBad() == true);
                assert(i34.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i35.IsGood() == false);
                assert(i35.IsBad() == true);
                assert(i35.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i36.IsGood() == false);
                assert(i36.IsBad() == true);
                assert(i36.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i37.IsGood() == false);
                assert(i37.IsBad() == true);
                assert(i37.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i38.IsGood() == true);
                assert(i38.IsBad() == false);
                assert(i38.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i39.IsGood() == true);
                assert(i39.IsBad() == false);
                assert(i39.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i40.IsGood() == true);
                assert(i40.IsBad() == false);
                assert(i40.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i41.IsGood() == false);
                assert(i41.IsBad() == true);
                assert(i41.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i42.IsGood() == false);
                assert(i42.IsBad() == true);
                assert(i42.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i43.IsGood() == false);
                assert(i43.IsBad() == true);
                assert(i43.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i44.IsGood() == true);
                assert(i44.IsBad() == false);
                assert(i44.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        i1_c.Reset();
        i2_c.Reset();
        i3_c.Reset();
        i4_c.Reset();
        i5_c.Reset();
        i6_c.Reset();
        i7_c.Reset();
        i8_c.Reset();
        i9_c.Reset();
        i10_c.Reset();
        i11_c.Reset();

        i1_c = i1;
        i2_c = i2;
        i3_c = i3;
        i4_c = i4;
        i5_c = i5;
        i6_c = i6;
        i7_c = i7;
        i8_c = i8;
        i9_c = i9;
        i10_c = i10;
        i11_c = i11;

        Integer<char> i45;
        Integer<char> i46;
        Integer<char> i47;
        Integer<char> i48;
        Integer<char> i49;
        Integer<char> i50;
        Integer<char> i51;
        Integer<char> i52;
        Integer<char> i53;
        Integer<char> i54;
        Integer<char> i55;

        i45 = std::move(i1_c);
        i46 = std::move(i2_c);
        i47 = std::move(i3_c);
        i48 = std::move(i4_c);
        i49 = std::move(i5_c);
        i50 = std::move(i6_c);
        i51 = std::move(i7_c);
        i52 = std::move(i8_c);
        i53 = std::move(i9_c);
        i54 = std::move(i10_c);
        i55 = std::move(i11_c);
        {
            assert(i45.IsSet() == true);
            assert(i45.GetValue().char_value == sch2);
            assert(i45.GetWidth() == 0);
            assert(i45.GetLength() == 0);
            assert(i45.IsGood() == true);
            assert(i45.IsBad() == false);
            assert(i45.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i46.IsSet() == true);
            assert(i46.GetValue().char_value == ch2);
            assert(i46.GetWidth() == wd1);
            assert(i46.GetLength() == 0);
            assert(i46.IsGood() == true);
            assert(i46.IsBad() == false);
            assert(i46.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i47.IsSet() == true);
            assert(i47.GetValue().short_value == sh2);
            assert(i47.GetWidth() == 0);
            assert(i47.GetLength() == ln1);
            assert(i47.IsGood() == true);
            assert(i47.IsBad() == false);
            assert(i47.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i48.IsSet() == true);
            assert(i48.GetValue().int_value == in2);
            assert(i48.GetWidth() == wd1);
            assert(i48.GetLength() == ln1);
            assert(i48.IsGood() == true);
            assert(i48.IsBad() == false);
            assert(i48.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i49.IsSet() == true);
            assert(i49.GetValue().long_value == lo1);
            assert(i49.GetWidth() == 0);
            assert(i49.GetLength() == 0);
            assert(i49.IsGood() == true);
            assert(i49.IsBad() == false);
            assert(i49.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i50.IsSet() == true);
            assert(i50.GetValue().long_long_value == lolo1);
            assert(i50.GetWidth() == wd1);
            assert(i50.GetLength() == 0);
            assert(i50.IsGood() == true);
            assert(i50.IsBad() == false);
            assert(i50.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i51.IsSet() == true);
            assert(i51.GetValue().unsigned_char_value == uch1);
            assert(i51.GetWidth() == 0);
            assert(i51.GetLength() == ln1);
            assert(i51.IsGood() == true);
            assert(i51.IsBad() == false);
            assert(i51.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i52.IsSet() == true);
            assert(i52.GetValue().unsigned_short_value == ush1);
            assert(i52.GetWidth() == wd2);
            assert(i52.GetLength() == ln2);
            assert(i52.IsGood() == true);
            assert(i52.IsBad() == false);
            assert(i52.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i53.IsSet() == true);
            assert(i53.GetValue().unsigned_int_value == uin1);
            assert(i53.GetWidth() == wd2);
            assert(i53.GetLength() == ln1);
            assert(i53.IsGood() == true);
            assert(i53.IsBad() == false);
            assert(i53.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i54.IsSet() == true);
            assert(i54.GetValue().unsigned_long_value == ulo1);
            assert(i54.GetWidth() == wd1);
            assert(i54.GetLength() == ln2);
            assert(i54.IsGood() == true);
            assert(i54.IsBad() == false);
            assert(i54.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i55.IsSet() == true);
            assert(i55.GetValue().unsigned_long_long_value == ulolo1);
            assert(i55.GetWidth() == wd1);
            assert(i55.GetLength() == ln1);
            assert(i55.IsGood() == true);
            assert(i55.IsBad() == false);
            assert(i55.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i45.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i46.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i47.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i48.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i49.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i50.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i51.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", wd2, ln2, 
                i52.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd2, ln1, 
                i53.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, ln2, 
                i54.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i55.GetValue().unsigned_long_long_value);

            auto len_b = i45.Output(out_cstr1_b);
            len_b += i46.Output(out_cstr1_b);
            len_b += i47.Output(out_cstr1_b);
            len_b += i48.Output(out_cstr1_b);
            len_b += i49.Output(out_cstr1_b);
            len_b += i50.Output(out_cstr1_b);
            len_b += i51.Output(out_cstr1_b);
            len_b += i52.Output(out_cstr1_b);
            len_b += i53.Output(out_cstr1_b);
            len_b += i54.Output(out_cstr1_b);
            len_b += i55.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i45.IsGood() == true);
                assert(i45.IsBad() == false);
                assert(i45.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i46.IsGood() == true);
                assert(i46.IsBad() == false);
                assert(i46.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i47.IsGood() == true);
                assert(i47.IsBad() == false);
                assert(i47.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i48.IsGood() == true);
                assert(i48.IsBad() == false);
                assert(i48.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i49.IsGood() == true);
                assert(i49.IsBad() == false);
                assert(i49.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i50.IsGood() == true);
                assert(i50.IsBad() == false);
                assert(i50.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i51.IsGood() == true);
                assert(i51.IsBad() == false);
                assert(i51.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i52.IsGood() == true);
                assert(i52.IsBad() == false);
                assert(i52.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i53.IsGood() == true);
                assert(i53.IsBad() == false);
                assert(i53.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i54.IsGood() == true);
                assert(i54.IsBad() == false);
                assert(i54.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i55.IsGood() == true);
                assert(i55.IsBad() == false);
                assert(i55.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            i45.Unset();
            assert(i45.IsSet() == false);
            assert(i45.GetValue().char_value == 0);
            assert(i45.GetWidth() == 0);
            assert(i45.GetLength() == 0);
            assert(i45.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i45.IsGood() == true);
            assert(i45.IsBad() == false);
            assert(i45.GetBadCode() == Integer<char>::StatusType::good);
            
            i46.Unset();
            assert(i46.IsSet() == false);
            assert(i46.GetValue().char_value == 0);
            assert(i46.GetWidth() == wd1);
            assert(i46.GetLength() == 0);
            assert(i46.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i46.IsGood() == true);
            assert(i46.IsBad() == false);
            assert(i46.GetBadCode() == Integer<char>::StatusType::good);
            
            i47.Unset();
            assert(i47.IsSet() == false);
            assert(i47.GetValue().short_value == 0);
            assert(i47.GetWidth() == 0);
            assert(i47.GetLength() == ln1);
            assert(i47.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i47.IsGood() == true);
            assert(i47.IsBad() == false);
            assert(i47.GetBadCode() == Integer<char>::StatusType::good);
            
            i48.Unset();
            assert(i48.IsSet() == false);
            assert(i48.GetValue().int_value == 0);
            assert(i48.GetWidth() == wd1);
            assert(i48.GetLength() == ln1);
            assert(i48.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i48.IsGood() == true);
            assert(i48.IsBad() == false);
            assert(i48.GetBadCode() == Integer<char>::StatusType::good);
            
            i49.Unset();
            assert(i49.IsSet() == true);
            assert(i49.GetValue().long_value == lo1);
            assert(i49.GetWidth() == 0);
            assert(i49.GetLength() == 0);
            assert(i49.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i49.IsGood() == true);
            assert(i49.IsBad() == false);
            assert(i49.GetBadCode() == Integer<char>::StatusType::good);
            
            i50.Unset();
            assert(i50.IsSet() == true);
            assert(i50.GetValue().long_long_value == lolo1);
            assert(i50.GetWidth() == wd1);
            assert(i50.GetLength() == 0);
            assert(i50.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i50.IsGood() == true);
            assert(i50.IsBad() == false);
            assert(i50.GetBadCode() == Integer<char>::StatusType::good);
            
            i51.Unset();
            assert(i51.IsSet() == true);
            assert(i51.GetValue().unsigned_char_value == uch1);
            assert(i51.GetWidth() == 0);
            assert(i51.GetLength() == ln1);
            assert(i51.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i51.IsGood() == true);
            assert(i51.IsBad() == false);
            assert(i51.GetBadCode() == Integer<char>::StatusType::good);
            
            i52.Unset();
            assert(i52.IsSet() == false);
            assert(i52.GetValue().unsigned_short_value == ush1);
            assert(i52.GetWidth() == 0);
            assert(i52.GetLength() == 0);
            assert(i52.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i52.IsGood() == true);
            assert(i52.IsBad() == false);
            assert(i52.GetBadCode() == Integer<char>::StatusType::good);

            i53.Unset();
            assert(i53.IsSet() == false);
            assert(i53.GetValue().unsigned_int_value == uin1);
            assert(i53.GetWidth() == 0);
            assert(i53.GetLength() == ln1);
            assert(i53.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i53.IsGood() == true);
            assert(i53.IsBad() == false);
            assert(i53.GetBadCode() == Integer<char>::StatusType::good);

            i54.Unset();
            assert(i54.IsSet() == false);
            assert(i54.GetValue().unsigned_long_value == ulo1);
            assert(i54.GetWidth() == wd1);
            assert(i54.GetLength() == 0);
            assert(i54.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i54.IsGood() == true);
            assert(i54.IsBad() == false);
            assert(i54.GetBadCode() == Integer<char>::StatusType::good);

            i55.Unset();
            assert(i55.IsSet() == true);
            assert(i55.GetValue().unsigned_long_long_value == ulolo1);
            assert(i55.GetWidth() == wd1);
            assert(i55.GetLength() == ln1);
            assert(i55.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i55.IsGood() == true);
            assert(i55.IsBad() == false);
            assert(i55.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i45.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i46.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i47.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i48.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i49.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i50.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i51.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i52.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i53.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i54.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i55.GetValue().unsigned_long_long_value);

            auto len_b = i45.Output(out_cstr1_b);
            len_b += i46.Output(out_cstr1_b);
            len_b += i47.Output(out_cstr1_b);
            len_b += i48.Output(out_cstr1_b);
            len_b += i49.Output(out_cstr1_b);
            len_b += i50.Output(out_cstr1_b);
            len_b += i51.Output(out_cstr1_b);
            len_b += i52.Output(out_cstr1_b);
            len_b += i53.Output(out_cstr1_b);
            len_b += i54.Output(out_cstr1_b);
            len_b += i55.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i45.IsGood() == false);
                assert(i45.IsBad() == true);
                assert(i45.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i46.IsGood() == false);
                assert(i46.IsBad() == true);
                assert(i46.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i47.IsGood() == false);
                assert(i47.IsBad() == true);
                assert(i47.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i48.IsGood() == false);
                assert(i48.IsBad() == true);
                assert(i48.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i49.IsGood() == true);
                assert(i49.IsBad() == false);
                assert(i49.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i50.IsGood() == true);
                assert(i50.IsBad() == false);
                assert(i50.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i51.IsGood() == true);
                assert(i51.IsBad() == false);
                assert(i51.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i52.IsGood() == false);
                assert(i52.IsBad() == true);
                assert(i52.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i53.IsGood() == false);
                assert(i53.IsBad() == true);
                assert(i53.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i54.IsGood() == false);
                assert(i54.IsBad() == true);
                assert(i54.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i55.IsGood() == true);
                assert(i55.IsBad() == false);
                assert(i55.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
        {
            assert(i1_c.IsSet() == false);
            assert(i1_c.GetValue().char_value == 0);
            assert(i1_c.GetWidth() == 0);
            assert(i1_c.GetLength() == 0);
            assert(i1_c.GetFlag() == flag::Integer::p__uhu_char_format);
            assert(i1_c.IsGood() == true);
            assert(i1_c.IsBad() == false);
            assert(i1_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i2_c.IsSet() == false);
            assert(i2_c.GetValue().char_value == 0);
            assert(i2_c.GetWidth() == wd1);
            assert(i2_c.GetLength() == 0);
            assert(i2_c.GetFlag() == flag::Integer::p_w_uhu_char_format);
            assert(i2_c.IsGood() == true);
            assert(i2_c.IsBad() == false);
            assert(i2_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i3_c.IsSet() == false);
            assert(i3_c.GetValue().short_value == 0);
            assert(i3_c.GetWidth() == 0);
            assert(i3_c.GetLength() == ln1);
            assert(i3_c.GetFlag() == flag::Integer::p_l_uhu_short_format);
            assert(i3_c.IsGood() == true);
            assert(i3_c.IsBad() == false);
            assert(i3_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i4_c.IsSet() == false);
            assert(i4_c.GetValue().int_value == 0);
            assert(i4_c.GetWidth() == wd1);
            assert(i4_c.GetLength() == ln1);
            assert(i4_c.GetFlag() == flag::Integer::p_wl_uhu_int_format);
            assert(i4_c.IsGood() == true);
            assert(i4_c.IsBad() == false);
            assert(i4_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i5_c.IsSet() == true);
            assert(i5_c.GetValue().long_value == lo1);
            assert(i5_c.GetWidth() == 0);
            assert(i5_c.GetLength() == 0);
            assert(i5_c.GetFlag() == flag::Integer::p__uhu_long_format);
            assert(i5_c.IsGood() == true);
            assert(i5_c.IsBad() == false);
            assert(i5_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i6_c.IsSet() == true);
            assert(i6_c.GetValue().long_long_value == lolo1);
            assert(i6_c.GetWidth() == wd1);
            assert(i6_c.GetLength() == 0);
            assert(i6_c.GetFlag() == flag::Integer::p_w_uhu_long_long_format);
            assert(i6_c.IsGood() == true);
            assert(i6_c.IsBad() == false);
            assert(i6_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i7_c.IsSet() == true);
            assert(i7_c.GetValue().unsigned_char_value == uch1);
            assert(i7_c.GetWidth() == 0);
            assert(i7_c.GetLength() == ln1);
            assert(i7_c.GetFlag() == 
                flag::Integer::p_l_uhu_unsigned_char_format);
            assert(i7_c.IsGood() == true);
            assert(i7_c.IsBad() == false);
            assert(i7_c.GetBadCode() == Integer<char>::StatusType::good);
            
            assert(i8_c.IsSet() == false);
            assert(i8_c.GetValue().unsigned_short_value == ush1);
            assert(i8_c.GetWidth() == 0);
            assert(i8_c.GetLength() == 0);
            assert(i8_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_short_format);
            assert(i8_c.IsGood() == true);
            assert(i8_c.IsBad() == false);
            assert(i8_c.GetBadCode() == Integer<char>::StatusType::good);

            assert(i9_c.IsSet() == false);
            assert(i9_c.GetValue().unsigned_int_value == uin1);
            assert(i9_c.GetWidth() == 0);
            assert(i9_c.GetLength() == ln1);
            assert(i9_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_int_format);
            assert(i9_c.IsGood() == true);
            assert(i9_c.IsBad() == false);
            assert(i9_c.GetBadCode() == Integer<char>::StatusType::good);

            assert(i10_c.IsSet() == false);
            assert(i10_c.GetValue().unsigned_long_value == ulo1);
            assert(i10_c.GetWidth() == wd1);
            assert(i10_c.GetLength() == 0);
            assert(i10_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_format);
            assert(i10_c.IsGood() == true);
            assert(i10_c.IsBad() == false);
            assert(i10_c.GetBadCode() == Integer<char>::StatusType::good);

            assert(i11_c.IsSet() == true);
            assert(i11_c.GetValue().unsigned_long_long_value == ulolo1);
            assert(i11_c.GetWidth() == wd1);
            assert(i11_c.GetLength() == ln1);
            assert(i11_c.GetFlag() == 
                flag::Integer::p_wl_uhu_unsigned_long_long_format);
            assert(i11_c.IsGood() == true);
            assert(i11_c.IsBad() == false);
            assert(i11_c.GetBadCode() == Integer<char>::StatusType::good);
        }
        {
            test::out::CString<char> out_cstr1_a, out_cstr1_b;
            auto len_a = out_cstr1_a.Print("%#hhX",
                i1_c.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*hhX", wd1, 
                i2_c.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#.*hX", ln1, 
                i3_c.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", wd1, ln1, 
                i4_c.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#lX", 
                i5_c.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*llX", wd1, 
                i6_c.GetValue().unsigned_long_long_value);
            len_a += out_cstr1_a.Print("%#.*hhX", ln1, 
                i7_c.GetValue().unsigned_char_value);
            len_a += out_cstr1_a.Print("%#*.*hX", 0, 0, 
                i8_c.GetValue().unsigned_short_value);
            len_a += out_cstr1_a.Print("%#*.*X", 0, ln1, 
                i9_c.GetValue().unsigned_int_value);
            len_a += out_cstr1_a.Print("%#*.*lX", wd1, 0, 
                i10_c.GetValue().unsigned_long_value);
            len_a += out_cstr1_a.Print("%#*.*llX", wd1, ln1, 
                i11_c.GetValue().unsigned_long_long_value);

            auto len_b = i1_c.Output(out_cstr1_b);
            len_b += i2_c.Output(out_cstr1_b);
            len_b += i3_c.Output(out_cstr1_b);
            len_b += i4_c.Output(out_cstr1_b);
            len_b += i5_c.Output(out_cstr1_b);
            len_b += i6_c.Output(out_cstr1_b);
            len_b += i7_c.Output(out_cstr1_b);
            len_b += i8_c.Output(out_cstr1_b);
            len_b += i9_c.Output(out_cstr1_b);
            len_b += i10_c.Output(out_cstr1_b);
            len_b += i11_c.Output(out_cstr1_b);

            assert(len_a == len_b);
            assert(out_cstr1_a.Size() == out_cstr1_b.Size());
            assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
                out_cstr1_b.Size()) == 0);
            {
                assert(i1_c.IsGood() == false);
                assert(i1_c.IsBad() == true);
                assert(i1_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i2_c.IsGood() == false);
                assert(i2_c.IsBad() == true);
                assert(i2_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i3_c.IsGood() == false);
                assert(i3_c.IsBad() == true);
                assert(i3_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i4_c.IsGood() == false);
                assert(i4_c.IsBad() == true);
                assert(i4_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i5_c.IsGood() == true);
                assert(i5_c.IsBad() == false);
                assert(i5_c.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i6_c.IsGood() == true);
                assert(i6_c.IsBad() == false);
                assert(i6_c.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i7_c.IsGood() == true);
                assert(i7_c.IsBad() == false);
                assert(i7_c.GetBadCode() == Integer<char>::StatusType::good);
            
                assert(i8_c.IsGood() == false);
                assert(i8_c.IsBad() == true);
                assert(i8_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i9_c.IsGood() == false);
                assert(i9_c.IsBad() == true);
                assert(i9_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i10_c.IsGood() == false);
                assert(i10_c.IsBad() == true);
                assert(i10_c.GetBadCode() == 
                    Integer<char>::StatusType::value_not_set);
            
                assert(i11_c.IsGood() == true);
                assert(i11_c.IsBad() == false);
                assert(i11_c.GetBadCode() == Integer<char>::StatusType::good);
            }
        }
    }


    return 0;
    
}
