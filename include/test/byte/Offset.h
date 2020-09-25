#ifndef TEST_BYTE_OFFSET_H_
#define TEST_BYTE_OFFSET_H_

#include "../Byte.h"
#include "Order.h"

#include <cstdint>
#include <cstddef>
#include <utility>
#include <new>

namespace test
{
namespace byte
{

template<typename T>
class Offset
{
public:
    typedef test::byte::Iterator<const std::uint8_t*> IteratorType;
private:
    T&& m_value;
    std::size_t m_size;
public:
    Offset(const std::size_t& size, T&& val);
public:
    Offset(const Offset<T>&) = delete;
    Offset(Offset<T>&& mov);
public:
    Offset<T> operator=(const Offset<T>&) = delete;
    Offset<T> operator=(Offset<T>&&) = delete;
public:
    std::size_t Size() const &&;
    IteratorType Begin() const &&;
    IteratorType End() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
};

template<std::size_t N, bool Sign>
class Offset<test::Byte<N, Sign>>
{
public:
    typedef test::byte::Iterator<const std::uint8_t*> IteratorType;
private:
    const test::Byte<N, Sign>&& m_value;
    std::size_t m_size;
public:
    Offset(const std::size_t& size, const test::Byte<N, Sign>& val);
    Offset(const std::size_t& size, test::Byte<N, Sign>&& val);
public:
    Offset(const Offset<test::Byte<N, Sign>>&) = delete;
    Offset(Offset<test::Byte<N, Sign>>&& mov);
public:
    Offset<test::Byte<N, Sign>> 
        operator=(const Offset<test::Byte<N, Sign>>&) = delete;
    Offset<test::Byte<N, Sign>> 
        operator=(Offset<test::Byte<N, Sign>>&&) = delete;
public:
    std::size_t Size() const &&;
    IteratorType Begin() const &&;
    IteratorType End() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
};

template<>
class Offset<test::byte::Order>
{
public:
    typedef test::byte::Iterator<const test::Pointer<std::uint8_t>> 
        IteratorType;
private:
    const test::byte::Order m_value;
    std::size_t m_size;
public:
    Offset(const std::size_t& size, const test::byte::Order& val);
    Offset(const std::size_t& size, test::byte::Order&& val);
public:
    Offset(const Offset<test::byte::Order>&) = delete;
    Offset(Offset<test::byte::Order>&& mov);
public:
    Offset<test::byte::Order>&
        operator=(const Offset<test::byte::Order>&) = delete;
    Offset<test::byte::Order>& 
        operator=(Offset<test::byte::Order>&&) = delete;
public:
    std::size_t Size() const &&;
    IteratorType Begin() const &&;
    IteratorType End() const &&;
public:
    void* operator new (std::size_t) = delete;
    void* operator new[] (std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
};

template<typename T>
Offset<T>::Offset(const std::size_t& size, T&& val) :
    m_value(std::move(val)),
    m_size(size)
{}

template<typename T>
Offset<T>::Offset(Offset<T>&& mov) :
    m_value(std::move(mov.m_value)),
    m_size(mov.m_size)
{}

template<typename T>
std::size_t Offset<T>::Size() const &&
{
    return m_size;
}

template<typename T>
typename Offset<T>::IteratorType Offset<T>::Begin() const &&
{
    const auto op = test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetMachineEndian());
    return {(std::uint8_t*)&const_cast<T&>(m_value), 0, sizeof(T),
        op.Begin(0, sizeof(T)), op};
}

template<typename T>
typename Offset<T>::IteratorType Offset<T>::End() const &&
{
    const auto op = test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetMachineEndian());
    return {(std::uint8_t*)&const_cast<T&>(m_value), 0, sizeof(T),
        op.End(0, sizeof(T)), op};
}

template<std::size_t N, bool Sign>
Offset<test::Byte<N, Sign>>::Offset(const std::size_t& size, 
    const test::Byte<N, Sign>& val) :
        m_value(std::forward<const test::Byte<N, Sign>>(val)),
        m_size(size)
{}

template<std::size_t N, bool Sign>
Offset<test::Byte<N, Sign>>::Offset(const std::size_t& size, 
    test::Byte<N, Sign>&& val) :
        m_value(std::forward<test::Byte<N, Sign>>(val)),
        m_size(size)
{}

template<std::size_t N, bool Sign>
Offset<test::Byte<N, Sign>>::Offset(Offset<test::Byte<N, Sign>>&& mov) :
    m_value(std::move(mov.m_value)),
    m_size(mov.m_size)
{}

template<std::size_t N, bool Sign>
std::size_t Offset<test::Byte<N, Sign>>::Size() const &&
{
    return m_size;
}

template<std::size_t N, bool Sign>
typename Offset<test::Byte<N, Sign>>::IteratorType 
Offset<test::Byte<N, Sign>>::Begin() const &&
{
    const auto op = test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetMachineEndian());
    return {const_cast<std::uint8_t*>(m_value.Get()), 0, N, 
        op.Begin(0, N), op};
}

template<std::size_t N, bool Sign>
typename Offset<test::Byte<N, Sign>>::IteratorType 
Offset<test::Byte<N, Sign>>::End() const &&
{
    const auto op = test::byte::Order::GetOperatorInstance(
        test::byte::Order::GetMachineEndian());
    return {const_cast<std::uint8_t*>(m_value.Get()), 0, N, 
        op.End(0, N), op};
}

Offset<test::byte::Order>::Offset(const std::size_t& size, 
    const test::byte::Order& val) :
        m_value(val),
        m_size(size)
{}

Offset<test::byte::Order>::Offset(const std::size_t& size, 
    test::byte::Order&& val) :
        m_value(std::move(val)),
        m_size(size)
{}

Offset<test::byte::Order>::Offset(Offset<test::byte::Order>&& mov) :
    m_value(std::move(mov.m_value)),
    m_size(mov.m_size)
{}

std::size_t Offset<test::byte::Order>::Size() const &&
{
    return m_size;
}

typename Offset<test::byte::Order>::IteratorType 
Offset<test::byte::Order>::Begin() const &&
{
    return m_value.Begin();
}

typename Offset<test::byte::Order>::IteratorType 
Offset<test::byte::Order>::End() const &&
{
    return m_value.End();
}

} //!byte

} //!test

#endif //!TEST_BYTE_OFFSET_H_
