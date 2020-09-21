#ifndef TEST_OUT_PRINT_CHARACTER_H_
#define TEST_OUT_PRINT_CHARACTER_H_

#include "../fmt/Flag.h"

#include <cstddef>

namespace test
{
namespace out
{
namespace print
{

struct Character
{
    typedef test::out::fmt::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;
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

#endif //!TEST_OUT_PRINT_CHARACTER_H_
