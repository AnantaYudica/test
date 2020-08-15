#include "test/msg/fmt/param/String.h"
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
    using namespace test::msg::fmt;
    const char * cstr1 = "test1234";
    const char * cstr2 = "1234test";
    {
        Parameter<char, String<char>> p1{};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(1, cstr1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s", cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 1, cstr2) == 1);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    
    {
        Parameter<char, String<char>> p1{String<char>{}};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(1, cstr1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s", cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 1, cstr2) == 1);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s", cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>> p1{String<char>{cstr1}};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        assert(pp1->Load(1, cstr1) == 0);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s", cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        assert(Load(*pp1, 1, cstr2) == 0);

        size_a = out_cstr1_a.Print("%s", cstr1);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr1);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr1);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s", cstr1);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%s", cstr1);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>, String<char>> p1{};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, cstr1, cstr1) == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, cstr2, cstr2) == 2);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>, String<char>> p1{
            String<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, cstr1, cstr1) == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, cstr2, cstr2) == 2);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>, String<char>> p1{
            String<char>{cstr1}
        };

        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, cstr1, cstr1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, cstr2, cstr2) == 1);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    
    {
        Parameter<char, String<char>, String<char>> p1{
            String<char>{}, String<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, cstr1, cstr1) == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, cstr2, cstr2) == 2);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>, String<char>> p1{
            String<char>{cstr1}, String<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, cstr1, cstr1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, cstr2, cstr2) == 1);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>, String<char>> p1{
            String<char>{}, String<char>{cstr1}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, cstr1, cstr1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, cstr2, cstr2) == 1);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr1);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr1);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr1);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr1);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%s%s", cstr2, cstr1);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, String<char>, String<char>> p1{
            String<char>{cstr1}, String<char>{cstr1}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        
        assert(pp1->Load(2, cstr1, cstr1) == 0);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        assert(Load(*pp1, 2, cstr2, cstr2) == 0);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, String<char>, String<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%s%s", cstr1, cstr1);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    return 1;
}