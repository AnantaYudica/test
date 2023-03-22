#ifndef TEST_OUT_FMT_ARG_OBJECT_H_
#define TEST_OUT_FMT_ARG_OBJECT_H_

#include "../../../System.h"
#include "../../../trait/out/fmt/IsFlag.h"
#include "../Argument.h"
#include "../Flag.h"

#include <type_traits>
#include <utility>

namespace test
{
namespace out
{
namespace fmt
{
namespace arg
{

template<typename T>
class Object;

} //!arg

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_ARG_OBJECT_DLEVEL

#define TEST_OUT_FMT_ARG_OBJECT_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_OBJECT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_OBJECT_DLEVEL, 
    "test::out::fmt::arg::Object", 
    test::out::fmt::arg::Object<T>);

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
class Object :
    public test::out::fmt::Argument<T>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    using FlagSpecifierType = 
        typename FlagType::template SpecifierType<FlagType::specifier_object>;
public:
    constexpr inline Object();
    template<typename... TFlagArgs>
    inline Object(const T& val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    inline Object(T&& val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Object(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<T>::GetFlag;
    using test::out::fmt::Argument<T>::GetValue;
    using test::out::fmt::Argument<T>::GetWidth;
    using test::out::fmt::Argument<T>::GetLength;
    using test::out::fmt::Argument<T>::GetPrecision;
    using test::out::fmt::Argument<T>::GetFormatOutput;
};

template<typename T>
constexpr inline Object<T>::Object() :
    test::out::fmt::Argument<T>(FlagSpecifierType{},
        test::out::fmt::flag::Define<T>{})
{}

template<typename T>
template<typename... TFlagArgs>
inline Object<T>::Object(const T& val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<T>(FlagSpecifierType{},
        test::out::fmt::flag::Define<T>{},
        test::out::fmt::flag::Value<T>(val),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename T>
template<typename... TFlagArgs>
inline Object<T>::Object(T&& val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<T>(FlagSpecifierType{},
        test::out::fmt::flag::Define<T>{},
        test::out::fmt::flag::Value<T>(std::forward<T>(val)),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename T>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::
        IsFlag<TFlagArg_>::Value, int>::type>
inline Object<T>::Object(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<T>(FlagSpecifierType{},
        test::out::fmt::flag::Define<T>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_OBJECT_H_
