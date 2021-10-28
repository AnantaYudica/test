#ifndef TEST_INTEGER_RAW_H_
#define TEST_INTEGER_RAW_H_

#include "Flag.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <utility>

namespace test
{
namespace integer
{

template<std::size_t N>
class Raw
{
public:
    typedef test::integer::Flag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
private:
    test::integer::Flag m_flag;
    std::uint8_t m_value[N];
public:
    Raw(const FlagValueType& flag_val);
    template<typename TArg, typename... TArgs, typename _TArg =
        typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<std::is_integral<_TArg>::value, int>::type = 0>
    Raw(const FlagValueType& flag_val, TArg&& arg, TArgs&&... args);
    ~Raw();
public:
    template<std::size_t N_>
    Raw(const Raw<N_>& cpy);
    template<std::size_t N_>
    Raw(Raw<N_>&& mov);
public:
    template<std::size_t N_>
    Raw<N>& operator=(const Raw<N_>& cpy);
    template<std::size_t N_>
    Raw<N>& operator=(Raw<N_>&& mov);
public:
    template<typename TInstance>
    TInstance& Get(const std::size_t& n);
    template<typename TInstance>
    TInstance Get(const std::size_t& n) const;
public:
    template<typename TInstance>
    TInstance Set(const std::size_t& n, const TInstance& val);
public:
    FlagType& Flag();
    FlagType Flag() const;
public:
    std::uint8_t& operator[](const std::size_t& n);
    std::uint8_t operator[](const std::size_t& n) const;
};

template<std::size_t N>
Raw<N>::Raw(const FlagValueType& flag_val) :
    m_flag(flag_val),
    m_value{}
{
    for(std::size_t i = 0; i < N; ++i)
        m_value[i] = 0;
}

template<std::size_t N>
template<typename TArg, typename... TArgs, typename _TArg,
    typename std::enable_if<std::is_integral<_TArg>::value, int>::type>
Raw<N>::Raw(const FlagValueType& flag_val, TArg&& arg, TArgs&&... args) :
    m_flag(flag_val),
    m_value{std::forward<TArg>(arg), std::forward<TArgs>(args)...}
{
    const std::size_t rem = N - (sizeof...(TArgs) + 1);
    for(std::size_t i = 1; i <= rem && i < N; ++i)
        m_value[N - i] = 0;
}

template<std::size_t N>
Raw<N>::~Raw()
{
    for (std::size_t i = 0;i < N; ++i)
        m_value[i] = 0;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const Raw<N_>& cpy) :
    m_flag(cpy.Flag())
{
    for (std::size_t i = 0;i < N && i < N_; ++i)
        m_value[i] = cpy[i];
    if (N > N_)
        for (std::size_t i = N_;i < N; ++i)
            m_value[i] = 0; 
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(Raw<N_>&& mov) :
    m_flag(std::move(mov.Flag()))
{
    for (std::size_t i = 0;i < N && i < N_; ++i)
    {
        m_value[i] = mov[i];
        mov[i] = 0;
    }
    if (N > N_)
        for (std::size_t i = N_;i < N; ++i)
            m_value[i] = 0;
    else
        for (std::size_t i = N;i < N_; ++i)
            mov[i] = 0;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(const Raw<N_>& cpy)
{
    m_flag = cpy.Flag();
    for (std::size_t i = 0;i < N && i < N_; ++i)
        m_value[i] = cpy[i];
    if (N > N_)
        for (std::size_t i = N_;i < N; ++i)
            m_value[i] = 0; 
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(Raw<N_>&& mov)
{
    m_flag = std::move(mov.Flag());
    for (std::size_t i = 0;i < N && i < N_; ++i)
    {
        m_value[i] = mov[i];
        mov[i] = 0;
    }
    if (N > N_)
        for (std::size_t i = N_;i < N; ++i)
            m_value[i] = 0;
    else
        for (std::size_t i = N;i < N_; ++i)
            mov[i] = 0;
    return *this;
}

template<std::size_t N>
template<typename TInstance>
TInstance& Raw<N>::Get(const std::size_t& n)
{
    static TInstance instance;
    const std::size_t off = n * sizeof(TInstance);
    const std::size_t rem = N > off ? N - off : 0;
    if (sizeof(TInstance) <= rem)
    {
        std::uint8_t * ptr = m_value;
        return reinterpret_cast<TInstance&>(*(ptr + off));
    }
    return instance;
}

template<std::size_t N>
template<typename TInstance>
TInstance Raw<N>::Get(const std::size_t& n) const
{
    const std::size_t off = n * sizeof(TInstance);
    const std::size_t rem = N > off ? N - off : 0;
    if (sizeof(TInstance) <= rem)
    {
        const std::uint8_t * ptr = m_value;
        return reinterpret_cast<const TInstance&>(*(ptr + off));
    }
    return {};
}

template<std::size_t N>
template<typename TInstance>
TInstance Raw<N>::Set(const std::size_t& n, const TInstance& val)
{
    TInstance& ref = this->Get<TInstance>(n);
    TInstance ret = ref;
    ref = val;
    return ret;
}

template<std::size_t N>
typename Raw<N>::FlagType& Raw<N>::Flag()
{
    return m_flag;
}

template<std::size_t N>
typename Raw<N>::FlagType Raw<N>::Flag() const
{
    return m_flag;
}

template<std::size_t N>
std::uint8_t& Raw<N>::operator[](const std::size_t& n)
{
    return this->m_value[n];
}

template<std::size_t N>
std::uint8_t Raw<N>::operator[](const std::size_t& n) const
{
    return this->m_value[n];
}

} //!integer

} //!test

#endif //!TEST_INTEGER_RAW_H_
