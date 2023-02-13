#ifndef TEST_OUT_FMT_ARG_POINTER_H_
#define TEST_OUT_FMT_ARG_POINTER_H_

#include "../../../System.h"
#include "../../../trait/out/fmt/IsFlag.h"
#include "../Argument.h"
#include "../Flag.h"

#include <type_traits>
#include <utility>

namespace test::out::fmt::arg
{

template<typename T>
class Pointer;

}

#ifndef TEST_OUT_FMT_ARG_POINTER_DLEVEL

#define TEST_OUT_FMT_ARG_POINTER_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_POINTER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_POINTER_DLEVEL, 
    "test::out::fmt::arg::Pointer", 
    test::out::fmt::arg::Pointer<T>);

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
class Pointer
{};

template<typename T>
class Pointer<T*> :
    public test::out::fmt::Argument<T*>
{
public:
    typedef typename test::out::fmt::Definition::FlagType FlagType;
public:
    constexpr inline Pointer();
    template<typename... TFlagArgs>
    constexpr inline Pointer(const T* val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    constexpr inline Pointer(T* val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    constexpr inline Pointer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<T*>::GetFlag;
    using test::out::fmt::Argument<T*>::GetValue;
    using test::out::fmt::Argument<T*>::GetWidth;
    using test::out::fmt::Argument<T*>::GetLength;
    using test::out::fmt::Argument<T*>::GetPrecision;
    using test::out::fmt::Argument<T*>::GetFormatOutput;
};

template<typename T>
constexpr inline Pointer<T*>::Pointer() :
    test::out::fmt::Argument<T*>(FlagType::specifier_ptr,
        test::out::fmt::flag::Define<T>{})
{}

template<typename T>
template<typename... TFlagArgs>
constexpr inline Pointer<T*>::Pointer(const T* val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<T*>(FlagType::specifier_ptr,
        test::out::fmt::flag::Value<T*>(const_cast<T*>(val)),
        test::out::fmt::flag::Define<T>{},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename T>
template<typename... TFlagArgs>
constexpr inline Pointer<T*>::Pointer(T* val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<T*>(FlagType::specifier_ptr,
        test::out::fmt::flag::Value<T*>(val),
        test::out::fmt::flag::Define<T>{},
        std::forward<TFlagArgs>(flags)...)
{}

template<typename T>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::
        IsFlag<TFlagArg_>::Value, int>::type>
constexpr inline Pointer<T*>::Pointer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<T*>(FlagType::specifier_ptr,
            test::out::fmt::flag::Define<T>{},
            std::forward<TFlagArg>(flag),
            std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_POINTER_H_
