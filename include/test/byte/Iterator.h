#ifndef TEST_BYTE_ITERATOR_H_
#define TEST_BYTE_ITERATOR_H_

#include "../Pointer.h"
#include "it/Operator.h"

#include <cstddef>
#include <cstdint>

namespace test
{
namespace byte
{

template<typename TPointer>
class Iterator
{};

template<>
class Iterator<const test::Pointer<std::uint8_t>>
{
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
    Iterator(const Iterator<ConstPointerType>& cpy);
    Iterator(Iterator<ConstPointerType>&& mov);
public:
    Iterator<const test::Pointer<std::uint8_t>>& 
        operator=(const Iterator<ConstPointerType>& cpy);
    Iterator<const test::Pointer<std::uint8_t>>& 
        operator=(Iterator<ConstPointerType>&& mov);
public:
    Iterator<const test::Pointer<std::uint8_t>>& 
        operator+=(const std::size_t& index);
    Iterator<const test::Pointer<std::uint8_t>>& 
        operator-=(const std::size_t& index);
public:
    const std::uint8_t& operator*() const;
public:
    Iterator<const test::Pointer<std::uint8_t>>& operator++();
    Iterator<const test::Pointer<std::uint8_t>> operator++(int);
public:
    Iterator<const test::Pointer<std::uint8_t>>& operator--();
    Iterator<const test::Pointer<std::uint8_t>> operator--(int);
public:
    Iterator<const test::Pointer<std::uint8_t>> 
        operator+(const std::size_t& index);
    Iterator<const test::Pointer<std::uint8_t>> 
        operator-(const std::size_t& index);
    Iterator<const test::Pointer<std::uint8_t>> operator+(const int& index);
    Iterator<const test::Pointer<std::uint8_t>> operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType>& other) const;
    bool operator!=(const Iterator<ConstPointerType>& other) const;
};

template<>
class Iterator<test::Pointer<std::uint8_t>> :
    public Iterator<const test::Pointer<std::uint8_t>>
{
public:
    typedef test::Pointer<std::uint8_t> PointerType;
    typedef const test::Pointer<std::uint8_t> ConstPointerType;
public:
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op);
public:
    ~Iterator();
public:
    Iterator(const Iterator<PointerType>& cpy);
    Iterator(Iterator<PointerType>&& mov);
public:
    Iterator<test::Pointer<std::uint8_t>>& 
        operator=(const Iterator<PointerType> & cpy);
    Iterator<test::Pointer<std::uint8_t>>& 
        operator=(Iterator<PointerType> && mov);
public:
    Iterator<test::Pointer<std::uint8_t>>& 
        operator+=(const std::size_t& index);
    Iterator<test::Pointer<std::uint8_t>>& 
        operator-=(const std::size_t& index);
public:
    std::uint8_t& operator*();
    const std::uint8_t& operator*() const;
public:
    Iterator<test::Pointer<std::uint8_t>>& operator++();
    Iterator<test::Pointer<std::uint8_t>>  operator++(int);
public:
    Iterator<test::Pointer<std::uint8_t>>& operator--();
    Iterator<test::Pointer<std::uint8_t>> operator--(int);
public:
    Iterator<test::Pointer<std::uint8_t>> operator+(const std::size_t& index);
    Iterator<test::Pointer<std::uint8_t>> operator-(const std::size_t& index);
    Iterator<test::Pointer<std::uint8_t>> operator+(const int& index);
    Iterator<test::Pointer<std::uint8_t>> operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType>& other) const;
    bool operator!=(const Iterator<ConstPointerType>& other) const;
};

template<>
class Iterator<const std::uint8_t*>
{
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
    Iterator(const Iterator<ConstPointerType>& cpy);
    Iterator(Iterator<ConstPointerType>&& mov);
public:
    Iterator<const std::uint8_t*>& 
        operator=(const Iterator<ConstPointerType>& cpy);
    Iterator<const std::uint8_t*>& 
        operator=(Iterator<ConstPointerType>&& mov);
public:
    Iterator<const std::uint8_t*>& operator+=(const std::size_t& index);
    Iterator<const std::uint8_t*>& operator-=(const std::size_t& index);
public:
    const std::uint8_t& operator*() const;
public:
    Iterator<const std::uint8_t*>& operator++();
    Iterator<const std::uint8_t*> operator++(int);
public:
    Iterator<const std::uint8_t*>& operator--();
    Iterator<const std::uint8_t*> operator--(int);
public:
    Iterator<const std::uint8_t*> operator+(const std::size_t& index);
    Iterator<const std::uint8_t*> operator-(const std::size_t& index);
    Iterator<const std::uint8_t*> operator+(const int& index);
    Iterator<const std::uint8_t*> operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType>& other) const;
    bool operator!=(const Iterator<ConstPointerType>& other) const;
};

template<>
class Iterator<std::uint8_t*> : public Iterator<const std::uint8_t*>
{
public:
    typedef std::uint8_t* PointerType;
    typedef const std::uint8_t* ConstPointerType;
public:
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op);
public:
    ~Iterator();
public:
    Iterator(const Iterator<PointerType>& cpy);
    Iterator(Iterator<PointerType>&& mov);
public:
    Iterator<std::uint8_t*>& operator=(const Iterator<PointerType>& cpy);
    Iterator<std::uint8_t*>& operator=(Iterator<PointerType>&& mov);
public:
    Iterator<std::uint8_t*>& operator+=(const std::size_t& index);
    Iterator<std::uint8_t*>& operator-=(const std::size_t& index);
public:
    std::uint8_t& operator*();
    const std::uint8_t& operator*() const;
public:
    Iterator<std::uint8_t*>& operator++();
    Iterator<std::uint8_t*> operator++(int);
public:
    Iterator<std::uint8_t*>& operator--();
    Iterator<std::uint8_t*> operator--(int);
public:
    Iterator<std::uint8_t*> operator+(const std::size_t& index);
    Iterator<std::uint8_t*> operator-(const std::size_t& index);
    Iterator<std::uint8_t*> operator+(const int& index);
    Iterator<std::uint8_t*> operator-(const int& index);
public:
    bool operator==(const Iterator<ConstPointerType>& other) const;
    bool operator!=(const Iterator<ConstPointerType>& other) const;
};

Iterator<const test::Pointer<std::uint8_t>>::
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end, 
        const std::size_t& index, const test::byte::it::Operator& op) :
            m_ptr(ptr),
            m_begin(begin),
            m_end(end),
            m_pos(index),
            m_op(op)
{
    m_ptr.SetIndex(index);
}

Iterator<const test::Pointer<std::uint8_t>>::~Iterator()
{}

Iterator<const test::Pointer<std::uint8_t>>::
    Iterator(const Iterator<ConstPointerType>& cpy) :
        m_ptr(cpy.m_ptr),
        m_begin(cpy.m_begin),
        m_end(cpy.m_end),
        m_pos(cpy.m_pos),
        m_op(cpy.m_op)
{}

Iterator<const test::Pointer<std::uint8_t>>::
    Iterator(Iterator<ConstPointerType>&& mov) :
        m_ptr(mov.m_ptr),
        m_begin(mov.m_begin),
        m_end(mov.m_end),
        m_pos(mov.m_pos),
        m_op(mov.m_op)
{}

Iterator<const test::Pointer<std::uint8_t>>& 
Iterator<const test::Pointer<std::uint8_t>>::
    operator=(const Iterator<ConstPointerType>& cpy)
{
    m_ptr = cpy.m_ptr;
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    m_pos = cpy.m_pos;
    m_op = cpy.m_op;
    return *this;
}

Iterator<const test::Pointer<std::uint8_t>>& 
Iterator<const test::Pointer<std::uint8_t>>::
    operator=(Iterator<ConstPointerType>&& mov)
{
    m_ptr = mov.m_ptr;
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    m_pos = mov.m_pos;
    m_op = mov.m_op;
    return *this;
}

Iterator<const test::Pointer<std::uint8_t>>& 
Iterator<const test::Pointer<std::uint8_t>>::
    operator+=(const std::size_t& index)
{
    auto new_pos = m_op.Addition(m_pos, index);
    m_ptr.SetIndex(new_pos);
    m_pos = new_pos;
    return *this;
}

Iterator<const test::Pointer<std::uint8_t>>& 
Iterator<const test::Pointer<std::uint8_t>>::
    operator-=(const std::size_t& index)
{
    auto new_pos = m_op.Subtraction(m_pos, index);
    m_ptr.SetIndex(new_pos);
    m_pos = new_pos;
    return *this;
}

const std::uint8_t& Iterator<const test::Pointer<std::uint8_t>>::
    operator*() const
{
    return *m_ptr;
}

Iterator<const test::Pointer<std::uint8_t>>& 
Iterator<const test::Pointer<std::uint8_t>>::operator++()
{
    return *this += 1;
}

Iterator<const test::Pointer<std::uint8_t>> 
Iterator<const test::Pointer<std::uint8_t>>::operator++(int)
{
    Iterator<ConstPointerType> ret{*this};
    operator++();
    return ret;
}

Iterator<const test::Pointer<std::uint8_t>>& 
Iterator<const test::Pointer<std::uint8_t>>::operator--()
{
    return *this -= 1;
}

Iterator<const test::Pointer<std::uint8_t>> 
Iterator<const test::Pointer<std::uint8_t>>::operator--(int)
{
    Iterator<ConstPointerType> ret{*this};
    operator--();
    return ret;
}

Iterator<const test::Pointer<std::uint8_t>> 
Iterator<const test::Pointer<std::uint8_t>>::
    operator+(const std::size_t& index)
{
    Iterator<ConstPointerType> ret{*this};
    ret += index;
    return ret;
}

Iterator<const test::Pointer<std::uint8_t>> 
Iterator<const test::Pointer<std::uint8_t>>::
    operator-(const std::size_t& index)
{
    Iterator<ConstPointerType> ret{*this};
    ret -= index;
    return ret;
}

Iterator<const test::Pointer<std::uint8_t>> 
Iterator<const test::Pointer<std::uint8_t>>::operator+(const int& index)
{
    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

Iterator<const test::Pointer<std::uint8_t>> 
Iterator<const test::Pointer<std::uint8_t>>::operator-(const int& index)
{
    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

bool Iterator<const test::Pointer<std::uint8_t>>::
    operator==(const Iterator<ConstPointerType>& other) const
{
    const std::size_t index = m_pos;
    const std::size_t other_index = other.m_pos;
    return m_ptr == other.m_ptr.GetData() &&
        (index == other_index || ((index < m_begin || index >= m_end) &&
        (other_index < other.m_begin || other_index >= other.m_end)));
}

bool Iterator<const test::Pointer<std::uint8_t>>::
    operator!=(const Iterator<ConstPointerType>& other) const
{
    return !(*this == other);
}

Iterator<test::Pointer<std::uint8_t>>::
    Iterator(PointerType ptr, const std::size_t& begin, const std::size_t& end,
        const std::size_t& index, const test::byte::it::Operator& op) :
            Iterator<ConstPointerType>(ptr, begin, end, index, op)
{}

Iterator<test::Pointer<std::uint8_t>>::~Iterator()
{}

Iterator<test::Pointer<std::uint8_t>>::
    Iterator(const Iterator<PointerType>& cpy) :
        Iterator<ConstPointerType>(cpy)
{}

Iterator<test::Pointer<std::uint8_t>>::
    Iterator(Iterator<PointerType>&& mov) :
        Iterator<ConstPointerType>(std::move(mov))
{}

Iterator<test::Pointer<std::uint8_t>>& Iterator<test::Pointer<std::uint8_t>>::
    operator=(const Iterator<PointerType>& cpy)
{
    Iterator<ConstPointerType>::operator=(cpy);
    return *this;
}

Iterator<test::Pointer<std::uint8_t>>& Iterator<test::Pointer<std::uint8_t>>::
    operator=(Iterator<PointerType>&& mov)
{
    Iterator<ConstPointerType>::operator=(std::move(mov));
    return *this;
}

Iterator<test::Pointer<std::uint8_t>>& 
Iterator<test::Pointer<std::uint8_t>>::operator+=(const std::size_t& index)
{
    Iterator<ConstPointerType>::operator+=(index);
    return *this;
}

Iterator<test::Pointer<std::uint8_t>>& 
Iterator<test::Pointer<std::uint8_t>>::operator-=(const std::size_t& index)
{
    Iterator<ConstPointerType>::operator-=(index);
    return *this;
}

std::uint8_t& Iterator<test::Pointer<std::uint8_t>>::operator*()
{
    return const_cast<std::uint8_t&>(Iterator<ConstPointerType>::operator*());
}

const std::uint8_t& Iterator<test::Pointer<std::uint8_t>>::
    operator*() const
{
    return Iterator<ConstPointerType>::operator*();
}

Iterator<test::Pointer<std::uint8_t>>& 
Iterator<test::Pointer<std::uint8_t>>::operator++()
{
    return *this += 1;
}

Iterator<test::Pointer<std::uint8_t>> 
Iterator<test::Pointer<std::uint8_t>>::operator++(int)
{
    Iterator<PointerType> ret{*this};
    operator++();
    return ret;
}

Iterator<test::Pointer<std::uint8_t>>& 
Iterator<test::Pointer<std::uint8_t>>::operator--()
{
    return *this -= 1;
}

Iterator<test::Pointer<std::uint8_t>> 
Iterator<test::Pointer<std::uint8_t>>::operator--(int)
{
    Iterator<PointerType> ret{*this};
    operator--();
    return ret;
}

Iterator<test::Pointer<std::uint8_t>> 
Iterator<test::Pointer<std::uint8_t>>::operator+(const std::size_t& index)
{
    Iterator<PointerType> ret{*this};
    ret += index;
    return ret;
}

Iterator<test::Pointer<std::uint8_t>> 
Iterator<test::Pointer<std::uint8_t>>::operator-(const std::size_t& index)
{
    Iterator<PointerType> ret{*this};
    ret -= index;
    return ret;
}

Iterator<test::Pointer<std::uint8_t>> 
Iterator<test::Pointer<std::uint8_t>>::operator+(const int& index)
{
    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

Iterator<test::Pointer<std::uint8_t>> 
Iterator<test::Pointer<std::uint8_t>>::operator-(const int& index)
{
    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

bool Iterator<test::Pointer<std::uint8_t>>::
    operator==(const Iterator<ConstPointerType>& other) const
{
    return Iterator<ConstPointerType>::operator==(other);
}

bool Iterator<test::Pointer<std::uint8_t>>::
    operator!=(const Iterator<ConstPointerType>& other) const
{
    return !(*this == other);
}

Iterator<const std::uint8_t*>::Iterator(PointerType ptr, 
    const std::size_t& begin, const std::size_t& end, 
    const std::size_t& index, const test::byte::it::Operator& op) :
        m_ptr(ptr),
        m_begin(begin),
        m_end(end),
        m_pos(index),
        m_op(op)
{}

Iterator<const std::uint8_t*>::~Iterator()
{}

Iterator<const std::uint8_t*>::
    Iterator(const Iterator<ConstPointerType>& cpy) :
        m_ptr(const_cast<std::uint8_t*>(cpy.m_ptr)),
        m_begin(cpy.m_begin),
        m_end(cpy.m_end),
        m_pos(cpy.m_pos),
        m_op(cpy.m_op)
{}

Iterator<const std::uint8_t*>::Iterator(Iterator<ConstPointerType>&& mov) :
    m_ptr(mov.m_ptr),
    m_begin(mov.m_begin),
    m_end(mov.m_end),
    m_pos(mov.m_pos),
    m_op(mov.m_op)
{}

Iterator<const std::uint8_t*>& Iterator<const std::uint8_t*>::
    operator=(const Iterator<ConstPointerType>& cpy)
{
    m_ptr = cpy.m_ptr;
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    m_pos = cpy.m_pos;
    m_op = cpy.m_op;
    return *this;
}

Iterator<const std::uint8_t*>& Iterator<const std::uint8_t*>::
    operator=(Iterator<ConstPointerType>&& mov)
{
    m_ptr = mov.m_ptr;
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    m_pos = mov.m_pos;
    m_op = mov.m_op;
    return *this;
}

Iterator<const std::uint8_t*>& Iterator<const std::uint8_t*>::
    operator+=(const std::size_t& index)
{
    m_pos = m_op.Addition(m_pos, index);
    return *this;
}

Iterator<const std::uint8_t*>& Iterator<const std::uint8_t*>::
    operator-=(const std::size_t& index)
{
    m_pos = m_op.Subtraction(m_pos, index);
    return *this;
}

const std::uint8_t& Iterator<const std::uint8_t*>::operator*() const
{
    static std::uint8_t _def;
    _def = 0;
    if (m_pos < m_begin || m_pos >= m_end) return _def;
    return *(m_ptr + m_pos);
}

Iterator<const std::uint8_t*>& Iterator<const std::uint8_t*>::operator++()
{
    return *this += 1;
}

Iterator<const std::uint8_t*> Iterator<const std::uint8_t*>::operator++(int)
{
    Iterator<ConstPointerType> ret{*this};
    operator++();
    return ret;
}

Iterator<const std::uint8_t*>& Iterator<const std::uint8_t*>::operator--()
{
    return *this -= 1;
}

Iterator<const std::uint8_t*> Iterator<const std::uint8_t*>::operator--(int)
{
    Iterator<ConstPointerType> ret{*this};
    operator--();
    return ret;
}

Iterator<const std::uint8_t*> Iterator<const std::uint8_t*>::
    operator+(const std::size_t& index)
{
    Iterator<ConstPointerType> ret{*this};
    ret += index;
    return ret;
}

Iterator<const std::uint8_t*> Iterator<const std::uint8_t*>::
    operator-(const std::size_t& index)
{
    Iterator<ConstPointerType> ret{*this};
    ret -= index;
    return ret;
}

Iterator<const std::uint8_t*> Iterator<const std::uint8_t*>::
    operator+(const int& index)
{
    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

Iterator<const std::uint8_t*> Iterator<const std::uint8_t*>::
    operator-(const int& index)
{
    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

bool Iterator<const std::uint8_t*>::
    operator==(const Iterator<ConstPointerType>& other) const
{
    const std::size_t other_index = other.m_pos;
    return m_ptr == other.m_ptr &&
        (m_pos == other_index || ((m_pos < m_begin || m_pos >= m_end) &&
        (other_index < other.m_begin || other_index >= other.m_end)));
}

bool Iterator<const std::uint8_t*>::
    operator!=(const Iterator<ConstPointerType>& other) const
{
    return !(*this == other);
}

Iterator<std::uint8_t*>::Iterator(PointerType ptr, const std::size_t& begin, 
    const std::size_t& end, const std::size_t& index, 
    const test::byte::it::Operator& op) :
        Iterator<ConstPointerType>(ptr, begin, end, index, op)
{}

Iterator<std::uint8_t*>::~Iterator()
{}

Iterator<std::uint8_t*>::Iterator(const Iterator<PointerType>& cpy) :
    Iterator<ConstPointerType>(cpy)
{}

Iterator<std::uint8_t*>::Iterator(Iterator<PointerType>&& mov) :
        Iterator<ConstPointerType>(std::move(mov))
{}

Iterator<std::uint8_t*>& Iterator<std::uint8_t*>::
    operator=(const Iterator<PointerType>& cpy)
{
    Iterator<ConstPointerType>::operator=(cpy);
    return *this;
}

Iterator<std::uint8_t*>& Iterator<std::uint8_t*>::
    operator=(Iterator<PointerType>&& mov)
{
    Iterator<ConstPointerType>::operator=(std::move(mov));
    return *this;
}

Iterator<std::uint8_t*>& Iterator<std::uint8_t*>::
    operator+=(const std::size_t& index)
{
    Iterator<ConstPointerType>::operator+=(index);
    return *this;
}

Iterator<std::uint8_t*>& Iterator<std::uint8_t*>::
    operator-=(const std::size_t& index)
{
    Iterator<ConstPointerType>::operator-=(index);
    return *this;
}

std::uint8_t& Iterator<std::uint8_t*>::operator*()
{
    return const_cast<std::uint8_t&>(Iterator<ConstPointerType>::operator*());
}

const std::uint8_t& Iterator<std::uint8_t*>::
    operator*() const
{
    return Iterator<ConstPointerType>::operator*();
}

Iterator<std::uint8_t*>& Iterator<std::uint8_t*>::operator++()
{
    return *this += 1;
}

Iterator<std::uint8_t*> Iterator<std::uint8_t*>::operator++(int)
{
    Iterator<PointerType> ret{*this};
    operator++();
    return ret;
}

Iterator<std::uint8_t*>& Iterator<std::uint8_t*>::operator--()
{
    return *this -= 1;
}

Iterator<std::uint8_t*> Iterator<std::uint8_t*>::operator--(int)
{
    Iterator<PointerType> ret{*this};
    operator--();
    return ret;
}

Iterator<std::uint8_t*> Iterator<std::uint8_t*>::
    operator+(const std::size_t& index)
{
    Iterator<PointerType> ret{*this};
    ret += index;
    return ret;
}

Iterator<std::uint8_t*> Iterator<std::uint8_t*>::
    operator-(const std::size_t& index)
{
    Iterator<PointerType> ret{*this};
    ret -= index;
    return ret;
}

Iterator<std::uint8_t*> Iterator<std::uint8_t*>::operator+(const int& index)
{
    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

Iterator<std::uint8_t*> Iterator<std::uint8_t*>::operator-(const int& index)
{
    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

bool Iterator<std::uint8_t*>::
    operator==(const Iterator<ConstPointerType>& other) const
{
    return Iterator<ConstPointerType>::operator==(other);
}

bool Iterator<std::uint8_t*>::
    operator!=(const Iterator<ConstPointerType>& other) const
{
    return !(*this == other);
}

} //!byte

} //!test

#endif //!TEST_BYTE_ITERATOR_H_
