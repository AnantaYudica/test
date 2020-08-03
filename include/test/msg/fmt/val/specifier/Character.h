#ifndef TEST_MSG_FMT_PARAM_SPECIFIER_CHARACTER_H_
#define TEST_MSG_FMT_PARAM_SPECIFIER_CHARACTER_H_

#include "../Specifier.h"
#include "../Width.h"
#include "../flag/Character.h"
#include "val/Character.h"
#include "print/Character.h"

#include <cwchar>
#include <type_traits>

namespace test
{
namespace msg
{
namespace fmt
{
namespace param
{
namespace specifier
{

template<typename TChar>
class Character :
    public test::msg::fmt::param::Specifier<TChar>
{
public:
    typedef test::msg::fmt::param::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::StatusType StatusType;
    typedef typename SpecifierBaseType::ParameterBaseType ParameterBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
    typedef test::msg::fmt::param::flag::Character FlagType;
    typedef typename FlagType::ValueType IntegerFlagType;
    typedef test::msg::fmt::param::specifier::val::Character ValueType;
    typedef test::msg::fmt::param::Width<TChar> WidthType;
public:
    template<int FlagValue>
    using PrintType = test::msg::fmt::param::specifier::print::
        Character<TChar, FlagValue>;
private:
    typedef SizeType (OutputPrintFunctionType)(OutputInterfaceType&, 
        const WidthType&, const ValueType&);
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
                test::msg::fmt::param::flag::arg::Width>::value, 
            int>::type = 0>
    static bool _SetWidth(WidthType& width, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    static bool _SetWidth(WidthType& width, 
        test::msg::fmt::param::flag::arg::Width&& set, TArgs&&... args);
private:
    template<typename... TArgs>
    static bool _Set(WidthType& width, OutputPrintFunctionType*& print_out, 
        TArgs&&... args);
private:
    FlagType m_flag;
    ValueType m_value;
    WidthType m_width;
    OutputPrintFunctionType* m_print_out;
public:
    Character();
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value &&
            !std::is_same<_TArg, Character<TChar>>::value, 
        int>::type = 0>
    Character(TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Character(const char& val, TArgs&&... args);
    template<typename... TArgs, typename Twchar = wchar_t,
        typename std::enable_if<!std::is_same<Twchar, char>::value, 
        int>::type = 0>
    Character(const Twchar& w_val, TArgs&&... args);
public:
    ~Character();
public:
    Character(const Character<TChar>& cpy);
    Character(Character<TChar>&& mov);
public:
    Character<TChar>& operator=(const Character<TChar>& cpy);
    Character<TChar>& operator=(Character<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list args) override;
    std::size_t Load(std::size_t size, ...) override;
public:
    typename OutputInterfaceType::SizeType
        Output(OutputInterfaceType& out) override;
public:
    ValueType GetValue() const;
    int GetWidth() const;
public:
    void Unset() override;
public:
    bool IsSet() const override;
public:
    IntegerFlagType GetFlag() const;
};

template<typename TChar>
template<typename... TArgs>
bool Character<TChar>::_SetPrintOutput(OutputPrintFunctionType*& print_out, 
    TArgs&&... args)
{
    constexpr FlagType flag{std::forward<TArgs>(args)...};
    print_out = &PrintType<flag.GetValue()>::Print;
    return true;
}

template<typename TChar>
bool Character<TChar>::_SetWidth(WidthType&)
{
    return true;
}
    
template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
            test::msg::fmt::param::flag::arg::Width>::value, 
        int>::type>
bool Character<TChar>::_SetWidth(WidthType& width, TArg&&, TArgs&&... args)
{
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Character<TChar>::_SetWidth(WidthType& width, 
    test::msg::fmt::param::flag::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) width = std::move(WidthType(set.GetValue()));
    return _SetWidth(width, std::forward<TArgs>(args)...);;
}

template<typename TChar>
template<typename... TArgs>
bool Character<TChar>::_Set(WidthType& width, 
    OutputPrintFunctionType*& print_out, TArgs&&... args)
{
    _SetWidth(width, std::forward<TArgs>(args)...);
    _SetPrintOutput(print_out, std::forward<TArgs>(args)...);
    return true;
}
    
template<typename TChar>
Character<TChar>::Character() :
    SpecifierBaseType(),
    m_flag(),
    m_value{0},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value &&
        !std::is_same<_TArg, Character<TChar>>::value, 
    int>::type>
Character<TChar>::Character(TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{0},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out, std::forward<TArg>(arg),
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Character<TChar>::Character(const char& val, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_value{.char_value = (unsigned char)val},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs, typename Twchar,
    typename std::enable_if<!std::is_same<Twchar, char>::value, 
    int>::type>
Character<TChar>::Character(const Twchar& w_val, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_value{.wchar_value = w_val},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
Character<TChar>::~Character()
{}

template<typename TChar>
Character<TChar>::Character(const Character<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag(cpy.m_flag),
    m_value{cpy.m_value},
    m_width(cpy.m_width),
    m_print_out(cpy.m_print_out)
{}

template<typename TChar>
Character<TChar>::Character(Character<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag(std::move(mov.m_flag)),
    m_value{mov.m_value},
    m_width(std::move(mov.m_width)),
    m_print_out(mov.m_print_out)
{
    if (!mov.GetStatus().IsDefaultValue())
        mov.m_value = ValueType{0};
}

template<typename TChar>
Character<TChar>& Character<TChar>::operator=(const Character<TChar>& cpy)
{
    SpecifierBaseType::operator=(cpy);
    m_flag = cpy.m_flag;
    m_value = cpy.m_value;
    m_width = cpy.m_width;
    m_print_out = cpy.m_print_out;
    return *this;
}

template<typename TChar>
Character<TChar>& Character<TChar>::operator=(Character<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_value = mov.m_value;
    m_width = std::move(mov.m_width);
    m_print_out = mov.m_print_out;
    if (!mov.GetStatus().IsDefaultValue())
        mov.m_value = ValueType{0};
    return *this;
}

template<typename TChar>
std::size_t Character<TChar>::VLoad(std::size_t size, std::size_t index, 
    va_list args)
{
    auto& status = SpecifierBaseType::GetStatus();

    if (status.IsBad() && !status.Reset(StatusType::value_not_set))
    {
        return index;
    }

    std::size_t skip = 0;
    if ((m_flag.GetValue() & FlagType::width) && !m_width.IsSet())
    {
        if (size <= index) 
        {
            status.Bad(StatusType::load_failed);
            return size;
        }
        skip = m_width.VLoad(size, index, args) - index;
    }

    const std::size_t next_index = index + skip;

    if (status.IsSetValue()) return next_index;
    if (size <= next_index) 
    {
        status.Bad(StatusType::load_failed);
        return size;
    }
    for (std::size_t i = 0; i < skip; ++i)
        va_arg(args, void*);
    if (m_flag.GetValue() & FlagType::define_char)
    {
        int val = va_arg(args, int);
        memcpy((void*)&m_value, (void*)&val, sizeof(char));
        memset(((char*)&m_value) + sizeof(char), 0, 
            sizeof(ValueType) - sizeof(char));
    }
    else if (m_flag.GetValue() & FlagType::define_wchar)
    {
        wint_t val = va_arg(args, wint_t);
        memcpy((void*)&m_value, (void*)&val, sizeof(wchar_t));
        memset(((char*)&m_value) + sizeof(wchar_t), 0, 
            sizeof(ValueType) - sizeof(wchar_t));
    }
    else
    {
        status.Bad(StatusType::flag_undefined);
        return next_index;
    }
    status.SetValue();
    return next_index + 1;
}
    
template<typename TChar>
std::size_t Character<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}
 
template<typename TChar>
typename Character<TChar>::OutputInterfaceType::SizeType
Character<TChar>::Output(OutputInterfaceType& out)
{
    if (!IsSet())
    {
        SpecifierBaseType::GetStatus().Bad(StatusType::value_not_set);
    }
    return m_print_out(out, m_width, m_value);
}

template<typename TChar>
typename Character<TChar>::ValueType 
Character<TChar>::GetValue() const
{
    return m_value;
}

template<typename TChar>
int Character<TChar>::GetWidth() const
{
    return m_width.GetValue();
}

template<typename TChar>
void Character<TChar>::Unset()
{
    auto& status = SpecifierBaseType::GetStatus();
    status.UnsetValue();
    if (!status.IsSetValue())
        m_value = ValueType{0};
    m_width.Unset();
}

template<typename TChar>
bool Character<TChar>::IsSet() const
{
    return (!(m_flag.GetValue() & FlagType::width) || m_width.IsSet()) &&
        SpecifierBaseType::GetStatus().IsSetValue();
}

template<typename TChar>
typename Character<TChar>::IntegerFlagType 
Character<TChar>::GetFlag() const
{
    return m_flag.GetValue();
}

} //!specifier

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_SPECIFIER_CHARACTER_H_