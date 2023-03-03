#ifndef TEST_OUT_FMT_STATUS_H_
#define TEST_OUT_FMT_STATUS_H_

#include "../../System.h"

#include <cstdint>
#include <utility>
#include <atomic>

namespace test
{
namespace out
{
namespace fmt
{

class Status;

} //!fmt

} //!out

} //!test

#ifndef TEST_OUT_FMT_STATUS_DLEVEL

#define TEST_OUT_FMT_STATUS_DLEVEL 2

#endif //!TEST_OUT_FMT_STATUS_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_OUT_FMT_STATUS_DLEVEL, 
    "test::out::fmt::Status", test::out::fmt::Status);


namespace test
{
namespace out
{
namespace fmt
{

class Status
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::out::fmt::Status> DebugType;
public:
    typedef std::uint8_t IntegerValueType;
    typedef std::atomic<IntegerValueType> ValueType;
private:
    static constexpr IntegerValueType bad_offset = 1;
public:
    enum : IntegerValueType
    {
        good = (IntegerValueType)-1,
        bad = IntegerValueType((IntegerValueType)-1 << 1),
        value_not_set = (0 << bad_offset) & bad,
        load_failed = (1 << bad_offset) & bad
    };
private:
    ValueType m_value; 
public: 
    inline Status();
public:
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
    inline void Reset();
public:
    inline bool Bad(const IntegerValueType& code);
public:
    inline IntegerValueType GetBadCode() const;
};

inline Status::Status() :
    m_value(value_not_set)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Status::~Status()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
    m_value.store(value_not_set);
}

inline Status::Status(const Status& cpy) :
        m_value((IntegerValueType)cpy.m_value.load())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);
    
}

inline Status::Status(Status&& mov) :
        m_value((IntegerValueType)mov.m_value.load())
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);
    
    mov.m_value.store(value_not_set);
}

inline Status& Status::operator=(const Status& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);

    m_value.store((IntegerValueType)cpy.m_value.load());
    
    return *this;
}

inline Status& Status::operator=(Status&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    m_value.store((IntegerValueType)mov.m_value.load());
    mov.m_value.store(value_not_set);
    return *this;
}

inline bool Status::IsGood() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsGood() const");
    
    return m_value.load() == good;
}

inline bool Status::IsBad() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsBad() const");
    
    return m_value.load() < good;
}

inline void Status::Reset()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "Reset()");
    
    m_value.store(value_not_set);
}

inline bool Status::Bad(const IntegerValueType& code)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, 
        "Bad(code=%s)", TEST_SYS_DEBUG_VALUE_STR(1, code));
    
    if (m_value.load() < good && 
        m_value.load() > value_not_set) 
    {
        return false;
    }

    m_value.store(code);
    return true;
}

inline typename Status::IntegerValueType Status::GetBadCode() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "GetBadCode() const");
    
    return m_value.load();
}

} //!fmt

} //!out

} //!test

#endif //!TEST_OUT_FMT_STATUS_H_
