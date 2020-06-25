#ifndef TEST_OUT_FILE_STATUS_H_
#define TEST_OUT_FILE_STATUS_H_

#include <cstdint>
#include <type_traits>

namespace test
{
namespace out
{
namespace file
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
public:
    static constexpr IntegerValueType output_mask = 0x03;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),
        standard_output = 1,
        file_output = 2,
        open_failed = bad | (IntegerValueType(1) << 2),
        print_buffer_failed = bad | (2 << 2),
        print_output_failed = bad | (3 << 2),
        print_buffer_overflow = bad | (4 << 2),
        puts_output_failed = bad | (5 << 2),
        puts_buffer_overflow = bad | (6 << 2)
    };
private:
    ValueType m_val;
public:
    Status();
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
    bool IsStandardOutput() const;
    bool IsFileOutput() const;
public:
    bool StandardOutput();
    bool FileOutput();
public:
    void Reset();
public:
    bool Bad(const IntegerValueType& code);
public:
    IntegerValueType BadCode() const;
};

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::Status() :
    m_val(good)
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
Status<TValue, TIntegerValue>::
    Status(Status<TValue, TIntegerValue>&& mov) :
        m_val((TIntegerValue)mov.m_val)
{
    mov.Reset();
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& Status<TValue, TIntegerValue>::
    operator=(const Status<TValue, TIntegerValue>& cpy)
{
    m_val = (TIntegerValue)cpy.m_val;
    return *this;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& Status<TValue, TIntegerValue>::
    operator=(Status<TValue, TIntegerValue>&& mov)
{
    m_val = (TIntegerValue)mov.m_val;
    mov.Reset();
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
bool Status<TValue, TIntegerValue>::IsStandardOutput() const
{
    return m_val & standard_output;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsFileOutput() const
{
    return m_val & file_output;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::StandardOutput()
{
    if (m_val & output_mask) return false;
    m_val |= standard_output;
    return true;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::FileOutput()
{
    if (m_val & output_mask) return false;
    m_val |= file_output;
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
    m_val |= (code & ~output_mask);
    return true;
}

template<typename TValue, typename TIntegerValue>
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::BadCode() const
{
    return m_val & ~output_mask;
}

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_STATUS_H_