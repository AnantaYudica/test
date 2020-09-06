#include "test/msg/fmt/val/specifier/print/Pointer.h"
#include "test/out/CString.h"

#include <cassert>

int main()
{
    using namespace test::msg::fmt::val::specifier;
    using namespace test::msg::fmt::val::flag;
    using namespace test::msg::fmt::val;
    using namespace test::msg::fmt::var;
    int in1 = 4;
    void * p1 = (void*)&in1;
    Width<char> wd1{14};

    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr Pointer po1{};

        out_cstr1_a.Print("%p", p1);
        print::Pointer<char, po1.GetValue()>::Print(out_cstr1_b, wd1, p1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        constexpr Pointer po1{arg::Width{}};
        
        out_cstr1_a.Print("%*p", wd1.GetValue(), p1);
        print::Pointer<char, po1.GetValue()>::Print(out_cstr1_b, wd1, p1);
        
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    return 0;
}