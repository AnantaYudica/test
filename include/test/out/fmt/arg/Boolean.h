#ifndef TEST_OUT_FMT_ARG_BOOLEAN_H_
#define TEST_OUT_FMT_ARG_BOOLEAN_H_

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

class Boolean;

} //!arg

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_ARG_BOOLEAN_DLEVEL

#define TEST_OUT_FMT_ARG_BOOLEAN_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_BOOLEAN_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_ARG_BOOLEAN_DLEVEL, 
    "test::out::fmt::arg::Boolean", test::out::fmt::arg::Boolean);

namespace test
{
namespace out
{
namespace fmt
{
namespace arg
{

class Boolean :
    public test::out::fmt::Argument<bool>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    using FlagSpecifierType = 
        typename FlagType::template SpecifierType<FlagType::specifier_bool>;
public:
    constexpr inline Boolean();
    template<typename... TFlagArgs>
    inline Boolean(bool val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Boolean(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<bool>::GetFlag;
    using test::out::fmt::Argument<bool>::GetValue;
    using test::out::fmt::Argument<bool>::GetWidth;
    using test::out::fmt::Argument<bool>::GetLength;
    using test::out::fmt::Argument<bool>::GetPrecision;
    using test::out::fmt::Argument<bool>::GetFormatOutput;
};

constexpr inline Boolean::Boolean() :
    test::out::fmt::Argument<bool>(FlagSpecifierType{},
        test::out::fmt::flag::Define<bool>{})
{}

template<typename... TFlagArgs>
inline Boolean::Boolean(bool val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<bool>(FlagSpecifierType{},
        test::out::fmt::flag::Define<bool>{},
        test::out::fmt::flag::Value<bool>{val},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value,
        int>::type>
inline Boolean::Boolean(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<bool>(FlagSpecifierType{},
        test::out::fmt::flag::Define<bool>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_BOOLEAN_H_
