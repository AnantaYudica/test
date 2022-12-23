#ifndef TEST_BYTE_ITERATOR_H_
#define TEST_BYTE_ITERATOR_H_

#include "../Pointer.h"
#include "it/Operator.h"

#include <cstddef>
#include <cstdint>

namespace test::byte
{
template<typename TPointer, typename TCast, std::size_t NStep>
class Iterator;
}

#ifndef TEST_BYTE_ITERATOR_DLEVEL

#define TEST_BYTE_ITERATOR_DLEVEL 2

#endif //!TEST_BYTE_ITERATOR_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TPointer>,\
    test::sys::dbg::Type<TCast>,\
    test::sys::dbg::type::Value<std::size_t, NStep>

template<typename TPointer, typename TCast, std::size_t NStep>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_BYTE_ITERATOR_DLEVEL, 
    "test::byte::Iterator", 
    test::byte::Iterator<TPointer, TCast, NStep>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace byte
{

template<typename TPointer, typename TCast = std::uint8_t, 
    std::size_t NStep = sizeof(TCast)>
class Iterator
{};

template<typename TCast, std::size_t NStep>
class Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<
        test::byte::Iterator<const test::Pointer<std::uint8_t>, 
        TCast, NStep>> DebugType;
public:
    typedef test::Pointer<std::uint8_t> PointerType;
    typedef const test::Pointer<std::uint8_t> ConstPointerType;
private:
    PointerType m_ptr;
    std::size_t m_begin, m_end, m_pos;
    test::byte::it::Operator m_op;
public:
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op);
public:
    ~Iterator();
public:
    Iterator(const Iterator<ConstPointerType, TCast, NStep>& cpy);
    Iterator(Iterator<ConstPointerType, TCast, NStep>&& mov);
public:
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator=(const Iterator<ConstPointerType, TCast, NStep>& cpy);
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator=(Iterator<ConstPointerType, TCast, NStep>&& mov);
public:
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator+=(const std::size_t& index);
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator-=(const std::size_t& index);
public:
    const TCast& operator*() const;
public:
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& operator++();
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> operator++(int);
public:
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& operator--();
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> operator--(int);
public:
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
        operator+(const std::size_t& index);
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
        operator-(const std::size_t& index);
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
        operator+(const int& index);
    Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
        operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
    bool operator!=(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
};

template<typename TCast, std::size_t NStep>
class Iterator<test::Pointer<std::uint8_t>, TCast, NStep> :
    public Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<
        test::byte::Iterator<const test::Pointer<std::uint8_t>, 
            TCast, NStep>> DebugType;
public:
    typedef test::Pointer<std::uint8_t> PointerType;
    typedef const test::Pointer<std::uint8_t> ConstPointerType;
public:
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op);
public:
    ~Iterator();
public:
    Iterator(const Iterator<PointerType, TCast, NStep>& cpy);
    Iterator(Iterator<PointerType, TCast, NStep>&& mov);
public:
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator=(const Iterator<PointerType, TCast, NStep> & cpy);
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator=(Iterator<PointerType, TCast, NStep> && mov);
public:
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator+=(const std::size_t& index);
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
        operator-=(const std::size_t& index);
public:
    TCast& operator*();
    const TCast& operator*() const;
public:
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& operator++();
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>  operator++(int);
public:
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& operator--();
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep> operator--(int);
public:
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
        operator+(const std::size_t& index);
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
        operator-(const std::size_t& index);
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
        operator+(const int& index);
    Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
        operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
    bool operator!=(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
};

template<typename TCast, std::size_t NStep>
class Iterator<const std::uint8_t*, TCast, NStep>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<
        test::byte::Iterator<const std::uint8_t*, TCast, NStep>> DebugType;
public:
    typedef std::uint8_t* PointerType;
    typedef const std::uint8_t* ConstPointerType;
private:
    PointerType m_ptr;
    std::size_t m_begin, m_end, m_pos;
    test::byte::it::Operator m_op;
public:
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op);
public:
    ~Iterator();
public:
    Iterator(const Iterator<ConstPointerType, TCast, NStep>& cpy);
    Iterator(Iterator<ConstPointerType, TCast, NStep>&& mov);
public:
    Iterator<const std::uint8_t*, TCast, NStep>& 
        operator=(const Iterator<ConstPointerType, TCast, NStep>& cpy);
    Iterator<const std::uint8_t*, TCast, NStep>& 
        operator=(Iterator<ConstPointerType, TCast, NStep>&& mov);
public:
    Iterator<const std::uint8_t*, TCast, NStep>& 
        operator+=(const std::size_t& index);
    Iterator<const std::uint8_t*, TCast, NStep>& 
        operator-=(const std::size_t& index);
public:
    const TCast& operator*() const;
public:
    Iterator<const std::uint8_t*, TCast, NStep>& operator++();
    Iterator<const std::uint8_t*, TCast, NStep> operator++(int);
public:
    Iterator<const std::uint8_t*, TCast, NStep>& operator--();
    Iterator<const std::uint8_t*, TCast, NStep> operator--(int);
public:
    Iterator<const std::uint8_t*, TCast, NStep> 
        operator+(const std::size_t& index);
    Iterator<const std::uint8_t*, TCast, NStep> 
        operator-(const std::size_t& index);
    Iterator<const std::uint8_t*, TCast, NStep> operator+(const int& index);
    Iterator<const std::uint8_t*, TCast, NStep> operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
    bool operator!=(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
};

template<typename TCast, std::size_t NStep>
class Iterator<std::uint8_t*, TCast, NStep> : 
    public Iterator<const std::uint8_t*, TCast, NStep>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<
        test::byte::Iterator<std::uint8_t*, TCast, NStep>> DebugType;
public:
    typedef std::uint8_t* PointerType;
    typedef const std::uint8_t* ConstPointerType;
public:
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op);
public:
    ~Iterator();
public:
    Iterator(const Iterator<PointerType, TCast, NStep>& cpy);
    Iterator(Iterator<PointerType, TCast, NStep>&& mov);
public:
    Iterator<std::uint8_t*, TCast, NStep>& 
        operator=(const Iterator<PointerType, TCast, NStep>& cpy);
    Iterator<std::uint8_t*, TCast, NStep>& 
        operator=(Iterator<PointerType, TCast, NStep>&& mov);
public:
    Iterator<std::uint8_t*, TCast, NStep>& 
        operator+=(const std::size_t& index);
    Iterator<std::uint8_t*, TCast, NStep>& 
        operator-=(const std::size_t& index);
public:
    TCast& operator*();
    const TCast& operator*() const;
public:
    Iterator<std::uint8_t*, TCast, NStep>& operator++();
    Iterator<std::uint8_t*, TCast, NStep> operator++(int);
public:
    Iterator<std::uint8_t*, TCast, NStep>& operator--();
    Iterator<std::uint8_t*, TCast, NStep> operator--(int);
public:
    Iterator<std::uint8_t*, TCast, NStep> operator+(const std::size_t& index);
    Iterator<std::uint8_t*, TCast, NStep> operator-(const std::size_t& index);
    Iterator<std::uint8_t*, TCast, NStep> operator+(const int& index);
    Iterator<std::uint8_t*, TCast, NStep> operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
    bool operator!=(const Iterator<ConstPointerType, 
        TCast, NStep>& other) const;
};

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end, 
        const std::size_t& index, const test::byte::it::Operator& op) :
            m_ptr(ptr),
            m_begin(begin),
            m_end(end),
            m_pos(index),
            m_op(op)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p, begin=%zu, end=%zu, index=%zu, op=%p)", 
        &*ptr, begin, end, index, &op);

    m_ptr.SetIndex(index);
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::~Iterator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    Iterator(const Iterator<ConstPointerType, TCast, NStep>& cpy) :
        m_ptr(cpy.m_ptr),
        m_begin(cpy.m_begin),
        m_end(cpy.m_end),
        m_pos(cpy.m_pos),
        m_op(cpy.m_op)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    Iterator(Iterator<ConstPointerType, TCast, NStep>&& mov) :
        m_ptr(mov.m_ptr),
        m_begin(mov.m_begin),
        m_end(mov.m_end),
        m_pos(mov.m_pos),
        m_op(mov.m_op)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator=(const Iterator<ConstPointerType, TCast, NStep>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_ptr = cpy.m_ptr;
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    m_pos = cpy.m_pos;
    m_op = cpy.m_op;
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator=(Iterator<ConstPointerType, TCast, NStep>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    m_ptr = mov.m_ptr;
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    m_pos = mov.m_pos;
    m_op = mov.m_op;
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    auto new_pos = m_op.Addition(m_pos, NStep * index);
    m_ptr.SetIndex(new_pos);
    m_pos = new_pos;
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    auto new_pos = m_op.Subtraction(m_pos, NStep * index);
    m_ptr.SetIndex(new_pos);
    m_pos = new_pos;
    return *this;
}

template<typename TCast, std::size_t NStep>
const TCast& Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    static TCast _def;
    _def = 0;
    if (m_pos < m_begin || (m_pos + NStep) > m_end) return _def;
    
    return *(reinterpret_cast<const TCast*>(
        (std::uint8_t*)(m_ptr.GetData()) + m_pos));
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    return *this += 1;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Iterator<ConstPointerType> ret{*this};
    operator++();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    return *this -= 1;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Iterator<ConstPointerType> ret{*this};
    operator--();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%zu)", index);

    Iterator<ConstPointerType> ret{*this};
    ret += index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%zu)", index);

    Iterator<ConstPointerType> ret{*this};
    ret -= index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

template<typename TCast, std::size_t NStep>
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename TCast, std::size_t NStep>
bool Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator==(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    const std::size_t index = m_pos;
    const std::size_t other_index = other.m_pos;
    return m_ptr == other.m_ptr.GetData() &&
        (index == other_index || ((index < m_begin || index >= m_end) &&
        (other_index < other.m_begin || other_index >= other.m_end)));
}

template<typename TCast, std::size_t NStep>
bool Iterator<const test::Pointer<std::uint8_t>, TCast, NStep>::
    operator!=(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !(*this == other);
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op) :
            Iterator<ConstPointerType, TCast, NStep>(ptr, begin, end, 
                index, op)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p, begin=%zu, end=%zu, index=%zu, op=%p)", 
        &*ptr, begin, end, index, &op);

}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::~Iterator()
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    Iterator(const Iterator<PointerType, TCast, NStep>& cpy) :
        Iterator<ConstPointerType, TCast, NStep>(cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    Iterator(Iterator<PointerType, TCast, NStep>&& mov) :
        Iterator<ConstPointerType, TCast, NStep>(std::move(mov))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator=(const Iterator<PointerType, TCast, NStep>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    Iterator<ConstPointerType, TCast, NStep>::operator=(cpy);
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator=(Iterator<PointerType, TCast, NStep>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    Iterator<ConstPointerType, TCast, NStep>::operator=(std::move(mov));
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    Iterator<ConstPointerType, TCast, NStep>::operator+=(index);
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    Iterator<ConstPointerType, TCast, NStep>::operator-=(index);
    return *this;
}

template<typename TCast, std::size_t NStep>
TCast& Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");

    return const_cast<TCast&>(Iterator<ConstPointerType, 
        TCast, NStep>::operator*());
}

template<typename TCast, std::size_t NStep>
const TCast& Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return Iterator<ConstPointerType, TCast, NStep>::operator*();
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    return *this += 1;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Iterator<PointerType> ret{*this};
    operator++();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>& 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    return *this -= 1;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Iterator<PointerType> ret{*this};
    operator--();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this,
        "operator+(index=%zu)", index);

    Iterator<PointerType> ret{*this};
    ret += index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this,
        "operator-(index=%zu)", index);

    Iterator<PointerType> ret{*this};
    ret -= index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this,
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

template<typename TCast, std::size_t NStep>
Iterator<test::Pointer<std::uint8_t>, TCast, NStep> 
Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this,
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename TCast, std::size_t NStep>
bool Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator==(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return Iterator<ConstPointerType>::operator==(other);
}

template<typename TCast, std::size_t NStep>
bool Iterator<test::Pointer<std::uint8_t>, TCast, NStep>::
    operator!=(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !(*this == other);
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>::Iterator(PointerType ptr, 
    const std::size_t& begin, const std::size_t& end, 
    const std::size_t& index, const test::byte::it::Operator& op) :
        m_ptr(ptr),
        m_begin(begin),
        m_end(end),
        m_pos(index),
        m_op(op)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p, begin=%zu, end=%zu, index=%zu, op=%p)", 
        &*ptr, begin, end, index, &op);

}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>::~Iterator()
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>::
    Iterator(const Iterator<ConstPointerType, TCast, NStep>& cpy) :
        m_ptr(const_cast<std::uint8_t*>(cpy.m_ptr)),
        m_begin(cpy.m_begin),
        m_end(cpy.m_end),
        m_pos(cpy.m_pos),
        m_op(cpy.m_op)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>::
    Iterator(Iterator<ConstPointerType, TCast, NStep>&& mov) :
        m_ptr(mov.m_ptr),
        m_begin(mov.m_begin),
        m_end(mov.m_end),
        m_pos(mov.m_pos),
        m_op(mov.m_op)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>& 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator=(const Iterator<ConstPointerType, TCast, NStep>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_ptr = cpy.m_ptr;
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    m_pos = cpy.m_pos;
    m_op = cpy.m_op;
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>& 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator=(Iterator<ConstPointerType, TCast, NStep>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    m_ptr = mov.m_ptr;
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    m_pos = mov.m_pos;
    m_op = mov.m_op;
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>& 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    m_pos = m_op.Addition(m_pos, NStep * index);
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>& 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    m_pos = m_op.Subtraction(m_pos, NStep * index);
    return *this;
}

template<typename TCast, std::size_t NStep>
const TCast& Iterator<const std::uint8_t*, TCast, NStep>::operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    static TCast _def;
    _def = 0;
    if (m_pos < m_begin || (m_pos + NStep) > m_end) return _def;
    return reinterpret_cast<const TCast&>(*(m_ptr + m_pos));
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>& 
Iterator<const std::uint8_t*, TCast, NStep>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    return *this += 1;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep> 
Iterator<const std::uint8_t*, TCast, NStep>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Iterator<ConstPointerType, TCast, NStep> ret{*this};
    operator++();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep>& 
Iterator<const std::uint8_t*, TCast, NStep>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    return *this -= 1;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep> 
Iterator<const std::uint8_t*, TCast, NStep>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Iterator<ConstPointerType, TCast, NStep> ret{*this};
    operator--();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep> 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%zu)", index);

    Iterator<ConstPointerType, TCast, NStep> ret{*this};
    ret += index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep> 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%zu)", index);

    Iterator<ConstPointerType, TCast, NStep> ret{*this};
    ret -= index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep> 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

template<typename TCast, std::size_t NStep>
Iterator<const std::uint8_t*, TCast, NStep> 
Iterator<const std::uint8_t*, TCast, NStep>::
    operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename TCast, std::size_t NStep>
bool Iterator<const std::uint8_t*, TCast, NStep>::
    operator==(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    const std::size_t other_index = other.m_pos;
    return m_ptr == other.m_ptr &&
        (m_pos == other_index || ((m_pos < m_begin || m_pos >= m_end) &&
        (other_index < other.m_begin || other_index >= other.m_end)));
}

template<typename TCast, std::size_t NStep>
bool Iterator<const std::uint8_t*, TCast, NStep>::
    operator!=(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !(*this == other);
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>::Iterator(PointerType ptr, 
    const std::size_t& begin, const std::size_t& end, const std::size_t& index,
    const test::byte::it::Operator& op) :
        Iterator<ConstPointerType, TCast, NStep>(ptr, begin, end, index, op)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p, begin=%zu, end=%zu, index=%zu, op=%p)", 
        &*ptr, begin, end, index, &op);

}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>::~Iterator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>::
    Iterator(const Iterator<PointerType, TCast, NStep>& cpy) :
        Iterator<ConstPointerType, TCast, NStep>(cpy)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>::
    Iterator(Iterator<PointerType, TCast, NStep>&& mov) :
        Iterator<ConstPointerType, TCast, NStep>(std::move(mov))
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>& 
Iterator<std::uint8_t*, TCast, NStep>::
    operator=(const Iterator<PointerType, TCast, NStep>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    Iterator<ConstPointerType, TCast, NStep>::operator=(cpy);
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>& 
Iterator<std::uint8_t*, TCast, NStep>::
    operator=(Iterator<PointerType, TCast, NStep>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    Iterator<ConstPointerType, TCast, NStep>::operator=(std::move(mov));
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>& 
Iterator<std::uint8_t*, TCast, NStep>::
    operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    Iterator<ConstPointerType, TCast, NStep>::operator+=(index);
    return *this;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>& 
Iterator<std::uint8_t*, TCast, NStep>::
    operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    Iterator<ConstPointerType, TCast, NStep>::operator-=(index);
    return *this;
}

template<typename TCast, std::size_t NStep>
TCast& Iterator<std::uint8_t*, TCast, NStep>::operator*()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*()");

    return const_cast<TCast&>(Iterator<ConstPointerType,
        TCast, NStep>::operator*());
}

template<typename TCast, std::size_t NStep>
const TCast& Iterator<std::uint8_t*, TCast, NStep>::
    operator*() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator*() const");

    return Iterator<ConstPointerType, TCast, NStep>::operator*();
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>& 
Iterator<std::uint8_t*, TCast, NStep>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    return *this += 1;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep> 
Iterator<std::uint8_t*, TCast, NStep>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Iterator<PointerType> ret{*this};
    operator++();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep>& 
Iterator<std::uint8_t*, TCast, NStep>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    return *this -= 1;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep> 
Iterator<std::uint8_t*, TCast, NStep>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Iterator<PointerType> ret{*this};
    operator--();
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep> 
Iterator<std::uint8_t*, TCast, NStep>::
    operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%zu)", index);

    Iterator<PointerType> ret{*this};
    ret += index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep> 
Iterator<std::uint8_t*, TCast, NStep>::
    operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%zu)", index);

    Iterator<PointerType> ret{*this};
    ret -= index;
    return ret;
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep> 
Iterator<std::uint8_t*, TCast, NStep>::operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

template<typename TCast, std::size_t NStep>
Iterator<std::uint8_t*, TCast, NStep> 
Iterator<std::uint8_t*, TCast, NStep>::operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<typename TCast, std::size_t NStep>
bool Iterator<std::uint8_t*, TCast, NStep>::
    operator==(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);

    return Iterator<ConstPointerType, TCast, NStep>::operator==(other);
}

template<typename TCast, std::size_t NStep>
bool Iterator<std::uint8_t*, TCast, NStep>::
    operator!=(const Iterator<ConstPointerType, TCast, NStep>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);

    return !(*this == other);
}

} //!byte

} //!test

#endif //!TEST_BYTE_ITERATOR_H_
