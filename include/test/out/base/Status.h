#ifndef TEST_OUT_BASE_STATUS_H_
#define TEST_OUT_BASE_STATUS_H_

namespace test
{
namespace out
{
namespace base
{

template<typename TValue, typename TIntegerValue = TValue>
class Status
{
public:
    typedef TValue ValueType;
    typedef TIntegerValue IntegerValueType;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1))
    };
private:
    TValue m_val;
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
    m_val(val)
{}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::~Status()
{
    m_val = good;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::
    Status(const Status<TValue, TIntegerValue>& cpy) :
        m_val((IntegerValueType)cpy.m_val)
{}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::Status(Status<TValue, TIntegerValue>&& mov) :
    m_val((IntegerValueType)mov.m_val)
{
    mov.m_val = good;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::
    operator=(const Status<TValue, TIntegerValue>& cpy)
{
    m_val = (IntegerValueType)cpy.m_val;
    return *this;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::operator=(Status<TValue, TIntegerValue>&& mov)
{
    m_val = (IntegerValueType)mov.m_val;
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
void Status<TValue, TIntegerValue>::Reset()
{
    m_val = good;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Bad(const IntegerValueType& code)
{
    if (m_val & bad) return false;
    m_val |= code;
    return true;
}

template<typename TValue, typename TIntegerValue>
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::GetBadCode() const
{
    return m_val;
}

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_STATUS_H_