#ifndef TEST_OUT_FMT_ARG_NOTHING_H_
#define TEST_OUT_FMT_ARG_NOTHING_H_

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
class Nothing;

} //!arg

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_ARG_NOTHING_DLEVEL

#define TEST_OUT_FMT_ARG_NOTHING_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_NOTHING_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_NOTHING_DLEVEL,
    "test::out::fmt::arg::Nothing",
    test::out::fmt::arg::Nothing<T>);

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
class Nothing :
    public test::out::fmt::Argument<void>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    using FlagSpecifierType = 
        typename FlagType::template SpecifierType<FlagType::specifier_blank>; 
public:
    constexpr inline Nothing();
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Nothing(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<void>::GetFlag;
    using test::out::fmt::Argument<void>::GetWidth;
    using test::out::fmt::Argument<void>::GetLength;
    using test::out::fmt::Argument<void>::GetPrecision;
    using test::out::fmt::Argument<void>::GetFormatOutput;
};

template<typename T>
constexpr inline Nothing<T>::Nothing() :
    test::out::fmt::Argument<void>(FlagSpecifierType{},
        test::out::fmt::flag::Define<void>{})
{}

template<typename T>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::
        IsFlag<TFlagArg_>::Value, int>::type>
inline Nothing<T>::Nothing(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<void>(FlagSpecifierType{},
        test::out::fmt::flag::Define<void>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //!arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_NOTHING_H_
