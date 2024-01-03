#ifndef TEST_OUT_FMT_ARGUMENT_H_
#define TEST_OUT_FMT_ARGUMENT_H_

#include "../../System.h"
#include "../../Pointer.h"
#include "../../ptr/Reference.h"
#include "../Definition.h"
#include "../print/imp/Boolean.h"
#include "../print/imp/Character.h"
#include "../print/imp/FloatingPoint.h"
#include "../print/imp/Integer.h"
#include "../print/imp/Nothing.h"
#include "../print/imp/Object.h"
#include "../print/imp/Pointer.h"
#include "../print/imp/String.h"
#include "Definition.h"
#include "Flag.h"

#include <type_traits>
#include <utility>
#include <cstring>
#include <cwchar>

namespace test
{
namespace out
{
namespace fmt
{

template<typename T, typename TFlag, typename>
class Argument;

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_ARGUMENT_DLEVEL

#define TEST_OUT_FMT_ARGUMENT_DLEVEL 2

#endif //!TEST_OUT_FMT_ARGUMENT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<T>,\
    test::sys::dbg::Type<TFlag>,\
    test::sys::dbg::Type<TEnable>

template<typename T, typename TFlag, typename TEnable>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_ARGUMENT_DLEVEL, 
    "test::out::fmt::Argument", 
    test::out::fmt::Argument<T, TFlag, TEnable>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace out
{
namespace fmt
{

template<typename T, typename TFlag = 
    typename test::out::fmt::Definition::FlagType, typename = 
        typename test::out::fmt::Definition::String<T>::DefaultType>
class Argument : public Argument<void, TFlag>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::Argument<T, TFlag, 
        typename test::out::fmt::Definition::String<T>::
            DefaultType>> DebugType;
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    template<FlagValueType V>
    using FlagSpecifierType = typename FlagType::template SpecifierType<V>;
public:
    typedef test::out::fmt::Definition DefinitionType;
private:
    static constexpr std::false_type IsDefineType_(...);
    template<typename T_>
    static constexpr std::true_type 
        IsDefineType_(test::out::fmt::flag::Define<T_>);
private:
    template<typename T_>
    using IsDefineType = decltype(IsDefineType_(std::declval<T_>()));
private:
    static constexpr std::false_type IsValueType_(...);
    template<typename T_>
    static constexpr std::true_type 
        IsValueType_(test::out::fmt::flag::Value<T_>);
private:
    template<typename T_>
    using IsValueType = decltype(IsValueType_(std::declval<T_>()));
private:
    static T Value();
    template<typename T_, typename... TFlagArgs>
    static T Value(test::out::fmt::flag::Value<T_>&& val, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsValueType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static T Value(TFlagArg&& flag, TFlagArgs&&... flags);
private:
    T m_value;
public:
    constexpr Argument();
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VIntegerValueFlag>
    constexpr Argument(FlagSpecifierType<VIntegerValueFlag> specifier);
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VIntegerValueFlag, typename TDefine>
    constexpr Argument(FlagSpecifierType<VIntegerValueFlag> specifier,
        test::out::fmt::flag::Define<TDefine>&& define_flag);
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VIntegerValueFlag, typename TFlagArg,
        typename... TFlagArgs, typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsDefineType<TFlagArg_>,
        typename std::enable_if<!TCond_::value ||
            sizeof...(TFlagArgs) != 0, int>::type = 1>
    Argument(FlagSpecifierType<VIntegerValueFlag> specifier,
        TFlagArg&& flag_arg, TFlagArgs&&... flag_args);
public:
    Argument(const Argument<T>&) = delete;
    Argument(Argument<T>&&) = delete;
public:
    Argument<T>& operator=(const Argument<T>&) = delete;
    Argument<T>& operator=(Argument<T>&&) = delete;
public:
    using Argument<void, TFlag>::GetFlag;
public:
    const T& GetValue() const;
public:
    using Argument<void, TFlag>::GetWidth;
    using Argument<void, TFlag>::GetLength;
    using Argument<void, TFlag>::GetPrecision;
    using Argument<void, TFlag>::GetFormatOutput;
};

template<typename TFlag>
class Argument<void, TFlag, void>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::Argument<void, TFlag, 
        void>> DebugType;
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    template<FlagValueType V>
    using FlagSpecifierType = typename FlagType::template SpecifierType<V>;
    template<typename T>
    using FlagDefineType = test::out::fmt::flag::Define<T>;
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    typedef typename DefinitionType::FormatOutputType FormatOutputType;
public:
    template<typename TChar>
    using FormatOutputFuncType = 
        typename DefinitionType::template FormatOutputFuncType<TChar>;
private:
    static constexpr std::false_type IsWidthType_(...);
    static constexpr std::true_type 
        IsWidthType_(test::out::fmt::flag::Width);
private:
    static constexpr std::false_type IsLengthType_(...);
    static constexpr std::true_type 
        IsLengthType_(test::out::fmt::flag::Length);
    static constexpr std::true_type 
        IsLengthType_(test::out::fmt::flag::Precision);
private:
    static constexpr std::false_type IsOutputType_(...);
    template<typename... TCharArgs>
    static constexpr std::true_type 
        IsOutputType_(test::out::fmt::flag::Output<TCharArgs...>);
private:
    template<typename T_>
    using IsWidthType = decltype(IsWidthType_(std::declval<T_>()));
private:
    template<typename T_>
    using IsLengthType = decltype(IsLengthType_(std::declval<T_>()));
private:
    template<typename T_>
    using IsOutputType = decltype(IsOutputType_(std::declval<T_>()));
private:
    template<typename TImpPrint, typename TChar>
    static constexpr std::false_type HasOutputFormatFuncType_(...);
    template<typename TImpPrint, typename TChar>
    static constexpr auto HasOutputFormatFuncType_(int) ->
        decltype((FormatOutputFuncType<TChar>)&TImpPrint::Output, std::true_type{});
private:
    template<typename TImpPrint, typename TChar>
    using HasOutputFormatFuncType = 
        decltype(HasOutputFormatFuncType_<TImpPrint, TChar>(0));
private:
    static constexpr int Width();
    template<typename... TFlagArgs>
    static constexpr int Width(test::out::fmt::flag::Width&& width, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsWidthType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr int Width(TFlagArg&& flag, TFlagArgs&&... flags);
private:
    static constexpr int Length();
    template<typename... TFlagArgs>
    static constexpr int Length(test::out::fmt::flag::Length&& length, 
        TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    static constexpr int Length(test::out::fmt::flag::Precision&& precision, 
        TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsLengthType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr int Length(TFlagArg&& flag, TFlagArgs&&... flags);
private:
    template<typename TImpPrint, 
        typename TCond1_ = HasOutputFormatFuncType<TImpPrint, char>,
        typename TCond2_ = HasOutputFormatFuncType<TImpPrint, wchar_t>,
        typename std::enable_if<TCond1_::value && TCond2_::value, 
            int>::type = 1>
    static constexpr FormatOutputType DefaultOutput_();
    template<typename TImpPrint,
        typename TCond1_ = HasOutputFormatFuncType<TImpPrint, char>,
        typename TCond2_ = HasOutputFormatFuncType<TImpPrint, wchar_t>,
        typename std::enable_if<!TCond1_::value || !TCond2_::value, 
            int>::type = 0>
    static constexpr FormatOutputType DefaultOutput_();
private:
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_bool == VFlagSpecifier_, 
            int>::type = 1>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_ch == VFlagSpecifier_, 
            int>::type = 2>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_fp == VFlagSpecifier_, 
            int>::type = 3>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_int == VFlagSpecifier_, 
            int>::type = 4>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_blank == VFlagSpecifier_, 
            int>::type = 5>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_object == VFlagSpecifier_, 
            int>::type = 6>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_ptr == VFlagSpecifier_, 
            int>::type = 7>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_str == VFlagSpecifier_, 
            int>::type = 8>
    static constexpr FormatOutputType DefaultOutput();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
        typename T, TIntegerValueFlag VFlagSpecifier_ = 
            (VIntegerValueFlag & FlagType::specifier_type_mask), 
        typename TFlag_ = FlagType,
        typename std::enable_if<TFlag_::specifier_undefined == VFlagSpecifier_,
            int>::type = 0>
    static constexpr FormatOutputType DefaultOutput();
private:
    template<typename TIntegerValueFlag, 
        TIntegerValueFlag VIntegerValueFlag, typename T>
    static constexpr FormatOutputType Output();
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag, 
        typename T, typename... TCharArgs, typename... TFlagArgs>
    static constexpr FormatOutputType Output(test::out::fmt::flag::
        Output<TCharArgs...>&& flag_out, TFlagArgs&&... flag_args);
    template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag, 
        typename T, typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond_ = IsOutputType<TFlagArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr FormatOutputType Output(TFlagArg&& flag_arg, 
        TFlagArgs&&... flag_args);
private:
    FlagType m_flag;
    int m_width;
    int m_length;
    FormatOutputType m_fmtout;
public:
    constexpr Argument();
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VFlagSpecifier, typename T, typename... TFlagArgs>
    constexpr Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
        FlagDefineType<T> define, TFlagArgs&&... flags);
public:
    Argument(const Argument<void, TFlag>&) = delete;
    Argument(Argument<void, TFlag>&&) = delete;
public:
    Argument<void, TFlag>& operator=(const Argument<void, TFlag>&) = delete;
    Argument<void, TFlag>& operator=(Argument<void, TFlag>&&) = delete;
public:
    FlagType GetFlag() const;
public:
    constexpr int GetWidth() const;
public:
    constexpr int GetLength() const;
public:
    constexpr int GetPrecision() const;
public:
    constexpr FormatOutputType GetFormatOutput() const;
};

template<typename TCharPtr, typename TFlag>
class Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type> : 
        public Argument<void, TFlag>
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::Argument<TCharPtr, TFlag, 
        typename test::out::fmt::Definition::String<TCharPtr>::
            Type>> DebugType;
public:
    typedef TFlag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
    typedef typename FlagType::IntegerValueType FlagIntegerValueType;
    template<FlagValueType V>
    using FlagSpecifierType = typename FlagType::template SpecifierType<V>;
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    template<typename T>
    using FmtFlagValueType = test::out::fmt::flag::Value<T>;
public:
    typedef typename DefinitionType::String<TCharPtr>::CharacterType 
        CharacterType;
    typedef typename test::out::Definition::StringPointerType<CharacterType> 
        StringPointerType;
public:
    typedef test::ptr::Reference<CharacterType> PointerReferenceType;
private:
    static constexpr std::false_type IsValueType_(...);
    template<typename T_>
    static constexpr std::true_type IsValueType_(FmtFlagValueType<T_>);
private:
    template<typename T_>
    using IsValueType = decltype(IsValueType_(std::declval<T_>()));
private:
    static constexpr std::false_type IsStringValue_(...);
    static constexpr std::true_type 
        IsStringValue_(FmtFlagValueType<char*>&&);
    static constexpr std::true_type 
        IsStringValue_(FmtFlagValueType<wchar_t*>&&);
    static constexpr std::true_type 
        IsStringValue_(FmtFlagValueType<const char*>&&);
    static constexpr std::true_type 
        IsStringValue_(FmtFlagValueType<const wchar_t*>&&);
private:
    template<typename T_>
    using IsStringValue = decltype(IsStringValue_(std::declval<T_>()));
private:
    static constexpr std::false_type IsPointerValue_(...);
    static constexpr std::true_type 
        IsPointerValue_(FmtFlagValueType<test::ptr::Reference<char>>&&);
    static constexpr std::true_type 
        IsPointerValue_(FmtFlagValueType<test::ptr::Reference<wchar_t>>&&);
private:
    template<typename T_>
    using IsPointerValue = decltype(IsPointerValue_(std::declval<T_>()));
private:
    static constexpr bool IsContainValueType_()
    {
        return false;
    }
    template<typename TArg, typename... TArgs,
        typename TArg_ = typename std::remove_cv<
            typename std::remove_reference<TArg>::type>::type,
        typename TCond = IsValueType<TArg_>,
        typename std::enable_if<!TCond::value, int>::type = 0>
    static constexpr bool IsContainValueType_(TArg&& arg, TArgs&&... args)
    {
        return IsContainValueType_(std::forward<TArgs>(args)...);
    }
    template<typename TArg, typename... TArgs,
        typename TArg_ = typename std::remove_cv<
            typename std::remove_reference<TArg>::type>::type,
        typename TCond_ = IsValueType<TArg_>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    static constexpr bool IsContainValueType_(TArg&& arg, TArgs&&... args)
    {
        return true;
    }
private:
    template<typename... TArgs>
    using IsContainValueType = std::integral_constant<bool, 
        IsContainValueType_(typename std::remove_cv<typename 
            std::remove_reference<TArgs>::type>::type()...)>;
private:
    static const CharacterType* StringValue();
    template<typename... TFlagArgs>
    static const CharacterType* StringValue(test::out::fmt::flag::
        Value<const CharacterType*>&& val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    static const CharacterType* StringValue(test::out::fmt::flag::
        Value<CharacterType*>&& val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond1_ = IsValueType<TFlagArg_>,
        typename TCond2_ = IsStringValue<TFlagArg_>,
        typename std::enable_if<!TCond1_::value || !TCond2_::value, 
            int>::type = 0>
    static const CharacterType* StringValue(TFlagArg&& flag,
        TFlagArgs&&... flags);
private:
    static PointerReferenceType PointerValue();
    template<typename... TFlagArgs>
    static PointerReferenceType PointerValue(test::out::fmt::flag::
        Value<test::Pointer<char>>&& val, TFlagArgs&&... flags);
    template<typename... TFlagArgs>
    static PointerReferenceType PointerValue(test::out::fmt::flag::
        Value<test::Pointer<wchar_t>>&& val, TFlagArgs&&... flags);
    template<typename TFlagArg, typename... TFlagArgs,
        typename TFlagArg_ = typename std::remove_cv<
            typename std::remove_reference<TFlagArg>::type>::type,
        typename TCond1_ = IsValueType<TFlagArg_>,
        typename TCond2_ = IsPointerValue<TFlagArg_>,
        typename std::enable_if<!TCond1_::value || !TCond2_::value, 
            int>::type = 0>
    static PointerReferenceType PointerValue(TFlagArg&& flag,
        TFlagArgs&&... flags);
private:
    StringPointerType m_value;
public:
    constexpr Argument();
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VFlagSpecifier, typename... TFlagArgs, 
        typename TCond_ = IsContainValueType<TFlagArgs...>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    constexpr Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
        TFlagArgs&&... flags);
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VFlagSpecifier, typename... TFlagArgs, 
        typename TCond_ = IsContainValueType<TFlagArgs...>,
        typename TChar_ = CharacterType,
        typename std::enable_if<TCond_::value &&
            std::is_same<char, TChar_>::value, int>::type = 1>
    Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
        TFlagArgs&&... flags);
    template<typename TFlagIntegerValue = FlagIntegerValueType,
        TFlagIntegerValue VFlagSpecifier, typename... TFlagArgs, 
        typename TCond_ = IsContainValueType<TFlagArgs...>,
        typename TChar_ = CharacterType,
        typename std::enable_if<TCond_::value &&
            std::is_same<wchar_t, TChar_>::value, int>::type = 2>
    Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
        TFlagArgs&&... flags);
public:
    Argument(const Argument<TCharPtr, TFlag>&) = delete;
    Argument(Argument<TCharPtr, TFlag>&&) = delete;
public:
    Argument<TCharPtr, TFlag>& 
        operator=(const Argument<TCharPtr, TFlag>&) = delete;
    Argument<TCharPtr, TFlag>& 
        operator=(Argument<TCharPtr, TFlag>&&) = delete;
private:
    void InitializeValue();
    void InitializeValue(const char* str_val);
    void InitializeValue(const wchar_t* str_val);
    template<typename T>
    void InitializeValue(test::ptr::Reference<T> ptr_str_val);
public:
    using Argument<void, TFlag>::GetFlag;
public:
    StringPointerType GetValue() const;
public:
    using Argument<void, TFlag>::GetWidth;
    using Argument<void, TFlag>::GetLength;
    using Argument<void, TFlag>::GetPrecision;
    using Argument<void, TFlag>::GetFormatOutput;
};

template<typename T, typename TFlag, typename TEnable>
T Argument<T, TFlag, TEnable>::Value()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL,  "Value()");

    return {};
}

template<typename T, typename TFlag, typename TEnable>
template<typename T_, typename... TFlagArgs>
T Argument<T, TFlag, TEnable>::
    Value(test::out::fmt::flag::Value<T_>&& val, TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL,  
        "Value<%s>(val=%p, flags={%s})", 
            TEST_SYS_DEBUG_TARGS_NAME_STR(T_, TFlagArgs...),
            &val, TEST_SYS_DEBUG_TARGS_VALUE_STR(flags...));

    return val.IsDefault() ? Value(std::forward<TFlagArgs>(flags)...) : 
        T{std::move(val).GetValue()};
}

template<typename T, typename TFlag, typename TEnable>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
T Argument<T, TFlag, TEnable>::Value(TFlagArg&& flag, 
    TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "Value<%s>(flags={%s})", 
            TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArg, TFlagArgs...),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(flag, flags...));
    
    return Value(std::forward<TFlagArgs>(flags)...);
}

template<typename T, typename TFlag, typename TEnable>
constexpr Argument<T, TFlag, TEnable>::Argument() :
    Argument<void, TFlag>(),
    m_value()
{}

template<typename T, typename TFlag, typename TEnable>
template<typename TFlagIntegerValue, TFlagIntegerValue VIntegerValueFlag>
constexpr Argument<T, TFlag, TEnable>::
    Argument(FlagSpecifierType<VIntegerValueFlag> specifier) :
        Argument<void, TFlag>(specifier, 
            test::out::fmt::flag::Define<T>{}, 
            test::out::fmt::flag::Define<T>{}),
        m_value()
{}

template<typename T, typename TFlag, typename TEnable>
template<typename TFlagIntegerValue, TFlagIntegerValue VIntegerValueFlag,
    typename TDefine>
constexpr Argument<T, TFlag, TEnable>::
    Argument(FlagSpecifierType<VIntegerValueFlag> specifier,
        test::out::fmt::flag::Define<TDefine>&& define_flag) :
        Argument<void, TFlag>(specifier, 
            test::out::fmt::flag::Define<T>{}, 
            std::forward<test::out::fmt::flag::Define<TDefine>>(define_flag)),
        m_value()
{}


template<typename T, typename TFlag, typename TEnable>
template<typename TFlagIntegerValue, TFlagIntegerValue VIntegerValueFlag, 
    typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename TCond_, typename std::enable_if<!TCond_::value ||
        sizeof...(TFlagArgs) != 0, int>::type>
Argument<T, TFlag, TEnable>::
    Argument(FlagSpecifierType<VIntegerValueFlag> specifier, 
        TFlagArg&& flag_arg, TFlagArgs&&... flag_args) :
            Argument<void, TFlag>(specifier, 
                test::out::fmt::flag::Define<T>{},
                std::forward<TFlagArg>(flag_arg),
                std::forward<TFlagArgs>(flag_args)...),
            m_value(Value(std::forward<TFlagArg>(flag_arg),
                std::forward<TFlagArgs>(flag_args)...))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor<%s, %s, %s>(specifier=%s, flag_args={%s})",
            TEST_SYS_DEBUG_T_NAME_STR(TFlagIntegerValue),
            TEST_SYS_DEBUG_VALUE_STR(0, VIntegerValueFlag),
            TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArg, TFlagArgs...),
            TEST_SYS_DEBUG_VALUE_STR(1, specifier),
            TEST_SYS_DEBUG_TARGS_VALUE_STR(flag_arg, flag_args...));
    
}

template<typename T, typename TFlag, typename TEnable>
const T& Argument<T, TFlag, TEnable>::GetValue() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetValue() const");
    
    return m_value;
}

template<typename TFlag>
constexpr int Argument<void, TFlag, void>::Width()
{
    return 0;
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag, void>::
    Width(test::out::fmt::flag::Width&& width,TFlagArgs&&... flags)
{
    return width.IsDefault() ? Width(std::forward<TFlagArgs>(flags)...) : 
        width.GetValue();
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr int Argument<void, TFlag, void>::Width(TFlagArg&& flag, 
    TFlagArgs&&... flags)
{
    return Width(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
constexpr int Argument<void, TFlag, void>::Length()
{
    return 0;
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag, void>::
    Length(test::out::fmt::flag::Length&& length, TFlagArgs&&... flags)
{
    return length.IsDefault() ? Length(std::forward<TFlagArgs>(flags)...) : 
        length.GetValue();
}

template<typename TFlag>
template<typename... TFlagArgs>
constexpr int Argument<void, TFlag, void>::
    Length(test::out::fmt::flag::Precision&& precision, TFlagArgs&&... flags)
{
    return precision.IsDefault() ? Length(std::forward<TFlagArgs>(flags)...) : 
        precision.GetValue();
}

template<typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr int Argument<void, TFlag, void>::
    Length(TFlagArg&& flag, TFlagArgs&&... flags)
{
    return Length(std::forward<TFlagArgs>(flags)...);
}

template<typename TFlag>
template<typename TImpPrint, typename TCond1_, typename TCond2_,
    typename std::enable_if<TCond1_::value && TCond2_::value, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput_()
{
    typedef test::out::fmt::flag::Output<char, wchar_t> FlagOutputType;
    return FormatOutputType{FlagOutputType{
        (FormatOutputFuncType<char>)&TImpPrint::Output,
        (FormatOutputFuncType<wchar_t>)&TImpPrint::Output,
    }};
}

template<typename TFlag>
template<typename TImpPrint, typename TCond1_, typename TCond2_,
    typename std::enable_if<!TCond1_::value || !TCond2_::value, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput_()
{
    static_assert(HasOutputFormatFuncType<TImpPrint, char>::value,
        "(FormatOutputFuncType<char>)&TImpPrint::Output isn't implemented");
    static_assert(HasOutputFormatFuncType<TImpPrint, wchar_t>::value,
        "(FormatOutputFuncType<char>)&TImpPrint::Output isn't implemented");
    return {};
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_bool == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::Boolean BooleanType;
    typedef test::out::print::imp::Boolean<VIntegerValueFlag & 
        BooleanType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_ch == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::Character CharacterType;
    typedef test::out::print::imp::Character<VIntegerValueFlag & 
        CharacterType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_fp == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::FloatingPoint FloatingPointType;
    typedef test::out::print::imp::FloatingPoint<VIntegerValueFlag & 
        FloatingPointType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_int == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::Integer IntegerType;
    typedef test::out::print::imp::Integer<VIntegerValueFlag & 
        IntegerType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_blank == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::imp::Nothing PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_ , typename TFlag_,
    typename std::enable_if<TFlag_::specifier_object == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::Object ObjectType;
    typedef test::out::print::imp::Object<T, VIntegerValueFlag & 
        ObjectType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_ptr == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::Pointer PointerType;
    typedef test::out::print::imp::Pointer<VIntegerValueFlag & 
        PointerType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_str == VFlagSpecifier_, 
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    typedef test::out::print::String StringType;
    typedef test::out::print::imp::String<VIntegerValueFlag & 
        StringType::MaskValue> PrintType;
    return DefaultOutput_<PrintType>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T, TIntegerValueFlag VFlagSpecifier_, typename TFlag_,
    typename std::enable_if<TFlag_::specifier_undefined == VFlagSpecifier_,
        int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::DefaultOutput()
{
    return {};
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag,
    typename T>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::Output()
{
    return DefaultOutput<TIntegerValueFlag, VIntegerValueFlag, T>();
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag, 
    typename T, typename... TCharArgs, typename... TFlagArgs>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::Output(test::out::fmt::flag::
    Output<TCharArgs...>&& flag_out, TFlagArgs&&... flag_args)
{
    return {std::forward<test::out::fmt::flag::
        Output<TCharArgs...>>(flag_out)};
}

template<typename TFlag>
template<typename TIntegerValueFlag, TIntegerValueFlag VIntegerValueFlag, 
    typename T, typename TFlagArg, typename... TFlagArgs, 
    typename TFlagArg_, typename TCond_, 
    typename std::enable_if<!TCond_::value, int>::type>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag>::Output(TFlagArg&& flag_arg, 
    TFlagArgs&&... flag_args)
{
    return Output<TIntegerValueFlag, 
        VIntegerValueFlag, T>(std::forward<TFlagArgs>(flag_args)...);
}

template<typename TFlag>
constexpr Argument<void, TFlag, void>::Argument() :
    m_flag(),
    m_width(0),
    m_length(0),
    m_fmtout()
{}

template<typename TFlag>
template<typename TFlagIntegerValue, TFlagIntegerValue VFlagSpecifier, 
    typename T, typename... TFlagArgs>
constexpr Argument<void, TFlag, void>::
    Argument(FlagSpecifierType<VFlagSpecifier> specifier,
        FlagDefineType<T> define, TFlagArgs&&... flags) :
            m_flag(VFlagSpecifier, FlagDefineType<T>{},
                std::forward<TFlagArgs>(flags)...),
            m_width(Width(std::forward<TFlagArgs>(flags)...)),
            m_length(Length(std::forward<TFlagArgs>(flags)...)),
            m_fmtout(Output<FlagIntegerValueType, 
                TFlag{VFlagSpecifier, FlagDefineType<T>{}, 
                TFlagArgs{}...}.GetValue(), 
                    T>(std::forward<TFlagArgs>(flags)...))
{}

template< typename TFlag>
typename Argument<void, TFlag, void>:: FlagType
Argument<void, TFlag, void>::GetFlag() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetFlag() const");

    return m_flag;
}

template< typename TFlag>
constexpr int Argument<void, TFlag, void>::GetWidth() const
{
    return m_width;
}

template< typename TFlag>
constexpr int Argument<void, TFlag, void>::GetLength() const
{
    return m_length;
}

template< typename TFlag>
constexpr int Argument<void, TFlag, void>::GetPrecision() const
{
    return m_length;
}

template< typename TFlag>
constexpr typename Argument<void, TFlag, void>::FormatOutputType 
Argument<void, TFlag, void>::GetFormatOutput() const
{
    return m_fmtout;
}

template<typename TCharPtr, typename TFlag>
const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::StringValue()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "StringValue() const");

    return NULL;
}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs>
const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        StringValue(test::out::fmt::flag::Value<const CharacterType*>&& val, 
            TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StringValue<%s>(val=%s, flags={%s}) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArgs...),
        TEST_SYS_DEBUG_VALUE_STR(0, val),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(flags...));

    return val.IsDefault() ? StringValue(std::forward<TFlagArgs>(flags)...) : 
        std::move(val).GetValue();
}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs>
const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        StringValue(test::out::fmt::flag::Value<CharacterType*>&& val, 
            TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StringValue<%s>(val=%s, flags={%s}) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArgs...),
        TEST_SYS_DEBUG_VALUE_STR(0, val),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(flags...));

    return val.IsDefault() ? StringValue(std::forward<TFlagArgs>(flags)...) : 
        std::move(val).GetValue();
}

template<typename TCharPtr, typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename TCond1_, typename TCond2_, 
    typename std::enable_if<!TCond1_::value || !TCond2_::value,
        int>::type>
const typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::CharacterType * 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        StringValue(TFlagArg&& flag, TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StringValue<%s>(flags={%s}) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArg, TFlagArgs...),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(flag, flags...));

    return StringValue(std::forward<TFlagArgs>(flags)...);
}

template<typename TCharPtr, typename TFlag>
typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerReferenceType
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerValue()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, "PointerValue() const");

    return PointerReferenceType{test::Pointer<CharacterType>{nullptr}};
}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs>
typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerReferenceType
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerValue(test::out::fmt::flag::
    Value<test::Pointer<char>>&& val, TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "PointerValue<%s>(val=%s, flags={%s}) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArgs...),
        TEST_SYS_DEBUG_VALUE_STR(0, val),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(flags...));

    return val.IsDefault() ? PointerValue(std::forward<TFlagArgs>(flags)...) : 
        std::move(val).GetValue().ReinterpretCast<CharacterType>();
}

template<typename TCharPtr, typename TFlag>
template<typename... TFlagArgs>
typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerReferenceType
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerValue(test::out::fmt::flag::
    Value<test::Pointer<wchar_t>>&& val, TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "PointerValue<%s>(val=%s, flags={%s}) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArgs...),
        TEST_SYS_DEBUG_VALUE_STR(0, val),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(flags...));

    return val.IsDefault() ? PointerValue(std::forward<TFlagArgs>(flags)...) : 
        std::move(val).GetValue().ReinterpretCast<CharacterType>();
}

template<typename TCharPtr, typename TFlag>
template<typename TFlagArg, typename... TFlagArgs, typename TFlagArg_,
    typename TCond1_, typename TCond2_, 
    typename std::enable_if<!TCond1_::value || !TCond2_::value, 
        int>::type>
typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerReferenceType
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::PointerValue(TFlagArg&& flag,
    TFlagArgs&&... flags)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "StringValue<%s>(flags={%s}) const", 
        TEST_SYS_DEBUG_TARGS_NAME_STR(TFlagArg, TFlagArgs...),
        TEST_SYS_DEBUG_TARGS_VALUE_STR(flag, flags...));

    return PointerValue(std::forward<TFlagArgs>(flags)...);
}

template<typename TCharPtr, typename TFlag>
constexpr Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::Argument() :
        Argument<void, TFlag>(),
        m_value(test::Pointer<CharacterType>{nullptr})
{}

template<typename TCharPtr, typename TFlag>
template<typename TFlagIntegerValue, TFlagIntegerValue VFlagSpecifier, 
    typename... TFlagArgs, typename TCond_,
    typename std::enable_if<!TCond_::value, int>::type>
constexpr Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
            TFlagArgs&&... flags) :
                Argument<void, TFlag>(specifier, 
                    test::out::fmt::flag::Define<CharacterType*>{},
                    std::forward<TFlagArgs>(flags)...),
                m_value(test::Pointer<CharacterType>{nullptr})
{}

template<typename TCharPtr, typename TFlag>
template<typename TFlagIntegerValue, TFlagIntegerValue VFlagSpecifier, 
    typename... TFlagArgs, typename TCond_, typename TChar_,
    typename std::enable_if<TCond_::value &&
        std::is_same<char, TChar_>::value, int>::type>
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
            TFlagArgs&&... flags) :
                Argument<void, TFlag>(specifier, 
                    test::out::fmt::flag::Define<CharacterType*>{},
                    std::forward<TFlagArgs>(flags)...),
                m_value(test::Pointer<CharacterType>{nullptr})
{
    const char* str_value = StringValue(std::forward<TFlagArgs>(flags)...);
    if (str_value != nullptr)
    {
        InitializeValue(str_value);
    }
    else
    {
        auto ptr_value = 
            PointerValue(std::forward<TFlagArgs>(flags)...);

        InitializeValue(ptr_value);
    }
}
    
template<typename TCharPtr, typename TFlag>
template<typename TFlagIntegerValue, TFlagIntegerValue VFlagSpecifier, 
    typename... TFlagArgs, typename TCond_, typename TChar_,
    typename std::enable_if<TCond_::value &&
        std::is_same<wchar_t, TChar_>::value, int>::type>
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        Argument(FlagSpecifierType<VFlagSpecifier> specifier, 
            TFlagArgs&&... flags) :
                Argument<void, TFlag>(specifier, 
                    test::out::fmt::flag::Define<CharacterType*>{},
                    std::forward<TFlagArgs>(flags)...),
                m_value(test::Pointer<CharacterType>{nullptr})
{
    const wchar_t* str_value = StringValue(std::forward<TFlagArgs>(flags)...);
    if (str_value != nullptr)
    {
        InitializeValue(str_value);
    }
    else
    {
        auto ptr_value = 
            PointerValue(std::forward<TFlagArgs>(flags)...);

        InitializeValue(ptr_value);
    }
}

template<typename TCharPtr, typename TFlag>
void Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        InitializeValue(const char* value)
{
    if (value != NULL)
    {
        const std::size_t max_len = test::out::fmt::Definition::string_max_len;

#ifdef __STDC_LIB_EXT1__
        const std::size_t len = strnlen_s(value, max_len);
#else
        std::size_t len = strlen(value);
        if (len >= max_len)
        {
            len = max_len;
        }
#endif
        m_value = test::ptr::Reference<char>{
            test::Pointer<char>(test::ptr::arg::Array{len + 1})};

#ifdef __STDC_LIB_EXT1__
        memcpy_s(&*m_value, len, value, len);
#else
        memcpy(&*m_value, value, len);
#endif 
        m_value[len] = '\0';
    }
}

template<typename TCharPtr, typename TFlag>
void Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        InitializeValue(const wchar_t* value)
{
    if (value != NULL)
    {
        const std::size_t max_len = test::out::fmt::Definition::string_max_len;

#ifdef __STDC_LIB_EXT1__
        const std::size_t len = wcsnlen_s(value, max_len);
#else
        std::size_t len = wcslen(value);
        if (len >= max_len)
        {
            len = max_len;
        }
#endif
        m_value = test::ptr::Reference<wchar_t>{
            test::Pointer<wchar_t>(test::ptr::arg::Array{len + 1})};

#ifdef __STDC_LIB_EXT1__
        wmemcpy_s(&*m_value, len, value, len);
#else
        wmemcpy(&*m_value, value, len);
#endif 
        m_value[len] = L'\0';
    }
}

template<typename TCharPtr, typename TFlag>
template<typename T>
void Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::
        InitializeValue(test::ptr::Reference<T> value)
{
    if(value != nullptr)
    {
        m_value = value;
    }
}

template<typename TCharPtr, typename TFlag>
typename Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::StringPointerType 
Argument<TCharPtr, TFlag, typename test::out::fmt::
    Definition::String<TCharPtr>::Type>::GetValue() const
{
    return m_value;
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_ARG_BOOLEAN_H_
