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
private:
    static constexpr IntegerValueType require_mask = 0x01;
    static constexpr IntegerValueType output_mask = 0x06;
    static constexpr IntegerValueType bad_offset = 3;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),
        require_initialize = 1,
        standard_output = 2,
        file_output = 4,
        open_file_failed = bad | (1 << bad_offset),
        open_file_mode_undefined = bad | (2 << bad_offset),
        close_file_failed = bad | (3 << bad_offset),
        size_file_close_failed = bad | (4 << bad_offset),
        size_file_seek_failed = bad | (5 << bad_offset),
        size_file_tell_failed = bad | (6 << bad_offset),
        size_overflow = bad | (7 << bad_offset),
        unresolve_size_overflow = bad | (8 << bad_offset),
        initialize_failed = bad | (9 << bad_offset),
        print_buffer_failed = bad | (10 << bad_offset),
        print_output_failed = bad | (11 << bad_offset),
        print_buffer_overflow = bad | (12 << bad_offset),
        puts_output_failed = bad | (13 << bad_offset),
        puts_buffer_overflow = bad | (14 << bad_offset),
        filename_size_overflow = bad | (15 << bad_offset)
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
public:
    bool IsRequire(const IntegerValueType& val) const;
public:
    bool IsRequireInitialize() const;
public:
    bool IsStandardOutput() const;
    bool IsFileOutput() const;
public:
    void Require(const IntegerValueType& val);
    void Unrequire(const IntegerValueType& val);
public:
    bool StandardOutput();
    bool FileOutput();
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
Status<TValue, TIntegerValue>::
    Status(const IntegerValueType& val) :
        m_val(val & (require_mask | output_mask))
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
bool Status<TValue, TIntegerValue>::
    IsRequire(const IntegerValueType& val) const
{
    return m_val & (val & require_mask);
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsRequireInitialize() const
{
    return m_val & require_initialize;
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
void Status<TValue, TIntegerValue>::Require(const IntegerValueType& val)
{
    m_val |= (val & require_mask);
}

template<typename TValue, typename TIntegerValue>
void Status<TValue, TIntegerValue>::Unrequire(const IntegerValueType& val)
{
    m_val ^= (val & require_mask);
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
    m_val |= (code & ~(output_mask | require_mask));
    return true;
}

template<typename TValue, typename TIntegerValue>
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::GetBadCode() const
{
    return m_val & ~(output_mask | require_mask);
}

} //!file

} //!out

} //!test

#endif //!TEST_OUT_FILE_STATUS_H_