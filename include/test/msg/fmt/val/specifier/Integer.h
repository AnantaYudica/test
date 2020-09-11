#ifndef TEST_MSG_FMT_VAL_SPECIFIER_INTEGER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_INTEGER_H_

#include "../Specifier.h"
#include "../Width.h"
#include "../Length.h"
#include "../flag/Integer.h"
#include "val/Integer.h"
#include "print/Integer.h"

#include <type_traits>
#include <utility>
#include <cstdarg>

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

template<typename TChar>
class Integer :
    public test::msg::fmt::val::Specifier<TChar>
{
public:
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::StatusType StatusType;
    typedef typename SpecifierBaseType::ParameterBaseType ParameterBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename SpecifierBaseType::StatusPointerType StatusPointerType;
    typedef typename SpecifierBaseType::ValueStatusType ValueStatusType;
    typedef typename OutputInterfaceType::SizeType SizeType;
    typedef test::msg::fmt::val::flag::Integer FlagType;
    typedef typename FlagType::ValueType IntegerFlagType;
    typedef test::msg::fmt::val::specifier::val::Integer ValueType;
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
public:
    template<int FlagValue>
    using PrintType = test::msg::fmt::val::specifier::print::
        Integer<TChar, FlagValue>;
private:
    typedef SizeType (OutputPrintFunctionType)(OutputInterfaceType&, 
        const WidthType&, const LengthType&, const ValueType&);
private:
    template<typename... TArgs>
    static bool _SetPrintOutput(OutputPrintFunctionType*& print_out, 
        TArgs&&... args);
private:
    static bool _SetWidth(WidthType& width);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Width>::value, 
            int>::type = 0>
    static bool _SetWidth(WidthType& width, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    static bool _SetWidth(WidthType& width, 
        test::msg::fmt::var::arg::Width&& set, TArgs&&... args);
private:   
    static bool _SetLength(LengthType& length);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Length>::value, 
            int>::type = 0>
    static bool _SetLength(LengthType& length, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    static bool _SetLength(LengthType& length, 
        test::msg::fmt::var::arg::Length&& set, TArgs&&... args);
private:
    template<typename... TArgs>
    static bool _Set(WidthType& width, LengthType& length, 
        OutputPrintFunctionType*& print_out, TArgs&&... args);
private:
    FlagType m_flag;
    ValueType m_value;
    WidthType m_width;
    LengthType m_length;
    OutputPrintFunctionType* m_print_out;
public:
    Integer();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename _TStatusPointer = 
            typename test::msg::fmt::val::Specifier<TChar>::StatusPointerType,
        typename std::enable_if<!std::is_integral<_TArg>::value &&
            !std::is_base_of<Integer<TChar>, _TArg>::value &&
            !std::is_base_of<_TStatusPointer, _TArg>::value, 
            int>::type = 0>
    Integer(TArg&& arg, TArgs&&... args);

    Integer(const char& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const char& val, TArg&& arg, TArgs&&... args);

    Integer(const short& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const short& val, TArg&& arg, TArgs&&... args);

    Integer(const int& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const int& val, TArg&& arg, TArgs&&... args);

    Integer(const long& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const long& val, TArg&& arg, TArgs&&... args);

    Integer(const long long& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const long long& val, TArg&& arg, TArgs&&... args);

    Integer(const unsigned char& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const unsigned char& val, TArg&& arg, TArgs&&... args);

    Integer(const unsigned short& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const unsigned short& val, TArg&& arg, TArgs&&... args);
    
    Integer(const unsigned int& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const unsigned int& val, TArg&& arg, TArgs&&... args);

    Integer(const unsigned long& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const unsigned long& val, TArg&& arg, TArgs&&... args);

    Integer(const unsigned long long& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(const unsigned long long& val, TArg&& arg, TArgs&&... args);

public:
    Integer(StatusPointerType&& status);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
            int>::type = 0>
    Integer(StatusPointerType&& status, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const char& val, TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const short& val, TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const int& val, TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const long& val, TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const long long& val, TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const unsigned char& val, 
        TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const unsigned short& val, 
        TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const unsigned int& val, 
        TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const unsigned long& val, 
        TArgs&&... args);
    template<typename... TArgs>
    Integer(StatusPointerType&& status, const unsigned long long& val, 
        TArgs&&... args);
public:
    ~Integer();
public:
    Integer(const Integer<TChar>& cpy);
    Integer(Integer<TChar>&& mov);
public:
    Integer<TChar>& operator=(const Integer<TChar>& cpy);
    Integer<TChar>& operator=(Integer<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    std::size_t Load(std::size_t size, ...) override;
public:
    SizeType Output(OutputInterfaceType& out) override;
public:
    ValueType GetValue() const;
    int GetWidth() const;
    int GetLength() const;
public:
    void Unset() override;
public:
    bool IsSet() const override;
public:
    IntegerFlagType GetFlag() const;
};

template<typename TChar>
template<typename... TArgs>
bool Integer<TChar>::_SetPrintOutput(OutputPrintFunctionType*& print_out, 
    TArgs&&...)
{
    constexpr FlagType flag{TArgs()...};
    print_out = &PrintType<flag.GetValue()>::Print;
    return true;
}

template<typename TChar>
bool Integer<TChar>::_SetWidth(WidthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Width>::value, 
    int>::type>
bool Integer<TChar>::_SetWidth(WidthType& width, TArg&&, TArgs&&... args)
{
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Integer<TChar>::_SetWidth(WidthType& width, 
    test::msg::fmt::var::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) width = std::move(WidthType(set.GetValue()));
    return _SetWidth(width, std::forward<TArgs>(args)...);;
}

template<typename TChar>
bool Integer<TChar>::_SetLength(LengthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Length>::value, 
    int>::type>
bool Integer<TChar>::_SetLength(LengthType& length, TArg&&, TArgs&&... args)
{
    return _SetLength(length, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Integer<TChar>::_SetLength(LengthType& length, 
    test::msg::fmt::var::arg::Length&& set, TArgs&&... args)
{
    if (!set.IsDefault()) length = std::move(LengthType(set.GetValue()));
    return _SetLength(length, std::forward<TArgs>(args)...);;
}

template<typename TChar>
template<typename... TArgs>
bool Integer<TChar>::_Set(WidthType& width, LengthType& length, 
    OutputPrintFunctionType*& print_out, TArgs&&... args)
{
    _SetWidth(width, std::forward<TArgs>(args)...);
    _SetLength(length, std::forward<TArgs>(args)...);
    _SetPrintOutput(print_out, std::forward<TArgs>(args)...);
    return true;
}

template<typename TChar>
Integer<TChar>::Integer() :
    SpecifierBaseType(),
    m_flag(),
    m_value{.unsigned_long_long_value=0ULL},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename _TStatusPointer,
    typename std::enable_if<!std::is_integral<_TArg>::value &&
        !std::is_base_of<Integer<TChar>, _TArg>::value &&
        !std::is_base_of<_TStatusPointer, _TArg>::value, int>::type>
Integer<TChar>::Integer(TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.unsigned_long_long_value=0ULL},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const char& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.char_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}


template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const char& val, TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.char_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const short& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.short_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const short& val, TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.short_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const int& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.int_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const int& val, TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.int_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const long& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.long_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const long& val, TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.long_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const long long& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.long_long_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const long long& val, TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.long_long_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const unsigned char& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.unsigned_char_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const unsigned char& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.unsigned_char_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const unsigned short& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.unsigned_short_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const unsigned short& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.unsigned_short_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const unsigned int& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.unsigned_int_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const unsigned int& val, TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.unsigned_int_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const unsigned long& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.unsigned_long_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const unsigned long& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.unsigned_long_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(const unsigned long long& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.unsigned_long_long_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type>
Integer<TChar>::Integer(const unsigned long long& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.unsigned_long_long_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::Integer(StatusPointerType&& status) :
    SpecifierBaseType(std::forward<StatusPointerType>(status)),
    m_flag(),
    m_value{.unsigned_long_long_value=0ULL},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, int>::type>
Integer<TChar>::Integer(StatusPointerType&& status, TArg&& arg,
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status)),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.unsigned_long_long_value=0ULL},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const char& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.char_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const short& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.short_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const int& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.int_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const long& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.long_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const long long& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.long_long_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const unsigned char& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.unsigned_char_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}
    
template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const unsigned short& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.unsigned_short_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}
    
template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const unsigned int& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.unsigned_int_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}
    
template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, const unsigned long& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.unsigned_long_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}
    
template<typename TChar>
template<typename... TArgs>
Integer<TChar>::Integer(StatusPointerType&& status, 
    const unsigned long long& val, TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.unsigned_long_long_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
Integer<TChar>::~Integer()
{}

template<typename TChar>
Integer<TChar>::Integer(const Integer<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag(cpy.m_flag),
    m_value{cpy.m_value},
    m_width(cpy.m_width),
    m_length(cpy.m_length),
    m_print_out(cpy.m_print_out)
{}

template<typename TChar>
Integer<TChar>::Integer(Integer<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag(std::move(mov.m_flag)),
    m_value{mov.m_value},
    m_width(std::move(mov.m_width)),
    m_length(std::move(mov.m_length)),
    m_print_out(mov.m_print_out)
{
    if (!mov.GetValueStatus().IsDefaultValue())
        mov.m_value = ValueType{.unsigned_long_long_value=0ULL};
}

template<typename TChar>
Integer<TChar>& Integer<TChar>::operator=(const Integer<TChar>& cpy)
{
    SpecifierBaseType::operator=(cpy);
    m_flag = cpy.m_flag;
    m_value = cpy.m_value;
    m_width = cpy.m_width;
    m_length = cpy.m_length;
    m_print_out = cpy.m_print_out;
    return *this;
}

template<typename TChar>
Integer<TChar>& Integer<TChar>::operator=(Integer<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_value = mov.m_value;
    m_width = std::move(mov.m_width);
    m_length = std::move(mov.m_length);
    m_print_out = mov.m_print_out;
    if (!mov.GetValueStatus().IsDefaultValue())
        mov.m_value = ValueType{.unsigned_long_long_value=0ULL};
    return *this;
}

template<typename TChar>
std::size_t Integer<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list& args)
{
    auto& status = SpecifierBaseType::GetStatus();
    
    if (status.IsBad() && !status.Reset(StatusType::value_not_set))
    {
        return index;
    }

    std::size_t skip = 0;
    std::size_t total_skip = 0;
    if ((m_flag.GetValue() & FlagType::width) && !m_width.IsSet())
    {
        if (size <= index) 
        {
            status.Bad(StatusType::load_failed);
            return size;
        }
        skip = m_width.VLoad(size, index, args) - index;
        total_skip += skip;
    }

    if ((m_flag.GetValue() & FlagType::length) && !m_length.IsSet())
    {
        if (size <= (index + skip)) 
        {
            status.Bad(StatusType::load_failed);
            return size;
        }
        skip = m_length.VLoad(size, index, args) - index;
        total_skip += skip;
    }
    
    const std::size_t next_index = index + (total_skip);

    if (SpecifierBaseType::GetValueStatus().IsSetValue()) return next_index;

    if (size <= next_index) 
    {
        status.Bad(StatusType::load_failed);
        return size;
    }
    if (m_flag.GetValue() & FlagType::define_char)
    {
        int val = va_arg(args, int);
        memcpy((void*)&m_value, (void*)&val, sizeof(char));
        memset(((char*)&m_value) + sizeof(char), 0, 
            sizeof(ValueType) - sizeof(char));
    }
    else if (m_flag.GetValue() & FlagType::define_short)
    {
        int val = va_arg(args, int);
        memcpy((void*)&m_value, (void*)&val, sizeof(short));
        memset(((char*)&m_value) + sizeof(short), 0, 
            sizeof(ValueType) - sizeof(short));
    }
    else if (m_flag.GetValue() & FlagType::define_int)
    {
        int val = va_arg(args, int);
        memcpy((void*)&m_value, (void*)&val, sizeof(int));
        memset(((char*)&m_value) + sizeof(int), 0, 
            sizeof(ValueType) - sizeof(int));
    }
    else if (m_flag.GetValue() & FlagType::define_long)
    {
        long val = va_arg(args, long);
        memcpy((void*)&m_value, (void*)&val, sizeof(long));
        memset(((char*)&m_value) + sizeof(long), 0, 
            sizeof(ValueType) - sizeof(long));
    }
    else if (m_flag.GetValue() & FlagType::define_long_long)
    {
        long long val = va_arg(args, long long);
        memcpy((void*)&m_value, (void*)&val, sizeof(long long));
        memset(((char*)&m_value) + sizeof(long long), 0, 
            sizeof(ValueType) - sizeof(long long));
    }
    else
    {
        status.Bad(StatusType::flag_undefined);
        return next_index;
    }
    SpecifierBaseType::GetValueStatus().SetValue();
    return next_index + 1;
}
    
template<typename TChar>
std::size_t Integer<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename Integer<TChar>::SizeType 
Integer<TChar>::Output(OutputInterfaceType& out)
{
    if (!IsSet())
    {
        SpecifierBaseType::GetStatus().Bad(StatusType::value_not_set);
    }
    return m_print_out(out, m_width, m_length, m_value);
}

template<typename TChar>
typename Integer<TChar>::ValueType 
Integer<TChar>::GetValue() const
{
    return {m_value};
}

template<typename TChar>
int Integer<TChar>::GetWidth() const
{
    return m_width.GetValue();
}

template<typename TChar>
int Integer<TChar>::GetLength() const
{
    return m_length.GetValue();
}

template<typename TChar>
void Integer<TChar>::Unset()
{
    SpecifierBaseType::GetValueStatus().UnsetValue();
    if (!SpecifierBaseType::GetValueStatus().IsSetValue())
        m_value = ValueType{.unsigned_long_long_value=0ULL};
    m_width.Unset();
    m_length.Unset();
}

template<typename TChar>
bool Integer<TChar>::IsSet() const
{
    return ((!(m_flag.GetValue() & FlagType::width) || m_width.IsSet()) && 
        (!(m_flag.GetValue() & FlagType::length) || m_length.IsSet())) &&
        SpecifierBaseType::GetValueStatus().IsSetValue();
}

template<typename TChar>
typename Integer<TChar>::IntegerFlagType 
Integer<TChar>::GetFlag() const
{
    return m_flag.GetValue();
}

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_INTEGER_H_
