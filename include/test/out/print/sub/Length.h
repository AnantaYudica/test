#ifndef TEST_OUT_PRINT_SUB_LENGTH_H_
#define TEST_OUT_PRINT_SUB_LENGTH_H_

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

struct Length
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;
    
    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_sub_length}.GetValue();
    
    enum : IntegerValueType
    {
        len_fmt = FlagType{FlagType::specifier_sub_length}.GetValue()
    };
};

} //!sub

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_SUB_LENGTH_DLEVEL

#define TEST_OUT_PRINT_SUB_LENGTH_DLEVEL 2

#endif //!TEST_OUT_PRINT_SUB_LENGTH_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_SUB_LENGTH_DLEVEL, 
    "test::out::print::sub::Length", test::out::print::sub::Length);

#endif //!TEST_OUT_PRINT_SUB_LENGTH_H_
