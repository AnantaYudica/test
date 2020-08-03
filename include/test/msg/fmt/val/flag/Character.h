#ifndef TEST_MSG_FMT_VAL_FLAG_CHARACTER_H_
#define TEST_MSG_FMT_VAL_FLAG_CHARACTER_H_

#include "../../arg/Width.h"
#include "../../arg/Define.h"

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
namespace val
{
namespace flag
{

class Character
{
public:
    typedef std::uint8_t ValueType;
    typedef test::msg::fmt::arg::Width WidthType;
    template<typename T>
    using DefineType = test::msg::fmt::arg::Define<T>;
public:
    enum : ValueType
    {
        good = 0,
        define_char = 1,
        define_wchar = 2,
        width = 4
    };
public:
    static constexpr ValueType char_format = define_char;
    static constexpr ValueType wchar_format = define_wchar;
    static constexpr ValueType w_char_format = define_char | width;
    static constexpr ValueType w_wchar_format = define_wchar | width;
private:
    static constexpr ValueType define_mask = define_char | define_wchar;
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
    inline Character& operator=(const Character& cpy);
    inline Character& operator=(Character&& mov);
private:
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<char>&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, DefineType<wchar_t>&&,
        TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Character::Character() :
    m_value(good | define_char)
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    Character>::value, int>::type>
inline constexpr Character::Character(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good | define_char, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...))
{}

inline constexpr Character::Character(const Character& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr Character::Character(Character&& mov) :
    m_value(mov.m_value)
{}

inline Character& Character::operator=(const Character& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline Character& Character::operator=(Character&& mov)
{
    m_value = mov.m_value;
    return *this;
}

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
Character::_Value(ValueType val, DefineType<char>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_char, 
        std::forward<TArgs>(args)...);
}
    
template<typename... TArgs>
inline constexpr typename Character::ValueType 
Character::_Value(ValueType val, DefineType<wchar_t>&&, 
    TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_wchar, 
        std::forward<TArgs>(args)...);
}

inline constexpr typename Character::ValueType 
Character::GetValue() const
{
    return m_value;
}

} //!flag

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_FLAG_CHARACTER_H_