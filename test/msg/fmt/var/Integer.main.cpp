#include "test/msg/fmt/var/Integer.h"
#include "test/out/CString.h"

#include <cassert>
#include <cstring>
#include <cstdarg>
#include <utility>

template<typename T>
std::size_t Load(T& obj, std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto index = obj.VLoad(size, 0, args);
    va_end(args);
    return index;
}

int main()
{
    using namespace test::msg::fmt::var;
    {
        Integer<char> in1;
        assert(in1.IsSet() == false);
        assert(in1.Load(1, 1234) == 1);
        assert(in1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%d", 1234);
        auto size_b = in1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        in1.Unset();
        assert(in1.IsSet() == false);
        assert(Load(in1, 1, 5678) == 1);

        size_a = out_cstr1.Print("%d", 5678);
        size_b = in1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in2{in1};
        assert(in2.IsSet() == true);

        size_a = out_cstr1.Print("%d", 5678);
        size_b = in2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in3{std::move(in2)};
        assert(in3.IsSet() == true);
        assert(in2.IsSet() == false);

        size_a = out_cstr1.Print("%d", 5678);
        size_b = in3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in4;
        in4 = in3;
        assert(in4.IsSet() == true);

        size_a = out_cstr1.Print("%d", 5678);
        size_b = in4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in5;
        in5 = std::move(in4);
        assert(in5.IsSet() == true);
        assert(in4.IsSet() == false);
        
        size_a = out_cstr1.Print("%d", 5678);
        size_b = in5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    {
        Integer<char> in1{1234};
        assert(in1.IsSet() == true);
        assert(in1.Load(1, 5678) == 0);
        assert(in1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%d", 1234);
        auto size_b = in1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        in1.Unset();
        assert(in1.IsSet() == true);
        assert(Load(in1, 1, 5678) == 0);

        size_a = out_cstr1.Print("%d", 1234);
        size_b = in1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in2{in1};
        assert(in2.IsSet() == true);

        size_a = out_cstr1.Print("%d", 1234);
        size_b = in2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in3{std::move(in2)};
        assert(in3.IsSet() == true);
        assert(in2.IsSet() == true);

        size_a = out_cstr1.Print("%d", 1234);
        size_b = in3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in4;
        in4 = in3;
        assert(in4.IsSet() == true);

        size_a = out_cstr1.Print("%d", 1234);
        size_b = in4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Integer<char> in5;
        in5 = std::move(in4);
        assert(in5.IsSet() == true);
        assert(in4.IsSet() == true);
        
        size_a = out_cstr1.Print("%d", 1234);
        size_b = in5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    return 0;
}