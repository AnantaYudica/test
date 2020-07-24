#ifndef TEST_MSG_FMT_STATUS_H_
#define TEST_MSG_FMT_STATUS_H_

#include <cstdint>
#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{

template<typename TValue = std::uint8_t, typename TIntegerValue = TValue>
class Status
{
public:
    typedef TValue ValueType;
    typedef TIntegerValue IntegerValueType;
private:
    static constexpr IntegerValueType bad_offset = 2;
    static constexpr IntegerValueType value_mask = 3;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),
        default_value = 1 | 2,
        set_value = 2,
        value_not_set = (1 << bad_offset) | bad,
        load_failed = (2 << bad_offset) | bad,
        flag_undefined = (3 << bad_offset) | bad
    };
private:
    ValueType m_value; 
public: 
    Status();
    Status(const IntegerValueType& val);
public:
    ~Status();
public:
    Status(const Status<TValue, TIntegerValue>& cpy);
    Status(Status<TValue, TIntegerValue>&& mov);
public:
    Status<TValue, TIntegerValue>& 
        operator=(const Status<TValue, TIntegerValue>& cpy);
    Status<TValue, TIntegerValue>& 
        operator=(Status<TValue, TIntegerValue>&& mov);
public:
    bool IsGood() const;
    bool IsBad() const;
    bool IsDefaultValue() const;
    bool IsSetValue() const;
public:
    bool SetValue();
    void UnsetValue();
public:
    void Reset();
    bool Reset(const IntegerValueType& bad_code);
public:
    bool Bad(const IntegerValueType& code);
public:
    IntegerValueType GetBadCode() const;
};

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::Status() :
    m_value(good)
{}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::Status(const IntegerValueType& val) :
    m_value(val)
{}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::~Status()
{
    m_value = good;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::
    Status(const Status<TValue, TIntegerValue>& cpy) :
        m_value((TIntegerValue)cpy.m_value)
{}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::
    Status(Status<TValue, TIntegerValue>&& mov) :
        m_value((TIntegerValue)mov.m_value)
{
    if ((mov.m_value & default_value) == set_value)
        mov.m_value = good;
    else
        mov.m_value = default_value;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::
    operator=(const Status<TValue, TIntegerValue>& cpy)
{
    m_value = (TIntegerValue)cpy.m_value;
    return *this;
}
    
template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::operator=(Status<TValue, TIntegerValue>&& mov)
{
    m_value = (TIntegerValue)mov.m_value;
    if ((mov.m_value & default_value) == set_value)
        mov.m_value = good;
    else
        mov.m_value = default_value;
    return *this;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsGood() const
{
    return !(m_value & bad);
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsBad() const
{
    return m_value & bad;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsDefaultValue() const
{
    return m_value & (default_value ^ set_value);
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsSetValue() const
{
    return m_value & set_value;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::SetValue()
{
    if ((m_value & (bad | value_mask)) != good)
        return false;
    m_value |= set_value;
    return true;
}

template<typename TValue, typename TIntegerValue>
void Status<TValue, TIntegerValue>::UnsetValue()
{
    if ((m_value & default_value) == set_value)
    {
        m_value ^= set_value;
    }
}
    
template<typename TValue, typename TIntegerValue>
void Status<TValue, TIntegerValue>::Reset()
{
    if ((m_value & default_value) == default_value)
        m_value = default_value;
    else
        m_value = good;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Reset(const IntegerValueType& bad_code)
{
    if (bad_code == value_not_set)
    {
        m_value ^= value_not_set;
        return true;
    }
    return false;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Bad(const IntegerValueType& code)
{
    if (m_value & bad) return false;
    m_value |= (code & ~value_mask);
    return true;
}

template<typename TValue, typename TIntegerValue>
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::GetBadCode() const
{
    return m_value & ~value_mask;
}

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_STATUS_H_