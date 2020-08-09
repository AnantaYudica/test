#ifndef TEST_MSG_FMT_VAL_FLAG_STRING_H_
#define TEST_MSG_FMT_VAL_FLAG_STRING_H_

#include "../../var/arg/Width.h"
#include "../../var/arg/Length.h"
#include "../../var/arg/Define.h"

#include <cstdint>
#include <cwchar>
#include <utility>
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

class String
{
public:
    typedef std::uint8_t ValueType;
    typedef test::msg::fmt::var::arg::Width WidthType;
    typedef test::msg::fmt::var::arg::Length LengthType;
    template<typename T>
    using DefineType = test::msg::fmt::var::arg::Define<T>;
public:
    enum : ValueType
    {
        good = 0,
        define_char = 1,
        define_wchar = 2,
        width = 4,
        length = 8
    };
public:
    static constexpr ValueType char_format = define_char;
    static constexpr ValueType wchar_format = define_wchar;
    static constexpr ValueType w_char_format = define_char | width;
    static constexpr ValueType w_wchar_format = define_wchar | width;
    static constexpr ValueType l_char_format = define_char | length;
    static constexpr ValueType l_wchar_format = define_wchar | length;
    static constexpr ValueType wl_char_format = define_char | width | length;
    static constexpr ValueType wl_wchar_format = define_wchar | width | length;
private:
    static constexpr ValueType define_mask = define_char | define_wchar;
private:
    ValueType m_value;
public:
    inline constexpr String();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        String>::value, int>::type = 0>
    inline constexpr String(TArg&& arg, TArgs&& ... args);
public:
    inline ~String() = default;
public:
    inline constexpr String(const String& cpy);
    inline constexpr String(String&& mov);
public:
    inline String& operator=(const String& cpy);
    inline String& operator=(String&& mov);
private:
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, LengthType&&, 
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

inline constexpr String::String() :
    m_value(good | define_char)
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    String>::value, int>::type>
inline constexpr String::String(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good | define_char, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...))
{}

inline constexpr String::String(const String& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr String::String(String&& mov) :
    m_value(mov.m_value)
{}

inline String& String::operator=(const String& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline String& String::operator=(String&& mov)
{
    m_value = mov.m_value;
    return *this;
}

inline constexpr typename String::ValueType String::_Value(ValueType val)
{
    return val;
}

template<typename... TArgs>
inline constexpr typename String::ValueType 
String::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value(val | width, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename String::ValueType 
String::_Value(ValueType val, LengthType&&, TArgs&&... args)
{
    return _Value(val | length, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename String::ValueType 
String::_Value(ValueType val, DefineType<char>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_char, 
        std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename String::ValueType 
String::_Value(ValueType val, DefineType<wchar_t>&&, TArgs&&... args)
{
    return _Value((val & ~define_mask) | define_wchar, 
        std::forward<TArgs>(args)...);
}

inline constexpr typename String::ValueType String::GetValue() const
{
    return m_value;
}

} //!flag

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_FLAG_STRING_H_
