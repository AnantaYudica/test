#include "test/Queue.h"

#include <cassert>
#include <utility>

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
        test::Queue<Obj1> queue1;
        const test::Queue<Obj1>& cqueue1 = queue1;

        assert(queue1.Size() == 0);
        assert(cqueue1.Size() == 0);

        auto res = queue1.Push(Obj1{1});

        assert(res == 1);

        assert(queue1.Size() == 1);
        assert(cqueue1.Size() == 1);
        assert(queue1.Front().val1 == 1);
        assert(cqueue1.Front().val1 == 1);

        Obj1 obj1_1{2};
        res = queue1.Push(std::move(obj1_1));

        assert(res == 1);

        assert(queue1.Size() == 2);
        assert(cqueue1.Size() == 2);
        assert(queue1.Front().val1 == 1);
        assert(cqueue1.Front().val1 == 1);
        
        assert(obj1_1.val1 == 0);

        res = queue1.Push(1, 2);

        assert(res == 1);

        assert(queue1.Size() == 3);
        assert(cqueue1.Size() == 3);
        assert(queue1.Front().val1 == 1);
        assert(cqueue1.Front().val1 == 1);

        {
            test::Queue<Obj1> queue1_cpy{queue1};
            const test::Queue<Obj1>& cqueue1_cpy{queue1_cpy};

            auto pop = queue1_cpy.Pop();

            assert(pop.val1 == 1);
            assert(queue1_cpy.Size() == 2);
            assert(cqueue1_cpy.Size() == 2);
            assert(queue1_cpy.Front().val1 == 2);
            assert(cqueue1_cpy.Front().val1 == 2);
            
            pop = queue1_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue1_cpy.Size() == 1);
            assert(cqueue1_cpy.Size() == 1);
            assert(queue1_cpy.Front().val1 == 3);
            assert(cqueue1_cpy.Front().val1 == 3);
            
            pop = queue1_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue1_cpy.Size() == 0);
            assert(cqueue1_cpy.Size() == 0);
            assert(queue1_cpy.Front().val1 == 0);
            assert(cqueue1_cpy.Front().val1 == 0);
        }

        test::Queue<Obj1> queue2{queue1};
        const test::Queue<Obj1>& cqueue2 = queue2;
        
        assert(queue2.Size() == 3);
        assert(cqueue2.Size() == 3);
        assert(queue2.Front().val1 == 1);
        assert(cqueue2.Front().val1 == 1);
        
        {
            test::Queue<Obj1> queue2_cpy{queue2};
            const test::Queue<Obj1>& cqueue2_cpy{queue2_cpy};

            auto pop = queue2_cpy.Pop();

            assert(pop.val1 == 1);
            assert(queue2_cpy.Size() == 2);
            assert(cqueue2_cpy.Size() == 2);
            assert(queue2_cpy.Front().val1 == 2);
            assert(cqueue2_cpy.Front().val1 == 2);
            
            pop = queue2_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue2_cpy.Size() == 1);
            assert(cqueue2_cpy.Size() == 1);
            assert(queue2_cpy.Front().val1 == 3);
            assert(cqueue2_cpy.Front().val1 == 3);
            
            pop = queue2_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue2_cpy.Size() == 0);
            assert(cqueue2_cpy.Size() == 0);
            assert(queue2_cpy.Front().val1 == 0);
            assert(cqueue2_cpy.Front().val1 == 0);
        }
        
        test::Queue<Obj1> queue3{std::move(queue2)};
        const test::Queue<Obj1>& cqueue3 = queue3;

        assert(queue3.Size() == 3);
        assert(cqueue3.Size() == 3);
        assert(queue3.Front().val1 == 1);
        assert(cqueue3.Front().val1 == 1);

        assert(queue2.Size() == 0);
        assert(cqueue2.Size() == 0);
        assert(queue2.Front().val1 == 0);
        assert(cqueue2.Front().val1 == 0);
        {
            test::Queue<Obj1> queue3_cpy{queue3};
            const test::Queue<Obj1>& cqueue3_cpy{queue3_cpy};

            auto pop = queue3_cpy.Pop();

            assert(pop.val1 == 1);
            assert(queue3_cpy.Size() == 2);
            assert(cqueue3_cpy.Size() == 2);
            assert(queue3_cpy.Front().val1 == 2);
            assert(cqueue3_cpy.Front().val1 == 2);
            
            pop = queue3_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue3_cpy.Size() == 1);
            assert(cqueue3_cpy.Size() == 1);
            assert(queue3_cpy.Front().val1 == 3);
            assert(cqueue3_cpy.Front().val1 == 3);
            
            pop = queue3_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue3_cpy.Size() == 0);
            assert(cqueue3_cpy.Size() == 0);
            assert(queue3_cpy.Front().val1 == 0);
            assert(cqueue3_cpy.Front().val1 == 0);
        }
        
        test::Queue<Obj1> queue4;
        const test::Queue<Obj1>& cqueue4 = queue4;
        queue4 = queue1;
        
        assert(queue4.Size() == 3);
        assert(cqueue4.Size() == 3);
        assert(queue4.Front().val1 == 1);
        assert(cqueue4.Front().val1 == 1);

        {
            test::Queue<Obj1> queue4_cpy{queue4};
            const test::Queue<Obj1>& cqueue4_cpy{queue4_cpy};

            auto pop = queue4_cpy.Pop();

            assert(pop.val1 == 1);
            assert(queue4_cpy.Size() == 2);
            assert(cqueue4_cpy.Size() == 2);
            assert(queue4_cpy.Front().val1 == 2);
            assert(cqueue4_cpy.Front().val1 == 2);
            
            pop = queue4_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue4_cpy.Size() == 1);
            assert(cqueue4_cpy.Size() == 1);
            assert(queue4_cpy.Front().val1 == 3);
            assert(cqueue4_cpy.Front().val1 == 3);
            
            pop = queue4_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue4_cpy.Size() == 0);
            assert(cqueue4_cpy.Size() == 0);
            assert(queue4_cpy.Front().val1 == 0);
            assert(cqueue4_cpy.Front().val1 == 0);
        }

        test::Queue<Obj1> queue5;
        const test::Queue<Obj1>& cqueue5 = queue5;
        queue5 = std::move(queue4);
        
        assert(queue5.Size() == 3);
        assert(cqueue5.Size() == 3);
        assert(queue5.Front().val1 == 1);
        assert(cqueue5.Front().val1 == 1);

        assert(queue4.Size() == 0);
        assert(cqueue4.Size() == 0);
        assert(queue4.Front().val1 == 0);
        assert(cqueue4.Front().val1 == 0);
        {
            test::Queue<Obj1> queue5_cpy{queue5};
            const test::Queue<Obj1>& cqueue5_cpy{queue5_cpy};

            auto pop = queue5_cpy.Pop();

            assert(pop.val1 == 1);
            assert(queue5_cpy.Size() == 2);
            assert(cqueue5_cpy.Size() == 2);
            assert(queue5_cpy.Front().val1 == 2);
            assert(cqueue5_cpy.Front().val1 == 2);
            
            pop = queue5_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue5_cpy.Size() == 1);
            assert(cqueue5_cpy.Size() == 1);
            assert(queue5_cpy.Front().val1 == 3);
            assert(cqueue5_cpy.Front().val1 == 3);
            
            pop = queue5_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue5_cpy.Size() == 0);
            assert(cqueue5_cpy.Size() == 0);
            assert(queue5_cpy.Front().val1 == 0);
            assert(cqueue5_cpy.Front().val1 == 0);
        }
        
        test::Queue<Obj1> queue6;
        const test::Queue<Obj1>& cqueue6 = queue6;
        queue6.Push(4);
        queue6.Push(5);
        queue6.Push(6);
        
        test::Queue<Obj1> queue7{queue1};
        const test::Queue<Obj1>& cqueue7 = queue7;
        res = queue7.Push(queue6);

        assert(res == 3);

        assert(queue7.Size() == 6);
        assert(cqueue7.Size() == 6);
        assert(queue7.Front().val1 == 1);
        assert(cqueue7.Front().val1 == 1);
        {
            test::Queue<Obj1> queue7_cpy{queue7};
            const test::Queue<Obj1>& cqueue7_cpy{queue7_cpy};

            auto pop = queue7_cpy.Pop();

            assert(pop.val1 == 1);

            assert(queue7_cpy.Size() == 5);
            assert(cqueue7_cpy.Size() == 5);
            assert(queue7_cpy.Front().val1 == 2);
            assert(cqueue7_cpy.Front().val1 == 2);
            
            pop = queue7_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue7_cpy.Size() == 4);
            assert(cqueue7_cpy.Size() == 4);
            assert(queue7_cpy.Front().val1 == 3);
            assert(cqueue7_cpy.Front().val1 == 3);
            
            pop = queue7_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue7_cpy.Size() == 3);
            assert(cqueue7_cpy.Size() == 3);
            assert(queue7_cpy.Front().val1 == 4);
            assert(cqueue7_cpy.Front().val1 == 4);
            
            pop = queue7_cpy.Pop();

            assert(pop.val1 == 4);
            assert(queue7_cpy.Size() == 2);
            assert(cqueue7_cpy.Size() == 2);
            assert(queue7_cpy.Front().val1 == 5);
            assert(cqueue7_cpy.Front().val1 == 5);
            
            pop = queue7_cpy.Pop();

            assert(pop.val1 == 5);

            assert(queue7_cpy.Size() == 1);
            assert(cqueue7_cpy.Size() == 1);
            assert(queue7_cpy.Front().val1 == 6);
            assert(cqueue7_cpy.Front().val1 == 6);
            
            pop = queue7_cpy.Pop();
            
            assert(pop.val1 == 6);

            assert(queue7_cpy.Size() == 0);
            assert(cqueue7_cpy.Size() == 0);
            assert(queue7_cpy.Front().val1 == 0);
            assert(cqueue7_cpy.Front().val1 == 0);
        }
        
        test::Queue<Obj1> queue8{queue1};
        const test::Queue<Obj1>& cqueue8 = queue8;
        res = queue8.Push(std::move(queue6));

        assert(res == 3);

        assert(queue8.Size() == 6);
        assert(cqueue8.Size() == 6);
        assert(queue8.Front().val1 == 1);
        assert(cqueue8.Front().val1 == 1);

        assert(queue6.Size() == 0);
        assert(cqueue6.Size() == 0);
        assert(queue6.Front().val1 == 0);
        assert(cqueue6.Front().val1 == 0);
        {
            test::Queue<Obj1> queue8_cpy{queue8};
            const test::Queue<Obj1>& cqueue8_cpy{queue8_cpy};

            auto pop = queue8_cpy.Pop();

            assert(pop.val1 == 1);

            assert(queue8_cpy.Size() == 5);
            assert(cqueue8_cpy.Size() == 5);
            assert(queue8_cpy.Front().val1 == 2);
            assert(cqueue8_cpy.Front().val1 == 2);
            
            pop = queue8_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue8_cpy.Size() == 4);
            assert(cqueue8_cpy.Size() == 4);
            assert(queue8_cpy.Front().val1 == 3);
            assert(cqueue8_cpy.Front().val1 == 3);
            
            pop = queue8_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue8_cpy.Size() == 3);
            assert(cqueue8_cpy.Size() == 3);
            assert(queue8_cpy.Front().val1 == 4);
            assert(cqueue8_cpy.Front().val1 == 4);
            
            pop = queue8_cpy.Pop();

            assert(pop.val1 == 4);
            assert(queue8_cpy.Size() == 2);
            assert(cqueue8_cpy.Size() == 2);
            assert(queue8_cpy.Front().val1 == 5);
            assert(cqueue8_cpy.Front().val1 == 5);
            
            pop = queue8_cpy.Pop();

            assert(pop.val1 == 5);

            assert(queue8_cpy.Size() == 1);
            assert(cqueue8_cpy.Size() == 1);
            assert(queue8_cpy.Front().val1 == 6);
            assert(cqueue8_cpy.Front().val1 == 6);
            
            pop = queue8_cpy.Pop();
            
            assert(pop.val1 == 6);

            assert(queue8_cpy.Size() == 0);
            assert(cqueue8_cpy.Size() == 0);
            assert(queue8_cpy.Front().val1 == 0);
            assert(cqueue8_cpy.Front().val1 == 0);
        }
        
        test::Queue<Obj1> queue9;
        const test::Queue<Obj1>& cqueue9 = queue9;

        assert(queue9.Size() == 0);
        assert(cqueue9.Size() == 0);
        assert(queue9.Front().val1 == 0);
        assert(cqueue9.Front().val1 == 0);

        queue9.Swap(queue5);
        
        assert(queue9.Size() == 3);
        assert(cqueue9.Size() == 3);
        assert(queue9.Front().val1 == 1);
        assert(cqueue9.Front().val1 == 1);
        
        assert(queue5.Size() == 0);
        assert(cqueue5.Size() == 0);
        assert(queue5.Front().val1 == 0);
        assert(cqueue5.Front().val1 == 0);
        
        {
            test::Queue<Obj1> queue9_cpy{queue9};
            const test::Queue<Obj1>& cqueue9_cpy{queue9_cpy};

            auto pop = queue9_cpy.Pop();

            assert(pop.val1 == 1);
            assert(queue9_cpy.Size() == 2);
            assert(cqueue9_cpy.Size() == 2);
            assert(queue9_cpy.Front().val1 == 2);
            assert(cqueue9_cpy.Front().val1 == 2);
            
            pop = queue9_cpy.Pop();

            assert(pop.val1 == 2);

            assert(queue9_cpy.Size() == 1);
            assert(cqueue9_cpy.Size() == 1);
            assert(queue9_cpy.Front().val1 == 3);
            assert(cqueue9_cpy.Front().val1 == 3);
            
            pop = queue9_cpy.Pop();
            
            assert(pop.val1 == 3);

            assert(queue9_cpy.Size() == 0);
            assert(cqueue9_cpy.Size() == 0);
            assert(queue9_cpy.Front().val1 == 0);
            assert(cqueue9_cpy.Front().val1 == 0);
        }
    }
    
    assert(count == 0);

    return 1;
}