#ifndef TEST_MSG_FMT_VAL_FLAG_POINTER_H_
#define TEST_MSG_FMT_VAL_FLAG_POINTER_H_

#include "../../var/arg/Width.h"

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

class Pointer
{
public:
    typedef std::uint8_t ValueType;
    typedef test::msg::fmt::var::arg::Width WidthType;
public:
    enum : ValueType
    {
        good = 0,
        width = 1
    };
public:
    static constexpr ValueType pointer_format = good;
    static constexpr ValueType w_pointer_format = width;
private:
    ValueType m_value;
public:
    inline constexpr Pointer();
    template<typename TArg, typename... TArgs, typename std::enable_if<
        !std::is_same<typename std::remove_cv<TArg>::type, 
        Pointer>::value, int>::type = 0>
    inline constexpr Pointer(TArg&& arg, TArgs&& ... args);
public:
    inline ~Pointer() = default;
public:
    inline constexpr Pointer(const Pointer& cpy);
    inline constexpr Pointer(Pointer&& mov);
public:
    inline Pointer& operator=(const Pointer& cpy);
    inline Pointer& operator=(Pointer&& mov);
private:
    inline constexpr ValueType _Value(ValueType val);
    template<typename... TArgs>
    inline constexpr ValueType _Value(ValueType val, WidthType&&, 
        TArgs&&... args);
public:
    inline constexpr ValueType GetValue() const;
};

inline constexpr Pointer::Pointer() :
    m_value{good}
{}

template<typename TArg, typename... TArgs, typename std::enable_if<
    !std::is_same<typename std::remove_cv<TArg>::type, 
    Pointer>::value, int>::type>
inline constexpr Pointer::Pointer(TArg&& arg, TArgs&& ... args) :
    m_value{_Value(good, std::forward<TArg>(arg), 
        std::forward<TArgs>(args)...)}
{}

inline constexpr Pointer::Pointer(const Pointer& cpy) :
    m_value(cpy.m_value)
{}

inline constexpr Pointer::Pointer(Pointer&& mov) :
    m_value(mov.m_value)
{}

inline Pointer& Pointer::operator=(const Pointer& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline Pointer& Pointer::operator=(Pointer&& mov)
{
    m_value = mov.m_value;
    return *this;
}

inline constexpr typename Pointer::ValueType 
Pointer::_Value(ValueType val)
{
    return val;
}

template<typename... TArgs>
inline constexpr typename Pointer::ValueType 
Pointer::_Value(ValueType val, WidthType&&, TArgs&&... args)
{
    return _Value(val | width, std::forward<TArgs>(args)...);
}

inline constexpr typename Pointer::ValueType 
Pointer::GetValue() const
{
    return m_value;
}

} //!flag

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_FLAG_POINTER_H_
