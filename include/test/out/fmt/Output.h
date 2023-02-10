#ifndef TEST_OUT_FMT_OUTPUT_H_
#define TEST_OUT_FMT_OUTPUT_H_

#include "../Interface.h"
#include "Definition.h"
#include "flag/Output.h"

#include <cstdint>
#include <cstdlib>
#include <cwchar>
#include <type_traits>

namespace test
{
namespace out
{
namespace fmt
{

template<typename... TCharArgs>
class Output
{
public:
    typedef typename test::out::fmt::Definition DefinitionType;
    typedef typename DefinitionType::FlagType FlagType;
public:
    template<typename TChar>
    using FormatOutputFuncType = 
        typename DefinitionType::FormatOutputFuncType<TChar>;
public:
    template<typename... TCharArgs_>
    using FlagOutputType = test::out::fmt::flag::Output<TCharArgs_...>;
private:
    std::size_t m_size;
public:
    constexpr Output();
    template<typename... TCharArgs_>
    constexpr Output(FlagOutputType<TCharArgs_...>&& flag);
protected:
    constexpr Output(std::size_t n);
    template<typename... TCharArgs_>
    constexpr Output(std::size_t n, FlagOutputType<TCharArgs_...>&& flag);
public:
    constexpr Output(const Output<TCharArgs...>& cpy);
    constexpr Output(Output<TCharArgs...>&& mov);
public:
    Output<TCharArgs...>& operator=(const Output<TCharArgs...>& cpy) = delete;
    Output<TCharArgs...>& operator=(Output<TCharArgs...>&& mov) = delete;
public:
    constexpr std::size_t Size() const;
public:
    template<typename TChar>
    constexpr FormatOutputFuncType<TChar> Get() const;
};

template<typename TChar, typename... TCharArgs>
class Output<TChar, TCharArgs...> : public Output<TCharArgs...>
{
public:
    typedef typename Output<TCharArgs...>::DefinitionType DefinitionType;
    typedef typename Output<TCharArgs...>::FlagType FlagType;
public:
    using FormatOutputFuncType = 
        typename DefinitionType::FormatOutputFuncType<TChar>;
public:
    template<typename... TCharArgs_>
    using FlagOutputType = typename Output<TCharArgs...>::
        template FlagOutputType<TCharArgs_...>;
private:
    FormatOutputFuncType m_value;
public:
    constexpr Output();
    template<typename... TCharArgs_>
    constexpr Output(FlagOutputType<TCharArgs_...>&& flag);
protected:
    constexpr Output(std::size_t n);
    template<typename... TCharArgs_>
    constexpr Output(std::size_t n, FlagOutputType<TCharArgs_...>&& flag);
public:
    constexpr Output(const Output<TChar, TCharArgs...>& cpy);
    constexpr Output(Output<TChar, TCharArgs...>&& mov);
public:
    Output<TChar, TCharArgs...>& 
        operator=(const Output<TChar, TCharArgs...>& cpy) = delete;
    Output<TChar, TCharArgs...>& 
        operator=(Output<TChar, TCharArgs...>&& mov) = delete;
public:
    using Output<TCharArgs...>::Size;
public:
    template<typename TChar_, typename std::enable_if<std::is_same<TChar, 
        TChar_>::value, int>::type = 0>
    constexpr typename Output<TChar_>::FormatOutputFuncType Get() const;
    template<typename TChar_, typename std::enable_if<!std::is_same<TChar, 
        TChar_>::value, int>::type = 1>
    constexpr typename Output<TChar_>::FormatOutputFuncType Get() const;
};

template<typename... TCharArgs>
constexpr Output<TCharArgs...>::Output() :
    m_size(0)
{}

template<typename... TCharArgs>
template<typename... TCharArgs_>
constexpr Output<TCharArgs...>::Output(FlagOutputType<TCharArgs_...>&& flag) :
    m_size(0)
{}

template<typename... TCharArgs>
constexpr Output<TCharArgs...>::Output(std::size_t n) :
    m_size(n)
{}

template<typename... TCharArgs>
template<typename... TCharArgs_>
constexpr Output<TCharArgs...>::Output(std::size_t n, 
    FlagOutputType<TCharArgs_...>&& flag) :
        m_size(n)
{}

template<typename... TCharArgs>
constexpr Output<TCharArgs...>::Output(const Output<TCharArgs...>& cpy) :
    m_size(cpy.m_size)
{}

template<typename... TCharArgs>
constexpr Output<TCharArgs...>::Output(Output<TCharArgs...>&& mov) :
    m_size(mov.m_size)
{}

template<typename... TCharArgs>
constexpr std::size_t Output<TCharArgs...>::Size() const
{
    return m_size;
}

template<typename... TCharArgs>
template<typename TChar>
constexpr typename Output<TCharArgs...>::FormatOutputFuncType<TChar> 
Output<TCharArgs...>::Get() const
{
    return nullptr;
}

template<typename TChar, typename... TCharArgs>
constexpr Output<TChar, TCharArgs...>::Output() :
    Output<TCharArgs...>(sizeof...(TCharArgs) + 1),
    m_value(nullptr)
{}

template<typename TChar, typename... TCharArgs>
template<typename... TCharArgs_>
constexpr Output<TChar, TCharArgs...>::
    Output(FlagOutputType<TCharArgs_...>&& flag) :
        Output<TCharArgs...>(sizeof...(TCharArgs) + 1,
            std::forward<FlagOutputType<TCharArgs_...>>(flag)),
        m_value(flag.template GetFormatOutput<TChar>())
{}

template<typename TChar, typename... TCharArgs>
constexpr Output<TChar, TCharArgs...>::Output(std::size_t n) :
    Output<TCharArgs...>(n),
    m_value(nullptr)
{}

template<typename TChar, typename... TCharArgs>
template<typename... TCharArgs_>
constexpr Output<TChar, TCharArgs...>::Output(std::size_t n, 
    FlagOutputType<TCharArgs_...>&& flag) :
        Output<TCharArgs...>(n,
            std::forward<FlagOutputType<TCharArgs_...>>(flag)),
        m_value(flag.template GetFormatOutput<TChar>())
{}

template<typename TChar, typename... TCharArgs>
constexpr Output<TChar, TCharArgs...>::Output(const Output<TChar, 
    TCharArgs...>& cpy) :
        Output<TCharArgs...>(cpy),
        m_value(cpy.m_value)
{}

template<typename TChar, typename... TCharArgs>
constexpr Output<TChar, TCharArgs...>:: Output(Output<TChar, 
    TCharArgs...>&& mov) :
        Output<TCharArgs...>(std::forward<Output<TChar, TCharArgs...>>(mov)),
        m_value(mov.m_value)

{}

template<typename TChar, typename... TCharArgs>
template<typename TChar_, typename std::enable_if<std::is_same<TChar, 
    TChar_>::value, int>::type>
constexpr typename Output<TChar_>::FormatOutputFuncType 
Output<TChar, TCharArgs...>::Get() const
{
    return m_value;
}

template<typename TChar, typename... TCharArgs>
template<typename TChar_, typename std::enable_if<!std::is_same<TChar, 
    TChar_>::value, int>::type>
constexpr typename Output<TChar_>::FormatOutputFuncType 
Output<TChar, TCharArgs...>::Get() const
{
    return Output<TCharArgs...>::template Get<TChar_>();
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_OUTPUT_H_
