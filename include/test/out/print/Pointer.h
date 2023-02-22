#ifndef TEST_OUT_PRINT_POINTER_H_
#define TEST_OUT_PRINT_POINTER_H_

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

struct Pointer
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_ptr |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length}.GetValue();
    
    enum : IntegerValueType
    {
        ptr_fmt = FlagType{FlagType::specifier_ptr}.GetValue(),
        w_ptr_fmt = FlagType{FlagType::specifier_ptr | 
            FlagType::specifier_sub_width}.GetValue(),
        l_ptr_fmt = FlagType{FlagType::specifier_ptr | 
            FlagType::specifier_sub_length}.GetValue(),
        wl_ptr_fmt = FlagType{FlagType::specifier_ptr |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length}.GetValue()
    };
};

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_POINTER_DLEVEL

#define TEST_OUT_PRINT_POINTER_DLEVEL 2

#endif //!TEST_OUT_PRINT_POINTER_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_POINTER_DLEVEL, 
    "test::out::print::Pointer", test::out::print::Pointer);


#endif //!TEST_OUT_PRINT_POINTER_H_
