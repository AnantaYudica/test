#ifndef TEST_MSG_FMT_VAL_FLAG_NOTHING_H_
#define TEST_MSG_FMT_VAL_FLAG_NOTHING_H_

#include "../../var/arg/Width.h"
#include "../../var/arg/Precision.h"
#include "../../var/arg/Length.h"

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
    typedef test::msg::fmt::var::arg::Width WidthType;
    typedef test::msg::fmt::var::arg::Precision PrecisionType;
    typedef test::msg::fmt::var::arg::Length LengthType; 
public:
    enum : ValueType
    {
        good = 0,
        width = 1,
        precision = 2,
        length = 2
    }; 
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
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, PrecisionType&&, 
        TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Nothing::Nothing() :
    m_value(_Value(good))
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, Nothing>::value, 
    int>::type>
inline constexpr Nothing::Nothing(TArg&& arg, TArgs&& ... args) :
    m_value(_Value(good, std::forward<TArg>(arg), 
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
Nothing::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value(val | width, std::forward<TArgs>(args)...);
}

template<typename... TArgs>
inline constexpr typename Nothing::ValueType 
Nothing::_Value(ValueType val, PrecisionType&&, TArgs&&... args)
{
    return _Value(val | precision, std::forward<TArgs>(args)...);
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