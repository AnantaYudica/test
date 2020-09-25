#ifndef TEST_BYTE_ORDER_H_
#define TEST_BYTE_ORDER_H_

#include "../Pointer.h"
#include "Iterator.h"
#include "it/Operator.h"
#include "order/op/BigEndian.h"
#include "order/op/LittleEndian.h"

#include <cstdint>
#include <cstring>
#include <type_traits>

namespace test
{
namespace byte
{

class Order
{
public:
    typedef test::byte::it::Operator OperatorType;
    typedef test::Pointer<std::uint8_t> PointerType;
    typedef test::byte::Iterator<test::Pointer<std::uint8_t>> IteratorType;
    typedef test::byte::Iterator<const test::Pointer<std::uint8_t>> 
        ConstIteratorType;
public:
    static constexpr int big_endian = 1;
    static constexpr int little_endian = 2;
public:
    static inline int GetMachineEndian();
    static inline int GetDefaultEndian();
    static inline int GetReverseEndian(const int& endian);
public:
    static inline OperatorType 
        GetOperatorInstance(const int& endian = GetDefaultEndian());
private:
    OperatorType m_op;
    PointerType m_ptr;
public:
    inline Order();
    template<std::size_t N>
    inline Order(const std::uint8_t (&val)[N]);
    inline Order(const std::uint8_t* val, std::size_t size);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_base_of<Order, _TArg>::value &&
            !std::is_base_of<test::byte::it::Operator, _TArg>::value &&
            !std::is_array<_TArg>::value &&
            !std::is_pointer<_TArg>::value, int>::type = 1>
    inline Order(TArg&& arg, TArgs&&... args);
    template<std::size_t N>
    inline Order(const OperatorType& op, const std::uint8_t (&val)[N]);
    inline Order(const OperatorType& op, const std::uint8_t* val, 
        std::size_t size);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_array<_TArg>::value &&
            !std::is_pointer<_TArg>::value, int>::type = 1>
    inline Order(const OperatorType& op, TArg&& arg, TArgs&&... args);
public:
    inline Order(const Order& cpy);
    inline Order(Order&& mov);
public:
    inline Order& operator=(const Order& cpy);
    inline Order& operator=(Order&& mov);
public:
    inline IteratorType Begin();
    inline IteratorType End();
public:
    inline ConstIteratorType Begin() const;
    inline ConstIteratorType End() const;
public:
    inline std::size_t Size() const;
public:
    inline int GetEndian() const;
public:
    inline OperatorType GetOperator() const;
public:
    inline std::uint8_t* Get();
    inline const std::uint8_t* Get() const;
public:
    inline PointerType GetPointer();
    inline const PointerType GetPointer() const;
public:
    inline std::uint8_t& operator[](const std::size_t index);
    inline std::uint8_t operator[](const std::size_t index) const;
public:
    inline bool operator==(const Order& other) const;
    inline bool operator!=(const Order& other) const;
    inline bool operator==(const PointerType& other) const;
    inline bool operator!=(const PointerType& other) const;
    inline bool operator==(const std::uint8_t*& other) const;
    inline bool operator!=(const std::uint8_t*& other) const;
};

inline int Order::GetMachineEndian()
{
    static std::uint16_t _tmp = 0x01;
    static int res = (((std::uint8_t *)&_tmp)[0] == 1 ? 
        little_endian : big_endian);
    return res;
}

inline int Order::GetDefaultEndian()
{
    return big_endian;
}

inline int Order::GetReverseEndian(const int& endian)
{
    if (endian == little_endian)
        return big_endian;
    else if (endian == big_endian)
        return little_endian;
    return endian;
}

inline typename Order::OperatorType 
Order::GetOperatorInstance(const int& endian)
{
    if (endian == little_endian)
        return byte::order::op::LittleEndian{};
    else if (endian == big_endian)
        return byte::order::op::BigEndian{};
    return GetOperatorInstance(GetDefaultEndian());
}

template<std::size_t N>
inline Order::Order(const std::uint8_t (&val)[N]) :
    m_op(GetOperatorInstance(GetDefaultEndian())),
    m_ptr(test::ptr::arg::Array(N))
{
    std::memcpy(m_ptr.GetData(), val, N);
}

inline Order::Order(const std::uint8_t* val, std::size_t size) :
    m_op(GetOperatorInstance(GetDefaultEndian())),
    m_ptr(test::ptr::arg::Array(size))
{
    std::memcpy(m_ptr.GetData(), val, size);
}

template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_base_of<Order, _TArg>::value &&
        !std::is_base_of<test::byte::it::Operator, _TArg>::value &&
        !std::is_array<_TArg>::value &&
        !std::is_pointer<_TArg>::value, int>::type >
inline Order::Order(TArg&& arg, TArgs&&... args) :
    m_op(GetOperatorInstance(GetDefaultEndian())),
    m_ptr(test::ptr::arg::Array(sizeof...(TArgs) + 1), 
        std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

template<std::size_t N>
inline Order::Order(const OperatorType& op, const std::uint8_t (&val)[N]) :
    m_op(op),
    m_ptr(test::ptr::arg::Array(N))
{
    std::memcpy(m_ptr.GetData(), val, N);
}

inline Order::Order(const OperatorType& op, const std::uint8_t* val, 
    std::size_t size) :
        m_op(op),
        m_ptr(test::ptr::arg::Array(size))
{
    std::memcpy(m_ptr.GetData(), val, size);
}

template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_array<_TArg>::value &&
        !std::is_pointer<_TArg>::value, int>::type>
inline Order::Order(const OperatorType& op, TArg&& arg, TArgs&&... args) :
    m_op(op),
    m_ptr(test::ptr::arg::Array(sizeof...(TArgs) + 1), 
        std::forward<TArg>(arg), std::forward<TArgs>(args)...)
{}

inline Order::Order(const Order& cpy) :
    m_op(cpy.m_op),
    m_ptr(cpy.m_ptr)
{}

inline Order::Order(Order&& mov) :
    m_op(mov.m_op),
    m_ptr(mov.m_ptr)
{}

inline Order& Order::operator=(const Order& cpy)
{
    m_op = cpy.m_op;
    m_ptr = cpy.m_ptr;
    return *this;
}

inline Order& Order::operator=(Order&& mov)
{
    m_op = mov.m_op;
    m_ptr = mov.m_ptr;
    return *this;
}

inline typename Order::IteratorType Order::Begin()
{
    const auto size = m_ptr.Size();
    return {m_ptr, 0, size, m_op.Begin(0, size), m_op};
}

inline typename Order::IteratorType Order::End()
{
    const auto size = m_ptr.Size();
    return {m_ptr, 0, size, m_op.End(0, size), m_op};
}

inline typename Order::ConstIteratorType Order::Begin() const
{
    return const_cast<Order*>(this)->Begin();
}

inline typename Order::ConstIteratorType Order::End() const
{
    return const_cast<Order*>(this)->End();
}

inline std::size_t Order::Size() const
{
    return m_ptr.Size();
}

inline int Order::GetEndian() const
{
    if (m_op == GetOperatorInstance(big_endian))
        return big_endian;
    else if (m_op == GetOperatorInstance(little_endian))
        return little_endian;
    return 0;
}

inline typename Order::OperatorType Order::GetOperator() const
{
    return m_op;
}

inline std::uint8_t* Order::Get()
{
    return (std::uint8_t*)m_ptr.GetData();
}

inline const std::uint8_t* Order::Get() const
{
    return (const std::uint8_t*)m_ptr.GetData();
}

inline typename Order::PointerType Order::GetPointer()
{
    return m_ptr;
}

inline const typename Order::PointerType Order::GetPointer() const
{
    return m_ptr;
}

inline std::uint8_t& Order::operator[](const std::size_t index)
{
    PointerType ret{this->m_ptr};
    ret.SetIndex(m_op.Addition(m_op.Begin(0, m_ptr.Size()), index));
    return *ret;
}

inline std::uint8_t Order::operator[](const std::size_t index) const
{
    PointerType ret{this->m_ptr};
    ret.SetIndex(m_op.Addition(m_op.Begin(0, m_ptr.Size()), index));
    return *ret;
}

inline bool Order::operator==(const Order& other) const
{
    return m_ptr == other.m_ptr.GetData() &&
        m_op == other.m_op;
}

inline bool Order::operator!=(const Order& other) const
{
    return m_ptr != other.m_ptr.GetData() ||
        m_op != other.m_op;
}

inline bool Order::operator==(const PointerType& other) const
{
    return m_ptr == other.GetData();
}

inline bool Order::operator!=(const PointerType& other) const
{
    return m_ptr != other.GetData();
}

inline bool Order::operator==(const std::uint8_t*& other) const
{
    return m_ptr.GetData() == other;
}

inline bool Order::operator!=(const std::uint8_t*& other) const
{
    return m_ptr.GetData() != other;
}

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_H_
