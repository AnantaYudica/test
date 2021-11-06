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
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using IteratorType = test::byte::Iterator<std::uint8_t*, TCast, NStep>;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using ConstIteratorType = test::byte::Iterator<const std::uint8_t*, 
        TCast, NStep>;
private:
    static void _SetZero(std::uint8_t* ptr, std::size_t size);
private:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    static void _Set(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    static void _Set(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _Set(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    static void _And(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    static void _And(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _And(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    static void _Or(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    static void _Or(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    static void _Or(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
private:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    static void _Xor(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    static void _Xor(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
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
private:
    template<typename TBValue, typename TCast, std::size_t NStep>
    static bool _Equal(ConstIteratorType<TCast, NStep> a_bg, 
        ConstIteratorType<TCast, NStep> a_ed, 
        test::byte::Iterator<TBValue> b_bg, 
        test::byte::Iterator<TBValue> b_ed);
    template<typename TCast, std::size_t NStep>
    static bool _Equal(ConstIteratorType<TCast, NStep> a_bg, 
        ConstIteratorType<TCast, NStep> a_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TBValue>
    static bool _Equal(const std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TBValue> b_bg,
        test::byte::Iterator<TBValue> b_ed);
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
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> Begin();
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> End();
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> Begin() const;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> End() const;
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> ReverseBegin();
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    IteratorType<TCast, NStep> ReverseEnd();
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> ReverseBegin() const;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    ConstIteratorType<TCast, NStep> ReverseEnd() const;
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
    Byte<N, Sign> operator&(const TValue& val) const;
    Byte<N, Sign> operator&(const test::byte::Order& byte_order) const;
    template<typename TValue>
    Byte<N, Sign> operator&(test::byte::Offset<TValue>&& offset_val) const;
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign> operator&(const Byte<_N, _Sign>& other) const;
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
    Byte<N, Sign> operator|(const TValue& val) const;
    Byte<N, Sign> operator|(const test::byte::Order& byte_order) const;
    template<typename TValue>
    Byte<N, Sign> operator|(test::byte::Offset<TValue>&& offset_val) const;
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign> operator|(const Byte<_N, _Sign>& other) const;
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
    Byte<N, Sign> operator^(const TValue& val) const;
    Byte<N, Sign> operator^(const test::byte::Order& byte_order) const;
    template<typename TValue>
    Byte<N, Sign> operator^(test::byte::Offset<TValue>&& offset_val) const;
    template<std::size_t _N, bool _Sign>
    Byte<N, Sign> operator^(const Byte<_N, _Sign>& other) const;
public:
    Byte<N, Sign> operator<<(const std::size_t& size) const;
    Byte<N, Sign> operator<<(const int& size) const;
public:
    Byte<N, Sign> operator>>(const std::size_t& size) const;
    Byte<N, Sign> operator>>(const int& size) const;
public:
    std::uint8_t& operator[](const std::size_t& index);
    std::uint8_t operator[](const std::size_t& index) const;
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
    bool operator==(const TValue& val) const;
    bool operator==(const test::byte::Order& byte_order) const;
    template<typename TValue>
    bool operator==(test::byte::Offset<TValue>&& offset_val) const;
    template<std::size_t _N, bool _Sign>
    bool operator==(const Byte<_N, _Sign>& other) const;
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
    bool operator!=(const TValue& val) const;
    bool operator!=(const test::byte::Order& byte_order) const;
    template<typename TValue>
    bool operator!=(test::byte::Offset<TValue>&& offset_val) const;
    template<std::size_t _N, bool _Sign>
    bool operator!=(const Byte<_N, _Sign>& other) const;
};

template<std::size_t N, bool Sign>
void Byte<N, Sign>::_SetZero(std::uint8_t* ptr, std::size_t size)
{
    std::memset(ptr, 0, size);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue, typename TCast, std::size_t NStep>
void Byte<N, Sign>::_Set(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
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
template<typename TCast, std::size_t NStep>
void Byte<N, Sign>::_Set(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    _Set(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue, typename TCast, std::size_t NStep>
void Byte<N, Sign>::_And(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed,
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
template<typename TCast, std::size_t NStep>
void Byte<N, Sign>::_And(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    _And(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue, typename TCast, std::size_t NStep>
void Byte<N, Sign>::_Or(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
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
template<typename TCast, std::size_t NStep>
void Byte<N, Sign>::_Or(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    _Or(begin, end, src_bg, src_ed);
}

template<std::size_t N, bool Sign>
template<typename TIDestValue, typename TCast, std::size_t NStep>
void Byte<N, Sign>::_Xor(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
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
template<typename TCast, std::size_t NStep>
void Byte<N, Sign>::_Xor(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
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
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
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
template<typename TBValue, typename TCast, std::size_t NStep>
bool Byte<N, Sign>::_Equal(ConstIteratorType<TCast, NStep> a_bg, 
    ConstIteratorType<TCast, NStep> a_ed, 
    test::byte::Iterator<TBValue> b_bg, test::byte::Iterator<TBValue> b_ed)
{
    while(a_bg != a_ed && b_bg != b_ed)
    {
        if (*a_bg != *b_bg) return false;
        ++a_bg; ++b_bg;
    }
    return true;
}
    
template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
bool Byte<N, Sign>::_Equal(ConstIteratorType<TCast, NStep> a_bg, 
    ConstIteratorType<TCast, NStep> a_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    const auto op = GetOperator();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    return _Equal(a_bg, a_ed, begin, end);
}
    
template<std::size_t N, bool Sign>
template<typename TBValue>
bool Byte<N, Sign>::_Equal(const std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TBValue> b_bg, test::byte::Iterator<TBValue> b_ed)
{
    const auto op = GetOperator();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    return _Equal(begin, end, b_bg, b_ed);
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
    _SetZero(mov.Get(), _N);
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
    _SetZero(mov.Get(), _N);
    return *this;
}

template<std::size_t N, bool Sign>
std::size_t Byte<N, Sign>::Size() const
{
    return N;
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template IteratorType<TCast, NStep> 
Byte<N, Sign>::Begin()
{
    const auto op = GetOperator();
    return {m_block, 0, N, op.Begin(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template IteratorType<TCast, NStep>  
Byte<N, Sign>::End()
{
    const auto op = GetOperator();
    return {m_block, 0, N, op.End(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template ConstIteratorType<TCast, NStep> 
Byte<N, Sign>::Begin() const
{
    return const_cast<Byte<N, Sign>*>(this)->template Begin<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template ConstIteratorType<TCast, NStep> 
Byte<N, Sign>::End() const
{
    return const_cast<Byte<N, Sign>*>(this)->template End<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template IteratorType<TCast, NStep> 
Byte<N, Sign>::ReverseBegin()
{
    const auto op = GetReverseOperator();
    return {m_block, 0, N, op.Begin(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template IteratorType<TCast, NStep> 
Byte<N, Sign>::ReverseEnd()
{
    const auto op = GetReverseOperator();
    return {m_block, 0, N, op.End(0, N, NStep), op};
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template ConstIteratorType<TCast, NStep> 
Byte<N, Sign>::ReverseBegin() const
{
    return const_cast<Byte<N, Sign>*>(this)->
        template ReverseBegin<TCast, NStep>();
}

template<std::size_t N, bool Sign>
template<typename TCast, std::size_t NStep>
typename Byte<N, Sign>::template ConstIteratorType<TCast, NStep> 
Byte<N, Sign>::ReverseEnd() const
{
    return const_cast<Byte<N, Sign>*>(this)->
        template ReverseEnd<TCast, NStep>();
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
Byte<N, Sign> Byte<N, Sign>::operator&(const TValue& val) const
{
    Byte<N, Sign> ret{*this};
    ret &= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> 
Byte<N, Sign>::operator&(const test::byte::Order& byte_order) const
{
    Byte<N, Sign> ret{*this};
    ret &= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> 
Byte<N, Sign>::operator&(test::byte::Offset<TValue>&& offset_val) const
{
    Byte<N, Sign> ret{*this};
    ret &= std::forward<test::byte::Offset<TValue>>(offset_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign> Byte<N, Sign>::operator&(const Byte<_N, _Sign>& other) const
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
Byte<N, Sign> Byte<N, Sign>::operator|(const TValue& val) const
{
    Byte<N, Sign> ret{*this};
    ret |= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> 
Byte<N, Sign>::operator|(const test::byte::Order& byte_order) const
{
    Byte<N, Sign> ret{*this};
    ret |= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> 
Byte<N, Sign>::operator|(test::byte::Offset<TValue>&& offset_val) const
{
    Byte<N, Sign> ret{*this};
    ret |= std::forward<test::byte::Offset<TValue>>(offset_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign> Byte<N, Sign>::operator|(const Byte<_N, _Sign>& other) const
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
Byte<N, Sign> Byte<N, Sign>::operator^(const TValue& val) const
{
    Byte<N, Sign> ret{*this};
    ret ^= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> 
Byte<N, Sign>::operator^(const test::byte::Order& byte_order) const
{
    Byte<N, Sign> ret{*this};
    ret ^= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> 
Byte<N, Sign>::operator^(test::byte::Offset<TValue>&& offset_val) const
{
    Byte<N, Sign> ret{*this};
    ret ^= std::forward<test::byte::Offset<TValue>>(offset_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
Byte<N, Sign> Byte<N, Sign>::operator^(const Byte<_N, _Sign>& other) const
{
    Byte<N, Sign> ret{*this};
    ret ^= other;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator<<(const std::size_t& size) const
{
    Byte<N, Sign> ret{*this};
    ret <<= size;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator<<(const int& size) const
{
    Byte<N, Sign> ret{*this};
    ret <<= size;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator>>(const std::size_t& size) const
{
    Byte<N, Sign> ret{*this};
    ret >>= size;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator>>(const int& size) const
{
    Byte<N, Sign> ret{*this};
    ret >>= size;
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

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
bool Byte<N, Sign>::operator==(const TValue& val) const
{
    return _Equal(Begin(), End(), (const std::uint8_t*)&val, sizeof(TValue));
}

template<std::size_t N, bool Sign>
bool Byte<N, Sign>::operator==(const test::byte::Order& byte_order) const
{
    return _Equal(Begin(), End(), byte_order.Begin(), byte_order.End());
}

template<std::size_t N, bool Sign>
template<typename TValue>
bool Byte<N, Sign>::operator==(test::byte::Offset<TValue>&& offset_val) const
{
    return _Equal(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
bool Byte<N, Sign>::operator==(const Byte<_N, _Sign>& other) const
{
    return _Equal(Begin(), End(), other.Begin(), other.End());
}

template<std::size_t N, bool Sign>
template<typename TValue, typename _TValue,
    typename std::enable_if<!test::trait::byte::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::off::IsBaseOf<_TValue>::Value &&
        !test::trait::byte::it::IsBaseOf<_TValue>::Value &&
        !std::is_base_of<test::byte::Order, _TValue>::value &&
        !std::is_pointer<_TValue>::value &&
        !std::is_array<_TValue>::value, int>::type>
bool Byte<N, Sign>::operator!=(const TValue& val) const
{
    return !(*this == val);
}

template<std::size_t N, bool Sign>
bool Byte<N, Sign>::operator!=(const test::byte::Order& byte_order) const
{
    return !(*this == byte_order);
}

template<std::size_t N, bool Sign>
template<typename TValue>
bool Byte<N, Sign>::operator!=(test::byte::Offset<TValue>&& offset_val) const
{
    return !(*this == std::forward<test::byte::Offset<TValue>>(offset_val));
}

template<std::size_t N, bool Sign>
template<std::size_t _N, bool _Sign>
bool Byte<N, Sign>::operator!=(const Byte<_N, _Sign>& other) const
{
    return !(*this == other);
}

} //!test

#endif //!TEST_BYTE_H_
