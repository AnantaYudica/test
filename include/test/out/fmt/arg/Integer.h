#ifndef TEST_OUT_FMT_ARG_INTEGER_H_
#define TEST_OUT_FMT_ARG_INTEGER_H_

#include "../../../System.h"
#include "../../../trait/out/fmt/IsFlag.h"
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
class Integer;

} //!arg

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_ARG_INTEGER_DLEVEL

#define TEST_OUT_FMT_ARG_INTEGER_DLEVEL 2

#endif //!TEST_OUT_FMT_ARG_INTEGER_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>

template<typename T>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARG_INTEGER_DLEVEL, 
    "test::out::fmt::arg::Integer", 
    test::out::fmt::arg::Integer<T>);

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
class Integer
{};

template<>
class Integer<signed char> :
    public test::out::fmt::Argument<signed char>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_signed : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(signed char val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<signed char>::GetFlag;
    using test::out::fmt::Argument<signed char>::GetValue;
    using test::out::fmt::Argument<signed char>::GetWidth;
    using test::out::fmt::Argument<signed char>::GetLength;
    using test::out::fmt::Argument<signed char>::GetPrecision;
    using test::out::fmt::Argument<signed char>::GetFormatOutput;
};

template<>
class Integer<short> :
    public test::out::fmt::Argument<short>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_signed : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(short val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<short>::GetFlag;
    using test::out::fmt::Argument<short>::GetValue;
    using test::out::fmt::Argument<short>::GetWidth;
    using test::out::fmt::Argument<short>::GetLength;
    using test::out::fmt::Argument<short>::GetPrecision;
    using test::out::fmt::Argument<short>::GetFormatOutput;
};

template<>
class Integer<int> :
    public test::out::fmt::Argument<int>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_signed : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(int val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<int>::GetFlag;
    using test::out::fmt::Argument<int>::GetValue;
    using test::out::fmt::Argument<int>::GetWidth;
    using test::out::fmt::Argument<int>::GetLength;
    using test::out::fmt::Argument<int>::GetPrecision;
    using test::out::fmt::Argument<int>::GetFormatOutput;
};

template<>
class Integer<long> :
    public test::out::fmt::Argument<long>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_signed : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(long val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<long>::GetFlag;
    using test::out::fmt::Argument<long>::GetValue;
    using test::out::fmt::Argument<long>::GetWidth;
    using test::out::fmt::Argument<long>::GetLength;
    using test::out::fmt::Argument<long>::GetPrecision;
    using test::out::fmt::Argument<long>::GetFormatOutput;
};

template<>
class Integer<long long> :
    public test::out::fmt::Argument<long long>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_signed : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(long long val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<long long>::GetFlag;
    using test::out::fmt::Argument<long long>::GetValue;
    using test::out::fmt::Argument<long long>::GetWidth;
    using test::out::fmt::Argument<long long>::GetLength;
    using test::out::fmt::Argument<long long>::GetPrecision;
    using test::out::fmt::Argument<long long>::GetFormatOutput;
};

template<>
class Integer<unsigned char> :
    public test::out::fmt::Argument<unsigned char>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_unsigned : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(unsigned char val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<unsigned char>::GetFlag;
    using test::out::fmt::Argument<unsigned char>::GetValue;
    using test::out::fmt::Argument<unsigned char>::GetWidth;
    using test::out::fmt::Argument<unsigned char>::GetLength;
    using test::out::fmt::Argument<unsigned char>::GetPrecision;
    using test::out::fmt::Argument<unsigned char>::GetFormatOutput;
};

template<>
class Integer<unsigned short> :
    public test::out::fmt::Argument<unsigned short>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_unsigned : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(unsigned short val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<unsigned short>::GetFlag;
    using test::out::fmt::Argument<unsigned short>::GetValue;
    using test::out::fmt::Argument<unsigned short>::GetWidth;
    using test::out::fmt::Argument<unsigned short>::GetLength;
    using test::out::fmt::Argument<unsigned short>::GetPrecision;
    using test::out::fmt::Argument<unsigned short>::GetFormatOutput;
};

template<>
class Integer<unsigned int> :
    public test::out::fmt::Argument<unsigned int>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_unsigned : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(unsigned int val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<unsigned int>::GetFlag;
    using test::out::fmt::Argument<unsigned int>::GetValue;
    using test::out::fmt::Argument<unsigned int>::GetWidth;
    using test::out::fmt::Argument<unsigned int>::GetLength;
    using test::out::fmt::Argument<unsigned int>::GetPrecision;
    using test::out::fmt::Argument<unsigned int>::GetFormatOutput;
};

template<>
class Integer<unsigned long> :
    public test::out::fmt::Argument<unsigned long>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_unsigned : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(unsigned long val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<unsigned long>::GetFlag;
    using test::out::fmt::Argument<unsigned long>::GetValue;
    using test::out::fmt::Argument<unsigned long>::GetWidth;
    using test::out::fmt::Argument<unsigned long>::GetLength;
    using test::out::fmt::Argument<unsigned long>::GetPrecision;
    using test::out::fmt::Argument<unsigned long>::GetFormatOutput;
};

template<>
class Integer<unsigned long long> :
    public test::out::fmt::Argument<unsigned long long>
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
        TFlagIntegerValue VSpecifierBase_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 0 ?
                FlagType::specifier_base_dec : 0),
        TFlagIntegerValue VSpecifierIntegerDec_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_dec &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierInteger() == 0 ?
                FlagType::specifier_int_unsigned : 0),
        TFlagIntegerValue VSpecifierIntegerHex_ = 
            (FlagType{0, TFlagArgs{}...}.GetSpecifierBase() == 
                FlagType::specifier_base_hex &&
                    FlagType{0, TFlagArgs{}...}.GetSpecifierCase() == 0 ?
                FlagType::specifier_lower_case : 0),
        TFlagIntegerValue VFlagIntegerValue = FlagType::specifier_int |
            VSpecifierBase_ | VSpecifierIntegerDec_ | VSpecifierIntegerHex_>
    static constexpr FlagSpecifierType_<TFlagIntegerValue, VFlagIntegerValue> 
        Specifier_(TFlagArgs&&...);
public:
    template<typename... TFlagArgs>
    using FlagSpecifierType = 
        decltype(Specifier_<FlagIntegerValueType>(TFlagArgs{}...));
public:
    constexpr inline Integer();
    template<typename... TFlagArgs>
    inline Integer(unsigned long long val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename std::enable_if<test::trait::out::fmt::
            IsFlag<TFlagArg_>::Value, int>::type = 0>
    inline Integer(TFlagArg&& flag, TFlagArgs&&... flags);
public:
    using test::out::fmt::Argument<unsigned long long>::GetFlag;
    using test::out::fmt::Argument<unsigned long long>::GetValue;
    using test::out::fmt::Argument<unsigned long long>::GetWidth;
    using test::out::fmt::Argument<unsigned long long>::GetLength;
    using test::out::fmt::Argument<unsigned long long>::GetPrecision;
    using test::out::fmt::Argument<unsigned long long>::GetFormatOutput;
};

constexpr inline Integer<signed char>::Integer() :
    test::out::fmt::Argument<signed char>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<signed char>{})
{}

template<typename... TFlagArgs>
inline Integer<signed char>::Integer(signed char val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<signed char>(
        FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<signed char>{},
        test::out::fmt::flag::Value<signed char>(val),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<signed char>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<signed char>(FlagSpecifierType<TFlagArg,
        TFlagArgs...>{},
        test::out::fmt::flag::Define<signed char>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<short>::Integer() :
    test::out::fmt::Argument<short>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<short>{})
{}

template<typename... TFlagArgs>
inline Integer<short>::Integer(short val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<short>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<short>{},
        test::out::fmt::flag::Value<short>(val),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<short>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<short>(FlagSpecifierType<TFlagArg,
        TFlagArgs...>{},
        test::out::fmt::flag::Define<short>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<int>::Integer() :
    test::out::fmt::Argument<int>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<int>{})
{}

template<typename... TFlagArgs>
inline Integer<int>::Integer(int val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<int>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<int>{},
        test::out::fmt::flag::Value<int>(val),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<int>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<int>(FlagSpecifierType<TFlagArg, TFlagArgs...>{},
        test::out::fmt::flag::Define<int>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<long>::Integer() :
    test::out::fmt::Argument<long>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<long>{})
{}

template<typename... TFlagArgs>
inline Integer<long>::Integer(long val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<long>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<long>{},
        test::out::fmt::flag::Value<long>(val),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<long>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<long>(FlagSpecifierType<TFlagArg, 
        TFlagArgs...>{}, test::out::fmt::flag::Define<long>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<long long>::Integer() :
    test::out::fmt::Argument<long long>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<long long>{})
{}

template<typename... TFlagArgs>
inline Integer<long long>::Integer(long long val, TFlagArgs&&... flags) :
    test::out::fmt::Argument<long long>(FlagSpecifierType<TFlagArgs...>{},
        test::out::fmt::flag::Define<long long>{},
        test::out::fmt::flag::Value<long long>(val),
        std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<long long>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<long long>(FlagSpecifierType<TFlagArg, 
        TFlagArgs...>{}, test::out::fmt::flag::Define<long long>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<unsigned char>::Integer() :
    test::out::fmt::Argument<unsigned char>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<unsigned char>{})
{}

template<typename... TFlagArgs>
inline Integer<unsigned char>::Integer(unsigned char val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned char>(FlagSpecifierType<
            TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned char>{},
            test::out::fmt::flag::Value<unsigned char>(val),
            std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<unsigned char>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<unsigned char>(FlagSpecifierType<TFlagArg,
        TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned char>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<unsigned short>::Integer() :
    test::out::fmt::Argument<unsigned short>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<unsigned short>{})
{}

template<typename... TFlagArgs>
inline Integer<unsigned short>::Integer(unsigned short val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned short>(FlagSpecifierType<
            TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned short>{},
            test::out::fmt::flag::Value<unsigned short>(val),
            std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<unsigned short>::Integer(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned short>(FlagSpecifierType<TFlagArg,
            TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned short>{},
            std::forward<TFlagArg>(flag),
            std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<unsigned int>::Integer() :
    test::out::fmt::Argument<unsigned int>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<unsigned int>{})
{}

template<typename... TFlagArgs>
inline Integer<unsigned int>::Integer(unsigned int val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned int>(FlagSpecifierType<
            TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned int>{},
            test::out::fmt::flag::Value<unsigned int>(val),
            std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<unsigned int>::Integer(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned int>(FlagSpecifierType<TFlagArg,
            TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned int>{},
            std::forward<TFlagArg>(flag),
            std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<unsigned long>::Integer() :
    test::out::fmt::Argument<unsigned long>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<unsigned long>{})
{}

template<typename... TFlagArgs>
inline Integer<unsigned long>::Integer(unsigned long val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned long>(FlagSpecifierType<
            TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned long>{},
            test::out::fmt::flag::Value<unsigned long>(val),
            std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<unsigned long>::Integer(TFlagArg&& flag, TFlagArgs&&... flags) :
    test::out::fmt::Argument<unsigned long>(FlagSpecifierType<TFlagArg,
        TFlagArgs...>{}, test::out::fmt::flag::Define<unsigned long>{},
        std::forward<TFlagArg>(flag),
        std::forward<TFlagArgs>(flags)...)
{}

constexpr inline Integer<unsigned long long>::Integer() :
    test::out::fmt::Argument<unsigned long long>(FlagSpecifierType<>{},
        test::out::fmt::flag::Define<unsigned long long>{})
{}

template<typename... TFlagArgs>
inline Integer<unsigned long long>::Integer(unsigned long long val, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned long long>(FlagSpecifierType<
            TFlagArgs...>{}, test::out::fmt::flag::
                Define<unsigned long long>{},
            test::out::fmt::flag::Value<unsigned long long>(val),
            std::forward<TFlagArgs>(flags)...)
{}

template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename std::enable_if<test::trait::out::fmt::IsFlag<TFlagArg_>::Value, 
        int>::type>
inline Integer<unsigned long long>::Integer(TFlagArg&& flag, 
    TFlagArgs&&... flags) :
        test::out::fmt::Argument<unsigned long long>(FlagSpecifierType<
            TFlagArg, TFlagArgs...>{}, test::out::fmt::flag::Define<
            unsigned long long>{}, std::forward<TFlagArg>(flag),
            std::forward<TFlagArgs>(flags)...)
{}

} //arg

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_INTEGER_H_
