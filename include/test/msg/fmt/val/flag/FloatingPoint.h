#ifndef TEST_MSG_FMT_VAL_FLAG_FLOATINGPOINT_H_
#define TEST_MSG_FMT_VAL_FLAG_FLOATINGPOINT_H_

#include "arg/Define.h"
#include "arg/Decimal.h"
#include "arg/Hexadecimal.h"
#include "arg/Exponent.h"
#include "arg/Fixed.h"
#include "arg/Lower.h"
#include "arg/Upper.h"
#include "arg/Prefix.h"
#include "arg/PrefixPlus.h"
#include "arg/PrefixSpace.h"
#include "arg/PrefixZero.h"
#include "arg/Width.h"
#include "arg/Precision.h"

#include <cstdint>
#include <utility>
#include <type_traits>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{
namespace flag
{

class FloatingPoint
{
public:
    typedef std::uint16_t ValueType;
    template<typename T>
    using DefineType = test::msg::fmt::param::flag::arg::Define<T>;
    typedef test::msg::fmt::param::flag::arg::Decimal DecimalType;
    typedef test::msg::fmt::param::flag::arg::Hexadecimal HexadecimalType;
    typedef test::msg::fmt::param::flag::arg::Exponent ExponentType;
    typedef test::msg::fmt::param::flag::arg::Fixed FixedType;
    typedef test::msg::fmt::param::flag::arg::Lower LowerType;
    typedef test::msg::fmt::param::flag::arg::Upper UpperType;
    typedef test::msg::fmt::param::flag::arg::Prefix PrefixType;
    typedef test::msg::fmt::param::flag::arg::PrefixPlus PrefixPlusType;
    typedef test::msg::fmt::param::flag::arg::PrefixSpace PrefixSpaceType;
    typedef test::msg::fmt::param::flag::arg::PrefixZero PrefixZeroType;
    typedef test::msg::fmt::param::flag::arg::Width WidthType;
    typedef test::msg::fmt::param::flag::arg::Precision PrecisionType;
public:
    enum : ValueType
    {
        good = 0,
        define_double = 1 << 0,
        define_long = 1 << 1,
        decimal = 1 << 2,
        hexadecimal = 1 << 3,
        fixed = 1 << 4,
        exponent = 1 << 5,
        lower = 1 << 6,
        upper = 1 << 7,
        prefix = 1 << 8,
        plus = 1 << 9,
        space = 1 << 10,
        zero = 1 << 11,
        width = 1 << 12,
        precision = 1 << 13
    };
private:
    static constexpr ValueType define_mask = define_double | define_long;
    static constexpr ValueType base_mask = decimal | hexadecimal;
    static constexpr ValueType notation_mask = fixed | exponent;
    static constexpr ValueType letter_mask = lower | upper;
    static constexpr ValueType prefix_mask = prefix| plus | space | zero;
public:
    static constexpr ValueType ldf_double_format =  
        define_double | decimal | fixed | lower;
    static constexpr ValueType ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower;
    static constexpr ValueType udf_double_format = 
        define_double | decimal | fixed | upper;
    static constexpr ValueType udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper;
    static constexpr ValueType lde_double_format = 
        define_double | decimal | exponent | lower;
    static constexpr ValueType lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower;
    static constexpr ValueType ude_double_format = 
        define_double | decimal | exponent | upper;
    static constexpr ValueType ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper;
    static constexpr ValueType ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower;
    static constexpr ValueType ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower;
    static constexpr ValueType udfe_double_format =  
        define_double | decimal | fixed | exponent| upper;
    static constexpr ValueType udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper;
    static constexpr ValueType lhe_double_format = 
        define_double | hexadecimal | exponent | lower;
    static constexpr ValueType lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower;
    static constexpr ValueType uhe_double_format = 
        define_double | hexadecimal | exponent | upper;
    static constexpr ValueType uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper;
public:
    static constexpr ValueType p__ldf_double_format =  
        define_double | decimal | fixed | lower | prefix;
    static constexpr ValueType p__ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | prefix;
    static constexpr ValueType p__udf_double_format = 
        define_double | decimal | fixed | upper | prefix;
    static constexpr ValueType p__udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | prefix;
    static constexpr ValueType p__lde_double_format = 
        define_double | decimal | exponent | lower | prefix;
    static constexpr ValueType p__lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | prefix;
    static constexpr ValueType p__ude_double_format = 
        define_double | decimal | exponent | upper | prefix;
    static constexpr ValueType p__ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | prefix;
    static constexpr ValueType p__ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | prefix;
    static constexpr ValueType p__ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        prefix;
    static constexpr ValueType p__udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | prefix;
    static constexpr ValueType p__udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        prefix;
    static constexpr ValueType p__lhe_double_format = 
        define_double | hexadecimal | exponent | lower | prefix;
    static constexpr ValueType p__lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        prefix;
    static constexpr ValueType p__uhe_double_format = 
        define_double | hexadecimal | exponent | upper | prefix;
    static constexpr ValueType p__uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        prefix;
public:
    static constexpr ValueType pp__ldf_double_format =  
        define_double | decimal | fixed | lower | prefix | plus;
    static constexpr ValueType pp__ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | prefix | plus;
    static constexpr ValueType pp__udf_double_format = 
        define_double | decimal | fixed | upper | prefix | plus;
    static constexpr ValueType pp__udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | prefix | plus;
    static constexpr ValueType pp__lde_double_format = 
        define_double | decimal | exponent | lower | prefix | plus;
    static constexpr ValueType pp__lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | prefix | 
        plus;
    static constexpr ValueType pp__ude_double_format = 
        define_double | decimal | exponent | upper | prefix | plus;
    static constexpr ValueType pp__ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | prefix | 
        plus;
    static constexpr ValueType pp__ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | prefix | plus;
    static constexpr ValueType pp__ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        prefix | plus;
    static constexpr ValueType pp__udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | prefix | plus;
    static constexpr ValueType pp__udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        prefix | plus;
    static constexpr ValueType pp__lhe_double_format = 
        define_double | hexadecimal | exponent | lower | prefix | plus;
    static constexpr ValueType pp__lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        prefix | plus;
    static constexpr ValueType pp__uhe_double_format = 
        define_double | hexadecimal | exponent | upper | prefix | plus;
    static constexpr ValueType pp__uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        prefix | plus;

public:
    static constexpr ValueType ps__ldf_double_format =  
        define_double | decimal | fixed | lower | prefix | space;
    static constexpr ValueType ps__ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | prefix | space;
    static constexpr ValueType ps__udf_double_format = 
        define_double | decimal | fixed | upper | prefix | space;
    static constexpr ValueType ps__udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | prefix | space;
    static constexpr ValueType ps__lde_double_format = 
        define_double | decimal | exponent | lower | prefix | space;
    static constexpr ValueType ps__lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | prefix | 
        space;
    static constexpr ValueType ps__ude_double_format = 
        define_double | decimal | exponent | upper | prefix | space;
    static constexpr ValueType ps__ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | prefix | 
        space;
    static constexpr ValueType ps__ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | prefix | space;
    static constexpr ValueType ps__ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        prefix | space;
    static constexpr ValueType ps__udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | prefix | space;
    static constexpr ValueType ps__udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        prefix | space;
    static constexpr ValueType ps__lhe_double_format = 
        define_double | hexadecimal | exponent | lower | prefix | space;
    static constexpr ValueType ps__lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        prefix | space;
    static constexpr ValueType ps__uhe_double_format = 
        define_double | hexadecimal | exponent | upper | prefix | space;
    static constexpr ValueType ps__uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        prefix | space;
public:
    static constexpr ValueType pz__ldf_double_format =  
        define_double | decimal | fixed | lower | prefix | zero;
    static constexpr ValueType pz__ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | prefix | zero;
    static constexpr ValueType pz__udf_double_format = 
        define_double | decimal | fixed | upper | prefix | zero;
    static constexpr ValueType pz__udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | prefix | zero;
    static constexpr ValueType pz__lde_double_format = 
        define_double | decimal | exponent | lower | prefix | zero;
    static constexpr ValueType pz__lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | prefix | 
        zero;
    static constexpr ValueType pz__ude_double_format = 
        define_double | decimal | exponent | upper | prefix | zero;
    static constexpr ValueType pz__ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | prefix | 
        zero;
    static constexpr ValueType pz__ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | prefix | zero;
    static constexpr ValueType pz__ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        prefix | zero;
    static constexpr ValueType pz__udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | prefix | zero;
    static constexpr ValueType pz__udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        prefix | zero;
    static constexpr ValueType pz__lhe_double_format = 
        define_double | hexadecimal | exponent | lower | prefix | zero;
    static constexpr ValueType pz__lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        prefix | zero;
    static constexpr ValueType pz__uhe_double_format = 
        define_double | hexadecimal | exponent | upper | prefix | zero;
    static constexpr ValueType pz__uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        prefix | zero;
public:
    static constexpr ValueType w_ldf_double_format =  
        define_double | decimal | fixed | lower | width;
    static constexpr ValueType w_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width;
    static constexpr ValueType w_udf_double_format = 
        define_double | decimal | fixed | upper | width;
    static constexpr ValueType w_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width;
    static constexpr ValueType w_lde_double_format = 
        define_double | decimal | exponent | lower | width;
    static constexpr ValueType w_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width;
    static constexpr ValueType w_ude_double_format = 
        define_double | decimal | exponent | upper | width;
    static constexpr ValueType w_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width;
    static constexpr ValueType w_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width;
    static constexpr ValueType w_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width;
    static constexpr ValueType w_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width;
    static constexpr ValueType w_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width;
    static constexpr ValueType w_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width;
    static constexpr ValueType w_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | width;
    static constexpr ValueType w_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width;
    static constexpr ValueType w_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | width;
public:
    static constexpr ValueType p_w_ldf_double_format =  
        define_double | decimal | fixed | lower | width | prefix;
    static constexpr ValueType p_w_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | prefix;
    static constexpr ValueType p_w_udf_double_format = 
        define_double | decimal | fixed | upper | width | prefix;
    static constexpr ValueType p_w_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | prefix;
    static constexpr ValueType p_w_lde_double_format = 
        define_double | decimal | exponent | lower | width | prefix;
    static constexpr ValueType p_w_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width | 
        prefix;
    static constexpr ValueType p_w_ude_double_format = 
        define_double | decimal | exponent | upper | width | prefix;
    static constexpr ValueType p_w_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        prefix;
    static constexpr ValueType p_w_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | prefix;
    static constexpr ValueType p_w_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | prefix;
    static constexpr ValueType p_w_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | prefix;
    static constexpr ValueType p_w_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | prefix;
    static constexpr ValueType p_w_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | prefix;
    static constexpr ValueType p_w_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | prefix;
    static constexpr ValueType p_w_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | prefix;
    static constexpr ValueType p_w_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | prefix;
public:
    static constexpr ValueType pp_w_ldf_double_format =  
        define_double | decimal | fixed | lower | width | prefix | plus;
    static constexpr ValueType pp_w_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        prefix | plus;
    static constexpr ValueType pp_w_udf_double_format = 
        define_double | decimal | fixed | upper | width | prefix | plus;
    static constexpr ValueType pp_w_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width |
        prefix | plus;
    static constexpr ValueType pp_w_lde_double_format = 
        define_double | decimal | exponent | lower | width | prefix | plus;
    static constexpr ValueType pp_w_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width |
        prefix | plus;
    static constexpr ValueType pp_w_ude_double_format = 
        define_double | decimal | exponent | upper | width | prefix | plus;
    static constexpr ValueType pp_w_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        prefix | plus;
    static constexpr ValueType pp_w_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | prefix |
        plus;
    static constexpr ValueType pp_w_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | prefix |
        plus;
    static constexpr ValueType pp_w_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | prefix | plus;
    static constexpr ValueType pp_w_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | prefix | plus;
    static constexpr ValueType pp_w_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | prefix | plus;
public:
    static constexpr ValueType ps_w_ldf_double_format =  
        define_double | decimal | fixed | lower | width | prefix | space;
    static constexpr ValueType ps_w_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        prefix | space;
    static constexpr ValueType ps_w_udf_double_format = 
        define_double | decimal | fixed | upper | width | prefix | space;
    static constexpr ValueType ps_w_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        prefix | space;
    static constexpr ValueType ps_w_lde_double_format = 
        define_double | decimal | exponent | lower | width | prefix | space;
    static constexpr ValueType ps_w_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width |
        prefix | space;
    static constexpr ValueType ps_w_ude_double_format = 
        define_double | decimal | exponent | upper | width | prefix | space;
    static constexpr ValueType ps_w_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        prefix | space;
    static constexpr ValueType ps_w_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | prefix | 
        space;
    static constexpr ValueType ps_w_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | prefix | 
        space;
    static constexpr ValueType ps_w_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | prefix | space;
    static constexpr ValueType ps_w_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | prefix | 
        space;
    static constexpr ValueType ps_w_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | prefix | 
        space;
    static constexpr ValueType ps_w_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | prefix | space;
public:
    static constexpr ValueType pz_w_ldf_double_format =  
        define_double | decimal | fixed | lower | width | prefix | zero;
    static constexpr ValueType pz_w_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        prefix | zero;
    static constexpr ValueType pz_w_udf_double_format = 
        define_double | decimal | fixed | upper | width | prefix | zero;
    static constexpr ValueType pz_w_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        prefix | zero;
    static constexpr ValueType pz_w_lde_double_format = 
        define_double | decimal | exponent | lower | width | prefix | zero;
    static constexpr ValueType pz_w_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width | 
        prefix | zero;
    static constexpr ValueType pz_w_ude_double_format = 
        define_double | decimal | exponent | upper | width | prefix | zero;
    static constexpr ValueType pz_w_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        prefix | zero;
    static constexpr ValueType pz_w_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | prefix | 
        zero;
    static constexpr ValueType pz_w_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | prefix | 
        zero;
    static constexpr ValueType pz_w_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | prefix | zero;
public:
    static constexpr ValueType p_ldf_double_format =  
        define_double | decimal | fixed | lower | precision;
    static constexpr ValueType p_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | precision;
    static constexpr ValueType p_udf_double_format = 
        define_double | decimal | fixed | upper | precision;
    static constexpr ValueType p_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | precision;
    static constexpr ValueType p_lde_double_format = 
        define_double | decimal | exponent | lower | precision;
    static constexpr ValueType p_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | precision;
    static constexpr ValueType p_ude_double_format = 
        define_double | decimal | exponent | upper | precision;
    static constexpr ValueType p_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | precision;
    static constexpr ValueType p_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | precision;
    static constexpr ValueType p_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        precision;
    static constexpr ValueType p_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | precision;
    static constexpr ValueType p_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        precision;
    static constexpr ValueType p_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | precision;
    static constexpr ValueType p_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        precision;
    static constexpr ValueType p_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | precision;
    static constexpr ValueType p_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        precision;
public:
    static constexpr ValueType p_p_ldf_double_format =  
        define_double | decimal | fixed | lower | precision | prefix;
    static constexpr ValueType p_p_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | precision | 
        prefix;
    static constexpr ValueType p_p_udf_double_format = 
        define_double | decimal | fixed | upper | precision | prefix;
    static constexpr ValueType p_p_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | precision | 
        prefix;
    static constexpr ValueType p_p_lde_double_format = 
        define_double | decimal | exponent | lower | precision | prefix;
    static constexpr ValueType p_p_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | precision | 
        prefix;
    static constexpr ValueType p_p_ude_double_format = 
        define_double | decimal | exponent | upper | precision | prefix;
    static constexpr ValueType p_p_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | precision | 
        prefix;
    static constexpr ValueType p_p_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | precision | prefix;
    static constexpr ValueType p_p_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        precision | prefix;
    static constexpr ValueType p_p_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | precision | prefix;
    static constexpr ValueType p_p_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        precision | prefix;
    static constexpr ValueType p_p_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | precision | prefix;
    static constexpr ValueType p_p_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        precision | prefix;
    static constexpr ValueType p_p_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | precision | prefix;
    static constexpr ValueType p_p_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        precision | prefix;
public:
    static constexpr ValueType pp_p_ldf_double_format =  
        define_double | decimal | fixed | lower | precision | prefix | plus;
    static constexpr ValueType pp_p_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | precision | 
        prefix | plus;
    static constexpr ValueType pp_p_udf_double_format = 
        define_double | decimal | fixed | upper | precision | prefix | plus;
    static constexpr ValueType pp_p_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | precision |
        prefix | plus;
    static constexpr ValueType pp_p_lde_double_format = 
        define_double | decimal | exponent | lower | precision | prefix | plus;
    static constexpr ValueType pp_p_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | precision |
        prefix | plus;
    static constexpr ValueType pp_p_ude_double_format = 
        define_double | decimal | exponent | upper | precision | prefix | plus;
    static constexpr ValueType pp_p_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | precision | 
        prefix | plus;
    static constexpr ValueType pp_p_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | precision | 
        prefix | plus;
    static constexpr ValueType pp_p_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        precision | prefix | plus;
    static constexpr ValueType pp_p_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | precision | 
        prefix | plus;
    static constexpr ValueType pp_p_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        precision | prefix | plus;
    static constexpr ValueType pp_p_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | precision | prefix | 
        plus;
    static constexpr ValueType pp_p_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        precision | prefix | plus;
    static constexpr ValueType pp_p_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | precision | prefix | 
        plus;
    static constexpr ValueType pp_p_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        precision | prefix | plus;
public:
    static constexpr ValueType ps_p_ldf_double_format =  
        define_double | decimal | fixed | lower | precision | prefix | space;
    static constexpr ValueType ps_p_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | precision | 
        prefix | space;
    static constexpr ValueType ps_p_udf_double_format = 
        define_double | decimal | fixed | upper | precision | prefix | space;
    static constexpr ValueType ps_p_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | precision | 
        prefix | space;
    static constexpr ValueType ps_p_lde_double_format = 
        define_double | decimal | exponent | lower | precision | prefix | 
        space;
    static constexpr ValueType ps_p_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | precision |
        prefix | space;
    static constexpr ValueType ps_p_ude_double_format = 
        define_double | decimal | exponent | upper | precision | prefix | 
        space;
    static constexpr ValueType ps_p_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | precision | 
        prefix | space;
    static constexpr ValueType ps_p_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | precision | 
        prefix | space;
    static constexpr ValueType ps_p_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        precision | prefix | space;
    static constexpr ValueType ps_p_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | precision | 
        prefix | space;
    static constexpr ValueType ps_p_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        precision | prefix | space;
    static constexpr ValueType ps_p_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | precision | prefix | 
        space;
    static constexpr ValueType ps_p_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        precision | prefix | space;
    static constexpr ValueType ps_p_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | precision | prefix | 
        space;
    static constexpr ValueType ps_p_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        precision | prefix | space;
public:
    static constexpr ValueType pz_p_ldf_double_format =  
        define_double | decimal | fixed | lower | precision | prefix | zero;
    static constexpr ValueType pz_p_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | precision | 
        prefix | zero;
    static constexpr ValueType pz_p_udf_double_format = 
        define_double | decimal | fixed | upper | precision | prefix | zero;
    static constexpr ValueType pz_p_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | precision | 
        prefix | zero;
    static constexpr ValueType pz_p_lde_double_format = 
        define_double | decimal | exponent | lower | precision | prefix | zero;
    static constexpr ValueType pz_p_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | precision | 
        prefix | zero;
    static constexpr ValueType pz_p_ude_double_format = 
        define_double | decimal | exponent | upper | precision | prefix | zero;
    static constexpr ValueType pz_p_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | precision | 
        prefix | zero;
    static constexpr ValueType pz_p_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | precision | 
        prefix | zero;
    static constexpr ValueType pz_p_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        precision | prefix | zero;
    static constexpr ValueType pz_p_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | precision | 
        prefix | zero;
    static constexpr ValueType pz_p_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        precision | prefix | zero;
    static constexpr ValueType pz_p_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | precision | prefix | 
        zero;
    static constexpr ValueType pz_p_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        precision | prefix | zero;
    static constexpr ValueType pz_p_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | precision | prefix | 
        zero;
    static constexpr ValueType pz_p_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        precision | prefix | zero;
public:
    static constexpr ValueType wp_ldf_double_format =  
        define_double | decimal | fixed | lower | width | precision;
    static constexpr ValueType wp_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        precision;
    static constexpr ValueType wp_udf_double_format = 
        define_double | decimal | fixed | upper | width | precision;
    static constexpr ValueType wp_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        precision;
    static constexpr ValueType wp_lde_double_format = 
        define_double | decimal | exponent | lower | width | precision;
    static constexpr ValueType wp_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width | 
        precision;
    static constexpr ValueType wp_ude_double_format = 
        define_double | decimal | exponent | upper | width | precision;
    static constexpr ValueType wp_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        precision;
    static constexpr ValueType wp_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | 
        precision;
    static constexpr ValueType wp_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | precision;
    static constexpr ValueType wp_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | precision;
    static constexpr ValueType wp_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | precision;
    static constexpr ValueType wp_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | precision;
    static constexpr ValueType wp_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | width | 
        precision;
    static constexpr ValueType wp_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | precision;
    static constexpr ValueType wp_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | width |
        precision;
public:
    static constexpr ValueType p_wp_ldf_double_format =  
        define_double | decimal | fixed | lower | width | precision | prefix;
    static constexpr ValueType p_wp_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        precision | prefix;
    static constexpr ValueType p_wp_udf_double_format = 
        define_double | decimal | fixed | upper | width | precision | prefix;
    static constexpr ValueType p_wp_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        precision | prefix;
    static constexpr ValueType p_wp_lde_double_format = 
        define_double | decimal | exponent | lower | width | precision | 
        prefix;
    static constexpr ValueType p_wp_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width | 
        precision | prefix;
    static constexpr ValueType p_wp_ude_double_format = 
        define_double | decimal | exponent | upper | width | precision | 
        prefix;
    static constexpr ValueType p_wp_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        precision | prefix;
    static constexpr ValueType p_wp_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | 
        precision | prefix;
    static constexpr ValueType p_wp_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | precision | prefix;
    static constexpr ValueType p_wp_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | 
        precision | prefix;
    static constexpr ValueType p_wp_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | precision | prefix;
    static constexpr ValueType p_wp_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | precision |
        prefix;
    static constexpr ValueType p_wp_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | precision | prefix;
    static constexpr ValueType p_wp_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | precision |
        prefix;
    static constexpr ValueType p_wp_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | precision | prefix;
public:
    static constexpr ValueType pp_wp_ldf_double_format =  
        define_double | decimal | fixed | lower | width | precision | prefix | 
        plus;
    static constexpr ValueType pp_wp_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        precision | prefix | plus;
    static constexpr ValueType pp_wp_udf_double_format = 
        define_double | decimal | fixed | upper | width | precision | prefix | 
        plus;
    static constexpr ValueType pp_wp_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        precision | prefix | plus;
    static constexpr ValueType pp_wp_lde_double_format = 
        define_double | decimal | exponent | lower | width | precision | 
        prefix | plus;
    static constexpr ValueType pp_wp_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width |
        precision | prefix | plus;
    static constexpr ValueType pp_wp_ude_double_format = 
        define_double | decimal | exponent | upper | width | precision | 
        prefix | plus;
    static constexpr ValueType pp_wp_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        precision | prefix | plus;
    static constexpr ValueType pp_wp_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | 
        precision | prefix | plus;
    static constexpr ValueType pp_wp_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | precision | prefix | plus;
    static constexpr ValueType pp_wp_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | 
        precision | prefix | plus;
    static constexpr ValueType pp_wp_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | precision | prefix | plus;
    static constexpr ValueType pp_wp_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | precision | 
        prefix | plus;
    static constexpr ValueType pp_wp_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | precision | prefix | plus;
    static constexpr ValueType pp_wp_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | precision | 
        prefix | plus;
    static constexpr ValueType pp_wp_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | precision | prefix | plus;
public:
    static constexpr ValueType ps_wp_ldf_double_format =  
        define_double | decimal | fixed | lower | width | precision | prefix |
        space;
    static constexpr ValueType ps_wp_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        precision | prefix | space;
    static constexpr ValueType ps_wp_udf_double_format = 
        define_double | decimal | fixed | upper | width | precision | prefix | 
        space;
    static constexpr ValueType ps_wp_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        precision | prefix | space;
    static constexpr ValueType ps_wp_lde_double_format = 
        define_double | decimal | exponent | lower | width | precision | 
        prefix | space;
    static constexpr ValueType ps_wp_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width |
        precision | prefix | space;
    static constexpr ValueType ps_wp_ude_double_format = 
        define_double | decimal | exponent | upper | width | precision | 
        prefix | space;
    static constexpr ValueType ps_wp_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        precision | prefix | space;
    static constexpr ValueType ps_wp_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | 
        precision | prefix | space;
    static constexpr ValueType ps_wp_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | precision | prefix | space;
    static constexpr ValueType ps_wp_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | 
        precision | prefix | space;
    static constexpr ValueType ps_wp_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | precision | prefix | space;
    static constexpr ValueType ps_wp_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | precision | 
        prefix | space;
    static constexpr ValueType ps_wp_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | precision | prefix | space;
    static constexpr ValueType ps_wp_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | precision | 
        prefix | space;
    static constexpr ValueType ps_wp_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | precision | prefix | space;
public:
    static constexpr ValueType pz_wp_ldf_double_format =  
        define_double | decimal | fixed | lower | width | precision | prefix | 
        zero;
    static constexpr ValueType pz_wp_ldf_long_double_format = 
        define_long | define_double | decimal | fixed | lower | width | 
        precision | prefix | zero;
    static constexpr ValueType pz_wp_udf_double_format = 
        define_double | decimal | fixed | upper | width | precision | prefix | 
        zero;
    static constexpr ValueType pz_wp_udf_long_double_format = 
        define_long | define_double | decimal | fixed | upper | width | 
        precision | prefix | zero;
    static constexpr ValueType pz_wp_lde_double_format = 
        define_double | decimal | exponent | lower | width | precision | 
        prefix | zero;
    static constexpr ValueType pz_wp_lde_long_double_format = 
        define_long | define_double | decimal | exponent | lower | width |
        precision | prefix | zero;
    static constexpr ValueType pz_wp_ude_double_format = 
        define_double | decimal | exponent | upper | width | precision | 
        prefix | zero;
    static constexpr ValueType pz_wp_ude_long_double_format = 
        define_long | define_double | decimal | exponent | upper | width | 
        precision | prefix | zero;
    static constexpr ValueType pz_wp_ldfe_double_format =  
        define_double | decimal | fixed | exponent| lower | width | 
        precision | prefix | zero;
    static constexpr ValueType pz_wp_ldfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | lower | 
        width | precision | prefix | zero;
    static constexpr ValueType pz_wp_udfe_double_format =  
        define_double | decimal | fixed | exponent| upper | width | 
        precision | prefix | zero;
    static constexpr ValueType pz_wp_udfe_long_double_format = 
        define_long | define_double | decimal | fixed | exponent | upper | 
        width | precision | prefix | zero;
    static constexpr ValueType pz_wp_lhe_double_format = 
        define_double | hexadecimal | exponent | lower | width | precision | 
        prefix | zero;
    static constexpr ValueType pz_wp_lhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | lower | 
        width | precision | prefix | zero;
    static constexpr ValueType pz_wp_uhe_double_format = 
        define_double | hexadecimal | exponent | upper | width | precision |
        prefix | zero;
    static constexpr ValueType pz_wp_uhe_long_double_format = 
        define_long | define_double | hexadecimal | exponent | upper | 
        width | precision | prefix | zero;
public:
    static constexpr ValueType hexadecimal_not_support = hexadecimal | fixed;
private:
    ValueType m_value;
public:
    inline constexpr FloatingPoint();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        FloatingPoint>::value, int>::type = 0>
    inline constexpr FloatingPoint(TArg&& arg, TArgs&& ... args);
public:
    inline ~FloatingPoint() = default;
public:
    inline constexpr FloatingPoint(const FloatingPoint& cpy);
    inline constexpr FloatingPoint(FloatingPoint&& mov);
public:
    inline FloatingPoint& operator=(const FloatingPoint& cpy);
    inline FloatingPoint& operator=(FloatingPoint&& mov);
private:
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<float>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<double>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long double>&&,
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DecimalType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, HexadecimalType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, FixedType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, ExponentType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, LowerType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, UpperType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrefixType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrefixPlusType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrefixSpaceType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrefixZeroType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrecisionType&&, 
        TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr FloatingPoint::FloatingPoint() :
    m_value(_Value(good | define_double | decimal | lower))
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    FloatingPoint>::value, int>::type>
inline constexpr FloatingPoint::FloatingPoint(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good | define_double | decimal | lower, 
        std::forward<TArg>(arg), std::forward<TArgs>(args)...))
{}

inline constexpr FloatingPoint::FloatingPoint(const FloatingPoint& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr FloatingPoint::FloatingPoint(FloatingPoint&& mov) :
    m_value(mov.m_value)
{}

inline FloatingPoint& FloatingPoint::operator=(const FloatingPoint& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline FloatingPoint& FloatingPoint::operator=(FloatingPoint&& mov)
{
    m_value = mov.m_value;
    return *this;
}

inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val)
{
    return ((val & notation_mask) != good) ? val :
        ((val & decimal) ? (val | fixed) : (val | exponent));
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, DefineType<float>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_double, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, DefineType<double>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_double, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, DefineType<long double>&&, 
    TArgs&&... args)
{
    return  _Value(val | (define_long | define_double), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, DecimalType&&, TArgs&&... args)
{
    return _Value((val & ~base_mask) | decimal, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, HexadecimalType&&, 
    TArgs&&... args)
{
    return _Value((val & ~base_mask) | hexadecimal, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, FixedType&&, TArgs&&... args)
{
    return _Value(val | fixed, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, ExponentType&&, TArgs&&... args)
{
    return _Value(val | exponent, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, LowerType&&, TArgs&&... args)
{
    return _Value((val & ~letter_mask) | lower, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, UpperType&&, TArgs&&... args)
{
    return _Value((val & ~letter_mask) | upper, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, PrefixType&&, TArgs&&... args)
{
    return _Value(val | prefix, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, PrefixPlusType&&, 
    TArgs&&... args)
{
    return _Value((val & ~prefix_mask) | (plus | prefix), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, PrefixSpaceType&&, 
    TArgs&&... args)
{
    return _Value((val & ~prefix_mask) | (space | prefix), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, PrefixZeroType&&, TArgs&&... args)
{
    return _Value((val & ~prefix_mask) | (zero | prefix), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value((val | width), std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::_Value(ValueType val, PrecisionType&&, 
    TArgs&&... args)
{
    return _Value((val | precision), std::forward<TArgs>(args)...);
}

inline constexpr typename FloatingPoint::ValueType 
FloatingPoint::GetValue() const
{
    return m_value;
}

} //!flag

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_FLAG_FLOATINGPOINT_H_
