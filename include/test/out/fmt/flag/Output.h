#ifndef TEST_OUT_FMT_FLAG_OUTPUT_H_
#define TEST_OUT_FMT_FLAG_OUTPUT_H_

#include "../../../System.h"

namespace test::out::fmt::flag
{

template<typename... TCharArgs>
class Output;

}

#include "../Definition.h"

#include <type_traits>

namespace test
{
namespace out
{
namespace fmt
{
namespace flag
{

template<typename... TCharArgs>
class Output 
{
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    template<typename TChar>
    using FormatOutputFuncType = typename DefinitionType::
        FormatOutputFuncType<TChar>;
protected:
    static constexpr std::false_type IsFormatOutputFuncType_(...);
    template<typename TChar>
    static constexpr std::true_type 
        IsFormatOutputFuncType_(FormatOutputFuncType<TChar>&&);
protected:
    template<typename T>
    using IsFormatOutputFuncType = 
        decltype(IsFormatOutputFuncType_(FormatOutputFuncType<T>(nullptr)));
private:
    std::size_t m_size;
public:
    constexpr Output();
    template<typename TValueArg, typename... TValueArgs, 
        typename TValueArg_ = typename std::remove_cv<
            typename std::remove_reference<TValueArg>::type>::type,
        typename TCond_ = IsFormatOutputFuncType<TValueArg_>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    constexpr Output(TValueArg&& arg, TValueArgs&&... args);
protected:
    template<typename TValueArg, typename... TValueArgs>
    constexpr Output(std::size_t n, TValueArg&& arg, 
        TValueArgs&&... args);
public:
    constexpr std::size_t Size() const;
public:
    template<typename TChar>
    constexpr FormatOutputFuncType<TChar> GetFormatOutput() const;
};

template<typename TChar, typename... TCharArgs>
class Output<TChar, TCharArgs...> : public Output<TCharArgs...>
{
    static_assert(test::out::fmt::Definition::OutputValue((TChar)0) != 0, 
        "Undefined character type");
private:
    typedef Output<TCharArgs...> BaseType;
public:
    typedef test::out::fmt::Definition DefinitionType;
public:
    template<typename TChar_>
    using FormatOutputFuncType = typename DefinitionType::
        FormatOutputFuncType<TChar_>;
protected:
    template<typename T>
    using IsFormatOutputFuncType = Output<>::
        template IsFormatOutputFuncType<T>;
private:
    static constexpr FormatOutputFuncType<TChar> Value();
    template<typename TValueArg, typename... TValueArgs,
        typename TValueArg_ = typename std::remove_cv<
            typename std::remove_reference<TValueArg>::type>::type,
        typename TCond_ = std::is_same<FormatOutputFuncType<TChar>,
            TValueArg_>,
        typename std::enable_if<!TCond_::value, int>::type = 0>
    static constexpr FormatOutputFuncType<TChar> Value(TValueArg&& arg, 
        TValueArgs&&... args);
    template<typename... TValueArgs>
    static constexpr FormatOutputFuncType<TChar> 
        Value(FormatOutputFuncType<TChar>&& arg, TValueArgs&&... args);
private:
    FormatOutputFuncType<TChar> m_value;
public:
    constexpr Output();
    template<typename TValueArg, typename... TValueArgs, 
        typename TValueArg_ = typename std::remove_cv<
            typename std::remove_reference<TValueArg>::type>::type,
        typename TCond_ = IsFormatOutputFuncType<TValueArg_>,
        typename std::enable_if<TCond_::value, int>::type = 0>
    constexpr Output(TValueArg&& arg, TValueArgs&&... args);
protected:
    template<typename TValueArg, typename... TValueArgs>
    constexpr Output(std::size_t n, TValueArg&& arg, 
        TValueArgs&&... args);
public:
    using Output<TCharArgs...>::Size;
public:
    template<typename TChar_, typename std::enable_if<std::is_same<TChar, 
        TChar_>::value, int>::type = 0>
    constexpr FormatOutputFuncType<TChar_> GetFormatOutput() const;
    template<typename TChar_, typename std::enable_if<!std::is_same<TChar, 
        TChar_>::value, int>::type = 1>
    constexpr FormatOutputFuncType<TChar_> GetFormatOutput() const;
};

template<typename... TCharArgs>
constexpr Output<TCharArgs...>::Output() :
    m_size(0)
{}

template<typename... TCharArgs>
template<typename TValueArg, typename... TValueArgs, 
    typename TValueArg_, typename TCond_,
    typename std::enable_if<TCond_::value, int>::type>
constexpr Output<TCharArgs...>::Output(TValueArg&& arg, TValueArgs&&... args) :
    m_size(0)
{}

template<typename... TCharArgs>
template<typename TValueArg, typename... TValueArgs>
constexpr Output<TCharArgs...>::Output(std::size_t n, TValueArg&& arg, 
    TValueArgs&&... args) :
        m_size(n)
{}

template<typename... TCharArgs>
constexpr std::size_t Output<TCharArgs...>::Size() const
{
    return m_size;
}

template<typename... TCharArgs>
template<typename TChar>
constexpr typename Output<TCharArgs...>::FormatOutputFuncType<TChar> 
Output<TCharArgs...>::GetFormatOutput() const
{
    return nullptr;
}

template<typename TChar, typename... TCharArgs>
constexpr typename Output<TChar, TCharArgs...>::FormatOutputFuncType<TChar> 
Output<TChar, TCharArgs...>::Value()
{
    return nullptr;
}

template<typename TChar, typename... TCharArgs>
template<typename TValueArg, typename... TValueArgs, typename TValueArg_,
    typename TCond_, typename std::enable_if<!TCond_::value, int>::type>
constexpr typename Output<TChar, TCharArgs...>::FormatOutputFuncType<TChar> 
Output<TChar, TCharArgs...>::Value(TValueArg&& arg, TValueArgs&&... args)
{
    return Value(std::forward<TValueArgs>(args)...);
}

template<typename TChar, typename... TCharArgs>
template<typename... TValueArgs>
constexpr typename Output<TChar, TCharArgs...>::FormatOutputFuncType<TChar> 
Output<TChar, TCharArgs...>::Value(FormatOutputFuncType<TChar>&& arg, 
    TValueArgs&&... args)
{
    return arg;
}

template<typename TChar, typename... TCharArgs>
constexpr Output<TChar, TCharArgs...>::Output() :
    BaseType(),
    m_value(nullptr)
{}

template<typename TChar, typename... TCharArgs>
template<typename TValueArg, typename... TValueArgs, typename TValueArg_,
    typename TCond_, typename std::enable_if<TCond_::value, int>::type>
constexpr Output<TChar, TCharArgs...>::Output(TValueArg&& arg, 
    TValueArgs&&... args) :
        BaseType(sizeof...(args) + 1, std::forward<TValueArg>(arg),
            std::forward<TValueArgs>(args)...),
        m_value(Value(std::forward<TValueArg>(arg),
            std::forward<TValueArgs>(args)...))
{}

template<typename TChar, typename... TCharArgs>
template<typename TValueArg, typename... TValueArgs>
constexpr Output<TChar, TCharArgs...>::Output(std::size_t n, TValueArg&& arg, 
    TValueArgs&&... args) :
        BaseType(n, std::forward<TValueArg>(arg),
            std::forward<TValueArgs>(args)...),
        m_value(Value(std::forward<TValueArg>(arg),
            std::forward<TValueArgs>(args)...))
{}

template<typename TChar, typename... TCharArgs>
template<typename TChar_, typename std::enable_if<std::is_same<TChar, 
    TChar_>::value, int>::type>
constexpr typename Output<TChar, TCharArgs...>::FormatOutputFuncType<TChar_> 
Output<TChar, TCharArgs...>::GetFormatOutput() const
{
    return m_value;
}

template<typename TChar, typename... TCharArgs>
template<typename TChar_, typename std::enable_if<!std::is_same<TChar, 
    TChar_>::value, int>::type>
constexpr typename Output<TChar, TCharArgs...>::FormatOutputFuncType<TChar_> 
Output<TChar, TCharArgs...>::GetFormatOutput() const
{
    return BaseType::template GetFormatOutput<TChar_>();
}

} //!flag

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_FLAG_OUTPUT_DLEVEL

#define TEST_OUT_FMT_FLAG_OUTPUT_DLEVEL 2

#endif //!TEST_OUT_FMT_FLAG_OUTPUT_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TCharArgs>...

template<typename... TCharArgs>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_FLAG_OUTPUT_DLEVEL, 
    "test::out::fmt::flag::Output", 
    test::out::fmt::flag::Output<TCharArgs...>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

#endif //!TEST_OUT_FMT_FLAG_OUTPUT_H_
