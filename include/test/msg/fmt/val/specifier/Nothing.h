#ifndef TEST_MSG_FMT_VAL_SPECIFIER_NOTHING_H_
#define TEST_MSG_FMT_VAL_SPECIFIER_NOTHING_H_

#include "../Specifier.h"
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
private:
    static bool _SetWidth(std::uint8_t& _default);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Width>::value, 
            int>::type = 0>
    static bool _SetWidth(std::uint8_t& _default, TArg&& arg, 
        TArgs&&... args);
    template<typename... TArgs>
    static bool _SetWidth(std::uint8_t& _default, 
        test::msg::fmt::var::arg::Width&& set, TArgs&&... args);
private:
    static bool _SetPrecision(std::uint8_t& _default);
    template<typename TArg, typename... TArgs, 
        typename _TArg = typename std::remove_reference<
            typename std::remove_cv<TArg>::type>::type,
        typename std::enable_if<!std::is_same<_TArg, 
                test::msg::fmt::var::arg::Precision>::value, 
            int>::type = 0>
    static bool _SetPrecision(std::uint8_t& _default, TArg&& arg, 
        TArgs&&... args);
    template<typename... TArgs>
    static bool _SetPrecision(std::uint8_t& _default, 
        test::msg::fmt::var::arg::Precision&& set, TArgs&&... args);
private:
    template<typename... TArgs>
    static bool _Set(std::uint8_t& _default, TArgs&&... args);
private:
    static constexpr std::uint8_t default_width = 1;
    static constexpr std::uint8_t default_set_width = 2;
    static constexpr std::uint8_t default_precision = 4;
    static constexpr std::uint8_t default_set_precision = 8;
private:
    FlagType m_flag;
    std::uint8_t m_default;
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
        va_list args) override;
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
bool Nothing<TChar>::_SetWidth(std::uint8_t&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
            test::msg::fmt::var::arg::Width>::value, 
        int>::type>
bool Nothing<TChar>::_SetWidth(std::uint8_t& _default, TArg&&, 
    TArgs&&... args)
{
    return _SetWidth(_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Nothing<TChar>::_SetWidth(std::uint8_t& _default, 
    test::msg::fmt::var::arg::Width&& set, TArgs&&... args)
{
    if (!set.IsDefault()) _default |= (default_width | default_set_width);
    return _SetWidth(_default, std::forward<TArgs>(args)...);;
}

template<typename TChar>
bool Nothing<TChar>::_SetPrecision(std::uint8_t&)
{
    return true;
}

template<typename TChar>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<!std::is_same<_TArg, 
            test::msg::fmt::var::arg::Precision>::value, 
        int>::type>
bool Nothing<TChar>::_SetPrecision(std::uint8_t& _default, TArg&&, 
    TArgs&&... args)
{
    return _SetPrecision(_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
bool Nothing<TChar>::_SetPrecision(std::uint8_t& _default, 
    test::msg::fmt::var::arg::Precision&& set, TArgs&&... args)
{
    if (!set.IsDefault()) _default |= (default_precision
        | default_set_precision);
    return _SetPrecision(_default, std::forward<TArgs>(args)...);;
}
    
template<typename TChar>
template<typename... TArgs>
bool Nothing<TChar>::_Set(std::uint8_t& _default, TArgs&&... args)
{
    _SetWidth(_default, std::forward<TArgs>(args)...);
    _SetPrecision(_default, std::forward<TArgs>(args)...);
    return true;
}

template<typename TChar>
Nothing<TChar>::Nothing() :
    SpecifierBaseType(),
    m_flag(),
    m_default(0)
{
    _Set(m_default);
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
    m_default(0)
{
    _Set(m_default, std::forward<TArg>(arg), std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const char&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const signed char&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const short&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const int&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const long long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned char&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned short&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned int&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const unsigned long long&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const float&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const double&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const long double&, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const void*, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
template<typename... TArgs>
Nothing<TChar>::Nothing(const char*, TArgs&&... args) :
    SpecifierBaseType(StatusType::default_value),
    m_flag{std::forward<TArgs>(args)...},
    m_default(0)
{
    _Set(m_default, std::forward<TArgs>(args)...);
}

template<typename TChar>
Nothing<TChar>::~Nothing()
{}

template<typename TChar>
Nothing<TChar>::Nothing(const Nothing<TChar>& cpy) :
    SpecifierBaseType(cpy),
    m_flag{cpy.m_flag},
    m_default(cpy.m_default)
{}

template<typename TChar>
Nothing<TChar>::Nothing(Nothing<TChar>&& mov) :
    SpecifierBaseType(std::move(mov)),
    m_flag{std::move(mov.m_flag)},
    m_default(mov.m_default)
{
    if (!(mov.m_default & default_width))
        mov.m_default &= ~default_set_width;
    if (!(mov.m_default & default_precision))
        mov.m_default &= ~default_set_precision;
}

template<typename TChar>
Nothing<TChar>& Nothing<TChar>::operator=(const Nothing<TChar>& cpy)
{
    SpecifierBaseType::operator=(cpy);
    m_flag = cpy.m_flag;
    m_default = cpy.m_default;
    return *this;
}

template<typename TChar>
Nothing<TChar>& Nothing<TChar>::operator=(Nothing<TChar>&& mov)
{
    SpecifierBaseType::operator=(std::move(mov));
    m_flag = std::move(mov.m_flag);
    m_default = std::move(mov.m_default);
    if (!(mov.m_default & default_width))
        mov.m_default &= ~default_set_width;
    if (!(mov.m_default & default_precision))
        mov.m_default &= ~default_set_precision;
    return *this;
}

template<typename TChar>
std::size_t 
Nothing<TChar>::VLoad(std::size_t size, std::size_t index, va_list)
{
    auto& status = SpecifierBaseType::GetStatus();
    
    if (status.IsBad() && !status.Reset(StatusType::value_not_set))
    {
        return index;
    }

    std::size_t skip = 0;

    if ((m_flag.GetValue() & FlagType::width) && 
        !(m_default & default_set_width))
    {
        if (size <= index) 
        {
            status.Bad(StatusType::load_failed);
            return size;
        }
        m_default |= default_set_width;
        skip += 1;
    }
    if ((m_flag.GetValue() & FlagType::precision) && 
        !(m_default & default_set_precision))
    {
        if (size <= (index + skip)) 
        {
            status.Bad(StatusType::load_failed);
            return size;
        }
        m_default |= default_set_precision;
        skip += 1;
    }

    const std::size_t next_index = index + (skip);

    if (status.IsSetValue()) return next_index;

    if (size <= next_index) 
    {
        status.Bad(StatusType::load_failed);
        return size;
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
     if ((m_flag.GetValue() & FlagType::width) && 
        !(m_default & default_width)) m_default &= ~default_set_width;
    if ((m_flag.GetValue() & FlagType::precision) && 
        !(m_default & default_precision)) 
            m_default &= ~default_set_precision;
}

template<typename TChar>
bool Nothing<TChar>::IsSet() const
{
    return (SpecifierBaseType::GetStatus().IsSetValue() &&
        (!(m_flag.GetValue() & FlagType::width) || 
            (m_default & default_set_width))) &&
        (!(m_flag.GetValue() & FlagType::precision) || 
            (m_default & default_set_precision));
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
