#include "test/Node.h"

#include <cstdio>
#include <utility>
#include <cassert>

struct Obj1
{
    int val1;
    Obj1() : val1(0)
    {
        
    }
    Obj1(const int& i) : val1(i)
    {
        
    }
    Obj1(const int& i, const int& j) : val1(i + j)
    {
        
    }
    Obj1(const Obj1& cpy) : val1(cpy.val1)
    {
        
    }
    Obj1(Obj1&& mov) : val1(mov.val1)
    {
        mov.val1 = 0;
    }
    ~Obj1()
    {
        val1 = 0;  
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
        test::Node<Obj1, 1> node1;
        assert(node1->val1 == 0);
        assert(node1.Link() == nullptr);

        test::Node<Obj1, 1> node2{Obj1{2}};
        node2.Link(&node1);

        assert(node2->val1 == 2);
        assert(node2.Link() == &node1);

        Obj1 obj1{5};
        test::Node<Obj1, 1> node3{std::move(obj1)};
        node3.Link(&node1);
        
        assert(node3->val1 == 5);
        assert(node3.Link() == &node1);

        assert(obj1.val1 == 0);

        test::Node<Obj1, 1> node4{1 , 3};
        
        assert(node4->val1 == 4);
        assert(node4.Link() == nullptr);

        test::Node<Obj1, 1> node5{node2};

        assert(node5->val1 == 2);
        assert(node5.Link() == &node1);

        test::Node<Obj1, 1> node6{std::move(node3)};

        assert(node6->val1 == 5);
        assert(node6.Link() == &node1);

        assert(node3->val1 == 0);
        assert(node3.Link() == nullptr);

        test::Node<Obj1, 1> node7;
        node7 = node2;
        
        assert(node7->val1 == 2);
        assert(node7.Link() == &node1);
        
        test::Node<Obj1, 1> node8;
        node8 = std::move(node6);

        assert(node8->val1 == 5);
        assert(node8.Link() == &node1);

        assert(node6->val1 == 0);
        assert(node6.Link() == nullptr);

        test::Node<Obj1, 1> node9;
        node9 = Obj1{9};
        
        assert(node9->val1 == 9);
        assert(node9.Link() == nullptr);

        Obj1 obj2{100};
        test::Node<Obj1, 1> node10;
        node10 = std::move(obj2);
        
        assert(node10->val1 == 100);
        assert(node10.Link() == nullptr);

        assert(obj2.val1 == 0);
    }
    {
        test::Node<Obj1, 2> node1;
        {
            auto node1_next = node1.Link();
            auto node1_prev = static_cast<test::Node<Obj1, 2, 0>&>(node1).Link();
            assert(node1->val1 == 0);
            assert(node1_next == nullptr);
            assert(node1_prev == nullptr);
        }
        

        test::Node<Obj1, 2> node2{Obj1{2}};
        node2.Link(&node1);
        static_cast<test::Node<Obj1, 2, 0>&>(node1).Link(&node2);
        {
            auto node1_next = node1.Link();
            auto node1_prev = static_cast<test::Node<Obj1, 2, 0>&>(node1).Link();
            auto node2_next = node2.Link();
            auto node2_prev = static_cast<test::Node<Obj1, 2, 0>&>(node2).Link();

            assert(node2->val1 == 2);
            assert(node2_next == &node1);
            assert(node2_prev == nullptr);
            
            assert(node1_next == nullptr);
            assert(node1_prev == &node2);
        }
        
        
        Obj1 obj1{5};
        test::Node<Obj1, 2> node3{std::move(obj1)};
        node3.Link(&node2);
        static_cast<test::Node<Obj1, 2, 0>&>(node2).Link(&node3);
        {
            auto node2_next = node2.Link();
            auto node2_prev = static_cast<test::Node<Obj1, 2, 0>&>(node2).Link();
            auto node3_next = node3.Link();
            auto node3_prev = static_cast<test::Node<Obj1, 2, 0>&>(node3).Link();

            assert(node3->val1 == 5);
            assert(node2_next == &node1);
            assert(node2_prev == &node3);
            
            assert(node3_next == &node2);
            assert(node3_prev == nullptr);
        }

        assert(obj1.val1 == 0);

        test::Node<Obj1, 2> node4{1 , 3};
        {
            auto node4_next = node4.Link();
            auto node4_prev = static_cast<test::Node<Obj1, 2, 0>&>(node4).Link();
            assert(node4->val1 == 4);
            assert(node4_next == nullptr);
            assert(node4_prev == nullptr);
        }

        test::Node<Obj1, 2> node5{node2};
        {
            auto node5_next = node5.Link();
            auto node5_prev = static_cast<test::Node<Obj1, 2, 0>&>(node5).Link();
            assert(node5->val1 == 2);
            assert(node5_next == &node1);
            assert(node5_prev == &node3);
        }

        test::Node<Obj1, 2> node6{std::move(node5)};
        {
            auto node5_next = node5.Link();
            auto node5_prev = static_cast<test::Node<Obj1, 2, 0>&>(node5).Link();
            auto node6_next = node6.Link();
            auto node6_prev = static_cast<test::Node<Obj1, 2, 0>&>(node6).Link();
            assert(node6->val1 == 2);
            assert(node6_next == &node1);
            assert(node6_prev == &node3);
            assert(node5_next == nullptr);
            assert(node5_prev == nullptr);
        }

        test::Node<Obj1, 2> node7;
        node7 = node2;
        {
            auto node7_next = node7.Link();
            auto node7_prev = static_cast<test::Node<Obj1, 2, 0>&>(node7).Link();
            assert(node7->val1 == 2);
            assert(node7_next == &node1);
            assert(node7_prev == &node3);
        }
        
        test::Node<Obj1, 2> node8;
        node8 = std::move(node6);
        {
            auto node6_next = node6.Link();
            auto node6_prev = static_cast<test::Node<Obj1, 2, 0>&>(node6).Link();
            auto node8_next = node8.Link();
            auto node8_prev = static_cast<test::Node<Obj1, 2, 0>&>(node8).Link();
            assert(node8->val1 == 2);
            assert(node8_next == &node1);
            assert(node8_prev == &node3);
            assert(node6_next == nullptr);
            assert(node6_prev == nullptr);
        }

        test::Node<Obj1, 2> node9;
        node9 = Obj1{9};
        {
            auto node9_next = node9.Link();
            auto node9_prev = static_cast<test::Node<Obj1, 2, 0>&>(node9).Link();
            assert(node9->val1 == 9);
            assert(node9_next == nullptr);
            assert(node9_prev == nullptr);
        }

        Obj1 obj2{100};
        test::Node<Obj1, 2> node10;
        node10 = std::move(obj2);
        {
            auto node10_next = node10.Link();
            auto node10_prev = static_cast<test::Node<Obj1, 2, 0>&>(node10).Link();
            assert(node10->val1 == 100);
            assert(node10_next == nullptr);
            assert(node10_prev == nullptr);
        }

        assert(obj2.val1 == 0);
    }

    return 1;
}