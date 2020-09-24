#ifndef TEST_PTR_ITERATOR_H_
#define TEST_PTR_ITERATOR_H_

#include <cstddef>
#include <utility>

namespace test
{
namespace ptr
{

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
class Iterator : public TTPointer<T, TDefault>
{
private:
    std::size_t m_begin, m_end;
public:
    Iterator(const TTPointer<T, TDefault>& ptr, const std::size_t& bg,
        const std::size_t& ed, const std::size_t& index);
public:
    ~Iterator();
public:
    Iterator(const Iterator<TTPointer, T, TDefault>& cpy);
    Iterator(Iterator<TTPointer, T, TDefault>&& mov);
public:
    Iterator<TTPointer, T, TDefault>& 
        operator=(const Iterator<TTPointer, T, TDefault>& cpy);
    Iterator<TTPointer, T, TDefault>& 
        operator=(Iterator<TTPointer, T, TDefault>&& mov);
public:
    using TTPointer<T, TDefault>::ConstCast;
    using TTPointer<T, TDefault>::DynamicCast;
    using TTPointer<T, TDefault>::ReinterpretCast;
    using TTPointer<T, TDefault>::StaticCast;
private:
    using TTPointer<T, TDefault>::StepSize;
    using TTPointer<T, TDefault>::AllocationSize;
    using TTPointer<T, TDefault>::Size;
private:
    using TTPointer<T, TDefault>::Offset;
private:
    using TTPointer<T, TDefault>::Index;
    using TTPointer<T, TDefault>::SetIndex;
private:
    void Begin() = delete;
    void End() = delete;;
public:
    using TTPointer<T, TDefault>::operator*;
public:
    using TTPointer<T, TDefault>::operator->;
public:
    using TTPointer<T, TDefault>::operator[];
public:
    Iterator<TTPointer, T, TDefault>& operator+=(const std::size_t& index);
    Iterator<TTPointer, T, TDefault>& operator-=(const std::size_t& index);
public:
    Iterator<TTPointer, T, TDefault>& operator++();
    Iterator<TTPointer, T, TDefault> operator++(int);
public:
    Iterator<TTPointer, T, TDefault>& operator--();
    Iterator<TTPointer, T, TDefault> operator--(int);
public:
    Iterator<TTPointer, T, TDefault> operator+(const std::size_t& index);
    Iterator<TTPointer, T, TDefault> operator-(const std::size_t& index);
    Iterator<TTPointer, T, TDefault> operator+(const int& index);
    Iterator<TTPointer, T, TDefault> operator-(const int& index);
public:
    using TTPointer<T, TDefault>::GetData;
public:
    bool operator==(const Iterator<TTPointer, T, TDefault>& other) const;
    bool operator!=(const Iterator<TTPointer, T, TDefault>& other) const;
    using TTPointer<T, TDefault>::operator==;
    using TTPointer<T, TDefault>::operator!=;
};

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>::Iterator(const TTPointer<T, TDefault>& ptr, 
    const std::size_t& bg, const std::size_t& ed, const std::size_t& index) :
        TTPointer<T, TDefault>(ptr),
        m_begin(bg),
        m_end(ed)
{
    this->SetIndex(index);
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>::~Iterator()
{
    m_begin = 0;
    m_end = 0;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>::
    Iterator(const Iterator<TTPointer, T, TDefault>& cpy) :
        TTPointer<T, TDefault>(cpy),
        m_begin(cpy.m_begin),
        m_end(cpy.m_end)
{}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>::
    Iterator(Iterator<TTPointer, T, TDefault>&& mov) :
        TTPointer<T, TDefault>(std::move(mov)),
        m_begin(mov.m_begin),
        m_end(mov.m_end)
{
    mov.SetIndex(mov.m_end);
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>& 
Iterator<TTPointer, T, TDefault>::
    operator=(const Iterator<TTPointer, T, TDefault>& cpy)
{
    Iterator<TTPointer, T, TDefault>::operator=(cpy);
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    return *this;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>& 
Iterator<TTPointer, T, TDefault>::
    operator=(Iterator<TTPointer, T, TDefault>&& mov)
{
    Iterator<TTPointer, T, TDefault>::operator=(mov);
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    mov.SetIndex(mov.m_end);
    return *this;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>& 
Iterator<TTPointer, T, TDefault>::operator+=(const std::size_t& index)
{
    TTPointer<T, TDefault>::operator+=(index);
    return *this;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>& 
Iterator<TTPointer, T, TDefault>::operator-=(const std::size_t& index)
{
    TTPointer<T, TDefault>::operator-=(index);
    return *this;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>& 
Iterator<TTPointer, T, TDefault>::operator++()
{
    TTPointer<T, TDefault>::operator++();
    return *this;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault> 
Iterator<TTPointer, T, TDefault>::operator++(int)
{
    Iterator<TTPointer, T, TDefault> ret{*this};
    operator++();
    return ret;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault>& 
Iterator<TTPointer, T, TDefault>::operator--()
{
    TTPointer<T, TDefault>::operator--();
    return *this;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault> 
Iterator<TTPointer, T, TDefault>::operator--(int)
{
    Iterator<TTPointer, T, TDefault> ret{*this};
    operator--();
    return ret;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault> Iterator<TTPointer, T, TDefault>::
    operator+(const std::size_t& index)
{
    Iterator<TTPointer, T, TDefault> ret{*this};
    ret += index;
    return ret;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault> Iterator<TTPointer, T, TDefault>::
    operator-(const std::size_t& index)
{
    Iterator<TTPointer, T, TDefault> ret{*this};
    ret -= index;
    return ret;
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault> Iterator<TTPointer, T, TDefault>::
    operator+(const int& index)
{
    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
Iterator<TTPointer, T, TDefault> Iterator<TTPointer, T, TDefault>::
    operator-(const int& index)
{
    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
bool Iterator<TTPointer, T, TDefault>::
    operator==(const Iterator<TTPointer, T, TDefault>& other) const
{
    const std::size_t index = this->Index();
    const std::size_t other_index = other.Index();
    return this->TTPointer<T, TDefault>::operator==(other.GetData()) &&
        (index == other_index || ((index < m_begin || index >= m_end) &&
        (other_index < other.m_begin || other_index >= other.m_begin)));
}

template<template<typename, typename> class TTPointer, 
    typename T, typename TDefault>
bool Iterator<TTPointer, T, TDefault>::
    operator!=(const Iterator<TTPointer, T, TDefault>& other) const
{
    return !(*this == other);
}

} //!ptr

} //!test

#endif //!TEST_PTR_ITERATOR_H_
