#include "test/msg/fmt/val/specifier/Pointer.h"
#include "test/out/CString.h"

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
    int in1 = 4;
    float fl1 = 3.14;
    char ch1 = 'L';
    void *vo1 = (void*)&in1, *vo2 = (void*)&fl1, *vo3 = (void*)&ch1;
    const int wd1 = 10, wd2 = 14, wd3 = -10;
    {
        Pointer<char> po1;
        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(po1.IsSet() == false);
        assert(po1.GetValue() == nullptr);
        assert(po1.GetWidth() == 0);
        assert(po1.GetFlag() == flag::Pointer::pointer_format);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%p", nullptr);
        auto len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == false);
        assert(po1.IsBad() == true);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        auto len = po1.Load(1, vo1);
        assert(len == 1);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        po1.Reset();
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = po1.Load(1, vo2);
        assert(len == 1);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo2);
        assert(po1.GetWidth() == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = Load(po1, 1, vo3);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo2);
        assert(po1.GetWidth() == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo2);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        Pointer<char> po2{po1};
        
        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo2);
        assert(po2.GetWidth() == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo2);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);

        Pointer<char> po3{std::move(po2)};
        
        assert(po3.IsSet() == true);
        assert(po3.GetValue() == vo2);
        assert(po3.GetWidth() == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);
        assert(po3.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo2);
        len_b = po3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);

        assert(po2.IsSet() == false);
        assert(po2.GetValue() == nullptr);
        assert(po2.GetWidth() == 0);
        assert(po2.GetFlag() == flag::Pointer::pointer_format);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%p", nullptr);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == false);
        assert(po2.IsBad() == true);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        Pointer<char> po4;
        po4 = po3;

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo2);
        assert(po4.GetWidth() == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo2);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);

        Pointer<char> po5;
        po5 = std::move(po4);
        
        assert(po5.IsSet() == true);
        assert(po5.GetValue() == vo2);
        assert(po5.GetWidth() == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);
        assert(po5.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo2);
        len_b = po5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);

        assert(po4.IsSet() == false);
        assert(po4.GetValue() == nullptr);
        assert(po4.GetWidth() == 0);
        assert(po4.GetFlag() == flag::Pointer::pointer_format);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%p", nullptr);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == false);
        assert(po4.IsBad() == true);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::value_not_set);
    }
    {
        Pointer<char> po1{arg::Width{}};
        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(po1.IsSet() == false);
        assert(po1.GetValue() == nullptr);
        assert(po1.GetWidth() == 0);
        assert(po1.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*p", 0, nullptr);
        auto len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == false);
        assert(po1.IsBad() == true);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        auto len = po1.Load(2, wd1, vo1);
        assert(len == 2);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        po1.Reset();
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = po1.Load(2, wd2, vo2);
        assert(len == 2);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo2);
        assert(po1.GetWidth() == wd2);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = Load(po1, 2, wd3, vo3);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo2);
        assert(po1.GetWidth() == wd2);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo2);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        Pointer<char> po2{po1};
        
        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo2);
        assert(po2.GetWidth() == wd2);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo2);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);

        Pointer<char> po3{std::move(po2)};
        
        assert(po3.IsSet() == true);
        assert(po3.GetValue() == vo2);
        assert(po3.GetWidth() == wd2);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);
        assert(po3.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo2);
        len_b = po3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);

        assert(po2.IsSet() == false);
        assert(po2.GetValue() == nullptr);
        assert(po2.GetWidth() == 0);
        assert(po2.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", 0, nullptr);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == false);
        assert(po2.IsBad() == true);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        Pointer<char> po4;
        po4 = po3;

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo2);
        assert(po4.GetWidth() == wd2);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo2);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);

        Pointer<char> po5;
        po5 = std::move(po4);
        
        assert(po5.IsSet() == true);
        assert(po5.GetValue() == vo2);
        assert(po5.GetWidth() == wd2);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);
        assert(po5.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo2);
        len_b = po5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);

        assert(po4.IsSet() == false);
        assert(po4.GetValue() == nullptr);
        assert(po4.GetWidth() == 0);
        assert(po4.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", 0, nullptr);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == false);
        assert(po4.IsBad() == true);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::value_not_set);
    }
    {
        Pointer<char> po1{arg::Width{wd1}};
        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(po1.IsSet() == false);
        assert(po1.GetValue() == nullptr);
        assert(po1.GetWidth() == wd1);
        assert(po1.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*p", wd1, nullptr);
        auto len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == false);
        assert(po1.IsBad() == true);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        auto len = po1.Load(1, vo1);
        assert(len == 1);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        po1.Reset();
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = po1.Load(1, vo2);
        assert(len == 1);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo2);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = Load(po1, 1, vo3);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo2);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo2);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        Pointer<char> po2{po1};
        
        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo2);
        assert(po2.GetWidth() == wd1);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo2);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);

        Pointer<char> po3{std::move(po2)};
        
        assert(po3.IsSet() == true);
        assert(po3.GetValue() == vo2);
        assert(po3.GetWidth() == wd1);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);
        assert(po3.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo2);
        len_b = po3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);

        assert(po2.IsSet() == false);
        assert(po2.GetValue() == nullptr);
        assert(po2.GetWidth() == wd1);
        assert(po2.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", wd1, nullptr);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == false);
        assert(po2.IsBad() == true);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        Pointer<char> po4;
        po4 = po3;

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo2);
        assert(po4.GetWidth() == wd1);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo2);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);

        Pointer<char> po5;
        po5 = std::move(po4);
        
        assert(po5.IsSet() == true);
        assert(po5.GetValue() == vo2);
        assert(po5.GetWidth() == wd1);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);
        assert(po5.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo2);
        len_b = po5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);

        assert(po4.IsSet() == false);
        assert(po4.GetValue() == nullptr);
        assert(po4.GetWidth() == wd1);
        assert(po4.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", wd1, nullptr);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == false);
        assert(po4.IsBad() == true);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::value_not_set);
    }
    ///
    {
        Pointer<char> po1{vo1};
        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == 0);
        assert(po1.GetFlag() == flag::Pointer::pointer_format);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%p", vo1);
        auto len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        auto len = po1.Load(1, vo1);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        po1.Reset();
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = po1.Load(1, vo2);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = Load(po1, 1, vo3);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        Pointer<char> po2{po1};
        
        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo1);
        assert(po2.GetWidth() == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);

        Pointer<char> po3{std::move(po2)};
        
        assert(po3.IsSet() == true);
        assert(po3.GetValue() == vo1);
        assert(po3.GetWidth() == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);
        assert(po3.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);

        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo1);
        assert(po2.GetWidth() == 0);
        assert(po2.GetFlag() == flag::Pointer::pointer_format);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        Pointer<char> po4;
        po4 = po3;

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo1);
        assert(po4.GetWidth() == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);

        Pointer<char> po5;
        po5 = std::move(po4);
        
        assert(po5.IsSet() == true);
        assert(po5.GetValue() == vo1);
        assert(po5.GetWidth() == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);
        assert(po5.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo1);
        assert(po4.GetWidth() == 0);
        assert(po4.GetFlag() == flag::Pointer::pointer_format);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%p", vo1);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
    }
    {
        Pointer<char> po1{vo1, arg::Width{}};
        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(po1.IsSet() == false);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == 0);
        assert(po1.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*p", 0, vo1);
        auto len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == false);
        assert(po1.IsBad() == true);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        auto len = po1.Load(1, wd1, vo1);
        assert(len == 1);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        po1.Reset();
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = po1.Load(1, wd2, vo2);
        assert(len == 1);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd2);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = Load(po1, 2, wd3, vo3);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd2);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        Pointer<char> po2{po1};
        
        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo1);
        assert(po2.GetWidth() == wd2);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo1);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);

        Pointer<char> po3{std::move(po2)};
        
        assert(po3.IsSet() == true);
        assert(po3.GetValue() == vo1);
        assert(po3.GetWidth() == wd2);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);
        assert(po3.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo1);
        len_b = po3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);

        assert(po2.IsSet() == false);
        assert(po2.GetValue() == vo1);
        assert(po2.GetWidth() == 0);
        assert(po2.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", 0, vo1);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == false);
        assert(po2.IsBad() == true);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::value_not_set);

        Pointer<char> po4;
        po4 = po3;

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo1);
        assert(po4.GetWidth() == wd2);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo1);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);

        Pointer<char> po5;
        po5 = std::move(po4);
        
        assert(po5.IsSet() == true);
        assert(po5.GetValue() == vo1);
        assert(po5.GetWidth() == wd2);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);
        assert(po5.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd2, vo1);
        len_b = po5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);

        assert(po4.IsSet() == false);
        assert(po4.GetValue() == vo1);
        assert(po4.GetWidth() == 0);
        assert(po4.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", 0, vo1);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == false);
        assert(po4.IsBad() == true);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::value_not_set);
    }
    {
        Pointer<char> po1{vo1, arg::Width{wd1}};
        test::out::CString<char> out_cstr1_a, out_cstr1_b;

        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);
        
        auto len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        auto len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        auto len = po1.Load(1, vo1);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        po1.Reset();
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = po1.Load(1, vo2);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len = Load(po1, 1, vo3);
        assert(len == 0);
        assert(po1.IsSet() == true);
        assert(po1.GetValue() == vo1);
        assert(po1.GetWidth() == wd1);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);
        assert(po1.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po1.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po1.IsGood() == true);
        assert(po1.IsBad() == false);

        Pointer<char> po2{po1};
        
        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo1);
        assert(po2.GetWidth() == wd1);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);

        Pointer<char> po3{std::move(po2)};
        
        assert(po3.IsSet() == true);
        assert(po3.GetValue() == vo1);
        assert(po3.GetWidth() == wd1);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);
        assert(po3.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po3.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po3.IsGood() == true);
        assert(po3.IsBad() == false);

        assert(po2.IsSet() == true);
        assert(po2.GetValue() == vo1);
        assert(po2.GetWidth() == wd1);
        assert(po2.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po2.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po2.IsGood() == true);
        assert(po2.IsBad() == false);
        assert(po2.GetBadCode() == Pointer<char>::StatusType::good);

        Pointer<char> po4;
        po4 = po3;

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo1);
        assert(po4.GetWidth() == wd1);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);

        Pointer<char> po5;
        po5 = std::move(po4);
        
        assert(po5.IsSet() == true);
        assert(po5.GetValue() == vo1);
        assert(po5.GetWidth() == wd1);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);
        assert(po5.GetBadCode() == Pointer<char>::StatusType::good);

        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po5.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po5.IsGood() == true);
        assert(po5.IsBad() == false);

        assert(po4.IsSet() == true);
        assert(po4.GetValue() == vo1);
        assert(po4.GetWidth() == wd1);
        assert(po4.GetFlag() == flag::Pointer::w_pointer_format);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
        
        len_a = out_cstr1_a.Print("%*p", wd1, vo1);
        len_b = po4.Output(out_cstr1_b);
        assert(len_a == len_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        assert(po4.IsGood() == true);
        assert(po4.IsBad() == false);
        assert(po4.GetBadCode() == Pointer<char>::StatusType::good);
    }
    return 0;
}
