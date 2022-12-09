#ifndef TEST_SYS_MEM_REC_ITERATOR_H_
#define TEST_SYS_MEM_REC_ITERATOR_H_

#include "Node.h"
#include "../../Definition.h"
#include "../../Interface.h"
#include "../../Debug.h"

#include <cstddef>

namespace test::sys::mem::rec
{
template<typename TBlock>
class Iterator;
}

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBlock>

template<typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::sys::mem::rec::Iterator", 
    test::sys::mem::rec::Iterator<TBlock>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

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
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::rec::Iterator<TBlock>> DebugType;
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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TBlock>
Iterator<TBlock>::Iterator(std::nullptr_t) :
    Iterator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Constructor(nullptr)");

}

template<typename TBlock>
Iterator<TBlock>::Iterator(test::sys::mem::rec::Node<TBlock>* pointer) :
    m_curr(pointer),
    m_next(pointer != nullptr ? pointer->Next() : nullptr),
    m_prev(pointer != nullptr ? pointer->Prev() : nullptr)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(pointer=%p)", pointer);

}

template<typename TBlock>
Iterator<TBlock>::Iterator(const Iterator<TBlock>& cpy) :
    m_curr(cpy.m_curr),
    m_next(cpy.m_next),
    m_prev(cpy.m_prev)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename TBlock>
Iterator<TBlock>::Iterator(Iterator<TBlock>&& mov) :
    m_curr(mov.m_curr),
    m_next(mov.m_next),
    m_prev(mov.m_prev)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_curr = nullptr;
    mov.m_next = nullptr;
    mov.m_prev = nullptr;
}

template<typename TBlock>
Iterator<TBlock>::~Iterator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_curr = nullptr;
    m_next = nullptr;
    m_prev = nullptr;
}

template<typename TBlock>
Iterator<TBlock>& 
Iterator<TBlock>::operator=(const Iterator<TBlock>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_curr = cpy.m_curr;
    m_next = cpy.m_next;
    m_prev = cpy.m_prev;
    return *this;
}

template<typename TBlock>
Iterator<TBlock>& 
Iterator<TBlock>::operator=(Iterator<TBlock>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator bool() const");

    return (m_curr != nullptr && (bool)*m_curr);
}

template<typename TBlock>
Iterator<TBlock>::operator TBlock*()
{
    TEST_SYS_DEBUG_T(SystemType, DebugType, 3, this, "operator %s*()",
        TEST_SYS_DEBUG_T_NAME_STR(TBlock));
    
    static TBlock instance;
    if (m_curr == nullptr) return &instance;
    return (TBlock*)*m_curr;
}

template<typename TBlock>
typename Iterator<TBlock>::NodeType& Iterator<TBlock>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");
    
    static NodeType instance;
    if (m_curr == nullptr) return instance;
    return *m_curr;
}

template<typename TBlock>
typename Iterator<TBlock>::NodeType* Iterator<TBlock>::operator->()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->()");
    
    return m_curr;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator+=(int val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator+=(val=%d)", val);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator+(val=%d)", val);

    Iterator<TBlock> cpy(*this);
    cpy += val;
    return cpy;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator-=(int val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator-=(val=%d)", val);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator-(val=%d)", val);
    
    Iterator<TBlock> cpy(*this);
    cpy -= val;
    return cpy;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");
    
    Iterator<TBlock> cpy(*this);
    operator++();
    return cpy;
}

template<typename TBlock>
Iterator<TBlock>& Iterator<TBlock>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");
    
    Iterator<TBlock> cpy(*this);
    operator--();
    return cpy;
}

template<typename TBlock>
bool Iterator<TBlock>::operator==(const Iterator<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);
    
    return m_curr == other.m_curr;
}

template<typename TBlock>
bool Iterator<TBlock>::operator!=(const Iterator<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);
    
    return m_curr != other.m_curr;
}

template<typename TBlock>
bool Iterator<TBlock>::operator==(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");
    
    return m_curr == nullptr;
}

template<typename TBlock>
bool Iterator<TBlock>::operator!=(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");

    return m_curr != nullptr;
}

template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Iterator<TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%s) const", (val ? "true" : "false"));

    return (m_curr != nullptr) == val;
}
    
template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Iterator<TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%s) const", (val ? "true" : "false"));
    
    return (m_curr != nullptr) != val;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Iterator<TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%p) const", (const void*)val);
    
    return m_curr == (const void*)val;;
}
        
template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Iterator<TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%p) const", (const void*)val);
    
    return m_curr != (const void*)val;;
}

} //!rec

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_REC_ITERATOR_H_
