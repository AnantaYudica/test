#include "test/msg/fmt/var/Nothing.h"
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
        Nothing<char> nt1;
        assert(nt1.IsSet() == false);
        assert(nt1.Load(1, 0) == 1);
        assert(nt1.IsSet() == true);
        
        test::out::CString<char> out_cstr1;
        auto size_a = nt1.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);
        
        nt1.Unset();
        assert(nt1.IsSet() == false);
        assert(Load(nt1, 1, 0) == 1);

        size_a = nt1.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt2{nt1};
        assert(nt2.IsSet() == true);

        size_a = nt2.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt3{std::move(nt2)};
        assert(nt3.IsSet() == true);
        assert(nt2.IsSet() == false);

        size_a = nt3.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt4;
        nt4 = nt3;
        assert(nt4.IsSet() == true);

        size_a = nt4.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt5;
        nt5 = std::move(nt4);
        assert(nt5.IsSet() == true);
        assert(nt4.IsSet() == false);
        
        size_a = nt5.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);
    }
    {
        Nothing<char> nt1{0};
        assert(nt1.IsSet() == true);
        assert(nt1.Load(1, 0) == 0);
        assert(nt1.IsSet() == true);
        
        test::out::CString<char> out_cstr1;
        auto size_a = nt1.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);
        
        nt1.Unset();
        assert(nt1.IsSet() == true);
        assert(Load(nt1, 1, 0) == 0);

        size_a = nt1.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt2{nt1};
        assert(nt2.IsSet() == true);

        size_a = nt2.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt3{std::move(nt2)};
        assert(nt3.IsSet() == true);
        assert(nt2.IsSet() == true);

        size_a = nt3.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt4;
        nt4 = nt3;
        assert(nt4.IsSet() == true);

        size_a = nt4.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);

        Nothing<char> nt5;
        nt5 = std::move(nt4);
        assert(nt5.IsSet() == true);
        assert(nt4.IsSet() == true);
        
        size_a = nt5.Output(out_cstr1);
        assert(size_a == 0);
        assert(out_cstr1.Size() == 0);
    }
    return 0;
}
