#ifndef TEST_MSG_FMT_PARAM_SPECIFIER_PRINT_FLOATINGPOINT_H_
#define TEST_MSG_FMT_PARAM_SPECIFIER_PRINT_FLOATINGPOINT_H_

#include "../../flag/FloatingPoint.h"
#include "../val/FloatingPoint.h"
#include "../../Specifier.h"
#include "../../Width.h"
#include "../../Precision.h"

namespace test
{
namespace msg
{
namespace fmt
{
namespace param
{
namespace specifier
{
namespace print
{

template<typename TChar, int FlagValue>
class FloatingPoint
{
    static_assert((FlagValue & test::msg::fmt::param::flag::
        FloatingPoint::hexadecimal_not_support) != test::msg::fmt::param::
        flag::FloatingPoint::hexadecimal_not_support, 
        "Flag Value is not support");
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};



template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p__uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp__uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps__uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz__uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::w_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_w_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_w_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_w_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_w_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_p_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_p_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_p_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_p_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::wp_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::p_wp_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pp_wp_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::ps_wp_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_ldf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_ldf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_udf_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_udf_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_lde_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_lde_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_ude_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_ude_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_ldfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_ldfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_udfe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_udfe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_lhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_lhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_uhe_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar>
class FloatingPoint<TChar,
    test::msg::fmt::param::flag::FloatingPoint::pz_wp_uhe_long_double_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::Precision<TChar> PrecisionType;
    typedef test::msg::fmt::param::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const PrecisionType& precision, const ValueType& val);
public:
    FloatingPoint() = delete;
};

template<typename TChar, int FlagValue>
typename FloatingPoint<TChar, FlagValue>::SizeType 
FloatingPoint<TChar, FlagValue>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType&)
{
    return 0;
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%f", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%Lf", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%F", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%LF", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%e", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%Le", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%E", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%LE", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%g", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%Lg", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%G", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%LG", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%a", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%La", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%A", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%LA", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#f", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#Lf", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#F", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#LF", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#e", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#Le", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#E", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#LE", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#g", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#Lg", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#G", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#LG", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#a", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#La", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#A", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p__uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#LA", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+f", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+Lf", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+F", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+LF", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+e", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+Le", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+E", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+LE", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+g", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+Lg", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+G", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+LG", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+a", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+La", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+A", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp__uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+LA", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% f", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% Lf", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% F", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% LF", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% e", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% Le", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% E", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% LE", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% g", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% Lg", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% G", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% LG", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% a", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% La", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% A", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps__uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("% LA", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0f", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0Lf", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0F", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0LF", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0e", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0Le", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0E", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0LE", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0g", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0Lg", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0G", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0LG", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0a", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0La", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0A", ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz__uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0LA", ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*f", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*Lf", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*F", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*LF", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*e", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*Le", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*E", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*LE", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*g", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*Lg", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*G", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*LG", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*a", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*La", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*A", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    w_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%*LA", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*f", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*Lf", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*F", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*LF", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*e", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*Le", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*E", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*LE", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*g", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*Lg", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*G", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*LG", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*a", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*La", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*A", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_w_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%#*LA", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*f", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*Lf", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*F", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*LF", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*e", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*Le", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*E", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*LE", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*g", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*Lg", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*G", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*LG", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*a", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*La", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*A", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_w_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%+*LA", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *f", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *Lf", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *F", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *LF", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *e", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *Le", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *E", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *LE", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *g", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *Lg", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *G", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *LG", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *a", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *La", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *A", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_w_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("% *LA", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*f", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*Lf", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*F", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*LF", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*e", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*Le", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*E", width.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*LE", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*g", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*Lg", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*G", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*LG", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*a", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*La", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*A", width.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_w_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType&, const ValueType& val)
{
    return out.Print("%0*LA", width.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*f", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*Lf", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*F", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*LF", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*e", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*Le", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*E", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*LE", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*g", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*Lg", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*G", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*LG", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*a", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*La", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*A", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%.*LA", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*f", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*Lf", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*F", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*LF", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*e", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*Le", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*E", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*LE", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*g", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*Lg", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*G", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*LG", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*a", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*La", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*A", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_p_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%#.*LA", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*f", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*Lf", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*F", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*LF", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*e", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*Le", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*E", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*LE", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*g", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*Lg", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*G", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*LG", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*a", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*La", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*A", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_p_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%+.*LA", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*f", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*Lf", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*F", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*LF", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*e", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*Le", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*E", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*LE", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*g", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*Lg", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*G", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*LG", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*a", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*La", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*A", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_p_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("% .*LA", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*f", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*Lf", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*F", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*LF", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*e", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*Le", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*E", precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*LE", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*g", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*Lg", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*G", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*LG", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*a", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*La", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*A", precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_p_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType&, const PrecisionType& precision, const ValueType& val)
{
    return out.Print("%0.*LA", precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*f", width.GetValue() ,precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*Lf", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*F", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*LF", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*e", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*Le", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*E", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*LE", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*g", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*Lg", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*G", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*LG", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*a", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*La", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*A", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    wp_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%*.*LA", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*f", width.GetValue() ,precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*Lf", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*F", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*LF", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*e", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*Le", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*E", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*LE", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*g", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*Lg", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*G", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*LG", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*a", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*La", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*A", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    p_wp_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%#*.*LA", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*f", width.GetValue() ,precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*Lf", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*F", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*LF", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*e", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*Le", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*E", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*LE", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*g", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*Lg", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*G", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*LG", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*a", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*La", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*A", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pp_wp_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%+*.*LA", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*f", width.GetValue() ,precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*Lf", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*F", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*LF", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*e", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*Le", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*E", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*LE", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*g", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*Lg", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*G", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*LG", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*a", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*La", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*A", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    ps_wp_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("% *.*LA", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*f", width.GetValue() ,precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*Lf", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udf_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udf_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*F", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udf_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udf_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*LF", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lde_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lde_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*e", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lde_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lde_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*Le", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ude_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ude_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*E", width.GetValue(), precision.GetValue(), 
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ude_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ude_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*LE", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*g", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_ldfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*Lg", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udfe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udfe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*G", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udfe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_udfe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*LG", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*a", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_lhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*La", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_uhe_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_uhe_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*A", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<double>(val));
}

template<typename TChar>
typename FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_uhe_long_double_format>::SizeType 
FloatingPoint<TChar, test::msg::fmt::param::flag::FloatingPoint::
    pz_wp_uhe_long_double_format>::Print(OutputInterfaceType& out, 
    const WidthType& width, const PrecisionType& precision, 
    const ValueType& val)
{
    return out.Print("%0*.*LA", width.GetValue(), precision.GetValue(),
        ValueType::CastTo<long double>(val));
}


} //!print

} //!specifier

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_SPECIFIER_PRINT_FLOATINGPOINT_H_
