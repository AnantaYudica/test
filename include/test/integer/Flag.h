#ifndef TEST_INTEGER_FLAG_H_
#define TEST_INTEGER_FLAG_H_

#include "../System.h"

#include <cstdint>

namespace test::integer
{

class Flag;

}

#ifndef TEST_INTEGER_FLAG_DLEVEL

#define TEST_INTEGER_FLAG_DLEVEL 2

#endif //!TEST_INTEGER_FLAG_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_INTEGER_FLAG_DLEVEL, 
    "test::integer::Flag", test::integer::Flag);

namespace test
{
namespace integer
{

class Flag
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::integer::Flag> DebugType;
public:
    typedef std::uint8_t ValueType;
    typedef std::uint16_t OperatorValueType;
    typedef std::uint8_t ErrorValueType;
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
    enum : ErrorValueType
    {
        kOk = 0,
        kOverflow = 1,
        kDivByZero = 2,
        kDivError = 4
    };
private:
    static constexpr ValueType ms_signValueMask = kNegative |
        kSigned;
    static constexpr ValueType ms_formatValueMask = 
        kBinaryFormat | kOctalFormat | kDecimalFormat;
    static constexpr ValueType ms_initValueMask = kSigned | 
        ms_formatValueMask;
private:
    ValueType m_val;
    ErrorValueType m_errVal;
public:
    inline constexpr Flag();
    inline constexpr Flag(const ValueType& val);
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
    inline constexpr bool IsSigned() const;
public:
    inline constexpr bool IsUndefinedFormat() const;
    inline constexpr bool IsBinaryFormat() const;
    inline constexpr bool IsOctalFormat() const;
    inline constexpr bool IsDecimalFormat() const;
    inline constexpr ValueType Format() const;
public:
    inline void Error(const ErrorValueType& err);
    inline ErrorValueType Error() const;
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

constexpr Flag::Flag() :
    m_val(0),
    m_errVal(0)
{}

constexpr Flag::Flag(const ValueType& val) :
    m_val(val & ms_initValueMask),
    m_errVal(0)
{}

inline Flag::Flag(const Flag& cpy) :
    m_val(cpy.m_val),
    m_errVal(cpy.m_errVal)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
}

inline Flag::Flag(Flag&& mov) :
    m_val(mov.m_val),
    m_errVal(mov.m_errVal)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

inline Flag& Flag::operator=(const Flag& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    if (this->Format() == cpy.Format() && m_val & kSigned)
    {
        m_val = cpy.m_val; 
        m_errVal = cpy.m_errVal;
    }
    return *this;
}

inline Flag& Flag::operator=(Flag&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);

    if (this->Format() == mov.Format() && m_val & kSigned)
    {
        m_val = mov.m_val; 
        m_errVal = mov.m_errVal;
    }
    return *this;
}

inline bool Flag::IsSet(const ValueType& keys) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "IsSet(keys=%s) const", TEST_SYS_DEBUG_VALUE_STR(0, keys));
    
    return m_val & keys;
}

inline bool Flag::IsNegative() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsNegative() const");
    
    return (m_val & ms_signValueMask) == 
        ms_signValueMask;
}

inline void Flag::SetNegative()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "SetNegative()");

    if (IsSigned()) m_val |= kNegative;
}

inline void Flag::UnsetNegative()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "UnsetNegative()");

    if (IsSigned()) m_val &= ~kNegative;
}

inline constexpr bool Flag::IsSigned() const
{
    return m_val & kSigned;
}

inline constexpr bool Flag::IsUndefinedFormat() const
{
    return Format() == 0;
}

inline constexpr bool Flag::IsBinaryFormat() const
{
    return Format() == kBinaryFormat;
}

inline constexpr bool Flag::IsOctalFormat() const
{
    return Format() == kOctalFormat;
}

inline constexpr bool Flag::IsDecimalFormat() const
{
    return Format() == kDecimalFormat;
}

inline constexpr typename Flag::ValueType Flag::Format() const
{
    return m_val & ms_formatValueMask;
}

inline void Flag::Error(const ErrorValueType& err)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Error(err=%s)", TEST_SYS_DEBUG_VALUE_STR(0, err));
    
    m_errVal |= err;
}

inline typename Flag::ErrorValueType Flag::Error() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Error() const");
    
    return m_errVal;
}

inline typename Flag::OperatorValueType 
Flag::operator+=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator+=(flag=%p)", &flag);
    
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (this->IsNegative() == flag.IsNegative())
        return cnv | kAdditionOp;
    return cnv | kSubtractionOp;
}

inline typename Flag::OperatorValueType 
Flag::operator-=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-=(flag=%p)", &flag);
    
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (this->IsNegative() == flag.IsNegative()) 
        return cnv | kSubtractionOp;
    return cnv | kAdditionOp;
}

inline typename Flag::OperatorValueType 
Flag::operator*=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator*=(flag=%p)", &flag);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator/=(flag=%p)", &flag);
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator%=(flag=%p)", &flag);
    
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    return cnv | kModuloOp;
}

inline typename Flag::OperatorValueType 
Flag::operator|=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator|=(flag=%p)", &flag);
    
    if (!this->IsBinaryFormat()) return 0;
    const OperatorValueType cnv = flag.Format() != kBinaryFormat ?
        kConversionOp : 0;
    return cnv | kOrOp;
}

inline typename Flag::OperatorValueType 
Flag::operator&=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator&=(flag=%p)", &flag);
    
    if (!this->IsBinaryFormat()) return 0;
    const OperatorValueType cnv = flag.Format() != kBinaryFormat ?
        kConversionOp : 0;
    return cnv | kAndOp;
}

inline typename Flag::OperatorValueType 
Flag::operator^=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator^=(flag=%p)", &flag);
    
    if (!this->IsBinaryFormat()) return 0;
    const OperatorValueType cnv = flag.Format() != kBinaryFormat ?
        kConversionOp : 0;
    return cnv | kXorOp;
}

inline typename Flag::OperatorValueType 
Flag::operator>>=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>=(flag=%p)", &flag);
    
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    if (this->IsNegative() && this->IsBinaryFormat())
        return cnv | kRShiftOp | kIncrementOp;
    return cnv | kRShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator<<=(const Flag& flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<=(flag=%p)", &flag);
    
    const OperatorValueType cnv = this->Format() != flag.Format() ?
        kConversionOp : 0;
    return cnv | kLShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator>>=(std::intmax_t)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator>>=(std::intmax_t)");
    
    if (!this->IsBinaryFormat()) return kRShiftOp;
    if (this->IsNegative())
        return kRShiftOp | kIncrementOp;
    return kRShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator<<=(std::intmax_t)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator<<=(std::intmax_t)");
    
    return kLShiftOp;
}

inline typename Flag::OperatorValueType 
Flag::operator~() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator~() const");
    
    if (!this->IsBinaryFormat()) return 0;
    return kNotOp;
}

inline Flag Flag::operator-() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator-() const");
    
    Flag ret(*this);
    if (ret.IsNegative())
        ret.UnsetNegative();
    else
        ret.SetNegative();
    return ret;
}

inline Flag::operator ValueType() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "operator %s() const", TEST_SYS_DEBUG_T_NAME_STR(ValueType));
    
    return m_val;
}

} //!integer

} //!test

#endif //!TEST_INTEGER_FLAG_H_
