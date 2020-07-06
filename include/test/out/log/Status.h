#ifndef TEST_OUT_LOG_STATUS_H_
#define TEST_OUT_LOG_STATUS_H_

#include <cstdint>

namespace test
{
namespace out
{
namespace log
{

template<typename TValue = std::uint8_t, typename TIntegerValue = TValue>
class Status
{
public:
    typedef TValue ValueType;
    typedef TIntegerValue IntegerValueType;
private:
    static constexpr IntegerValueType stage_mask = 3;
    static constexpr IntegerValueType bad_offset = 2;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),
        begin = 1,
        end = 2,
        on_begin_failed = bad | (1 << bad_offset),
        set_begin_failed = bad | (2 << bad_offset),
        message_failed = bad | (3 << bad_offset),
        on_end_failed = bad | (4 << bad_offset),
        set_end_failed = bad | (5 << bad_offset)
    };
private:
    ValueType m_val;
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
    bool IsBegin() const;
    bool IsEnd() const;
public:
    bool Begin();
    bool End();
public:
    void Reset();
public:
    bool Bad(const IntegerValueType& code);
public:
    IntegerValueType GetBadCode() const;
};

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>::Status() :
    m_val(good)
{}

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>::Status(const IntegerValueType& val) :
    m_val(val & stage_mask)
{}

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>::~Status()
{
    m_val = good;
}

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>::
    Status(const Status<TValue, TIntegerValue>& cpy) :
        m_val(cpy.m_val)
{}

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>::Status(Status<TValue, TIntegerValue>&& mov) :
    m_val(mov.m_val)
{
    mov.m_val = good;
}

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::
    operator=(const Status<TValue, TIntegerValue>& cpy)
{
    m_val = cpy.m_val;
    return *this;
}

template<typename TValue, typename TIntegerValue> 
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::operator=(Status<TValue, TIntegerValue>&& mov)
{
    m_val = mov.m_val;
    mov.m_val = good;
    return *this;
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::IsGood() const
{
    return !(m_val & bad);
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::IsBad() const
{
    return m_val & bad;
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::IsBegin() const
{
    return m_val & begin;
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::IsEnd() const
{
    return m_val & end;
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::Begin()
{
    if (m_val != good) return false;
    m_val |= begin;
    return true;
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::End()
{
    if ((m_val & (bad | begin)) != begin) return false;
    m_val |= end;
    return true; 
}

template<typename TValue, typename TIntegerValue> 
void Status<TValue, TIntegerValue>::Reset()
{
    m_val = good;
}

template<typename TValue, typename TIntegerValue> 
bool Status<TValue, TIntegerValue>::Bad(const IntegerValueType& code)
{
    if (m_val & bad) return false;
    m_val |= (code & ~stage_mask);
    return true;
}

template<typename TValue, typename TIntegerValue> 
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::GetBadCode() const
{
    return m_val & ~stage_mask;
}

} //!log

} //!out

} //!test

#endif //!TEST_OUT_LOG_STATUS_H_