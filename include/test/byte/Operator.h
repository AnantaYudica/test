#ifndef TEST_BYTE_OPERATOR_H_
#define TEST_BYTE_OPERATOR_H_

#include "../System.h"
#include "../Queue.h"
#include "Order.h"
#include "Iterator.h"

#include <cstdlib>
#include <cstdint>
#include <cstring>

namespace test::byte
{
class Operator;
}

#ifndef TEST_BYTE_OPERATOR_DLEVEL

#define TEST_BYTE_OPERATOR_DLEVEL 2

#endif //!TEST_BYTE_OPERATOR_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(
    TEST_BYTE_OPERATOR_DLEVEL,
    "test::byte::Operator",
    test::byte::Operator);

namespace test
{
namespace byte
{

class Operator
{
public:
    static inline Operator& GetInstance();
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::Operator> DebugType;
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using IteratorType = test::byte::Iterator<std::uint8_t*, TCast, NStep>;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using ConstIteratorType = test::byte::Iterator<const std::uint8_t*, 
        TCast, NStep>;
public:
    inline Operator();
public:
    inline ~Operator();
public:
    inline Operator(const Operator& cpy);
    inline Operator(Operator&& mov);
public:
    inline Operator& operator=(const Operator& cpy);
    inline Operator& operator=(Operator&& mov);
public:
    inline void SetZero(std::uint8_t* ptr, std::size_t size);
public:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    inline void Set(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    inline void Set(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    inline void Set(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
public:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    inline void And(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    inline void And(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    inline void And(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
public:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    inline void Or(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    inline void Or(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    inline void Or(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
public:
    template<typename TIDestValue, typename TCast, std::size_t NStep>
    inline void Xor(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
    template<typename TCast, std::size_t NStep>
    inline void Xor(IteratorType<TCast, NStep> dest_bg, 
        IteratorType<TCast, NStep> dest_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TIDestValue>
    inline void Xor(std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TIDestValue> src_bg,
        test::byte::Iterator<TIDestValue> src_ed);
public:
    inline void Not(std::uint8_t* ptr, std::size_t size);
public:
    template<bool _Sign, typename std::enable_if<_Sign, int>::type = 1>
    inline void RShift(std::uint8_t* ptr, std::size_t size, 
        std::size_t shift);
    template<bool _Sign, typename std::enable_if<!_Sign, int>::type = 1>
    inline void RShift(std::uint8_t* ptr, std::size_t size,
        std::size_t shift);
public:
    inline void LShift(std::uint8_t* ptr, std::size_t size, 
        std::size_t shift);
public:
    template<typename TBValue, typename TCast, std::size_t NStep>
    inline bool Equal(ConstIteratorType<TCast, NStep> a_bg, 
        ConstIteratorType<TCast, NStep> a_ed, 
        test::byte::Iterator<TBValue> b_bg, 
        test::byte::Iterator<TBValue> b_ed);
    template<typename TCast, std::size_t NStep>
    inline bool Equal(ConstIteratorType<TCast, NStep> a_bg, 
        ConstIteratorType<TCast, NStep> a_ed, 
        const std::uint8_t* ptr, std::size_t size);
    template<typename TBValue>
    inline bool Equal(const std::uint8_t* ptr, std::size_t size, 
        test::byte::Iterator<TBValue> b_bg,
        test::byte::Iterator<TBValue> b_ed);
public:
    inline test::byte::it::Operator GetOrder();
    inline test::byte::it::Operator GetReverseOrder();
};

inline Operator& Operator::GetInstance()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "GetInstance()");

    static Operator instance;
    return instance;
}

inline Operator::Operator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}
    
inline Operator::~Operator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
}
    
inline Operator::Operator(const Operator& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

inline Operator::Operator(Operator&& mov)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(mov=%p)", &mov);

}

inline Operator& Operator::operator=(const Operator& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    return *this;
}

inline Operator& Operator::operator=(Operator&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(mov=%p)", &mov);

    return *this;
}

inline void Operator::SetZero(std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "SetZero(ptr=%p, size=%zu)", ptr, size);

    std::memset(ptr, 0, size);
}

template<typename TIDestValue, typename TCast, std::size_t NStep>
inline void Operator::Set(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(dest_bg=%p, dest_ed=%p, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TIDestValue), 
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, &*src_bg, &*src_ed);

    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg = *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<typename TCast, std::size_t NStep>
inline void Operator::Set(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(dest_bg=%p, dest_ed=%p, ptr=%p, size=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, ptr, size);

    const auto op = GetOrder();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    Set(dest_bg, dest_ed, begin, end);
}

template<typename TIDestValue>
inline void Operator::Set(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Set<%s>(ptr=%p, size=%zu, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TIDestValue),
        ptr, size, &*src_bg, &*src_ed);

    const auto op = GetOrder();
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    Set(begin, end, src_bg, src_ed);
}

template<typename TIDestValue, typename TCast, std::size_t NStep>
inline void Operator::And(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed,
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "And<%s>(dest_bg=%p, dest_ed=%p, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TIDestValue), 
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, &*src_bg, &*src_ed);

    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg &= *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<typename TCast, std::size_t NStep>
inline void Operator::And(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "And<%s>(dest_bg=%p, dest_ed=%p, ptr=%p, size=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, ptr, size);

    const auto op = GetOrder();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    And(dest_bg, dest_ed, begin, end);
}

template<typename TIDestValue>
inline void Operator::And(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "And<%s>(ptr=%p, size=%zu, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TIDestValue),
        ptr, size, &*src_bg, &*src_ed);

    const auto op = GetOrder();
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    And(begin, end, src_bg, src_ed);
}

template<typename TIDestValue, typename TCast, std::size_t NStep>
inline void Operator::Or(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Or<%s>(dest_bg=%p, dest_ed=%p, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TIDestValue),
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, &*src_bg, &*src_ed);

    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg |= *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<typename TCast, std::size_t NStep>
inline void Operator::Or(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Or<%s>(dest_bg=%p, dest_ed=%p, ptr=%p, size=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, ptr, size);

    const auto op = GetOrder();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    Or(dest_bg, dest_ed, begin, end);
}

template<typename TIDestValue>
inline void Operator::Or(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Or<%s>(ptr=%p, size=%zu, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TIDestValue),
        ptr, size, &*src_bg, &*src_ed);

    const auto op = GetOrder();
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    Or(begin, end, src_bg, src_ed);
}

template<typename TIDestValue, typename TCast, std::size_t NStep>
inline void Operator::Xor(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Xor<%s>(dest_bg=%p, dest_ed=%p, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TIDestValue), 
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, &*src_bg, &*src_ed);

    while(dest_bg != dest_ed && src_bg != src_ed)
    {
        *dest_bg ^= *src_bg;
        ++dest_bg; ++src_bg;
    }
}

template<typename TCast, std::size_t NStep>
inline void Operator::Xor(IteratorType<TCast, NStep> dest_bg, 
    IteratorType<TCast, NStep> dest_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Xor<%s>(dest_bg=%p, dest_ed=%p, ptr=%p, size=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast), 
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*dest_bg, &*dest_ed, ptr, size);

    const auto op = GetOrder();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    Xor(dest_bg, dest_ed, begin, end);
}

template<typename TIDestValue>
inline void Operator::Xor(std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TIDestValue> src_bg,
    test::byte::Iterator<TIDestValue> src_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Xor<%s>(ptr=%p, size=%zu, src_bg=%p, src_ed=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TIDestValue),
        ptr, size, &*src_bg, &*src_ed);

    const auto op = GetOrder();
    IteratorType<std::uint8_t> begin{ptr, 0, size, op.Begin(0, size), op};
    IteratorType<std::uint8_t> end{ptr, 0, size, op.End(0, size), op};
    Xor(begin, end, src_bg, src_ed);
}

inline void Operator::Not(std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Not(ptr=%p, size=%zu)", 
        ptr, size);

    for(std::size_t i = 0; i < size; ++i)
    {
        ptr[i] = ~ptr[i];
    }
}

template<bool _Sign, typename std::enable_if<_Sign, int>::type>
inline void Operator::RShift(std::uint8_t* ptr, std::size_t size, 
    std::size_t shift)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RShift<%s>(ptr=%p, size=%zu, shift=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(bool, _Sign),
            TEST_SYS_DEBUG_T_TYPE(typename std::enable_if<_Sign, int>::type)),
        ptr, size, shift);

    test::Queue<std::uint8_t> queue;
    auto op = GetReverseOrder();
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

template<bool _Sign, typename std::enable_if<!_Sign, int>::type>
inline void Operator::RShift(std::uint8_t* ptr, std::size_t size, 
    std::size_t shift)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "RShift<%s>(ptr=%p, size=%zu, shift=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(bool, _Sign),
            TEST_SYS_DEBUG_T_TYPE(typename std::enable_if<!_Sign, int>::type)),
        ptr, size, shift);

    test::Queue<std::uint8_t> queue;
    auto op = GetReverseOrder();
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

inline void Operator::LShift(std::uint8_t* ptr, std::size_t size, 
    std::size_t shift)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "LShift(ptr=%p, size=%zu, shift=%zu)", ptr, size, shift);

    test::Queue<std::uint8_t> queue;
    auto op = GetOrder();
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

template<typename TBValue, typename TCast, std::size_t NStep>
inline bool Operator::Equal(ConstIteratorType<TCast, NStep> a_bg, 
    ConstIteratorType<TCast, NStep> a_ed, 
    test::byte::Iterator<TBValue> b_bg, test::byte::Iterator<TBValue> b_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Equal<%s>(a_bg=%p, a_ed=%p, b_bg=%p, b_ed=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TBValue),
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*a_bg, &*a_ed, &*b_bg, &*b_ed);

    while(a_bg != a_ed && b_bg != b_ed)
    {
        if (*a_bg != *b_bg) return false;
        ++a_bg; ++b_bg;
    }
    return true;
}

template<typename TCast, std::size_t NStep>
inline bool Operator::Equal(ConstIteratorType<TCast, NStep> a_bg, 
    ConstIteratorType<TCast, NStep> a_ed, 
    const std::uint8_t* ptr, std::size_t size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Equal<%s>(a_bg=%p, a_ed=%p, ptr=%p, size=%zu)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_T_TYPE(TCast),
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, NStep)),
        &*a_bg, &*a_ed, ptr, size);

    const auto op = GetOrder();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0,
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    return Equal(a_bg, a_ed, begin, end);
}

template<typename TBValue>
inline bool Operator::Equal(const std::uint8_t* ptr, std::size_t size, 
    test::byte::Iterator<TBValue> b_bg, test::byte::Iterator<TBValue> b_ed)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Equal<%s>(ptr=%p, size=%zu, b_bg=%p, b_ed=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TBValue),
        ptr, size, &*b_bg, &*b_ed);

    const auto op = GetOrder();
    ConstIteratorType<std::uint8_t> begin{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.Begin(0, size), op};
    ConstIteratorType<std::uint8_t> end{const_cast<std::uint8_t*>(ptr), 0, 
        size, op.End(0, size), op};
    return Equal(begin, end, b_bg, b_ed);
}

inline test::byte::it::Operator Operator::GetOrder()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetOrder()");

    return test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetMachineEndian());
}

inline test::byte::it::Operator Operator::GetReverseOrder()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetReverseOrder()");

    return test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetReverseEndian(
            test::byte::Order::GetMachineEndian()));
}


} //!byte

} //!test

#endif //!TEST_BYTE_OPERATOR_H_
