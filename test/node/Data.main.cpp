#include "test/node/Data.h"

#include <cassert>

struct Obj1
{
    int val1;
    Obj1() :
        val1{0}
    {}
    Obj1(const int& i) :
        val1{i}
    {}
    Obj1(const Obj1& cpy) :
        val1(cpy.val1)
    {}
    Obj1(Obj1&& mov) :
        val1(mov.val1)
    {
        mov.val1 = 0;
    }
    Obj1& operator=(const Obj1& cpy)
    {
        val1 = cpy.val1;
        return *this;
    }
    Obj1& operator=(Obj1&& mov)
    {
        val1 = mov.val1;
        mov.val1 = 0;
        return *this;
    }
};


int main()
{
    // T = Obj1
    {
        test::node::Data<Obj1> d1;
        assert((*d1).val1 == 0);
        assert(d1->val1 == 0);

        const test::node::Data<Obj1>& cd1 = d1;
        assert((*cd1).val1 == 0);
        assert(cd1->val1 == 0);

        test::node::Data<Obj1> d2{Obj1(4)};
        assert((*d2).val1 == 4);
        assert(d2->val1 == 4);

        const test::node::Data<Obj1>& cd2 = d2;
        assert((*cd2).val1 == 4);
        assert(cd2->val1 == 4);
        
        Obj1 obj1(22);
        test::node::Data<Obj1> d3{std::move(obj1)};
        assert((*d3).val1 == 22);
        assert(d3->val1 == 22);
            
        const test::node::Data<Obj1>& cd3 = d3;
        assert((*cd3).val1 == 22);
        assert(cd3->val1 == 22);

        assert(obj1.val1 == 0);

        test::node::Data<Obj1> d4{144};
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        const test::node::Data<Obj1>& cd4 = d4;
        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<Obj1> d5{d3};
        assert((*d5).val1 == 22);
        assert(d5->val1 == 22);
        
        const test::node::Data<Obj1>& cd5 = d5;
        assert((*cd5).val1 == 22);
        assert(cd5->val1 == 22);

        test::node::Data<Obj1> d6{std::move(d4)};
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        const test::node::Data<Obj1>& cd6 = d6;
        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);
        
        assert((*d4).val1 == 0);
        assert(d4->val1 == 0);

        assert((*cd4).val1 == 0);
        assert(cd4->val1 == 0);

        test::node::Data<Obj1> d7;
        d7 = d3;
        assert((*d7).val1 == 22);
        assert(d7->val1 == 22);

        const test::node::Data<Obj1>& cd7 = d7;
        assert((*cd7).val1 == 22);
        assert(cd7->val1 == 22);

        test::node::Data<Obj1> d8;
        d8 = std::move(d6);
        assert((*d8).val1 == 144);
        assert(d8->val1 == 144);

        const test::node::Data<Obj1>& cd8 = d8;
        assert((*cd8).val1 == 144);
        assert(cd8->val1 == 144);
        
        assert((*d6).val1 == 0);
        assert(d6->val1 == 0);

        assert((*cd6).val1 == 0);
        assert(cd6->val1 == 0);

        Obj1 obj2{123};
        test::node::Data<Obj1> d9;
        d9 = obj2;
        assert((*d9).val1 == 123);
        assert(d9->val1 == 123);

        const test::node::Data<Obj1>& cd9 = d9;
        assert((*cd9).val1 == 123);
        assert(cd9->val1 == 123);
        
        test::node::Data<Obj1> d10;
        d10 = std::move(obj2);
        assert((*d10).val1 == 123);
        assert(d10->val1 == 123);

        const test::node::Data<Obj1>& cd10 = d10;
        assert((*cd10).val1 == 123);
        assert(cd10->val1 == 123);

        assert(obj2.val1 == 0);
    }
    // T = int
    {
        test::node::Data<int> d1;

        test::node::Data<int> d2{8};
        assert(*d2 == 8);
        
        const test::node::Data<int>& cd2 = d2;
        assert(*cd2 == 8);

        test::node::Data<int> d3{std::move(16)};
        assert(*d3 == 16);

        const test::node::Data<int>& cd3 = d3;
        assert(*cd3 == 16);

        test::node::Data<int> d4{d2};
        assert(*d4 == 8);

        const test::node::Data<int>& cd4 = d4;
        assert(*cd4 == 8);
        
        test::node::Data<int> d5{std::move(d3)};
        assert(*d5 == 16);

        const test::node::Data<int>& cd5 = d5;
        assert(*cd5 == 16);

        test::node::Data<int> d6;
        d6 = d2;
        assert(*d6 == 8);

        const test::node::Data<int>& cd6 = d6;
        assert(*cd6 == 8);

        test::node::Data<int> d7;
        d7 = std::move(d6);
        assert(*d7== 8);

        const test::node::Data<int>& cd7 = d7;
        assert(*cd7 == 8);

        test::node::Data<int> d8;
        d8 = 16;
        assert(*d8 == 16);

        const test::node::Data<int>& cd8 = d8;
        assert(*cd8 == 16);

        test::node::Data<int> d9;
        d9 = std::move(116);
        assert(*d9 == 116);

        const test::node::Data<int>& cd9 = d9;
        assert(*cd9 == 116);
        
    }
    //T = const Obj1
    {
        test::node::Data<const Obj1> d1;
        assert((*d1).val1 == 0);
        assert(d1->val1 == 0);

        const test::node::Data<const Obj1>& cd1 = d1;
        assert((*cd1).val1 == 0);
        assert(cd1->val1 == 0);
        
        test::node::Data<const Obj1> d2{Obj1{5}};
        assert((*d2).val1 == 5);
        assert(d2->val1 == 5);

        const test::node::Data<const Obj1>& cd2 = d2;
        assert((*cd2).val1 == 5);
        assert(cd2->val1 == 5);
        
        Obj1 obj1{15};
        test::node::Data<const Obj1> d3{std::move(obj1)};
        assert((*d3).val1 == 15);
        assert(d3->val1 == 15);

        const test::node::Data<const Obj1>& cd3 = d3;
        assert((*cd3).val1 == 15);
        assert(cd3->val1 == 15);

        assert(obj1.val1 == 0);

        test::node::Data<const Obj1> d4{255};
        assert((*d4).val1 == 255);
        assert(d4->val1 == 255);

        const test::node::Data<const Obj1>& cd4 = d4;
        assert((*cd4).val1 == 255);
        assert(cd4->val1 == 255);

        test::node::Data<const Obj1> d5{d2};
        assert((*d5).val1 == 5);
        assert(d5->val1 == 5);

        const test::node::Data<const Obj1>& cd5 = d5;
        assert((*cd5).val1 == 5);
        assert(cd5->val1 == 5);

        test::node::Data<const Obj1> d6{std::move(d3)};
        assert((*d6).val1 == 15);
        assert(d6->val1 == 15);

        const test::node::Data<const Obj1>& cd6 = d6;
        assert((*cd6).val1 == 15);
        assert(cd6->val1 == 15);
        
        assert((*d3).val1 == 15);
        assert(d3->val1 == 15);

        assert((*cd3).val1 == 15);
        assert(cd3->val1 == 15);

        test::node::Data<const Obj1> d7;
        d7 = d5;
        assert((*d7).val1 == 0);
        assert(d7->val1 == 0);

        const test::node::Data<const Obj1>& cd7 = d7;
        assert((*cd7).val1 == 0);
        assert(cd7->val1 == 0);
        
        test::node::Data<const Obj1> d8;
        d8 = std::move(d6);
        assert((*d8).val1 == 0);
        assert(d8->val1 == 0);

        const test::node::Data<const Obj1>& cd8 = d8;
        assert((*cd8).val1 == 0);
        assert(cd8->val1 == 0);
        
        assert((*d6).val1 == 15);
        assert(d6->val1 == 15);
        assert((*cd6).val1 == 15);
        assert(cd6->val1 == 15);

        test::node::Data<const Obj1> d9;
        d9 = Obj1{17};
        assert((*d9).val1 == 0);
        assert(d9->val1 == 0);

        const test::node::Data<const Obj1>& cd9 = d9;
        assert((*cd9).val1 == 0);
        assert(cd9->val1 == 0);
        
        Obj1 obj2{222};
        test::node::Data<const Obj1> d10;
        d10 = std::move(obj2);
        assert((*d10).val1 == 0);
        assert(d10->val1 == 0);

        const test::node::Data<const Obj1>& cd10 = d10;
        assert((*cd10).val1 == 0);
        assert(cd10->val1 == 0);

        assert(obj2.val1 == 222);

    }
    // T = const int
    {
        test::node::Data<const int> d1;

        test::node::Data<const int> d2{8};
        assert(*d2 == 8);
        
        const test::node::Data<const int>& cd2 = d2;
        assert(*cd2 == 8);

        test::node::Data<const int> d3{std::move(16)};
        assert(*d3 == 16);

        const test::node::Data<const int>& cd3 = d3;
        assert(*cd3 == 16);

        test::node::Data<const int> d4{d2};
        assert(*d4 == 8);

        const test::node::Data<const int>& cd4 = d4;
        assert(*cd4 == 8);
        
        test::node::Data<const int> d5{std::move(d3)};
        assert(*d5 == 16);

        const test::node::Data<const int>& cd5 = d5;
        assert(*cd5 == 16);

        test::node::Data<const int> d6{0};
        d6 = d2;
        assert(*d6 == 0);

        const test::node::Data<const int>& cd6 = d6;
        assert(*cd6 == 0);

        test::node::Data<const int> d7{0};
        d7 = std::move(d6);
        assert(*d7== 0);

        const test::node::Data<const int>& cd7 = d7;
        assert(*cd7 == 0);

        test::node::Data<const int> d8{0};
        d8 = 16;
        assert(*d8 == 0);

        const test::node::Data<const int>& cd8 = d8;
        assert(*cd8 == 0);

        test::node::Data<const int> d9{0};
        d9 = std::move(116);
        assert(*d9 == 0);

        const test::node::Data<const int>& cd9 = d9;
        assert(*cd9 == 0);
    }
    // T = Obj1 *
    {
        test::node::Data<Obj1*> d1;
        assert((*d1).val1 == 0);
        assert(d1->val1 == 0);

        const test::node::Data<Obj1*>& cd1 = d1;
        assert((*cd1).val1 == 0);
        assert(cd1->val1 == 0);

        test::node::Data<Obj1*> d2{Obj1(4)};
        assert((*d2).val1 == 4);
        assert(d2->val1 == 4);

        const test::node::Data<Obj1*>& cd2 = d2;
        assert((*cd2).val1 == 4);
        assert(cd2->val1 == 4);
        
        Obj1 obj1(22);
        test::node::Data<Obj1*> d3{std::move(obj1)};
        assert((*d3).val1 == 22);
        assert(d3->val1 == 22);
            
        const test::node::Data<Obj1*>& cd3 = d3;
        assert((*cd3).val1 == 22);
        assert(cd3->val1 == 22);

        assert(obj1.val1 == 0);

        test::node::Data<Obj1*> d4{144};
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        const test::node::Data<Obj1*>& cd4 = d4;
        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<Obj1*> d5{d3};
        assert((*d5).val1 == 22);
        assert(d5->val1 == 22);
        
        const test::node::Data<Obj1*>& cd5 = d5;
        assert((*cd5).val1 == 22);
        assert(cd5->val1 == 22);

        test::node::Data<Obj1*> d6{std::move(d4)};
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        const test::node::Data<Obj1*>& cd6 = d6;
        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);
        
        assert((*d4).val1 == 0);
        assert(d4->val1 == 0);

        assert((*cd4).val1 == 0);
        assert(cd4->val1 == 0);

        test::node::Data<Obj1*> d7;
        d7 = d3;
        assert((*d7).val1 == 22);
        assert(d7->val1 == 22);

        const test::node::Data<Obj1*>& cd7 = d7;
        assert((*cd7).val1 == 22);
        assert(cd7->val1 == 22);

        test::node::Data<Obj1*> d8;
        d8 = std::move(d6);
        assert((*d8).val1 == 144);
        assert(d8->val1 == 144);

        const test::node::Data<Obj1*>& cd8 = d8;
        assert((*cd8).val1 == 144);
        assert(cd8->val1 == 144);
        
        assert((*d6).val1 == 0);
        assert(d6->val1 == 0);

        assert((*cd6).val1 == 0);
        assert(cd6->val1 == 0);

        Obj1 obj2{123};
        test::node::Data<Obj1*> d9;
        d9 = obj2;
        assert((*d9).val1 == 123);
        assert(d9->val1 == 123);

        const test::node::Data<Obj1*>& cd9 = d9;
        assert((*cd9).val1 == 123);
        assert(cd9->val1 == 123);
        
        test::node::Data<Obj1*> d10;
        d10 = std::move(obj2);
        assert((*d10).val1 == 123);
        assert(d10->val1 == 123);

        const test::node::Data<Obj1*>& cd10 = d10;
        assert((*cd10).val1 == 123);
        assert(cd10->val1 == 123);

        assert(obj2.val1 == 0);
    }
    // T= int *
    {
        test::node::Data<int*> d1;

        test::node::Data<int*> d2{8};
        assert(*d2 == 8);
        
        const test::node::Data<int*>& cd2 = d2;
        assert(*cd2 == 8);

        test::node::Data<int*> d3{std::move(16)};
        assert(*d3 == 16);

        const test::node::Data<int*>& cd3 = d3;
        assert(*cd3 == 16);

        test::node::Data<int*> d4{d2};
        assert(*d4 == 8);

        const test::node::Data<int*>& cd4 = d4;
        assert(*cd4 == 8);
        
        test::node::Data<int*> d5{std::move(d3)};
        assert(*d5 == 16);

        const test::node::Data<int*>& cd5 = d5;
        assert(*cd5 == 16);

        test::node::Data<int*> d6;
        d6 = d2;
        assert(*d6 == 8);

        const test::node::Data<int*>& cd6 = d6;
        assert(*cd6 == 8);

        test::node::Data<int*> d7;
        d7 = std::move(d6);
        assert(*d7== 8);

        const test::node::Data<int*>& cd7 = d7;
        assert(*cd7 == 8);

        test::node::Data<int*> d8;
        d8 = 16;
        assert(*d8 == 16);

        const test::node::Data<int*>& cd8 = d8;
        assert(*cd8 == 16);

        test::node::Data<int*> d9;
        d9 = std::move(116);
        assert(*d9 == 116);

        const test::node::Data<int*>& cd9 = d9;
        assert(*cd9 == 116);
    }
    // T = const Obj1*
    {
        test::node::Data<const Obj1*> d1;
        assert((*d1).val1 == 0);
        assert(d1->val1 == 0);

        const test::node::Data<const Obj1*>& cd1 = d1;
        assert((*cd1).val1 == 0);
        assert(cd1->val1 == 0);

        test::node::Data<const Obj1*> d2{Obj1(4)};
        assert((*d2).val1 == 4);
        assert(d2->val1 == 4);

        const test::node::Data<const Obj1*>& cd2 = d2;
        assert((*cd2).val1 == 4);
        assert(cd2->val1 == 4);
        
        Obj1 obj1(22);
        test::node::Data<const Obj1*> d3{std::move(obj1)};
        assert((*d3).val1 == 22);
        assert(d3->val1 == 22);
            
        const test::node::Data<const Obj1*>& cd3 = d3;
        assert((*cd3).val1 == 22);
        assert(cd3->val1 == 22);

        assert(obj1.val1 == 0);

        test::node::Data<const Obj1*> d4{144};
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        const test::node::Data<const Obj1*>& cd4 = d4;
        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<const Obj1*> d5{d3};
        assert((*d5).val1 == 22);
        assert(d5->val1 == 22);
        
        const test::node::Data<const Obj1*>& cd5 = d5;
        assert((*cd5).val1 == 22);
        assert(cd5->val1 == 22);

        test::node::Data<const Obj1*> d6{std::move(d4)};
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        const test::node::Data<const Obj1*>& cd6 = d6;
        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);
        
        assert((*d4).val1 == 0);
        assert(d4->val1 == 0);

        assert((*cd4).val1 == 0);
        assert(cd4->val1 == 0);

        test::node::Data<const Obj1*> d7;
        d7 = d3;
        assert((*d7).val1 == 22);
        assert(d7->val1 == 22);

        const test::node::Data<const Obj1*>& cd7 = d7;
        assert((*cd7).val1 == 22);
        assert(cd7->val1 == 22);

        test::node::Data<const Obj1*> d8;
        d8 = std::move(d6);
        assert((*d8).val1 == 144);
        assert(d8->val1 == 144);

        const test::node::Data<const Obj1*>& cd8 = d8;
        assert((*cd8).val1 == 144);
        assert(cd8->val1 == 144);
        
        assert((*d6).val1 == 0);
        assert(d6->val1 == 0);

        assert((*cd6).val1 == 0);
        assert(cd6->val1 == 0);

        Obj1 obj2{123};
        test::node::Data<const Obj1*> d9;
        d9 = obj2;
        assert((*d9).val1 == 123);
        assert(d9->val1 == 123);

        const test::node::Data<const Obj1*>& cd9 = d9;
        assert((*cd9).val1 == 123);
        assert(cd9->val1 == 123);
        
        test::node::Data<const Obj1*> d10;
        d10 = std::move(obj2);
        assert((*d10).val1 == 123);
        assert(d10->val1 == 123);

        const test::node::Data<const Obj1*>& cd10 = d10;
        assert((*cd10).val1 == 123);
        assert(cd10->val1 == 123);

        assert(obj2.val1 == 0);
    }
    // T = const int *
    {
        test::node::Data<const int*> d1;

        test::node::Data<const int*> d2{8};
        assert(*d2 == 8);
        
        const test::node::Data<const int*>& cd2 = d2;
        assert(*cd2 == 8);

        test::node::Data<const int*> d3{std::move(16)};
        assert(*d3 == 16);

        const test::node::Data<const int*>& cd3 = d3;
        assert(*cd3 == 16);

        test::node::Data<const int*> d4{d2};
        assert(*d4 == 8);

        const test::node::Data<const int*>& cd4 = d4;
        assert(*cd4 == 8);
        
        test::node::Data<const int*> d5{std::move(d3)};
        assert(*d5 == 16);

        const test::node::Data<const int*>& cd5 = d5;
        assert(*cd5 == 16);

        test::node::Data<const int*> d6;
        d6 = d2;
        assert(*d6 == 8);

        const test::node::Data<const int*>& cd6 = d6;
        assert(*cd6 == 8);

        test::node::Data<const int*> d7;
        d7 = std::move(d6);
        assert(*d7== 8);

        const test::node::Data<const int*>& cd7 = d7;
        assert(*cd7 == 8);

        test::node::Data<const int*> d8;
        d8 = 16;
        assert(*d8 == 16);

        const test::node::Data<const int*>& cd8 = d8;
        assert(*cd8 == 16);

        test::node::Data<const int*> d9;
        d9 = std::move(116);
        assert(*d9 == 116);

        const test::node::Data<const int*>& cd9 = d9;
        assert(*cd9 == 116);
    }   
    // T= Obj1 * const 
    {
        test::node::Data<Obj1*const> d1;
        assert((*d1).val1 == 0);
        assert(d1->val1 == 0);

        const test::node::Data<Obj1*const>& cd1 = d1;
        assert((*cd1).val1 == 0);
        assert(cd1->val1 == 0);

        test::node::Data<Obj1*const> d2{Obj1(4)};
        assert((*d2).val1 == 4);
        assert(d2->val1 == 4);

        const test::node::Data<Obj1*const>& cd2 = d2;
        assert((*cd2).val1 == 4);
        assert(cd2->val1 == 4);
        
        Obj1 obj1(22);
        test::node::Data<Obj1*const> d3{std::move(obj1)};
        assert((*d3).val1 == 22);
        assert(d3->val1 == 22);
            
        const test::node::Data<Obj1*const>& cd3 = d3;
        assert((*cd3).val1 == 22);
        assert(cd3->val1 == 22);

        assert(obj1.val1 == 0);

        test::node::Data<Obj1*const> d4{144};
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        const test::node::Data<Obj1*const>& cd4 = d4;
        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<Obj1*const> d5{d3};
        assert((*d5).val1 == 22);
        assert(d5->val1 == 22);
        
        const test::node::Data<Obj1*const>& cd5 = d5;
        assert((*cd5).val1 == 22);
        assert(cd5->val1 == 22);

        test::node::Data<Obj1*const> d6{std::move(d4)};
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        const test::node::Data<Obj1*const>& cd6 = d6;
        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);
        
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<Obj1*const> d7;
        d7 = d3;
        assert((*d7).val1 == 0);
        assert(d7->val1 == 0);

        const test::node::Data<Obj1*const>& cd7 = d7;
        assert((*cd7).val1 == 0);
        assert(cd7->val1 == 0);

        test::node::Data<Obj1*const> d8;
        d8 = std::move(d6);
        assert((*d8).val1 == 0);
        assert(d8->val1 == 0);

        const test::node::Data<Obj1*const>& cd8 = d8;
        assert((*cd8).val1 == 0);
        assert(cd8->val1 == 0);
        
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);

        Obj1 obj2{123};
        test::node::Data<Obj1*const> d9;
        d9 = obj2;
        assert((*d9).val1 == 0);
        assert(d9->val1 == 0);

        const test::node::Data<Obj1*const>& cd9 = d9;
        assert((*cd9).val1 == 0);
        assert(cd9->val1 == 0);
        
        test::node::Data<Obj1*const> d10;
        d10 = std::move(obj2);
        assert((*d10).val1 == 0);
        assert(d10->val1 == 0);

        const test::node::Data<Obj1*const>& cd10 = d10;
        assert((*cd10).val1 == 0);
        assert(cd10->val1 == 0);

        assert(obj2.val1 == 123);
    }
    // T = int*const
    {
        test::node::Data<int*const> d1;

        test::node::Data<int*const> d2{8};
        assert(*d2 == 8);
        
        const test::node::Data<int*const>& cd2 = d2;
        assert(*cd2 == 8);

        test::node::Data<int*const> d3{std::move(16)};
        assert(*d3 == 16);

        const test::node::Data<int*const>& cd3 = d3;
        assert(*cd3 == 16);

        test::node::Data<int*const> d4{d2};
        assert(*d4 == 8);

        const test::node::Data<int*const>& cd4 = d4;
        assert(*cd4 == 8);
        
        test::node::Data<int*const> d5{std::move(d3)};
        assert(*d5 == 16);

        const test::node::Data<int*const>& cd5 = d5;
        assert(*cd5 == 16);

        test::node::Data<int*const> d6{0};
        d6 = d2;
        assert(*d6 == 0);

        const test::node::Data<int*const>& cd6 = d6;
        assert(*cd6 == 0);

        test::node::Data<int*const> d7{0};
        d7 = std::move(d6);
        assert(*d7== 0);

        const test::node::Data<int*const>& cd7 = d7;
        assert(*cd7 == 0);

        test::node::Data<int*const> d8{0};
        d8 = 16;
        assert(*d8 == 0);

        const test::node::Data<int*const>& cd8 = d8;
        assert(*cd8 == 0);

        test::node::Data<int*const> d9{0};
        d9 = std::move(116);
        assert(*d9 == 0);

        const test::node::Data<int*const>& cd9 = d9;
        assert(*cd9 == 0);
    }
    // T = const Obj1* const
    {
        test::node::Data<const Obj1*const> d1;
        assert((*d1).val1 == 0);
        assert(d1->val1 == 0);

        const test::node::Data<const Obj1*const>& cd1 = d1;
        assert((*cd1).val1 == 0);
        assert(cd1->val1 == 0);

        test::node::Data<const Obj1*const> d2{Obj1(4)};
        assert((*d2).val1 == 4);
        assert(d2->val1 == 4);

        const test::node::Data<const Obj1*const>& cd2 = d2;
        assert((*cd2).val1 == 4);
        assert(cd2->val1 == 4);
        
        Obj1 obj1(22);
        test::node::Data<const Obj1*const> d3{std::move(obj1)};
        assert((*d3).val1 == 22);
        assert(d3->val1 == 22);
            
        const test::node::Data<const Obj1*const>& cd3 = d3;
        assert((*cd3).val1 == 22);
        assert(cd3->val1 == 22);

        assert(obj1.val1 == 0);

        test::node::Data<const Obj1*const> d4{144};
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        const test::node::Data<const Obj1*const>& cd4 = d4;
        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<const Obj1*const> d5{d3};
        assert((*d5).val1 == 22);
        assert(d5->val1 == 22);
        
        const test::node::Data<const Obj1*const>& cd5 = d5;
        assert((*cd5).val1 == 22);
        assert(cd5->val1 == 22);

        test::node::Data<const Obj1*const> d6{std::move(d4)};
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        const test::node::Data<const Obj1*const>& cd6 = d6;
        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);
        
        assert((*d4).val1 == 144);
        assert(d4->val1 == 144);

        assert((*cd4).val1 == 144);
        assert(cd4->val1 == 144);

        test::node::Data<const Obj1*const> d7;
        d7 = d3;
        assert((*d7).val1 == 0);
        assert(d7->val1 == 0);

        const test::node::Data<const Obj1*const>& cd7 = d7;
        assert((*cd7).val1 == 0);
        assert(cd7->val1 == 0);

        test::node::Data<const Obj1*const> d8;
        d8 = std::move(d6);
        assert((*d8).val1 == 0);
        assert(d8->val1 == 0);

        const test::node::Data<const Obj1*const>& cd8 = d8;
        assert((*cd8).val1 == 0);
        assert(cd8->val1 == 0);
        
        assert((*d6).val1 == 144);
        assert(d6->val1 == 144);

        assert((*cd6).val1 == 144);
        assert(cd6->val1 == 144);

        Obj1 obj2{123};
        test::node::Data<const Obj1*const> d9;
        d9 = obj2;
        assert((*d9).val1 == 0);
        assert(d9->val1 == 0);

        const test::node::Data<const Obj1*const>& cd9 = d9;
        assert((*cd9).val1 == 0);
        assert(cd9->val1 == 0);
        
        test::node::Data<const Obj1*const> d10;
        d10 = std::move(obj2);
        assert((*d10).val1 == 0);
        assert(d10->val1 == 0);

        const test::node::Data<const Obj1*const>& cd10 = d10;
        assert((*cd10).val1 == 0);
        assert(cd10->val1 == 0);

        assert(obj2.val1 == 123);
    }
    // T = const int * const
    {
        test::node::Data<const int*const> d1;

        test::node::Data<const int*const> d2{8};
        assert(*d2 == 8);
        
        const test::node::Data<const int*const>& cd2 = d2;
        assert(*cd2 == 8);

        test::node::Data<const int*const> d3{std::move(16)};
        assert(*d3 == 16);

        const test::node::Data<const int*const>& cd3 = d3;
        assert(*cd3 == 16);

        test::node::Data<const int*const> d4{d2};
        assert(*d4 == 8);

        const test::node::Data<const int*const>& cd4 = d4;
        assert(*cd4 == 8);
        
        test::node::Data<const int*const> d5{std::move(d3)};
        assert(*d5 == 16);

        const test::node::Data<const int*const>& cd5 = d5;
        assert(*cd5 == 16);

        test::node::Data<const int*const> d6{0};
        d6 = d2;
        assert(*d6 == 0);

        const test::node::Data<const int*const>& cd6 = d6;
        assert(*cd6 == 0);

        test::node::Data<const int*const> d7{0};
        d7 = std::move(d6);
        assert(*d7== 0);

        const test::node::Data<const int*const>& cd7 = d7;
        assert(*cd7 == 0);

        test::node::Data<const int*const> d8{0};
        d8 = 16;
        assert(*d8 == 0);

        const test::node::Data<const int*const>& cd8 = d8;
        assert(*cd8 == 0);

        test::node::Data<const int*const> d9{0};
        d9 = std::move(116);
        assert(*d9 == 0);

        const test::node::Data<const int*const>& cd9 = d9;
        assert(*cd9 == 0);
    }

    return 1;
}