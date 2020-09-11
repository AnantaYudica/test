#define USING_TEST_MEMORY
#include "Test.h"
TEST_CONSTRUCT;

#include "test/Pointer.h"

#include <cassert>
#include <utility>

struct Obj1
{
    int value;
    Obj1() : value(0) {};
    Obj1(int i) : value(i) {};
    int GetValue() {return value;};
};

struct Obj2
{
    int value;
    Obj2(int i) : value(i) {};
    Obj2(const Obj2& cpy) : value(cpy.value) {};
    Obj2(Obj2&& mov) : value(mov.value){};
    int GetValue() {return value;};
};

const int DefaultValueObj2 = 10; 

Obj2 DefaultObj2()
{
    return Obj2{DefaultValueObj2};
}

struct Obj3Base1
{
    Obj3Base1() = default;
    virtual ~Obj3Base1() = default;
    virtual int& Value() const = 0;
};

struct Obj3 : Obj3Base1
{
    int * val;
    Obj3() : val(new int(0)) {}
    ~Obj3() {delete val;}
    int& Value() const override {return *val;}
};

template<typename TT, typename TTDefault, typename TF, typename TFDefault>
bool TestDynamicCast(test::Pointer<TF, TFDefault> from)
{
    auto p = from.template DynamicCast<TT, TTDefault>();
    return from == p;
}


int main()
{
    {
        test::Pointer<int> p1{0};
        assert(*p1 == 0);
        assert(p1[0] == 0);
        assert(p1.Size() == 1);
        assert(p1.AllocationSize() == sizeof(int));
        assert(p1.StepSize() == sizeof(int));
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);

        *p1 = 4;
        assert(*p1 == 4);
        assert(p1[0] == 4);
        assert(static_cast<const test::Pointer<int>&>(p1)[0] == 4);

        p1 += 1;
        
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);

        p1 -= 1;
        
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);

        p1++;
        ++p1;
        
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);

        p1--;
        --p1;
        
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);

        assert((p1 + 1).Offset() == 0);
        assert((p1 + 1).Index() == 0);

        assert((p1 - 1).Offset() == 0);
        assert((p1 - 1).Index() == 0);

        test::Pointer<int> p2{p1};
        assert(*p2 == 4);
        assert(*p1 == 4);
        assert(p2.Size() == 1);
        assert(p2.AllocationSize() == sizeof(int));
        assert(p2.StepSize() == sizeof(int));

        assert(p2 == p1);

        test::Pointer<int> p3{std::move(p2)};
        assert(*p3 == 4);
        assert(*p2 != 4);
        assert(*p1 == 4);
        assert(p3.Size() == 1);
        assert(p3.AllocationSize() == sizeof(int));
        assert(p3.StepSize() == sizeof(int));

        assert(p3 == p1);
        assert(p3 != p2);

        test::Pointer<int> p4;

        p4 = p3;
        assert(*p4 == 4);
        assert(*p3 == 4);
        assert(*p2 != 4);
        assert(*p1 == 4);
        assert(p4.Size() == 1);
        assert(p4.AllocationSize() == sizeof(int));
        assert(p4.StepSize() == sizeof(int));

        assert(p4 == p1);
        assert(p4 != p2);
        assert(p4 == p3);
        
        test::Pointer<int> p5;

        p5 = std::move(p4);
        assert(*p5 == 4);
        assert(*p4 != 4);
        assert(*p3 == 4);
        assert(*p2 != 4);
        assert(*p1 == 4);
        assert(p5.Size() == 1);
        assert(p5.AllocationSize() == sizeof(int));
        assert(p5.StepSize() == sizeof(int));

        assert(p5 == p1);
        assert(p5 != p2);
        assert(p5 == p3);
        assert(p5 != p4);

        auto p6 = p5.StaticCast<const int>();
        assert(*p6 == 4);
        assert(p6.Size() == 1);
        assert(p6.AllocationSize() == sizeof(int));
        assert(p6.StepSize() == sizeof(int));
        assert(p6 == p5);

        auto p7 = p6.ConstCast<int>();
        
        assert(*p7 == 4);
        assert(p7.Size() == 1);
        assert(p7.AllocationSize() == sizeof(int));
        assert(p7.StepSize() == sizeof(int));
        assert(p7 == p5);
        assert(p7 == p5);

        *p7 += 6;
        assert(*p6 == 10);
        assert(*p7 == 10);

        auto p8 = p7.ReinterpretCast<char>();
        
        assert(p8.Size() == sizeof(int) / sizeof(char));
        assert(p8.AllocationSize() == sizeof(int));
        assert(p8.StepSize() == sizeof(char));
        assert(p8 == p7);

    }
    {
        test::Pointer<int> p1{test::ptr::arg::Array(10), 1, 2, 3, 4, 5};
        
        assert(p1[0] == 1);
        assert(p1[1] == 2);
        assert(p1[2] == 3);
        assert(p1[3] == 4);
        assert(p1[4] == 5);
        
        assert(p1.Size() == 10);
        assert(p1.AllocationSize() == (sizeof(int)* 10));
        assert(p1.StepSize() == sizeof(int));
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);

        p1 += 5;
        assert(p1.Offset() == 5 * sizeof(int));
        assert(p1.Index() == 5);

        *(p1++) = 6;
        *(p1++) = 7;
        *(p1++) = 8;
        *(p1++) = 9;
        *(p1++) = 10;

        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);
    
        assert(p1[5] == 6);
        assert(p1[6] == 7);
        assert(p1[7] == 8);
        assert(p1[8] == 9);
        assert(p1[9] == 10);

        p1 += 1;
        
        assert(p1.Offset() == (sizeof(int) * 1));
        assert(p1.Index() == 1);
        
        p1 += 6;
        
        assert(p1.Offset() == (sizeof(int) * 7));
        assert(p1.Index() == 7);

        p1 -= 1;
        
        assert(p1.Offset() == (sizeof(int) * 6));
        assert(p1.Index() == 6);

        p1 -= 5;

        assert(p1.Offset() == (sizeof(int) * 1));
        assert(p1.Index() == 1);

        auto p2 = p1++;

        assert(p2 == p1);
        
        assert(p2.Offset() == (sizeof(int) * 1));
        assert(p2.Index() == 1);

        assert(p1.Offset() == (sizeof(int) * 2));
        assert(p1.Index() == 2);

        auto p3 = ++p1;

        assert(p3 == p1);

        assert(p3.Offset() == (sizeof(int) * 3));
        assert(p3.Index() == 3);

        assert(p1.Offset() == (sizeof(int) * 3));
        assert(p1.Index() == 3);

        auto p4 = p1--;
        
        assert(p4 == p1);

        assert(p4.Offset() == (sizeof(int) * 3));
        assert(p4.Index() == 3);

        assert(p1.Offset() == (sizeof(int) * 2));
        assert(p1.Index() == 2);

        auto p5 = --p1;
        
        assert(p5 == p1);

        assert(p5.Offset() == (sizeof(int) * 1));
        assert(p5.Index() == 1);

        assert(p1.Offset() == (sizeof(int) * 1));
        assert(p1.Index() == 1);

        auto p6 = (p1 + 4);

        assert(p6 == p1);
        
        assert(p6.Offset() == (sizeof(int) * 5));
        assert(p6.Index() == 5);

        auto p7 = (p1 - 3);
        
        assert(p7 == p1);

        assert(p7.Offset() == (sizeof(int) * 8));
        assert(p7.Index() == 8);

        auto p8 = p1.StaticCast<const int>();

        assert(p8 == p1);
    
        assert(p8.Size() == 10);
        assert(p8.AllocationSize() == (sizeof(int)* 10));
        assert(p8.StepSize() == sizeof(int));
        assert(p8.Offset() == (sizeof(int) * 1));
        assert(p8.Index() == 1);

        auto p9 = p8.ConstCast<int>();
        
        assert(p9 == p1);
        
        assert(p8.Size() == 10);
        assert(p8.AllocationSize() == (sizeof(int)* 10));
        assert(p8.StepSize() == sizeof(int));
        assert(p9.Offset() == (sizeof(int) * 1));
        assert(p9.Index() == 1);

        auto p10 = p1.ReinterpretCast<char>();
        
        assert(p10 == p1);
        
        assert(p10.Size() == ((sizeof(int)* 10)/ (sizeof(char))));
        assert(p10.AllocationSize() == (sizeof(int)* 10));
        assert(p10.StepSize() == sizeof(char));
        assert(p10.Offset() == (sizeof(int) * 1));
        assert(p10.Index() == (sizeof(int) * 1));

    }
    {
        test::Pointer<Obj1> p1{};
        assert(p1->value == 0);
        assert((*p1).value == 0);
        assert(p1.AllocationSize() == sizeof(Obj1));
        assert(p1.StepSize() == sizeof(Obj1));
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);
        
        (*p1).value = 4;
        assert(p1->value == 4);

        p1->value = 108;
        assert((*p1).value == 108);
        
        test::Pointer<Obj1> p2{p1};
        assert(p2->value == 108);
        assert(p1->value == 108);
        assert(p2 == p1);

        test::Pointer<Obj1> p3{std::move(p2)};
        assert(p3->value == 108);
        assert(p2->value == 0);
        assert(p1->value == 108);
        assert(p3 == p1);
        assert(p3 != p2);

        test::Pointer<Obj1> p4;
        p4 = p3;
        assert(p4->value == 108);
        assert(p3->value == 108);
        assert(p2->value == 0);
        assert(p1->value == 108);
        assert(p4 == p1);
        assert(p4 != p2);
        assert(p4 == p3);
        
        test::Pointer<Obj1> p5;
        p5 = std::move(p4);
        assert(p5->value == 108);
        assert(p4->value == 0);
        assert(p3->value == 108);
        assert(p2->value == 0);
        assert(p1->value == 108);
        assert(p5 == p1);
        assert(p5 != p2);
        assert(p5 == p3);
        assert(p5 != p4);
        
        auto p6 = p5.StaticCast<const Obj1>();
        
        assert(p6->value == 108);
        assert(p6 == p5);

        auto p7 = p6.ConstCast<Obj1>();
        
        assert(p7->value == 108);
        assert(p7 == p6);
        assert(p7 == p5);

        p7->value += 6;
        
        assert(p6->value == 114);
        assert(p7->value == 114);

        auto p8 = p7.ReinterpretCast<char>();

        assert(p8.Size() == sizeof(Obj1) / sizeof(char));
        assert(p8.AllocationSize() == sizeof(Obj1));
        assert(p8.StepSize() == sizeof(char));
        assert(p8 == p7);

    }
    {
        test::Pointer<Obj2, test::ptr::Default<Obj2, &DefaultObj2>> p1{};
        assert(p1->value == DefaultValueObj2);
        assert((*p1).value == DefaultValueObj2);
        assert(p1.AllocationSize() == sizeof(Obj2));
        assert(p1.StepSize() == sizeof(Obj2));
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);
        
        (*p1).value = 4;
        assert(p1->value == 4);

        p1->value = 108;
        assert((*p1).value == 108);
        
        test::Pointer<Obj2, test::ptr::Default<Obj2, &DefaultObj2>> p2{p1};
        assert(p2->value == 108);
        assert(p1->value == 108);
        assert(p2 == p1);

        test::Pointer<Obj2, 
            test::ptr::Default<Obj2, &DefaultObj2>> p3{std::move(p2)};
        assert(p3->value == 108);
        assert(p2->value == DefaultValueObj2);
        assert(p1->value == 108);
        assert(p3 == p1);
        assert(p3 != p2);

        test::Pointer<Obj2, test::ptr::Default<Obj2, &DefaultObj2>> p4;
        p4 = p3;
        assert(p4->value == 108);
        assert(p3->value == 108);
        assert(p2->value == DefaultValueObj2);
        assert(p1->value == 108);
        assert(p4 == p1);
        assert(p4 != p2);
        assert(p4 == p3);
        
        test::Pointer<Obj2, test::ptr::Default<Obj2, &DefaultObj2>> p5;
        p5 = std::move(p4);
        assert(p5->value == 108);
        assert(p4->value == DefaultValueObj2);
        assert(p3->value == 108);
        assert(p2->value == DefaultValueObj2);
        assert(p1->value == 108);
        assert(p5 == p1);
        assert(p5 != p2);
        assert(p5 == p3);
        assert(p5 != p4);
        
        auto p6 = p5.StaticCast<const Obj2>();
        
        assert(p6->value == 108);
        assert(p6 == p5);

        auto p7 = p6.ConstCast<Obj2>();
        
        assert(p7->value == 108);
        assert(p7 == p6);
        assert(p7 == p5);

        p7->value += 6;
        
        assert(p6->value == 114);
        assert(p7->value == 114);

        auto p8 = p7.ReinterpretCast<char>();

        assert(p8.Size() == sizeof(Obj1) / sizeof(char));
        assert(p8.AllocationSize() == sizeof(Obj1));
        assert(p8.StepSize() == sizeof(char));
        assert(p8 == p7);
    }
    {
        test::Pointer<Obj3> p1{};
        auto p1_base = p1.DynamicCast<Obj3Base1>();
        assert(p1->Value() == 0);
        assert(p1_base->Value() == 0);
        assert(p1 == p1_base);
        assert(p1.AllocationSize() == sizeof(Obj3));
        assert(p1.StepSize() == sizeof(Obj3));
        assert(p1.Offset() == 0);
        assert(p1.Index() == 0);
        assert(p1_base.AllocationSize() == sizeof(Obj3));
        assert(p1_base.StepSize() == sizeof(Obj3));
        assert(p1_base.Offset() == 0);
        assert(p1_base.Index() == 0);

        bool t_f_base_1 = 
            TestDynamicCast<Obj1, test::ptr::Default<Obj1>>(p1_base);
        assert(t_f_base_1 == false);
        bool t_f_base_2 = 
            TestDynamicCast<Obj3, test::ptr::Default<Obj3>>(p1_base);
        assert(t_f_base_2 == true);

        p1->Value() = 600;

        assert(p1->Value() == 600);
        assert(p1_base->Value() == 600);

        auto p2_base{p1_base};
        
        assert(p2_base->Value() == 600);
        assert(p2_base == p1_base);
        
        auto p3_base{std::move(p2_base)};
        
        assert(p3_base->Value() == 600);
        assert(p3_base == p1_base);
        assert(p3_base != p2_base);

        decltype(p3_base) p4_base;
        p4_base = p3_base;
        
        assert(p4_base->Value() == 600);
        assert(p4_base == p3_base);

        decltype(p4_base) p5_base;
        p5_base = std::move(p3_base);
        
        assert(p5_base->Value() == 600);
        assert(p5_base == p1_base);
        assert(p5_base != p3_base);

        auto p6_base = p5_base.StaticCast<const Obj3Base1>();
        
        assert(p6_base->Value() == 600);
        assert(p6_base == p5_base);

        auto p7_base = p6_base.ConstCast<Obj3Base1>();
        
        assert(p7_base->Value() == 600);
        assert(p7_base == p6_base);
        assert(p7_base == p5_base);

        p7_base->Value() += 400;
        
        assert(p7_base->Value() == 1000);
        assert(p6_base->Value() == 1000);

        auto p8_base = p7_base.ReinterpretCast<char>();

        assert(p8_base.Size() == sizeof(Obj3) / sizeof(char));
        assert(p8_base.AllocationSize() == sizeof(Obj3));
        assert(p8_base.StepSize() == sizeof(char));
        assert(p8_base == p7_base);
    }
    return TEST::GetInstance().Status().Get();;
}
