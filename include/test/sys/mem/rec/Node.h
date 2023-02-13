#ifndef TEST_SYS_MEM_REC_NODE_H_
#define TEST_SYS_MEM_REC_NODE_H_

#include "../../Interface.h"
#include "../../Debug.h"

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
class Node;

} //!rec

} //!mem

} //!sys

} //!test

#ifndef TEST_SYS_MEM_REC_NODE_DLEVEL

#define TEST_SYS_MEM_REC_NODE_DLEVEL 2

#endif //!TEST_SYS_MEM_REC_NODE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TBlock>

template<typename TBlock>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_SYS_MEM_REC_NODE_DLEVEL, 
    "test::sys::mem::rec::Node", 
    test::sys::mem::rec::Node<TBlock>);

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
class Node
{
private:
    typedef test::sys::Definition DefinitionType;
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::sys::mem::rec::Node<TBlock>> DebugType;
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
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TBlock>
Node<TBlock>::Node(TBlock* data) :
    m_next(nullptr),
    m_prev(nullptr),
    m_data(data)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(data=%p)", data);

}

template<typename TBlock>
Node<TBlock>::Node(const Node<TBlock>& cpy) :
    m_next(cpy.m_next),
    m_prev(cpy.m_prev),
    m_data(cpy.m_data)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename TBlock>
Node<TBlock>::Node(Node<TBlock>&& mov) :
    m_next(mov.m_next),
    m_prev(mov.m_prev),
    m_data(mov.m_data)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.m_next = nullptr;
    mov.m_prev = nullptr;
    mov.m_data = nullptr;
}

template<typename TBlock>
Node<TBlock>::~Node()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
    m_next = nullptr;
    m_prev = nullptr;
    m_data = nullptr;
}

template<typename TBlock>
Node<TBlock>& Node<TBlock>::operator=(TBlock* set)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment(set=%p)", set);
    
    m_data = set;
    return *this;
}

template<typename TBlock>
Node<TBlock>& Node<TBlock>::operator=(const Node<TBlock>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_next = cpy.m_next;
    m_prev = cpy.m_prev;
    m_data = cpy.m_data;
    return *this;
}

template<typename TBlock>
Node<TBlock>& Node<TBlock>::operator=(Node<TBlock>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Next()");
    
    return m_next;
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Next(Node<TBlock> *set)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Next(set=%p)", set);
    
    return (m_next = set);
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Prev()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Prev()");
    
    return m_prev;
}

template<typename TBlock>
Node<TBlock>* Node<TBlock>::Prev(Node<TBlock> *set)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Prev(set=%p)", set);
    
    return (m_prev = set);
}

template<typename TBlock>
Node<TBlock>::operator bool() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator bool() const");
    
    return (m_data != nullptr);
}

template<typename TBlock>
Node<TBlock>::operator TBlock*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator %s*()",
        TEST_SYS_DEBUG_T_NAME_STR(TBlock));

    return m_data;
}

template<typename TBlock>
TBlock& Node<TBlock>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");
    
    return *m_data;
}

template<typename TBlock>
TBlock* Node<TBlock>::operator->()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator->()");
    
    return m_data;
}

template<typename TBlock>
bool Node<TBlock>::operator==(const Node<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);
    
    return m_data == other.m_data;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(const Node<TBlock>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);
    
    return m_data != other.m_data;
}

template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Node<TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%s) const", (val ? "true" : "false"));

    return (bool)*this == val;
}
    
template<typename TBlock>
template<typename TValue>
typename std::enable_if<std::is_same<TValue, bool>::value, bool>::type 
Node<TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%s) const", (val ? "true" : "false"));

    return (bool)*this != val;
}


template<typename TBlock>
bool Node<TBlock>::operator==(const TBlock* other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", other);
    
    return m_data == other;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(const TBlock* other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", other);
    
    return m_data != other;
}

template<typename TBlock>
bool Node<TBlock>::operator==(TBlock* other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", other);
    
    return m_data == other;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(TBlock* other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", other);
    
    return m_data != other;
}

template<typename TBlock>
bool Node<TBlock>::operator==(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(nullptr) const");
    
    return m_data == nullptr;
}

template<typename TBlock>
bool Node<TBlock>::operator!=(std::nullptr_t) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(nullptr) const");
    
    return m_data != nullptr;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Node<TBlock>::operator==(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%p) const", (const void*)val);
    
    return m_data == (const void*)val;
}

template<typename TBlock>
template<typename TValue, typename TNull>
typename std::enable_if<!std::is_same<TNull, void*>::value
    && std::is_same<TValue, TNull>::value, bool>::type 
Node<TBlock>::operator!=(const TValue& val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%p) const", (const void*)val);
    
    return m_data != (const void*)val;
}

} //!rec

} //!mem

} //!sys

} //!test

#endif //!TEST_SYS_MEM_REC_NODE_H_
