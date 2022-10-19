#ifndef TEST_SYS_MEM_REC_ITERATOR_H_
#define TEST_SYS_MEM_REC_ITERATOR_H_

#include "Node.h"

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
class Iterator
{
public:
    typedef test::sys::mem::rec::Node<TBlock> NodeType;
private:
    NodeType *m_curr, *m_prev, *m_next;
public:
    Iterator();
    Iterator(std::nullptr_t);
    Iterator(NodeType* pointer);
public:
    Iterator(const Iterator<TBlock>& cpy);
    Iterator(Iterator<TBlock>&& mov);
public:
    ~Iterator();
public:
    Iterator<TBlock>& operator=(const Iterator<TBlock>& cpy);
    Iterator<TBlock>& operator=(Iterator<TBlock>&& mov);
public:
    explicit operator bool() const;
    operator TBlock*();
public:
    NodeType& operator*();
    NodeType* operator->();
public:
    Iterator<TBlock>& operator+=(int val);
    Iterator<TBlock> operator+(int val);
public:
    Iterator<TBlock>& operator-=(int val);
    Iterator<TBlock> operator-(int val);
public:
    Iterator<TBlock>& operator++();
    Iterator<TBlock> operator++(int);
public:
    Iterator<TBlock>& operator--();
    Iterator<TBlock> operator--(int);
public:
    bool operator==(const Iterator<TBlock>& other) const;
    bool operator!=(const Iterator<TBlock>& other) const;
public:
    bool operator==(std::nullptr_t) const;
    bool operator!=(std::nullptr_t) const;
public:
    template<typename TValue>
    typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
        operator==(const TValue& val) const;
    template<typename TValue>
    typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
        operator!=(const TValue& val) const;
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
Iterator<TBlock>::Iterator() :
    m_curr(nullptr),
    m_prev(nullptr),
    m_next(nullptr)
{}

template<typename TBlock>
Iterator<TBlock>::Iterator(std::nullptr_t) :
    Iterator()
{}

template<typename TBlock>
Iterator<TBlock>::Iterator(test::sys::mem::rec::Node<TBlock>* pointer) :
    m_curr(pointer),
    m_next(pointer != nullptr ? pointer->Next() : nullptr),
    m_prev(pointer != nullptr ? pointer->Prev() : nullptr)
{}

template<typename TBlock>
Iterator<TBlock>::Iterator(const Iterator<TBlock>& cpy) :
    m_curr(cpy.m_curr),
    m_next(cpy.m_next),
    m_prev(cpy.m_prev)
{}

template<typename TBlock>
Iterator<TBlock>::Iterator(Iterator<TBlock>&& mov) :
    m_curr(mov.m_curr),
    m_next(mov.m_next),
    m_prev(mov.m_prev)
{
    mov.m_curr = nullptr;
    mov.m_next = nullptr;
    mov.m_prev = nullptr;
}

template<typename TBlock>
Iterator<TBlock>::~Iterator()
{
    m_curr = nullptr;
    m_next = nullptr;
    m_prev = nullptr;
}

template<typename TBlock>
Iterator<TBlock>& 
Iterator<TBlock>::operator=(const Iterator<TBlock>& cpy)
{
    m_curr = cpy.m_curr;
    m_next = cpy.m_next;
    m_prev = cpy.m_prev;
    return *this;
}

template<typename TBlock>
Iterator<TBlock>& 
Iterator<TBlock>::operator=(Iterator<TBlock>&& mov)
{
    m_curr = mov.m_curr;
    m_next = mov.m_next;
    m_prev = mov.m_prev;
    mov.m_curr = nullptr;
    mov.m_next = nullptr;
    mov.m_prev = nullptr;
    return *this;
}

template<typename TBlock>
Iterator<TBlock>::operator bool() const
{
    return (m_curr != nullptr && (bool)*m_curr);
}

template<typename TBlock>
Iterator<TBlock>::operator TBlock*()
{
    static TBlock instance;
    if (m_curr == nullptr) return &instance;
    return (TBlock*)*m_curr;
}

template<typename TBlock>
typename Iterator<TBlock>::NodeType& Iterator<TBlock>::operator*()
{
    static NodeType instance;
    if (m_curr == nullptr) return instance;
    return *m_curr;
}

template<typename TBlock>
typename Iterator<TBlock>::NodeType* Iterator<TBlock>::operator->()
{
    return m_curr;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator+=(int val)
{
    if (val < 0)
    {
        return operator-=(-val);
    }
    for(int i = 0; i < val; ++i)
    {
        if (m_next != nullptr)
        {
            m_prev = m_curr;
            m_curr = m_next;
            m_next = m_curr->Next();
        }
        else
        {
            m_prev = m_curr;
            m_curr = nullptr;
            m_next = nullptr;
            break;
        }
    }
    return *this;
}

template<typename TBlock>
Iterator<TBlock> Iterator<TBlock>::operator+(int val)
{
    Iterator<TBlock> cpy(*this);
    cpy += val;
    return cpy;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator-=(int val)
{
    if (val < 0)
    {
        return operator+=(-val);
    }
    for(int i = 0; i < val; ++i)
    {
        if (m_prev != nullptr)
        {
            m_next = m_curr;
            m_curr = m_prev;
            m_prev = m_curr->Prev();
        }
        else
        {
            m_next = m_curr;
            m_curr = nullptr;
            m_prev = nullptr;
        }
    }
    return *this;
}

template<typename TBlock>
Iterator<TBlock> Iterator<TBlock>::operator-(int val)
{
    Iterator<TBlock> cpy(*this);
    cpy -= val;
    return cpy;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator++()
{
    if (m_next != nullptr)
    {
        m_prev = m_curr;
        m_curr = m_next;
        m_next = m_curr->Next();
    }
    else
    {
        m_prev = m_curr;
        m_curr = nullptr;
        m_next = nullptr;
    }
    return *this;
}

template<typename TBlock>
Iterator<TBlock> Iterator<TBlock>::operator++(int)
{
    Iterator<TBlock> cpy(*this);
    operator++();
    return cpy;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator--()
{
    if (m_prev != nullptr)
    {
        m_next = m_curr;
        m_curr = m_prev;
        m_prev = m_curr->Prev();
    }
    else
    {
        m_next = m_curr;
        m_curr = nullptr;
        m_prev = nullptr;
    }
    return *this;
}

template<typename TBlock>
Iterator<TBlock> Iterator<TBlock>::operator--(int)
{
    Iterator<TBlock> cpy(*this);
    operator--();
    return cpy;
}

template<typename TBlock>
bool Iterator<TBlock>::operator==(const Iterator<TBlock>& other) const
{
    return m_curr == other.m_curr;
}

template<typename TBlock>
bool Iterator<TBlock>::operator!=(const Iterator<TBlock>& other) const
{
    return m_curr != other.m_curr;
}

template<typename TBlock>
bool Iterator<TBlock>::operator==(std::nullptr_t) const
{
    return m_curr == nullptr;
}

template<typename TBlock>
bool Iterator<TBlock>::operator!=(std::nullptr_t) const
{
    return m_curr != nullptr;
}

template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Iterator<TBlock>::operator==(const TValue& val) const
{
    return (m_curr != nullptr) == val;
}
    
template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Iterator<TBlock>::operator!=(const TValue& val) const
{
    return (m_curr != nullptr) != val;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Iterator<TBlock>::operator==(const TValue& val) const
{
    return m_curr == (const void*)val;;
}
        
template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Iterator<TBlock>::operator!=(const TValue& val) const
{
    return m_curr != (const void*)val;;
}

} //!rec

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_REC_ITERATOR_H_
