#ifndef TEST_OUT_PRINT_IMP_SUB_LENGTH_H_
#define TEST_OUT_PRINT_IMP_SUB_LENGTH_H_

#include "../../../../System.h"
#include "../../../Definition.h"
#include "../../../CString.h"
#include "../../../fmt/Flag.h"
#include "../../sub/Length.h"

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
namespace imp
{
namespace sub
{

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger>
struct Length
{
    
};

} //!sub

} //!imp

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_IMP_SUB_LENGTH_DLEVEL

#define TEST_OUT_PRINT_IMP_SUB_LENGTH_DLEVEL 2

#endif //!TEST_OUT_PRINT_IMP_SUB_LENGTH_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<typename test::out::Definition::FlagType::\
        IntegerValueType, VFlagInteger>

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_PRINT_IMP_SUB_LENGTH_DLEVEL, 
    "test::out::print::imp::sub::Length", 
    test::out::print::imp::sub::Length<VFlagInteger>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace out
{
namespace print
{
namespace imp
{
namespace sub
{

template<>
struct Length<test::out::print::sub::Length::len_fmt>
{
    typedef test::out::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType IntegerValueType;
    
    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    template<typename TChar>
    using FormatOutputFuncType = 
        test::out::Definition::FormatOutputFuncType<TChar>;

    static std::size_t Output(FormatOutputFuncType<char> fmt_out, 
        OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        if (fmt_out == nullptr) return 0;

        test::out::CString<char> tmp;
        const std::size_t size = (*fmt_out)(tmp, value, value_size, flag, 
            width, len_pred);
        if (size <= len_pred)
        {
            return out.Print("%s", *(tmp.Get()));
        }
        return out.Print("%.*s", len_pred, *(tmp.Get()));
    }
    
    static std::size_t Output(FormatOutputFuncType<char> fmt_out, 
        OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        if (fmt_out == nullptr) return 0;
        
        test::out::CString<char> tmp;
        const std::size_t size = (*fmt_out)(tmp, value, value_size, flag, 
            width, len_pred);
        if (size <= len_pred)
        {
            return out.Print(L"%s", *(tmp.Get()));
        }
        return out.Print(L"%.*s", len_pred, *(tmp.Get()));
    }

    static std::size_t Output(FormatOutputFuncType<wchar_t> fmt_out, 
        OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        if (fmt_out == nullptr) return 0;
        
        test::out::CString<wchar_t> tmp;
        const std::size_t size = (*fmt_out)(tmp, value, value_size, flag, 
            width, len_pred);
        if (size <= len_pred)
        {
            return out.Print(L"%ls", *(tmp.Get()));
        }
        return out.Print(L"%.*ls", len_pred, *(tmp.Get()));
    }
};

} //!sub

} //!imp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_IMP_SUB_LENGTH_H_
