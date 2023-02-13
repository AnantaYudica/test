#ifndef TEST_OUT_FMT_ARGUMENT_H_
#define TEST_OUT_FMT_ARGUMENT_H_

#include "../../System.h"
#include "../../Pointer.h"
#include "Definition.h"
#include "Flag.h"

#include <type_traits>
#include <utility>
#include <cstring>
#include <cwchar>

namespace test::out::fmt
{

template<typename T, typename TFlag, typename>
class Argument;

}

#ifndef TEST_OUT_FMT_ARGUMENT_DLEVEL

#define TEST_OUT_FMT_ARGUMENT_DLEVEL 2

#endif //!TEST_OUT_FMT_ARGUMENT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TFlag>,\
    test::sys::dbg::Type<TEnable>

template<typename T, typename TFlag, typename TEnable>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARGUMENT_DLEVEL, 
    "test::out::fmt::Argument", 
    test::out::fmt::Argument<T, TFlag, TEnable>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace out
{
namespace fmt
{

template<typename T, typename TFlag = 
    typename test::out::fmt::Definition::FlagType, typename = 
        typename test::out::fmt::Definition::String<T>::DefaultType>
class Argument : public Argument<void, TFlag>
{
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
public:
    typedef test::out::fmt::Definition DefinitionType;
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
    using Argument<void, TFlag>::GetFormatOutput;
};

template<typename TFlag>
class Argument<void, TFlag, void>
{
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    typedef typename DefinitionType::FormatOutputType FormatOutputType;
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
    static constexpr std::false_type IsOutputType_(...);
    template<typename... TCharArgs>
    static constexpr std::true_type 
        IsOutputType_(test::out::fmt::flag::Output<TCharArgs...>);
private:
    template<typename T_>
    using IsWidthType = decltype(IsWidthType_(std::declval<T_>()));
private:
    template<typename T_>
    using IsLengthType = decltype(IsLengthType_(std::declval<T_>()));
private:
    template<typename T_>
    using IsOutputType = decltype(IsOutputType_(std::declval<T_>()));
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
    static constexpr FormatOutputType Output();
    template<typename... TCharArgs, typename... TFlagArgs>
    static constexpr FormatOutputType Output(test::out::fmt::flag::
        Output<TCharArgs...>&& out, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsOutputType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr FormatOutputType Output(TFlagArg&& flag, 
        TFlagArgs&&... flags);
private:
    FlagType m_flag;
    int m_width;
    int m_length;
    FormatOutputType m_fmtout;
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
public:
    constexpr FormatOutputType GetFormatOutput() const;
};

template<typename TCharPtr, typename TFlag>
class Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type> : 
        public Argument<void, TFlag>
{
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    typedef typename DefinitionType::String<TCharPtr>::CharacterType 
        CharacterType;
    typedef typename test::Pointer<CharacterType> StringPointerType;
private:
    static constexpr std::false_type IsValueType_(...);
    template<typename T_>
    static constexpr std::true_type 
        IsValueType_(test::out::fmt::flag::Value<T_>);
private:
    template<typename T_>
    using IsValueType = decltype(IsValueType_(std::declval<T_>()));
private:
    static constexpr bool IsContainValueType_()
    {
        return false;
    }
    template<typename TArg, typename... TArgs,
        typename TArg_ = typename std::remove_cv<
            typename std::remove_reference<TArg>::type>::type,
        typename TCond = IsValueType<TArg_>,
        typename std::enable_if<!TCond::value, int>::type = 0>
    static constexpr bool IsContainValueType_(TArg&& arg, TArgs&&... args)
    {
        return IsContainValueType_(std::forward<TArgs>(args)...);
    }
    template<typename TArg, typename... TArgs,
        typename TArg_ = typename std::remove_cv<
            typename std::remove_reference<TArg>::type>::type,
        typename TCond_ = IsValueType<TArg_>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    static constexpr bool IsContainValueType_(TArg&& arg, TArgs&&... args)
    {
        return true;
    }
private:
    template<typename... TArgs>
    using IsContainValueType = std::integral_constant<bool, 
        IsContainValueType_( typename std::remove_reference<TArgs>::type()...)>;
private:
    static constexpr const CharacterType* Value();
    template<typename... TFlagArgs>
    static constexpr const CharacterType* Value(test::out::fmt::flag::
        Value<const CharacterType*>&& val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    static constexpr const CharacterType* Value(test::out::fmt::flag::
        Value<CharacterType*>&& val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsValueType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr const CharacterType* Value(TFlagArg&& flag,
        TFlagArgs&&... flags);
private:
    StringPointerType m_value;
public:
    constexpr Argument();
    template<typename... TFlagArgs, 
        typename TCond_ = IsContainValueType<TFlagArgs...>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    constexpr Argument(FlagIntegerValueType specifier, TFlagArgs&&... flags);
    template<typename... TFlagArgs, 
        typename TCond_ = IsContainValueType<TFlagArgs...>,
        typename TChar_ = CharacterType,
        typename std::enable_if<TCond_::value &&
            std::is_same<char, TChar_>::value, int>::type = 1>
    Argument(FlagIntegerValueType specifier, TFlagArgs&&... flags);
    template<typename... TFlagArgs, 
        typename TCond_ = IsContainValueType<TFlagArgs...>,
        typename TChar_ = CharacterType,
        typename std::enable_if<TCond_::value &&
            std::is_same<wchar_t, TChar_>::value, int>::type = 2>
    Argument(FlagIntegerValueType specifier, TFlagArgs&&... flags);
public:
    Argument(const Argument<TCharPtr, TFlag>&) = delete;
    Argument(Argument<TCharPtr, TFlag>&&) = delete;
public:
    Argument<TCharPtr, TFlag>& 
        operator=(const Argument<TCharPtr, TFlag>&) = delete;
    Argument<TCharPtr, TFlag>& 
        operator=(Argument<TCharPtr, TFlag>&&) = delete;
public:
    using Argument<void, TFlag>::GetFlag;
public:
    StringPointerType GetValue() const;
public:
    using Argument<void, TFlag>::GetWidth;
    using Argument<void, TFlag>::GetLength;
    using Argument<void, TFlag>::GetPrecision;
    using Argument<void, TFlag>::GetFormatOutput;
};

template<typename T, typename TFlag, typename TEnable>
constexpr T Argument<T, TFlag, TEnable>::Value()
{
    return {};
}

template<typename T, typename TFlag, typename TEnable>
template<typename T_, typename... TFlagArgs>
constexpr T Argument<T, TFlag, TEnable>::
    Value(test::out::fmt::flag::Value<T_>&& val, TFlagArgs&&... flags)
{
    return val.IsDefault() ? Value(std::forward<TFlagArgs>(flags)...) : 
        val.GetValue();
}

template<typename T, typename TFlag, typename TEnable>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr T Argument<T, TFlag, TEnable>::Value(TFlagArg&& flag, 
    TFlagArgs&&... flags)
{
    return Value(std::forward<TFlagArgs>(flags)...);
}

template<typename T, typename TFlag, typename TEnable>
constexpr Argument<T, TFlag, TEnable>::Argument() :
    Argument<void, TFlag>(),
    m_value()
{}

template<typename T, typename TFlag, typename TEnable>
template<typename... TFlagArgs>
constexpr Argument<T, TFlag, TEnable>::Argument(FlagIntegerValueType specifier,
        TFlagArgs&&... flags) :
    Argument<void, TFlag>(specifier, std::forward<TFlagArgs>(flags)...),
    m_value(Value(std::forward<TFlagArgs>(flags)...))
{}

template<typename T, typename TFlag, typename TEnable>
constexpr T Argument<T, TFlag, TEnable>::GetValue() const
{
    return m_value;
}

template<typename TFlag>
constexpr int Argument<void, TFlag, void>::Width()
{
    return 0;
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag, void>::
    Width(test::out::fmt::flag::Width&& width,TFlagArgs&&... flags)
{
    return width.IsDefault() ? Width(std::forward<TFlagArgs>(flags)...) : 
        width.GetValue();
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr int Argument<void, TFlag, void>::Width(TFlagArg&& flag, 
    TFlagArgs&&... flags)
{
    return Width(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
constexpr int Argument<void, TFlag, void>::Length()
{
    return 0;
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag, void>::
    Length(test::out::fmt::flag::Length&& length, TFlagArgs&&... flags)
{
    return length.IsDefault() ? Length(std::forward<TFlagArgs>(flags)...) : 
        length.GetValue();
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag, void>::
    Length(test::out::fmt::flag::Precision&& precision, TFlagArgs&&... flags)
{
    return precision.IsDefault() ? Length(std::forward<TFlagArgs>(flags)...) : 
        precision.GetValue();
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr int Argument<void, TFlag, void>::
    Length(TFlagArg&& flag, TFlagArgs&&... flags)
{
    return Length(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::Output()
{
    return {};
}

template<typename TFlag>
    template<typename... TCharArgs, typename... TFlagArgs>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::Output(test::out::fmt::flag::
    Output<TCharArgs...>&& out, TFlagArgs&&... flags)
{
    return {std::forward<test::out::fmt::flag::Output<TCharArgs...>>(out)};
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename TCond_, typename std::enable_if<!TCond_::value, int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag>::Output(TFlagArg&& flag, TFlagArgs&&... flags)
{
    return Output(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
constexpr Argument<void, TFlag, void>::Argument() :
    m_flag(),
    m_width(0),
    m_length(0),
    m_fmtout()
{}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr Argument<void, TFlag, void>::Argument(FlagIntegerValueType specifier,
        TFlagArgs&&... flags) :
    m_flag(specifier, std::forward<TFlagArgs>(flags)...),
    m_width(Width(std::forward<TFlagArgs>(flags)...)),
    m_length(Length(std::forward<TFlagArgs>(flags)...)),
    m_fmtout(Output(std::forward<TFlagArgs>(flags)...))
{}

template< typename TFlag>
typename Argument<void, TFlag, void>:: FlagType
Argument<void, TFlag, void>::GetFlag() const
{
    return m_flag;
}

template< typename TFlag>
constexpr int Argument<void, TFlag, void>::GetWidth() const
{
    return m_width;
}

template< typename TFlag>
constexpr int Argument<void, TFlag, void>::GetLength() const
{
    return m_length;
}

template< typename TFlag>
constexpr int Argument<void, TFlag, void>::GetPrecision() const
{
    return m_length;
}

template< typename TFlag>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::GetFormatOutput() const
{
    return m_fmtout;
}

template<typename TCharPtr, typename TFlag>
constexpr const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::Value()
{
    return NULL;
}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs>
constexpr const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Value(test::out::fmt::flag::Value<const CharacterType*>&& val, 
            TFlagArgs&&... flags)
{
    return val.IsDefault() ? Value(std::forward<TFlagArgs>(flags)...) : 
        val.GetValue();
}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs>
constexpr const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Value(test::out::fmt::flag::Value<CharacterType*>&& val, 
            TFlagArgs&&... flags)
{
    return val.IsDefault() ? Value(std::forward<TFlagArgs>(flags)...) : 
        val.GetValue();
}

template<typename TCharPtr, typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename TCond_, typename std::enable_if<!TCond_::value, int>::type>
constexpr const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Value(TFlagArg&& flag, TFlagArgs&&... flags)
{
    return Value(std::forward<TFlagArgs>(flags)...);
}

template<typename TCharPtr, typename TFlag>
constexpr Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::Argument() :
        Argument<void, TFlag>(),
        m_value(nullptr)
{}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Argument(FlagIntegerValueType specifier, TFlagArgs&&... flags) :
            Argument<void, TFlag>(specifier, 
                std::forward<TFlagArgs>(flags)...),
            m_value(nullptr)
{}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs, typename TCond_, typename TChar_,
    typename std::enable_if<TCond_::value &&
        std::is_same<char, TChar_>::value, int>::type>
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Argument(FlagIntegerValueType specifier, TFlagArgs&&... flags) :
            Argument<void, TFlag>(specifier, 
                std::forward<TFlagArgs>(flags)...),
            m_value(nullptr)
{
    const char* value = Value(std::forward<TFlagArgs>(flags)...);
    if (value != NULL)
    {
        const std::size_t max_len = test::out::fmt::Definition::string_max_len;

#ifdef __STDC_LIB_EXT1__
        const std::size_t len = strnlen_s(value, max_len);
#else
        std::size_t len = strlen(value);
        if (len >= max_len)
        {
            len = max_len;
        }
#endif
        m_value = test::Pointer<char>(test::ptr::arg::Array{len + 1});

#ifdef __STDC_LIB_EXT1__
        memcpy_s(&*m_value, len, value, len);
#else
        memcpy(&*m_value, value, len);
#endif 
        m_value[len] = '\0';
    }
}
    
template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs, typename TCond_, typename TChar_,
    typename std::enable_if<TCond_::value &&
        std::is_same<wchar_t, TChar_>::value, int>::type>
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Argument(FlagIntegerValueType specifier, TFlagArgs&&... flags) :
            Argument<void, TFlag>(specifier, 
                std::forward<TFlagArgs>(flags)...),
            m_value(nullptr)
{
    const wchar_t* value = Value(std::forward<TFlagArgs>(flags)...);
    if (value != NULL)
    {
        const std::size_t max_len = test::out::fmt::Definition::string_max_len;

#ifdef __STDC_LIB_EXT1__
        const std::size_t len = wcsnlen_s(value, max_len);
#else
        std::size_t len = wcslen(value);
        if (len >= max_len)
        {
            len = max_len;
        }
#endif
        m_value = test::Pointer<wchar_t>(test::ptr::arg::Array{len + 1});

#ifdef __STDC_LIB_EXT1__
        wmemcpy_s(&*m_value, len, value, len);
#else
        wmemcpy(&*m_value, value, len);
#endif 
        m_value[len] = L'\0';
    }
}

template<typename TCharPtr, typename TFlag>
typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::StringPointerType 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::GetValue() const
{
    return m_value;
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_BOOLEAN_H_
