#include "test/msg/fmt/Parameter.h"
#include "test/msg/fmt/param/Character.h"
#include "test/msg/fmt/param/FloatingPoint.h"
#include "test/msg/fmt/param/Integer.h"
#include "test/msg/fmt/param/Nothing.h"
#include "test/msg/fmt/param/Pointer.h"
#include "test/msg/fmt/param/String.h"
#include "test/out/CString.h"

#include <cassert>
#include <utility>
#include <cstring>

int main()
{
    using namespace test::msg::fmt;
    using namespace test::msg::fmt::var;
    char ch1 = 'A', ch2 = 'd';
    long double ld1 = 22.0L/7.0L, ld2 = 7.0L/22.0L;
    const char * cstr1 = "test1234", *cstr2 = "1234test";
    long long ll1 = 230192LL, ll2 = 291032LL;
    void * vo1 = (void*)&ch1, *vo2 = (void*)&ch2;
    {
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p1{
                Character<char>{}, 
                FloatingPoint<char>{arg::Define<long double>{}},
                String<char>{},
                Integer<char>{arg::Define<long long>{}},
                Pointer<char>{}
            };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(5, ch1, ld1, cstr1, ll1, vo1) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%c%Lf%s%lld%p", 
            ch1, ld1, cstr1, ll1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(pp1->Load(5, ch2, ld2, cstr2, ll2, vo2) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        size_a = out_cstr1_a.Print("%c%Lf%s%lld%p", 
            ch2, ld2, cstr2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld%p", 
            ch2, ld2, cstr2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld%p", 
            ch2, ld2, cstr2, ll2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld%p", 
            ch2, ld2, cstr2, ll2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
            
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld%p", 
            ch2, ld2, cstr2, ll2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Nothing<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p1{
                Nothing<char>{arg::Define<char>{}}, 
                FloatingPoint<char>{arg::Define<long double>{}},
                String<char>{},
                Integer<char>{arg::Define<long long>{}},
                Pointer<char>{}
            };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(5, ch1, ld1, cstr1, ll1, vo1) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%Lf%s%lld%p", 
            ld1, cstr1, ll1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(pp1->Load(5, ch2, ld2, cstr2, ll2, vo2) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        size_a = out_cstr1_a.Print("%Lf%s%lld%p", 
            ld2, cstr2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Nothing<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%Lf%s%lld%p", 
            ld2, cstr2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        
        Parameter<char, Nothing<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%Lf%s%lld%p", 
            ld2, cstr2, ll2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        Parameter<char, Nothing<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%Lf%s%lld%p", 
            ld2, cstr2, ll2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
            
        Parameter<char, Nothing<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%Lf%s%lld%p", 
            ld2, cstr2, ll2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Character<char>, Nothing<char>, 
            String<char>, Integer<char>, Pointer<char>> p1{
                Character<char>{}, 
                Nothing<char>{arg::Define<long double>{}},
                String<char>{},
                Integer<char>{arg::Define<long long>{}},
                Pointer<char>{}
            };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        
        assert(pp1->Load(5, ch1, ld1, cstr1, ll1, vo1) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%c%s%lld%p", 
            ch1, cstr1, ll1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(pp1->Load(5, ch2, ld2, cstr2, ll2, vo2) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        size_a = out_cstr1_a.Print("%c%s%lld%p", 
            ch2, cstr2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Character<char>, Nothing<char>, 
            String<char>, Integer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%s%lld%p", 
            ch2, cstr2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        
        Parameter<char, Character<char>, Nothing<char>, 
            String<char>, Integer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%s%lld%p", 
            ch2, cstr2, ll2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        Parameter<char, Character<char>, Nothing<char>, 
            String<char>, Integer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%s%lld%p", 
            ch2, cstr2, ll2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
            
        Parameter<char, Character<char>, Nothing<char>, 
            String<char>, Integer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%s%lld%p", 
            ch2, cstr2, ll2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Character<char>, FloatingPoint<char>, 
            Nothing<char>, Integer<char>, Pointer<char>> p1{
                Character<char>{}, 
                FloatingPoint<char>{arg::Define<long double>{}},
                Nothing<char>{arg::Define<const char*>{}},
                Integer<char>{arg::Define<long long>{}},
                Pointer<char>{}
            };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(5, ch1, ld1, cstr1, ll1, vo1) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%c%Lf%lld%p", 
            ch1, ld1, ll1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(pp1->Load(5, ch2, ld2, cstr2, ll2, vo2) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        size_a = out_cstr1_a.Print("%c%Lf%lld%p", 
            ch2, ld2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Character<char>, FloatingPoint<char>, 
            Nothing<char>, Integer<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%lld%p", 
            ch2, ld2, ll2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        
        Parameter<char, Character<char>, FloatingPoint<char>, 
            Nothing<char>, Integer<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%lld%p", 
            ch2, ld2, ll2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        Parameter<char, Character<char>, FloatingPoint<char>, 
            Nothing<char>, Integer<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%lld%p", 
            ch2, ld2, ll2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
            
        Parameter<char, Character<char>, FloatingPoint<char>, 
            Nothing<char>, Integer<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%lld%p", 
            ch2, ld2, ll2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Nothing<char>, Pointer<char>> p1{
                Character<char>{}, 
                FloatingPoint<char>{arg::Define<long double>{}},
                String<char>{},
                Nothing<char>{arg::Define<long long>{}},
                Pointer<char>{}
            };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(5, ch1, ld1, cstr1, ll1, vo1) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%c%Lf%s%p", 
            ch1, ld1, cstr1, vo1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(pp1->Load(5, ch2, ld2, cstr2, ll2, vo2) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        size_a = out_cstr1_a.Print("%c%Lf%s%p", 
            ch2, ld2, cstr2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Nothing<char>, Pointer<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%p", 
            ch2, ld2, cstr2, vo2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Nothing<char>, Pointer<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%p", 
            ch2, ld2, cstr2, vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Nothing<char>, Pointer<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%p", 
            ch2, ld2, cstr2, vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
            
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Nothing<char>, Pointer<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%p", 
            ch2, ld2, cstr2, vo2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    {
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Nothing<char>> p1{
                Character<char>{}, 
                FloatingPoint<char>{arg::Define<long double>{}},
                String<char>{},
                Integer<char>{arg::Define<long long>{}},
                Nothing<char>{arg::Define<const void*>{}}
            };
        Parameter<char> * pp1 = &p1;
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);

        assert(pp1->Load(5, ch1, ld1, cstr1, ll1, vo1) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        test::out::CString<char> out_cstr1_a, out_cstr1_b;
        auto size_a = out_cstr1_a.Print("%c%Lf%s%lld", 
            ch1, ld1, cstr1, ll1);
        auto size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        pp1->Unset();
        assert(p1.IsSet() == false);
        assert(pp1->IsSet() == false);
        assert(pp1->Load(5, ch2, ld2, cstr2, ll2, vo2) == 5);
        assert(p1.IsSet() == true);
        assert(pp1->IsSet() == true);

        size_a = out_cstr1_a.Print("%c%Lf%s%lld", 
            ch2, ld2, cstr2, ll2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);

        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Nothing<char>> p2{p1};
        Parameter<char> * pp2 = &p2;
        assert(p2.IsSet() == true);
        assert(pp2->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld", 
            ch2, ld2, cstr2, ll2);
        size_b = pp1->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
        
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Nothing<char>> p3{std::move(p2)};
        Parameter<char> * pp3 = &p3;
        assert(p3.IsSet() == true);
        assert(pp3->IsSet() == true);
        assert(p2.IsSet() == false);
        assert(pp2->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld%n", 
            ch2, ld2, cstr2, ll2, (int*)vo2);
        size_b = pp3->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Nothing<char>> p4;
        Parameter<char> * pp4 = &p4;
        p4 = p3;
        assert(p4.IsSet() == true);
        assert(pp4->IsSet() == true);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld%n", 
            ch2, ld2, cstr2, ll2, (int*)vo2);
        size_b = pp4->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
            
        Parameter<char, Character<char>, FloatingPoint<char>, 
            String<char>, Integer<char>, Nothing<char>> p5;
        Parameter<char> * pp5 = &p5;
        p5 = std::move(p4);
        assert(p5.IsSet() == true);
        assert(pp5->IsSet() == true);
        assert(p4.IsSet() == false);
        assert(pp4->IsSet() == false);
        
        size_a = out_cstr1_a.Print("%c%Lf%s%lld", 
            ch2, ld2, cstr2, ll2);
        size_b = pp5->Output(out_cstr1_b);
        assert(size_a == size_b);
        assert(out_cstr1_a.Size() == out_cstr1_b.Size());
        assert(strncmp(*(out_cstr1_a.Get()), *(out_cstr1_b.Get()), 
            out_cstr1_b.Size()) == 0);
    }
    return 0;
}
