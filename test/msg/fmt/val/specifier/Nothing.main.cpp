#include "test/msg/fmt/val/specifier/Nothing.h"
#include "test/out/CString.h"

#include <cstdarg>
#include <cassert>
#include <utility>

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
        Nothing<char> nt1{};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == flag::Nothing::define_int);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_int);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_int);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == flag::Nothing::define_int);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_int);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_int);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == flag::Nothing::define_int);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Width(1)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Precision(1)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 3);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 3);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const char ch1 = 'A';
    {
        Nothing<char> nt1{ch1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_char);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_char);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_char);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_char);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_char);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_char);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_char);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ch1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{ch1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const signed char sch1 = 1;
    {
        Nothing<char> nt1{sch1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_char);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_char);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_char);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_char);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_char);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_char);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_char);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sch1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{sch1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const short sh1 = 1;
    {
        Nothing<char> nt1{sh1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_short);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_short);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_short);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_short);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_short);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_short);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_short);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{sh1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{sh1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const int in1 = 1;
    {
        Nothing<char> nt1{in1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_int);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_int);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_int);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_int);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_int);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_int);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_int);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{in1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{in1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const long lo1 = 1;
    {
        Nothing<char> nt1{lo1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_long);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_long);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_long);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lo1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{lo1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const long long lolo1 = 1;
    {
        Nothing<char> nt1{lolo1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_long_long);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_long_long);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_long_long);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lolo1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{lolo1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const unsigned char uch1 = 1;
    {
        Nothing<char> nt1{uch1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_char);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_char);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_char);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_char);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_char);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_char);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_char);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uch1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{uch1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_char | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const unsigned short ush1 = 1;
    {
        Nothing<char> nt1{ush1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_short);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_short);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_short);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_short);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_short);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_short);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_short);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ush1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{ush1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_short | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const unsigned int uin1 = 1;
    {
        Nothing<char> nt1{uin1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_int);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_int);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_int);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_int);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_int);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_int);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_int);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{uin1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{uin1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_int | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const unsigned long ulo1 = 1;
    {
        Nothing<char> nt1{ulo1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_long);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_long);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_long);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulo1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{ulo1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const unsigned long long ulolo1 = 1;
    {
        Nothing<char> nt1{ulolo1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_long_long);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_long_long);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long_long);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_long_long);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long_long);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{ulolo1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{ulolo1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_long | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const float fl1 = 1;
    {
        Nothing<char> nt1{fl1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_double);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_double);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_double);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_double);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_double);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_double);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_double);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{fl1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{fl1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const double do1 = 1;
    {
        Nothing<char> nt1{do1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_double);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_double);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_double);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_double);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_double);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_double);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_double);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{do1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{do1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const long double lodo1 = 1;
    {
        Nothing<char> nt1{lodo1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_long_double);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long_double);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_long_double);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_long_double);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long_double);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_long_double);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_long_double);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{lodo1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{lodo1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_long_double | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const void* vo1 = (void*)&in1;
    {
        Nothing<char> nt1{vo1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_pointer);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_pointer);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_pointer);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_pointer);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_pointer);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_pointer);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_pointer);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{vo1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{vo1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    ///
    const char * chp1 = "a";
    {
        Nothing<char> nt1{chp1};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == flag::Nothing::define_pointer);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_pointer);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == flag::Nothing::define_pointer);
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == flag::Nothing::define_pointer);
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_pointer);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        
        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == flag::Nothing::define_pointer);
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == flag::Nothing::define_pointer);
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Width()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Width(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Precision(1)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer |
            flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Width(), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 2);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Width(1), arg::Precision()};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    {
        Nothing<char> nt1{chp1, arg::Width(), arg::Precision(2)};
        
        assert(nt1.IsSet() == false);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == false);
        assert(nt1.IsBad() == true);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::value_not_set);

        assert(nt1.Load(3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 1);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == false);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == false);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }
    
    {
        Nothing<char> nt1{chp1, arg::Width(1), arg::Precision(2)};
        
        assert(nt1.IsSet() == true);
        assert(nt1.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        test::out::CString<char> out_cstr1;
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt1.Output(out_cstr1) == 0);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(Load(nt1, 3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        assert(nt1.Load(3, 1, 2, 3) == 0);
        
        assert(nt1.IsSet() == true);
        assert(nt1.IsGood() == true);
        assert(nt1.IsBad() == false);
        assert(nt1.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt2{nt1};
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);
        
        Nothing<char> nt3{std::move(nt2)};
        
        assert(nt3.IsSet() == true);
        assert(nt3.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt3.IsGood() == true);
        assert(nt3.IsBad() == false);
        assert(nt3.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt2.IsSet() == true);
        assert(nt2.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt2.IsGood() == true);
        assert(nt2.IsBad() == false);
        assert(nt2.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt4;
        nt4 = nt3;
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);

        Nothing<char> nt5;
        nt5 = std::move(nt4);

        assert(nt5.IsSet() == true);
        assert(nt5.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt5.IsGood() == true);
        assert(nt5.IsBad() == false);
        assert(nt5.GetBadCode() == Nothing<char>::StatusType::good);
        
        assert(nt4.IsSet() == true);
        assert(nt4.GetFlag() == (flag::Nothing::define_pointer | 
            flag::Nothing::width | flag::Nothing::precision));
        assert(nt4.IsGood() == true);
        assert(nt4.IsBad() == false);
        assert(nt4.GetBadCode() == Nothing<char>::StatusType::good);
    }

    return 0;
}
