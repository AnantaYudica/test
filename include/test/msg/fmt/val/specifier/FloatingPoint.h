#ifndef TEST_MSG_FMT_VAL_SPECIFIER_FLOATINGPOINT_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_FLOATINGPOINT_H_

#include "../Specifier.h"
#include "../Width.h"
#include "../Precision.h"
#include "../flag/FloatingPoint.h"
#include "val/FloatingPoint.h"
#include "print/FloatingPoint.h"

#include <type_traits>
#include <utility>
#include <cstring>

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
class FloatingPoint :
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
    typedef test::msg::fmt::val::flag::FloatingPoint FlagType;
    typedef typename FlagType::ValueType IntegerFlagType;
    typedef test::msg::fmt::val::specifier::val::FloatingPoint ValueType;
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Precision<TChar> PrecisionType;
public:
    template<int FlagValue>
    using PrintType = test::msg::fmt::val::specifier::print::
        FloatingPoint<TChar, FlagValue>;
private:
    typedef SizeType (OutputPrintFunctionType)(OutputInterfaceType&, 
        const WidthType&, const PrecisionType&, const ValueType&);
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
    static bool _SetPrecision(PrecisionType& precision);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Precision>::value, 
            int>::type = 0>
    static bool _SetPrecision(PrecisionType& precision, TArg&& arg, 
        TArgs&&... args);
    template<typename... TArgs>
    static bool _SetPrecision(PrecisionType& precision, 
        test::msg::fmt::var::arg::Precision&& set, TArgs&&... args);
private:
    template<typename... TArgs>
    static bool _Set(WidthType& width, PrecisionType& precision, 
        OutputPrintFunctionType*& print_out, TArgs&&... args);
private:
    FlagType m_flag;
    ValueType m_value;
    WidthType m_width;
    PrecisionType m_precision;
    OutputPrintFunctionType* m_print_out;
public:
    FloatingPoint();
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename _TStatusPointer = 
            typename test::msg::fmt::val::Specifier<TChar>::StatusPointerType,
        typename std::enable_if<!std::is_floating_point<_TArg>::value &&
            !std::is_base_of<FloatingPoint<TChar>, _TArg>::value &&
            !std::is_base_of<_TStatusPointer, _TArg>::value, int>::type = 0>
    FloatingPoint(TArg&& arg, TArgs&&... args);
    
    FloatingPoint(const float& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_floating_point<_TArg>::value,
            int>::type = 0>
    FloatingPoint(const float& val, TArg&& arg, TArgs&&... args);
    FloatingPoint(const double& val);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_floating_point<_TArg>::value,
            int>::type = 0>
    FloatingPoint(const double& val, TArg&& arg, TArgs&&... args);
    FloatingPoint(const long double& val); 
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_floating_point<_TArg>::value,
            int>::type = 0>
    FloatingPoint(const long double& val, TArg&& arg, TArgs&&... args); 
public:
    FloatingPoint(StatusPointerType&& status);
    template<typename TArg, typename... TArgs, typename _TArg = 
        typename std::remove_cv<typename std::remove_reference<TArg>::
            type>::type,
        typename std::enable_if<!std::is_floating_point<_TArg>::value, 
            int>::type = 0>
    FloatingPoint(StatusPointerType&& status, TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    FloatingPoint(StatusPointerType&& status, const float& val, 
        TArgs&&... args);
    template<typename... TArgs>
    FloatingPoint(StatusPointerType&& status, const double& val, 
        TArgs&&... args);
    template<typename... TArgs>
    FloatingPoint(StatusPointerType&& status, const long double& val, 
        TArgs&&... args);
public:
    ~FloatingPoint();
public:
    FloatingPoint(const FloatingPoint<TChar>& cpy);
    FloatingPoint(FloatingPoint<TChar>&& mov);
public:
    FloatingPoint<TChar>& operator=(const FloatingPoint<TChar>& cpy);
    FloatingPoint<TChar>& operator=(FloatingPoint<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    std::size_t Load(std::size_t size, ...) override;
public:
    SizeType Output(OutputInterfaceType& out) override;
public:
    ValueType GetValue() const;
    int GetWidth() const;
    int GetPrecision() const;
public:
    void Unset() override;
public:
    bool IsSet() const override;
public:
    IntegerFlagType GetFlag() const;
};

template<typename TChar>
template<typename... TArgs>
bool FloatingPoint<TChar>::_SetPrintOutput(OutputPrintFunctionType*& print_out,
    TArgs&&...)
{
    constexpr FlagType flag{TArgs()...};
    print_out = &PrintType<flag.GetValue()>::Print;
    return true;
}

template<typename TChar>
bool FloatingPoint<TChar>::_SetWidth(WidthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Width>::value, int>::type>
bool FloatingPoint<TChar>::_SetWidth(WidthType& width, TArg&&, 
    TArgs&&... args)
{
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool FloatingPoint<TChar>::_SetWidth(WidthType& width, 
    test::msg::fmt::var::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) width = std::move(WidthType(set.GetValue()));
    return _SetWidth(width, std::forward<TArgs>(args)...);;
}

template<typename TChar>
bool FloatingPoint<TChar>::_SetPrecision(PrecisionType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
        test::msg::fmt::var::arg::Precision>::value, int>::type>
bool FloatingPoint<TChar>::_SetPrecision(PrecisionType& precision, TArg&&,
    TArgs&&... args)
{
    return _SetPrecision(precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool FloatingPoint<TChar>::_SetPrecision(PrecisionType& precision, 
    test::msg::fmt::var::arg::Precision&& set, TArgs&&... args)
{
    if (!set.IsDefault()) precision = std::move(PrecisionType(set.GetValue()));
    return _SetPrecision(precision, std::forward<TArgs>(args)...);;
}

template<typename TChar>
template<typename... TArgs>
bool FloatingPoint<TChar>::_Set(WidthType& width, PrecisionType& precision, 
    OutputPrintFunctionType*& print_out, TArgs&&... args)
{
    _SetWidth(width, std::forward<TArgs>(args)...);
    _SetPrecision(precision, std::forward<TArgs>(args)...);
    _SetPrintOutput(print_out, std::forward<TArgs>(args)...);
    return true;
}
    
template<typename TChar>
FloatingPoint<TChar>::FloatingPoint() :
    SpecifierBaseType(),
    m_flag(),
    m_value{.long_double_value=0.0L},
    m_width(),
    m_precision(),
    m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename _TStatusPointer,
    typename std::enable_if<!std::is_floating_point<_TArg>::value &&
        !std::is_base_of<FloatingPoint<TChar>, _TArg>::value &&
        !std::is_base_of<_TStatusPointer, _TArg>::value, int>::type>
FloatingPoint<TChar>::FloatingPoint(TArg&& arg, TArgs&&... args) :
    SpecifierBaseType(),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_value{.long_double_value=0.0L},
    m_width(),
    m_precision(),
    m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(const float& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.float_value = val},
    m_width(),
    m_precision(),
    m_print_out(nullptr)
{
    m_value._float_aligned.double_padding = 0;
    m_value._float_aligned.long_double_padding = 0;
    _Set(m_width, m_precision, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_floating_point<_TArg>::value,
        int>::type>
FloatingPoint<TChar>::FloatingPoint(const float& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.float_value=val},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    m_value._float_aligned.double_padding = 0;
    m_value._float_aligned.long_double_padding = 0;
    _Set(m_width, m_precision, m_print_out, std::forward<TArg>(arg),
        std::forward<TArgs>(args)...);
}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(const double& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.double_value=val},
    m_width(),
    m_precision(),
    m_print_out(nullptr)
{
    m_value._float_aligned.long_double_padding = 0;
    _Set(m_width, m_precision, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_floating_point<_TArg>::value,
        int>::type>
FloatingPoint<TChar>::FloatingPoint(const double& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.double_value=val},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    m_value._float_aligned.long_double_padding = 0;
    _Set(m_width, m_precision, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(const long double& val) :
    SpecifierBaseType(ValueStatusType::default_value),
    m_flag{},
    m_value{.long_double_value=val},
    m_width(),
    m_precision(),
    m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_floating_point<_TArg>::value,
        int>::type>
FloatingPoint<TChar>::FloatingPoint(const long double& val, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(ValueStatusType::default_value),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.long_double_value=val},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(StatusPointerType&& status) :
    SpecifierBaseType(std::forward<StatusPointerType>(status)),
    m_flag(),
    m_value{.long_double_value=0.0L},
    m_width(),
    m_precision(),
    m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_floating_point<_TArg>::value, int>::type>
FloatingPoint<TChar>::FloatingPoint(StatusPointerType&& status, TArg&& arg, 
    TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status)),
        m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
        m_value{.long_double_value=0.0L},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
FloatingPoint<TChar>::FloatingPoint(StatusPointerType&& status, 
    const float& val, TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.float_value=val},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    m_value._float_aligned.double_padding = 0;
    m_value._float_aligned.long_double_padding = 0;
    _Set(m_width, m_precision, m_print_out, std::forward<TArgs>(args)...);
}
    
template<typename TChar>
template<typename... TArgs>
FloatingPoint<TChar>::FloatingPoint(StatusPointerType&& status, 
    const double& val, TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.double_value=val},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    m_value._float_aligned.long_double_padding = 0;
    _Set(m_width, m_precision, m_print_out, std::forward<TArgs>(args)...);
}
    
template<typename TChar>
template<typename... TArgs>
FloatingPoint<TChar>::FloatingPoint(StatusPointerType&& status, 
    const long double& val, TArgs&&... args) :
        SpecifierBaseType(std::forward<StatusPointerType>(status),
            ValueStatusType::default_value),
        m_flag{std::forward<TArgs>(args)...},
        m_value{.long_double_value = val},
        m_width(),
        m_precision(),
        m_print_out(nullptr)
{
    _Set(m_width, m_precision, m_print_out, std::forward<TArgs>(args)...);
}

template<typename TChar>
FloatingPoint<TChar>::~FloatingPoint()
{}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(const FloatingPoint<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag(cpy.m_flag),
    m_value{cpy.m_value},
    m_width(cpy.m_width),
    m_precision(cpy.m_precision),
    m_print_out(cpy.m_print_out)
{}

template<typename TChar>
FloatingPoint<TChar>::FloatingPoint(FloatingPoint<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag(std::move(mov.m_flag)),
    m_value{mov.m_value},
    m_width(std::move(mov.m_width)),
    m_precision(std::move(mov.m_precision)),
    m_print_out(mov.m_print_out)
{
    if (!mov.GetValueStatus().IsDefaultValue())
        mov.m_value = ValueType{.long_double_value=0.0L};
}

template<typename TChar>
FloatingPoint<TChar>& 
FloatingPoint<TChar>::operator=(const FloatingPoint<TChar>& cpy)
{
    SpecifierBaseType::operator=(cpy);
    m_flag = cpy.m_flag;
    m_value = cpy.m_value;
    m_width = cpy.m_width;
    m_precision = cpy.m_precision;
    m_print_out = cpy.m_print_out;
    return *this;
}

template<typename TChar>
FloatingPoint<TChar>& 
FloatingPoint<TChar>::operator=(FloatingPoint<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_value = mov.m_value;
    m_width = std::move(mov.m_width);
    m_precision = std::move(mov.m_precision);
    m_print_out = mov.m_print_out;
    if (!mov.GetValueStatus().IsDefaultValue())
        mov.m_value = ValueType{.long_double_value=0.0L};
    return *this;
}

template<typename TChar>
std::size_t FloatingPoint<TChar>::VLoad(std::size_t size, std::size_t index, 
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

    if ((m_flag.GetValue() & FlagType::precision) && !m_precision.IsSet())
    {
        if (size <= (index + skip)) 
        {
            status.Bad(StatusType::load_failed);
            return size;
        }
        skip = m_precision.VLoad(size, index, args) - index;
        total_skip += skip;
    }
    
    const std::size_t next_index = index + (total_skip);

    if (SpecifierBaseType::GetValueStatus().IsSetValue()) return next_index;

    if (size <= next_index) 
    {
        status.Bad(StatusType::load_failed);
        return size;
    }
    if ((m_flag.GetValue() & (FlagType::define_long | FlagType::define_double))
        != FlagType::define_double)
    {
        long double val = va_arg(args, long double);
        memcpy((void*)&m_value, (void*)&val, sizeof(long double));
        memset(((char*)&m_value) + sizeof(long double), 0, 
            sizeof(ValueType) - sizeof(long double));
    }
    else if (m_flag.GetValue() & (FlagType::define_double))
    {
        double val = va_arg(args, double);
        memcpy((void*)&m_value, (void*)&val, sizeof(double));
        memset(((char*)&m_value) + sizeof(double), 0, 
            sizeof(ValueType) - sizeof(double));
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
std::size_t FloatingPoint<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename FloatingPoint<TChar>::SizeType 
FloatingPoint<TChar>::Output(OutputInterfaceType& out)
{
    if (!IsSet())
    {
        SpecifierBaseType::GetStatus().Bad(StatusType::value_not_set);
    }
    return m_print_out(out, m_width, m_precision, m_value);
}

template<typename TChar>
typename FloatingPoint<TChar>::ValueType 
FloatingPoint<TChar>::GetValue() const
{
    return {m_value};
}

template<typename TChar>
int FloatingPoint<TChar>::GetWidth() const
{
    return m_width.GetValue();
}

template<typename TChar>
int FloatingPoint<TChar>::GetPrecision() const
{
    return m_precision.GetValue();
}

template<typename TChar>
void FloatingPoint<TChar>::Unset()
{
    SpecifierBaseType::GetValueStatus().UnsetValue();
    if (!SpecifierBaseType::GetValueStatus().IsSetValue())
        m_value = ValueType{.long_double_value=0.0L};
    m_width.Unset();
    m_precision.Unset();
}

template<typename TChar>
bool FloatingPoint<TChar>::IsSet() const
{
    return ((!(m_flag.GetValue() & FlagType::width) || m_width.IsSet()) && 
        (!(m_flag.GetValue() & FlagType::precision) || m_precision.IsSet())) &&
        SpecifierBaseType::GetValueStatus().IsSetValue();
}

template<typename TChar>
typename FloatingPoint<TChar>::IntegerFlagType 
FloatingPoint<TChar>::GetFlag() const
{
    return m_flag.GetValue();
}

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_FLOATINGPOINT_H_