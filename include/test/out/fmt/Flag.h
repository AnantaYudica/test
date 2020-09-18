#ifndef TEST_OUT_FMT_FLAG_H_
#define TEST_OUT_FMT_FLAG_H_

#include "flag/Decimal.h"
#include "flag/Define.h"
#include "flag/Exponent.h"
#include "flag/Fixed.h"
#include "flag/Hexadecimal.h"
#include "flag/Length.h"
#include "flag/Lower.h"
#include "flag/Octal.h"
#include "flag/Precision.h"
#include "flag/Prefix.h"
#include "flag/PrefixPlus.h"
#include "flag/PrefixSpace.h"
#include "flag/PrefixZero.h"
#include "flag/Short.h"
#include "flag/Signed.h"
#include "flag/Unsigned.h"
#include "flag/Upper.h"
#include "flag/Width.h"

#include <cstdint>
#include <utility>

namespace test
{
namespace out
{
namespace fmt
{

template<typename TValue = std::uint32_t, 
    typename TIntegerValue = std::uint32_t>
class Flag;

typedef Flag<std::uint32_t, std::uint32_t> FlagType;

template<typename TValue, typename TIntegerValue>
class Flag
{
public:
    typedef TValue ValueType;
    typedef TIntegerValue IntegerValueType;
public:
    template<typename T>
    using DefineType = test::out::fmt::flag::Define<T>;
    typedef test::out::fmt::flag::Width WidthType;
    typedef test::out::fmt::flag::Precision PrecisionType;
    typedef test::out::fmt::flag::Length LengthType;
    typedef test::out::fmt::flag::Signed SignedType;
    typedef test::out::fmt::flag::Unsigned UnsignedType;
    typedef test::out::fmt::flag::Fixed FixedType;
    typedef test::out::fmt::flag::Exponent ExponentType;
    typedef test::out::fmt::flag::Short ShortType;
    typedef test::out::fmt::flag::Decimal DecimalType;
    typedef test::out::fmt::flag::Octal OctalType;
    typedef test::out::fmt::flag::Hexadecimal HexadecimalType;
    typedef test::out::fmt::flag::Lower LowerType;
    typedef test::out::fmt::flag::Upper UpperType;
    typedef test::out::fmt::flag::Prefix PrefixType;
    typedef test::out::fmt::flag::PrefixPlus PrefixPlusType;
    typedef test::out::fmt::flag::PrefixSpace PrefixSpaceType;
    typedef test::out::fmt::flag::PrefixZero PrefixZeroType;
public:
    static constexpr IntegerValueType define_type_offset = 0;
    static constexpr IntegerValueType define_type_mask = 
        0x1 | 0x2 | 0x4 | 0x8;
    static constexpr IntegerValueType define_signed_offset = 4;
    static constexpr IntegerValueType define_signed_mask = 0x10;
    static constexpr IntegerValueType specifier_type_offset = 5;
    static constexpr IntegerValueType specifier_type_mask = 
        0x10 | 0x20 | 0x40;
    static constexpr IntegerValueType specifier_sub_offset = 8;
    static constexpr IntegerValueType specifier_sub_mask = 0x80 | 0x100;
    static constexpr IntegerValueType specifier_int_offset = 10;
    static constexpr IntegerValueType specifier_int_mask = 0x200 | 0x400;
    static constexpr IntegerValueType specifier_fp_offset = 12;
    static constexpr IntegerValueType specifier_fp_mask = 0x400 | 0x800;
    static constexpr IntegerValueType specifier_base_offset = 14;
    static constexpr IntegerValueType specifier_base_mask = 0x1000 | 0x2000;
    static constexpr IntegerValueType specifier_case_offset = 16;
    static constexpr IntegerValueType specifier_case_mask = 0x4000;
    static constexpr IntegerValueType specifier_flag_offset = 17;
    static constexpr IntegerValueType specifier_flag_mask = 0x8000 | 0x10000 |
        0x20000;
public:
    static constexpr IntegerValueType define_mask = define_type_mask | 
        define_signed_mask;
    static constexpr IntegerValueType define_offset = define_type_offset;
    static constexpr IntegerValueType specifier_mask = specifier_type_mask |
        specifier_sub_mask | specifier_int_mask | specifier_fp_mask |
        specifier_base_mask | specifier_case_mask | specifier_flag_mask;
    static constexpr IntegerValueType specifier_offset = define_signed_offset;
    static constexpr IntegerValueType bad_mask = 
        ~(define_mask | specifier_mask);
    static constexpr IntegerValueType bad_offset = 20;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),

        undefined = 0 << define_type_offset,
        define_char = 1 << define_type_offset,
        define_short = 2 << define_type_offset,
        define_int = 3 << define_type_offset,
        define_long = 4 << define_type_offset,
        define_long_long = 5 << define_type_offset,
        define_float = 6 << define_type_offset,
        define_double = 7 << define_type_offset,
        define_long_double = 8 << define_type_offset,
        define_unsigned = 0 << define_signed_offset,
        define_signed = 1 << define_signed_offset,

        specifier_undefined = 0 << specifier_type_offset,
        specifier_ch = 1 << specifier_type_offset,
        specifier_str = 2 << specifier_type_offset,
        specifier_ptr = 3 << specifier_type_offset,
        specifier_int = 4 << specifier_type_offset,
        specifier_fp = 5 << specifier_type_offset,
        specifier_num_ch = 6 << specifier_type_offset,
        specifier_blank = 7 << specifier_type_offset,

        specifier_sub_width = 1 << specifier_sub_offset,
        specifier_sub_precision = 2 << specifier_sub_offset,
        specifier_sub_length = 2 << specifier_sub_offset,

        specifier_int_signed = 1 << specifier_int_offset,
        specifier_int_unsigned = 2 << specifier_int_offset,

        specifier_fp_fixed = 1 << specifier_fp_offset,
        specifier_fp_exponent = 2 << specifier_fp_offset,
        specifier_fp_short = 3 << specifier_fp_offset,

        specifier_base_dec = 0 << specifier_base_offset,
        specifier_base_oct = 1 << specifier_base_offset,
        specifier_base_hex = 2 << specifier_base_offset,

        specifier_lower_case = 0 << specifier_case_offset,
        specifier_upper_case = 1 << specifier_case_offset,

        specifier_flag_undefined = 0 << specifier_flag_offset,
        specifier_flag_prefix = 1 << specifier_flag_offset,
        specifier_flag_prefix_plus = 2 << specifier_flag_offset,
        specifier_flag_prefix_space = 3 << specifier_flag_offset,
        specifier_flag_prefix_zero = 4 << specifier_flag_offset


    };
private:
    static constexpr IntegerValueType _Value(IntegerValueType val);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<signed char>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<char>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<short>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<int>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<long>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<long long>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<unsigned char>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<unsigned short>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<unsigned int>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<unsigned long>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<unsigned long long>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<float>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<double>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<long double>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        WidthType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        PrecisionType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        SignedType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        UnsignedType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        FixedType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        ExponentType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        ShortType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DecimalType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        OctalType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        HexadecimalType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        LowerType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        UpperType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        PrefixType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        PrefixPlusType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        PrefixSpaceType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        PrefixZeroType&&, TArgs&&... args);
private:
    ValueType m_value;
public:
    constexpr Flag();
    template<typename... TArgs>
    constexpr Flag(const IntegerValueType& specifier, TArgs&& ... args);
    ~Flag() = default;
public:
    constexpr Flag(const Flag<TValue, TIntegerValue>& cpy);
    constexpr Flag(Flag<TValue, TIntegerValue>&& mov);
public:
    Flag<TValue, TIntegerValue>& 
        operator=(const Flag<TValue, TIntegerValue>& cpy);
    Flag<TValue, TIntegerValue>& operator=(Flag<TValue, TIntegerValue>&& mov);
public:
    constexpr IntegerValueType GetValue() const;
public:
    constexpr bool IsDefine() const;
    constexpr bool IsDefineSigned() const;
    constexpr bool IsDefineUnsigned() const;
    constexpr IntegerValueType GetDefine() const;
    constexpr IntegerValueType GetDefineSigned() const;
    constexpr IntegerValueType GetDefineType() const;
    void SetDefine(const IntegerValueType& val);
    void SetDefineSigned(const IntegerValueType& val);
    void SetDefineType(const IntegerValueType& val);
public:
    constexpr IntegerValueType GetSpecifier() const;
    void SetSpecifier(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierUndefined() const;
    constexpr bool IsSpecifierCharacter() const;
    constexpr bool IsSpecifierString() const;
    constexpr bool IsSpecifierPointer() const;
    constexpr bool IsSpecifierInteger() const;
    constexpr bool IsSpecifierFloatingPoint() const;
    constexpr bool IsSpecifierNumberCharacter() const;
    constexpr bool IsSpecifierBlank() const;
    constexpr IntegerValueType GetSpecifierType() const;
    void SetSpecifierType(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierFlagUndefined() const;
    constexpr bool IsSpecifierFlagPrefix() const;
    constexpr bool IsSpecifierFlagPrefixPlus() const;
    constexpr bool IsSpecifierFlagPrefixSpace() const;
    constexpr bool IsSpecifierFlagPrefixZero() const;
    constexpr IntegerValueType GetSpecifierFlag() const;
    void SetSpecifierFlag(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierSubWidth() const;
    constexpr bool IsSpecifierSubPrecision() const;
    constexpr bool IsSpecifierSubLength() const;
    constexpr IntegerValueType GetSpecifierSub() const;
    void SetSpecifierSub(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierIntegerSigned() const;
    constexpr bool IsSpecifierIntegerUnsigned() const;
    constexpr IntegerValueType GetSpecifierInteger() const;
    void GetSpecifierInteger(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierFloatingPointFixed() const;
    constexpr bool IsSpecifierFloatingPointExponent() const;
    constexpr bool IsSpecifierFloatingPointShort() const;
    constexpr IntegerValueType GetSpecifierFloatingPoint() const;
    void SetSpecifierFloatingPoint(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierBaseDecimal() const;
    constexpr bool IsSpecifierBaseOctal() const;
    constexpr bool IsSpecifierBaseHexadecimal() const;
    constexpr IntegerValueType GetSpecifierBase() const;
    void SetSpecifierBase(const IntegerValueType& val);
public:
    constexpr bool IsSpecifierLowerCase() const;
    constexpr bool IsSpecifierUpperCase() const;
    constexpr IntegerValueType GetSpecifierCase() const;
    void SetSpecifierCase(const IntegerValueType& val);
public:
    bool IsGood() const;
    bool IsBad() const;
public:
    void SetBad(const IntegerValueType& val);
    IntegerValueType GetBadCode() const;
};

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val)
{
    return val;
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<signed char>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_char | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<char>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_char,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<short>&&,
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_short | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<int>&&,
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_int | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<long>&&,
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<long long>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long_long | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned char>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_char | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned short>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_short | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned int>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_int | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned long>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned long long>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long_long | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<float>&&,
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_float,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<double>&&,
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_double,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<long double>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_long_double,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, WidthType&&,
    TArgs&&... args)
{
    return _Value((val | specifier_sub_width), std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrecisionType&&,
    TArgs&&... args)
{
    return _Value((val | specifier_sub_precision), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, SignedType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_int_mask) | specifier_int_signed, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, UnsignedType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_int_mask) | specifier_int_unsigned, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, FixedType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_fp_mask) | specifier_fp_fixed, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, ExponentType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_fp_mask) | specifier_fp_exponent, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, ShortType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_fp_mask) | specifier_fp_short, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DecimalType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_base_mask) | specifier_base_dec, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, OctalType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_base_mask) | specifier_base_oct, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, HexadecimalType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_base_mask) | specifier_base_hex, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, LowerType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_case_mask) | specifier_lower_case, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, UpperType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_case_mask) | specifier_upper_case, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_flag_mask) | specifier_flag_prefix, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixPlusType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_flag_mask) | specifier_flag_prefix_plus, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixSpaceType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_flag_mask) | specifier_flag_prefix_space, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixZeroType&&,
    TArgs&&... args)
{
    return _Value((val & ~specifier_flag_mask) | specifier_flag_prefix_zero, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
constexpr Flag<TValue, TIntegerValue>::Flag() :
    m_value(IntegerValueType(0))
{}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr Flag<TValue, TIntegerValue>::Flag(const IntegerValueType& specifier,
    TArgs&& ... args) :
        m_value(_Value(specifier & specifier_mask, 
            std::forward<TArgs>(args)...))
{}

template<typename TValue, typename TIntegerValue>
constexpr Flag<TValue, TIntegerValue>::
    Flag(const Flag<TValue, TIntegerValue>& cpy) :
        m_value(cpy.m_value)
{}

template<typename TValue, typename TIntegerValue>
constexpr Flag<TValue, TIntegerValue>::
    Flag(Flag<TValue, TIntegerValue>&& mov) :
        m_value(mov.m_value)
{}

template<typename TValue, typename TIntegerValue>
Flag<TValue, TIntegerValue>& 
Flag<TValue, TIntegerValue>::operator=(const Flag<TValue, TIntegerValue>& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

template<typename TValue, typename TIntegerValue>
Flag<TValue, TIntegerValue>& 
Flag<TValue, TIntegerValue>::operator=(Flag<TValue, TIntegerValue>&& mov)
{
    m_value = mov.m_value;
    return *this;
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetValue() const
{
    return m_value & ~bad_mask;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsDefine() const
{
    return (m_value & define_type_mask) != undefined;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsDefineSigned() const
{
    return ((m_value & define_signed_mask) == define_signed) &&
        IsDefine();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsDefineUnsigned() const
{
    return ((m_value & define_signed_mask) == define_unsigned) &&
        IsDefine();
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetDefine() const
{
    return m_value & define_mask;
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetDefineSigned() const
{
    return m_value & define_signed_mask;
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetDefineType() const
{
    return m_value & define_type_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetDefine(const IntegerValueType& val)
{
    const auto val_type_mask = val & define_type_mask;
    const auto val_signed_mask = val & define_signed_mask;
    IntegerValueType new_type_val = (val_type_mask <= define_long_double) ?
        val_type_mask : undefined;
    m_value = (m_value & ~define_mask) | (new_type_val | val_signed_mask);
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetDefineSigned(const IntegerValueType& val)
{
    m_value = (m_value & ~define_signed_mask) | (val & define_signed_mask);
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetDefineType(const IntegerValueType& val)
{
    const auto val_type_mask = val & define_type_mask;
    IntegerValueType new_type_val = (val_type_mask <= define_long_double) ?
        val_type_mask : undefined;
    m_value = (m_value & ~define_signed_mask) | new_type_val;
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifier() const
{
    return m_value & specifier_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetSpecifier(const IntegerValueType& val)
{
    m_value = (m_value & ~specifier_mask) | (val & specifier_mask);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierUndefined() const
{
    return (m_value & specifier_type_mask) == specifier_undefined;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierCharacter() const
{
    return (m_value & specifier_type_mask) == specifier_ch;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierString() const
{
    return (m_value & specifier_type_mask) == specifier_str;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierPointer() const
{
    return (m_value & specifier_type_mask) == specifier_ptr;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierInteger() const
{
    return (m_value & specifier_type_mask) == specifier_int;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFloatingPoint() const
{
    return (m_value & specifier_type_mask) == specifier_fp;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierNumberCharacter() const
{
    return (m_value & specifier_type_mask) == specifier_num_ch;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierBlank() const
{
    return (m_value & specifier_type_mask) == specifier_blank;
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierType() const
{
    return m_value & specifier_type_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetSpecifierType(const IntegerValueType& val)
{
    m_value = (m_value & ~specifier_type_mask) | (val & specifier_type_mask);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagUndefined() const
{
    return ((m_value & specifier_flag_mask) == specifier_flag_undefined) ||
        IsSpecifierUndefined();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefix() const
{
    return ((m_value & specifier_flag_mask) == specifier_flag_prefix) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefixPlus() const
{
    return ((m_value & specifier_flag_mask) == specifier_flag_prefix_plus) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefixSpace() const
{
    return ((m_value & specifier_flag_mask) == specifier_flag_prefix_space) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefixZero() const
{
    return ((m_value & specifier_flag_mask) == specifier_flag_prefix_zero) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierFlag() const
{
    return m_value & specifier_flag_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetSpecifierFlag(const IntegerValueType& val)
{
    const IntegerValueType val_mask = val & specifier_flag_mask;
    const IntegerValueType new_val = val_mask <= specifier_flag_prefix_zero ? 
        val_mask : specifier_flag_undefined;
    m_value = (m_value & ~specifier_flag_mask) | new_val;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierSubWidth() const
{
    return ((m_value & specifier_sub_mask) == specifier_sub_width) &&
        !IsSpecifierUndefined();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierSubPrecision() const
{
    return ((m_value & specifier_sub_mask) == specifier_sub_precision) &&
        !IsSpecifierUndefined();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierSubLength() const
{
    return ((m_value & specifier_sub_mask) == specifier_sub_length) &&
        !IsSpecifierUndefined();
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierSub() const
{
    return m_value & specifier_sub_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetSpecifierSub(const IntegerValueType& val)
{
    m_value = (m_value & ~specifier_sub_mask) | (val & specifier_sub_mask);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierIntegerSigned() const
{
    return ((m_value & specifier_int_mask) == specifier_int_signed) &&
        IsSpecifierInteger();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierIntegerUnsigned() const
{
    return ((m_value & specifier_int_mask) == specifier_int_unsigned) &&
        IsSpecifierInteger();
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierInteger() const
{
    return m_value & specifier_int_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::
    GetSpecifierInteger(const IntegerValueType& val)
{
    const auto val_mask = val & specifier_int_mask;
    const auto new_val = val_mask <= specifier_int_unsigned ?
        val_mask : (IntegerValueType)0;
    m_value = (m_value & ~specifier_int_mask) | new_val;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::
    IsSpecifierFloatingPointFixed() const
{
    return ((m_value & specifier_fp_mask) == specifier_fp_fixed) &&
        IsSpecifierFloatingPoint();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::
    IsSpecifierFloatingPointExponent() const
{
    return ((m_value & specifier_fp_mask) == specifier_fp_exponent) &&
        IsSpecifierFloatingPoint();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::
    IsSpecifierFloatingPointShort() const
{
    return ((m_value & specifier_fp_mask) == specifier_fp_short) &&
        IsSpecifierFloatingPoint();
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierFloatingPoint() const
{
    return m_value & specifier_fp_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::
    SetSpecifierFloatingPoint(const IntegerValueType& val)
{
    const auto val_mask = val & specifier_fp_mask;
    const auto new_val = val_mask <= specifier_fp_short ?
        val_mask : (IntegerValueType)0;
    m_value = (m_value & ~specifier_fp_mask) | new_val;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierBaseDecimal() const
{
    return ((m_value & specifier_base_mask) == specifier_base_dec) &&
        (IsSpecifierInteger() || IsSpecifierFloatingPoint()); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierBaseOctal() const
{
    return ((m_value & specifier_base_mask) == specifier_base_oct) &&
        (IsSpecifierInteger() || IsSpecifierFloatingPoint()); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierBaseHexadecimal() const
{
    return ((m_value & specifier_base_mask) == specifier_base_hex) &&
        (IsSpecifierInteger() || IsSpecifierFloatingPoint()); 
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierBase() const
{
    return m_value & specifier_base_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetSpecifierBase(const IntegerValueType& val)
{
    const auto val_mask = val & specifier_base_mask;
    const auto new_val = val_mask <= specifier_base_hex ?
        val_mask : specifier_base_dec;
    m_value = (m_value & ~specifier_fp) | new_val;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierLowerCase() const
{
    return ((m_value & specifier_case_mask) == specifier_lower_case) &&
        (IsSpecifierInteger() || IsSpecifierFloatingPoint());
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierUpperCase() const
{
    return ((m_value & specifier_case_mask) == specifier_upper_case) &&
        (IsSpecifierInteger() || IsSpecifierFloatingPoint());
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetSpecifierCase() const
{
    return m_value & specifier_case_mask;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetSpecifierCase(const IntegerValueType& val)
{
    m_value = (m_value & ~specifier_case_mask) | (val & specifier_case_mask);
}

template<typename TValue, typename TIntegerValue>
bool Flag<TValue, TIntegerValue>::IsGood() const
{
    return !(m_value & bad);
}

template<typename TValue, typename TIntegerValue>
bool Flag<TValue, TIntegerValue>::IsBad() const
{
    return m_value & bad;
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetBad(const IntegerValueType& val)
{
    if (IsBad()) return;
    m_value = (m_value & ~bad_mask) | (val & bad_mask);
}

template<typename TValue, typename TIntegerValue>
typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::GetBadCode() const
{
    return m_value & bad_mask;
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_FLAG_H_
