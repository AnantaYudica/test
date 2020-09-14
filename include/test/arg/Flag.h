#ifndef TEST_ARG_FLAG_H_
#define TEST_ARG_FLAG_H_

#include <cstddef>
#include <cstdint>

namespace test
{
namespace arg
{

class Flag
{
public:
    typedef std::uint8_t IntegerValueType;
public:
    enum : IntegerValueType
    {
        forward_end = 1,
        backward_end = 2
    };
private:
    IntegerValueType m_value;
public:
    inline Flag();
    inline Flag(const IntegerValueType& flag);
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
{}

inline Flag::Flag(const IntegerValueType& flag) :
    m_value(flag)
{}

inline Flag::Flag(const std::size_t& n) :
    m_value(n != 0 ? 0 : (forward_end | backward_end))
{}

inline Flag::~Flag()
{
    m_value = 0;
}

inline Flag::Flag(const Flag& cpy) :
    m_value(cpy.m_value)
{}

inline Flag::Flag(Flag&& mov) :
    m_value(mov.m_value)
{}

inline Flag& Flag::operator=(const Flag& cpy)
{
    m_value = cpy.m_value;
    return *this;
}

inline Flag& Flag::operator=(Flag&& mov)
{
    m_value = mov.m_value;
    return *this;
}

inline std::size_t Flag::Forward(const std::size_t& n, const std::size_t& pos,
    const std::size_t end)
{
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
    if (m_value & (forward_end | backward_end))
        return end;
    return pos;
}

inline bool Flag::IsForwardEnd() const
{
    return m_value & forward_end;
}

inline bool Flag::IsBackwardEnd() const
{
    return m_value & backward_end;
}

inline bool Flag::IsEnd() const
{
    return m_value & (forward_end | backward_end);
}

inline void Flag::Reset()
{
    m_value = 0;
}

inline bool Flag::operator==(const Flag& other) const
{
    return IsEnd() == other.IsEnd();
}

inline bool Flag::operator!=(const Flag& other) const
{
    return IsEnd() != other.IsEnd();
}

} //!arg

} //!test

#endif //!TEST_ARG_FLAG_H_
