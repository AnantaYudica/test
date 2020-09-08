#ifndef TEST_MSG_FMT_VAL_SPECIFIER_PRINT_POINTER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_PRINT_POINTER_H_

#include "../../flag/Pointer.h"
#include "../../Specifier.h"
#include "../../Width.h"

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{
namespace specifier
{
namespace print
{

template<typename TChar, int FlagValue>
class Pointer
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef void* ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Pointer() = delete;
};

template<typename TChar>
class Pointer<TChar, test::msg::fmt::val::flag::Pointer::pointer_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef void* ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Pointer() = delete;
};

template<typename TChar>
class Pointer<TChar, test::msg::fmt::val::flag::Pointer::w_pointer_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef void* ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Pointer() = delete;
};

template<typename TChar, int FlagValue>
typename Pointer<TChar, FlagValue>::SizeType 
Pointer<TChar, FlagValue>::Print(OutputInterfaceType&, const WidthType&,
    const ValueType&)
{
    return 0;
}

template<typename TChar>
typename Pointer<TChar, 
    test::msg::fmt::val::flag::Pointer::pointer_format>::SizeType 
Pointer<TChar, test::msg::fmt::val::flag::Pointer::pointer_format>::
    Print(OutputInterfaceType& out, const WidthType&, 
        const ValueType& val)
{
    return out.Print("%p", val);
}
    
template<typename TChar>
typename Pointer<TChar, 
    test::msg::fmt::val::flag::Pointer::w_pointer_format>::SizeType 
Pointer<TChar, test::msg::fmt::val::flag::Pointer::w_pointer_format>::
    Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val)
{
    return out.Print("%*p", width.GetValue(), val);
}

} //!print

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_PRINT_POINTER_H_