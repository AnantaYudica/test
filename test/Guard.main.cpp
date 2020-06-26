#include "test/Guard.h"
#include <cassert>

struct Obj1
{
    bool call_begin;
    bool call_end;
private:
    bool Begin1()
    {
        call_begin = true;
        return true;
    }
    bool Begin2()
    {
        call_begin = true;
        return false;
    }
private:
    void End()
    {
        call_end = true;
    }
public:
    test::Guard<Obj1> Guard1()
    {
        return {this, &Obj1::Begin1};
    }
    test::Guard<Obj1> Guard2()
    {
        return {this, &Obj1::Begin1, &Obj1::End};
    }
    test::Guard<Obj1> Guard3()
    {
        return {this, &Obj1::Begin2};
    }
    test::Guard<Obj1> Guard4()
    {
        return {this, &Obj1::Begin2, &Obj1::End};
    }
    test::Guard<Obj1> Guard5()
    {
        return {nullptr, &Obj1::Begin1};
    }
    test::Guard<Obj1> Guard6()
    {
        return {this, nullptr};
    }
    test::Guard<Obj1> Guard7()
    {
        return {nullptr, nullptr};
    }
    test::Guard<Obj1> Guard8()
    {
        return {nullptr, &Obj1::Begin1, &Obj1::End};
    }
    test::Guard<Obj1> Guard9()
    {
        return {this, &Obj1::Begin1, nullptr};
    }
    test::Guard<Obj1> Guard10()
    {
        return {this, nullptr, nullptr};
    }
    test::Guard<Obj1> Guard11()
    {
        return {this, nullptr, &Obj1::End};
    }
    test::Guard<Obj1> Guard12()
    {
        return {nullptr, nullptr, nullptr};
    }
public:
    Obj1() : 
        call_begin(false),
        call_end(false) 
    {}
};

int main()
{
    Obj1 obj1_1;
    {
        auto guard = obj1_1.Guard1();
        assert(obj1_1.call_begin == true);
        assert((bool)guard == true);
    }
    assert(obj1_1.call_end == false);

    Obj1 obj1_2;
    {
        auto guard = obj1_2.Guard2();
        assert(obj1_2.call_begin == true);
        assert((bool)guard == true);
    }
    assert(obj1_2.call_end == true);

    Obj1 obj1_3;
    {
        auto guard = obj1_3.Guard3();
        assert(obj1_3.call_begin == true);
        assert((bool)guard == false);
    }
    assert(obj1_3.call_end == false);

    Obj1 obj1_4;
    {
        auto guard = obj1_4.Guard4();
        assert(obj1_4.call_begin == true);
        assert((bool)guard == false);
    }
    assert(obj1_4.call_end == false);
    
    Obj1 obj1_5;
    {
        auto guard = obj1_5.Guard5();
        assert(obj1_5.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_5.call_end == false);
    
    Obj1 obj1_6;
    {
        auto guard = obj1_6.Guard6();
        assert(obj1_6.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_6.call_end == false);

    Obj1 obj1_7;
    {
        auto guard = obj1_7.Guard7();
        assert(obj1_7.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_7.call_end == false);

    Obj1 obj1_8;
    {
        auto guard = obj1_8.Guard8();
        assert(obj1_8.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_8.call_end == false);

    Obj1 obj1_9;
    {
        auto guard = obj1_9.Guard9();
        assert(obj1_9.call_begin == true);
        assert((bool)guard == true);
    }
    assert(obj1_9.call_end == false);

    Obj1 obj1_10;
    {
        auto guard = obj1_10.Guard10();
        assert(obj1_10.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_10.call_end == false);

    Obj1 obj1_11;
    {
        auto guard = obj1_11.Guard11();
        assert(obj1_11.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_11.call_end == false);
    
    Obj1 obj1_12;
    {
        auto guard = obj1_12.Guard12();
        assert(obj1_12.call_begin == false);
        assert((bool)guard == false);
    }
    assert(obj1_12.call_end == false);

    return 1;
}