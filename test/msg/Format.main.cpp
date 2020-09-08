#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/msg/Format.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <utility>

int main()
{
    {
        test::msg::Format<char> f1{
            test::msg::fmt::var::String<char>{},
            test::msg::fmt::var::Integer<char>{}
        };

        assert(f1 == true);
        assert(f1.IsSet() == false);
        assert(f1.IsGood() == true);
        assert(f1.IsBad() == false);
        assert(f1.GetBadCode() == test::msg::Format<char>::StatusType::good);

        assert(f1.Load("test : ", 4000) == 2);
        assert(f1.IsSet() == true);
        assert(f1.IsGood() == true);
        assert(f1.IsBad() == false);
        assert(f1.GetBadCode() == test::msg::Format<char>::StatusType::good);

        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr2.Print("%s%d", "test : ", 4000);
        auto size_b = f1.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        f1.Unset();
        assert(f1.IsSet() == false);
        assert(f1.IsGood() == true);
        assert(f1.IsBad() == false);
        assert(f1.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        assert(f1.Load("test ? ", -4000) == 2);
        assert(f1.IsSet() == true);
        assert(f1.IsGood() == true);
        assert(f1.IsBad() == false);
        assert(f1.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        size_a = out_cstr2.Print("%s%d", "test ? ", -4000);
        size_b = f1.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        f1.Reset();
        assert(f1.IsSet() == false);
        assert(f1.IsGood() == true);
        assert(f1.IsBad() == false);
        assert(f1.GetBadCode() == test::msg::Format<char>::StatusType::good);

        assert(f1.Load("test ? ", 6000) == 2);
        assert(f1.IsSet() == true);
        assert(f1.IsGood() == true);
        assert(f1.IsBad() == false);
        assert(f1.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        size_a = out_cstr2.Print("%s%d", "test ? ", 6000);
        size_b = f1.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        test::msg::Format<char> f2{f1};
        assert(f2 == true);
        assert(f2.IsSet() == true);
        assert(f2.IsGood() == true);
        assert(f2.IsBad() == false);
        assert(f2.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        size_a = out_cstr2.Print("%s%d", "test ? ", 6000);
        size_b = f2.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        test::msg::Format<char> f3{std::move(f2)};
        assert(f3 == true);
        assert(f3.IsSet() == true);
        assert(f3.IsGood() == true);
        assert(f3.IsBad() == false);
        assert(f3.GetBadCode() == test::msg::Format<char>::StatusType::good);

        assert(f2 == false);
        assert(f2.IsSet() == false);
        assert(f2.IsGood() == true);
        assert(f2.IsBad() == false);
        assert(f2.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        size_a = out_cstr2.Print("%s%d", "test ? ", 6000);
        size_b = f3.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        test::msg::Format<char> f4;
        f4 = f3;

        assert(f4 == true);
        assert(f4.IsSet() == true);
        assert(f4.IsGood() == true);
        assert(f4.IsBad() == false);
        assert(f4.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        size_a = out_cstr2.Print("%s%d", "test ? ", 6000);
        size_b = f4.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        test::msg::Format<char> f5;
        f5 = std::move(f4);
        
        assert(f5 == true);
        assert(f5.IsSet() == true);
        assert(f5.IsGood() == true);
        assert(f5.IsBad() == false);
        assert(f5.GetBadCode() == test::msg::Format<char>::StatusType::good);

        assert(f4 == false);
        assert(f4.IsSet() == false);
        assert(f4.IsGood() == true);
        assert(f4.IsBad() == false);
        assert(f4.GetBadCode() == test::msg::Format<char>::StatusType::good);
        
        size_a = out_cstr2.Print("%s%d", "test ? ", 6000);
        size_b = f5.Output(out_cstr1);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
    }
    
    return TEST::GetInstance().Status().Get();
}
