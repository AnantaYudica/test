#ifndef TEST_OUT_PRINT_IMP_BOOLEAN_H_
#define TEST_OUT_PRINT_IMP_BOOLEAN_H_

#include "../../../System.h"
#include "../../../def/cstr/val/Boolean.h"
#include "../../Definition.h"
#include "../Boolean.h"

#include <cstddef>
#include <cwchar>

namespace test
{
namespace out
{
namespace print
{
namespace imp
{

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger>
struct Boolean
{
    
};

} //!imp

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_IMP_BOOLEAN_DLEVEL

#define TEST_OUT_PRINT_IMP_BOOLEAN_DLEVEL 2

#endif //!TEST_OUT_PRINT_IMP_BOOLEAN_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<typename test::out::Definition::FlagType::\
        IntegerValueType, VFlagInteger>

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_PRINT_IMP_BOOLEAN_DLEVEL, 
    "test::out::print::imp::Boolean", 
    test::out::print::imp::Boolean<VFlagInteger>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace out
{
namespace print
{
namespace imp
{

template<>
struct Boolean<test::out::print::Boolean::bool_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%s", *(test::def::cstr::val::
            Boolean::CStr<char>(*((bool*)value))));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%ls", *(test::def::cstr::val::
            Boolean::CStr<wchar_t>(*((bool*)value))));
    }
};

template<>
struct Boolean<test::out::print::Boolean::w_bool_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*s", width, *(test::def::cstr::val::
            Boolean::CStr<char>(*((bool*)value))));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*ls", width, *(test::def::cstr::val::
            Boolean::CStr<wchar_t>(*((bool*)value))));
    }
};

} //!imp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_IMP_BOOLEAN_H_
