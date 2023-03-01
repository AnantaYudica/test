#ifndef TEST_OUT_PRINT_OBJECT_H_
#define TEST_OUT_PRINT_OBJECT_H_

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

struct Object
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;
    
    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static constexpr IntegerValueType MaskValue =
        FlagType{FlagType::specifier_object |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length}.GetValue();
    
    enum : IntegerValueType
    {
        obj_fmt = FlagType{FlagType::specifier_object}.GetValue(),
        w_obj_fmt = FlagType{FlagType::specifier_object |
            FlagType::specifier_sub_width}.GetValue(),
        l_obj_fmt = FlagType{FlagType::specifier_object |
            FlagType::specifier_sub_length}.GetValue(),
        wl_obj_fmt = FlagType{FlagType::specifier_object |
            FlagType::specifier_sub_width |
            FlagType::specifier_sub_length}.GetValue(),
    };
};

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_OBJECT_DLEVEL

#define TEST_OUT_PRINT_OBJECT_DLEVEL 2

#endif //!TEST_OUT_PRINT_OBJECT_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_PRINT_OBJECT_DLEVEL, 
    "test::out::print::Object", test::out::print::Object);

#endif //!TEST_OUT_PRINT_OBJECT_H_
