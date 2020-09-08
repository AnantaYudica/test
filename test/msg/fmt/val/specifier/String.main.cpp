#include "test/msg/fmt/val/specifier/String.h"
#include "test/out/CSstring.h"

#include <cassert>

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
    
    const char * cstr1 = "test1234567890"; 
    const char * cstr2 = "1234test567890"; 
    const char * cstr3 = "12345678test90"; 
    const wchar_t * wcstr1 = L"1234567890test"; 
    const wchar_t * wcstr2 = L"123456test7890"; 
    const wchar_t * wcstr3 = L"12test34567890"; 
    
    const int wd1 = 10, wd2 = 14, wd3 = -10;
    const int ln1 = 4, ln2 = 9, ln3 = 15;
    {
        String<char> st1;

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%s", nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{arg::Width{wd1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", wd1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Length{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{arg::Length{ln1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);

    }
    {
        String<char> st1{arg::Width{}, arg::Length{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(3, wd1, ln1, cstr1);
        assert(len == 3);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 3, wd2, ln2, cstr2);
        assert(len == 3);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(3, wd3, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{wd1}, arg::Length{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{}, arg::Length{ln1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{wd1}, arg::Length{ln1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%s", cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    {
        String<char> st1{cstr1, arg::Width{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{cstr1, arg::Width{wd1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    {
        String<char> st1{cstr1, arg::Length{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Length{ln1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

    }
    {
        String<char> st1{cstr1, arg::Width{}, arg::Length{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(3, wd1, ln1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 3, wd2, ln2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(3, wd3, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Width{wd1}, arg::Length{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Width{}, arg::Length{ln1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, ln1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Width{wd1}, arg::Length{ln1}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    ///
    {
        String<char> st1{arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%s", nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{arg::Width{wd1}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", wd1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Length{}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{arg::Length{ln1}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);

    }
    {
        String<char> st1{arg::Width{}, arg::Length{}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(3, wd1, ln1, cstr1);
        assert(len == 3);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 3, wd2, ln2, cstr2);
        assert(len == 3);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(3, wd3, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{wd1}, arg::Length{}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{}, arg::Length{ln1}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{wd1}, arg::Length{ln1}, 
            arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%s", cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%s", cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    {
        String<char> st1{cstr1, arg::Width{}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{cstr1, arg::Width{wd1}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*s", wd1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    {
        String<char> st1{cstr1, arg::Length{}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Length{ln1}, arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::l_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*s", ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

    }
    {
        String<char> st1{cstr1, arg::Width{}, arg::Length{}, 
            arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(3, wd1, ln1, cstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 3, wd2, ln2, cstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(3, wd3, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Width{wd1}, arg::Length{}, 
            arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, 0, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln2, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, 0, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Width{}, arg::Length{ln1}, 
            arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", 0, ln1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, cstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, cstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd2, ln1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", 0, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{cstr1, arg::Width{wd1}, arg::Length{ln1}, 
            arg::Define<char>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_char_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, cstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, cstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, cstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().char_ptr_value == cstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().char_ptr_value == cstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().char_ptr_value == cstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().char_ptr_value == cstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().char_ptr_value == cstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*s", wd1, ln1, cstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    
    ///
    {
        String<char> st1{arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%ls", nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*ls", 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, wcstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, wcstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{arg::Width{wd1}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*ls", wd1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Length{}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::l_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*ls", 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, wcstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, wcstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{arg::Length{ln1}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::l_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*ls", ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);

    }
    {
        String<char> st1{arg::Width{}, arg::Length{}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", 0, 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(3, wd1, ln1, wcstr1);
        assert(len == 3);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 3, wd2, ln2, wcstr2);
        assert(len == 3);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(3, wd3, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{wd1}, arg::Length{}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", wd1, 0, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, wcstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, wcstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, 0, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, 0, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{}, arg::Length{ln1}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", 0, ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, wcstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, wcstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{arg::Width{wd1}, arg::Length{ln1}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, nullptr);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().char_ptr_value == nullptr);
        assert(st1.GetValue().wchar_ptr_value == nullptr);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr2);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr2);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr2);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr2);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr2);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr2);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().char_ptr_value == nullptr);
        assert(st2.GetValue().wchar_ptr_value == nullptr);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, nullptr);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr2);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr2);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr2);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr2);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().char_ptr_value == nullptr);
        assert(st4.GetValue().wchar_ptr_value == nullptr);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, nullptr);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{wcstr1, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%ls", wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, wcstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%ls", wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    {
        String<char> st1{wcstr1, arg::Width{}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*ls", 0, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", 0, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd2, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", 0, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    
    {
        String<char> st1{wcstr1, arg::Width{wd1}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::w_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, wcstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*ls", wd1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    {
        String<char> st1{wcstr1, arg::Length{}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::l_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*ls", 0, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", 0, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln2, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", 0, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{wcstr1, arg::Length{ln1}, arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::l_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, wcstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == 0);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == 0);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%.*ls", ln1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

    }
    {
        String<char> st1{wcstr1, arg::Width{}, arg::Length{}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", 0, 0, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(3, wd1, ln1, wcstr1);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 3, wd2, ln2, wcstr2);
        assert(len == 2);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(3, wd3, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, 0, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln2, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, 0, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{wcstr1, arg::Width{wd1}, arg::Length{}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", wd1, 0, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, ln1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, ln2, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, ln3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln2);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln2);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln2);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, 0, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln2);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln2);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln2, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, 0, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{wcstr1, arg::Width{}, arg::Length{ln1}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", 0, ln1, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == false);
        assert(st1.IsBad() == true);
        assert(st1.GetBadCode() == String<char>::StatusType::value_not_set);

        auto len = st1.Load(2, wd1, wcstr1);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == false);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == 0);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 2, wd2, wcstr2);
        assert(len == 1);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(2, wd3, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd2);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd2);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == wd2);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == false);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == 0);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, ln1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == false);
        assert(st2.IsBad() == true);
        assert(st2.GetBadCode() == String<char>::StatusType::value_not_set);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd2);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == wd2);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd2, ln1, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == false);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == 0);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", 0, ln1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == false);
        assert(st4.IsBad() == true);
        assert(st4.GetBadCode() == String<char>::StatusType::value_not_set);
    }
    {
        String<char> st1{wcstr1, arg::Width{wd1}, arg::Length{ln1}, 
            arg::Define<wchar_t>{}};

        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.GetFlag() == flag::String::wl_wchar_format);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        auto len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        auto len = st1.Load(1, wcstr1);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);
        
        st1.Reset();
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = Load(st1, 1, wcstr2);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len = st1.Load(1, wcstr3);
        assert(len == 0);
        assert(st1.IsSet() == true);
        assert(st1.GetValue().wchar_ptr_value == wcstr1);
        assert(st1.GetWidth() == wd1);
        assert(st1.GetLength() == ln1);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st1.IsGood() == true);
        assert(st1.IsBad() == false);
        assert(st1.GetBadCode() == String<char>::StatusType::good);

        String<char> st2{st1};
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st3{std::move(st2)};
        
        assert(st3.IsSet() == true);
        assert(st3.GetValue().wchar_ptr_value == wcstr1);
        assert(st3.GetWidth() == wd1);
        assert(st3.GetLength() == ln1);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st3.IsGood() == true);
        assert(st3.IsBad() == false);
        assert(st3.GetBadCode() == String<char>::StatusType::good);
        
        assert(st2.IsSet() == true);
        assert(st2.GetValue().wchar_ptr_value == wcstr1);
        assert(st2.GetWidth() == wd1);
        assert(st2.GetLength() == ln1);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st2.IsGood() == true);
        assert(st2.IsBad() == false);
        assert(st2.GetBadCode() == String<char>::StatusType::good);

        String<char> st4;
        st4 = st3;
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
        
        String<char> st5;
        st5 = std::move(st4);
        
        assert(st5.IsSet() == true);
        assert(st5.GetValue().wchar_ptr_value == wcstr1);
        assert(st5.GetWidth() == wd1);
        assert(st5.GetLength() == ln1);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st5.IsGood() == true);
        assert(st5.IsBad() == false);
        assert(st5.GetBadCode() == String<char>::StatusType::good);
        
        assert(st4.IsSet() == true);
        assert(st4.GetValue().wchar_ptr_value == wcstr1);
        assert(st4.GetWidth() == wd1);
        assert(st4.GetLength() == ln1);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*.*ls", wd1, ln1, wcstr1);
        len_b = st4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(st4.IsGood() == true);
        assert(st4.IsBad() == false);
        assert(st4.GetBadCode() == String<char>::StatusType::good);
    }
    return 0;
}