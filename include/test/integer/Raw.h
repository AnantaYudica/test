#ifndef TEST_INTEGER_RAW_H_
#define TEST_INTEGER_RAW_H_

#include "Flag.h"
#include "../Byte.h"

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <utility>

namespace test
{
namespace integer
{

template<std::size_t N>
class Raw : public test::Byte<N>
{
public:
    typedef test::integer::Flag FlagType;
    typedef typename FlagType::ValueType FlagValueType;
private:
    test::integer::Flag m_flag;
public:
    Raw(const FlagValueType& flag_val);
    Raw(const FlagType& flag);
    template<std::size_t N_>
    Raw(const FlagValueType& flag_val, const test::Byte<N_>& byte_val);
    template<std::size_t N_>
    Raw(const FlagType& flag_val, const test::Byte<N_>& byte_val);
    template<std::size_t N_>
    Raw(const FlagValueType& flag_val, test::Byte<N_>&& byte_val);
    template<std::size_t N_>
    Raw(const FlagType& flag_val, test::Byte<N_>&& byte_val);
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
    template<std::size_t N_>
    Raw<N>& operator=(const test::Byte<N_>& byte_val);
    template<std::size_t N_>
    Raw<N>& operator=(test::Byte<N_>&& byte_val);
public:
    FlagType& Flag();
    FlagType Flag() const;
};

template<std::size_t N>
Raw<N>::Raw(const FlagValueType& flag_val) :
    test::Byte<N>(),
    m_flag(flag_val)
{}

template<std::size_t N>
Raw<N>::Raw(const FlagType& flag) :
    test::Byte<N>(),
    m_flag(flag)
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagValueType& flag_val, const test::Byte<N_>& byte_val) :
    test::Byte<N>(byte_val),
    m_flag(flag_val)
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagType& flag, const test::Byte<N_>& byte_val) :
    test::Byte<N>(byte_val),
    m_flag(flag)
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagValueType& flag_val, test::Byte<N_>&& byte_val) :
    test::Byte<N>(std::forward<test::Byte<N_>>(byte_val)),
    m_flag(flag_val)
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const FlagType& flag, test::Byte<N_>&& byte_val) :
    test::Byte<N>(std::forward<test::Byte<N_>>(byte_val)),
    m_flag(flag)
{}

template<std::size_t N>
Raw<N>::~Raw()
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(const Raw<N_>& cpy) :
    test::Byte<N>(cpy),
    m_flag(cpy.Flag())
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>::Raw(Raw<N_>&& mov) :
    test::Byte<N>(std::move(mov)),
    m_flag(std::move(mov.Flag()))
{}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(const Raw<N_>& cpy)
{
    test::Byte<N>::operator=(cpy);
    m_flag = cpy.Flag();
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(Raw<N_>&& mov)
{
    test::Byte<N>::operator=(std::move(mov));
    m_flag = std::move(mov.Flag());
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(const test::Byte<N_>& byte_val)
{
    test::Byte<N>::operator=(byte_val);
    return *this;
}

template<std::size_t N>
template<std::size_t N_>
Raw<N>& Raw<N>::operator=(test::Byte<N_>&& byte_val)
{
    test::Byte<N>::operator=(std::move(byte_val));
    return *this;
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

} //!integer

} //!test

#endif //!TEST_INTEGER_RAW_H_
