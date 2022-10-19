#ifndef TEST_SYS_MEM_REC_NODE_H_
#define TEST_SYS_MEM_REC_NODE_H_

#include <type_traits>
#include <cstddef>

namespace test
{
namespace sys
{
namespace mem
{
namespace rec
{

template<typename TBlock>
class Node
{
private:
    Node<TBlock> *m_next, *m_prev;
    TBlock* m_data;
public:
    Node();
    Node(TBlock* data);
public:
    Node(const Node<TBlock>& cpy);
    Node(Node<TBlock>&& mov);
public:
    ~Node();
public:
    Node<TBlock>& operator=(TBlock* set);
    Node<TBlock>& operator=(const Node<TBlock>& cpy);
    Node<TBlock>& operator=(Node<TBlock>&& cpy);
public:
    Node<TBlock>* Next();
    Node<TBlock>* Next(Node<TBlock> *set);
public:
    Node<TBlock>* Prev();
    Node<TBlock>* Prev(Node<TBlock> *set);
public:
    operator bool() const;
    operator TBlock*();
public:
    TBlock& operator*();
    TBlock* operator->();
public:
    bool operator==(const Node<TBlock>& other) const;
    bool operator!=(const Node<TBlock>& other) const;
public:
    template<typename TValue>
    typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
        operator==(const TValue& val) const;
    template<typename TValue>
    typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
        operator!=(const TValue& val) const;
public:
    bool operator==(const TBlock* other) const;
    bool operator!=(const TBlock* other) const;
public:
    bool operator==(TBlock* other) const;
    bool operator!=(TBlock* other) const;
public:
    bool operator==(std::nullptr_t) const;
    bool operator!=(std::nullptr_t) const;
public:
    template<typename TValue, typename TNull = decltype(NULL)>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
            operator==(const TValue& val) const;
    template<typename TValue, typename TNull = decltype(NULL)>
    typename std::enable_if<!std::is_same<TNull, void*>::value
        && std::is_same<TValue, TNull>::value, bool>::type 
            operator!=(const TValue& val) const;
};

template<typename TBlock>
Node<TBlock>::Node() :
    m_next(nullptr),
    m_prev(nullptr),
    m_data(nullptr)
{}

template<typename TBlock>
Node<TBlock>::Node(TBlock* data) :
    m_next(nullptr),
    m_prev(nullptr),
    m_data(data)
{}

template<typename TBlock>
Node<TBlock>::Node(const Node<TBlock>& cpy) :
    m_next(cpy.m_next),
    m_prev(cpy.m_prev),
    m_data(cpy.m_data)
{}

template<typename TBlock>
Node<TBlock>::Node(Node<TBlock>&& mov) :
    m_next(mov.m_next),
    m_prev(mov.m_prev),
    m_data(mov.m_data)
{
    mov.m_next = nullptr;
    mov.m_prev = nullptr;
    mov.m_data = nullptr;
}

template<typename TBlock>
Node<TBlock>::~Node()
{
    m_next = nullptr;
    m_prev = nullptr;
    m_data = nullptr;
}

template<typename TBlock>
Node<TBlock>& Node<TBlock>::operator=(TBlock* set)
{
    m_data = set;
}

template<typename TBlock>
Node<TBlock>& Node<TBlock>::operator=(const Node<TBlock>& cpy)
{
    m_next = cpy.m_next;
    m_prev = cpy.m_prev;
    m_data = cpy.m_data;
    return *this;
}

template<typename TBlock>
Node<TBlock>& Node<TBlock>::operator=(Node<TBlock>&& mov)
{
    m_next = mov.m_next;
    m_prev = mov.m_prev;
    m_data = mov.m_data;
    mov.m_next = nullptr;
    mov.m_prev = nullptr;
    mov.m_data = nullptr;
    return *this;
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Next()
{
    return m_next;
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Next(Node<TBlock> *set)
{
    return (m_next = set);
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Prev()
{
    return m_prev;
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Prev(Node<TBlock> *set)
{
    return (m_prev = set);
}

template<typename TBlock>
Node<TBlock>::operator bool() const
{
    return (m_data != nullptr);
}

template<typename TBlock>
Node<TBlock>::operator TBlock*()
{
    return m_data;
}

template<typename TBlock>
TBlock& Node<TBlock>::operator*()
{
    return *m_data;
}

template<typename TBlock>
TBlock* Node<TBlock>::operator->()
{
    return m_data;
}

template<typename TBlock>
bool Node<TBlock>::operator==(const Node<TBlock>& other) const
{
    return m_data == other.m_data;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(const Node<TBlock>& other) const
{
    return m_data != other.m_data;
}

template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Node<TBlock>::operator==(const TValue& val) const
{
    return (bool)*this == val;
}
    
template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Node<TBlock>::operator!=(const TValue& val) const
{
    return (bool)*this != val;
}


template<typename TBlock>
bool Node<TBlock>::operator==(const TBlock* other) const
{
    return m_data == other;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(const TBlock* other) const
{
    return m_data != other;
}

template<typename TBlock>
bool Node<TBlock>::operator==(TBlock* other) const
{
    return m_data == other;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(TBlock* other) const
{
    return m_data != other;
}

template<typename TBlock>
bool Node<TBlock>::operator==(std::nullptr_t) const
{
    return m_data == nullptr;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(std::nullptr_t) const
{
    return m_data != nullptr;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Node<TBlock>::operator==(const TValue& val) const
{
    return m_data == (const void*)val;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Node<TBlock>::operator!=(const TValue& val) const
{
    return m_data != (const void*)val;
}

} //!rec

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_REC_NODE_H_
