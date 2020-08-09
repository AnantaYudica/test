#ifndef TEST_MSG_FMT_VAL_SPECIFIER_POINTER_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_POINTER_H_

#include "../Specifier.h"
#include "../Width.h"
#include "../flag/Pointer.h"
#include "print/Pointer.h"

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
class Pointer :
    public test::msg::fmt::val::Specifier<TChar>
{
public:
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::StatusType StatusType;
    typedef typename SpecifierBaseType::ParameterBaseType ParameterBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
    typedef test::msg::fmt::val::flag::Pointer FlagType;
    typedef typename FlagType::ValueType IntegerFlagType;
    typedef void * ValueType;
    typedef test::msg::fmt::val::Width<TChar> WidthType;
public:
    template<int FlagValue>
    using PrintType = test::msg::fmt::val::specifier::print::
        Pointer<TChar, FlagValue>;
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
                test::msg::fmt::var::arg::Width>::value, 
            int>::type = 0>
    static bool _SetWidth(WidthType& width, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    static bool _SetWidth(WidthType& width, 
        test::msg::fmt::var::arg::Width&& set, TArgs&&... args);
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
    Pointer();
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_pointer<typename 
            std::remove_reference<typename std::remove_cv<TArg>
                ::type>::type>::type,
        typename std::enable_if<!std::is_void<_TArg>::value &&
            !std::is_same<_TArg, Pointer<TChar>>::value, 
        int>::type = 0>
    Pointer(TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Pointer(const void* val, TArgs&&... args);
public:
    ~Pointer();
public:
    Pointer(const Pointer<TChar>& cpy);
    Pointer(Pointer<TChar>&& mov);
public:
    Pointer<TChar>& operator=(const Pointer<TChar>& cpy);
    Pointer<TChar>& operator=(Pointer<TChar>&& mov);
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
bool Pointer<TChar>::_SetPrintOutput(OutputPrintFunctionType*& print_out, 
    TArgs&&... args)
{
    constexpr FlagType flag{std::forward<TArgs>(args)...};
    print_out = &PrintType<flag.GetValue()>::Print;
    return true;
}

template<typename TChar>
bool Pointer<TChar>::_SetWidth(WidthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Width>::value, int>::type>
bool Pointer<TChar>::_SetWidth(WidthType& width, TArg&&, TArgs&&... args)
{
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Pointer<TChar>::_SetWidth(WidthType& width, 
    test::msg::fmt::var::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) width = std::move(WidthType(set.GetValue()));
    return _SetWidth(width, std::forward<TArgs>(args)...);;
}

template<typename TChar>
template<typename... TArgs>
bool Pointer<TChar>::_Set(WidthType& width, 
    OutputPrintFunctionType*& print_out, TArgs&&... args)
{
    _SetWidth(width, std::forward<TArgs>(args)...);
    _SetPrintOutput(print_out, std::forward<TArgs>(args)...);
    return true;
}

template<typename TChar>
Pointer<TChar>::Pointer() :
    SpecifierBaseType(),
    m_flag{},
    m_value{nullptr},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_void<_TArg>::value &&
        !std::is_same<_TArg, Pointer<TChar>>::value, int>::type>
Pointer<TChar>::Pointer(TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{nullptr},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out, std::forward<TArg>(arg),
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Pointer<TChar>::Pointer(const void* val, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_value{const_cast<void*>(val)},
    m_width(),
    m_print_out(nullptr)
{
    _Set(m_width, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
Pointer<TChar>::~Pointer()
{}

template<typename TChar>
Pointer<TChar>::Pointer(const Pointer<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag{cpy.m_flag},
    m_value{cpy.m_value},
    m_width(cpy.m_width),
    m_print_out(cpy.m_print_out)
{}

template<typename TChar>
Pointer<TChar>::Pointer(Pointer<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag{std::move(mov.m_flag)},
    m_value{mov.m_value},
    m_width(std::move(mov.m_width)),
    m_print_out(mov.m_print_out)
{
    if (!mov.GetStatus().IsDefaultValue())
        mov.m_value = nullptr;
}

template<typename TChar>
Pointer<TChar>& Pointer<TChar>::operator=(const Pointer<TChar>& cpy)
{
    SpecifierBaseType::operator=(cpy);
    m_flag = cpy.m_flag;
    m_value = cpy.m_value;
    m_width = cpy.m_width;
    m_print_out = cpy.m_print_out;
    return *this;
}

template<typename TChar>
Pointer<TChar>& Pointer<TChar>::operator=(Pointer<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_value = mov.m_value;
    m_width = std::move(mov.m_width);
    m_print_out = mov.m_print_out;
    if (!mov.GetStatus().IsDefaultValue())
        mov.m_value = nullptr;
    return *this;
}

template<typename TChar>
std::size_t Pointer<TChar>::VLoad(std::size_t size, std::size_t index, 
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
    m_value = va_arg(args, void*);
    status.SetValue();
    return next_index + 1;
}
    
template<typename TChar>
std::size_t Pointer<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename Pointer<TChar>::OutputInterfaceType::SizeType
Pointer<TChar>::Output(OutputInterfaceType& out)
{
    if (!IsSet())
    {
        SpecifierBaseType::GetStatus().Bad(StatusType::value_not_set);
    }
    return m_print_out(out, m_width, m_value);
}

template<typename TChar>
typename Pointer<TChar>::ValueType Pointer<TChar>::GetValue() const
{
    return m_value;
}

template<typename TChar>
int Pointer<TChar>::GetWidth() const
{
    return m_width.GetValue();
}

template<typename TChar>
void Pointer<TChar>::Unset()
{
    auto& status = SpecifierBaseType::GetStatus();
    status.UnsetValue();
    if (!status.IsSetValue())
        m_value = nullptr;
    m_width.Unset();
}

template<typename TChar>
bool Pointer<TChar>::IsSet() const
{
    return (!(m_flag.GetValue() & FlagType::width) || m_width.IsSet()) &&
        SpecifierBaseType::GetStatus().IsSetValue();
}

template<typename TChar>
typename Pointer<TChar>::IntegerFlagType Pointer<TChar>::GetFlag() const
{
    return m_flag.GetValue();
}

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_POINTER_H_
