#ifndef TEST_OUT_PRINT_SUB_WIDTH_H_
#define TEST_OUT_PRINT_SUB_WIDTH_H_

#include "../../../System.h"
#include "../../Definition.h"
#include "../../fmt/Flag.h"

#include <cmath>
#include <cwchar>
#include <cstddef>
#include <type_traits>

namespace test
{
namespace out
{
namespace print
{
namespace sub
{

struct Width
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
    
    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_sub_width |
            FlagType::specifier_sub_length}.GetValue();
    
    enum : IntegerValueType
    {
        w_fmt = FlagType{FlagType::specifier_sub_width}.GetValue(),
        l_w_fmt = FlagType{FlagType::specifier_sub_width |
            FlagType::specifier_sub_length}.GetValue(),
    };
};

} //!sub

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_SUB_WIDTH_DLEVEL

#define TEST_OUT_PRINT_SUB_WIDTH_DLEVEL 2

#endif //!TEST_OUT_PRINT_SUB_WIDTH_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_SUB_WIDTH_DLEVEL, 
    "test::out::print::sub::Width", test::out::print::sub::Width);

#endif //!TEST_OUT_PRINT_SUB_WIDTH_H_
