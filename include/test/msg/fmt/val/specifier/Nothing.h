#ifndef TEST_MSG_FMT_VAL_SPECIFIER_NOTHING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_NOTHING_H_

#include "../Specifier.h"
#include "../Width.h"
#include "../Precision.h"
#include "../flag/Nothing.h"

#include <type_traits>
#include <utility>
#include <cstdarg>
#include <cstdint>

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
class Nothing :
    public test::msg::fmt::val::Specifier<TChar>
{
public:
    typedef test::msg::fmt::val::Specifier<TChar> SpecifierBaseType;
    typedef typename SpecifierBaseType::StatusType StatusType;
    typedef typename SpecifierBaseType::ParameterBaseType ParameterBaseType;
    typedef typename SpecifierBaseType::OutputInterfaceType 
        OutputInterfaceType;
    typedef typename OutputInterfaceType::SizeType SizeType;
    typedef test::msg::fmt::val::flag::Nothing FlagType;
    typedef typename FlagType::ValueType IntegerFlagType;
    typedef test::msg::fmt::val::Width<TChar> WidthType;
    typedef test::msg::fmt::val::Precision<TChar> PrecisionType;
private:
    static bool _SetWidth(WidthType& width);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Width>::value, 
            int>::type = 0>
    static bool _SetWidth(WidthType& width, TArg&& arg, 
        TArgs&&... args);
    template<typename... TArgs>
    static bool _SetWidth(WidthType& width, 
        test::msg::fmt::var::arg::Width&& set, TArgs&&... args);
private:
    static bool _SetPrecision(PrecisionType& precision);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
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
        TArgs&&... args);
private:
    FlagType m_flag;
    WidthType m_width;
    PrecisionType m_precision;
public:
    Nothing();
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_pointer<typename 
            std::remove_reference<typename std::remove_cv<TArg>
                ::type>::type>::type,
        typename std::enable_if<!std::is_integral<_TArg>::value &&
            !std::is_floating_point<_TArg>::value &&
            !std::is_void<_TArg>::value &&
            !std::is_same<_TArg, Nothing<TChar>>::value, 
            int>::type = 0>
    Nothing(TArg&& arg, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const char&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const signed char&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const short&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const int&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const long&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const long long&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const unsigned char&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const unsigned short&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const unsigned int&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const unsigned long&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const unsigned long long&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const float&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const double&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const long double&, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const void*, TArgs&&... args);
    template<typename... TArgs>
    Nothing(const char*, TArgs&&... args);
public:
    ~Nothing();
public:
    Nothing(const Nothing<TChar>& cpy);
    Nothing(Nothing<TChar>&& mov);
public:
    Nothing<TChar>& operator=(const Nothing<TChar>& cpy);
    Nothing<TChar>& operator=(Nothing<TChar>&& mov);
public:
    std::size_t VLoad(std::size_t size, std::size_t index, 
        va_list& args) override;
    std::size_t Load(std::size_t size, ...) override;
public:
    typename OutputInterfaceType::SizeType
        Output(OutputInterfaceType& out) override;
public:
    void Unset();
public:
    bool IsSet() const;
public:
    IntegerFlagType GetFlag() const;
};

template<typename TChar>
bool Nothing<TChar>::_SetWidth(WidthType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
            test::msg::fmt::var::arg::Width>::value, 
        int>::type>
bool Nothing<TChar>::_SetWidth(WidthType& width, TArg&&, 
    TArgs&&... args)
{
    return _SetWidth(width, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Nothing<TChar>::_SetWidth(WidthType& width, 
    test::msg::fmt::var::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) width = std::move(WidthType(set.GetValue()));
    return _SetWidth(width, std::forward<TArgs>(args)...);;
}

template<typename TChar>
bool Nothing<TChar>::_SetPrecision(PrecisionType&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
            test::msg::fmt::var::arg::Precision>::value, 
        int>::type>
bool Nothing<TChar>::_SetPrecision(PrecisionType& precision, TArg&&, 
    TArgs&&... args)
{
    return _SetPrecision(precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Nothing<TChar>::_SetPrecision(PrecisionType& precision,
    test::msg::fmt::var::arg::Precision&& set, TArgs&&... args)
{
    if (!set.IsDefault()) precision = std::move(PrecisionType(set.GetValue()));
    return _SetPrecision(precision, std::forward<TArgs>(args)...);;
}
    
template<typename TChar>
template<typename... TArgs>
bool Nothing<TChar>::_Set(WidthType& width, PrecisionType& precision, 
        TArgs&&... args)
{
    _SetWidth(width, std::forward<TArgs>(args)...);
    _SetPrecision(precision, std::forward<TArgs>(args)...);
    return true;
}

template<typename TChar>
Nothing<TChar>::Nothing() :
    SpecifierBaseType(),
    m_flag(),
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision);
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_integral<_TArg>::value &&
        !std::is_floating_point<_TArg>::value &&
        !std::is_void<_TArg>::value &&
        !std::is_same<_TArg, Nothing<TChar>>::value, 
        int>::type>
Nothing<TChar>::Nothing(TArg&& arg, TArgs&&... args):
    SpecifierBaseType(),
    m_flag{std::forward<TArg>(arg), std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const char&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<char>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const signed char&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<signed char>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const short&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<short>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const int&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<int>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<long>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const long long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<long long>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned char&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<unsigned char>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned short&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<unsigned short>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned int&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<unsigned int>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<unsigned long>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned long long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<unsigned long long>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const float&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<float>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const double&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<double>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const long double&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<long double>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const void*, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<const void*>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const char*, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{test::msg::fmt::var::arg::Define<const char*>{},
        std::forward<TArgs>(args)...},
    m_width(),
    m_precision()
{
    _Set(m_width, m_precision, std::forward<TArgs>(args)...);
}

template<typename TChar>
Nothing<TChar>::~Nothing()
{}

template<typename TChar>
Nothing<TChar>::Nothing(const Nothing<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag{cpy.m_flag},
    m_width(cpy.m_width),
    m_precision(cpy.m_precision)
{}

template<typename TChar>
Nothing<TChar>::Nothing(Nothing<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag{std::move(mov.m_flag)},
    m_width(std::move(mov.m_width)),
    m_precision(std::move(mov.m_precision))
{}

template<typename TChar>
Nothing<TChar>& Nothing<TChar>::operator=(const Nothing<TChar>& cpy)
{
    SpecifierBaseType::operator=(cpy);
    m_flag = cpy.m_flag;
    m_width = cpy.m_width;
    m_precision = cpy.m_precision;
    return *this;
}

template<typename TChar>
Nothing<TChar>& Nothing<TChar>::operator=(Nothing<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_width = std::move(mov.m_width);
    m_precision = std::move(mov.m_precision);
    return *this;
}

template<typename TChar>
std::size_t 
Nothing<TChar>::VLoad(std::size_t size, std::size_t index, 
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

    if (status.IsSetValue()) return next_index;

    if (size <= next_index) 
    {
        status.Bad(StatusType::load_failed);
        return size;
    }
    if (m_flag.GetValue() & (FlagType::define_int | 
        FlagType::define_char | FlagType::define_short))
        va_arg(args, int);
    else if (m_flag.GetValue() & FlagType::define_long)
        va_arg(args, long);
    else if (m_flag.GetValue() & FlagType::define_long_long)
        va_arg(args, long long);
    else if (m_flag.GetValue() & FlagType::define_double)
        va_arg(args, double);
    else if (m_flag.GetValue() & FlagType::define_long_double)
        va_arg(args, long double);
    else if (m_flag.GetValue() & FlagType::define_pointer)
        va_arg(args, const void*);
    else
    {
        status.Bad(StatusType::flag_undefined);
        return next_index;
    }
    status.SetValue();
    return next_index + 1;
}

template<typename TChar>
std::size_t Nothing<TChar>::Load(std::size_t size, ...)
{
    va_list args;
    va_start(args, size);
    const auto last_index = VLoad(size, 0, args);
    va_end(args);
    return last_index;
}

template<typename TChar>
typename Nothing<TChar>::OutputInterfaceType::SizeType
Nothing<TChar>::Output(OutputInterfaceType&)
{
    if (!IsSet())
        SpecifierBaseType::GetStatus().Bad(StatusType::value_not_set);
    return 0;
}

template<typename TChar>
void Nothing<TChar>::Unset()
{
    auto& status = SpecifierBaseType::GetStatus();
    status.UnsetValue();
    m_width.Unset();
    m_precision.Unset();
}

template<typename TChar>
bool Nothing<TChar>::IsSet() const
{
    return ((!(m_flag.GetValue() & FlagType::width) || m_width.IsSet()) && 
        (!(m_flag.GetValue() & FlagType::precision) || m_precision.IsSet())) &&
        SpecifierBaseType::GetStatus().IsSetValue();
}

template<typename TChar>
typename Nothing<TChar>::IntegerFlagType 
Nothing<TChar>::GetFlag() const
{
    return m_flag.GetValue();
}

} //!specifier

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_SPECIFIER_NOTHING_H_
