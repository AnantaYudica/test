#ifndef TEST_MSG_FMT_VAL_SPECIFIER_STRING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_STRING_H_

#include "../Specifier.h"
#include "../Width.h"
#include "../Length.h"
#include "../flag/String.h"
#include "val/String.h"
#include "print/String.h"

#include <cwchar>
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
class String :
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
    typedef test::msg::fmt::val::flag::String FlagType;
    typedef typename FlagType::ValueType IntegerFlagType;
    typedef test::msg::fmt::val::specifier::val::String ValueType;
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Length<TChar> LengthType;
public:
    template<int FlagValue>
    using PrintType = test::msg::fmt::val::specifier::print::
        String<TChar, FlagValue>;
private:
    typedef SizeType (OutputPrintFunctionType)(OutputInterfaceType&, 
        const WidthType&, const LengthType&, const ValueType&);
private:
    template<typename... TArgs>
    static bool _SetPrintOutput(OutputPrintFunctionType*& print_out, 
        TArgs&&... args);
private:
    static bool _SetWidth(WidthType& width);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Width>::value, 
            int>::type = 0>
    static bool _SetWidth(WidthType& width, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    static bool _SetWidth(WidthType& width, 
        test::msg::fmt::var::arg::Width&& set, TArgs&&... args);
private:   
    static bool _SetLength(LengthType& length);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
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
    String();
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_pointer<typename 
            std::remove_reference<typename std::remove_cv<TArg>
                ::type>::type>::type,
        typename _TStatusPointer = 
            typename test::msg::fmt::val::Specifier<TChar>::StatusPointerType,
        typename std::enable_if<!std::is_integral<_TArg>::value &&
            !std::is_same<_TArg, String<TChar>>::value &&
            !std::is_same<_TArg, _TStatusPointer>::value, 
        int>::type = 0>
    String(TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    String(const char *& val, TArgs&&... args);
    template<typename... TArgs, typename Twchar = wchar_t,
        typename std::enable_if<std::is_same<Twchar, wchar_t>::value &&
            !std::is_same<Twchar, char>::value, int>::type = 0>
    String(const Twchar *& w_val, TArgs&&... args);
public:
    String(StatusPointerType&& status);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_pointer<typename 
            std::remove_reference<typename std::remove_cv<TArg>
                ::type>::type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value, 
        int>::type = 0>
    String(StatusPointerType&& status, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    String(StatusPointerType&& status, const char *& val, TArgs&&... args);
    template<typename... TArgs, typename Twchar = wchar_t,
        typename std::enable_if<std::is_same<Twchar, wchar_t>::value &&
            !std::is_same<Twchar, char>::value, int>::type = 0>
    String(StatusPointerType&& status, const Twchar *& w_val, TArgs&&... args);
public:
    ~String();
public:
    String(const String<TChar>& cpy);
    String(String<TChar>&& mov);
public:
    String<TChar>& operator=(const String<TChar>& cpy);
    String<TChar>& operator=(String<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    std::size_t Load(std::size_t size, ...) override;
public:
    typename OutputInterfaceType::SizeType
        Output(OutputInterfaceType& out) override;
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
bool String<TChar>::_SetPrintOutput(OutputPrintFunctionType*& print_out, 
    TArgs&&... args)
{
    constexpr FlagType flag{std::forward<TArgs>(args)...};
    print_out = &PrintType<flag.GetValue()>::Print;
    return true;
}

template<typename TChar>
bool String<TChar>::_SetWidth(WidthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Width>::value, int>::type>
bool String<TChar>::_SetWidth(WidthType& width, TArg&&, TArgs&&... args)
{
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool String<TChar>::_SetWidth(WidthType& width, 
    test::msg::fmt::var::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) width = std::move(WidthType(set.GetValue()));
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
bool String<TChar>::_SetLength(LengthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Length>::value, int>::type>
bool String<TChar>::_SetLength(LengthType& length, TArg&&, TArgs&&... args)
{
    return _SetLength(length, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool String<TChar>::_SetLength(LengthType& length, 
    test::msg::fmt::var::arg::Length&& set, TArgs&&... args)
{
    if (!set.IsDefault()) length = std::move(LengthType(set.GetValue()));
    return _SetLength(length, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool String<TChar>::_Set(WidthType& width, LengthType& length, 
    OutputPrintFunctionType*& print_out, TArgs&&... args)
{
    _SetWidth(width, std::forward<TArgs>(args)...);
    _SetLength(length, std::forward<TArgs>(args)...);
    _SetPrintOutput(print_out, std::forward<TArgs>(args)...);
    return true;
}

template<typename TChar>
String<TChar>::String() :
    SpecifierBaseType(),
    m_flag(),
    m_value{0},
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
        !std::is_same<_TArg, String<TChar>>::value &&
        !std::is_same<_TArg, _TStatusPointer>::value, int>::type>
String<TChar>::String(TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{0},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(const char *& val, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_value{.char_ptr_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs, typename Twchar,
    typename std::enable_if<std::is_same<Twchar, wchar_t>::value &&
        !std::is_same<Twchar, char>::value, int>::type>
String<TChar>::String(const Twchar *& val, TArgs&&... args) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_value{.wchar_ptr_value = val},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
String<TChar>::String(StatusPointerType&& status) :
    SpecifierBaseType(std::forward<StatusPointerType>(status)),
    m_flag(),
    m_value{0},
    m_width(),
    m_length(),
    m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value, int>::type>
String<TChar>::String(StatusPointerType&& status, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status)),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{0},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
String<TChar>::String(StatusPointerType&& status, const char *& val, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.char_ptr_value = val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs, typename Twchar,
    typename std::enable_if<std::is_same<Twchar, wchar_t>::value &&
        !std::is_same<Twchar, char>::value, int>::type>
String<TChar>::String(StatusPointerType&& status, const Twchar *& w_val, 
    TArgs&&... args):
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.wchar_ptr_value = w_val},
        m_width(),
        m_length(),
        m_print_out(nullptr)
{
    _Set(m_width, m_length, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
String<TChar>::~String()
{}

template<typename TChar>
String<TChar>::String(const String<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag(cpy.m_flag),
    m_value{cpy.m_value},
    m_width(cpy.m_width),
    m_length(cpy.m_length),
    m_print_out(cpy.m_print_out)
{}

template<typename TChar>
String<TChar>::String(String<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag(std::move(mov.m_flag)),
    m_value{mov.m_value},
    m_width(std::move(mov.m_width)),
    m_length(std::move(mov.m_length)),
    m_print_out(mov.m_print_out)
{
    if (!mov.GetValueStatus().IsDefaultValue())
        mov.m_value = ValueType{0};
}

template<typename TChar>
String<TChar>& String<TChar>::operator=(const String<TChar>& cpy)
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
String<TChar>& String<TChar>::operator=(String<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_value = mov.m_value;
    m_width = std::move(mov.m_width);
    m_length = std::move(mov.m_length);
    m_print_out = mov.m_print_out;
    if (!mov.GetValueStatus().IsDefaultValue())
        mov.m_value = ValueType{0};
    return *this;
}

template<typename TChar>
std::size_t String<TChar>::VLoad(std::size_t size, std::size_t index, 
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
        m_value.char_ptr_value = va_arg(args, const char *);
    }
    else if (m_flag.GetValue() & FlagType::define_wchar)
    {
        m_value.wchar_ptr_value = va_arg(args, const wchar_t*);
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
std::size_t String<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename String<TChar>::OutputInterfaceType::SizeType
String<TChar>::Output(OutputInterfaceType& out)
{
    if (!IsSet())
    {
        SpecifierBaseType::GetStatus().Bad(StatusType::value_not_set);
    }
    return m_print_out(out, m_width, m_length, m_value);
}

template<typename TChar>
typename String<TChar>::ValueType String<TChar>::GetValue() const
{
    return {m_value};
}

template<typename TChar>
int String<TChar>::GetWidth() const
{
    return m_width.GetValue();
}

template<typename TChar>
int String<TChar>::GetLength() const
{
    return m_length.GetValue();
}

template<typename TChar>
void String<TChar>::Unset()
{
    SpecifierBaseType::GetValueStatus().UnsetValue();
    if (!SpecifierBaseType::GetValueStatus().IsSetValue())
        m_value = ValueType{};
    m_width.Unset();
    m_length.Unset();
}

template<typename TChar>
bool String<TChar>::IsSet() const
{
    return ((!(m_flag.GetValue() & FlagType::width) || m_width.IsSet()) && 
        (!(m_flag.GetValue() & FlagType::length) || m_length.IsSet())) &&
        SpecifierBaseType::GetValueStatus().IsSetValue();
}

template<typename TChar>
typename String<TChar>::IntegerFlagType String<TChar>::GetFlag() const
{
    return m_flag.GetValue();
}

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_STRING_H_