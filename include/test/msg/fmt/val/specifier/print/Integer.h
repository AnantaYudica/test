#ifndef TEST_MSG_FMT_VAL_SPECIFIER_PRINT_INTEGER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_PRINT_INTEGER_H_

#include "../../flag/Integer.h"
#include "../val/Integer.h"
#include "../../Specifier.h"
#include "../../Width.h"
#include "../../Length.h"

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{
namespace specifier
{
namespace print
{

template<typename TChar, int FlagValue>
class Integer
{
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        signed_octal_not_support) != test::msg::fmt::val::flag::Integer::
        signed_octal_not_support, "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        signed_hexadecimal_not_support) != test::msg::fmt::val::flag::
        Integer::signed_hexadecimal_not_support, "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        decimal_upper_not_support) != test::msg::fmt::val::flag::Integer::
        decimal_upper_not_support, "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        octal_upper_not_support) != test::msg::fmt::val::flag::Integer::
        octal_upper_not_support, "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        prefix_decimal_not_support_mask) != test::msg::fmt::val::flag::
        Integer::prefix_decimal_not_support, "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        prefix_plus_unsigned_not_support) != test::msg::fmt::val::flag::
        Integer::prefix_plus_unsigned_not_support, 
        "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        prefix_space_unsigned_not_support) != test::msg::fmt::val::flag::
        Integer::prefix_space_unsigned_not_support, 
        "Flag Value is not support");
    static_assert((FlagValue & test::msg::fmt::val::flag::Integer::
        prefix_zero_length_not_support) != test::msg::fmt::val::flag::
        Integer::prefix_zero_length_not_support, "Flag Value is not support");
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ldu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p__uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp__lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps__lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__ldu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz__uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_ldu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::w_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_w_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_w_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_w_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_ldu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pz_w_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_ldu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::l_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_l_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_l_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_l_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_ldu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::wl_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lou_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
  
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_lhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};
   
template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::p_wl_uhu_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::pp_wl_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_unsigned_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_unsigned_short_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_unsigned_int_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_unsigned_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar>
class Integer<TChar, 
    test::msg::fmt::val::flag::Integer::ps_wl_lds_unsigned_long_long_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    Integer() = delete;
};

template<typename TChar, int FlagValue>
typename Integer<TChar, FlagValue>::SizeType 
Integer<TChar, FlagValue>::Print(OutputInterfaceType&, const WidthType&, 
    const LengthType&, const ValueType&)
{
    return 0;
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhu", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hu", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%u", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lu", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llu", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhu", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hu", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%u", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lu", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ldu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llu", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hho", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%ho", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%o", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lo", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llo", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hho", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%ho", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%o", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lo", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llo", val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhx", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hx", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%x", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lx", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llx", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhx", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hx", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%x", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lx", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llx", val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhX", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hX", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%X", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lX", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llX", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hhX", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%hX", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%X", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%lX", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%llX", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hho", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#ho", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#o", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#lo", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#llo", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hho", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#ho", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#o", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#lo", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#llo", val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hhx", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hx", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#x", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#lx", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#llx", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hhx", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hx", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#x", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#lx", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#llx", val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hhX", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hX", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#X", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#lX", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#llX", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hhX", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#hX", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#X", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#lX", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p__uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%#llX", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp__lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%+lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps__lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("% lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhi", val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hi", val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0i", val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0li", val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lli", val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhu", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hu", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0u", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lu", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llu", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhu", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hu", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0u", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lu", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__ldu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llu", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hho", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0ho", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0o", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lo", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llo", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hho", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0ho", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0o", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lo", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llo", val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhx", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hx", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0x", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lx", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llx", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhx", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hx", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0x", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lx", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llx", val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhX", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hX", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0X", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lX", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llX", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hhX", val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0hX", val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0X", val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0lX", val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz__uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType&, const ValueType& val)
{
    return out.Print("%0llX", val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhu", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hu", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*u", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lu", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llu", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhu", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hu", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*u", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lu", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_ldu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llu", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hho", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*ho", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*o", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lo", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llo", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hho", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*ho", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*o", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lo", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llo", width.GetValue(), 
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhx", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hx", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*x", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lx", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llx", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhx", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hx", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*x", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lx", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llx", width.GetValue(), 
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhX", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hX", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*X", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lX", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llX", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hhX", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*hX", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*X", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*lX", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::w_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%*llX", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hho", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*ho", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*o", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*lo", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*llo", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hho", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*ho", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*o", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*lo", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*llo", width.GetValue(), 
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hhx", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hx", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*x", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*lx", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*llx", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hhx", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hx", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*x", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*lx", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*llx", width.GetValue(), 
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hhX", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hX", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*X", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*lX", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*llX", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hhX", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*hX", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*X", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*lX", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_w_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%#*llX", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_w_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%+*lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_w_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("% *lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhi", width.GetValue(), 
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hi", width.GetValue(), 
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*i", width.GetValue(), 
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*li", width.GetValue(), 
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lli", width.GetValue(), 
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhu", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hu", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*u", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lu", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llu", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhu", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hu", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*u", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lu", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_ldu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llu", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hho", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*ho", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*o", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lo", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llo", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hho", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*ho", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*o", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lo", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llo", width.GetValue(), 
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhx", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hx", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*x", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lx", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llx", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhx", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hx", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*x", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lx", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llx", width.GetValue(), 
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhX", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hX", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*X", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lX", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llX", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hhX", width.GetValue(), 
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*hX", width.GetValue(), 
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*X", width.GetValue(), 
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*lX", width.GetValue(), 
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pz_w_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType&, const ValueType& val)
{
    return out.Print("%0*llX", width.GetValue(), 
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhi", length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hi", length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*i", length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*li", length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lli", length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhi", length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hi", length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*i", length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*li", length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lli", length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhu", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hu", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*u", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lu", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llu", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhu", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hu", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*u", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lu", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_ldu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llu", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hho", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*ho", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*o", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lo", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llo", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hho", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*ho", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*o", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lo", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llo", length.GetValue(),
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhx", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hx", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*x", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lx", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llx", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhx", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hx", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*x", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lx", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llx", length.GetValue(),
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhX", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hX", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*X", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lX", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llX", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hhX", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*hX", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*X", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*lX", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::l_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%.*llX", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hho", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*ho", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*o", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*lo", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*llo", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hho", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*ho", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*o", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*lo", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*llo", length.GetValue(),
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hhx", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hx", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*x", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*lx", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*llx", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hhx", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hx", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*x", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*lx", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*llx", length.GetValue(),
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hhX", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hX", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*X", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*lX", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*llX", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hhX", length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*hX", length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*X", length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*lX", length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_l_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%#.*llX", length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*hhi", length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*hi", length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*i", length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*li", length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*lli", length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*hhi", length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*hi", length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*i", length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*li", length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_l_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("%+.*lli", length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*hhi", length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*hi", length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*i", length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*li", length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*lli", length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*hhi", length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*hi", length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*i", length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*li", length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_l_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const LengthType& length, const ValueType& val)
{
    return out.Print("% .*lli", length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhi", width.GetValue(), length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hi", width.GetValue(), length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*i", width.GetValue(), length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*li", width.GetValue(), length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lli", width.GetValue(), length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhi", width.GetValue(), length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hi", width.GetValue(), length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*i", width.GetValue(), length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*li", width.GetValue(), length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lli", width.GetValue(), length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhu", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hu", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*u", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lu", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llu", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhu", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hu", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*u", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lu", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_ldu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llu", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hho", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*ho", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*o", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lo", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llo", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hho", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*ho", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*o", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lo", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llo", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhx", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hx", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*x", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lx", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llx", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhx", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hx", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*x", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lx", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llx", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhX", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hX", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*X", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lX", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llX", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hhX", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*hX", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*X", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*lX", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::wl_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*llX", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hho", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*ho", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*o", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*lo", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*llo", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hho", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*ho", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*o", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*lo", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lou_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*llo", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}
  
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hhx", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hx", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*x", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*lx", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*llx", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hhx", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hx", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*x", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*lx", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_lhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*llx", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}
   
template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hhX", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hX", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*X", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*lX", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*llX", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hhX", width.GetValue(), length.GetValue(),
        val.unsigned_char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*hX", width.GetValue(), length.GetValue(),
        val.unsigned_short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*X", width.GetValue(), length.GetValue(),
        val.unsigned_int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*lX", width.GetValue(), length.GetValue(),
        val.unsigned_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::p_wl_uhu_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%#*.*llX", width.GetValue(), length.GetValue(),
        val.unsigned_long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*hhi", width.GetValue(), length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*hi", width.GetValue(), length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*i", width.GetValue(), length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*li", width.GetValue(), length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*lli", width.GetValue(), length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*hhi", width.GetValue(), length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*hi", width.GetValue(), length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*i", width.GetValue(), length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*li", width.GetValue(), length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::pp_wl_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("%+*.*lli", width.GetValue(), length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*hhi", width.GetValue(), length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*hi", width.GetValue(), length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*i", width.GetValue(), length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*li", width.GetValue(), length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*lli", width.GetValue(), length.GetValue(),
        val.long_long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_char_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_char_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*hhi", width.GetValue(), length.GetValue(),
        val.char_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_short_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_short_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*hi", width.GetValue(), length.GetValue(),
        val.short_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_int_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_int_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*i", width.GetValue(), length.GetValue(),
        val.int_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*li", width.GetValue(), length.GetValue(),
        val.long_value);
}

template<typename TChar>
typename Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_long_long_format>::SizeType 
Integer<TChar, test::msg::fmt::val::flag::
    Integer::ps_wl_lds_unsigned_long_long_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const LengthType& length, const ValueType& val)
{
    return out.Print("% *.*lli", width.GetValue(), length.GetValue(),
        val.long_long_value);
}

} //!print

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_PRINT_INTEGER_H_
