#ifndef TEST_INTEGER_FLAG_H_
#define TEST_INTEGER_FLAG_H_

#include <cstdint>

namespace test
{
namespace integer
{

class Flag
{
public:
    typedef std::uint8_t ValueType;
    typedef std::uint16_t OperatorValueType;
    enum : ValueType
    {
        kNegative = 1,
        kSigned = 2,
        kBinaryFormat = 4,
        kOctalFormat = 12,
        kDecimalFormat = 28
    };
    enum : OperatorValueType
    {
        kAdditionOp = 1,
        kSubtractionOp = 2,
        kMultiplicationOp = 4, 
        kDivisionOp = 8,
        kModuloOp = 16,
        kOrOp = 32,
        kAndOp = 64,
        kXorOp = 128,
        kNotOp = 256,
        kRShiftOp = 512,
        kLShiftOp = 1024,
        kNegationOp = 2048,
        kIncrementOp = 4096,
        kConversionOp = 8192
    };
private:
    static constexpr ValueType ms_signValueMask = kNegative |
        kSigned;
    static constexpr ValueType ms_formatValueMask = 
        kBinaryFormat | kOctalFormat | kDecimalFormat;
    static constexpr ValueType ms_initValueMask = kNegative | kSigned | 
        ms_formatValueMask;
private:
    ValueType m_val;
public:
    inline Flag();
    inline Flag(const ValueType& val);
    ~Flag() = default;
public:
    inline Flag(const Flag& cpy);
    inline Flag(Flag&& mov);
public:
    inline Flag& operator=(const Flag& cpy); 
    inline Flag& operator=(Flag&& mov);
public:
    inline bool IsSet(const ValueType& keys) const;
public:
    inline bool IsNegative() const;
    inline void SetNegative();
    inline void UnsetNegative();
public:
    inline bool IsSigned() const;
public:
    inline bool IsUndefinedFormat() const;
    inline bool IsBinaryFormat() const;
    inline bool IsOctalFormat() const;
    inline bool IsDecimalFormat() const;
    inline ValueType Format() const;
public:
    inline OperatorValueType operator+=(const Flag& flag);
    inline OperatorValueType operator-=(const Flag& flag);
    inline OperatorValueType operator*=(const Flag& flag);
    inline OperatorValueType operator/=(const Flag& flag);
    inline OperatorValueType operator%=(const Flag& flag);
    inline OperatorValueType operator|=(const Flag& flag);
    inline OperatorValueType operator&=(const Flag& flag);
    inline OperatorValueType operator^=(const Flag& flag);
    inline OperatorValueType operator>>=(const Flag& flag);
    inline OperatorValueType operator<<=(const Flag& flag);
    inline OperatorValueType operator>>=(std::intmax_t);
    inline OperatorValueType operator<<=(std::intmax_t);
    inline OperatorValueType operator~() const;
public:
    inline Flag operator-() const;
public:
    inline operator ValueType() const;
};

inline Flag::Flag() :
    m_val(0)
{}

inline Flag::Flag(const ValueType& val) :
    m_val(val & ms_initValueMask)
{}

inline Flag::Flag(const Flag& cpy) :
    m_val(cpy.m_val & ms_initValueMask)
{}

inline Flag::Flag(Flag&& mov) :
    m_val(mov.m_val & ms_initValueMask)
{
    mov.m_val = 0;
}

inline Flag& Flag::operator=(const Flag& cpy)
{
    if (this->Format() == cpy.Format() && m_val & kSigned)
        m_val = cpy.m_val; 
    return *this;
}

inline Flag& Flag::operator=(Flag&& mov)
{
    if (this->Format() == mov.Format() && m_val & kSigned)
        m_val = mov.m_val; 
    return *this;
}

inline bool Flag::IsSet(const ValueType& keys) const
{
    return m_val & keys;
}

inline bool Flag::IsNegative() const
{
    return (m_val & ms_signValueMask) == 
        ms_signValueMask;
}

inline void Flag::SetNegative()
{
    if (IsSigned()) m_val |= kNegative;
}

inline void Flag::UnsetNegative()
{
    if (IsSigned()) m_val &= ~kNegative;
}

inline bool Flag::IsSigned() const
{
    return m_val & kSigned;
}

inline bool Flag::IsUndefinedFormat() const
{
    const auto fmt = Format();
    return fmt == 0;
}

inline bool Flag::IsBinaryFormat() const
{
    return Format() == kBinaryFormat;
}

inline bool Flag::IsOctalFormat() const
{
    return Format() == kOctalFormat;
}

inline bool Flag::IsDecimalFormat() const
{
    return Format() == kDecimalFormat;
}

inline typename Flag::ValueType Flag::Format() const
{
    return m_val & ms_formatValueMask;
}

inline typename Flag::OperatorValueType 
Flag::operator+=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (this->IsNegative() == flag.IsNegative())
        return cnv | kAdditionOp;
    return cnv | kSubtractionOp;
}

inline typename Flag::OperatorValueType 
Flag::operator-=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (this->IsNegative() == flag.IsNegative()) 
        return cnv | kSubtractionOp;
    return cnv | kAdditionOp;
}

inline typename Flag::OperatorValueType 
Flag::operator*=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (!this->IsSigned())
    {
        if (flag.IsNegative())
            return cnv | kMultiplicationOp | kNegationOp;
        return cnv | kMultiplicationOp;
    }
    if (this->IsNegative() && flag.IsNegative())
        this->UnsetNegative();
    else if (flag.IsNegative())
        this->SetNegative();
    return cnv | kMultiplicationOp;
}

inline typename Flag::OperatorValueType 
Flag::operator/=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (!this->IsSigned())
    {
        if (flag.IsNegative())
            return cnv | kDivisionOp | kNegationOp;
        return cnv | kDivisionOp;
    }
    if (this->IsNegative() && flag.IsNegative())
        this->UnsetNegative();
    else if (flag.IsNegative())
        this->SetNegative();
    return cnv | kDivisionOp;
}

inline typename Flag::OperatorValueType 
Flag::operator%=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    return cnv | kModuloOp;
}

inline typename Flag::OperatorValueType 
Flag::operator|=(const Flag& flag)
{
    if (!this->IsBinaryFormat()) return 0;
    const OperatorValueType cnv = flag.Format() != kBinaryFormat ?
        kConversionOp : 0;
    return cnv | kOrOp;
}

inline typename Flag::OperatorValueType 
Flag::operator&=(const Flag& flag)
{
    if (!this->IsBinaryFormat()) return 0;
    const OperatorValueType cnv = flag.Format() != kBinaryFormat ?
        kConversionOp : 0;
    return cnv | kAndOp;
}

inline typename Flag::OperatorValueType 
Flag::operator^=(const Flag& flag)
{
    if (!this->IsBinaryFormat()) return 0;
    const OperatorValueType cnv = flag.Format() != kBinaryFormat ?
        kConversionOp : 0;
    return cnv | kXorOp;
}

inline typename Flag::OperatorValueType 
Flag::operator>>=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (this->IsNegative() && this->IsBinaryFormat())
        return cnv | kRShiftOp | kIncrementOp;
    return cnv | kRShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator<<=(const Flag& flag)
{
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    return cnv | kLShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator>>=(std::intmax_t)
{
    if (!this->IsBinaryFormat()) return kRShiftOp;
    if (this->IsNegative())
        return kRShiftOp | kIncrementOp;
    return kRShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator<<=(std::intmax_t)
{
    return kLShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator~() const
{
    if (!this->IsBinaryFormat()) return 0;
    return kNotOp;
}

inline Flag Flag::operator-() const
{
    Flag ret(*this);
    if (ret.IsNegative())
        ret.UnsetNegative();
    else
        ret.SetNegative();
    return ret;
}

inline Flag::operator ValueType() const
{
    return m_val;
}

} //!integer

} //!test

#endif //!TEST_INTEGER_FLAG_H_
