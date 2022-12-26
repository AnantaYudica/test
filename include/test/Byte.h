#ifndef TEST_BYTE_H_
#define TEST_BYTE_H_

#include "System.h"
#include "Pointer.h"
#include "Queue.h"
#include "trait/byte/IsBaseOf.h"
#include "trait/byte/it/IsBaseOf.h"
#include "trait/byte/off/IsBaseOf.h"
#include "byte/Base.h"
#include "byte/Operator.h"
#include "byte/Offset.h"
#include "byte/Iterator.h"
#include "byte/Order.h"
#include "byte/Sequence.h"

#include <cstdint>
#include <type_traits>
#include <utility>
#include <cstring>

#include <cstddef>

namespace test
{

template<std::size_t N, bool Sign>
class Byte;

} //!test

#ifndef TEST_BYTE_DLEVEL

#define TEST_BYTE_DLEVEL 2

#endif //!TEST_BYTE_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<std::size_t, N>,\
    test::sys::dbg::type::Value<bool, Sign>

template<std::size_t N, bool Sign>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_BYTE_DLEVEL, 
    "test::Byte", 
    test::Byte<N, Sign>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#define TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T test::Byte<N, Sign>

template<std::size_t N, bool Sign>
TEST_SYS_DBG_VALUE_PARAMETER_DEFINE("%p", &val);

#undef TEST_SYS_DBG_VALUE_PARAMETER_DEFINE_T

namespace test
{

template<std::size_t N, bool Sign = false>
class Byte : public test::byte::Base<N, Sign>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::Byte<N, Sign>> DebugType;
public:
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using IteratorType = test::byte::Iterator<std::uint8_t*, TCast, NStep>;
    template<typename TCast = std::uint8_t, std::size_t NStep = sizeof(TCast)>
    using ConstIteratorType = test::byte::Iterator<const std::uint8_t*, 
        TCast, NStep>;
public:
    typedef test::byte::Operator OperatorType;
public:
    static test::byte::it::Operator GetOrderOperator();
    static test::byte::it::Operator GetReverseOrderOperator();
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte(test::byte::Sequence<Flag, TValue>&& seq_val);
public:
    ~Byte();
public:
    template<std::size_t RN, bool RSign>
    Byte(const Byte<RN, RSign>& cpy);
    template<std::size_t RN, bool RSign>
    Byte(Byte<RN, RSign>&& mov);
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign>& operator=(test::byte::Sequence<Flag, TValue>&& seq_val);
public:
    template<std::size_t RN, bool RSign>
    Byte<N, Sign>& operator=(const Byte<RN, RSign>& cpy);
    template<std::size_t RN, bool RSign>
    Byte<N, Sign>& operator=(Byte<RN, RSign>&& mov);
public:
    using test::byte::Base<N, Sign>::Size;
public:
    using test::byte::Base<N, Sign>::Begin;
    using test::byte::Base<N, Sign>::End;
public:
    using test::byte::Base<N, Sign>::ReverseBegin;
    using test::byte::Base<N, Sign>::ReverseEnd;
public:
    using test::byte::Base<N, Sign>::CastTo;
public:
    template<std::size_t LN = N, bool LSign = Sign>
    test::Byte<LN, LSign> Resize(const std::size_t& r_off = 0, 
        const std::size_t& r_size = LN, const std::size_t& l_off = 0, 
        const std::size_t& l_size = LN) const;
public:
    using test::byte::Base<N, Sign>::Get;
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign>& operator&=(test::byte::Sequence<Flag, TValue>&& seq_val);
    template<std::size_t RN, bool RSign>
    Byte<N, Sign>& operator&=(const test::byte::Base<RN, RSign>& other);
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign>& operator|=(test::byte::Sequence<Flag, TValue>&& seq_val);
    template<std::size_t RN, bool RSign>
    Byte<N, Sign>& operator|=(const test::byte::Base<RN, RSign>& other);
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign>& operator^=(test::byte::Sequence<Flag, TValue>&& seq_val);
    template<std::size_t RN, bool RSign>
    Byte<N, Sign>& operator^=(const test::byte::Base<RN, RSign>& other);
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign> operator&(test::byte::Sequence<Flag, TValue>&& seq_val) const;
    template<std::size_t RN, bool RSign>
    Byte<N, Sign> operator&(const test::byte::Base<RN, RSign>& other) const;
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign> operator|(test::byte::Sequence<Flag, TValue>&& seq_val) const;
    template<std::size_t RN, bool RSign>
    Byte<N, Sign> operator|(const test::byte::Base<RN, RSign>& other) const;
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
    template<test::byte::seq::Flag Flag, typename TValue>
    Byte<N, Sign> operator^(test::byte::Sequence<Flag, TValue>&& seq_val) const;
    template<std::size_t RN, bool RSign>
    Byte<N, Sign> operator^(const test::byte::Base<RN, RSign>& other) const;
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
    template<test::byte::seq::Flag Flag, typename TValue>
    bool operator==(test::byte::Sequence<Flag, TValue>&& seq_val) const;
    template<std::size_t RN, bool RSign>
    bool operator==(const test::byte::Base<RN, RSign>& other) const;
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
    template<test::byte::seq::Flag Flag, typename TValue>
    bool operator!=(test::byte::Sequence<Flag, TValue>&& seq_val) const;
    template<std::size_t RN, bool RSign>
    bool operator!=(const test::byte::Base<RN, RSign>& other) const;
};

template<std::size_t N, bool Sign>
test::byte::it::Operator Byte<N, Sign>::GetOrderOperator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "GetOrderOperator()");

    return test::byte::Operator::GetInstance().GetOrder();
}

template<std::size_t N, bool Sign>
test::byte::it::Operator Byte<N, Sign>::GetReverseOrderOperator()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "GetReverseOrderOperator()");

    return test::byte::Operator::GetInstance().GetReverseOrder();
}

template<std::size_t N, bool Sign>
Byte<N, Sign>::Byte() :
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

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
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(val=%s)", 
            TEST_SYS_DEBUG_T_NAME_STR(TValue),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(val));

    test::byte::Operator::GetInstance().Set(Begin(), End(),
        (const std::uint8_t*)&val, sizeof(TValue));
}

template<std::size_t N, bool Sign>
Byte<N, Sign>::Byte(const test::byte::Order& byte_order) :
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(byte_order=%p)", &byte_order);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(),
        byte_order.Begin(), byte_order.End());
}

template<std::size_t N, bool Sign>
template<typename TIValue>
Byte<N, Sign>::Byte(test::byte::Iterator<TIValue> bg, 
    test::byte::Iterator<TIValue> ed) :
        test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(bg=%p, ed=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TIValue),
        &*bg, &*ed);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(), bg, ed);
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>::Byte(test::byte::Offset<TValue>&& offset_val) :
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(offset_val=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TValue),
        &offset_val);
    
    test::byte::Operator::GetInstance().Set(
        Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign>::Byte(test::byte::Sequence<Flag, TValue>&& seq_val) :
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    test::byte::Operator::GetInstance().Set(
        std::move(seq_val).LeftBegin(*this), 
        std::move(seq_val).LeftEnd(*this),
        std::move(seq_val).RightBegin(),
        std::move(seq_val).RightEnd());
}

template<std::size_t N, bool Sign>
Byte<N, Sign>::~Byte()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");

}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>::Byte(const Byte<RN, RSign>& cpy) :
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor<%s>(cpy=%p)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &cpy);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(),
        cpy.Begin(), cpy.End());
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>::Byte(Byte<RN, RSign>&& mov) :
    test::byte::Base<N, Sign>()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor<%s>(mov=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &mov);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(),
        std::move(mov).Begin(), std::move(mov).End());
    OperatorType::GetInstance().SetZero(mov.Get(), RN);
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
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment<%s>(val=%s)", 
        TEST_SYS_DEBUG_T_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    test::byte::Operator::GetInstance().Set(Begin(), End(), 
        (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator=(const test::byte::Order& byte_order)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment(byte_order=%p)", &byte_order);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(), 
        byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& Byte<N, Sign>::
    operator=(test::byte::Offset<TValue>&& offset_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment<%s>(offset_val=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TValue), &offset_val);
    
    test::byte::Operator::GetInstance().Set(
        Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign>& Byte<N, Sign>::
    operator=(test::byte::Sequence<Flag, TValue>&& seq_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Assignment<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    test::byte::Operator::GetInstance().Set(
        std::move(seq_val).LeftBegin(*this),
        std::move(seq_val).LeftEnd(*this),
        std::move(seq_val).RightBegin(),
        std::move(seq_val).RightEnd());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>& Byte<N, Sign>::operator=(const Byte<RN, RSign>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment<%s>(cpy=%p)",
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &cpy);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(),
        cpy.Begin(), cpy.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>& Byte<N, Sign>::operator=(Byte<RN, RSign>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment<%s>(mov=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &mov);
    
    test::byte::Operator::GetInstance().Set(Begin(), End(),
        std::move(mov).Begin(), std::move(mov).End());
    OperatorType::GetInstance().SetZero(mov.Get(), RN);
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t LN, bool LSign>
test::Byte<LN, LSign> Byte<N, Sign>::Resize(const std::size_t& r_off, 
    const std::size_t& r_size, const std::size_t& l_off, 
    const std::size_t& l_size) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Resize<%s>(r_off=%zu, r_size=%zu, l_off=%zu, l_size=%zu) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, LN),
            TEST_SYS_DEBUG_TV_TYPE(bool, LSign)), r_off, r_size,
            l_off, l_size);
    
    test::Byte<LN, LSign> res;
    auto lend = (l_off + l_size) >= LN ? res.End() : res.Begin() + l_off + l_size;
    auto rend = (r_off + r_size) >= N ? End() : (Begin() + r_off + r_size);
    OperatorType::GetInstance().Set(res.Begin() + l_off, 
        lend, Begin() + r_off, rend);
    
    return res;
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&=<%s>(val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    OperatorType::GetInstance().And(Begin(), End(), 
        (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator&=(const test::byte::Order& byte_order)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&=(byte_order=%p)", &byte_order);
    
    OperatorType::GetInstance().And(Begin(), End(), 
        byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& 
Byte<N, Sign>::operator&=(test::byte::Offset<TValue>&& offset_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&=<%s>(offset_val=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TValue),
        &offset_val);
    
    OperatorType::GetInstance().And(Begin() + std::move(offset_val).Size(), 
        End(), std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign>& Byte<N, Sign>::
    operator&=(test::byte::Sequence<Flag, TValue>&& seq_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator&=<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    test::byte::Operator::GetInstance().And(
        std::move(seq_val).LeftBegin(*this),
        std::move(seq_val).LeftEnd(*this),
        std::move(seq_val).RightBegin(),
        std::move(seq_val).RightEnd());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>& Byte<N, Sign>::
    operator&=(const test::byte::Base<RN, RSign>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&=<%s>(other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &other);
    
    OperatorType::GetInstance().And(Begin(), End(), 
        other.Begin(), other.End());
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|=<%s>(val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    OperatorType::GetInstance().Or(Begin(), End(), 
        (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator|=(const test::byte::Order& byte_order)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|=(byte_order=%p)", &byte_order);
    
    OperatorType::GetInstance().Or(Begin(), End(), 
        byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& 
Byte<N, Sign>::operator|=(test::byte::Offset<TValue>&& offset_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|=<%s>(offset_val=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TValue),
        &offset_val);
    
    OperatorType::GetInstance().Or(Begin() + std::move(offset_val).Size(), 
        End(), std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign>& Byte<N, Sign>::
    operator|=(test::byte::Sequence<Flag, TValue>&& seq_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator|=<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    test::byte::Operator::GetInstance().Or(
        std::move(seq_val).LeftBegin(*this),
        std::move(seq_val).LeftEnd(*this),
        std::move(seq_val).RightBegin(),
        std::move(seq_val).RightEnd());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>& Byte<N, Sign>::
    operator|=(const test::byte::Base<RN, RSign>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|=<%s>(other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &other);
    
    OperatorType::GetInstance().Or(Begin(), End(), 
        other.Begin(), other.End());
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^=<%s>(val=%s)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    OperatorType::GetInstance().Xor(Begin(), End(), 
        (const std::uint8_t*)&val, sizeof(TValue));
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator^=(const test::byte::Order& byte_order)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^=(byte_order=%p)", &byte_order);
    
    OperatorType::GetInstance().Xor(Begin(), End(), 
        byte_order.Begin(), byte_order.End());
    return *this;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign>& 
Byte<N, Sign>::operator^=(test::byte::Offset<TValue>&& offset_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^=<%s>(offset_val=%p)", 
        TEST_SYS_DEBUG_T_NAME_STR(TValue),
        &offset_val);
    
    OperatorType::GetInstance().Xor(Begin() + std::move(offset_val).Size(), 
        End(), std::move(offset_val).Begin(), std::move(offset_val).End());
    return *this;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign>& Byte<N, Sign>::
    operator^=(test::byte::Sequence<Flag, TValue>&& seq_val)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator^=<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    test::byte::Operator::GetInstance().Xor(
        std::move(seq_val).LeftBegin(*this),
        std::move(seq_val).LeftEnd(*this),
        std::move(seq_val).RightBegin(),
        std::move(seq_val).RightEnd());
    return *this;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign>& Byte<N, Sign>::
    operator^=(const test::byte::Base<RN, RSign>& other)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^=<%s>(other=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &other);
    
    OperatorType::GetInstance().Xor(Begin(), End(), 
        other.Begin(), other.End());
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator<<=(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<=(size=%zu)", size);
    
    OperatorType::GetInstance().LShift(Get(), N, size);
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator<<=(const int& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<=(size=%d)", size);
    
    if (size < 0) return *this >>= (std::size_t)-size;
    *this <<= (std::size_t)size;
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator>>=(const std::size_t& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>=(size=%zu)", size);
    
    OperatorType::GetInstance().RShift<Sign>(Get(), N, size);
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign>& Byte<N, Sign>::operator>>=(const int& size)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>=(size=%d)", size);
    
    if (size < 0) return *this <<= (std::size_t)-size;
    *this >>= (std::size_t)size;
    return *this;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator~() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "operator~() const");
    
    Byte<N, Sign> ret{*this};
    OperatorType::GetInstance().Not(ret.Get(), N);
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&<%s>(val=%s) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    Byte<N, Sign> ret{*this};
    ret &= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> 
Byte<N, Sign>::operator&(const test::byte::Order& byte_order) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&(byte_order=%p) const", &byte_order);
    
    Byte<N, Sign> ret{*this};
    ret &= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> 
Byte<N, Sign>::operator&(test::byte::Offset<TValue>&& offset_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&<%s>(offset_val=%p) const", 
            TEST_SYS_DEBUG_T_NAME_STR(TValue),
            &offset_val);
    
    Byte<N, Sign> ret{*this};
    ret &= std::forward<test::byte::Offset<TValue>>(offset_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign> Byte<N, Sign>::
    operator&(test::byte::Sequence<Flag, TValue>&& seq_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator&<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    Byte<N, Sign> ret{*this};
    ret &= std::forward<test::byte::Sequence<Flag, TValue>>(seq_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign> Byte<N, Sign>::
    operator&(const test::byte::Base<RN, RSign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &other);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|<%s>(val=%s) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    Byte<N, Sign> ret{*this};
    ret |= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> 
Byte<N, Sign>::operator|(const test::byte::Order& byte_order) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|(byte_order=%p) const", &byte_order);
    
    Byte<N, Sign> ret{*this};
    ret |= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> 
Byte<N, Sign>::operator|(test::byte::Offset<TValue>&& offset_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|<%s>(offset_val=%p) const", 
            TEST_SYS_DEBUG_T_NAME_STR(TValue),
            &offset_val);
    
    Byte<N, Sign> ret{*this};
    ret |= std::forward<test::byte::Offset<TValue>>(offset_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign> Byte<N, Sign>::
    operator|(test::byte::Sequence<Flag, TValue>&& seq_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator|<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    Byte<N, Sign> ret{*this};
    ret |= std::forward<test::byte::Sequence<Flag, TValue>>(seq_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign> Byte<N, Sign>::
    operator|(const test::byte::Base<RN, RSign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &other);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^<%s>(val=%s) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    Byte<N, Sign> ret{*this};
    ret ^= val;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> 
Byte<N, Sign>::operator^(const test::byte::Order& byte_order) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^(byte_order=%p) const", &byte_order);
    
    Byte<N, Sign> ret{*this};
    ret ^= byte_order;
    return ret;
}

template<std::size_t N, bool Sign>
template<typename TValue>
Byte<N, Sign> 
Byte<N, Sign>::operator^(test::byte::Offset<TValue>&& offset_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^<%s>(offset_val=%p) const", 
            TEST_SYS_DEBUG_T_NAME_STR(TValue),
            &offset_val);
    
    Byte<N, Sign> ret{*this};
    ret ^= std::forward<test::byte::Offset<TValue>>(offset_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
Byte<N, Sign> Byte<N, Sign>::
    operator^(test::byte::Sequence<Flag, TValue>&& seq_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "operator^<%s>(seq_val=%p)", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(test::byte::seq::Flag, Flag),
            TEST_SYS_DEBUG_T_TYPE(TValue)),
        &seq_val);
    
    Byte<N, Sign> ret{*this};
    ret ^= std::forward<test::byte::Sequence<Flag, TValue>>(seq_val);
    return ret;
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
Byte<N, Sign> Byte<N, Sign>::
    operator^(const test::byte::Base<RN, RSign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^<%s>(other=%p) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(
            TEST_SYS_DEBUG_TV_TYPE(std::size_t, RN),
            TEST_SYS_DEBUG_TV_TYPE(bool, RSign)), &other);
    
    Byte<N, Sign> ret{*this};
    ret ^= other;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator<<(const std::size_t& size) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<(size=%zu) const", size);
    
    Byte<N, Sign> ret{*this};
    ret <<= size;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator<<(const int& size) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<(size=%d) const", size);
    
    Byte<N, Sign> ret{*this};
    ret <<= size;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator>>(const std::size_t& size) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>(size=%zu) const", size);
    
    Byte<N, Sign> ret{*this};
    ret >>= size;
    return ret;
}

template<std::size_t N, bool Sign>
Byte<N, Sign> Byte<N, Sign>::operator>>(const int& size) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>(size=%d) const", size);
    
    Byte<N, Sign> ret{*this};
    ret >>= size;
    return ret;
}

template<std::size_t N, bool Sign>
std::uint8_t& Byte<N, Sign>::operator[](const std::size_t& index)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu)", index);
    
    static std::uint8_t tmp;
    tmp = 0;
    if (index >= N) return tmp;
    return *(Begin() + index);
}

template<std::size_t N, bool Sign>
std::uint8_t Byte<N, Sign>::operator[](const std::size_t& index) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator[](index=%zu) const", index);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(val=%s) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    return OperatorType::GetInstance().Equal(Begin(), End(), 
        (const std::uint8_t*)&val, sizeof(TValue));
}

template<std::size_t N, bool Sign>
bool Byte<N, Sign>::operator==(const test::byte::Order& byte_order) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(byte_order=%p) const", &byte_order);
    
    return OperatorType::GetInstance().Equal(Begin(), End(), 
        byte_order.Begin(), byte_order.End());
}

template<std::size_t N, bool Sign>
template<typename TValue>
bool Byte<N, Sign>::operator==(test::byte::Offset<TValue>&& offset_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(offset_val=%p) const", &offset_val);
    
    return OperatorType::GetInstance().
        Equal(Begin() + std::move(offset_val).Size(), End(), 
        std::move(offset_val).Begin(), std::move(offset_val).End());
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
bool Byte<N, Sign>::
    operator==(test::byte::Sequence<Flag, TValue>&& seq_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(seq_val=%p) const", &seq_val);
    
    return OperatorType::GetInstance().Equal(
        std::move(seq_val).LeftBegin(*this),
        std::move(seq_val).LeftEnd(*this),
        std::move(seq_val).RightBegin(),
        std::move(seq_val).RightEnd());
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
bool Byte<N, Sign>::
    operator==(const test::byte::Base<RN, RSign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator==(other=%p) const", &other);
    
    return OperatorType::GetInstance().Equal(Begin(), End(), 
        other.Begin(), other.End());
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(val=%s) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TValue),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(val));
    
    return !(*this == val);
}

template<std::size_t N, bool Sign>
bool Byte<N, Sign>::operator!=(const test::byte::Order& byte_order) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(byte_order=%p) const", &byte_order);
    
    return !(*this == byte_order);
}

template<std::size_t N, bool Sign>
template<typename TValue>
bool Byte<N, Sign>::operator!=(test::byte::Offset<TValue>&& offset_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(offset_val=%p) const", &offset_val);
    
    return !(*this == std::forward<test::byte::Offset<TValue>>(offset_val));
}

template<std::size_t N, bool Sign>
template<test::byte::seq::Flag Flag, typename TValue>
bool Byte<N, Sign>::
    operator!=(test::byte::Sequence<Flag, TValue>&& seq_val) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(seq_val=%p) const", &seq_val);
    
    return !(*this == 
        std::forward<test::byte::Sequence<Flag, TValue>>(seq_val));
}

template<std::size_t N, bool Sign>
template<std::size_t RN, bool RSign>
bool Byte<N, Sign>::
    operator!=(const test::byte::Base<RN, RSign>& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator!=(other=%p) const", &other);
    
    return !(*this == other);
}

} //!test

#endif //!TEST_BYTE_H_
