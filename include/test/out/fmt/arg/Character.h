#ifndef TEST_OUT_FMT_ARG_CHARACTER_H_
#define TEST_OUT_FMT_ARG_CHARACTER_H_

#include "../../../System.h"
#include "../../../trait/out/fmt/IsFlag.h"
#include "../Flag.h"
#include "../Argument.h"
#include "../Definition.h"

#include <type_traits>
#include <utility>
#include <cwchar>

namespace test::out::fmt::arg
{

template<typename T>
class Character;

}

#ifndef TEST_OUT_FMT_ARG_CHARACTER_DLEVEL

#define TEST_OUT_FMT_ARG_CHARACTER_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_CHARACTER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_CHARACTER_DLEVEL, 
    "test::out::fmt::arg::Character", 
    test::out::fmt::arg::Character<T>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace out
{
namespace fmt
{
namespace arg
{

template<typename T>
class Character
{};

template<>
class Character<char> :
    public test::out::fmt::Argument<char>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    constexpr inline Character();
    template<typename... TFlagArgs>
    constexpr inline Character(char val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    constexpr inline Character(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<char>::GetFlag;
    using test::out::fmt::Argument<char>::GetValue;
    using test::out::fmt::Argument<char>::GetWidth;
    using test::out::fmt::Argument<char>::GetLength;
    using test::out::fmt::Argument<char>::GetPrecision;
    using test::out::fmt::Argument<char>::GetFormatOutput;
};

template<>
class Character<wchar_t> :
    public test::out::fmt::Argument<wchar_t>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    constexpr inline Character();
    template<typename... TFlagArgs>
    constexpr inline Character(wchar_t val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    constexpr inline Character(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<wchar_t>::GetFlag;
    using test::out::fmt::Argument<wchar_t>::GetValue;
    using test::out::fmt::Argument<wchar_t>::GetWidth;
    using test::out::fmt::Argument<wchar_t>::GetLength;
    using test::out::fmt::Argument<wchar_t>::GetPrecision;
    using test::out::fmt::Argument<wchar_t>::GetFormatOutput;

};

constexpr inline Character<char>::Character() :
    test::out::fmt::Argument<char>(FlagType::specifier_ch, 
        test::out::fmt::flag::Define<char>{})
{}

template<typename... TFlagArgs>
constexpr inline Character<char>::Character(char val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<char>(FlagType::specifier_ch, 
        test::out::fmt::flag::Define<char>{},
        test::out::fmt::flag::Value<char>{val},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
constexpr inline Character<char>::Character(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<char>(FlagType::specifier_ch,
            test::out::fmt::flag::Define<char>{},
            std::forward<TFlagArg>(flag),
            std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Character<wchar_t>::Character() :
    test::out::fmt::Argument<wchar_t>(FlagType::specifier_ch,
        test::out::fmt::flag::Define<wchar_t>{})
{}

template<typename... TFlagArgs>
constexpr inline Character<wchar_t>::Character(wchar_t val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<wchar_t>(FlagType::specifier_ch,
            test::out::fmt::flag::Define<wchar_t>{}, 
            test::out::fmt::flag::Value<wchar_t>{val},
            std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
constexpr inline Character<wchar_t>::Character(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<wchar_t>(FlagType::specifier_ch,
            test::out::fmt::flag::Define<wchar_t>{}, 
            std::forward<TFlagArg>(flag),
            std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_CHARACTER_H_
