#ifndef TEST_FP_BASE_H_
#define TEST_FP_BASE_H_

#include "../bit/index/Big.h"
#include "Number.h"

#include <cstddef>
#include <cmath>
#include <cfloat>
#include <utility>

namespace test
{
namespace fp
{

template<std::size_t N, typename TFloatingPoint, 
    bool BNormalize = false>
class Base
{};

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
class Base<N, TTFloatingPoint<TFloat, TFormat>, false>
{
public:
    typedef TTFloatingPoint<TFloat, TFormat> FloatingPointType;
    typedef typename FloatingPointType::SignType SignType;
    typedef typename FloatingPointType::ExponentType ExponentType;
    typedef typename FloatingPointType::MantissaType MantissaType;
    typedef typename FloatingPointType::SignedIntegerType SignedIntegerType;
    typedef typename FloatingPointType::UnsignedIntegerType 
        UnsignedIntegerType;
    typedef test::fp::Number<ExponentType, MantissaType> NumberType;
protected:
    typedef void (InitializeFuncType(int&, TFloat&, ExponentType&, 
        NumberType&));
protected:
    static int _InitExponent(TFloat& mant_exp, 
        const MantissaType& subnorm_mant, const int& subnorm_ndigit_mant);
    static void _InitNormalMantisssa(TFloat& mant, TFloat& mant_exp);
    static void _InitSubNormalMantisssa(TFloat& mant, const TFloat& mant_exp,
        MantissaType subnorm_mant, const int& subnorm_ndigit_mant);
    static void _InitNumber(NumberType& num, const TFloat& mant, 
        const ExponentType& mant_exp);
private:
    static void _Initialize(int& classify, TFloat& mant, 
        ExponentType& mant_exp, NumberType& num);
public:
    static constexpr TFloat Log();
public:
    static constexpr ExponentType MinimumBinExponent();
    static constexpr ExponentType MaximumBinExponent();
public:
    static constexpr MantissaType MinimumMantissa();
    static constexpr MantissaType MaximumMantissa();
    static constexpr int DigitSizeMantissa(const MantissaType& mant);
    static constexpr int BitSizeMantissa();
public:
    int m_classify;
    ExponentType m_exp;
    TFloat m_mant;
    NumberType m_num;
public:
    Base();
    Base(const TTFloatingPoint<TFloat, TFormat>& fp);
protected:
    Base(InitializeFuncType* init_func, 
        const TTFloatingPoint<TFloat, TFormat>& fp);
public:
    ~Base();
public:
    Base(const Base<N, TTFloatingPoint<TFloat, TFormat>, false>& cpy);
    Base(Base<N, TTFloatingPoint<TFloat, TFormat>, false>&& mov);
public:
    Base<N, TTFloatingPoint<TFloat, TFormat>, false>&
        operator=(const Base<N, TTFloatingPoint<TFloat, TFormat>, 
            false>& cpy);
    Base<N, TTFloatingPoint<TFloat, TFormat>, false>& 
        operator=(Base<N, TTFloatingPoint<TFloat, TFormat>,false>&& mov);
public:
    int Classify() const;
public:
    bool IsSign() const;
    ExponentType GetExponent() const;
    TFloat GetMantissa() const;
public:
    NumberType GetNumber() const;
};

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
class Base<N, TTFloatingPoint<TFloat, TFormat>, true> :
    private  Base<N, TTFloatingPoint<TFloat, TFormat>, false>
{
private:
    typedef Base<N, TTFloatingPoint<TFloat, TFormat>, false> BaseType;
public:
    typedef typename BaseType::FloatingPointType FloatingPointType;
    typedef typename BaseType::SignType SignType;
    typedef typename BaseType::ExponentType ExponentType;
    typedef typename BaseType::MantissaType MantissaType;
    typedef typename BaseType::SignedIntegerType SignedIntegerType;
    typedef typename BaseType::UnsignedIntegerType UnsignedIntegerType;
    typedef typename BaseType::NumberType NumberType;
protected:
    static void _InitNumber(NumberType& num, const TFloat& mant, 
        const ExponentType& mant_exp);
private:
    static void _Initialize(int& classify, TFloat& mant, 
        ExponentType& mant_exp, NumberType& num);
public:
    using BaseType::Log;
public:
    using BaseType::MinimumBinExponent;
    using BaseType::MaximumBinExponent;
public:
    using BaseType::MinimumMantissa;
    using BaseType::MaximumMantissa;
    using BaseType::DigitSizeMantissa;
    using BaseType::BitSizeMantissa;
public:
    Base();
    Base(const TTFloatingPoint<TFloat, TFormat>& fp);
public:
    ~Base();
public:
    Base(const Base<N, TTFloatingPoint<TFloat, TFormat>, true>& cpy);
    Base(Base<N, TTFloatingPoint<TFloat, TFormat>, true>&& mov);
public:
    Base<N, TTFloatingPoint<TFloat, TFormat>, true>&
        operator=(const Base<N, TTFloatingPoint<TFloat, TFormat>, 
            true>& cpy);
    Base<N, TTFloatingPoint<TFloat, TFormat>, true>& 
        operator=(Base<N, TTFloatingPoint<TFloat, TFormat>,true>&& mov);
public:
    using BaseType::Classify;
public:
    using BaseType::IsSign;
    using BaseType::GetExponent;
    using BaseType::GetMantissa;
public:
    using BaseType::GetNumber;
};

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
int Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    _InitExponent(TFloat& mant_exp, const MantissaType& subnorm_mant,
        const int& subnorm_ndigit_mant)
{
    const bool is_more_max_binexp = mant_exp > MaximumBinExponent();
    const bool is_less_min_binexp = mant_exp < MinimumBinExponent();
    
    if(is_more_max_binexp && subnorm_mant == 0)
    {
        mant_exp *= Log();
        return FP_INFINITE;
    }
    else if(is_more_max_binexp && subnorm_mant != 0)
    {
        mant_exp *= Log();
        return FP_NAN;
    }
    else if (is_less_min_binexp && subnorm_mant == 0)
    {
        mant_exp *= Log();
        return FP_ZERO;
    }

    if (is_less_min_binexp) 
    {
        mant_exp -= ((BitSizeMantissa() * 2) - subnorm_ndigit_mant);
        mant_exp *= Log();
        return FP_SUBNORMAL;
    }

    mant_exp -= BitSizeMantissa();
    mant_exp *= Log();
    return FP_NORMAL;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
void Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    _InitNormalMantisssa(TFloat& mant, TFloat& mant_exp)
{
    const TFloat abs_exp = std::abs(mant_exp);
    const TFloat index = abs_exp - std::floor(abs_exp);

    if (mant_exp < 0) mant *= std::pow((TFloat)N, -index);
    else if (index != 0)
    {
        mant *= std::pow((TFloat)N, index - 1);
        mant_exp += 1;
    }
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
void Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    _InitSubNormalMantisssa(TFloat& mant, const TFloat& mant_exp,
        MantissaType subnorm_mant, const int& subnorm_ndigit_mant)
{
    const TFloat abs_exp = std::abs(mant_exp);
    const TFloat index = abs_exp - std::floor(abs_exp);
    subnorm_mant <<= (int)((BitSizeMantissa() + 1) - subnorm_ndigit_mant);
    mant = subnorm_mant; 
    mant *= std::pow((TFloat)N, -index);
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
void Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    _InitNumber(NumberType& num, const TFloat& mant, 
        const ExponentType& mant_exp)
{
    const int ndigit_mant = DigitSizeMantissa(mant) + 1;
    const ExponentType diff_exp = std::abs(mant_exp) - ndigit_mant;
    const auto abs_mant_exp = std::abs(mant_exp);
    if (mant_exp >= 0)
    {
        num.SetInteger(mant, ndigit_mant);
        num.SetRemainder(0, 0);
        num.SetExponent(mant_exp);
    }
    else if (mant_exp <= -ndigit_mant)
    {
        num.SetInteger(0, 0);
        num.SetRemainder(mant, ndigit_mant);
        num.SetExponent(num.GetRemainder() == 0 ? 0 : mant_exp);
    }
    else
    {
        
        TFloat int_f = std::floor(mant);
        int_f *= std::pow((TFloat)N, mant_exp);
        num.SetInteger(std::floor(int_f), std::abs(diff_exp));
        TFloat rem_f = num.GetInteger();
        rem_f *= std::pow((TFloat)N, -mant_exp);
        rem_f = mant - rem_f;
        rem_f = std::floor(rem_f);
        if (rem_f == 0)
        {
            num.SetRemainder(0, 0);
            num.SetExponent(0);
        }
        else
        {
            num.SetRemainder(rem_f, DigitSizeMantissa(rem_f) + 1);
            num.SetExponent(mant_exp);
        }
    }
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
void Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    _Initialize(int& classify, TFloat& mant, ExponentType& mant_exp, 
        NumberType& num)
{
    MantissaType subnorm_mant = std::abs(mant);
    subnorm_mant &= ~MinimumMantissa();
    const ExponentType sub_mant_ndigit = test::bit::index::Big(subnorm_mant, 
        TTFloatingPoint<TFloat, TFormat>::BitFieldMantissa() + 1) + 1;
    TFloat fexp = mant_exp;
    classify = _InitExponent(fexp, subnorm_mant, sub_mant_ndigit);
    switch (classify)
    {
    case FP_NORMAL:
        _InitNormalMantisssa(mant, fexp);
        _InitNumber(num, mant, fexp);
        break;
    case FP_SUBNORMAL:
        _InitSubNormalMantisssa(mant, fexp, subnorm_mant, sub_mant_ndigit);
        _InitNumber(num, mant, fexp);
        break;
    case FP_ZERO:
    case FP_INFINITE:
    case FP_NAN:
    default:
        break;
    }
    mant_exp = fexp < 0 ? (ExponentType)-std::floor(std::abs(fexp)) : 
        (ExponentType)std::floor(fexp);
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr TFloat Base<N, TTFloatingPoint<TFloat, TFormat>, false>::Log()
{
    return std::log((TFloat)2) / std::log((TFloat)N);
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr typename Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    ExponentType 
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::MinimumBinExponent()
{
    return TTFloatingPoint<TFloat, TFormat>::MinimumExponent();
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr typename Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    ExponentType 
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::MaximumBinExponent()
{
    return TTFloatingPoint<TFloat, TFormat>::MaximumExponent();
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr typename Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    MantissaType 
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::MinimumMantissa()
{
    return TTFloatingPoint<TFloat, TFormat>::MinimumNormalMantissa();
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr typename Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    MantissaType 
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::MaximumMantissa()
{
    return TTFloatingPoint<TFloat, TFormat>::MaximumNormalMantissa();
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr int Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    DigitSizeMantissa(const MantissaType& mant)
{
    return N == 2 ? test::bit::index::Big(mant, 
        TTFloatingPoint<TFloat, TFormat>::BitFieldMantissa() + 1) :
        std::floor(std::log((TFloat)mant) / std::log((TFloat)N));
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
constexpr int Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    BitSizeMantissa()
{
    return TTFloatingPoint<TFloat, TFormat>::BitFieldMantissa();
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::Base() :
    m_classify(FP_ZERO),
    m_exp(0),
    m_mant(0.0f),
    m_num()
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    Base(const TTFloatingPoint<TFloat, TFormat>& fp) :
        m_classify(FP_ZERO),
        m_exp(fp.GetExponent()),
        m_mant(fp.GetNormalMantissa()),
        m_num()
{
    _Initialize(m_classify, m_mant, m_exp, m_num);
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    Base(InitializeFuncType* init_func, 
        const TTFloatingPoint<TFloat, TFormat>& fp) :
            m_classify(FP_ZERO),
            m_exp(fp.GetExponent()),
            m_mant(fp.GetNormalMantissa()),
            m_num()
{
    init_func(m_classify, m_mant, m_exp, m_num);
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::~Base()
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    Base(const Base<N, TTFloatingPoint<TFloat, TFormat>, false>& cpy) :
        m_classify(cpy.m_classify),
        m_exp(cpy.m_exp),
        m_mant(cpy.m_mant),
        m_num(cpy.m_num)
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    Base(Base<N, TTFloatingPoint<TFloat, TFormat>, false>&& mov) :
        m_classify(mov.m_classify),
        m_exp(mov.m_exp),
        m_mant(mov.m_mant),
        m_num(mov.m_num)
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>&
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    operator=(const Base<N, TTFloatingPoint<TFloat, TFormat>, false>& cpy)
{
    m_classify = cpy.m_classify;
    m_exp = cpy.m_exp;
    m_mant = cpy.m_mant;
    m_num = cpy.m_num;
    return *this;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, false>& 
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::
    operator=(Base<N, TTFloatingPoint<TFloat, TFormat>,false>&& mov)
{
    m_classify = mov.m_classify;
    m_exp = mov.m_exp;
    m_mant = mov.m_mant;
    m_num = mov.m_num;
    return *this;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
int Base<N, TTFloatingPoint<TFloat, TFormat>, false>::Classify() const
{
    return m_classify;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
bool Base<N, TTFloatingPoint<TFloat, TFormat>, false>::IsSign() const
{
    return m_mant < 0;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
typename Base<N, TTFloatingPoint<TFloat, TFormat>, false>::ExponentType
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::GetExponent() const
{
    return m_exp;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
TFloat Base<N, TTFloatingPoint<TFloat, TFormat>, false>::GetMantissa() const
{
    return m_mant;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
typename Base<N, TTFloatingPoint<TFloat, TFormat>, false>::NumberType 
Base<N, TTFloatingPoint<TFloat, TFormat>, false>::GetNumber() const
{
    return m_num;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
void Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    _InitNumber(NumberType& num, const TFloat& mant, 
        const ExponentType& mant_exp)
{
    const int ndigit_mant = DigitSizeMantissa(mant) + 1;
    ExponentType rem_ndigit = ndigit_mant - 1;

    TFloat int_f = std::floor(mant);
    int_f *= std::pow((TFloat)N, -rem_ndigit);

    if (int_f == 0)
    {
        num.SetInteger(0, 0);
        num.SetRemainder(0, 0);
        num.SetExponent(0);
        return;
    }
    
    num.SetInteger(std::floor(int_f), 1);

    TFloat rem_f = num.GetInteger();
    rem_f *= std::pow((TFloat)N, rem_ndigit);
    rem_f = mant - rem_f;
    
    num.SetExponent(mant_exp + rem_ndigit);

    if (N == 2)
    {
        rem_f *= std::pow((TFloat)N, 1);
        rem_ndigit += 1;
    }
    rem_f = std::floor(rem_f);

    if (rem_f == 0)
        num.SetRemainder(0, rem_ndigit);
    else
        num.SetRemainder(rem_f, rem_ndigit);
    
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
void Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    _Initialize(int& classify, TFloat& mant, ExponentType& mant_exp, 
        NumberType& num)
{
    MantissaType subnorm_mant = std::abs(mant);
    subnorm_mant &= ~MinimumMantissa();
    const ExponentType sub_mant_ndigit = test::bit::index::Big(subnorm_mant, 
        TTFloatingPoint<TFloat, TFormat>::BitFieldMantissa() + 1) + 1;
    TFloat fexp = mant_exp;
    classify = BaseType::_InitExponent(fexp, subnorm_mant, sub_mant_ndigit);
    switch (classify)
    {
    case FP_NORMAL:
        BaseType::_InitNormalMantisssa(mant, fexp);
        _InitNumber(num, mant, fexp);
        break;
    case FP_SUBNORMAL:
        BaseType::_InitSubNormalMantisssa(mant, fexp, subnorm_mant, 
            sub_mant_ndigit);
        _InitNumber(num, mant, fexp);
        break;
    case FP_ZERO:
    case FP_INFINITE:
    case FP_NAN:
    default:
        break;
    }
    mant_exp = fexp < 0 ? (ExponentType)-std::floor(std::abs(fexp)) : 
        (ExponentType)std::floor(fexp);
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::Base() :
    BaseType()
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    Base(const TTFloatingPoint<TFloat, TFormat>& fp) :
        BaseType(&_Initialize, fp)
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::~Base()
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    Base(const Base<N, TTFloatingPoint<TFloat, TFormat>, true>& cpy) :
        BaseType(cpy)
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    Base(Base<N, TTFloatingPoint<TFloat, TFormat>, true>&& mov) :
        BaseType(std::move(mov))
{}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>&
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    operator=(const Base<N, TTFloatingPoint<TFloat, TFormat>, true>& cpy)
{
    BaseType::operator=(cpy);
    return *this;
}

template<std::size_t N, typename TFloat, typename TFormat,
    template <typename, typename> class TTFloatingPoint>
Base<N, TTFloatingPoint<TFloat, TFormat>, true>& 
Base<N, TTFloatingPoint<TFloat, TFormat>, true>::
    operator=(Base<N, TTFloatingPoint<TFloat, TFormat>,true>&& mov)
{
    BaseType::operator=(std::move(mov));
    return *this;
}

} //!fp

} //!test

#endif //!TEST_FP_BASE_H_
