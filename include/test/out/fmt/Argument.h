#ifndef TEST_OUT_FMT_ARGUMENT_H_
#define TEST_OUT_FMT_ARGUMENT_H_

#include "../../System.h"
#include "Definition.h"
#include "Flag.h"

#include <type_traits>
#include <utility>

namespace test::out::fmt
{

template<typename T, typename TFlag>
class Argument;

}

#ifndef TEST_OUT_FMT_ARGUMENT_DLEVEL

#define TEST_OUT_FMT_ARGUMENT_DLEVEL 2

#endif //!TEST_OUT_FMT_ARGUMENT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TFlag>

template<typename T, typename TFlag>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARGUMENT_DLEVEL, 
    "test::out::fmt::Argument", 
    test::out::fmt::Argument<T, TFlag>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace out
{
namespace fmt
{

template<typename T, typename TFlag = 
    typename test::out::fmt::Definition::FlagType>
class Argument : public Argument<void, TFlag>
{
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
private:
    static constexpr std::false_type IsValueType_(...);
    template<typename T_>
    static constexpr std::true_type 
        IsValueType_(test::out::fmt::flag::Value<T_>);
private:
    template<typename T_>
    using IsValueType = decltype(IsValueType_(std::declval<T_>()));
private:
    static constexpr T Value();
    template<typename T_, typename... TFlagArgs>
    static constexpr T Value(test::out::fmt::flag::Value<T_>&& val, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsValueType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr T Value(TFlagArg&& flag, TFlagArgs&&... flags);
private:
    T m_value;
public:
    constexpr Argument();
    template<typename... TFlagArgs>
    constexpr Argument(FlagIntegerValueType specifier, 
        TFlagArgs&&... flags);
public:
    Argument(const Argument<T>&) = delete;
    Argument(Argument<T>&&) = delete;
public:
    Argument<T>& operator=(const Argument<T>&) = delete;
    Argument<T>& operator=(Argument<T>&&) = delete;
public:
    using Argument<void, TFlag>::GetFlag;
public:
    constexpr T GetValue() const;
public:
    using Argument<void, TFlag>::GetWidth;
    using Argument<void, TFlag>::GetLength;
    using Argument<void, TFlag>::GetPrecision;
};


template<typename TFlag>
class Argument<void, TFlag>
{
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
private:
    static constexpr std::false_type IsWidthType_(...);
    static constexpr std::true_type 
        IsWidthType_(test::out::fmt::flag::Width);
private:
    static constexpr std::false_type IsLengthType_(...);
    static constexpr std::true_type 
        IsLengthType_(test::out::fmt::flag::Length);
    static constexpr std::true_type 
        IsLengthType_(test::out::fmt::flag::Precision);
private:
    template<typename T_>
    using IsWidthType = decltype(IsWidthType_(std::declval<T_>()));
private:
    template<typename T_>
    using IsLengthType = decltype(IsLengthType_(std::declval<T_>()));
private:
    static constexpr int Width();
    template<typename... TFlagArgs>
    static constexpr int Width(test::out::fmt::flag::Width&& width, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsWidthType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr int Width(TFlagArg&& flag, TFlagArgs&&... flags);
private:
    static constexpr int Length();
    template<typename... TFlagArgs>
    static constexpr int Length(test::out::fmt::flag::Length&& length, 
        TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    static constexpr int Length(test::out::fmt::flag::Precision&& precision, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsLengthType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr int Length(TFlagArg&& flag, TFlagArgs&&... flags);
private:
    FlagType m_flag;
    int m_width;
    int m_length;
public:
    constexpr Argument();
    template<typename... TFlagArgs>
    constexpr Argument(FlagIntegerValueType specifier, 
        TFlagArgs&&... flags);
public:
    Argument(const Argument<void, TFlag>&) = delete;
    Argument(Argument<void, TFlag>&&) = delete;
public:
    Argument<void, TFlag>& operator=(const Argument<void, TFlag>&) = delete;
    Argument<void, TFlag>& operator=(Argument<void, TFlag>&&) = delete;
public:
    FlagType GetFlag() const;
public:
    constexpr int GetWidth() const;
public:
    constexpr int GetLength() const;
public:
    constexpr int GetPrecision() const;
};

template<typename T, typename TFlag>
constexpr T Argument<T, TFlag>::Value()
{
    return {};
}

template<typename T, typename TFlag>
template<typename T_, typename... TFlagArgs>
constexpr T Argument<T, TFlag>::Value(test::out::fmt::flag::Value<T_>&& val, 
    TFlagArgs&&... flags)
{
    return val.IsDefault() ? Value(std::forward<TFlagArgs>(flags)...) : 
        val.GetValue();
}

template<typename T, typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr T Argument<T, TFlag>::Value(TFlagArg&& flag, TFlagArgs&&... flags)
{
    return Value(std::forward<TFlagArgs>(flags)...);
}

template<typename T, typename TFlag>
constexpr Argument<T, TFlag>::Argument() :
    Argument<void, TFlag>(),
    m_value()
{}

template<typename T, typename TFlag>
template<typename... TFlagArgs>
constexpr Argument<T, TFlag>::Argument(FlagIntegerValueType specifier, 
        TFlagArgs&&... flags) :
    Argument<void, TFlag>(specifier, std::forward<TFlagArgs>(flags)...),
    m_value(Value(std::forward<TFlagArgs>(flags)...))
{}

template<typename T, typename TFlag>
constexpr T Argument<T, TFlag>::GetValue() const
{
    return m_value;
}

template<typename TFlag>
constexpr int Argument<void, TFlag>::Width()
{
    return 0;
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag>::Width(test::out::fmt::flag::Width&& width,
    TFlagArgs&&... flags)
{
    return width.IsDefault() ? Width(std::forward<TFlagArgs>(flags)...) : 
        width.GetValue();
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr int Argument<void, TFlag>::Width(TFlagArg&& flag, 
    TFlagArgs&&... flags)
{
    return Width(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
constexpr int Argument<void, TFlag>::Length()
{
    return 0;
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag>::
    Length(test::out::fmt::flag::Length&& length, TFlagArgs&&... flags)
{
    return length.IsDefault() ? Length(std::forward<TFlagArgs>(flags)...) : 
        length.GetValue();
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag>::
    Length(test::out::fmt::flag::Precision&& precision, TFlagArgs&&... flags)
{
    return precision.IsDefault() ? Length(std::forward<TFlagArgs>(flags)...) : 
        precision.GetValue();
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr int Argument<void, TFlag>::
    Length(TFlagArg&& flag, TFlagArgs&&... flags)
{
    return Length(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
constexpr Argument<void, TFlag>::Argument() :
    m_flag(),
    m_width(0),
    m_length(0)
{}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr Argument<void, TFlag>::Argument(FlagIntegerValueType specifier, 
        TFlagArgs&&... flags) :
    m_flag(specifier, std::forward<TFlagArgs>(flags)...),
    m_width(Width(std::forward<TFlagArgs>(flags)...)),
    m_length(Length(std::forward<TFlagArgs>(flags)...))
{}

template< typename TFlag>
typename Argument<void, TFlag>:: FlagType
Argument<void, TFlag>::GetFlag() const
{
    return m_flag;
}

template< typename TFlag>
constexpr int Argument<void, TFlag>::GetWidth() const
{
    return m_width;
}

template< typename TFlag>
constexpr int Argument<void, TFlag>::GetLength() const
{
    return m_length;
}

template< typename TFlag>
constexpr int Argument<void, TFlag>::GetPrecision() const
{
    return m_length;
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_BOOLEAN_H_
