#ifndef TEST_MSG_FMT_VAL_SPECIFIER_PRINT_NOTHING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_PRINT_NOTHING_H_

#include "../../flag/Nothing.h"
#include "../val/Nothing.h"
#include "../../Specifier.h"

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
class Nothing
{
public:
    typedef test::msg::fmt::param::specifier::val::Nothing ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const ValueType& val);
public:
    Nothing() = delete;
};

template<typename TChar>
class Nothing<TChar, test::msg::fmt::param::flag::Nothing::char_format>
{
public:
    typedef test::msg::fmt::param::specifier::val::Nothing ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const ValueType& val);
public:
    Nothing() = delete;
};

template<typename TChar>
class Nothing<TChar, test::msg::fmt::param::flag::Nothing::short_format>
{
public:
    typedef test::msg::fmt::param::specifier::val::Nothing ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const ValueType& val);
public:
    Nothing() = delete;
};

template<typename TChar>
class Nothing<TChar, test::msg::fmt::param::flag::Nothing::int_format>
{
public:
    typedef test::msg::fmt::param::specifier::val::Nothing ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const ValueType& val);
public:
    Nothing() = delete;
};

template<typename TChar>
class Nothing<TChar, test::msg::fmt::param::flag::Nothing::long_format>
{
public:
    typedef test::msg::fmt::param::specifier::val::Nothing ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const ValueType& val);
public:
    Nothing() = delete;
};

template<typename TChar>
class Nothing<TChar, test::msg::fmt::param::flag::Nothing::long_long_format>
{
public:
    typedef test::msg::fmt::param::specifier::val::Nothing ValueType;
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
public:
    static SizeType Print(OutputInterfaceType& out, const ValueType& val);
public:
    Nothing() = delete;
};

template<typename TChar, int FlagValue>
typename Nothing<TChar, FlagValue>::SizeType 
Nothing<TChar, FlagValue>::Print(OutputInterfaceType&, const ValueType&)
{
    return 0;
}

template<typename TChar>
typename Nothing<TChar, 
    test::msg::fmt::param::flag::Nothing::char_format>::SizeType 
Nothing<TChar, test::msg::fmt::param::flag::Nothing::char_format>::
    Print(OutputInterfaceType& out, const ValueType& val)
{
    return out.Print("%hhn", val.char_value);
}

template<typename TChar>
typename Nothing<TChar, 
    test::msg::fmt::param::flag::Nothing::short_format>::SizeType 
Nothing<TChar, test::msg::fmt::param::flag::Nothing::short_format>::
    Print(OutputInterfaceType& out, const ValueType& val)
{
    return out.Print("%hn", val.short_value);
}

template<typename TChar>
typename Nothing<TChar, 
    test::msg::fmt::param::flag::Nothing::int_format>::SizeType 
Nothing<TChar, test::msg::fmt::param::flag::Nothing::int_format>::
    Print(OutputInterfaceType& out, const ValueType& val)
{
    return out.Print("%n", val.int_value);
}

template<typename TChar>
typename Nothing<TChar, 
    test::msg::fmt::param::flag::Nothing::long_format>::SizeType 
Nothing<TChar, test::msg::fmt::param::flag::Nothing::long_format>::
    Print(OutputInterfaceType& out, const ValueType& val)
{
    return out.Print("%ln", val.long_value);
}

template<typename TChar>
typename Nothing<TChar, 
    test::msg::fmt::param::flag::Nothing::long_long_format>::SizeType 
Nothing<TChar, test::msg::fmt::param::flag::Nothing::long_long_format>::
    Print(OutputInterfaceType& out, const ValueType& val)
{
    return out.Print("%lln", val.long_long_value);
}

} //!print

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_PRINT_NOTHING_H_