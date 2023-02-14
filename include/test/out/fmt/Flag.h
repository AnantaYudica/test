#ifndef TEST_OUT_FMT_FLAG_H_
#define TEST_OUT_FMT_FLAG_H_

#include "../../System.h"
#include "Flag.decl.h"
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
#include "flag/Value.h"
#include "flag/Output.h"

#include <cstdint>
#include <utility>
#include <cwchar>

#ifndef TEST_OUT_FMT_FLAG_DLEVEL

#define TEST_OUT_FMT_FLAG_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TValue>,\
    test::sys::dbg::Type<TIntegerValue>

template<typename TValue, typename TIntegerValue>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_FLAG_DLEVEL, 
    "test::out::fmt::Flag", 
    test::out::fmt::Flag<TValue, TIntegerValue>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace out
{
namespace fmt
{

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
    template<typename T>
    using SetValueType = test::out::fmt::flag::Value<T>;
    template<typename... TCharArgs>
    using SetOutputType = test::out::fmt::flag::Output<TCharArgs...>;
public:
    static constexpr IntegerValueType define_type_offset = 0;
    static constexpr IntegerValueType define_type_mask = 
        0x1 | 0x2 | 0x4 | 0x8;
    static constexpr IntegerValueType define_signed_offset = 4;
    static constexpr IntegerValueType define_signed_mask = 0x10 | 0x20;
    static constexpr IntegerValueType specifier_type_offset = 6;
    static constexpr IntegerValueType specifier_type_mask = 
        0x40 | 0x80 | 0x100 | 0x200;
    static constexpr IntegerValueType specifier_sub_offset = 10;
    static constexpr IntegerValueType specifier_sub_mask = 0x400 | 0x800;
    static constexpr IntegerValueType specifier_int_offset = 12;
    static constexpr IntegerValueType specifier_int_mask = 0x1000 | 0x2000;
    static constexpr IntegerValueType specifier_fp_offset = 14;
    static constexpr IntegerValueType specifier_fp_mask = 0x4000 | 0x8000;
    static constexpr IntegerValueType specifier_base_offset = 16;
    static constexpr IntegerValueType specifier_base_mask = 0x10000 | 0x20000;
    static constexpr IntegerValueType specifier_case_offset = 18;
    static constexpr IntegerValueType specifier_case_mask = 0x40000;
    static constexpr IntegerValueType specifier_flag_offset = 19;
    static constexpr IntegerValueType specifier_flag_mask = 0x80000 | 0x100000 |
        0x200000 | 0x400000;
    static constexpr IntegerValueType input_offset= 23;
    static constexpr IntegerValueType input_mask = 0x800000 | 0x1000000 |
        0x2000000;
    static constexpr IntegerValueType output_offset= 26;
    static constexpr IntegerValueType output_mask = 0x4000000 | 0x8000000;
public:
    static constexpr IntegerValueType define_mask = define_type_mask | 
        define_signed_mask;
    static constexpr IntegerValueType define_offset = define_type_offset;
    static constexpr IntegerValueType specifier_mask = specifier_type_mask |
        specifier_sub_mask | specifier_int_mask | specifier_fp_mask |
        specifier_base_mask | specifier_case_mask | specifier_flag_mask;
    static constexpr IntegerValueType specifier_offset = define_signed_offset;
    static constexpr IntegerValueType bad_mask = 
        ~(define_mask | specifier_mask | input_mask | output_mask);
    static constexpr IntegerValueType bad_offset = 28;
public:
    static constexpr IntegerValueType good = 0;
    static constexpr IntegerValueType bad = 
        IntegerValueType(~((IntegerValueType)-1 >> 1));

    static constexpr IntegerValueType undefined = 0 << define_type_offset;
    static constexpr IntegerValueType define_wchar = 1 << define_type_offset;
    static constexpr IntegerValueType define_char = 2 << define_type_offset;
    static constexpr IntegerValueType define_short = 3 << define_type_offset;
    static constexpr IntegerValueType define_int = 4 << define_type_offset;
    static constexpr IntegerValueType define_long = 5 << define_type_offset;
    static constexpr IntegerValueType define_long_long = 
        6 << define_type_offset;
    static constexpr IntegerValueType define_float = 7 << define_type_offset;
    static constexpr IntegerValueType define_double = 8 << define_type_offset;
    static constexpr IntegerValueType define_long_double = 
        9 << define_type_offset;
    static constexpr IntegerValueType define_bool = 
        10 << define_type_offset;
    static constexpr IntegerValueType define_unsigned = 
        1 << define_signed_offset;
    static constexpr IntegerValueType define_signed = 
        2 << define_signed_offset;

    static constexpr IntegerValueType specifier_undefined = 
        0 << specifier_type_offset;
    static constexpr IntegerValueType specifier_ch = 
        1 << specifier_type_offset;
    static constexpr IntegerValueType specifier_str = 
        2 << specifier_type_offset;
    static constexpr IntegerValueType specifier_ptr = 
        3 << specifier_type_offset;
    static constexpr IntegerValueType specifier_int = 
        4 << specifier_type_offset;
    static constexpr IntegerValueType specifier_fp = 
        5 << specifier_type_offset;
    static constexpr IntegerValueType specifier_blank = 
        6 << specifier_type_offset;
    static constexpr IntegerValueType specifier_bool = 
        7 << specifier_type_offset;
    static constexpr IntegerValueType specifier_object = 
        8 << specifier_type_offset;

    static constexpr IntegerValueType specifier_sub_width = 
        1 << specifier_sub_offset;
    static constexpr IntegerValueType specifier_sub_length = 
        2 << specifier_sub_offset;
    static constexpr IntegerValueType specifier_sub_precision = 
        2 << specifier_sub_offset;

    static constexpr IntegerValueType specifier_int_signed = 
        1 << specifier_int_offset;
    static constexpr IntegerValueType specifier_int_unsigned = 
        2 << specifier_int_offset;

    static constexpr IntegerValueType specifier_fp_fixed = 
        1 << specifier_fp_offset;
    static constexpr IntegerValueType specifier_fp_exponent = 
        2 << specifier_fp_offset;
    static constexpr IntegerValueType specifier_fp_short = 
        3 << specifier_fp_offset;

    static constexpr IntegerValueType specifier_base_dec = 
        0 << specifier_base_offset;
    static constexpr IntegerValueType specifier_base_oct = 
        1 << specifier_base_offset;
    static constexpr IntegerValueType specifier_base_hex = 
        2 << specifier_base_offset;

    static constexpr IntegerValueType specifier_lower_case = 
        0 << specifier_case_offset;
    static constexpr IntegerValueType specifier_upper_case = 
        1 << specifier_case_offset;

    static constexpr IntegerValueType specifier_flag_undefined = 
        0 << specifier_flag_offset;
    static constexpr IntegerValueType specifier_flag_prefix = 
        1 << specifier_flag_offset;
    static constexpr IntegerValueType specifier_flag_prefix_plus = 
        2 << specifier_flag_offset;
    static constexpr IntegerValueType specifier_flag_prefix_space = 
        4 << specifier_flag_offset;
    static constexpr IntegerValueType specifier_flag_prefix_zero = 
        8 << specifier_flag_offset;

    static constexpr IntegerValueType input_value = 1 << input_offset;
    static constexpr IntegerValueType input_width = 2 << input_offset;
    static constexpr IntegerValueType input_length = 4 << input_offset;
    static constexpr IntegerValueType input_precision = input_length;

    static constexpr IntegerValueType output_char = 1 << output_offset;
    static constexpr IntegerValueType output_wchar = 2 << output_offset;
private:
    static constexpr IntegerValueType _Value(IntegerValueType val);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<wchar_t>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<char>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<signed char>&&, TArgs&&... args);
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
        DefineType<bool>&&, TArgs&&... args);
    template<typename T, typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        DefineType<T>&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        WidthType&&, TArgs&&... args);
    template<typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        LengthType&&, TArgs&&... args);
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
    template<typename T, typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        SetValueType<T>&&, TArgs&&... args);
    template<typename... TCharArgs, typename... TArgs>
    static constexpr IntegerValueType _Value(IntegerValueType val, 
        SetOutputType<TCharArgs...>&&, TArgs&&... args);
private:
    static constexpr IntegerValueType __Value(IntegerValueType val);
    template<typename TArg, typename... TArgs>
    static constexpr IntegerValueType __Value(IntegerValueType val, 
        TArg&& arg, TArgs&&... args);
private:
    static constexpr std::false_type ___Value(...);
    template<typename ... TArgs>
    static constexpr auto ___Value(TArgs&&... args) -> 
        decltype(_Value(std::forward<TArgs>(args)...), 
            std::true_type());
private:
    ValueType m_value;
public:
    constexpr Flag();
    template<typename... TArgs>
    constexpr Flag(IntegerValueType specifier, TArgs&& ... args);
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
    constexpr bool IsSpecifierBlank() const;
    constexpr bool IsSpecifierBoolean() const;
    constexpr bool IsSpecifierObject() const;
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
    constexpr bool HasInputValue() const;
    constexpr bool HasInputWidth() const;
    constexpr bool HasInputLength() const;
    constexpr bool HasInputPrecision() const;
    void SetInput(const IntegerValueType& val);
public:
    constexpr bool HasOutput() const;
    template<typename TChar>
    constexpr bool HasOutput(TChar&&) const;
private:
    constexpr std::size_t OutputSize(std::size_t n, 
        IntegerValueType v) const;
public:
    constexpr std::size_t OutputSize() const;
public:
    void SetOutput(const IntegerValueType& val);
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
    DefineType<wchar_t>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | define_wchar,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<char>&&, 
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | define_char,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<signed char>&&, 
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_char | define_signed),
        std::forward<TArgs>(args)...);
}


template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<short>&&,
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_short | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<int>&&,
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_int | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<long>&&,
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_long | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<long long>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_long_long | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned char>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_char | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned short>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_short | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned int>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_int | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned long>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_long | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<unsigned long long>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | (define_long_long | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<float>&&,
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | define_float,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DefineType<double>&&,
    TArgs&&... args)
{
    return __Value((val & ~define_mask) | define_double,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<long double>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | define_long_double,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<bool>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | define_bool,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename T, typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    DefineType<T>&&, TArgs&&... args)
{
    return __Value((val & ~define_mask) | undefined,
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, WidthType&& width,
    TArgs&&... args)
{
    return __Value((val | specifier_sub_width | 
        (width.IsDefault() ? 0 : input_width)), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    LengthType&& length, TArgs&&... args)
{
    return __Value((val | specifier_sub_length | 
        (length.IsDefault() ? 0 : input_length)), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    PrecisionType&& precision, TArgs&&... args)
{
    return __Value((val | specifier_sub_precision |
        (precision.IsDefault() ? 0 : input_precision)), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, SignedType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_int_mask) | specifier_int_signed, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, UnsignedType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_int_mask) | specifier_int_unsigned, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, FixedType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_fp_mask) | specifier_fp_fixed, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, ExponentType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_fp_mask) | specifier_fp_exponent, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, ShortType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_fp_mask) | specifier_fp_short, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, DecimalType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_base_mask) | specifier_base_dec, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, OctalType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_base_mask) | specifier_base_oct, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, HexadecimalType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_base_mask) | specifier_base_hex, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, LowerType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_case_mask) | specifier_lower_case, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, UpperType&&,
    TArgs&&... args)
{
    return __Value((val & ~specifier_case_mask) | specifier_upper_case, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixType&&,
    TArgs&&... args)
{
    return __Value(val | specifier_flag_prefix, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixPlusType&&,
    TArgs&&... args)
{
    return __Value(val | specifier_flag_prefix_plus, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixSpaceType&&,
    TArgs&&... args)
{
    return __Value(val | specifier_flag_prefix_space, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, PrefixZeroType&&,
    TArgs&&... args)
{
    return __Value(val | specifier_flag_prefix_zero, 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename T, typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    SetValueType<T>&& value, TArgs&&... args)
{
    return __Value(val | (value.IsDefault() ? 0 : input_value), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
template<typename... TCharArgs, typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::_Value(IntegerValueType val, 
    SetOutputType<TCharArgs...>&& value, TArgs&&... args)
{
    return __Value(val | 
            (value.template GetFormatOutput<char>() == nullptr ?
                0 : output_char) | 
            (value.template GetFormatOutput<wchar_t>() == nullptr ?
                0 : output_wchar), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::__Value(IntegerValueType val)
{
    return val;
}

template<typename TValue, typename TIntegerValue>
template<typename TArg, typename... TArgs>
constexpr typename Flag<TValue, TIntegerValue>::IntegerValueType 
Flag<TValue, TIntegerValue>::__Value(IntegerValueType val, 
    TArg&& arg, TArgs&&... args)
{
    static_assert(decltype(___Value(val, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...))::value, "Argument is not valid");
    return _Value(val, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TValue, typename TIntegerValue>
constexpr Flag<TValue, TIntegerValue>::Flag() :
    m_value(IntegerValueType(0))
{}

template<typename TValue, typename TIntegerValue>
template<typename... TArgs>
constexpr Flag<TValue, TIntegerValue>::Flag(IntegerValueType specifier,
    TArgs&& ... args) :
        m_value(Flag<TValue, TIntegerValue>::_Value(specifier & specifier_mask, 
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
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierBlank() const
{
    return (m_value & specifier_type_mask) == specifier_blank;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierBoolean() const
{
    return (m_value & specifier_type_mask) == specifier_bool;
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierObject() const
{
    return (m_value & specifier_type_mask) == specifier_object;
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
    return (m_value & specifier_flag_prefix) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefixPlus() const
{
    return (m_value & specifier_flag_prefix_plus) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefixSpace() const
{
    return (m_value & specifier_flag_prefix_space) &&
        !IsSpecifierUndefined(); 
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierFlagPrefixZero() const
{
    return (m_value & specifier_flag_prefix_zero) &&
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
    return ((m_value & specifier_sub_mask) & specifier_sub_width) &&
        !IsSpecifierUndefined();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierSubPrecision() const
{
    return ((m_value & specifier_sub_mask) & specifier_sub_precision) &&
        !IsSpecifierUndefined();
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::IsSpecifierSubLength() const
{
    return ((m_value & specifier_sub_mask) & specifier_sub_length) &&
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
constexpr bool Flag<TValue, TIntegerValue>::HasInputValue() const
{
    return ((m_value & input_mask) & input_value);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::HasInputWidth() const
{
    return ((m_value & input_mask) & input_width);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::HasInputLength() const
{
    return ((m_value & input_mask) & input_length);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::HasInputPrecision() const
{
    return ((m_value & input_mask) & input_precision);
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetInput(const IntegerValueType& val)
{
    m_value = (m_value & ~input_mask) | (val & input_mask);
}

template<typename TValue, typename TIntegerValue>
constexpr bool Flag<TValue, TIntegerValue>::HasOutput() const
{
    return (m_value & output_mask);
}

template<typename TValue, typename TIntegerValue>
template<typename TChar>
constexpr bool Flag<TValue, TIntegerValue>::HasOutput(TChar&& ch) const
{
    typedef test::out::fmt::Definition DefinitionType;
    return DefinitionType::OutputValue(std::forward<TChar>(ch)) ==
            DefinitionType::output_char ? (m_value & output_char) :
        DefinitionType::OutputValue(std::forward<TChar>(ch)) == 
            DefinitionType::output_wchar ? (m_value & output_wchar) : false;
}

template<typename TValue, typename TIntegerValue>
constexpr std::size_t Flag<TValue, TIntegerValue>::OutputSize(std::size_t n, 
    IntegerValueType v) const
{
    return (v & output_mask) == 0 ? n : 
        OutputSize((m_value & v) != 0 ? n + 1 : n, v << 1);
}

template<typename TValue, typename TIntegerValue>
constexpr std::size_t Flag<TValue, TIntegerValue>::OutputSize() const
{
    return OutputSize(0, output_char);
}

template<typename TValue, typename TIntegerValue>
void Flag<TValue, TIntegerValue>::SetOutput(const IntegerValueType& val)
{
    m_value = (m_value & ~output_mask) | (val & output_mask);
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
