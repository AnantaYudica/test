#include "test/msg/fmt/val/flag/Pointer.h"
#include "test/out/CString.h"

#include <cassert>
#include <utility>
#include <cstring>

template<int Val>
struct PoFormat
{
    auto Output(test::out::Interface<char>& out) -> decltype(out.Print(""))
    {
        return 0;
    }
};

template<>
struct PoFormat<test::msg::fmt::val::flag::Pointer::good>
{
    static auto Output(test::out::Interface<char>& out) -> decltype(out.Print("_"))
    {
        return out.Print("%s", "%p");
    }
};

template<>
struct PoFormat<test::msg::fmt::val::flag::Pointer::width>
{
    static auto Output(test::out::Interface<char>& out) -> decltype(out.Print("_"))
    {
        return out.Print("%s", "%*p");
    }
};

int main()
{
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt::var;

    {
        constexpr Pointer po1{};

        assert(po1.GetValue() == Pointer::good);

        test::out::CString<char> out_cstr1;

        PoFormat<po1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%p", 3) == 0);

        constexpr Pointer po2{po1};

        assert(po2.GetValue() == Pointer::good);

        PoFormat<po2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%p%p", 5) == 0);

        constexpr Pointer po3{std::move(po2)};

        assert(po3.GetValue() == Pointer::good);

        PoFormat<po3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%p%p%p", 7) == 0);

        Pointer po4;

        po4 = po3;

        assert(po4.GetValue() == Pointer::good);

        Pointer po5;
        
        po5 = std::move(po4);

        assert(po5.GetValue() == Pointer::good);
    }
    {
        constexpr Pointer po1{arg::Width{}};

        assert(po1.GetValue() == Pointer::width);

        test::out::CString<char> out_cstr1;

        PoFormat<po1.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*p", 4) == 0);

        constexpr Pointer po2{po1};

        assert(po2.GetValue() == Pointer::width);

        PoFormat<po2.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*p%*p", 7) == 0);

        constexpr Pointer po3{std::move(po2)};

        assert(po3.GetValue() == Pointer::width);

        PoFormat<po3.GetValue()>::Output(out_cstr1);

        assert(strncmp(*(out_cstr1.Get()), "%*p%*p%*p", 10) == 0);

        Pointer po4;

        po4 = po3;

        assert(po4.GetValue() == Pointer::width);

        Pointer po5;
        
        po5 = std::move(po4);

        assert(po5.GetValue() == Pointer::width);
    }

    return 1;
}