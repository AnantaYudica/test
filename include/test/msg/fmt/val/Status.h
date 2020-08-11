#ifndef TEST_MSG_FMT_VAL_STATUS_H_
#define TEST_MSG_FMT_VAL_STATUS_H_

#include <cstdint>
#include <utility>

namespace test
{
namespace msg
{
namespace fmt
{
namespace val
{

class Status
{
public:
    typedef std::uint8_t ValueType;
    typedef std::uint8_t IntegerValueType;
public:
    enum : IntegerValueType
    {
        default_value = 1 | 2,
        set_value = 2,
    };
private:
    ValueType m_value; 
public: 
    inline Status();
    inline Status(const IntegerValueType& val);
public:
    inline ~Status();
public:
    inline Status(const Status& cpy);
    inline Status(Status&& mov);
public:
    inline Status& operator=(const Status& cpy);
    inline Status& operator=(Status&& mov);
public:
    inline bool IsDefaultValue() const;
    inline bool IsSetValue() const;
public:
    inline bool SetValue();
    inline void UnsetValue();
public:
    inline void Reset();
};

inline Status::Status() :
    m_value(0)
{}

inline Status::Status(const IntegerValueType& val) :
    m_value(val)
{}

inline Status::~Status()
{
    m_value = 0;
}

inline Status::Status(const Status& cpy) :
    m_value(cpy.m_value)
{}

inline Status::Status(Status&& mov) :
    m_value(mov.m_value)
{
    if ((mov.m_value & default_value) == set_value)
        mov.m_value = 0;
    else
        mov.m_value = default_value;
}

inline Status& Status::operator=(const Status& cpy)
{
    m_value = (IntegerValueType)cpy.m_value;
    return *this;
}

inline Status& Status::operator=(Status&& mov)
{
    m_value = (IntegerValueType)mov.m_value;
    if ((mov.m_value & default_value) == set_value)
        mov.m_value = 0;
    else
        mov.m_value = default_value;
    return *this;
}

inline bool Status::IsDefaultValue() const
{
    return m_value & (default_value ^ set_value);
}

inline bool Status::IsSetValue() const
{
    return m_value & set_value;
}

inline bool Status::SetValue()
{
    if ((m_value & default_value) != 0)
        return false;
    m_value |= set_value;
    return true;
}

inline void Status::UnsetValue()
{
    if ((m_value & default_value) == set_value)
    {
        m_value ^= set_value;
    }
}

inline void Status::Reset()
{
    if ((m_value & default_value) == default_value)
        m_value = default_value;
    else
        m_value = 0;
}

} //!val

} //!fmt

} //!msg

} //!test

#endif //!TEST_MSG_FMT_VAL_STATUS_H_
