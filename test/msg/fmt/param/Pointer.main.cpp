#include "test/msg/fmt/param/Pointer.h"
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
    int in1 = 4, in2 = 8;
    void *vo1 = (void*)&in1, *vo2 = (void*)&in2;
    {
        Parameter<char, Pointer<char>> p1{};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(1, vo1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p", vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 1, vo2) == 1);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>> p1{Pointer<char>{}};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(1, vo1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p", vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 1, vo2) == 1);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p", vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>> p1{Pointer<char>{vo1}};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        assert(pp1->Load(1, vo1) == 0);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p", vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        assert(Load(*pp1, 1, vo2) == 0);

        size_a = out_cstr1_a.Print("%p", vo1);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo1);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo1);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p", vo1);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%p", vo1);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, vo1, vo1) == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, vo2, vo2) == 2);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{
            Pointer<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, vo1, vo1) == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, vo2, vo2) == 2);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{
            Pointer<char>{vo1}
        };

        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, vo1, vo1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, vo2, vo2) == 1);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{
            Pointer<char>{}, Pointer<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, vo1, vo1) == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, vo2, vo2) == 2);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p%p", vo2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{
            Pointer<char>{vo1}, Pointer<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, vo1, vo1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, vo2, vo2) == 1);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p%p", vo1, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{
            Pointer<char>{}, Pointer<char>{vo1}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, vo1, vo1) == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, vo2, vo2) == 1);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo1);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo1);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo1);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo2, vo1);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%p%p", vo2, vo1);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Pointer<char>, Pointer<char>> p1{
            Pointer<char>{vo1}, Pointer<char>{vo1}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        
        assert(pp1->Load(2, vo1, vo1) == 0);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        pp1->Unset();
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        assert(Load(*pp1, 2, vo2, vo2) == 0);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        size_b = pp2->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Pointer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%p%p", vo1, vo1);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    return 0;
}
