#ifndef TEST_FP_NUMBER_H_
#define TEST_FP_NUMBER_H_

#include <cstddef>
#include <utility>

namespace test
{
namespace fp
{

template<typename TExponent, typename TMantissa>
class Number
{
private:
    TExponent m_exp;
    TExponent m_int_ndigit;
    TExponent m_rem_ndigit;
    TMantissa m_int;
    TMantissa m_rem;
public:
    Number();
public:
    ~Number();
public:
    Number(const Number<TExponent, TMantissa>& cpy);
    Number(Number<TExponent, TMantissa>&& mov);
public:
    Number<TExponent, TMantissa>& 
        operator=(const Number<TExponent, TMantissa>& cpy);
    Number<TExponent, TMantissa>& 
        operator=(Number<TExponent, TMantissa>&& mov);
public:
    void SetInteger(const TMantissa& val, const TExponent& ndigit);
    void SetRemainder(const TMantissa& val, const TExponent& ndigit);
    void SetExponent(const TExponent& val);
public:
    TMantissa GetInteger() const;
    TMantissa GetRemainder() const;
    TExponent GetExponent() const;
    TExponent GetIntegerDigitSize() const;
    TExponent GetRemainderDigitSize() const;
};

template<typename TExponent, typename TMantissa>
Number<TExponent, TMantissa>::Number() :
    m_exp(0),
    m_int_ndigit(0),
    m_rem_ndigit(0),
    m_int(0),
    m_rem(0)
{}

template<typename TExponent, typename TMantissa>
Number<TExponent, TMantissa>::~Number()
{}

template<typename TExponent, typename TMantissa>
Number<TExponent, TMantissa>::
    Number(const Number<TExponent, TMantissa>& cpy) :
        m_exp(cpy.m_exp),
        m_int_ndigit(cpy.m_int_ndigit),
        m_rem_ndigit(cpy.m_rem_ndigit),
        m_int(cpy.m_int),
        m_rem(cpy.m_rem)
{}

template<typename TExponent, typename TMantissa>
Number<TExponent, TMantissa>::
    Number(Number<TExponent, TMantissa>&& mov) :
        m_exp(mov.m_exp),
        m_int_ndigit(mov.m_int_ndigit),
        m_rem_ndigit(mov.m_rem_ndigit),
        m_int(mov.m_int),
        m_rem(mov.m_rem)
{}

template<typename TExponent, typename TMantissa>
Number<TExponent, TMantissa>& Number<TExponent, TMantissa>::
    operator=(const Number<TExponent, TMantissa>& cpy)
{
    m_exp = cpy.m_exp;
    m_int_ndigit = cpy.m_int_ndigit;
    m_rem_ndigit = cpy.m_rem_ndigit;
    m_int = cpy.m_int;
    m_rem = cpy.m_rem;
    return *this;
}

template<typename TExponent, typename TMantissa>
Number<TExponent, TMantissa>& Number<TExponent, TMantissa>::
    operator=(Number<TExponent, TMantissa>&& mov)
{
    m_exp = mov.m_exp;
    m_int_ndigit = mov.m_int_ndigit;
    m_rem_ndigit = mov.m_rem_ndigit;
    m_int = mov.m_int;
    m_rem = mov.m_rem;
    return *this;
}

template<typename TExponent, typename TMantissa>
void Number<TExponent, TMantissa>::
    SetInteger(const TMantissa& val, const TExponent& ndigit)
{
    m_int = val;
    m_int_ndigit = ndigit;
}

template<typename TExponent, typename TMantissa>
void Number<TExponent, TMantissa>::
    SetRemainder(const TMantissa& val, const TExponent& ndigit)
{
    m_rem = val;
    m_rem_ndigit = ndigit;
}

template<typename TExponent, typename TMantissa>
void Number<TExponent, TMantissa>::SetExponent(const TExponent& val)
{
    m_exp = val;
}

template<typename TExponent, typename TMantissa>
TMantissa Number<TExponent, TMantissa>::GetInteger() const
{
    return m_int;
}

template<typename TExponent, typename TMantissa>
TMantissa Number<TExponent, TMantissa>::GetRemainder() const
{
    return m_rem;
}

template<typename TExponent, typename TMantissa>
TExponent Number<TExponent, TMantissa>::GetExponent() const
{
    return m_exp;
}

template<typename TExponent, typename TMantissa>
TExponent Number<TExponent, TMantissa>::GetIntegerDigitSize() const
{
    return m_int_ndigit;
}

template<typename TExponent, typename TMantissa>
TExponent Number<TExponent, TMantissa>::GetRemainderDigitSize() const
{
    return m_rem_ndigit;
}

} //fp

} //!test

#endif //!TEST_FP_NUMBER_H_
