#ifndef TEST_STACK_H_
#define TEST_STACK_H_

#include "Node.h"
#include "node/Link.h"
#include "node/Data.h"

#include <cstddef>

namespace test
{

template<typename T>
class Stack
{
public:
    typedef std::size_t SizeType;
private:
    static bool _Push(test::Node<T, 1> *& head,
        test::Node<T, 1> *& tail, test::Node<T, 1> * curr_head, 
        test::Node<T, 1> * curr_tail);
    static bool _Pop(test::Node<T, 1> *& head,
        test::Node<T, 1> *& tail, test::Node<T, 1> *& curr);
    static void _Clear(test::Node<T, 1> *& head,
        test::Node<T, 1> *& tail);
    static void _Copy(test::Node<T, 1> *& head,
        test::Node<T, 1> *& tail, const test::Node<T, 1> * other_head,
        const test::Node<T, 1> * other_tail);
private:
    test::Node<T, 1> * m_head, * m_tail;
    test::node::Data<T> * m_default;
    SizeType m_size;
    
public:
    Stack();
public:
    ~Stack();
public:
    Stack(const Stack<T>& cpy);
    Stack(Stack<T>&& mov);
public:
    Stack<T>& operator=(const Stack<T>& cpy);
    Stack<T>& operator=(Stack<T>&& mov);
public:
    SizeType Size() const;
public:
    SizeType Push(const T & val);
    SizeType Push(T && val);
    template<typename... TArgs, typename std::enable_if<
        std::is_constructible<T, TArgs...>::value, int>::type = 0>
    SizeType Push(TArgs && ... args);
    SizeType Push(const Stack<T>& cpy);
    SizeType Push(Stack<T>&& mov);
public:
    T Pop();
public:
    T& Top();
    T Top() const;
public:
    void Swap(Stack<T>& other);
};

template<typename T>
bool Stack<T>::_Push(test::Node<T, 1> *& head,
    test::Node<T, 1> *& tail, test::Node<T, 1> * curr_head, 
    test::Node<T, 1> * curr_tail)
{
    using namespace test::node;
    if (curr_head == nullptr || curr_tail == nullptr) return false;
    if (head == nullptr && tail == nullptr)
    {
        head = curr_head;
        tail = curr_tail;
    }
    else
    {
        Link<link::next>(curr_tail, head);
        head = curr_head;
    }
    return true;
}

template<typename T>
bool Stack<T>::_Pop(test::Node<T, 1> *& head,
    test::Node<T, 1> *& tail, test::Node<T, 1> *& curr)
{
    using namespace test::node;
    if (curr != nullptr) return false;
    if (head == nullptr && tail == nullptr)
    {
        return false;
    }
    curr = head;
    head = Link<link::next>(head);
    if (curr == tail)
        tail = nullptr;
    return true;
}

template<typename T>
void Stack<T>::_Clear(test::Node<T, 1> *& head,
    test::Node<T, 1> *& tail)
{
    using namespace test::node;
    while(head != tail)
    {
        auto curr = head;
        head = Link<link::next>(head);
        delete curr;
    }
}

template<typename T>
void Stack<T>::_Copy(test::Node<T, 1> *& head,
    test::Node<T, 1> *& tail, const test::Node<T, 1> * other_head,
    const test::Node<T, 1> * other_tail)
{
    using namespace test::node;
    if (other_head == nullptr) return;
    if (other_head != other_tail)
        _Copy(head, tail, Link<link::next>(other_head), other_tail);
    auto* new_node = new test::Node<T, 1>(**other_head);
    _Push(head, tail, new_node, new_node);
}

template<typename T>
Stack<T>::Stack() :
    m_head(nullptr),
    m_tail(nullptr),
    m_default(nullptr),
    m_size(0)
{}

template<typename T>
Stack<T>::~Stack()
{
    _Clear(m_head, m_tail);
    if (m_default != nullptr)
    {
        delete m_default;
        m_default = nullptr;
    }
    m_size = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& cpy) :
    m_head(nullptr),
    m_tail(nullptr),
    m_default(nullptr),
    m_size(cpy.m_size)
{
    _Copy(m_head, m_tail, cpy.m_head, cpy.m_tail);
}

template<typename T>
Stack<T>::Stack(Stack<T>&& mov) :
    m_head(mov.m_head),
    m_tail(mov.m_tail),
    m_default(nullptr),
    m_size(mov.m_size)
{
    mov.m_head = nullptr;
    mov.m_tail = nullptr;
    mov.m_size = 0;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& cpy)
{
    _Clear(m_head, m_tail);
    _Copy(m_head, m_tail, cpy.m_head, cpy.m_tail);
    m_size = cpy.m_size;
    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& mov)
{
    _Clear(m_head, m_tail);
    m_head = mov.m_head;
    m_tail = mov.m_tail;
    m_size = mov.m_size;

    mov.m_head = nullptr;
    mov.m_tail = nullptr;
    mov.m_size = 0;
    return *this;
}

template<typename T>
typename Stack<T>::SizeType Stack<T>::Size() const
{
    return m_size;
}

template<typename T>
typename Stack<T>::SizeType Stack<T>::Push(const T & val)
{
    auto new_node = new test::Node<T, 1>(val);
    if (_Push(m_head, m_tail, new_node, new_node))
    {
        ++m_size;
        return 1;
    }
    delete new_node;
    return 0;
}

template<typename T>
typename Stack<T>::SizeType Stack<T>::Push(T && val)
{
    auto new_node = new test::Node<T, 1>(std::move(val));
    if (_Push(m_head, m_tail, new_node, new_node))
    {
        ++m_size;
        return 1;
    }
    delete new_node;
    return 0;
}

template<typename T>
template<typename... TArgs, typename std::enable_if<
    std::is_constructible<T, TArgs...>::value, int>::type>
typename Stack<T>::SizeType Stack<T>::Push(TArgs && ... args)
{
    auto new_node = new test::Node<T, 1>(std::forward<TArgs>(args)...);
    if (_Push(m_head, m_tail, new_node, new_node))
    {
        ++m_size;
        return 1;
    }
    delete new_node;
    return 0;
}

template<typename T>
typename Stack<T>::SizeType Stack<T>::Push(const Stack<T>& cpy)
{
    if (cpy.m_size > 0)
    {
        test::Node<T, 1> * head = nullptr, * tail = nullptr;
        _Copy(head, tail, cpy.m_head, cpy.m_tail);
        _Push(m_head, m_tail, head, tail);
        m_size += cpy.m_size;
        return cpy.m_size;
    }
    return 0;
}

template<typename T>
typename Stack<T>::SizeType Stack<T>::Push(Stack<T>&& mov)
{
    const auto size = mov.m_size;
    if (size> 0)
    {
        _Push(m_head, m_tail, mov.m_head, mov.m_tail);
        mov.m_head = nullptr;
        mov.m_tail = nullptr;
        mov.m_size = 0;
        m_size += size;
        return size;
    }
    return 0;
}

template<typename T>
T Stack<T>::Pop()
{
    test::Node<T, 1>* pop_node = nullptr;
    if (_Pop(m_head, m_tail, pop_node))
    {
        T ret = std::move(**pop_node);
        --m_size;
        delete pop_node;
        return ret;
    }
    return {};
}

template<typename T>
T& Stack<T>::Top()
{
    if (m_head == nullptr)
    {
        if (m_default == nullptr)
            m_default = new test::node::Data<T>();
        else
            *m_default = std::move(T());
        return **m_default;
    }
    return **m_head;
}

template<typename T>
T Stack<T>::Top() const
{
    if (m_head == nullptr)
        return {};
    return **m_head;
}

template<typename T>
void Stack<T>::Swap(Stack<T>& other)
{
    auto* head = m_head;
    auto* tail = m_tail;
    auto size = m_size;
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;
    other.m_head = head;
    other.m_tail = tail;
    other.m_size = size;
}

} //!test

#endif //!TEST_STACK_H_