#ifndef TEST_BYTE_H_
#define TEST_BYTE_H_

#include <cstddef>

namespace test
{

template<std::size_t N, bool Sign = false>
class Byte;

} //!test

#include "Pointer.h"
#include "Queue.h"
#include "trait/byte/IsBaseOf.h"
#include "trait/byte/it/IsBaseOf.h"
#include "trait/byte/off/IsBaseOf.h"
#include "byte/Offset.h"
#include "byte/Iterator.h"
#include "byte/Order.h"

#include <cstdint>
#include <type_traits>
#include <utility>
#include <cstring>

namespace test
{

template<std::size_t N, bool Sign>
class Byte
{
public:
    typedef test::byte::Iterator<std::uint8_t*> IteratorType;
    typedef test::byte::Iterator<const std::uint8_t*> ConstIteratorType;
private:
    static void _SetZero(std::uint8_t* ptr, std::size_t size);
private:
    template<typename TIDestValue>
    static void _Set(IteratorType dest_bg, IteratorType dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    static void _Set(IteratorType dest_bg, IteratorType dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _Set(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    template<typename TIDestValue>
    static void _And(IteratorType dest_bg, IteratorType dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    static void _And(IteratorType dest_bg, IteratorType dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _And(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    template<typename TIDestValue>
    static void _Or(IteratorType dest_bg, IteratorType dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    static void _Or(IteratorType dest_bg, IteratorType dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _Or(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    template<typename TIDestValue>
    static void _Xor(IteratorType dest_bg, IteratorType dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    static void _Xor(IteratorType dest_bg, IteratorType dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _Xor(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    static void _Not(std::uint8_t* ptr, std::size_t size);
private:
    template<bool _Sign, typename std::enable_if<_Sign, int>::type = 1>
    static void _RShift(std::uint8_t* ptr, std::size_t size, 
        std::size_t shift);
    template<bool _Sign, typename std::enable_if<!_Sign, int>::type = 1>
    static void _RShift(std::uint8_t* ptr, std::size_t size,
        std::size_t shift);
private:
    static void _LShift(std::uint8_t* ptr, std::size_t size, 
        std::size_t shift);
public:
    static test::byte::it::Operator GetOperator();
    static test::byte::it::Operator GetReverseOperator();
private:
    std::uint8_t m_block[N];
public:
    Byte();
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte(const TValue& val);
    Byte(const test::byte::Order& byte_order);
    template<typename TIValue>
    Byte(test::byte::Iterator<TIValue> bg, test::byte::Iterator<TIValue> ed);
    template<typename TValue>
    Byte(test::byte::Offset<TValue>&& offset_val);
public:
    ~Byte() = default;
public:
    template<std::size_t _N, bool _Sign>
    Byte(const Byte<_N, _Sign>& cpy);
    template<std::size_t _N, bool _Sign>
    Byte(Byte<_N, _Sign>&& mov);
public:
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign>& operator=(const TValue& val);
    Byte<N, Sign>& operator=(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign>& operator=(test::byte::Offset<TValue>&& offset_val);
public:
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign>& operator=(const Byte<_N, _Sign>& cpy);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign>& operator=(Byte<_N, _Sign>&& mov);
public:
    std::size_t Size() const;
public:
    IteratorType Begin();
    IteratorType End();
public:
    ConstIteratorType Begin() const;
    ConstIteratorType End() const;
public:
    IteratorType ReverseBegin();
    IteratorType ReverseEnd();
public:
    ConstIteratorType ReverseBegin() const;
    ConstIteratorType ReverseEnd() const;
public:
    template<typename T>
    T CastTo(const std::size_t& off = 0) const;
public:
    template<std::size_t _N = N, bool _Sign = Sign>
    Byte<_N, _Sign> GetBlock(const std::size_t& off = 0) const;
public:
    std::uint8_t* Get();
    const std::uint8_t* Get() const;
public:
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign>& operator&=(const TValue& val);
    Byte<N, Sign>& operator&=(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign>& operator&=(test::byte::Offset<TValue>&& offset_val);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign>& operator&=(const Byte<_N, _Sign>& other);
public:
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign>& operator|=(const TValue& val);
    Byte<N, Sign>& operator|=(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign>& operator|=(test::byte::Offset<TValue>&& offset_val);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign>& operator|=(const Byte<_N, _Sign>& other);
public:
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign>& operator^=(const TValue& val);
    Byte<N, Sign>& operator^=(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign>& operator^=(test::byte::Offset<TValue>&& offset_val);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign>& operator^=(const Byte<_N, _Sign>& other);
public:
    Byte<N, Sign>& operator<<=(const std::size_t& size);
    Byte<N, Sign>& operator<<=(const int& size);
public:
    Byte<N, Sign>& operator>>=(const std::size_t& size);
    Byte<N, Sign>& operator>>=(const int& size);
public:
    Byte<N, Sign> operator~() const;
public:
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign> operator&(const TValue& val);
    Byte<N, Sign> operator&(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign> operator&(test::byte::Offset<TValue>&& offset_val);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign> operator&(const Byte<_N, _Sign>& other);
public:
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign> operator|(const TValue& val);
    Byte<N, Sign> operator|(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign> operator|(test::byte::Offset<TValue>&& offset_val);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign> operator|(const Byte<_N, _Sign>& other);
public:
    
    template<typename TValue, typename _TValue = 
        typename std::remove_cv<typename std::remove_reference<
            TValue>::type>::type,
        typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
            !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
            !std::is_base_of<test::byte::Order, _TValue>::value &&
            !std::is_pointer<_TValue>::value &&
            !std::is_array<_TValue>::value, int>::type = 1>
    Byte<N, Sign> operator^(const TValue& val);
    Byte<N, Sign> operator^(const test::byte::Order& byte_order);
    template<typename TValue>
    Byte<N, Sign> operator^(test::byte::Offset<TValue>&& offset_val);
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign> operator^(const Byte<_N, _Sign>& other);
public:
    std::uint8_t& operator[](const std::size_t& index);
    std::uint8_t operator[](const std::size_t& index) const;

};

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_SetZero(std::uint8_t* ptr, std::size_t size)
{
    std::memset(ptr, 0, size);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_Set(IteratorType dest_bg, IteratorType dest_ed, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg = *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_Set(IteratorType dest_bg, IteratorType dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    _Set(dest_bg, dest_ed, begin, end);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_Set(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    const auto op = GetOperator();
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    _Set(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_And(IteratorType dest_bg, IteratorType dest_ed,
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg &= *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_And(IteratorType dest_bg, IteratorType dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    _And(dest_bg, dest_ed, begin, end);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_And(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    const auto op = GetOperator();
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    _And(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_Or(IteratorType dest_bg, IteratorType dest_ed, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg |= *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_Or(IteratorType dest_bg, IteratorType dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    _Or(dest_bg, dest_ed, begin, end);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_Or(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    const auto op = GetOperator();
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    _Or(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_Xor(IteratorType dest_bg, IteratorType dest_ed, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg ^= *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_Xor(IteratorType dest_bg, IteratorType dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    _Xor(dest_bg, dest_ed, begin, end);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue>
void Byte<N, Sign>::_Xor(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    const auto op = GetOperator();
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    _Xor(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_Not(std::uint8_t* ptr, std::size_t size)
{
    for(std::size_t i = 0; i < size; ++i)
    {
        ptr[i] = ~ptr[i];
    }
}

template<std::size_t N, bool Sign>
template<bool _Sign, typename std::enable_if<_Sign, int>::type>
void Byte<N, Sign>::_RShift(std::uint8_t* ptr, std::size_t size, 
    std::size_t shift)
{
    test::Queue<std::uint8_t> queue;
    auto op = GetReverseOperator();
    const std::size_t start = shift / 8;
    const std::size_t rem = shift % 8;
    const std::size_t inv_rem = 8 - rem;
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    auto it = begin;
    std::uint8_t prev = *it, sign = (((std::int8_t)*it) < 0 ? 0xff : 0);
    for(std::size_t i = 0; it != end; ++i, ++it)
    {
        if (it == begin)
            queue.Push((std::uint8_t)((std::int8_t)*it >> rem));
        else
        {
            queue.Push((*it >> rem) | (prev << inv_rem));
            prev = *it;
        }
        if (i >= start)
            *it = queue.Pop();
        else
            *it = sign;
    }
}

template<std::size_t N, bool Sign>
template<bool _Sign, typename std::enable_if<!_Sign, int>::type>
void Byte<N, Sign>::_RShift(std::uint8_t* ptr, std::size_t size, 
    std::size_t shift)
{
    test::Queue<std::uint8_t> queue;
    auto op = GetReverseOperator();
    const std::size_t start = shift / 8;
    const std::size_t rem = shift % 8;
    const std::size_t inv_rem = 8 - rem;
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    auto it = begin;
    std::uint8_t prev = *it;
    for(std::size_t i = 0; it != end; ++i, ++it)
    {
        if (it == begin)
            queue.Push(*it >> rem);
        else
        {
            queue.Push((*it >> rem) | (prev << inv_rem));
            prev = *it;
        }
        if (i >= start)
            *it = queue.Pop();
        else
            *it = 0;
    }
}

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_LShift(std::uint8_t* ptr, std::size_t size, 
    std::size_t shift)
{
    test::Queue<std::uint8_t> queue;
    auto op = GetOperator();
    const std::size_t start = shift / 8;
    const std::size_t rem = shift % 8;
    const std::size_t inv_rem = 8 - rem;
    IteratorType begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType end{ptr, 0, size, op.End(0, size), op};
    auto it = begin;
    std::uint8_t prev = *it;
    for(std::size_t i = 0; it != end; ++i, ++it)
    {
        if (it == begin)
            queue.Push(*it << rem);
        else
        {
            queue.Push((*it << rem) | (prev >> inv_rem));
            prev = *it;
        }
        if (i >= start)
            *it = queue.Pop();
        else
            *it = 0;
    }
}

template<std::size_t N, bool Sign>
test::byte::it::Operator Byte<N, Sign>::GetOperator()
{
    return test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetMachineEndian());
}

template<std::size_t N, bool Sign>
test::byte::it::Operator Byte<N, Sign>::GetReverseOperator()
{
    return test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetReverseEndian(
            test::byte::Order::GetMachineEndian()));
}

template<std::size_t N, bool Sign>
Byte<N, Sign>::Byte() :
    m_block{}
{
    _SetZero(m_block, N);
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign>::Byte(const TValue& val) :
    m_block{}
{
    _SetZero(m_block, N);
    _Set(Begin(), End(), (const std::uint8_t*)&val, sizeof(TValue));
}

template<std::size_t N, bool Sign>
Byte<N, Sign>::Byte(const test::byte::Order& byte_order) :
    m_block{}
{
    _SetZero(m_block, N);
    _Set(Begin(), End(), byte_order.Begin(), byte_order.End());
}

template<std::size_t N, bool Sign>
template<typename TIValue>
Byte<N, Sign>::Byte(test::byte::Iterator<TIValue> bg, 
    test::byte::Iterator<TIValue> ed) :
        m_block{}
{
    _SetZero(m_block, N);
    _Set(Begin(), End(), bg, ed);
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>::Byte(test::byte::Offset<TValue>&& offset_val) :
    m_block{}
{
    _SetZero(m_block, N);
    _Set(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>::Byte(const Byte<_N, _Sign>& cpy) :
    m_block{}
{
    _SetZero(m_block, N);
    _Set(Begin(), End(), cpy.Begin(), cpy.End());
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>::Byte(Byte<_N, _Sign>&& mov) :
    m_block{}
{
    _SetZero(m_block, N);
    _Set(Begin(), End(), mov.Begin(), mov.End());
    _SetZero(mov.Get(), N);
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign>& Byte<N, Sign>::operator=(const TValue& val)
{
    _Set(Begin(), End(), (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator=(const test::byte::Order& byte_order)
{
    _Set(Begin(), End(), byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& Byte<N, Sign>::
    operator=(test::byte::Offset<TValue>&& offset_val)
{
    _Set(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>& Byte<N, Sign>::operator=(const Byte<_N, _Sign>& cpy)
{
    _Set(Begin(), End(), cpy.Begin(), cpy.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>& Byte<N, Sign>::operator=(Byte<_N, _Sign>&& mov)
{
    _Set(Begin(), End(), mov.Begin(), mov.End());
    _SetZero(mov.Get(), N);
    return *this;
}

template<std::size_t N, bool Sign>
std::size_t Byte<N, Sign>::Size() const
{
    return N;
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::IteratorType Byte<N, Sign>::Begin()
{
    const auto op = GetOperator();
    return {m_block, 0, N, op.Begin(0, N), op};
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::IteratorType Byte<N, Sign>::End()
{
    const auto op = GetOperator();
    return {m_block, 0, N, op.End(0, N), op};
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::ConstIteratorType Byte<N, Sign>::Begin() const
{
    return const_cast<Byte<N, Sign>*>(this)->Begin();
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::ConstIteratorType Byte<N, Sign>::End() const
{
    return const_cast<Byte<N, Sign>*>(this)->End();
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::IteratorType Byte<N, Sign>::ReverseBegin()
{
    const auto op = GetReverseOperator();
    return {m_block, 0, N, op.Begin(0, N), op};
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::IteratorType Byte<N, Sign>::ReverseEnd()
{
    const auto op = GetReverseOperator();
    return {m_block, 0, N, op.End(0, N), op};
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::ConstIteratorType Byte<N, Sign>::ReverseBegin() const
{
    return const_cast<Byte<N, Sign>*>(this)->ReverseBegin();
}

template<std::size_t N, bool Sign>
typename Byte<N, Sign>::ConstIteratorType Byte<N, Sign>::ReverseEnd() const
{
    return const_cast<Byte<N, Sign>*>(this)->ReverseEnd();
}

template<std::size_t N, bool Sign>
template<typename T>
T Byte<N, Sign>::CastTo(const std::size_t& off) const
{
    T ret;
    std::memset(&ret, 0, sizeof(T));
    const std::size_t size = (off >= N ? N : off);
    _Set((std::uint8_t*)&ret, sizeof(T), Begin() + size, End());
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<_N, _Sign> Byte<N, Sign>::GetBlock(const std::size_t& off) const
{
    const std::size_t size = (off >= N ? N : off);
    Byte<_N, _Sign> ret{Begin() + size, End()};
    return ret;
}

template<std::size_t N, bool Sign>
std::uint8_t* Byte<N, Sign>::Get()
{
    return m_block;
}

template<std::size_t N, bool Sign>
const std::uint8_t* Byte<N, Sign>::Get() const
{
    return m_block;
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign>& Byte<N, Sign>::operator&=(const TValue& val)
{
    _And(Begin(), End(), (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator&=(const test::byte::Order& byte_order)
{
    _And(Begin(), End(), byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& 
Byte<N, Sign>::operator&=(test::byte::Offset<TValue>&& offset_val)
{
    _And(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>& Byte<N, Sign>::operator&=(const Byte<_N, _Sign>& other)
{
    _And(Begin(), End(), other.Begin(), other.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign>& Byte<N, Sign>::operator|=(const TValue& val)
{
    _Or(Begin(), End(), (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator|=(const test::byte::Order& byte_order)
{
    _Or(Begin(), End(), byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& 
Byte<N, Sign>::operator|=(test::byte::Offset<TValue>&& offset_val)
{
    _Or(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>& Byte<N, Sign>::operator|=(const Byte<_N, _Sign>& other)
{
    _Or(Begin(), End(), other.Begin(), other.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign>& Byte<N, Sign>::operator^=(const TValue& val)
{
    _Xor(Begin(), End(), (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator^=(const test::byte::Order& byte_order)
{
    _Xor(Begin(), End(), byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& 
Byte<N, Sign>::operator^=(test::byte::Offset<TValue>&& offset_val)
{
    _Xor(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign>& Byte<N, Sign>::operator^=(const Byte<_N, _Sign>& other)
{
    _Xor(Begin(), End(), other.Begin(), other.End());
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator<<=(const std::size_t& size)
{
    _LShift(m_block, N, size);
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator<<=(const int& size)
{
    if (size < 0) return *this >>= (std::size_t)-size;
    *this <<= (std::size_t)size;
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator>>=(const std::size_t& size)
{
    _RShift<Sign>(m_block, N, size);
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator>>=(const int& size)
{
    if (size < 0) return *this <<= (std::size_t)-size;
    *this >>= (std::size_t)size;
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator~() const
{
    Byte<N, Sign> ret{*this};
    _Not(ret.m_block, N);
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign> Byte<N, Sign>::operator&(const TValue& val)
{
    Byte<N, Sign> ret{*this};
    ret &= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator&(const test::byte::Order& byte_order)
{
    Byte<N, Sign> ret{*this};
    ret &= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> Byte<N, Sign>::operator&(test::byte::Offset<TValue>&& offset_val)
{
    Byte<N, Sign> ret{*this};
    ret &= offset_val;
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign> Byte<N, Sign>::operator&(const Byte<_N, _Sign>& other)
{
    Byte<N, Sign> ret{*this};
    ret &= other;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign> Byte<N, Sign>::operator|(const TValue& val)
{
    Byte<N, Sign> ret{*this};
    ret |= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator|(const test::byte::Order& byte_order)
{
    Byte<N, Sign> ret{*this};
    ret |= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> Byte<N, Sign>::operator|(test::byte::Offset<TValue>&& offset_val)
{
    Byte<N, Sign> ret{*this};
    ret |= offset_val;
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign> Byte<N, Sign>::operator|(const Byte<_N, _Sign>& other)
{
    Byte<N, Sign> ret{*this};
    ret |= other;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
Byte<N, Sign> Byte<N, Sign>::operator^(const TValue& val)
{
    Byte<N, Sign> ret{*this};
    ret ^= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator^(const test::byte::Order& byte_order)
{
    Byte<N, Sign> ret{*this};
    ret ^= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> Byte<N, Sign>::operator^(test::byte::Offset<TValue>&& offset_val)
{
    Byte<N, Sign> ret{*this};
    ret ^= offset_val;
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign> Byte<N, Sign>::operator^(const Byte<_N, _Sign>& other)
{
    Byte<N, Sign> ret{*this};
    ret ^= other;
    return ret;
}

template<std::size_t N, bool Sign>
std::uint8_t& Byte<N, Sign>::operator[](const std::size_t& index)
{
    static std::uint8_t tmp;
    tmp = 0;
    if (index >= N) return tmp;
    return *(Begin() + index);
}

template<std::size_t N, bool Sign>
std::uint8_t Byte<N, Sign>::operator[](const std::size_t& index) const
{
    return const_cast<Byte<N, Sign>*>(this)->operator[](index);
}

} //!test

#endif //!TEST_BYTE_H_
