#ifndef TEST_OUT_BASE_TASK_STATUS_H_
#define TEST_OUT_BASE_TASK_STATUS_H_

#include <type_traits>

namespace test
{
namespace out
{
namespace base
{
namespace task
{

template<typename TValue, typename TIntegerValue = TValue>
class Status
{
public:
    static_assert(std::is_unsigned<TIntegerValue>::value, 
        "TIntegerValue is not unsigned type");
    static_assert(std::is_integral<TIntegerValue>::value,
        "TIntegerValue is not integer type");
public:
    typedef TValue ValueType;
    typedef TIntegerValue IntegerValueType;
private:
    static constexpr IntegerValueType stage_mask = 7;
    static constexpr IntegerValueType bad_offset = 3; 
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),
        done = 1,
        release = 2,
        assign = 4
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
    bool IsDone() const;
    bool IsRelease() const;
    bool IsAssign() const;
public:
    bool Assign();
    bool Release();
    bool Execute();
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
        m_val((TIntegerValue)cpy.m_val)
{}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::Status(Status<TValue, TIntegerValue>&& mov) :
    m_val((TIntegerValue)mov.m_val)
{
    mov.m_val = good;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::operator=(const Status<TValue, TIntegerValue>& cpy)
{
    m_val = (TIntegerValue)cpy.m_val;
    return *this;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::operator=(Status<TValue, TIntegerValue>&& mov)
{
    m_val = (TIntegerValue)mov.m_val;
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
bool Status<TValue, TIntegerValue>::IsDone() const
{
    return m_val & done;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsRelease() const
{
    return m_val & release;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsAssign() const
{
    return m_val & assign;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Assign()
{
    if (m_val == good)
    {
        m_val |= assign;
        return true;
    }
    return false;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Release()
{
    if (!(m_val & bad) && m_val & assign)
    {
        m_val |= release;
        return true;
    }
    return false;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Execute()
{
    if ((!(m_val & bad) && m_val & assign) && m_val & release)
    {
        m_val |= done;
        return true;
    }
    return false;
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
    m_val |= (~stage_mask & code);
    return true;
}

template<typename TValue, typename TIntegerValue>
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::GetBadCode() const
{
    return m_val & ~stage_mask;
}

} //!task

} //!base

} //!out

} //!test

#endif //!TEST_OUT_BASE_TASK_STATUS_H_