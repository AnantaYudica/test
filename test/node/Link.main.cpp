#include "test/node/Link.h"

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

template<typename... TArgs>
test::Node<Obj1, 1>* AddSLL(test::Node<Obj1, 1> *& head, 
    test::Node<Obj1, 1> *& tail, TArgs && ... args)
{
    auto* curr = new test::Node<Obj1, 1>(std::forward<TArgs>(args)...);
    if (head == nullptr && head == tail)
    {
        head = curr;
        tail = head;
    }
    else 
    {
        test::node::Link<test::node::link::next>(tail, curr);
        tail = curr;
    }
    return curr;
}

void ClearSLL(test::Node<Obj1, 1> *& head, 
    test::Node<Obj1, 1> *& tail)
{
    test::Node<Obj1, 1> * curr = head;
    while(curr != nullptr)
    {
        head = test::node::Link<test::node::link::next>(curr);
        
        delete curr;
        curr = head;
    }
    head = nullptr;
    tail = nullptr;
}

template<typename... TArgs>
test::Node<Obj1, 2>* AddDLL(test::Node<Obj1, 2> *& head, 
    test::Node<Obj1, 2> *& tail, TArgs && ... args)
{
    auto* curr = new test::Node<Obj1, 2>(std::forward<TArgs>(args)...);
    if (head == nullptr && head == tail)
    {
        head = curr;
        tail = head;
    }
    else 
    {
        test::node::Link<test::node::link::next>(tail, curr);
        test::node::Link<test::node::link::prev>(curr, tail);
        tail = curr;
    }
    return curr;
}

void ClearDLL(test::Node<Obj1, 2> *& head, 
    test::Node<Obj1, 2> *& tail)
{
    test::Node<Obj1, 2> * curr = head;
    while(curr != nullptr)
    {
        head = test::node::Link<test::node::link::next>(curr);
        
        delete curr;
        curr = head;
    }
    head = nullptr;
    tail = nullptr;
}

int main()
{
    test::Node<Obj1, 1> * head1 = nullptr, *tail1 = nullptr;
    auto curr1 = AddSLL(head1, tail1, 1);
    {
        Obj1 obj = **head1;
        auto link = test::node::Link<test::node::link::next>(head1);
        assert(obj.val1 == 1);
        assert(curr1 == head1);
        assert(curr1 == tail1);
        assert(link == nullptr);
        
    }

    curr1 = AddSLL(head1, tail1, 1, 1);
    {
        Obj1 obj1_1 = **head1, obj1_2 = **tail1;
        auto link1 = test::node::Link<test::node::link::next>(head1);
        auto link2 = test::node::Link<test::node::link::next>(tail1);
        assert(obj1_1.val1 == 1);
        assert(obj1_2.val1 == 2);
        assert(link1 == tail1);
        assert(tail1 == curr1);
        assert(link2 == nullptr);
    }

    curr1 = AddSLL(head1, tail1, (**head1));
    (*curr1)->val1 = 3;
    {
        auto link1 = test::node::Link<test::node::link::next>(head1);
        auto link2 = test::node::Link<test::node::link::next>(link1);
        auto link3 = test::node::Link<test::node::link::next>(tail1);
        Obj1 obj1_1 = **head1, 
            obj1_2 = **link1,
            obj1_3 = **tail1;
        assert(obj1_1.val1 == 1);
        assert(obj1_2.val1 == 2);
        assert(obj1_3.val1 == 3);
        assert(link2 == tail1);
        assert(tail1 == curr1);
        assert(link3 == nullptr);
    }

    curr1 = AddSLL(head1, tail1, 4);
    {
        auto link1 = test::node::Link<test::node::link::next>(head1);
        auto link2 = test::node::Link<test::node::link::next>(link1);
        auto link3 = test::node::Link<test::node::link::next>(link2);
        auto link4 = test::node::Link<test::node::link::next>(tail1);
        Obj1 obj1_1 = **head1, 
            obj1_2 = **link1,
            obj1_3 = **link2,
            obj1_4 = **tail1;
        assert(obj1_1.val1 == 1);
        assert(obj1_2.val1 == 2);
        assert(obj1_3.val1 == 3);
        assert(obj1_4.val1 == 4);
        assert(link3 == tail1);
        assert(tail1 == curr1);
        assert(link4 == nullptr);
    }

    ClearSLL(head1, tail1);
    
    test::Node<Obj1, 2> * head2 = nullptr, *tail2 = nullptr;
    auto curr2 = AddDLL(head2, tail2, 5);
    {
        auto link1_1 = test::node::Link<test::node::link::next>(head2);
        auto link1_2 = test::node::Link<test::node::link::prev>(head2);
        Obj1 obj1_1 = **head2;
        assert(obj1_1.val1 == 5);
        assert(curr2 == head2);
        assert(curr2 == tail2);
        assert(link1_1 == nullptr);
        assert(link1_2 == nullptr);
    }

    curr2 = AddDLL(head2, tail2, 6);
    {
        auto link1_1 = test::node::Link<test::node::link::next>(head2);
        auto link1_2 = test::node::Link<test::node::link::prev>(head2);
        auto link2_1 = test::node::Link<test::node::link::next>(tail2);
        auto link2_2 = test::node::Link<test::node::link::prev>(tail2);
        Obj1 obj1_1 = **head2, obj1_2 = **tail2;
        assert(obj1_1.val1 == 5);
        assert(obj1_2.val1 == 6);
        assert(curr2 == tail2);
        assert(link1_1 == tail2);
        assert(link1_2 == nullptr);
        assert(link2_1 == nullptr);
        assert(link2_2 == head2);
    }

    curr2 = AddDLL(head2, tail2, **head2);
    (*curr2)->val1 += 2;
    {
        auto link1_1 = test::node::Link<test::node::link::next>(head2);
        auto link1_2 = test::node::Link<test::node::link::prev>(head2);
        auto link3_1 = test::node::Link<test::node::link::next>(tail2);
        auto link3_2 = test::node::Link<test::node::link::prev>(tail2);
        auto link2_1 = test::node::Link<test::node::link::next>(link1_1);
        auto link2_2 = test::node::Link<test::node::link::prev>(link3_2);
        Obj1 obj1_1 = **head2, 
            obj1_2 = **link1_1,
            obj1_3 = **tail2;
        assert(obj1_1.val1 == 5);
        assert(obj1_2.val1 == 6);
        assert(obj1_3.val1 == 7);
        assert(curr2 == tail2);
        assert(link1_1 == link3_2);
        assert(link1_2 == nullptr);
        assert(link2_1 == tail2);
        assert(link2_2 == head2);
        assert(link3_1 == nullptr);
        assert(link3_2 == link1_1);

    }

    curr2 = AddDLL(head2, tail2, 8);
    {
        auto link1_1 = test::node::Link<test::node::link::next>(head2);
        auto link1_2 = test::node::Link<test::node::link::prev>(head2);
        auto link4_1 = test::node::Link<test::node::link::next>(tail2);
        auto link4_2 = test::node::Link<test::node::link::prev>(tail2);
        auto link3_2 = test::node::Link<test::node::link::prev>(link4_2);
        auto link2_1 = test::node::Link<test::node::link::next>(link1_1);
        auto link2_2 = test::node::Link<test::node::link::prev>(link3_2);
        auto link3_1 = test::node::Link<test::node::link::next>(link2_1);
        Obj1 obj1_1 = **head2, 
            obj1_2 = **link1_1,
            obj1_3 = **link4_2,
            obj1_4 = **tail2;
        assert(obj1_1.val1 == 5);
        assert(obj1_2.val1 == 6);
        assert(obj1_3.val1 == 7);
        assert(obj1_4.val1 == 8);
        assert(curr2 == tail2);
        assert(link1_1 == link3_2);
        assert(link1_2 == nullptr);
        assert(link2_1 == link4_2);
        assert(link2_2 == head2);
        assert(link3_1 == tail2);
        assert(link3_2 == link1_1);
        assert(link4_1 == nullptr);
        assert(link4_2 == link2_1);

    }

    ClearDLL(head2, tail2);
    
    assert(count == 0);
}
