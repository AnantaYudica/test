#ifndef TEST_BYTE_SEQUENCE_H_
#define TEST_BYTE_SEQUENCE_H_

#include "../System.h"

namespace test
{
namespace byte
{

namespace seq
{

enum class Flag : int
{
    first = 1,
    last = 2
};

} //!seq

template<test::byte::seq::Flag Flag, typename T>
class Sequence
{};


} //!byte

} //!test

TEST_SYS_DBG_TYPE_DEFINE("test::byte::seq::Flag", test::byte::seq::Flag);

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::byte::seq::Flag

template<>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("%s", (val == test::byte::seq::Flag::first ? 
    "test::byte::seq::Flag::first" : "test::byte::seq::Flag::last"));

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

#ifndef TEST_BYTE_SEQUENCE_DLEVEL

#define TEST_BYTE_SEQUENCE_DLEVEL 2

#endif //!TEST_BYTE_SEQUENCE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<test::byte::seq::Flag, Flag>, test::sys::dbg::Type<T>

template<test::byte::seq::Flag Flag, typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_BYTE_SEQUENCE_DLEVEL, 
    "test::byte::Sequence", 
    test::byte::Sequence<Flag, T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#include "Iterator.h"
#include "Order.h"

namespace test
{
namespace byte
{

template<typename T>
class Sequence<test::byte::seq::Flag::first, T>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::Sequence<
        test::byte::seq::Flag::first, T>> DebugType;
public:
    typedef T ValueType;
    typedef test::byte::Iterator<std::uint8_t*> IteratorType;
    typedef test::byte::Iterator<const std::uint8_t*> constIteratorType;
private:
    ValueType&& m_value;
    std::size_t m_off;
    std::size_t m_size;
public:
    Sequence(T&& val);
    Sequence(T&& val, const std::size_t& off);
public:
    Sequence(const Sequence<test::byte::seq::Flag::first, T>&) = delete;
    Sequence(Sequence<test::byte::seq::Flag::first, T>&& mov);
public:
    Sequence<test::byte::seq::Flag::first, T> 
        operator=(const Sequence<test::byte::seq::Flag::first, T>&) = delete;
    Sequence<test::byte::seq::Flag::first, T> 
        operator=(Sequence<test::byte::seq::Flag::first, T>&&) = delete;
public:
    template<typename TByte>
    IteratorType LeftBegin(TByte& left_val) const &&;
    template<typename TByte>
    IteratorType LeftEnd(TByte& left_val) const &&;
public:
    constIteratorType RightBegin() const &&;
    constIteratorType RightEnd() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
};

template<typename T>
class Sequence<test::byte::seq::Flag::last, T>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::Sequence<
        test::byte::seq::Flag::last, T>> DebugType;
public:
    typedef T ValueType;
    typedef test::byte::Iterator<std::uint8_t*> IteratorType;
    typedef test::byte::Iterator<const std::uint8_t*> constIteratorType;
private:
    ValueType&& m_value;
    std::size_t m_off;
public:
    Sequence(T&& val);
    Sequence(T&& val, const std::size_t& off);
public:
    Sequence(const Sequence<test::byte::seq::Flag::last, T>&) = delete;
    Sequence(Sequence<test::byte::seq::Flag::last, T>&& mov);
public:
    Sequence<test::byte::seq::Flag::last, T> 
        operator=(const Sequence<test::byte::seq::Flag::last, T>&) = delete;
    Sequence<test::byte::seq::Flag::last, T> 
        operator=(Sequence<test::byte::seq::Flag::last, T>&&) = delete;
public:
    template<typename TByte>
    IteratorType LeftBegin(TByte& left_val) const &&;
    template<typename TByte>
    IteratorType LeftEnd(TByte& left_val) const &&;
public:
    constIteratorType RightBegin() const &&;
    constIteratorType RightEnd() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
};

template<>
class Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::Sequence<
        test::byte::seq::Flag::first, 
        test::byte::Iterator<const std::uint8_t*>>> DebugType;
public:
    typedef test::byte::Iterator<const std::uint8_t*>  ValueType;
    typedef test::byte::Iterator<std::uint8_t*> IteratorType;
    typedef test::byte::Iterator<const std::uint8_t*> constIteratorType;
private:
    ValueType m_begin;
    ValueType m_end;
    std::size_t m_off;
public:
    Sequence(constIteratorType begin, constIteratorType end);
    Sequence(constIteratorType begin, constIteratorType end, 
        const std::size_t& off);
public:
    Sequence(const Sequence<test::byte::seq::Flag::first, 
        test::byte::Iterator<const std::uint8_t*>>&) = delete;
    Sequence(Sequence<test::byte::seq::Flag::first, 
        test::byte::Iterator<const std::uint8_t*>>&& mov);
public:
    Sequence<test::byte::seq::Flag::first, 
        test::byte::Iterator<const std::uint8_t*>> 
        operator=(const Sequence<test::byte::seq::Flag::first, 
            test::byte::Iterator<const std::uint8_t*>>&) = delete;
    Sequence<test::byte::seq::Flag::first, 
        test::byte::Iterator<const std::uint8_t*>> 
        operator=(Sequence<test::byte::seq::Flag::first, 
            test::byte::Iterator<const std::uint8_t*>>&&) = delete;
public:
    template<typename TByte>
    IteratorType LeftBegin(TByte& left_val) const &&;
    template<typename TByte>
    IteratorType LeftEnd(TByte& left_val) const &&;
public:
    constIteratorType RightBegin() const &&;
    constIteratorType RightEnd() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
};


template<>
class Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*, std::uint8_t, 
        sizeof(std::uint8_t)>>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::Sequence<
        test::byte::seq::Flag::last, 
        test::byte::Iterator<const std::uint8_t*, std::uint8_t, 
        sizeof(std::uint8_t)>>> DebugType;
public:
    typedef test::byte::Iterator<const std::uint8_t*>  ValueType;
    typedef test::byte::Iterator<std::uint8_t*> IteratorType;
    typedef test::byte::Iterator<const std::uint8_t*> constIteratorType;
private:
    ValueType m_begin;
    ValueType m_end;
    std::size_t m_off;
public:
    Sequence(constIteratorType begin, constIteratorType end);
    Sequence(constIteratorType begin, constIteratorType end, 
        const std::size_t& off);
public:
    Sequence(const Sequence<test::byte::seq::Flag::last, 
        test::byte::Iterator<const std::uint8_t*>>&) = delete;
    Sequence(Sequence<test::byte::seq::Flag::last, 
        test::byte::Iterator<const std::uint8_t*>>&& mov);
public:
    Sequence<test::byte::seq::Flag::last, 
        test::byte::Iterator<const std::uint8_t*>> 
        operator=(const Sequence<test::byte::seq::Flag::last, 
            test::byte::Iterator<const std::uint8_t*>>&) = delete;
    Sequence<test::byte::seq::Flag::last, 
        test::byte::Iterator<const std::uint8_t*>> 
        operator=(Sequence<test::byte::seq::Flag::last, 
            test::byte::Iterator<const std::uint8_t*>>&&) = delete;
public:
    template<typename TByte>
    IteratorType LeftBegin(TByte& left_val) const &&;
    template<typename TByte>
    IteratorType LeftEnd(TByte& left_val) const &&;
public:
    inline constIteratorType RightBegin() const &&;
    inline constIteratorType RightEnd() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
    
};


} //!byte

} //!test

#include <cstdint>
#include <cstddef>

namespace test
{
namespace byte
{

template<typename T>
Sequence<test::byte::seq::Flag::first, T>::Sequence(T&& val) :
    m_value(std::move(val)),
    m_off(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(val=%p)", &val);
    
}

template<typename T>
Sequence<test::byte::seq::Flag::first, T>::Sequence(T&& val, 
    const std::size_t& off) :
        m_value(std::move(val)),
        m_off(off)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(val=%s, off=%zu)", 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val), off);
    
}

template<typename T>
Sequence<test::byte::seq::Flag::first, T>::
    Sequence(Sequence<test::byte::seq::Flag::first, T>&& mov) :
        m_value(std::move(mov.m_value)),
        m_off(std::move(mov.m_off))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
}

template<typename T>
template<typename TByte>
typename Sequence<test::byte::seq::Flag::first, T>::IteratorType 
Sequence<test::byte::seq::Flag::first, T>::
    LeftBegin(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftBegin<%s>(left_val=%p) const &&", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TByte), &left_val);
    
    return left_val.Begin() + m_off;
}

template<typename T>
template<typename TByte>
typename Sequence<test::byte::seq::Flag::first, T>::IteratorType 
Sequence<test::byte::seq::Flag::first, T>::
    LeftEnd(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftEnd<%s>(LeftEnd=%p) const &&", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TByte), &left_val);
    
    return left_val.End();
}

template<typename T>
typename Sequence<test::byte::seq::Flag::first, T>::constIteratorType
Sequence<test::byte::seq::Flag::first, T>::RightBegin() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightBegin() const &&");
    
    return std::move(m_value).Begin();
}

template<typename T>
typename Sequence<test::byte::seq::Flag::first, T>::constIteratorType 
Sequence<test::byte::seq::Flag::first, T>::RightEnd() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightEnd() const &&");
    
    return std::move(m_value).End();
}

template<typename T>
Sequence<test::byte::seq::Flag::last, T>::Sequence(T&& val) :
    m_value(std::move(val)),
    m_off(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(val=%s)", TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
}

template<typename T>
Sequence<test::byte::seq::Flag::last, T>::Sequence(T&& val, 
    const std::size_t& off) :
        m_value(std::move(val)),
        m_off(off)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(val=%s, off=%zu)", 
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val), off);
    
}

template<typename T>
Sequence<test::byte::seq::Flag::last, T>::
    Sequence(Sequence<test::byte::seq::Flag::last, T>&& mov) :
        m_value(std::move(mov.m_value)),
        m_off(std::move(mov.m_off))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
}

template<typename T>
template<typename TByte>
typename Sequence<test::byte::seq::Flag::last, T>::IteratorType 
Sequence<test::byte::seq::Flag::last, T>::
    LeftBegin(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftBegin<%s>(left_val=%p) const &&", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TByte), &left_val);
    
    return left_val.ReverseBegin() + m_off;
}

template<typename T>
template<typename TByte>
typename Sequence<test::byte::seq::Flag::last, T>::IteratorType 
Sequence<test::byte::seq::Flag::last, T>::
    LeftEnd(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftEnd<%s>(left_val=%p) const &&", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TByte), &left_val);
    
    return left_val.ReverseEnd();
}

template<typename T>
typename Sequence<test::byte::seq::Flag::last, T>::constIteratorType
Sequence<test::byte::seq::Flag::last, T>::RightBegin() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightBegin() const &&");
    
    return std::move(m_value).ReverseBegin();
}

template<typename T>
typename Sequence<test::byte::seq::Flag::last, T>::constIteratorType
Sequence<test::byte::seq::Flag::last, T>::RightEnd() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightEnd() const &&");
    
    return std::move(m_value).ReverseEnd();
}

Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::
    Sequence(constIteratorType begin, constIteratorType end) :
        m_begin(begin),
        m_end(end),
        m_off(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(begin=%p, end=%p)", &*begin, &*end);
    
}

Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::
    Sequence(constIteratorType begin, constIteratorType end, 
        const std::size_t& off) :
            m_begin(begin),
            m_end(end),
            m_off(off)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(begin=%p, end=%p, off=%zu)", 
        &*begin, &*end, off);

}

Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::
    Sequence(Sequence<test::byte::seq::Flag::first, 
        test::byte::Iterator<const std::uint8_t*>>&& mov) :
            m_begin(std::move(mov.m_begin)),
            m_end(std::move(mov.m_end)),
            m_off(std::move(mov.m_off))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
}

template<typename TByte>
typename Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::IteratorType 
Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::
    LeftBegin(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftBegin<%s>(left_val=%p) const &&", &left_val);
    
    return left_val.Begin() + m_off;
}

template<typename TByte>
typename Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::IteratorType 
Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::
    LeftEnd(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftEnd<%s>(left_val=%p) const &&", &left_val);
    
    return left_val.End();
}

typename Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::constIteratorType 
Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::RightBegin() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightBegin() const &&");
    
    return m_begin;
}


typename Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::constIteratorType 
Sequence<test::byte::seq::Flag::first, 
    test::byte::Iterator<const std::uint8_t*>>::RightEnd() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightEnd() const &&");
    
    return m_end;
}

Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::
    Sequence(constIteratorType begin, constIteratorType end) :
        m_begin(begin),
        m_end(end),
        m_off(0)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(begin=%p, end=%p)", &*begin, &*end);
    
}

Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::
    Sequence(constIteratorType begin, constIteratorType end, 
        const std::size_t& off) :
            m_begin(begin),
            m_end(end),
            m_off(off)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(begin=%p, end=%p, off=%zu)", 
        &*begin, &*end, off);

}

Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::
    Sequence(Sequence<test::byte::seq::Flag::last, 
        test::byte::Iterator<const std::uint8_t*>>&& mov) :
            m_begin(std::move(mov.m_begin)),
            m_end(std::move(mov.m_end)),
            m_off(std::move(mov.m_off))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

template<typename TByte>
typename Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::IteratorType 
Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::
    LeftBegin(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftBegin<%s>(left_val=%p) const &&", &left_val);
    
    return left_val.ReverseBegin() + m_off;
}

template<typename TByte>
typename Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::IteratorType 
Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::
    LeftEnd(TByte& left_val) const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LeftEnd<%s>(left_val=%p) const &&", &left_val);
    
    return left_val.ReverseEnd();
}

typename Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::constIteratorType 
Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::RightBegin() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightBegin() const &&");
    
    return m_begin;
}

typename Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::constIteratorType 
Sequence<test::byte::seq::Flag::last, 
    test::byte::Iterator<const std::uint8_t*>>::RightEnd() const &&
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RightEnd() const &&");
    
    return m_end;
}

} //!byte

} //!test

#endif //!TEST_BYTE_SEQUENCE_H_
