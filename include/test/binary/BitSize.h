#ifndef TEST_BINARY_BITSIZE_H_
#define TEST_BINARY_BITSIZE_H_

#include "../System.h"

#include <cstdlib>
#include <utility>

namespace test
{
namespace binary
{

template<typename T, std::size_t N,  std::size_t I>
class BitSize;

} //!binary

} //!test

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS \
    test::sys::dbg::Type<T>,\
    test::sys::dbg::type::Value<std::size_t, N>,\
    test::sys::dbg::type::Value<std::size_t, I>

template<typename T, std::size_t N,  std::size_t I>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE(
    "test::binary::BitSize", 
    test::binary::BitSize<T, N, I>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace binary
{

template<typename T, std::size_t N = sizeof(T) * 8, 
    std::size_t I = 0>
class BitSize : public BitSize<T, N, I + 1>
{
private:
    static constexpr T _PreMask();
    static constexpr T _Mask();
protected:
    static constexpr std::size_t _Size(const T& val);
public:
    constexpr BitSize(const T& val);
    constexpr BitSize(T&& val);
public:
    BitSize(const T& val, std::size_t n);
    BitSize(const T& val, const std::size_t& n, const std::size_t& index);
protected:
    constexpr BitSize(const T& val, std::size_t (*func)(const T&));
    constexpr BitSize(T&& val, std::size_t (*func)(const T&));
public:
    constexpr BitSize(const BitSize<T, N, N>& cpy);
    constexpr BitSize(BitSize<T, N, N>&& mov);
public:
    constexpr std::size_t Value() const;
};

template<typename T, std::size_t N>
class BitSize<T, N, N>
{
private:
    static constexpr T _PreMask();
    static constexpr T _Mask();
protected:
    static T _PreMaskNIndex(const std::size_t& n, const std::size_t i);
    static T _MaskIndex(const std::size_t i);
protected:
    static constexpr std::size_t _Size(const T& val);
protected:
    static std::size_t _SizeNIndex(const T& val, const std::size_t& n, 
        const std::size_t& i);
private:
    std::size_t m_value;
public:
    constexpr BitSize(const T& val);
    constexpr BitSize(T&& val);
public:
    BitSize(const T& val, std::size_t n);
    BitSize(const T& val, const std::size_t& n, const std::size_t& index);
protected:
    constexpr BitSize(const T& val, std::size_t (*func)(const T&));
    constexpr BitSize(T&& val, std::size_t (*func)(const T&));
public:
    constexpr BitSize(const BitSize<T, N, N>& cpy);
    constexpr BitSize(BitSize<T, N, N>&& mov);
public:
    constexpr std::size_t Value() const;
};

template<typename T, std::size_t N, std::size_t I>
constexpr T BitSize<T, N, I>::_PreMask()
{
    return T(-1) >> ((sizeof(T) * 8) - N) & 
        ~(T(-1) >> ((sizeof(T) * 8) - I));
}

template<typename T, std::size_t N, std::size_t I>
constexpr T BitSize<T, N, I>::_Mask()
{
    return T(1) << I; 
}

template<typename T, std::size_t N, std::size_t I>
constexpr std::size_t BitSize<T, N, I>::_Size(const T& val)
{
    return ((val & _PreMask()) == _Mask() ? (I + 1) : 0) 
        + BitSize<T, N, I + 1>::_Size(val);
}

template<typename T, std::size_t N, std::size_t I>
constexpr BitSize<T, N, I>::BitSize(const T& val) :
    BitSize<T, N, I + 1>(val, &_Size)
{}

template<typename T, std::size_t N, std::size_t I>
constexpr BitSize<T, N, I>::BitSize(T&& val) :
    BitSize<T, N, I + 1>(std::forward<T>(val), &_Size)
{}

template<typename T, std::size_t N, std::size_t I>
BitSize<T, N, I>::BitSize(const T& val, std::size_t n) :
    BitSize<T, N, I + 1>(val, n)
{}

template<typename T, std::size_t N, std::size_t I>
BitSize<T, N, I>::BitSize(const T& val, const std::size_t& n, 
    const std::size_t& index) :
        BitSize<T, N, I + 1>(val, n, index)
{}

template<typename T, std::size_t N, std::size_t I>
constexpr BitSize<T, N, I>::BitSize(const T& val, 
    std::size_t (*func)(const T&)) :
        BitSize<T, N, I + 1>(val, func)
{}

template<typename T, std::size_t N, std::size_t I>
constexpr BitSize<T, N, I>::BitSize(T&& val, std::size_t (*func)(const T&)) :
    BitSize<T, N, I + 1>(std::forward<T>(val), func)
{}

template<typename T, std::size_t N, std::size_t I>
constexpr BitSize<T, N, I>::BitSize(const BitSize<T, N, N>& cpy) :
    BitSize<T, N, I + 1>(cpy)
{}

template<typename T, std::size_t N, std::size_t I>
constexpr BitSize<T, N, I>::BitSize(BitSize<T, N, N>&& mov) :
    BitSize<T, N, I + 1>(std::move(mov))
{}

template<typename T, std::size_t N, std::size_t I>
constexpr std::size_t BitSize<T, N, I>::Value() const
{
    return BitSize<T, N, I + 1>::Value();
}

template<typename T, std::size_t N>
T BitSize<T, N, N>::_PreMaskNIndex(const std::size_t& n, const std::size_t i)
{
    return T(-1) >> ((sizeof(T) * 8) - n) & 
        ~(T(-1) >> ((sizeof(T) * 8) - i));
}

template<typename T, std::size_t N>
T BitSize<T, N, N>::_MaskIndex(const std::size_t i)
{
    return T(1) << i;
}

template<typename T, std::size_t N>
constexpr std::size_t BitSize<T, N, N>::_Size(const T& val)
{
    return 0;
}

template<typename T, std::size_t N>
std::size_t BitSize<T, N, N>::_SizeNIndex(const T& val, const std::size_t& n, 
    const std::size_t& i)
{
    std::size_t result = 0;
    for (std::size_t index = i; index < n; ++index)
    {
        result += ((val & _PreMaskNIndex(n, index)) == 
            _MaskIndex(index) ? (index + 1) : 0);
    }
    return result;
}

template<typename T, std::size_t N>
constexpr BitSize<T, N, N>::BitSize(const T& val) :
    m_value(_Size(val))
{}

template<typename T, std::size_t N>
constexpr BitSize<T, N, N>::BitSize(T&& val) :
    m_value(_Size(val))
{}

template<typename T, std::size_t N>
BitSize<T, N, N>::BitSize(const T& val, std::size_t n) :
    m_value(_SizeNIndex(val, n, 0))
{}

template<typename T, std::size_t N>
BitSize<T, N, N>::BitSize(const T& val, const std::size_t& n, 
    const std::size_t& index) :
        m_value(_SizeNIndex(val, n, index))
{}

template<typename T, std::size_t N>
constexpr BitSize<T, N, N>::BitSize(const T& val, std::size_t (*func)(const T&)) :
        m_value(func(val))
{}

template<typename T, std::size_t N>
constexpr BitSize<T, N, N>::BitSize(T&& val, std::size_t (*func)(const T&)) :
        m_value(func(const_cast<const T&>(val)))
{}

template<typename T, std::size_t N>
constexpr BitSize<T, N, N>::BitSize(const BitSize<T, N, N>& cpy) :
    m_value(cpy.m_value)
{}

template<typename T, std::size_t N>
constexpr BitSize<T, N, N>::BitSize(BitSize<T, N, N>&& mov) :
    m_value(std::move(mov.m_value))
{}

template<typename T, std::size_t N>
constexpr std::size_t BitSize<T, N, N>::Value() const
{
    return m_value;
}

} //!binary

} //!test

#endif //!TEST_BINARY_BITSIZE_H_
