#ifndef TEST_NODE_H_
#define TEST_NODE_H_

#include "node/Data.h"

#include <cstddef>
#include <utility>
#include <type_traits>

namespace test
{

template<typename T, std::size_t N, std::size_t I = N - 1>
class Node : public Node<T, N, I - 1>
{
private:
    Node<T, N, N - 1> * m_link;
public:
    Node();
    Node(const T & set);
    Node(T && set);
    template<typename... TArgs, typename _TValue = 
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<T>::type>::type>::type,
        typename std::enable_if<std::is_constructible<_TValue, 
            TArgs...>::value, int>::type = 0>
    Node(TArgs && ... args);
public:
    ~Node();
public:
    Node(const Node<T, N, I>& cpy);
    Node(Node<T, N, I>&& mov);
public:
    Node<T, N, I>& operator=(const Node<T, N, I>& cpy);
    Node<T, N, I>& operator=(Node<T, N, I>&& mov);
    Node<T, N, I>& operator=(const T& cpy);
    Node<T, N, I>& operator=(T&& mov);
public:
    Node<T, N, N - 1> * Link();
    const Node<T, N, N - 1> * Link() const;
    void Link(Node<T, N, N - 1> * link);
};

template<typename T, std::size_t N>
class Node<T, N, 0> : public test::node::Data<T>
{
private:
    Node<T, N, N - 1> * m_link;
public:
    Node();
    Node(const T & set);
    Node(T && set);
    template<typename... TArgs, typename _TValue = 
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<T>::type>::type>::type,
        typename std::enable_if<std::is_constructible<_TValue, 
            TArgs...>::value, int>::type = 0>
    Node(TArgs && ... args);
public:
    ~Node();
public:
    Node(const Node<T, N, 0>& cpy);
    Node(Node<T, N, 0>&& mov);
public:
    Node<T, N, 0>& operator=(const Node<T, N, 0>& cpy);
    Node<T, N, 0>& operator=(Node<T, N, 0>&& mov);
    Node<T, N, 0>& operator=(const T& cpy);
    Node<T, N, 0>& operator=(T&& mov);
public:
    Node<T, N, N - 1> * Link();
    const Node<T, N, N - 1> * Link() const;
    void Link(Node<T, N, N - 1> * link);
};

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>::Node() :
    Node<T, N, I - 1>(),
    m_link(nullptr)
{}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>::Node(const T & set) :
    Node<T, N, I - 1>(set),
    m_link(nullptr)
{}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>::Node(T && set) :
    Node<T, N, I - 1>(std::move(set)),
    m_link(nullptr)
{}

template<typename T, std::size_t N, std::size_t I>
template<typename... TArgs, typename _TValue,
    typename std::enable_if<std::is_constructible<_TValue, 
        TArgs...>::value, int>::type>
Node<T, N, I>::Node(TArgs &&... args) :
    Node<T, N, I - 1>(std::forward<TArgs>(args)...),
    m_link(nullptr)
{}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>::~Node()
{}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>::Node(const Node<T, N, I>& cpy) :
    Node<T, N, I - 1>(cpy),
    m_link(cpy.m_link)
{}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>::Node(Node<T, N, I>&& mov) :
    Node<T, N, I - 1>(std::move(mov)),
    m_link(mov.m_link)
{
    mov.m_link = nullptr; 
}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>& Node<T, N, I>::operator=(const Node<T, N, I>& cpy)
{
    Node<T, N, I - 1>::operator=(cpy);
    m_link = cpy.m_link;
    return *this;
}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>& Node<T, N, I>::operator=(Node<T, N, I>&& mov)
{
    Node<T, N, I - 1>::operator=(std::move(mov));
    m_link = mov.m_link;
    mov.m_link = nullptr;
    return *this;
}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>& Node<T, N, I>::operator=(const T& cpy)
{
    Node<T, N, I - 1>::operator=(cpy);
    return *this;
}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, I>& Node<T, N, I>::operator=(T&& mov)
{
    Node<T, N, I - 1>::operator=(std::move(mov));
    return *this;
}

template<typename T, std::size_t N, std::size_t I>
Node<T, N, N - 1> * Node<T, N, I>::Link()
{
    return m_link;
}

template<typename T, std::size_t N, std::size_t I>
const Node<T, N, N - 1> * Node<T, N, I>::Link() const
{
    return m_link;
}

template<typename T, std::size_t N, std::size_t I>
void Node<T, N, I>::Link(Node<T, N, N - 1> * link)
{
    m_link = link;
}

template<typename T, std::size_t N>
Node<T, N, 0>::Node() :
    test::node::Data<T>(),
    m_link(nullptr)
{}

template<typename T, std::size_t N>
Node<T, N, 0>::Node(const T & set) :
    test::node::Data<T>(set),
    m_link(nullptr)
{}

template<typename T, std::size_t N>
Node<T, N, 0>::Node(T && set) :
    test::node::Data<T>(std::move(set)),
    m_link(nullptr)
{}

template<typename T, std::size_t N>
template<typename... TArgs, typename _TValue,
    typename std::enable_if<std::is_constructible<_TValue, 
        TArgs...>::value, int>::type>
Node<T, N, 0>::Node(TArgs && ... args) :
    test::node::Data<T>(std::forward<TArgs>(args)...),
    m_link(nullptr)
{}

template<typename T, std::size_t N>
Node<T, N, 0>::~Node()
{}

template<typename T, std::size_t N>
Node<T, N, 0>::Node(const Node<T, N, 0>& cpy) :
    test::node::Data<T>(cpy),
    m_link(cpy.m_link)
{}

template<typename T, std::size_t N>
Node<T, N, 0>::Node(Node<T, N, 0>&& mov) :
    test::node::Data<T>(std::move(mov)),
    m_link(mov.m_link)
{
    mov.m_link = nullptr;
}

template<typename T, std::size_t N>
Node<T, N, 0>& Node<T, N, 0>::operator=(const Node<T, N, 0>& cpy)
{
    test::node::Data<T>::operator=(cpy);
    m_link = cpy.m_link;
    return *this;
}

template<typename T, std::size_t N>
Node<T, N, 0>& Node<T, N, 0>::operator=(Node<T, N, 0>&& mov)
{
    test::node::Data<T>::operator=(std::move(mov));
    m_link = mov.m_link;
    mov.m_link = nullptr;
    return *this;
}

template<typename T, std::size_t N>
Node<T, N, 0>& Node<T, N, 0>::operator=(const T& cpy)
{
    test::node::Data<T>::operator=(cpy);
    return *this;
}

template<typename T, std::size_t N>
Node<T, N, 0>& Node<T, N, 0>::operator=(T&& mov)
{
    test::node::Data<T>::operator=(std::move(mov));
    return *this;
}

template<typename T, std::size_t N>
Node<T, N, N - 1> * Node<T, N, 0>::Link()
{
    return m_link;
}

template<typename T, std::size_t N>
const Node<T, N, N - 1> * Node<T, N, 0>::Link() const
{
    return m_link;
}

template<typename T, std::size_t N>
void Node<T, N, 0>::Link(Node<T, N, N - 1> * link)
{
    m_link = link;
}

} //!test

#endif //!TEST_NODE_H_
