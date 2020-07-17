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

class Character
{
public:
    typedef std::uint8_t ValueType;
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
public:
    static constexpr ValueType char_format = length_char;
    static constexpr ValueType wchar_format = length_wchar;
    static constexpr ValueType w_char_format = length_char | width;
    static constexpr ValueType w_wchar_format = length_wchar | width;
private:
    static constexpr ValueType length_mask = length_char | length_wchar;
private:
    ValueType m_value;
public:
    inline constexpr Character();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        Character>::value, int>::type = 0>
    inline constexpr Character(TArg&& arg, TArgs&& ... args);
public:
    inline ~Character() = default;
public:
    inline constexpr Character(const Character& cpy);
    inline constexpr Character(Character&& mov);
public:
    Character& operator=(const Character&) = delete;
    Character& operator=(Character&&) = delete;
private:
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, 
        LengthType<unsigned char>&&, TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, LengthType<std::wint_t>&&,
        TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Character::Character() :
    m_value(good | length_char)
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    Character>::value, int>::type>
inline constexpr Character::Character(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good | length_char, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...))
{}

inline constexpr Character::Character(const Character& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr Character::Character(Character&& mov) :
    m_value(mov.m_value)
{}

inline constexpr typename Character::ValueType 
Character::_Value(ValueType val)
{
    return val;
}

template<typename... TArgs>
inline constexpr typename Character::ValueType 
Character::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value(val | width, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Character::ValueType 
Character::_Value(ValueType val, LengthType<unsigned char>&&, 
    TArgs&&... args)
{
    return _Value((val & ~length_mask) | length_char, 
        std::forward<TArgs>(args)...);
}
    
template<typename... TArgs>
inline constexpr typename Character::ValueType 
Character::_Value(ValueType val, LengthType<std::wint_t>&&, 
    TArgs&&... args)
{
    return _Value((val & ~length_mask) | length_wchar, 
        std::forward<TArgs>(args)...);
}

inline constexpr typename Character::ValueType 
Character::GetValue() const
{
    return m_value;
}

} //!flag

} //!param

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_PARAM_FLAG_CHARACTER_H_