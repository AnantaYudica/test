#ifndef TEST_MSG_FMT_VAL_SPECIFIER_PRINT_CHARACTER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_PRINT_CHARACTER_H_

#include "../../flag/Character.h"
#include "../val/Character.h"
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
class Character
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::specifier::val::Character ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Character() = delete;
};

template<typename TChar>
class Character<TChar, test::msg::fmt::param::flag::Character::char_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::specifier::val::Character ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Character() = delete;
};

template<typename TChar>
class Character<TChar, test::msg::fmt::param::flag::Character::w_char_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::specifier::val::Character ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Character() = delete;
};

template<typename TChar>
class Character<TChar, test::msg::fmt::param::flag::Character::wchar_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::specifier::val::Character ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Character() = delete;
};

template<typename TChar>
class Character<TChar, test::msg::fmt::param::flag::Character::w_wchar_format>
{
public:
    typedef test::msg::fmt::param::Width<TChar> WidthType;
    typedef test::msg::fmt::param::specifier::val::Character ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const WidthType& width,
        const ValueType& val);
public:
    Character() = delete;
};

template<typename TChar, int FlagValue>
typename Character<TChar, FlagValue>::SizeType 
Character<TChar, FlagValue>::Print(OutputInterfaceType&, 
    const WidthType&, const ValueType&)
{
    return 0;
}

template<typename TChar>
typename Character<TChar, 
    test::msg::fmt::param::flag::Character::char_format>::SizeType
Character<TChar, test::msg::fmt::param::flag::Character::char_format>::
    Print(OutputInterfaceType& out, const WidthType&, const ValueType& val)
{
    return out.Print("%c", val.char_value);
}

template<typename TChar>
typename Character<TChar, 
    test::msg::fmt::param::flag::Character::w_char_format>::SizeType
Character<TChar, test::msg::fmt::param::flag::Character::w_char_format>::
    Print(OutputInterfaceType& out, const WidthType& width, const ValueType& val)
{
    return out.Print("%*c", width.GetValue(), val.char_value);
}

template<typename TChar>
typename Character<TChar, 
    test::msg::fmt::param::flag::Character::wchar_format>::SizeType
Character<TChar, test::msg::fmt::param::flag::Character::wchar_format>::
    Print(OutputInterfaceType& out, const WidthType&, const ValueType& val)
{
    return out.Print("%lc", val.char_value);
}

template<typename TChar>
typename Character<TChar, 
    test::msg::fmt::param::flag::Character::w_wchar_format>::SizeType
Character<TChar, test::msg::fmt::param::flag::Character::w_wchar_format>::
    Print(OutputInterfaceType& out, const WidthType& width, const ValueType& val)
{
    return out.Print("%*lc", width.GetValue(), val.char_value);
}

} //!print

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_PRINT_CHARACTER_H_
