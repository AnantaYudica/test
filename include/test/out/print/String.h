#ifndef TEST_OUT_PRINT_STRING_H_
#define TEST_OUT_PRINT_STRING_H_

#include "../../System.h"
#include "../fmt/Flag.h"
#include "../Definition.h"

#include <cstddef>

namespace test
{
namespace out
{
namespace print
{

struct String
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_str |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length,
            test::out::fmt::flag::Define<char>{}}.GetValue() |
        FlagType{FlagType::specifier_str |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue();
    
    enum : IntegerValueType
    {
        char_fmt = FlagType{FlagType::specifier_str,
            test::out::fmt::flag::Define<char>{}}.GetValue(),
        wchar_fmt = FlagType{FlagType::specifier_str,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue(),
        w_char_fmt = FlagType{FlagType::specifier_str | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<char>{}}.GetValue(),
        w_wchar_fmt = FlagType{FlagType::specifier_str | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue(),
        l_char_fmt = FlagType{FlagType::specifier_str | 
            FlagType::specifier_sub_length,
            test::out::fmt::flag::Define<char>{}}.GetValue(),
        l_wchar_fmt = FlagType{FlagType::specifier_str | 
            FlagType::specifier_sub_length,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue(),
        wl_char_fmt = FlagType{FlagType::specifier_str |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length,
            test::out::fmt::flag::Define<char>{}}.GetValue(),
        wl_wchar_fmt = FlagType{FlagType::specifier_str |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue()
    };
};

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_STRING_DLEVEL

#define TEST_OUT_PRINT_STRING_DLEVEL 2

#endif //!TEST_OUT_PRINT_STRING_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_STRING_DLEVEL, 
    "test::out::print::String", test::out::print::String);


#endif //!TEST_OUT_PRINT_STRING_H_
