#ifndef TEST_OUT_CSTR_STATUS_H_
#define TEST_OUT_CSTR_STATUS_H_

#include <cstdint>
#include <utility>

namespace test
{
namespace out
{
namespace cstr
{

class Status
{
public:
    typedef std::uint8_t ValueType;
private:
    static constexpr ValueType require_mask = 0x07;
public:
    enum : ValueType
    {
        good = 0,
        bad = 0x80,
        require_initialize = good | 0x01,
        require_allocation = good | 0x02,
        require_reallocation = good | 0x4,
        overflow_capacity = bad | (0x01 << 3),
        predict_failed = bad | (0x02 << 3),
        allocation_failed = bad | (0x03 << 3),
        zero_allocation_failed = bad | (0x04 << 3),
        reallocation_failed = bad | (0x05 << 3),
        predict_reallocation_failed = bad | (0x06 << 3),
        copy_reallocation_failed = bad | (0x07 << 3),
    };
private:
    ValueType m_val;
public:
    inline Status();
    inline ~Status();
public:
    inline Status(const Status& cpy);
    inline Status(Status&& mov);
public:
    inline Status& operator=(const Status& cpy);
    inline Status& operator=(Status&& mov);
public:
    inline bool IsGood() const;
    inline bool IsBad() const;
public:
    inline bool IsRequire() const;
    inline bool IsRequire(const ValueType& val) const;
public:
    inline bool IsRequireInitialize() const;
    inline bool IsRequireAllocation() const;
    inline bool IsRequireReallocation() const;
public:
    inline void Reset();
public:
    inline void Require(const ValueType& val);
    inline void Unrequire(const ValueType& val);
public:
    inline void Bad(const ValueType& code);
public:
    inline ValueType BadCode() const;
};

inline Status::Status() :
    m_val(good)
{}

inline Status::~Status()
{
    m_val = 0;
}

inline Status::Status(const Status& cpy) :
    m_val(cpy.m_val)
{}

inline Status::Status(Status&& mov) :
    m_val(std::move(mov.m_val))
{
    mov.Reset();
}

inline Status& Status::operator=(const Status& cpy)
{
    m_val = cpy.m_val;
    return *this;
}

inline Status& Status::operator=(Status&& mov)
{
    m_val = std::move(mov.m_val);
    mov.Reset();
    return *this;
}

inline bool Status::IsGood() const
{
    return m_val == good;
}

inline bool Status::IsBad() const
{
    return m_val & bad;
}

inline bool Status::IsRequire() const
{
    return m_val & require_mask;
}

inline bool Status::IsRequire(const ValueType& val) const
{
    return m_val & val;
}

inline bool Status::IsRequireInitialize() const
{
    return m_val & require_initialize;
}

inline bool Status::IsRequireAllocation() const
{
    return m_val & require_allocation;
}

inline bool Status::IsRequireReallocation() const
{
    return m_val & require_reallocation;
}

inline void Status::Reset()
{
    m_val = good;
}

inline void Status::Require(const ValueType& val)
{
    m_val |= (require_mask & val);
}

inline void Status::Unrequire(const ValueType& val)
{
    m_val ^= (require_mask & val);
}

inline void Status::Bad(const ValueType& code)
{
    if(m_val & bad) return;
    m_val |= (code & ~require_mask);
}

inline typename Status::ValueType Status::BadCode() const
{
    return m_val & ~require_mask;
}

} //!cstr

} //!out

} //!test

#endif //!TEST_OUT_CSTR_STATUS_H_
