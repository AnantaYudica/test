#include "test/msg/fmt/var/Pointer.h"
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
    int in1 = 2, in2 = 4;
    void * vo1 = (void*)&in1, *vo2 = (void*)&in2;
    {
        Pointer<char> po1;
        assert(po1.IsSet() == false);
        assert(po1.Load(1, vo1) == 1);
        assert(po1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%p", vo1);
        auto size_b = po1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        po1.Unset();
        assert(po1.IsSet() == false);
        assert(Load(po1, 1, vo2) == 1);

        size_a = out_cstr1.Print("%p", vo2);
        size_b = po1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po2{po1};
        assert(po2.IsSet() == true);

        size_a = out_cstr1.Print("%p", vo2);
        size_b = po2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po3{std::move(po2)};
        assert(po3.IsSet() == true);
        assert(po2.IsSet() == false);

        size_a = out_cstr1.Print("%p", vo2);
        size_b = po3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po4;
        po4 = po3;
        assert(po4.IsSet() == true);

        size_a = out_cstr1.Print("%p", vo2);
        size_b = po4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po5;
        po5 = std::move(po4);
        assert(po5.IsSet() == true);
        assert(po4.IsSet() == false);
        
        size_a = out_cstr1.Print("%p", vo2);
        size_b = po5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    {
        Pointer<char> po1{vo1};
        assert(po1.IsSet() == true);
        assert(po1.Load(1, vo1) == 0);
        assert(po1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%p", vo1);
        auto size_b = po1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        po1.Unset();
        assert(po1.IsSet() == true);
        assert(Load(po1, 1, vo2) == 0);

        size_a = out_cstr1.Print("%p", vo1);
        size_b = po1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po2{po1};
        assert(po2.IsSet() == true);

        size_a = out_cstr1.Print("%p", vo1);
        size_b = po2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po3{std::move(po2)};
        assert(po3.IsSet() == true);
        assert(po2.IsSet() == true);

        size_a = out_cstr1.Print("%p", vo1);
        size_b = po3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po4;
        po4 = po3;
        assert(po4.IsSet() == true);

        size_a = out_cstr1.Print("%p", vo1);
        size_b = po4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        Pointer<char> po5;
        po5 = std::move(po4);
        assert(po5.IsSet() == true);
        assert(po4.IsSet() == true);
        
        size_a = out_cstr1.Print("%p", vo1);
        size_b = po5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    return 1;
}