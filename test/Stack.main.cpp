#include "test/Stack.h"

#include <cstdio>
#include <cassert>

static int count = 0;

struct Obj1
{
    int val1;
    Obj1() : val1(0)
    {
        count++;
    }
    Obj1(const int& i) : val1(i)
    {
        count++;
    }
    Obj1(const int& i, const int& j) : val1(i + j)
    {
        count++;
    }
    Obj1(const Obj1& cpy) : val1(cpy.val1)
    {
        count++;
    }
    Obj1(Obj1&& mov) : val1(mov.val1)
    {
        mov.val1 = 0;
        count++;
    }
    ~Obj1()
    {
        val1 = 0;
        count--;   
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
    {
        test::Stack<Obj1> stack1;
        const test::Stack<Obj1>& cstack1 = stack1;

        assert(stack1.Size() == 0);
        assert(cstack1.Size() == 0);

        auto push1 = stack1.Push(Obj1{1});

        assert(push1->val1 == 1);

        assert(stack1.Size() == 1);
        assert(cstack1.Size() == 1);
        assert(stack1.Top().val1 == 1);
        assert(cstack1.Top().val1 == 1);

        Obj1 obj1_1{2};
        auto push2 = stack1.Push(std::move(obj1_1));

        assert(push2->val1 == 2);

        assert(stack1.Size() == 2);
        assert(cstack1.Size() == 2);
        assert(stack1.Top().val1 == 2);
        assert(cstack1.Top().val1 == 2);
        
        assert(obj1_1.val1 == 0);

        auto push3 = stack1.Push(1, 2);
        
        assert(push3->val1 == 3);

        assert(stack1.Size() == 3);
        assert(cstack1.Size() == 3);
        assert(stack1.Top().val1 == 3);
        assert(cstack1.Top().val1 == 3);

        {
            test::Stack<Obj1> stack1_cpy{stack1};
            const test::Stack<Obj1>& cstack1_cpy{stack1_cpy};

            auto pop = stack1_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack1_cpy.Size() == 2);
            assert(cstack1_cpy.Size() == 2);
            assert(stack1_cpy.Top().val1 == 2);
            assert(cstack1_cpy.Top().val1 == 2);
            
            pop = stack1_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack1_cpy.Size() == 1);
            assert(cstack1_cpy.Size() == 1);
            assert(stack1_cpy.Top().val1 == 1);
            assert(cstack1_cpy.Top().val1 == 1);
            
            pop = stack1_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack1_cpy.Size() == 0);
            assert(cstack1_cpy.Size() == 0);
            assert(stack1_cpy.Top().val1 == 0);
            assert(cstack1_cpy.Top().val1 == 0);
        }

        test::Stack<Obj1> stack2{stack1};
        const test::Stack<Obj1>& cstack2 = stack2;
        
        assert(stack2.Size() == 3);
        assert(cstack2.Size() == 3);
        assert(stack2.Top().val1 == 3);
        assert(cstack2.Top().val1 == 3);
        
        {
            test::Stack<Obj1> stack2_cpy{stack2};
            const test::Stack<Obj1>& cstack2_cpy{stack2_cpy};

            auto pop = stack2_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack2_cpy.Size() == 2);
            assert(cstack2_cpy.Size() == 2);
            assert(stack2_cpy.Top().val1 == 2);
            assert(cstack2_cpy.Top().val1 == 2);
            
            pop = stack2_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack2_cpy.Size() == 1);
            assert(cstack2_cpy.Size() == 1);
            assert(stack2_cpy.Top().val1 == 1);
            assert(cstack2_cpy.Top().val1 == 1);
            
            pop = stack2_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack2_cpy.Size() == 0);
            assert(cstack2_cpy.Size() == 0);
            assert(stack2_cpy.Top().val1 == 0);
            assert(cstack2_cpy.Top().val1 == 0);
        }
        
        test::Stack<Obj1> stack3{std::move(stack2)};
        const test::Stack<Obj1>& cstack3 = stack3;

        assert(stack3.Size() == 3);
        assert(cstack3.Size() == 3);
        assert(stack3.Top().val1 == 3);
        assert(cstack3.Top().val1 == 3);

        assert(stack2.Size() == 0);
        assert(cstack2.Size() == 0);
        assert(stack2.Top().val1 == 0);
        assert(cstack2.Top().val1 == 0);
        {
            test::Stack<Obj1> stack3_cpy{stack3};
            const test::Stack<Obj1>& cstack3_cpy{stack3_cpy};

            auto pop = stack3_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack3_cpy.Size() == 2);
            assert(cstack3_cpy.Size() == 2);
            assert(stack3_cpy.Top().val1 == 2);
            assert(cstack3_cpy.Top().val1 == 2);
            
            pop = stack3_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack3_cpy.Size() == 1);
            assert(cstack3_cpy.Size() == 1);
            assert(stack3_cpy.Top().val1 == 1);
            assert(cstack3_cpy.Top().val1 == 1);
            
            pop = stack3_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack3_cpy.Size() == 0);
            assert(cstack3_cpy.Size() == 0);
            assert(stack3_cpy.Top().val1 == 0);
            assert(cstack3_cpy.Top().val1 == 0);
        }
        
        test::Stack<Obj1> stack4;
        const test::Stack<Obj1>& cstack4 = stack4;
        stack4 = stack1;
        
        assert(stack4.Size() == 3);
        assert(cstack4.Size() == 3);
        assert(stack4.Top().val1 == 3);
        assert(cstack4.Top().val1 == 3);

        {
            test::Stack<Obj1> stack4_cpy{stack4};
            const test::Stack<Obj1>& cstack4_cpy{stack4_cpy};

            auto pop = stack4_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack4_cpy.Size() == 2);
            assert(cstack4_cpy.Size() == 2);
            assert(stack4_cpy.Top().val1 == 2);
            assert(cstack4_cpy.Top().val1 == 2);
            
            pop = stack4_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack4_cpy.Size() == 1);
            assert(cstack4_cpy.Size() == 1);
            assert(stack4_cpy.Top().val1 == 1);
            assert(cstack4_cpy.Top().val1 == 1);
            
            pop = stack4_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack4_cpy.Size() == 0);
            assert(cstack4_cpy.Size() == 0);
            assert(stack4_cpy.Top().val1 == 0);
            assert(cstack4_cpy.Top().val1 == 0);
        }

        test::Stack<Obj1> stack5;
        const test::Stack<Obj1>& cstack5 = stack5;
        stack5 = std::move(stack4);
        
        assert(stack5.Size() == 3);
        assert(cstack5.Size() == 3);
        assert(stack5.Top().val1 == 3);
        assert(cstack5.Top().val1 == 3);

        assert(stack4.Size() == 0);
        assert(cstack4.Size() == 0);
        assert(stack4.Top().val1 == 0);
        assert(cstack4.Top().val1 == 0);
        {
            test::Stack<Obj1> stack5_cpy{stack5};
            const test::Stack<Obj1>& cstack5_cpy{stack5_cpy};

            auto pop = stack5_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack5_cpy.Size() == 2);
            assert(cstack5_cpy.Size() == 2);
            assert(stack5_cpy.Top().val1 == 2);
            assert(cstack5_cpy.Top().val1 == 2);
            
            pop = stack5_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack5_cpy.Size() == 1);
            assert(cstack5_cpy.Size() == 1);
            assert(stack5_cpy.Top().val1 == 1);
            assert(cstack5_cpy.Top().val1 == 1);
            
            pop = stack5_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack5_cpy.Size() == 0);
            assert(cstack5_cpy.Size() == 0);
            assert(stack5_cpy.Top().val1 == 0);
            assert(cstack5_cpy.Top().val1 == 0);
        }
        
        test::Stack<Obj1> stack6;
        const test::Stack<Obj1>& cstack6 = stack6;
        stack6.Push(4);
        stack6.Push(5);
        stack6.Push(6);
        
        test::Stack<Obj1> stack7{stack1};
        const test::Stack<Obj1>& cstack7 = stack7;
        auto res = stack7.Push(stack6);
        
        assert(res == 3);

        assert(stack7.Size() == 6);
        assert(cstack7.Size() == 6);
        assert(stack7.Top().val1 == 6);
        assert(cstack7.Top().val1 == 6);
        {
            test::Stack<Obj1> stack7_cpy{stack7};
            const test::Stack<Obj1>& cstack7_cpy{stack7_cpy};

            auto pop = stack7_cpy.Pop();

            assert(pop.val1 == 6);

            assert(stack7_cpy.Size() == 5);
            assert(cstack7_cpy.Size() == 5);
            assert(stack7_cpy.Top().val1 == 5);
            assert(cstack7_cpy.Top().val1 == 5);
            
            pop = stack7_cpy.Pop();

            assert(pop.val1 == 5);

            assert(stack7_cpy.Size() == 4);
            assert(cstack7_cpy.Size() == 4);
            assert(stack7_cpy.Top().val1 == 4);
            assert(cstack7_cpy.Top().val1 == 4);
            
            pop = stack7_cpy.Pop();
            
            assert(pop.val1 == 4);

            assert(stack7_cpy.Size() == 3);
            assert(cstack7_cpy.Size() == 3);
            assert(stack7_cpy.Top().val1 == 3);
            assert(cstack7_cpy.Top().val1 == 3);
            
            pop = stack7_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack7_cpy.Size() == 2);
            assert(cstack7_cpy.Size() == 2);
            assert(stack7_cpy.Top().val1 == 2);
            assert(cstack7_cpy.Top().val1 == 2);
            
            pop = stack7_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack7_cpy.Size() == 1);
            assert(cstack7_cpy.Size() == 1);
            assert(stack7_cpy.Top().val1 == 1);
            assert(cstack7_cpy.Top().val1 == 1);
            
            pop = stack7_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack7_cpy.Size() == 0);
            assert(cstack7_cpy.Size() == 0);
            assert(stack7_cpy.Top().val1 == 0);
            assert(cstack7_cpy.Top().val1 == 0);
        }
        
        test::Stack<Obj1> stack8{stack1};
        const test::Stack<Obj1>& cstack8 = stack8;
        res = stack8.Push(std::move(stack6));
        
        assert(res == 3);

        assert(stack8.Size() == 6);
        assert(cstack8.Size() == 6);
        assert(stack8.Top().val1 == 6);
        assert(cstack8.Top().val1 == 6);

        assert(stack6.Size() == 0);
        assert(cstack6.Size() == 0);
        assert(stack6.Top().val1 == 0);
        assert(cstack6.Top().val1 == 0);
        {
            test::Stack<Obj1> stack8_cpy{stack8};
            const test::Stack<Obj1>& cstack8_cpy{stack8_cpy};

            auto pop = stack8_cpy.Pop();

            assert(pop.val1 == 6);

            assert(stack8_cpy.Size() == 5);
            assert(cstack8_cpy.Size() == 5);
            assert(stack8_cpy.Top().val1 == 5);
            assert(cstack8_cpy.Top().val1 == 5);
            
            pop = stack8_cpy.Pop();

            assert(pop.val1 == 5);

            assert(stack8_cpy.Size() == 4);
            assert(cstack8_cpy.Size() == 4);
            assert(stack8_cpy.Top().val1 == 4);
            assert(cstack8_cpy.Top().val1 == 4);
            
            pop = stack8_cpy.Pop();
            
            assert(pop.val1 == 4);

            assert(stack8_cpy.Size() == 3);
            assert(cstack8_cpy.Size() == 3);
            assert(stack8_cpy.Top().val1 == 3);
            assert(cstack8_cpy.Top().val1 == 3);
            
            pop = stack8_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack8_cpy.Size() == 2);
            assert(cstack8_cpy.Size() == 2);
            assert(stack8_cpy.Top().val1 == 2);
            assert(cstack8_cpy.Top().val1 == 2);
            
            pop = stack8_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack8_cpy.Size() == 1);
            assert(cstack8_cpy.Size() == 1);
            assert(stack8_cpy.Top().val1 == 1);
            assert(cstack8_cpy.Top().val1 == 1);
            
            pop = stack8_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack8_cpy.Size() == 0);
            assert(cstack8_cpy.Size() == 0);
            assert(stack8_cpy.Top().val1 == 0);
            assert(cstack8_cpy.Top().val1 == 0);
        }
        
        test::Stack<Obj1> stack9;
        const test::Stack<Obj1>& cstack9 = stack9;

        assert(stack9.Size() == 0);
        assert(cstack9.Size() == 0);
        assert(stack9.Top().val1 == 0);
        assert(cstack9.Top().val1 == 0);

        stack9.Swap(stack5);
        
        assert(stack9.Size() == 3);
        assert(cstack9.Size() == 3);
        assert(stack9.Top().val1 == 3);
        assert(cstack9.Top().val1 == 3);
        
        assert(stack5.Size() == 0);
        assert(cstack5.Size() == 0);
        assert(stack5.Top().val1 == 0);
        assert(cstack5.Top().val1 == 0);
        
        {
            test::Stack<Obj1> stack9_cpy{stack9};
            const test::Stack<Obj1>& cstack9_cpy{stack9_cpy};

            auto pop = stack9_cpy.Pop();

            assert(pop.val1 == 3);
            assert(stack9_cpy.Size() == 2);
            assert(cstack9_cpy.Size() == 2);
            assert(stack9_cpy.Top().val1 == 2);
            assert(cstack9_cpy.Top().val1 == 2);
            
            pop = stack9_cpy.Pop();

            assert(pop.val1 == 2);

            assert(stack9_cpy.Size() == 1);
            assert(cstack9_cpy.Size() == 1);
            assert(stack9_cpy.Top().val1 == 1);
            assert(cstack9_cpy.Top().val1 == 1);
            
            pop = stack9_cpy.Pop();
            
            assert(pop.val1 == 1);

            assert(stack9_cpy.Size() == 0);
            assert(cstack9_cpy.Size() == 0);
            assert(stack9_cpy.Top().val1 == 0);
            assert(cstack9_cpy.Top().val1 == 0);
        }
    }
    
    assert(count == 0);

    return 1;
}