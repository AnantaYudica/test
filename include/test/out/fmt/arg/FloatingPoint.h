#ifndef TEST_OUT_FMT_ARG_FLOATINGPOINT_H_
#define TEST_OUT_FMT_ARG_FLOATINGPOINT_H_

#include "../../../System.h"
#include "../Flag.h"
#include "../Argument.h"

#include <type_traits>
#include <utility>

namespace test::out::fmt::arg
{

template<typename T>
class FloatingPoint;

}

#ifndef TEST_OUT_FMT_ARG_FLOATINGPOINT_DLEVEL

#define TEST_OUT_FMT_ARG_FLOATINGPOINT_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_FLOATINGPOINT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_FLOATINGPOINT_DLEVEL, 
    "test::out::fmt::arg::FloatingPoint", 
    test::out::fmt::arg::FloatingPoint<T>);

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
class FloatingPoint
{};

template<>
class FloatingPoint<float> :
    public test::out::fmt::Argument<float>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    constexpr inline FloatingPoint();
    template<typename... TFlagArgs>
    constexpr inline FloatingPoint(float val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<!std::is_same<TFlagArg_, float>::value, 
            int>::type = 0>
    constexpr inline FloatingPoint(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<float>::GetFlag;
    using test::out::fmt::Argument<float>::GetValue;
    using test::out::fmt::Argument<float>::GetWidth;
    using test::out::fmt::Argument<float>::GetLength;
    using test::out::fmt::Argument<float>::GetPrecision;
};

template<>
class FloatingPoint<double> :
    public test::out::fmt::Argument<double>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    constexpr inline FloatingPoint();
    template<typename... TFlagArgs>
    constexpr inline FloatingPoint(double val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<!std::is_same<TFlagArg_, double>::value, 
            int>::type = 0>
    constexpr inline FloatingPoint(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<double>::GetFlag;
    using test::out::fmt::Argument<double>::GetValue;
    using test::out::fmt::Argument<double>::GetWidth;
    using test::out::fmt::Argument<double>::GetLength;
    using test::out::fmt::Argument<double>::GetPrecision;
};

template<>
class FloatingPoint<long double> :
    public test::out::fmt::Argument<long double>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    constexpr inline FloatingPoint();
    template<typename... TFlagArgs>
    constexpr inline FloatingPoint(long double val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<!std::is_same<TFlagArg_, long double>::value, 
            int>::type = 0>
    constexpr inline FloatingPoint(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<long double>::GetFlag;
    using test::out::fmt::Argument<long double>::GetValue;
    using test::out::fmt::Argument<long double>::GetWidth;
    using test::out::fmt::Argument<long double>::GetLength;
    using test::out::fmt::Argument<long double>::GetPrecision;
};

constexpr inline FloatingPoint<float>::FloatingPoint() :
    test::out::fmt::Argument<float>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<float>{})
{}

template<typename... TFlagArgs>
constexpr inline FloatingPoint<float>::FloatingPoint(float val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<float>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<float>{},
        test::out::fmt::flag::Value<float>{val},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<!std::is_same<TFlagArg_, float>::value, 
        int>::type>
constexpr inline FloatingPoint<float>::FloatingPoint(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<float>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<float>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline FloatingPoint<double>::FloatingPoint() :
    test::out::fmt::Argument<double>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<double>{})
{}

template<typename... TFlagArgs>
constexpr inline FloatingPoint<double>::FloatingPoint(double val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<double>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<double>{},
        test::out::fmt::flag::Value<double>{val},
        std::forward<TFlagArgs>(flags)...)

{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<!std::is_same<TFlagArg_, double>::value, 
        int>::type>
constexpr inline FloatingPoint<double>::FloatingPoint(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<double>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<double>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)

{}

constexpr inline FloatingPoint<long double>::FloatingPoint() :
    test::out::fmt::Argument<long double>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<long double>{})
{}

template<typename... TFlagArgs>
constexpr inline FloatingPoint<long double>::FloatingPoint(long double val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<long double>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<long double>{},
        test::out::fmt::flag::Value<long double>{val},
        std::forward<TFlagArgs>(flags)...)

{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<!std::is_same<TFlagArg_, long double>::value, 
        int>::type>
constexpr inline FloatingPoint<long double>::FloatingPoint(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<long double>(FlagType::specifier_fp,
        test::out::fmt::flag::Define<long double>{}, 
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_FLOATINGPOINT_H_
