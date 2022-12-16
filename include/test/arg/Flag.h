#ifndef TEST_ARG_FLAG_H_
#define TEST_ARG_FLAG_H_

#include "../System.h"

#include <cstddef>
#include <cstdint>

namespace test::arg
{
class Flag;
}

TEST_SYS_DBG_TYPE_DEFINE("test::arg::Flag", test::arg::Flag);

namespace test
{
namespace arg
{

class Flag
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::arg::Flag> DebugType;
public:
    typedef std::uint8_t IntegerValueType;
public:
    enum ValueEnum : IntegerValueType
    {
        forward_end = 1,
        backward_end = 2
    };
private:
    IntegerValueType m_value;
public:
    inline Flag();
    inline Flag(const ValueEnum& flag);
    inline Flag(const std::size_t& size);
public:
    inline ~Flag();
public:
    inline Flag(const Flag& cpy);
    inline Flag(Flag&& mov);
public:
    inline Flag& operator=(const Flag& cpy);
    inline Flag& operator=(Flag&& mov);
public:
    inline std::size_t Forward(const std::size_t& n, const std::size_t& pos,
        const std::size_t end);
    inline std::size_t Backward(const std::size_t& n, const std::size_t& pos,
        const std::size_t end);
public:
    inline std::size_t Position(const std::size_t& pos, 
        const std::size_t end) const;
public:
    inline bool IsForwardEnd() const;
    inline bool IsBackwardEnd() const;
    inline bool IsEnd() const;
public:
    inline void Reset();
public:
    inline bool operator==(const Flag& other) const;
    inline bool operator!=(const Flag& other) const;
};

inline Flag::Flag() :
    m_value(forward_end | backward_end)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");

}

inline Flag::Flag(const ValueEnum& flag) :
    m_value(flag)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(flag=%hhu)", flag);

}

inline Flag::Flag(const std::size_t& n) :
    m_value(n != 0 ? 0 : (forward_end | backward_end))
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Constructor(n=%zu)", n);
    
}

inline Flag::~Flag()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Destructor");
    
    m_value = 0;
}

inline Flag::Flag(const Flag& cpy) :
    m_value(cpy.m_value)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Constructor(cpy=%p)", &cpy);

}

inline Flag::Flag(Flag&& mov) :
    m_value(mov.m_value)
{    
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Constructor(mov=%p)", &mov);

}

inline Flag& Flag::operator=(const Flag& cpy)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Copy Assignment(cpy=%p)", &cpy);
    
    m_value = cpy.m_value;
    return *this;
}

inline Flag& Flag::operator=(Flag&& mov)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, 
        "Move Assignment(mov=%p)", &mov);
    
    m_value = mov.m_value;
    return *this;
}

inline std::size_t Flag::Forward(const std::size_t& n, const std::size_t& pos,
    const std::size_t end)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Forward(n=%zu, pos=%zu, end=%zu)", n, pos, end);

    if (n == 0) return pos;
    if (m_value & (forward_end | backward_end)) return end;
    else if (IsBackwardEnd()) 
    {
        m_value &= ~backward_end;
        return Forward(n - 1, 0, end);
    }
    const std::size_t next = pos + n;
    if (next >= end || pos > next)
    {
        m_value |= forward_end;
        return end;
    }
    return next;
}

inline std::size_t Flag::Backward(const std::size_t& n, const std::size_t& pos,
    const std::size_t end)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Backward(n=%zu, pos=%zu, end=%zu)", n, pos, end);

    if (n == 0) return pos;
    if (m_value & (forward_end | backward_end)) return end;
    else if (IsForwardEnd())
    {
        m_value &= ~forward_end;
    }
    if (pos < n)
    {
        m_value |= backward_end;
        return end;
    }
    return pos - n;
}

inline std::size_t Flag::Position(const std::size_t& pos, 
    const std::size_t end) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, 
        "Position(pos=%zu, end=%zu)", pos, end);

    if (m_value & (forward_end | backward_end))
        return end;
    return pos;
}

inline bool Flag::IsForwardEnd() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsForwardEnd() const");

    return m_value & forward_end;
}

inline bool Flag::IsBackwardEnd() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsBackwardEnd() const");

    return m_value & backward_end;
}

inline bool Flag::IsEnd() const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, this, "IsEnd() const");

    return m_value & (forward_end | backward_end);
}

inline void Flag::Reset()
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this, "Reset()");

    m_value = 0;
}

inline bool Flag::operator==(const Flag& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this,
        "operator==(other=%p)", &other);

    return IsEnd() == other.IsEnd();
}

inline bool Flag::operator!=(const Flag& other) const
{
    TEST_SYS_DEBUG(SystemType, DebugType, 2, this,
        "operator!=(other=%p)", &other);
    
    return IsEnd() != other.IsEnd();
}

} //!arg

} //!test

#endif //!TEST_ARG_FLAG_H_
