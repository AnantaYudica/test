#include "test/msg/fmt/var/Character.h"
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
        
        Character<char> ch1;
        assert(ch1.IsSet() == false);
        assert(ch1.Load(1, 'A') == 1);
        assert(ch1.IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = ch1.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "A", 2) == 0);

        ch1.Unset();
        assert(ch1.IsSet() == false);
        assert(Load(ch1, 1, 'a') == 1);

        size = ch1.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "Aa", 3) == 0);

        Character<char> ch2{ch1};
        assert(ch2.IsSet() == true);

        size = ch2.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaa", 4) == 0);

        Character<char> ch3{std::move(ch2)};
        assert(ch3.IsSet() == true);
        assert(ch2.IsSet() == false);

        size = ch3.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaa", 5) == 0);

        Character<char> ch4;
        ch4 = ch3;
        assert(ch4.IsSet() == true);

        size = ch4.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaaa", 6) == 0);

        Character<char> ch5;
        ch5 = std::move(ch4);
        assert(ch5.IsSet() == true);
        assert(ch4.IsSet() == false);
        
        size = ch5.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaaaa", 7) == 0);
    }
    {
        Character<char> ch1{'Y'};
        assert(ch1.IsSet() == true);

        ch1.Unset();
        
        assert(ch1.IsSet() == true);
        
        test::out::CString<char> out_cstr1;
        auto size = ch1.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "Y", 2) == 0);

        Character<char> ch2{ch1};
        assert(ch2.IsSet() == true);

        size = ch2.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "YY", 3) == 0);

        Character<char> ch3{std::move(ch2)};
        assert(ch3.IsSet() == true);
        assert(ch2.IsSet() == true);

        size = ch3.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "YYY", 4) == 0);

        Character<char> ch4;
        ch4 = ch3;
        assert(ch4.IsSet() == true);

        size = ch4.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "YYYY", 5) == 0);

        Character<char> ch5;
        ch5 = std::move(ch4);
        assert(ch5.IsSet() == true);
        assert(ch4.IsSet() == true);
        
        size = ch5.Output(out_cstr1);
        assert(size = 1);
        assert(strncmp(*(out_cstr1.Get()), "YYYYY", 6) == 0);

    }
    return 1;
}