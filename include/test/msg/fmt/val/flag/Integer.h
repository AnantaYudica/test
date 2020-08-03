#ifndef TEST_MSG_FMT_VAL_FLAG_INTEGER_H_
#define TEST_MSG_FMT_VAL_FLAG_INTEGER_H_

#include "../../arg/Define.h"
#include "../../arg/Signed.h"
#include "../../arg/Unsigned.h"
#include "../../arg/Decimal.h"
#include "../../arg/Octal.h"
#include "../../arg/Hexadecimal.h"
#include "../../arg/Lower.h"
#include "../../arg/Upper.h"
#include "../../arg/Prefix.h"
#include "../../arg/PrefixPlus.h"
#include "../../arg/PrefixSpace.h"
#include "../../arg/PrefixZero.h"
#include "../../arg/Width.h"
#include "../../arg/Length.h"

#include <cstdint>
#include <type_traits>
#include <utility>

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

class Integer
{
public:
    typedef std::uint32_t ValueType;
    template<typename T>
    using DefineType = test::msg::fmt::arg::Define<T>;
    typedef test::msg::fmt::arg::Signed SignedType;
    typedef test::msg::fmt::arg::Unsigned UnsignedType;
    typedef test::msg::fmt::arg::Decimal DecimalType;
    typedef test::msg::fmt::arg::Octal OctalType;
    typedef test::msg::fmt::arg::Hexadecimal HexadecimalType;
    typedef test::msg::fmt::arg::Lower LowerType;
    typedef test::msg::fmt::arg::Upper UpperType;
    typedef test::msg::fmt::arg::Prefix PrefixType;
    typedef test::msg::fmt::arg::PrefixPlus PrefixPlusType;
    typedef test::msg::fmt::arg::PrefixSpace PrefixSpaceType;
    typedef test::msg::fmt::arg::PrefixZero PrefixZeroType;
    typedef test::msg::fmt::arg::Width WidthType;
    typedef test::msg::fmt::arg::Length LengthType;
public:
    enum : ValueType
    {
        good = 0,
        define_signed = 1 << 1,
        define_unsigned = 1 << 2,
        define_char = 1 << 3,
        define_short = 1 << 4,
        define_int = 1 << 5,
        define_long = 1 << 6,
        define_long_long = 1 << 7,
        signed_integer = 1 << 8,
        unsigned_integer = 1 << 9,
        decimal = 1 << 10,
        octal = 1 << 11,
        hexadecimal = 1 << 12,
        lower = 1 << 13,
        upper = 1 << 14,
        prefix = 1 << 15,
        plus = 1 << 16,
        space = 1 << 17,
        zero = 1 << 18,
        width = 1 << 19,
        length =  1 << 20
    };
private:
    static constexpr ValueType define_flag_mask = 
        define_signed | define_unsigned;
    static constexpr ValueType define_type_mask = define_char | define_short |
        define_int | define_long | define_long_long;
    static constexpr ValueType define_mask = 
        define_flag_mask | define_type_mask;
    static constexpr ValueType flag_integer_mask = 
        signed_integer | unsigned_integer;
    static constexpr ValueType base_mask = 
        decimal | hexadecimal | octal;
    static constexpr ValueType letter_mask = lower | upper;
    static constexpr ValueType prefix_mask = prefix| plus | space | zero;
public:
    static constexpr ValueType lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower;
    static constexpr ValueType lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower;
    static constexpr ValueType lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower;
    static constexpr ValueType lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower;
    static constexpr ValueType lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower;
    static constexpr ValueType lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower;
    static constexpr ValueType lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower;
    static constexpr ValueType lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower;
    static constexpr ValueType lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower;
    static constexpr ValueType lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | lower;
public:
    static constexpr ValueType ldu_char_format = 
        define_signed | define_char | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_short_format = 
        define_signed | define_short | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_int_format = 
        define_signed | define_int | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_long_format = 
        define_signed | define_long | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | decimal | lower;
    static constexpr ValueType ldu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | decimal | 
        lower;
public:
    static constexpr ValueType lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower;
    static constexpr ValueType lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower;
    static constexpr ValueType lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower;
    static constexpr ValueType lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower;
    static constexpr ValueType lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower;
    static constexpr ValueType lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower;
    static constexpr ValueType lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower;
    static constexpr ValueType lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower;
    static constexpr ValueType lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower;
    static constexpr ValueType lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | lower;
public:  
    static constexpr ValueType lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower;
    static constexpr ValueType lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower;
    static constexpr ValueType lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | lower;
    static constexpr ValueType lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower;
public:   
    static constexpr ValueType uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper;
    static constexpr ValueType uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper;
    static constexpr ValueType uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | upper;
    static constexpr ValueType uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper;
public:
    static constexpr ValueType p__lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | prefix;
    static constexpr ValueType p__lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        prefix;
    static constexpr ValueType p__lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | prefix;
public:  
    static constexpr ValueType p__lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        prefix;
    static constexpr ValueType p__lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | prefix;
    static constexpr ValueType p__lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        prefix;
    static constexpr ValueType p__lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        prefix;
    static constexpr ValueType p__lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | prefix;
    static constexpr ValueType p__lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | prefix;
    static constexpr ValueType p__lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | prefix;
    static constexpr ValueType p__lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | prefix;
    static constexpr ValueType p__lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | prefix;
    static constexpr ValueType p__lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | prefix;
public:   
    static constexpr ValueType p__uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        prefix;
    static constexpr ValueType p__uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | prefix;
    static constexpr ValueType p__uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        prefix;
    static constexpr ValueType p__uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        prefix;
    static constexpr ValueType p__uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | prefix;
    static constexpr ValueType p__uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | prefix;
    static constexpr ValueType p__uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | prefix;
    static constexpr ValueType p__uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | prefix;
    static constexpr ValueType p__uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | prefix;
    static constexpr ValueType p__uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | prefix;
public:
    static constexpr ValueType pp__lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        prefix | plus;
    static constexpr ValueType pp__lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | prefix | plus;
public:
    static constexpr ValueType ps__lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        prefix | space;
    static constexpr ValueType ps__lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | prefix | space;
public:
    static constexpr ValueType pz__lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | prefix | zero;
public:
    static constexpr ValueType pz__ldu_char_format = 
        define_signed | define_char | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_short_format = 
        define_signed | define_short | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_int_format = 
        define_signed | define_int | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_long_format = 
        define_signed | define_long | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | decimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__ldu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | decimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__ldu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | decimal | 
        lower | prefix | zero;
public:
    static constexpr ValueType pz__lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | prefix | zero;
public:  
    static constexpr ValueType pz__lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        prefix | zero;
    static constexpr ValueType pz__lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
    static constexpr ValueType pz__lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | prefix | zero;
public:   
    static constexpr ValueType pz__uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        prefix | zero;
    static constexpr ValueType pz__uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
    static constexpr ValueType pz__uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        prefix | zero;
    static constexpr ValueType pz__uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        prefix | zero;
    static constexpr ValueType pz__uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
    static constexpr ValueType pz__uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
    static constexpr ValueType pz__uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
    static constexpr ValueType pz__uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
    static constexpr ValueType pz__uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
    static constexpr ValueType pz__uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | prefix | zero;
public:
    static constexpr ValueType w_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | width;
    static constexpr ValueType w_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | width;
    static constexpr ValueType w_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width;
    static constexpr ValueType w_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width;
public:
    static constexpr ValueType w_ldu_char_format = 
        define_signed | define_char | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_short_format = 
        define_signed | define_short | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_int_format = 
        define_signed | define_int | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_long_format = 
        define_signed | define_long | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | decimal | 
        lower | width;
    static constexpr ValueType w_ldu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | decimal | lower | 
        width;
    static constexpr ValueType w_ldu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | decimal | 
        lower | width;
public:
    static constexpr ValueType w_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | width;
    static constexpr ValueType w_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        width;
    static constexpr ValueType w_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | width;
    static constexpr ValueType w_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | width;
    static constexpr ValueType w_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        width;
    static constexpr ValueType w_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        width;
    static constexpr ValueType w_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        width;
    static constexpr ValueType w_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        width;
    static constexpr ValueType w_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        width;
    static constexpr ValueType w_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | width;
public:  
    static constexpr ValueType w_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        width;
    static constexpr ValueType w_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | width;
    static constexpr ValueType w_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        width;
    static constexpr ValueType w_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        width;
    static constexpr ValueType w_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | width;
    static constexpr ValueType w_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | width;
    static constexpr ValueType w_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | width;
    static constexpr ValueType w_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | width;
    static constexpr ValueType w_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | width;
    static constexpr ValueType w_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | width;
public:   
    static constexpr ValueType w_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        width;
    static constexpr ValueType w_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | width;
    static constexpr ValueType w_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        width;
    static constexpr ValueType w_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        width;
    static constexpr ValueType w_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | width;
    static constexpr ValueType w_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | width;
    static constexpr ValueType w_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | width;
    static constexpr ValueType w_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | width;
    static constexpr ValueType w_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | width;
    static constexpr ValueType w_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | width;
public:
    static constexpr ValueType p_w_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | width | prefix;
public:  
    static constexpr ValueType p_w_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | width | prefix;
    static constexpr ValueType p_w_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        width | prefix;
    static constexpr ValueType p_w_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | prefix;
    static constexpr ValueType p_w_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | width | prefix;
    static constexpr ValueType p_w_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | width | prefix;
    static constexpr ValueType p_w_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | width | prefix;
    static constexpr ValueType p_w_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | width | prefix;
    static constexpr ValueType p_w_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | prefix;
public:   
    static constexpr ValueType p_w_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        width | prefix;
    static constexpr ValueType p_w_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | width | prefix;
    static constexpr ValueType p_w_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        width | prefix;
    static constexpr ValueType p_w_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        width | prefix;
    static constexpr ValueType p_w_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | prefix;
    static constexpr ValueType p_w_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | width | prefix;
    static constexpr ValueType p_w_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | width | prefix;
    static constexpr ValueType p_w_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | width | prefix;
    static constexpr ValueType p_w_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | width | prefix;
    static constexpr ValueType p_w_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | prefix;
public:
    static constexpr ValueType pp_w_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width | prefix | plus;
    static constexpr ValueType pp_w_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width | prefix | plus;
public:
    static constexpr ValueType ps_w_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width | prefix | space;
    static constexpr ValueType ps_w_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width | prefix | space;
public:
    static constexpr ValueType pz_w_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width | prefix | zero;
public:
    static constexpr ValueType pz_w_ldu_char_format = 
        define_signed | define_char | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_short_format = 
        define_signed | define_short | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_int_format = 
        define_signed | define_int | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_long_format = 
        define_signed | define_long | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | decimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_ldu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | decimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_ldu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | decimal | 
        lower | width | prefix | zero;
public:
    static constexpr ValueType pz_w_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | width | prefix | zero;
public:  
    static constexpr ValueType pz_w_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        width | prefix | zero;
    static constexpr ValueType pz_w_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
    static constexpr ValueType pz_w_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | prefix | zero;
public:   
    static constexpr ValueType pz_w_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        width | prefix | zero;
    static constexpr ValueType pz_w_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        width | prefix | zero;
    static constexpr ValueType pz_w_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        width | prefix | zero;
    static constexpr ValueType pz_w_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
    static constexpr ValueType pz_w_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | prefix | zero;
public:
    static constexpr ValueType l_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | length;
    static constexpr ValueType l_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        length;
    static constexpr ValueType l_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | length;
public:
    static constexpr ValueType l_ldu_char_format = 
        define_signed | define_char | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_short_format = 
        define_signed | define_short | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_int_format = 
        define_signed | define_int | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_long_format = 
        define_signed | define_long | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | decimal | 
        lower | length;
    static constexpr ValueType l_ldu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | decimal | lower | 
        length;
    static constexpr ValueType l_ldu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | decimal | 
        lower | length;
public:
    static constexpr ValueType l_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | length;
    static constexpr ValueType l_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        length;
    static constexpr ValueType l_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | length;
public:  
    static constexpr ValueType l_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        length;
    static constexpr ValueType l_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | length;
    static constexpr ValueType l_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        length;
    static constexpr ValueType l_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        length;
    static constexpr ValueType l_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | length;
    static constexpr ValueType l_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | length;
    static constexpr ValueType l_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | length;
    static constexpr ValueType l_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | length;
    static constexpr ValueType l_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | length;
    static constexpr ValueType l_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | length;
public:   
    static constexpr ValueType l_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        length;
    static constexpr ValueType l_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | length;
    static constexpr ValueType l_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        length;
    static constexpr ValueType l_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        length;
    static constexpr ValueType l_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | length;
    static constexpr ValueType l_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | length;
    static constexpr ValueType l_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | length;
    static constexpr ValueType l_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | length;
    static constexpr ValueType l_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | length;
    static constexpr ValueType l_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | length;
public:
    static constexpr ValueType p_l_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | length | prefix;
public:  
    static constexpr ValueType p_l_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | length | prefix;
    static constexpr ValueType p_l_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        length | prefix;
    static constexpr ValueType p_l_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | length | prefix;
    static constexpr ValueType p_l_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | length | prefix;
    static constexpr ValueType p_l_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | length | prefix;
    static constexpr ValueType p_l_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | length | prefix;
    static constexpr ValueType p_l_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | length | prefix;
    static constexpr ValueType p_l_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | length | prefix;
public:   
    static constexpr ValueType p_l_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        length | prefix;
    static constexpr ValueType p_l_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | length | prefix;
    static constexpr ValueType p_l_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        length | prefix;
    static constexpr ValueType p_l_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        length | prefix;
    static constexpr ValueType p_l_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | length | prefix;
    static constexpr ValueType p_l_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | length | prefix;
    static constexpr ValueType p_l_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | length | prefix;
    static constexpr ValueType p_l_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | length | prefix;
    static constexpr ValueType p_l_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | length | prefix;
    static constexpr ValueType p_l_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | length | prefix;
public:
    static constexpr ValueType pp_l_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        length | prefix | plus;
    static constexpr ValueType pp_l_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | length | prefix | plus;
public:
    static constexpr ValueType ps_l_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        length | prefix | space;
    static constexpr ValueType ps_l_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | length | prefix | space;
public:
    static constexpr ValueType wl_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width | length;
public:
    static constexpr ValueType wl_ldu_char_format = 
        define_signed | define_char | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_short_format = 
        define_signed | define_short | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_int_format = 
        define_signed | define_int | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_long_format = 
        define_signed | define_long | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | decimal | 
        lower | width | length;
    static constexpr ValueType wl_ldu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | decimal | lower | 
        width | length;
    static constexpr ValueType wl_ldu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | decimal | 
        lower | width | length;
public:
    static constexpr ValueType wl_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        width | length;
    static constexpr ValueType wl_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | width | length;
public:  
    static constexpr ValueType wl_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        width | length;
    static constexpr ValueType wl_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | width | length;
    static constexpr ValueType wl_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        width | length;
    static constexpr ValueType wl_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        width | length;
    static constexpr ValueType wl_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | length;
    static constexpr ValueType wl_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | width | length;
    static constexpr ValueType wl_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | width | length;
    static constexpr ValueType wl_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | width | length;
    static constexpr ValueType wl_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | width | length;
    static constexpr ValueType wl_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | length;
public:   
    static constexpr ValueType wl_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        width | length;
    static constexpr ValueType wl_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | width | length;
    static constexpr ValueType wl_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        width | length;
    static constexpr ValueType wl_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        width | length;
    static constexpr ValueType wl_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | length;
    static constexpr ValueType wl_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | width | length;
    static constexpr ValueType wl_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | width | length;
    static constexpr ValueType wl_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | width | length;
    static constexpr ValueType wl_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | width | length;
    static constexpr ValueType wl_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | length;
public:
    static constexpr ValueType p_wl_lou_char_format = 
        define_signed | define_char | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_short_format = 
        define_signed | define_short | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_int_format = 
        define_signed | define_int | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_long_format = 
        define_signed | define_long | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_long_long_format = 
        define_signed | define_long_long | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | octal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lou_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | octal | 
        lower | width | length | prefix;
public:  
    static constexpr ValueType p_wl_lhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
    static constexpr ValueType p_wl_lhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | lower | 
        width | length | prefix;
    static constexpr ValueType p_wl_lhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
    static constexpr ValueType p_wl_lhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
    static constexpr ValueType p_wl_lhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
    static constexpr ValueType p_wl_lhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
    static constexpr ValueType p_wl_lhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
    static constexpr ValueType p_wl_lhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        lower | width | length | prefix;
public:   
    static constexpr ValueType p_wl_uhu_char_format = 
        define_signed | define_char | unsigned_integer | hexadecimal | upper | 
        width | length | prefix;
    static constexpr ValueType p_wl_uhu_short_format = 
        define_signed | define_short | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
    static constexpr ValueType p_wl_uhu_int_format = 
        define_signed | define_int | unsigned_integer | hexadecimal | upper | 
        width | length | prefix;
    static constexpr ValueType p_wl_uhu_long_format = 
        define_signed | define_long | unsigned_integer | hexadecimal | upper | 
        width | length | prefix;
    static constexpr ValueType p_wl_uhu_long_long_format = 
        define_signed | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
    static constexpr ValueType p_wl_uhu_unsigned_char_format = 
        define_unsigned | define_char | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
    static constexpr ValueType p_wl_uhu_unsigned_short_format = 
        define_unsigned | define_short | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
    static constexpr ValueType p_wl_uhu_unsigned_int_format = 
        define_unsigned | define_int | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
    static constexpr ValueType p_wl_uhu_unsigned_long_format = 
        define_unsigned | define_long | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
    static constexpr ValueType p_wl_uhu_unsigned_long_long_format = 
        define_unsigned | define_long_long | unsigned_integer | hexadecimal | 
        upper | width | length | prefix;
public:
    static constexpr ValueType pp_wl_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width | length | prefix | plus;
    static constexpr ValueType pp_wl_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width | length | prefix | plus;
public:
    static constexpr ValueType ps_wl_lds_char_format = 
        define_signed | define_char | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_short_format =
        define_signed | define_short | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_int_format = 
        define_signed | define_int | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_long_format =
        define_signed | define_long | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_long_long_format =
        define_signed |  define_long_long | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_unsigned_char_format =
        define_unsigned | define_char | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_unsigned_short_format =
        define_unsigned | define_short | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_unsigned_int_format =
        define_unsigned | define_int | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_unsigned_long_format =
        define_unsigned | define_long | signed_integer | decimal | lower | 
        width | length | prefix | space;
    static constexpr ValueType ps_wl_lds_unsigned_long_long_format =
        define_unsigned | define_long_long | signed_integer | decimal | 
        lower | width | length | prefix | space;
public:
    static constexpr ValueType signed_octal_not_support = 
        signed_integer | octal;
    static constexpr ValueType signed_hexadecimal_not_support = 
        signed_integer | hexadecimal;
    static constexpr ValueType decimal_upper_not_support = 
        decimal | upper;
    static constexpr ValueType octal_upper_not_support = 
        octal | upper;
    static constexpr ValueType prefix_decimal_not_support_mask =
        decimal | prefix | plus | space | zero;
    static constexpr ValueType prefix_decimal_not_support =
        decimal | prefix;
    static constexpr ValueType prefix_plus_unsigned_not_support =
        unsigned_integer | plus;
    static constexpr ValueType prefix_space_unsigned_not_support =
        unsigned_integer | space;
    static constexpr ValueType prefix_zero_length_not_support =
        length | zero;
private:
    ValueType m_value;
public:
    inline constexpr Integer();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        Integer>::value, int>::type = 0>
    inline constexpr Integer(TArg&& arg, TArgs&& ... args);
public:
    inline ~Integer() = default;
public:
    inline constexpr Integer(const Integer& cpy);
    inline constexpr Integer(Integer&& mov);
public:
    inline Integer& operator=(const Integer& cpy);
    inline Integer& operator=(Integer&& mov);
private:
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<signed char>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<char>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned char>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<short>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned short>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<int>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned int>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned long>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long long>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned long long>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, SignedType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, UnsignedType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DecimalType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, OctalType&&, 
        TArgs&&... args);  
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, HexadecimalType&&, 
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
    inline constexpr ValueType _Value(ValueType val, LengthType&&, 
        TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Integer::Integer() :
    m_value(_Value(define_signed | define_int | decimal | lower))
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    Integer>::value, int>::type>
inline constexpr Integer::Integer(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(define_signed | define_int | decimal | 
        lower, std::forward<TArg>(arg), std::forward<TArgs>(args)...))
{}

inline constexpr Integer::Integer(const Integer& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr Integer::Integer(Integer&& mov) :
    m_value(mov.m_value)
{}

inline Integer& Integer::operator=(const Integer& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline Integer& Integer::operator=(Integer&& mov)
{
    m_value = mov.m_value;
    return *this;
}

inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val)
{
    return ((val & flag_integer_mask) != good ? val : 
        ((val & decimal) ? (val | signed_integer) : (val | unsigned_integer)));
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<signed char>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_char | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<char>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_char | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<unsigned char>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_char | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<short>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_short | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<unsigned short>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_short | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<int>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_int | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<unsigned int>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_int | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<long>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<unsigned long>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<long long>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long_long | define_signed),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DefineType<unsigned long long>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | (define_long_long | define_unsigned),
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, SignedType&&, TArgs&&... args)
{
    return _Value((val & ~flag_integer_mask) | signed_integer, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, UnsignedType&&, TArgs&&... args)
{
    return _Value((val & ~flag_integer_mask) | unsigned_integer, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, DecimalType&&, TArgs&&... args)
{
    return _Value((val & ~base_mask) | decimal, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, OctalType&&, TArgs&&... args)
{
    return _Value((val & ~base_mask) | octal, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, HexadecimalType&&, TArgs&&... args)
{
    return _Value((val & ~base_mask) | hexadecimal, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, LowerType&&, TArgs&&... args)
{
    return _Value((val & ~letter_mask) | lower, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, UpperType&&, TArgs&&... args)
{
    return _Value((val & ~letter_mask) | upper, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, PrefixType&&, TArgs&&... args)
{
    return _Value(val | prefix, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, PrefixPlusType&&, TArgs&&... args)
{
    return _Value((val & ~prefix_mask) | (plus | prefix), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, PrefixSpaceType&&, TArgs&&... args)
{
    return _Value((val & ~prefix_mask) | (space | prefix), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, PrefixZeroType&&, TArgs&&... args)
{
    return _Value((val & ~prefix_mask) | (zero | prefix), 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value((val | width), std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Integer::ValueType 
Integer::_Value(ValueType val, LengthType&&, TArgs&&... args)
{
    return _Value((val | length), std::forward<TArgs>(args)...);
}

inline constexpr typename Integer::ValueType Integer::GetValue() const
{
    return m_value;
}

} //!flag

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_FLAG_INTEGER_H_
