#ifndef TEST_OUT_PRINT_IMP_POINTER_H_
#define TEST_OUT_PRINT_IMP_POINTER_H_

#include "../../../System.h"
#include "../../Definition.h"
#include "../Pointer.h"

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
struct Pointer
{
    
};

} //!imp

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_IMP_POINTER_DLEVEL

#define TEST_OUT_PRINT_IMP_POINTER_DLEVEL 2

#endif //!TEST_OUT_PRINT_IMP_POINTER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<typename test::out::Definition::FlagType::\
        IntegerValueType, VFlagInteger>

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_PRINT_IMP_POINTER_DLEVEL, 
    "test::out::print::imp::Pointer", 
    test::out::print::imp::Pointer<VFlagInteger>);

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
struct Pointer<test::out::print::Pointer::ptr_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%p", value);
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%p", value);
    }
};

template<>
struct Pointer<test::out::print::Pointer::w_ptr_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*p", width, value);
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*p", width, value);
    }
};

template<>
struct Pointer<test::out::print::Pointer::l_ptr_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%.*p", len_pred, value);
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%.*p", len_pred, value);
    }
};

template<>
struct Pointer<test::out::print::Pointer::wl_ptr_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*.*p", width, len_pred, value);
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*.*p", width, len_pred, value);
    }
};

} //!imp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_IMP_POINTER_H_
