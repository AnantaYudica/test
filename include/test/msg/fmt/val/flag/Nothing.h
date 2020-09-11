#ifndef TEST_MSG_FMT_VAL_FLAG_NOTHING_H_
#define TEST_MSG_FMT_VAL_FLAG_NOTHING_H_

#include "../../var/arg/Width.h"
#include "../../var/arg/Precision.h"
#include "../../var/arg/Length.h"
#include "../../var/arg/Define.h"

#include <cstdint>
#include <type_traits>
#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{
namespace flag
{

class Nothing
{
public:
    typedef std::uint16_t ValueType;
    typedef test::msg::fmt::var::arg::Width WidthType;
    typedef test::msg::fmt::var::arg::Precision PrecisionType;
    typedef test::msg::fmt::var::arg::Length LengthType; 
    template<typename T>
    using DefineType = test::msg::fmt::var::arg::Define<T>;
public:
    enum : ValueType
    {
        good = 0,
        define_char = 1 << 0,
        define_short = 1 << 1,
        define_int = 1 << 2,
        define_long = 1 << 3,
        define_long_long = 1 << 4,
        define_double = 1 << 5,
        define_long_double = 1 << 6,
        define_pointer = 1 << 7,
        width = 1 << 8,
        precision = 1 << 9,
        length = 1 << 9
    }; 
private:
    static constexpr ValueType define_mask = define_char | define_short | 
        define_int | define_long | define_long_long | define_double |
        define_long_double | define_pointer;
private:
    ValueType m_value;
public:
    inline constexpr Nothing();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        Nothing>::value, int>::type = 0>
    inline constexpr Nothing(TArg&& arg, TArgs&& ... args);
public:
    inline ~Nothing() = default;
public:
    inline constexpr Nothing(const Nothing& cpy);
    inline constexpr Nothing(Nothing&& mov);
public:
    inline Nothing& operator=(const Nothing& cpy);
    inline Nothing& operator=(Nothing&& mov);
private:
    inline constexpr ValueType _Value(ValueType val) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrecisionType&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<char>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<signed char>&&,
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned char>&&, TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<short>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned short>&&, TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<int>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned int>&&, TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned long>&&, TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long long>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned long long>&&, TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<float>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<double>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long double>&&,
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<const char *>&&, 
        TArgs&&... args) const;
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<const void *>&&, 
        TArgs&&... args) const;
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Nothing::Nothing() :
    m_value(_Value(good | define_int))
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, Nothing>::value, 
    int>::type>
inline constexpr Nothing::Nothing(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good | define_int, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...))
{}

inline constexpr Nothing::Nothing(const Nothing& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr Nothing::Nothing(Nothing&& mov) :
    m_value(mov.m_value)
{}

inline Nothing& Nothing::operator=(const Nothing& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline Nothing& Nothing::operator=(Nothing&& mov)
{
    m_value = mov.m_value;
    return *this;
}

inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val) const
{
    return val;
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, WidthType&&, TArgs&&... args) const
{
    return _Value(val | width, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, PrecisionType&&, TArgs&&... args) const
{
    return _Value(val | precision, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<char>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<signed char>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned char>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<short>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_short, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned short>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_short, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<int>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_int, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned int>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_int, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<long>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned long>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<long long>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_long_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned long long>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_long_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<float>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_double, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<double>&&, TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_double, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<long double>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_long_double, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<const char *>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_pointer, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<const void *>&&, 
    TArgs&&... args) const
{
    return _Value((val & ~define_mask) | define_pointer, 
        std::forward<TArgs>(args)...);
}

inline constexpr typename Nothing::ValueType 
Nothing::GetValue() const
{
    return m_value;
}

} //!flag

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_FLAG_NOTHING_H_
