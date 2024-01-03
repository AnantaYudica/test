#ifndef TEST_OUT_FMT_ARG_STRING_H_
#define TEST_OUT_FMT_ARG_STRING_H_

#include "../../../System.h"
#include "../../../Pointer.h"
#include "../../../trait/out/fmt/IsFlag.h"
#include "../Argument.h"
#include "../Flag.h"

#include <type_traits>
#include <utility>
#include <cwchar>

namespace test
{
namespace out
{
namespace fmt
{
namespace arg
{

template<typename T>
class String;

} //!arg

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_ARG_STRING_DLEVEL

#define TEST_OUT_FMT_ARG_STRING_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_STRING_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_STRING_DLEVEL, 
    "test::out::fmt::arg::String", 
    test::out::fmt::arg::String<T>);

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
class String
{};

template<>
class String<char*> :
    public test::out::fmt::Argument<char*>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    using FlagSpecifierType = 
        typename FlagType::template SpecifierType<FlagType::specifier_str>;
public:
    constexpr inline String();
    template<typename... TFlagArgs>
    inline String(const char* val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    inline String(char* val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    inline String(test::Pointer<char> val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline String(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<char*>::GetFlag;
    using test::out::fmt::Argument<char*>::GetValue;
    using test::out::fmt::Argument<char*>::GetWidth;
    using test::out::fmt::Argument<char*>::GetLength;
    using test::out::fmt::Argument<char*>::GetPrecision;
    using test::out::fmt::Argument<char*>::GetFormatOutput;
};

template<>
class String<wchar_t*> :
    public test::out::fmt::Argument<wchar_t*>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    using FlagSpecifierType = 
        typename FlagType::template SpecifierType<FlagType::specifier_str>;
public:
    constexpr inline String();
    template<typename... TFlagArgs>
    inline String(const wchar_t* val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    inline String(wchar_t* val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    inline String(test::Pointer<wchar_t> val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline String(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<wchar_t*>::GetFlag;
    using test::out::fmt::Argument<wchar_t*>::GetValue;
    using test::out::fmt::Argument<wchar_t*>::GetWidth;
    using test::out::fmt::Argument<wchar_t*>::GetLength;
    using test::out::fmt::Argument<wchar_t*>::GetPrecision;
    using test::out::fmt::Argument<wchar_t*>::GetFormatOutput;
};

constexpr inline String<char*>::String() :
    test::out::fmt::Argument<char*>(FlagSpecifierType{},
        test::out::fmt::flag::Define<char>{})
{}

template<typename... TFlagArgs>
inline String<char*>::String(const char* val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<char*>(FlagSpecifierType{},
        test::out::fmt::flag::Value<char*>(const_cast<char*>(val)),
        test::out::fmt::flag::Define<char>{},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename... TFlagArgs>
inline String<char*>::String(char* val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<char*>(FlagSpecifierType{},
        test::out::fmt::flag::Value<char*>(val),
            test::out::fmt::flag::Define<char>{},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::
        IsFlag<TFlagArg_>::Value, int>::type>
inline String<char*>::String(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<char*>(FlagSpecifierType{},
        test::out::fmt::flag::Define<char>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline String<wchar_t*>::String() :
    test::out::fmt::Argument<wchar_t*>(FlagSpecifierType{},
        test::out::fmt::flag::Define<wchar_t>{})
{}

template<typename... TFlagArgs>
inline String<wchar_t*>::String(const wchar_t* val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<wchar_t*>(FlagSpecifierType{},
        test::out::fmt::flag::Value<wchar_t*>(const_cast<wchar_t*>(val)),
        test::out::fmt::flag::Define<wchar_t>{},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename... TFlagArgs>
inline String<wchar_t*>::String(wchar_t* val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<wchar_t*>(FlagSpecifierType{},
        test::out::fmt::flag::Value<wchar_t*>(val),
        test::out::fmt::flag::Define<wchar_t>{},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::
        IsFlag<TFlagArg_>::Value, int>::type>
inline String<wchar_t*>::String(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<wchar_t*>(FlagSpecifierType{},
        test::out::fmt::flag::Define<wchar_t>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_POINTER_H_
