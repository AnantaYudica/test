#ifndef TEST_FLOATINGPOINT_H_
#define TEST_FLOATINGPOINT_H_

#include "Byte.h"
#include "fp/fmt/Definition.h"

#include <cstddef>
#include <cmath>
#include <cfloat>

namespace test
{

template<typename TFloat, 
    typename TFormat = typename test::fp::fmt::Definition<TFloat>::Type>
class FloatingPoint
{
public:
    typedef TFormat FormatType;
    typedef typename FormatType::FloatByteType ByteType;
    typedef typename FormatType::SignValueType SignType;
    typedef typename FormatType::ExponentValueType ExponentType;
    typedef typename FormatType::MantissaValueType MantissaType;
    typedef typename FormatType::SignedIntegerType SignedIntegerType;
    typedef typename FormatType::UnsignedIntegerType UnsignedIntegerType;
public:
    static constexpr int format_size = FormatType::size;
private:
    static ByteType _SetSign(const ByteType& byte, const SignType& sign_val);
private:
    static ByteType _SetExponent(const ByteType& byte, 
        const ExponentType& exp_val);
private:
    static ByteType _SetMantissa(const ByteType& byte,
        const MantissaType& mant_val);
private:
    static SignType _GetSign(const ByteType& byte);
private:
    static ExponentType _GetExponent(const ByteType& byte);
private:
    static MantissaType _GetNormalMantissa(const ByteType& byte);
    static MantissaType _GetSubNormalMantissa(const ByteType& byte);
private:
    static ByteType _GetValue(const SignedIntegerType& val);
    static ByteType _GetValue(const UnsignedIntegerType& val);
public:
    static ExponentType GetBiasExponent();
    static ExponentType GetMinimumExponent();
    static ExponentType GetMaximumExponent();
public:
    static MantissaType GetMinimumNormalMantissa();
    static MantissaType GetMaximumNormalMantissa();
    static MantissaType GetMinimumSubNormalMantissa();
    static MantissaType GetMaximumSubNormalMantissa();
public:
    static constexpr int GetBitFieldSign();
    static constexpr int GetBitFieldExponent();
    static constexpr int GetBitFieldMantissa();
private:
    TFloat m_value;
public:
    FloatingPoint();
    FloatingPoint(const TFloat& val);
    FloatingPoint(const SignedIntegerType& val);
    FloatingPoint(const UnsignedIntegerType& val);
public:
    ~FloatingPoint();
public:
    FloatingPoint(const FloatingPoint<TFloat, TFormat>& cpy);
    FloatingPoint(FloatingPoint<TFloat, TFormat>&& mov);
public:
    FloatingPoint<TFloat, TFormat>& operator=(const TFloat& val);
    FloatingPoint<TFloat, TFormat>& operator=(const SignedIntegerType& val);
    FloatingPoint<TFloat, TFormat>& operator=(const UnsignedIntegerType& val);
    FloatingPoint<TFloat, TFormat>& 
        operator=(const FloatingPoint<TFloat, TFormat>& cpy);
    FloatingPoint<TFloat, TFormat>&
        operator=(FloatingPoint<TFloat, TFormat>&& mov);
public:
    void SetSign(const SignType& sign);
    void SetExponent(const ExponentType& exp);
    void SetMantissa(const MantissaType& mant);
public:
    bool IsSign() const;
    ExponentType GetExponent() const;
    MantissaType GetNormalMantissa() const;
    MantissaType GetSubNormalMantissa() const;
    TFloat GetFloat() const;
};

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ByteType 
FloatingPoint<TFloat, TFormat>::_SetSign(const ByteType& byte, 
    const SignType& sign_val)
{
    const auto _sign_index = FormatType::sign_index;
    ByteType res{byte};
    if ((bool)sign_val)
        res |= test::byte::off::Make(_sign_index, FormatType::SignMaskByte());
    else
        res &= test::byte::off::Make(_sign_index, ~FormatType::SignMaskByte());
    return res;
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ByteType 
FloatingPoint<TFloat, TFormat>::_SetExponent(const ByteType& byte, 
    const ExponentType& exp_val)
{
    const auto _exponent_index = FormatType::exponent_index;
    const auto _exponent_bitoff = FormatType::exponent_bitoff;
    ByteType res{byte};
    auto exp = FormatType::ExponentBias().template CastTo<ExponentType>();
    exp += exp_val;
    exp &= FormatType::ExponentMask().template CastTo<ExponentType>();
    ByteType exp_byte{exp};
    exp_byte <<= _exponent_bitoff;
    res &= test::byte::off::Make(_exponent_index, 
        ~FormatType::ExponentMaskByte());
    res |= test::byte::off::Make(_exponent_index, exp_byte);
    return res;
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ByteType 
FloatingPoint<TFloat, TFormat>::_SetMantissa(const ByteType& byte,
    const MantissaType& mant_val)
{
    typedef typename FormatType::MantissaByteType MantissaByteType;
    const auto _mantissa_index = FormatType::mantissa_index;
    ByteType res{byte};
    MantissaByteType mant_byte = mant_val & FormatType::MantissaMaskByte();
    res &= test::byte::off::Make(_mantissa_index,
        ~FormatType::MantissaMaskByte());
    res |= mant_byte;
    return res;
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::SignType 
FloatingPoint<TFloat, TFormat>::_GetSign(const ByteType& byte)
{
    const auto _sign_index = FormatType::sign_index;
    auto sign_byte = 
        byte.template GetBlock<FormatType::sign_size>(_sign_index);
    return (sign_byte & FormatType::SignMaskByte()) == 
        FormatType::SignMaskByte();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ExponentType 
FloatingPoint<TFloat, TFormat>::_GetExponent(const ByteType& byte)
{
    typedef typename FormatType::ExponentByteType ExponentByteType;
    typedef typename FormatType::ExponentExpandValueType 
        ExponentExpandValueType;
    const auto _exponent_index = FormatType::exponent_index;
    const auto _exponent_bitoff = FormatType::exponent_bitoff;
    ExponentByteType exp_byte{byte.template 
        GetBlock<FormatType::exponent_size>(_exponent_index)};
    exp_byte >>= _exponent_bitoff;
    exp_byte &= FormatType::ExponentMask();
    auto exp_val = exp_byte.template CastTo<ExponentExpandValueType>();
    if (exp_val == 0) 
        return FormatType::ExponentMinimumValue().template 
            CastTo<ExponentExpandValueType>();
    exp_val -= FormatType::ExponentBias().template 
        CastTo<ExponentExpandValueType>();
    return (ExponentType)exp_val;
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::_GetNormalMantissa(const ByteType& byte)
{
    return _GetSubNormalMantissa(byte) | 
        FormatType::MantissaNormalMinimumValue();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::_GetSubNormalMantissa(const ByteType& byte)
{
    typedef typename FormatType::MantissaByteType MantissaByteType;
    const auto _mantissa_index = FormatType::mantissa_index;
    const auto _mantissa_size = FormatType::mantissa_size;
    MantissaByteType mant_byte = byte.template
        GetBlock<FormatType::mantissa_size>(_mantissa_index);
    mant_byte &= FormatType::MantissaSubNormalMaximumValue();
    return mant_byte;
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ByteType 
FloatingPoint<TFloat, TFormat>::_GetValue(const SignedIntegerType& val)
{
    auto byte = _GetValue(UnsignedIntegerType(std::abs(val)));
    if (val < 0)
        return _SetSign(byte, true);
    else
        return _SetSign(byte, false);
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ByteType 
FloatingPoint<TFloat, TFormat>::_GetValue(const UnsignedIntegerType& val)
{
    const auto _mantissa_bitfield = FormatType::mantissa_bitfield;
    ByteType byte;
    ExponentType exp = 1;
    auto id_val = std::log2(val);
    int len = std::floor(id_val);
    int inv_len = _mantissa_bitfield - len;

    if (inv_len >= 0)
    {
        byte = _SetMantissa(byte, val << inv_len);
        byte = _SetExponent(byte, len);
    }
    else
    {
        byte = _SetMantissa(byte, val >> (std::abs(inv_len) - 1));
        byte = _SetExponent(byte, std::abs(len));
    }
    return byte;
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ExponentType 
FloatingPoint<TFloat, TFormat>::GetBiasExponent()
{
    return FormatType::ExponentBias().template CastTo<ExponentType>();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ExponentType 
FloatingPoint<TFloat, TFormat>::GetMinimumExponent()
{
    return FormatType::ExponentMinimumValue().template CastTo<ExponentType>();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ExponentType 
FloatingPoint<TFloat, TFormat>::GetMaximumExponent()
{
    return FormatType::ExponentMaximumValue().template CastTo<ExponentType>();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::GetMinimumNormalMantissa()
{
    return FormatType::MantissaNormalMinimumValue();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::GetMaximumNormalMantissa()
{
    return FormatType::MantissaNormalMaximumValue();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::GetMinimumSubNormalMantissa()
{
    return FormatType::MantissaSubNormalMinimumValue();
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::GetMaximumSubNormalMantissa()
{
    return FormatType::MantissaSubNormalMaximumValue();
}

template<typename TFloat, typename TFormat>
constexpr int FloatingPoint<TFloat, TFormat>::GetBitFieldSign()
{
    return FormatType::sign_bitfield;
}

template<typename TFloat, typename TFormat>
constexpr int FloatingPoint<TFloat, TFormat>::GetBitFieldExponent()
{
    return FormatType::exponent_bitfield;
}

template<typename TFloat, typename TFormat>
constexpr int FloatingPoint<TFloat, TFormat>::GetBitFieldMantissa()
{
    return FormatType::mantissa_bitfield;
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::FloatingPoint() :
    m_value{FormatType::Zero().template CastTo<TFloat>()}
{}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::FloatingPoint(const TFloat& val) :
    m_value(val)
{}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::FloatingPoint(const SignedIntegerType& val) :
    m_value(_GetValue(val).template CastTo<TFloat>())
{}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::FloatingPoint(const UnsignedIntegerType& val) :
    m_value(_GetValue(val).template CastTo<TFloat>())
{}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::~FloatingPoint()
{
    m_value = FormatType::Zero().template CastTo<TFloat>();
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::
    FloatingPoint(const FloatingPoint<TFloat, TFormat>& cpy) :
        m_value(cpy.m_value)
{}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>::
    FloatingPoint(FloatingPoint<TFloat, TFormat>&& mov) :
        m_value(mov.m_value)
{
    m_value = FormatType::Zero().template CastTo<TFloat>();
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>& FloatingPoint<TFloat, TFormat>::
    operator=(const TFloat& val)
{
    m_value = val;
    return *this;
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>& FloatingPoint<TFloat, TFormat>::
    operator=(const SignedIntegerType& val)
{
    m_value = _GetValue(val).template CastTo<TFloat>();
    return *this;
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>& FloatingPoint<TFloat, TFormat>::
    operator=(const UnsignedIntegerType& val)
{
    m_value = _GetValue(val).template CastTo<TFloat>();
    return *this;
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>& FloatingPoint<TFloat, TFormat>::
    operator=(const FloatingPoint<TFloat, TFormat>& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

template<typename TFloat, typename TFormat>
FloatingPoint<TFloat, TFormat>& FloatingPoint<TFloat, TFormat>::
    operator=(FloatingPoint<TFloat, TFormat>&& mov)
{
    m_value = mov.m_value;
    mov.m_value = FormatType::Zero().template CastTo<TFloat>();
    return *this;
}

template<typename TFloat, typename TFormat>
void FloatingPoint<TFloat, TFormat>::SetSign(const SignType& sign)
{
    const ByteType byte = m_value;
    m_value = _SetSign(byte, sign).template CastTo<TFloat>();
}

template<typename TFloat, typename TFormat>
void FloatingPoint<TFloat, TFormat>::SetExponent(const ExponentType& exp)
{
    const ByteType byte = m_value;
    m_value = _SetExponent(byte, exp).template CastTo<TFloat>();
}

template<typename TFloat, typename TFormat>
void FloatingPoint<TFloat, TFormat>::SetMantissa(const MantissaType& mant)
{
    const ByteType byte = m_value;
    m_value = _SetMantissa(byte, mant).template CastTo<TFloat>();
}

template<typename TFloat, typename TFormat>
bool FloatingPoint<TFloat, TFormat>::IsSign() const
{
    const ByteType byte = m_value;
    return _GetSign(byte);
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::ExponentType 
FloatingPoint<TFloat, TFormat>::GetExponent() const
{
    const ByteType byte = m_value;
    return _GetExponent(byte);
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::GetNormalMantissa() const
{
    const ByteType byte = m_value;
    return _GetNormalMantissa(byte);
}

template<typename TFloat, typename TFormat>
typename FloatingPoint<TFloat, TFormat>::MantissaType 
FloatingPoint<TFloat, TFormat>::GetSubNormalMantissa() const
{
    const ByteType byte = m_value;
    return _GetSubNormalMantissa(byte);
}

template<typename TFloat, typename TFormat>
TFloat FloatingPoint<TFloat, TFormat>::GetFloat() const
{
    return m_value;
}

} //!test

#endif //!TEST_FLOATINGPOINT_H_
