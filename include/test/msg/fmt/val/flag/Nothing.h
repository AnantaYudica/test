#ifndef TEST_MSG_FMT_VAL_FLAG_NOTHING_H_
#define TEST_MSG_FMT_VAL_FLAG_NOTHING_H_

#include "../../arg/Define.h"

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
    typedef std::uint8_t ValueType;
    template<typename T>
    using DefineType = test::msg::fmt::arg::Define<T>;
public:
    enum : ValueType
    {
        good = 0,
        define_char = 1 << 1,
        define_short = 1 << 2,
        define_int = 1 << 3,
        define_long = 1 << 4,
        define_long_long = 1 << 5,
    }; 
private:
    static constexpr ValueType define_type_mask = define_char | define_short |
        define_int | define_long | define_long_long;
public:
    static constexpr ValueType char_format = define_char;
    static constexpr ValueType short_format = define_short;
    static constexpr ValueType int_format = define_int;
    static constexpr ValueType long_format = define_long;
    static constexpr ValueType long_long_format = define_long_long;
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
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<signed char>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<char>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned char>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<short>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned short>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<int>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned int>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned long>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<long long>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        DefineType<unsigned long long>&&, TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Nothing::Nothing() :
    m_value(_Value(define_int))
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, Nothing>::value, 
    int>::type>
inline constexpr Nothing::Nothing(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(define_int, std::forward<TArg>(arg), 
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
Nothing::_Value(ValueType val)
{
    return val;
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<signed char>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<char>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned char>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<short>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_short, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned short>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_short, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<int>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_int, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned int>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_int, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<long>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned long>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<long long>&&, TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_long_long, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, DefineType<unsigned long long>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_type_mask) | define_long_long, 
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