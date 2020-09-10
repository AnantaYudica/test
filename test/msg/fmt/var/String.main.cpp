#include "test/msg/fmt/var/String.h"
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
    const char * cstr1 = "test1234";
    const char * cstr2 = "1234test";
    {
        String<char> st1;
        assert(st1.IsSet() == false);
        assert(st1.Load(1, cstr1) == 1);
        assert(st1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%s", cstr1);
        auto size_b = st1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        st1.Unset();
        assert(st1.IsSet() == false);
        assert(Load(st1, 1, cstr2) == 1);

        size_a = out_cstr1.Print("%s", cstr2);
        size_b = st1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st2{st1};
        assert(st2.IsSet() == true);

        size_a = out_cstr1.Print("%s", cstr2);
        size_b = st2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st3{std::move(st2)};
        assert(st3.IsSet() == true);
        assert(st2.IsSet() == false);

        size_a = out_cstr1.Print("%s", cstr2);
        size_b = st3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st4;
        st4 = st3;
        assert(st4.IsSet() == true);

        size_a = out_cstr1.Print("%s", cstr2);
        size_b = st4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st5;
        st5 = std::move(st4);
        assert(st5.IsSet() == true);
        assert(st4.IsSet() == false);
        
        size_a = out_cstr1.Print("%s", cstr2);
        size_b = st5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    {
        String<char> st1{cstr1};
        assert(st1.IsSet() == true);
        assert(st1.Load(1, cstr1) == 0);
        assert(st1.IsSet() == true);
        
        test::out::CString<char> out_cstr1, out_cstr2;
        auto size_a = out_cstr1.Print("%s", cstr1);
        auto size_b = st1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
        
        st1.Unset();
        assert(st1.IsSet() == true);
        assert(Load(st1, 1, cstr2) == 0);

        size_a = out_cstr1.Print("%s", cstr1);
        size_b = st1.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st2{st1};
        assert(st2.IsSet() == true);

        size_a = out_cstr1.Print("%s", cstr1);
        size_b = st2.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st3{std::move(st2)};
        assert(st3.IsSet() == true);
        assert(st2.IsSet() == true);

        size_a = out_cstr1.Print("%s", cstr1);
        size_b = st3.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st4;
        st4 = st3;
        assert(st4.IsSet() == true);

        size_a = out_cstr1.Print("%s", cstr1);
        size_b = st4.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);

        String<char> st5;
        st5 = std::move(st4);
        assert(st5.IsSet() == true);
        assert(st4.IsSet() == true);
        
        size_a = out_cstr1.Print("%s", cstr1);
        size_b = st5.Output(out_cstr2);
        assert(size_a == size_b);
        assert(out_cstr1.Size() == out_cstr2.Size());
        assert(strncmp(*(out_cstr1.Get()), *(out_cstr2.Get()), 
            out_cstr2.Size()) == 0);
    }
    return 0;
}
