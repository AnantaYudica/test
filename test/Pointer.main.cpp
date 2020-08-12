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

int main()
{
    {
        test::Pointer<int> p1{0};
        assert(*p1 == 0);

        *p1 = 4;
        assert(*p1 == 4);

        test::Pointer<int> p2{p1};
        assert(*p2 == 4);
        assert(*p1 == 4);
        assert(p2 == p1);

        test::Pointer<int> p3{std::move(p2)};
        assert(*p3 == 4);
        assert(*p2 != 4);
        assert(*p1 == 4);
        assert(p3 == p1);
        assert(p3 != p2);

        test::Pointer<int> p4;
        p4 = p3;
        assert(*p4 == 4);
        assert(*p3 == 4);
        assert(*p2 != 4);
        assert(*p1 == 4);
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
        assert(p5 == p1);
        assert(p5 != p2);
        assert(p5 == p3);
        assert(p5 != p4);
    }
    {
        test::Pointer<Obj1> p1{};
        assert(p1->value == 0);
        assert((*p1).value == 0);
        
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
    }
    {
        test::Pointer<Obj2, &DefaultObj2> p1{};
        assert(p1->value == DefaultValueObj2);
        assert((*p1).value == DefaultValueObj2);
        
        (*p1).value = 4;
        assert(p1->value == 4);

        p1->value = 108;
        assert((*p1).value == 108);
        
        test::Pointer<Obj2, &DefaultObj2> p2{p1};
        assert(p2->value == 108);
        assert(p1->value == 108);
        assert(p2 == p1);

        test::Pointer<Obj2, &DefaultObj2> p3{std::move(p2)};
        assert(p3->value == 108);
        assert(p2->value == DefaultValueObj2);
        assert(p1->value == 108);
        assert(p3 == p1);
        assert(p3 != p2);

        test::Pointer<Obj2, &DefaultObj2> p4;
        p4 = p3;
        assert(p4->value == 108);
        assert(p3->value == 108);
        assert(p2->value == DefaultValueObj2);
        assert(p1->value == 108);
        assert(p4 == p1);
        assert(p4 != p2);
        assert(p4 == p3);
        
        test::Pointer<Obj2, &DefaultObj2> p5;
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
    }

    return TEST::GetInstance().Status().Get();;
}