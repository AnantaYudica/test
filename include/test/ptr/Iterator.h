#ifndef TEST_PTR_ITERATOR_H_
#define TEST_PTR_ITERATOR_H_

#include "../System.h"

#include <cstddef>
#include <utility>

namespace test
{
namespace ptr
{

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
class Iterator;

} //!ptr

} //!test

#ifndef TEST_PTR_ITERATOR_DLEVEL

#define TEST_PTR_ITERATOR_DLEVEL 2

#endif //!TEST_PTR_ITERATOR_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TTClass<T, TArgs...>>,\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TArgs>...

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_PTR_ITERATOR_DLEVEL, 
    "test::ptr::Iterator", 
    test::ptr::Iterator<TTClass, T, TArgs...>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace ptr
{

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
class Iterator : public TTClass<T, TArgs...>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::ptr::Iterator<TTClass, 
        T, TArgs...>> DebugType;
private:
    std::size_t m_begin, m_end, m_pos;
public:
    Iterator(const TTClass<T, TArgs...>& ptr, const std::size_t& bg,
        const std::size_t& ed, const std::size_t& index);
public:
    ~Iterator();
public:
    Iterator(const Iterator<TTClass, T, TArgs...>& cpy);
    Iterator(Iterator<TTClass, T, TArgs...>&& mov);
public:
    Iterator<TTClass, T, TArgs...>& 
        operator=(const Iterator<TTClass, T, TArgs...>& cpy);
    Iterator<TTClass, T, TArgs...>& 
        operator=(Iterator<TTClass, T, TArgs...>&& mov);
public:
    using TTClass<T, TArgs...>::ConstCast;
    using TTClass<T, TArgs...>::DynamicCast;
    using TTClass<T, TArgs...>::ReinterpretCast;
    using TTClass<T, TArgs...>::StaticCast;
private:
    using TTClass<T, TArgs...>::StepSize;
    using TTClass<T, TArgs...>::AllocationSize;
    using TTClass<T, TArgs...>::Size;
private:
    using TTClass<T, TArgs...>::Offset;
private:
    using TTClass<T, TArgs...>::Index;
    using TTClass<T, TArgs...>::SetIndex;
private:
    void Begin() = delete;
    void End() = delete;;
public:
    using TTClass<T, TArgs...>::operator*;
public:
    using TTClass<T, TArgs...>::operator->;
public:
    using TTClass<T, TArgs...>::operator[];
public:
    Iterator<TTClass, T, TArgs...>& operator+=(const std::size_t& index);
    Iterator<TTClass, T, TArgs...>& operator-=(const std::size_t& index);
public:
    Iterator<TTClass, T, TArgs...>& operator++();
    Iterator<TTClass, T, TArgs...> operator++(int);
public:
    Iterator<TTClass, T, TArgs...>& operator--();
    Iterator<TTClass, T, TArgs...> operator--(int);
public:
    Iterator<TTClass, T, TArgs...> operator+(const std::size_t& index);
    Iterator<TTClass, T, TArgs...> operator-(const std::size_t& index);
    Iterator<TTClass, T, TArgs...> operator+(const int& index);
    Iterator<TTClass, T, TArgs...> operator-(const int& index);
public:
    using TTClass<T, TArgs...>::GetData;
public:
    bool operator==(const Iterator<TTClass, T, TArgs...>& other) const;
    bool operator!=(const Iterator<TTClass, T, TArgs...>& other) const;
    using TTClass<T, TArgs...>::operator==;
    using TTClass<T, TArgs...>::operator!=;
};

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>::Iterator(const TTClass<T, TArgs...>& ptr, 
    const std::size_t& bg, const std::size_t& ed, const std::size_t& index) :
        TTClass<T, TArgs...>(ptr),
        m_begin(bg),
        m_end(ed),
        m_pos(index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(ptr=%p, bg=%zu, ed=%zu, index=%zu)",
        &ptr, bg, ed, index);

    this->SetIndex(index);
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>::~Iterator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

    m_begin = 0;
    m_end = 0;
    m_pos = 0;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>::
    Iterator(const Iterator<TTClass, T, TArgs...>& cpy) :
        TTClass<T, TArgs...>(cpy),
        m_begin(cpy.m_begin),
        m_end(cpy.m_end),
        m_pos(cpy.m_pos)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>::
    Iterator(Iterator<TTClass, T, TArgs...>&& mov) :
        TTClass<T, TArgs...>(std::move(mov)),
        m_begin(mov.m_begin),
        m_end(mov.m_end),
        m_pos(mov.m_pos)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

    mov.SetIndex(0);
    mov.m_pos = mov.m_end;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>& 
Iterator<TTClass, T, TArgs...>::
    operator=(const Iterator<TTClass, T, TArgs...>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    TTClass<T, TArgs...>::operator=(cpy);
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    m_pos = cpy.m_pos;
    return *this;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>&
Iterator<TTClass, T, TArgs...>::
    operator=(Iterator<TTClass, T, TArgs...>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    TTClass<T, TArgs...>::operator=(mov);
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    m_pos = mov.m_pos;
    mov.SetIndex(0);
    mov.m_pos = mov.m_end;
    return *this;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>&
Iterator<TTClass, T, TArgs...>::operator+=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(index=%zu)", index);

    TTClass<T, TArgs...>::operator+=(index);
    m_pos += index;
    return *this;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>& 
Iterator<TTClass, T, TArgs...>::operator-=(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(index=%zu)", index);

    TTClass<T, TArgs...>::operator-=(index);
    m_pos -= index;
    return *this;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>& 
Iterator<TTClass, T, TArgs...>::operator++()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++()");

    *this += 1;
    return *this;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>
Iterator<TTClass, T, TArgs...>::operator++(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator++(int)");

    Iterator<TTClass, T, TArgs...> ret{*this};
    operator++();
    return ret;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>& 
Iterator<TTClass, T, TArgs...>::operator--()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--()");

    *this -= 1;
    return *this;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...>
Iterator<TTClass, T, TArgs...>::operator--(int)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator--(int)");

    Iterator<TTClass, T, TArgs...> ret{*this};
    operator--();
    return ret;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...> Iterator<TTClass, T, TArgs...>::
    operator+(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%zu)", index);

    Iterator<TTClass, T, TArgs...> ret{*this};
    ret += index;
    return ret;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...> Iterator<TTClass, T, TArgs...>::
    operator-(const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%zu)", index);

    Iterator<TTClass, T, TArgs...> ret{*this};
    ret -= index;
    return ret;
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...> Iterator<TTClass, T, TArgs...>::
    operator+(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+(index=%d)", index);

    if (index >= 0)
        return (*this + std::size_t(index)); 
    return (*this - std::size_t(-index)); 
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
Iterator<TTClass, T, TArgs...> Iterator<TTClass, T, TArgs...>::
    operator-(const int& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-(index=%d)", index);

    if (index >= 0)
        return (*this - std::size_t(index));
    return (*this + std::size_t(-index));
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
bool Iterator<TTClass, T, TArgs...>::
    operator==(const Iterator<TTClass, T, TArgs...>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%d) const", &other);
    
    const std::size_t index = m_pos;
    const std::size_t other_index = other.m_pos;
    return this->TTClass<T, TArgs...>::operator==(other.GetData()) &&
        (index == other_index || ((index < m_begin || index >= m_end) &&
        (other_index < other.m_begin || other_index >= other.m_end)));
}

template<template<typename, typename...> class TTClass, 
    typename T, typename... TArgs>
bool Iterator<TTClass, T, TArgs...>::
    operator!=(const Iterator<TTClass, T, TArgs...>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%d) const", &other);
    
    return !(*this == other);
}

} //!ptr

} //!test

#endif //!TEST_PTR_ITERATOR_H_
