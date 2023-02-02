#ifndef TEST_OUT_FMT_ARG_BOOLEAN_H_
#define TEST_OUT_FMT_ARG_BOOLEAN_H_

#include "../../../System.h"
#include "../Argument.h"
#include "../Flag.h"

#include <type_traits>
#include <utility>

namespace test::out::fmt::arg
{

class Boolean;

}

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
public:
    constexpr inline Boolean();
    template<typename... TFlagArgs>
    constexpr inline Boolean(bool val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<!std::is_same<TFlagArg_, bool>::value, 
            int>::type = 0>
    constexpr inline Boolean(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<bool>::GetFlag;
    using test::out::fmt::Argument<bool>::GetValue;
    using test::out::fmt::Argument<bool>::GetWidth;
    using test::out::fmt::Argument<bool>::GetLength;
    using test::out::fmt::Argument<bool>::GetPrecision;
};

constexpr inline Boolean::Boolean() :
    test::out::fmt::Argument<bool>(FlagType::specifier_bool,
        test::out::fmt::flag::Define<bool>{})
{}

template<typename... TFlagArgs>
constexpr inline Boolean::Boolean(bool val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<bool>(FlagType::specifier_bool,
        test::out::fmt::flag::Define<bool>{},
        test::out::fmt::flag::Value<bool>{val},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<!std::is_same<TFlagArg_, bool>::value, 
        int>::type>
constexpr inline Boolean::Boolean(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<bool>(FlagType::specifier_bool,
        test::out::fmt::flag::Define<bool>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_BOOLEAN_H_
