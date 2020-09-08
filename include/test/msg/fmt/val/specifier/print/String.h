#ifndef TEST_MSG_FMT_VAL_SPECIFIER_PRINT_STRING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_PRINT_STRING_H_

#include "../../flag/String.h"
#include "../val/String.h"
#include "../../Specifier.h"
#include "../../Width.h"
#include "../../Length.h"

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
class String
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::wchar_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::w_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::w_wchar_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::l_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::l_wchar_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::wl_char_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar>
class String<TChar, test::msg::fmt::val::flag::String::wl_wchar_format>
{
public:
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val);
public:
    String() = delete;
};

template<typename TChar, int FlagValue>
typename String<TChar, FlagValue>::SizeType 
String<TChar, FlagValue>::Print(OutputInterfaceType&, 
    const WidthType&, const LengthType&, const ValueType&)
{
    return 0;
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::char_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::char_format>::
    Print(OutputInterfaceType& out, const WidthType&,
        const LengthType&, const ValueType& val)
{
    return out.Print("%s", val.char_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::wchar_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::wchar_format>::
    Print(OutputInterfaceType& out, const WidthType&,
        const LengthType&, const ValueType& val)
{
    return out.Print("%ls", val.wchar_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::w_char_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::w_char_format>::
    Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType&, const ValueType& val)
{
    return out.Print("%*s", width.GetValue(), val.char_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::w_wchar_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::w_wchar_format>::
    Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType&, const ValueType& val)
{
    return out.Print("%*ls", width.GetValue(), val.wchar_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::l_char_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::l_char_format>::
    Print(OutputInterfaceType& out, const WidthType&,
        const LengthType& length, const ValueType& val)
{
    return out.Print("%.*s", length.GetValue(), val.char_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::l_wchar_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::l_wchar_format>::
    Print(OutputInterfaceType& out, const WidthType&,
        const LengthType& length, const ValueType& val)
{
    return out.Print("%.*ls", length.GetValue(), val.wchar_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::wl_char_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::wl_char_format>::
    Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*s", width.GetValue(), length.GetValue(), 
        val.char_ptr_value);
}

template<typename TChar>
typename String<TChar, 
    test::msg::fmt::val::flag::String::wl_wchar_format>::SizeType 
String<TChar, test::msg::fmt::val::flag::String::wl_wchar_format>::
    Print(OutputInterfaceType& out, const WidthType& width,
        const LengthType& length, const ValueType& val)
{
    return out.Print("%*.*ls", width.GetValue(), length.GetValue(), 
        val.wchar_ptr_value);
}

} //!print

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_PRINT_STRING_H_
