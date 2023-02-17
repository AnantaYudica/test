#ifndef TEST_OUT_PRINT_CHARACTER_H_
#define TEST_OUT_PRINT_CHARACTER_H_

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

struct Character
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_ch | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<char>{}}.GetValue() |
        FlagType{FlagType::specifier_ch | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue();
    
    enum : IntegerValueType
    {
        char_fmt = FlagType{FlagType::specifier_ch, 
            test::out::fmt::flag::Define<char>{}}.GetValue(),
        w_char_fmt = FlagType{FlagType::specifier_ch | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<char>{}}.GetValue(),
        wchar_fmt = FlagType{FlagType::specifier_ch, 
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue(),
        w_wchar_fmt = FlagType{FlagType::specifier_ch | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<wchar_t>{}}.GetValue()
    };
};

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_CHARACTER_DLEVEL

#define TEST_OUT_PRINT_CHARACTER_DLEVEL 2

#endif //!TEST_OUT_PRINT_CHARACTER_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_CHARACTER_DLEVEL, 
    "test::out::print::Character", test::out::print::Character);


#endif //!TEST_OUT_PRINT_CHARACTER_H_
