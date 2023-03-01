#ifndef TEST_OUT_FMT_STATUS_H_
#define TEST_OUT_FMT_STATUS_H_

#include "../../System.h"

#include <cstdint>
#include <utility>

namespace test
{
namespace out
{
namespace fmt
{

template<typename TValue, typename TIntegerValue>
class Status;

} //!fmt

} //!out

} //!test


#ifndef TEST_OUT_FMT_STATUS_DLEVEL

#define TEST_OUT_FMT_STATUS_DLEVEL 2

#endif //!TEST_OUT_FMT_STATUS_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TValue>,\
    test::sys::dbg::Type<TIntegerValue>

template<typename TValue, typename TIntegerValue>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_OUT_FMT_STATUS_DLEVEL, 
    "test::out::fmt::Status", 
    test::out::fmt::Status<TValue, TIntegerValue>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS


namespace test
{
namespace out
{
namespace fmt
{

template<typename TValue = std::uint8_t, typename TIntegerValue = TValue>
class Status
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::Status<TValue, 
        TIntegerValue>> DebugType;
public:
    typedef TValue ValueType;
    typedef TIntegerValue IntegerValueType;
private:
    static constexpr IntegerValueType bad_offset = 2;
public:
    enum : IntegerValueType
    {
        good = 0,
        bad = IntegerValueType(~((IntegerValueType)-1 >> 1)),
        value_not_set = (1 << bad_offset) | bad,
        load_failed = (2 << bad_offset) | bad,
        flag_undefined = (3 << bad_offset) | bad
    };
private:
    ValueType m_value; 
public: 
    Status();
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
    bool Reset(const IntegerValueType& bad_code);
public:
    bool Bad(const IntegerValueType& code);
public:
    IntegerValueType GetBadCode() const;
};

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::Status() :
    m_value(good)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::~Status()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
    m_value = good;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::
    Status(const Status<TValue, TIntegerValue>& cpy) :
        m_value((TIntegerValue)cpy.m_value)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>::
    Status(Status<TValue, TIntegerValue>&& mov) :
        m_value((TIntegerValue)mov.m_value)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
    mov.m_value = good;
}

template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::
    operator=(const Status<TValue, TIntegerValue>& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    if (!(m_value & bad))
        m_value = (TIntegerValue)cpy.m_value;
    return *this;
}
    
template<typename TValue, typename TIntegerValue>
Status<TValue, TIntegerValue>& 
Status<TValue, TIntegerValue>::operator=(Status<TValue, TIntegerValue>&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    if (!(m_value & bad))
    {
        m_value = (TIntegerValue)mov.m_value;
        mov.m_value = good;
    }
    return *this;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsGood() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsGood() const");
    
    return !(m_value & bad);
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::IsBad() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsBad() const");
    
    return m_value & bad;
}
 
template<typename TValue, typename TIntegerValue>
void Status<TValue, TIntegerValue>::Reset()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Reset()");
    
    m_value = good;
}

template<typename TValue, typename TIntegerValue>
bool Status<TValue, TIntegerValue>::Reset(const IntegerValueType& bad_code)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Reset(bad_code=%s)", TEST_SYS_DEBUG_VALUE_STR(1, bad_code));
    
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Bad(code=%s)", TEST_SYS_DEBUG_VALUE_STR(1, code));
    
    if (m_value & bad) return false;
    m_value |= code;
    return true;
}

template<typename TValue, typename TIntegerValue>
typename Status<TValue, TIntegerValue>::IntegerValueType 
Status<TValue, TIntegerValue>::GetBadCode() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetBadCode() const");
    
    return m_value;
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_STATUS_H_
