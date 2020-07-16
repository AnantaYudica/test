#ifndef TEST_MSG_FMT_PARAM_FLAG_CHARACTER_H_
#define TEST_MSG_FMT_PARAM_FLAG_CHARACTER_H_

#include "arg/Width.h"
#include "arg/Length.h"

#include <cstdint>
#include <utility>
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
namespace flag
{

template<typename TValue = std::uint8_t>
class Character
{
public:
    typedef TValue ValueType;
    typedef test::msg::fmt::param::flag::arg::Width WidthType;
    template<typename T>
    using LengthType = test::msg::fmt::param::flag::arg::Length<T>;
public:
    enum : ValueType
    {
        good = 0,
        length_char = 1,
        length_wchar = 2,
        width = 4
    };
private:
    static constexpr ValueType length_mask = length_char | length_wchar;
private:
    ValueType m_value;
public:
    constexpr Character();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        Character<TValue>>::value, int>::type = 0>
    constexpr Character(TArg&& arg, TArgs&& ... args);
public:
    ~Character() = default;
public:
    constexpr Character(const Character<TValue>& cpy);
    constexpr Character(Character<TValue>&& mov);
public:
    Character<TValue>& operator=(const Character<TValue>&) = delete;
    Character<TValue>& operator=(Character<TValue>&&) = delete;
private:
    constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    constexpr ValueType _Value(ValueType val, LengthType<unsigned char>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    constexpr ValueType _Value(ValueType val, LengthType<std::wint_t>&&, 
        TArgs&&... args);
public:
    constexpr ValueType GetValue() const;
};

template<typename TValue>
constexpr Character<TValue>::Character() :
    m_value(good | length_char)
{}

template<typename TValue>
template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    Character<TValue>>::value, int>::type>
constexpr Character<TValue>::Character(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good | length_char, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...))
{}

template<typename TValue>
constexpr Character<TValue>::Character(const Character<TValue>& cpy) :
    m_value(cpy.m_value)
{}

template<typename TValue>
constexpr Character<TValue>::Character(Character<TValue>&& mov) :
    m_value(mov.m_value)
{}

template<typename TValue>
constexpr typename Character<TValue>::ValueType 
Character<TValue>::_Value(ValueType val)
{
    return val;
}

template<typename TValue>
template<typename... TArgs>
constexpr typename Character<TValue>::ValueType 
Character<TValue>::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value(val | width, std::forward<TArgs>(args)...);
}

template<typename TValue>
template<typename... TArgs>
constexpr typename Character<TValue>::ValueType 
Character<TValue>::_Value(ValueType val, LengthType<unsigned char>&&, 
    TArgs&&... args)
{
    return _Value((val & ~length_mask) | length_char, 
        std::forward<TArgs>(args)...);
}
    
template<typename TValue>
template<typename... TArgs>
constexpr typename Character<TValue>::ValueType 
Character<TValue>::_Value(ValueType val, LengthType<std::wint_t>&&, 
    TArgs&&... args)
{
    return _Value((val & ~length_mask) | length_wchar, 
        std::forward<TArgs>(args)...);
}

template<typename TValue>
constexpr typename Character<TValue>::ValueType 
Character<TValue>::GetValue() const
{
    return m_value;
}

} //!flag

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_FLAG_CHARACTER_H_