#ifndef TEST_BYTE_IT_OPERATOR_H_
#define TEST_BYTE_IT_OPERATOR_H_

#include <cstddef>
#include <cstdint>

namespace test
{
namespace byte
{
namespace it
{

class Operator
{
public:
    typedef std::size_t (AdditionFuncType(const std::size_t&, 
        const std::size_t&));
    typedef std::size_t (SubtractionFuncType(const std::size_t&, 
        const std::size_t&));
    typedef std::size_t (BeginFuncType(const std::size_t&, 
        const std::size_t&));
    typedef std::size_t (EndFuncType(const std::size_t&, const std::size_t&));
private:
    AdditionFuncType * m_add;
    SubtractionFuncType * m_sub;
    BeginFuncType * m_begin;
    EndFuncType * m_end;
protected:
    inline Operator(AdditionFuncType& add, SubtractionFuncType& sub,
        BeginFuncType& begin, EndFuncType& end);
public:
    inline ~Operator();
public:
    inline Operator(const Operator& cpy);
    inline Operator(Operator&& mov);
public:
    inline Operator& operator=(const Operator& cpy);
    inline Operator& operator=(Operator&& mov);
public:
    inline std::size_t Addition(const std::size_t& i, 
        const std::size_t& a) const;
    inline std::size_t Subtraction(const std::size_t& i, 
        const std::size_t& s) const;
    inline std::size_t Begin(const std::size_t& off, 
        const std::size_t& size) const;
    inline std::size_t End(const std::size_t& off, 
        const std::size_t& size) const;
public:
    inline bool operator==(const Operator& other) const;
    inline bool operator!=(const Operator& other) const;
};

inline Operator::Operator(AdditionFuncType& add, SubtractionFuncType& sub,
    BeginFuncType& begin, EndFuncType& end) :
        m_add(&add),
        m_sub(&sub),
        m_begin(&begin),
        m_end(&end)
{}

inline Operator::~Operator()
{}

inline Operator::Operator(const Operator& cpy) :
    m_add(cpy.m_add),
    m_sub(cpy.m_sub),
    m_begin(cpy.m_begin),
    m_end(cpy.m_end)
{}

inline Operator::Operator(Operator&& mov) :
    m_add(mov.m_add),
    m_sub(mov.m_sub),
    m_begin(mov.m_begin),
    m_end(mov.m_end)
{}

inline Operator& Operator::operator=(const Operator& cpy)
{
    m_add = cpy.m_add;
    m_sub = cpy.m_sub;
    m_begin = cpy.m_begin;
    m_end = cpy.m_end;
    return *this;
}

inline Operator& Operator::operator=(Operator&& mov)
{
    m_add = mov.m_add;
    m_sub = mov.m_sub;
    m_begin = mov.m_begin;
    m_end = mov.m_end;
    return *this;
}

inline std::size_t Operator::Addition(const std::size_t& i, 
    const std::size_t& a) const
{
    return m_add(i, a);
}

inline std::size_t Operator::Subtraction(const std::size_t& i, 
    const std::size_t& s) const
{
    return m_sub(i, s);
}

inline std::size_t Operator::Begin(const std::size_t& off, 
    const std::size_t& size) const
{
    return m_begin(off, size);
}

inline std::size_t Operator::End(const std::size_t& off, 
    const std::size_t& size) const
{
    return m_end(off, size);
}

inline bool Operator::operator==(const Operator& other) const
{
    return m_add == other.m_add &&
        m_sub == other.m_sub &&
        m_begin == other.m_begin &&
        m_end == other.m_end;
}

inline bool Operator::operator!=(const Operator& other) const
{
    return m_add != other.m_add ||
        m_sub != other.m_sub ||
        m_begin != other.m_begin ||
        m_end != other.m_end;
}

} //!it

} //!byte

} //!test

#endif //!TEST_BYTE_IT_OPERATOR_H_
