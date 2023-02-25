#ifndef TEST_OUT_PRINT_IMP_STRING_H_
#define TEST_OUT_PRINT_IMP_STRING_H_

#include "../../../System.h"
#include "../../Definition.h"
#include "../String.h"

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

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger,
    typename IInputValue = void>
struct String
{
    
};

} //!imp

} //!print

} //!out

} //!test

#ifndef TEST_OUT_PRINT_IMP_STRING_DLEVEL

#define TEST_OUT_PRINT_IMP_STRING_DLEVEL 2

#endif //!TEST_OUT_PRINT_IMP_STRING_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::type::Value<typename test::out::Definition::FlagType::\
        IntegerValueType, VFlagInteger>,\
    test::sys::dbg::Type<IInputValue>

template<test::out::Definition::FlagType::IntegerValueType VFlagInteger,
    typename IInputValue>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_PRINT_IMP_STRING_DLEVEL, 
    "test::out::print::imp::String", 
    test::out::print::imp::String<VFlagInteger, IInputValue>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace out
{
namespace print
{
namespace imp
{

template<typename TChar, typename TDefinition>
struct String<0, test::Pointer<TChar, TDefinition>>
{
    static const TChar* Get(void* value, std::size_t size)
    {
        auto cast = (test::Pointer<TChar>*)value;
        return &**cast;
    }
};

template<>
struct String<test::out::print::String::char_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<char>
        ValueType;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%s", String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%s", String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::wchar_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<wchar_t>
        ValueType;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%ls", String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%ls", String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::w_char_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<char>
        ValueType;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*s", width, 
            String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*s", width, 
            String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::w_wchar_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<wchar_t>
        ValueType;

    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*ls", width, 
            String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*ls", width, 
            String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::l_char_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<char>
        ValueType;
    
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%.*s", len_pred,
            String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%.*s", len_pred,
            String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::l_wchar_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<wchar_t>
        ValueType;
    
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%.*ls", len_pred,
            String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%.*ls", len_pred,
            String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::wl_char_fmt, void>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<char>
        ValueType;
    
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*.*s", width, len_pred,
            String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*.*s", width, len_pred,
            String<0, ValueType>::Get(value, value_size));
    }
};

template<>
struct String<test::out::print::String::wl_wchar_fmt>
{
    typedef typename test::out::Definition::FlagType FlagType;

    template<typename TChar>
    using OutputInterfaceType = 
        test::out::Definition::OutputInterfaceType<TChar>;

    typedef typename test::out::Definition::StringPointerType<wchar_t>
        ValueType;
    
    static std::size_t Output(OutputInterfaceType<char>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print("%*.*ls", width, len_pred,
            String<0, ValueType>::Get(value, value_size));
    }

    static std::size_t Output(OutputInterfaceType<wchar_t>& out, 
        void* value, std::size_t value_size, FlagType flag, 
        int width, int len_pred)
    {
        return out.Print(L"%*.*ls", width, len_pred,
            String<0, ValueType>::Get(value, value_size));
    }
};

} //!imp

} //!print

} //!out

} //!test

#endif //!TEST_OUT_PRINT_IMP_STRING_H_
