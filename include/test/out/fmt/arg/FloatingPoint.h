#ifndef TEST_OUT_FMT_ARG_FLOATINGPOINT_H_
#define TEST_OUT_FMT_ARG_FLOATINGPOINT_H_

#include "../../../System.h"
#include "../../../trait/out/fmt/IsFlag.h"
#include "../../print/imp/FloatingPoint.h"
#include "../Flag.h"
#include "../Argument.h"

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
class FloatingPoint;

} //!arg

} //!fmt

} //!out

} //test

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
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
private:
    template<typename TFlagIntegerValue, TFlagIntegerValue VFlagIntegerValue>
    using FlagSpecifierType_ = 
        typename FlagType::template SpecifierType<VFlagIntegerValue>;
private:
    template<typename TFlagIntegerValue, typename... TFlagArgs,
        TFlagIntegerValue VSpecifierFloatingPoint_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierFloatingPoint() == 0 ?
                FlagType::specifier_fp_fixed : 0),
        TFlagIntegerValue VSpecifierCase_ = 
            (VSpecifierFloatingPoint_ != 0 &&
                FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_fp |
            VSpecifierFloatingPoint_ | VSpecifierCase_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline FloatingPoint();
    template<typename... TFlagArgs>
    inline FloatingPoint(float val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline FloatingPoint(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<float>::GetFlag;
    using test::out::fmt::Argument<float>::GetValue;
    using test::out::fmt::Argument<float>::GetWidth;
    using test::out::fmt::Argument<float>::GetLength;
    using test::out::fmt::Argument<float>::GetPrecision;
    using test::out::fmt::Argument<float>::GetFormatOutput;
};

template<>
class FloatingPoint<double> :
    public test::out::fmt::Argument<double>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
private:
    template<typename TFlagIntegerValue, TFlagIntegerValue VFlagIntegerValue>
    using FlagSpecifierType_ = 
        typename FlagType::template SpecifierType<VFlagIntegerValue>;
private:
    template<typename TFlagIntegerValue, typename... TFlagArgs,
        TFlagIntegerValue VSpecifierFloatingPoint_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierFloatingPoint() == 0 ?
                FlagType::specifier_fp_fixed : 0),
        TFlagIntegerValue VSpecifierCase_ = 
            (VSpecifierFloatingPoint_ != 0 &&
                FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_fp |
            VSpecifierFloatingPoint_ | VSpecifierCase_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline FloatingPoint();
    template<typename... TFlagArgs>
    inline FloatingPoint(double val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline FloatingPoint(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<double>::GetFlag;
    using test::out::fmt::Argument<double>::GetValue;
    using test::out::fmt::Argument<double>::GetWidth;
    using test::out::fmt::Argument<double>::GetLength;
    using test::out::fmt::Argument<double>::GetPrecision;
    using test::out::fmt::Argument<double>::GetFormatOutput;
};

template<>
class FloatingPoint<long double> :
    public test::out::fmt::Argument<long double>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
private:
    template<typename TFlagIntegerValue, TFlagIntegerValue VFlagIntegerValue>
    using FlagSpecifierType_ = 
        typename FlagType::template SpecifierType<VFlagIntegerValue>;
private:
    template<typename TFlagIntegerValue, typename... TFlagArgs,
        TFlagIntegerValue VSpecifierFloatingPoint_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierFloatingPoint() == 0 ?
                FlagType::specifier_fp_fixed : 0),
        TFlagIntegerValue VSpecifierCase_ = 
            (VSpecifierFloatingPoint_ != 0 &&
                FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_fp |
            VSpecifierFloatingPoint_ | VSpecifierCase_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline FloatingPoint();
    template<typename... TFlagArgs>
    inline FloatingPoint(long double val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline FloatingPoint(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<long double>::GetFlag;
    using test::out::fmt::Argument<long double>::GetValue;
    using test::out::fmt::Argument<long double>::GetWidth;
    using test::out::fmt::Argument<long double>::GetLength;
    using test::out::fmt::Argument<long double>::GetPrecision;
};

constexpr inline FloatingPoint<float>::FloatingPoint() :
    test::out::fmt::Argument<float>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<float>{})
{}

template<typename... TFlagArgs>
inline FloatingPoint<float>::FloatingPoint(float val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<float>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<float>{},
        test::out::fmt::flag::Value<float>{val},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline FloatingPoint<float>::FloatingPoint(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<float>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<float>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline FloatingPoint<double>::FloatingPoint() :
    test::out::fmt::Argument<double>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<double>{})
{}

template<typename... TFlagArgs>
inline FloatingPoint<double>::FloatingPoint(double val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<double>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<double>{},
        test::out::fmt::flag::Value<double>{val},
        std::forward<TFlagArgs>(flags)...)

{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline FloatingPoint<double>::FloatingPoint(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<double>(FlagSpecifierType<TFlagArg, 
            TFlagArgs...>{},
        test::out::fmt::flag::Define<double>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)

{}

constexpr inline FloatingPoint<long double>::FloatingPoint() :
    test::out::fmt::Argument<long double>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<long double>{})
{}

template<typename... TFlagArgs>
inline FloatingPoint<long double>::FloatingPoint(long double val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<long double>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<long double>{},
        test::out::fmt::flag::Value<long double>{val},
        std::forward<TFlagArgs>(flags)...)

{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline FloatingPoint<long double>::FloatingPoint(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<long double>(FlagSpecifierType<TFlagArg,
            TFlagArgs...>{},
        test::out::fmt::flag::Define<long double>{}, 
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_FLOATINGPOINT_H_
