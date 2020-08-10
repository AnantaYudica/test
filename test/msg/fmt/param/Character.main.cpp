#include "test/msg/fmt/param/Character.h"
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
    
    {
        Parameter<char, Character<char>> p1{};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(1, 'A') == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "A", 2) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 1, 'a') == 1);

        size = pp1->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aa", 3) == 0);

        Parameter<char, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaa", 4) == 0);

        Parameter<char, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaa", 5) == 0);

        Parameter<char, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaaa", 6) == 0);

        Parameter<char, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaaaa", 7) == 0);
    }
    {
        Parameter<char, Character<char>> p1{Character<char>{}};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(1, 'A') == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "A", 2) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 1, 'a') == 1);

        size = pp1->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aa", 3) == 0);

        Parameter<char, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaa", 4) == 0);

        Parameter<char, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaa", 5) == 0);

        Parameter<char, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaaa", 6) == 0);

        Parameter<char, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "Aaaaaa", 7) == 0);
        
    }
    {
        Parameter<char, Character<char>> p1{Character<char>{'N'}};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        pp1->Unset();

        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "N", 2) == 0);

        Parameter<char, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "NN", 3) == 0);

        Parameter<char, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp3->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "NNN", 4) == 0);

        Parameter<char, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "NNNN", 5) == 0);

        Parameter<char, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size = pp5->Output(out_cstr1);
        assert(size == 1);
        assert(strncmp(*(out_cstr1.Get()), "NNNNN", 6) == 0);
        
    }
    {
        Parameter<char, Character<char>, Character<char>> p1{};
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(2, 'A', 'B') == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AB", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, 'C', 'd') == 2);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCd", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCd", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCd", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCdCd", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCdCdCd", 13) == 0);

    }
    {
        Parameter<char, Character<char>, Character<char>> p1{
            Character<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, 'A', 'B') == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AB", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, 'C', 'd') == 2);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCd", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCd", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCd", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCdCd", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCdCdCd", 13) == 0);

    }
    {
        Parameter<char, Character<char>, Character<char>> p1{
            Character<char>{'D'}
        };

        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, 'A', 'B') == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "DA", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, 'C', 'd') == 1);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "DADC", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "DADCDC", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "DADCDCDC", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "DADCDCDCDC", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "DADCDCDCDCDC", 13) == 0);

    }
    
    {
        Parameter<char, Character<char>, Character<char>> p1{
            Character<char>{}, Character<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, 'A', 'B') == 2);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AB", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, 'C', 'd') == 2);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCd", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCd", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCd", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCdCd", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ABCdCdCdCdCd", 13) == 0);

    }
    {
        Parameter<char, Character<char>, Character<char>> p1{
            Character<char>{'Z'}, Character<char>{}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, 'A', 'B') == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ZA", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, 'C', 'd') == 1);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ZAZC", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ZAZCZC", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ZAZCZCZC", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ZAZCZCZCZC", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "ZAZCZCZCZCZC", 13) == 0);
    }
    {
        Parameter<char, Character<char>, Character<char>> p1{
            Character<char>{}, Character<char>{'H'}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(2, 'A', 'B') == 1);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AH", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(Load(*pp1, 2, 'C', 'd') == 1);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AHCH", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AHCHCH", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AHCHCHCH", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AHCHCHCHCH", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "AHCHCHCHCHCH", 13) == 0);
    }
    {
        Parameter<char, Character<char>, Character<char>> p1{
            Character<char>{'v'}, Character<char>{'W'}
        };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        assert(pp1->Load(2, 'A', 'B') == 0);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1;
        auto size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "vW", 3) == 0);

        pp1->Unset();
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);
        assert(Load(*pp1, 2, 'C', 'd') == 0);

        size = pp1->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "vWvW", 5) == 0);

        Parameter<char, Character<char>, Character<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp2->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "vWvWvW", 7) == 0);

        Parameter<char, Character<char>, Character<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);

        size = pp3->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "vWvWvWvW", 9) == 0);

        Parameter<char, Character<char>, Character<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;

        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);

        size = pp4->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "vWvWvWvWvW", 11) == 0);

        Parameter<char, Character<char>, Character<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size = pp5->Output(out_cstr1);
        assert(size == 2);
        assert(strncmp(*(out_cstr1.Get()), "vWvWvWvWvWvW", 13) == 0);
    }
    return 1;
};