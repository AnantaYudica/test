#ifndef TEST_OUT_PRINT_BOOLEAN_H_
#define TEST_OUT_PRINT_BOOLEAN_H_

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

struct Boolean
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_bool | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<bool>{}}.GetValue();
    
    enum : IntegerValueType
    {
        bool_fmt = FlagType{FlagType::specifier_bool, 
            test::out::fmt::flag::Define<bool>{}}.GetValue(),
        w_bool_fmt = FlagType{FlagType::specifier_bool | 
            FlagType::specifier_sub_width,
            test::out::fmt::flag::Define<bool>{}}.GetValue()
    };
};

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_CHARACTER_DLEVEL

#define TEST_OUT_PRINT_CHARACTER_DLEVEL 2

#endif //!TEST_OUT_PRINT_CHARACTER_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_CHARACTER_DLEVEL, 
    "test::out::print::Boolean", test::out::print::Boolean);


#endif //!TEST_OUT_PRINT_BOOLEAN_H_
