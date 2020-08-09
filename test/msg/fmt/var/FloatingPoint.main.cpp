#include "test/msg/fmt/var/FloatingPoint.h"
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
        FloatingPoint<char> fl1;
        assert(fl1.IsSet() == false);
        assert(fl1.Load(1, 3.14) == 1);
        assert(fl1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%f", 3.14);
        auto size_b = fl1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        
        fl1.Unset();
        assert(fl1.IsSet() == false);
        assert(Load(fl1, 1, 6.28) == 1);

        size_a = out_cstr1.Print("%f", 6.28);
        size_b = fl1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl2{fl1};
        assert(fl2.IsSet() == true);

        size_a = out_cstr1.Print("%f", 6.28);
        size_b = fl2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl3{std::move(fl2)};
        assert(fl3.IsSet() == true);
        assert(fl2.IsSet() == false);

        size_a = out_cstr1.Print("%f", 6.28);
        size_b = fl3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl4;
        fl4 = fl3;
        assert(fl4.IsSet() == true);

        size_a = out_cstr1.Print("%f", 6.28);
        size_b = fl4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl5;
        fl5 = std::move(fl4);
        assert(fl5.IsSet() == true);
        assert(fl4.IsSet() == false);
        
        size_a = out_cstr1.Print("%f", 6.28);
        size_b = fl5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    {
        FloatingPoint<char> fl1{3.14};
        assert(fl1.IsSet() == true);
        assert(fl1.Load(1, 3.14) == 0);
        assert(fl1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%f", 3.14);
        auto size_b = fl1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        fl1.Unset();
        assert(fl1.IsSet() == true);
        assert(Load(fl1, 1, 6.28) == 0);

        size_a = out_cstr1.Print("%f", 3.14);
        size_b = fl1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl2{fl1};
        assert(fl2.IsSet() == true);

        size_a = out_cstr1.Print("%f", 3.14);
        size_b = fl2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl3{std::move(fl2)};
        assert(fl3.IsSet() == true);
        assert(fl2.IsSet() == true);

        size_a = out_cstr1.Print("%f", 3.14);
        size_b = fl3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl4;
        fl4 = fl3;
        assert(fl4.IsSet() == true);

        size_a = out_cstr1.Print("%f", 3.14);
        size_b = fl4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        FloatingPoint<char> fl5;
        fl5 = std::move(fl4);
        assert(fl5.IsSet() == true);
        assert(fl4.IsSet() == true);
        
        size_a = out_cstr1.Print("%f", 3.14);
        size_b = fl5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    return 1;
}