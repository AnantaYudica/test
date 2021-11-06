#ifndef TEST_BYTE_ORDER_OP_BIGENDIAN_H_
#define TEST_BYTE_ORDER_OP_BIGENDIAN_H_

#include "../../it/Operator.h"

namespace test
{
namespace byte
{
namespace order
{
namespace op
{

class BigEndian : public test::byte::it::Operator
{
private:  
    static inline std::size_t _Addition(const std::size_t& i, 
        const std::size_t& a);
    static inline std::size_t _Subtraction(const std::size_t& i, 
        const std::size_t& s);
    static inline std::size_t _Begin(const std::size_t& off, 
        const std::size_t& size, const std::size_t& tsize);
    static inline std::size_t _End(const std::size_t& off, 
        const std::size_t& size, const std::size_t& tsize);
public:
    inline BigEndian();
public:
    inline ~BigEndian() = default;
public:
    inline BigEndian(const BigEndian& cpy) = delete;
    inline BigEndian(BigEndian&& mov) = delete;
public:
    inline BigEndian& operator=(const BigEndian& cpy) = delete;
    inline BigEndian& operator=(BigEndian&& mov) = delete;
};

inline std::size_t BigEndian::_Addition(const std::size_t& i, 
    const std::size_t& a)
{
    return i - a;
}

inline std::size_t BigEndian::_Subtraction(const std::size_t& i, 
    const std::size_t& s)
{
    return i + s;
}

inline std::size_t BigEndian::_Begin(const std::size_t& off, 
    const std::size_t& size, const std::size_t& tsize)
{
    return (off + size) - tsize;
}

inline std::size_t BigEndian::_End(const std::size_t& off, 
    const std::size_t& size, const std::size_t& tsize)
{
    return (off == 0 ? size : off - tsize); 
}

inline BigEndian::BigEndian() :
    test::byte::it::Operator(_Addition, _Subtraction, _Begin, _End)
{}

} //!op

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_OP_BIGENDIAN_H_
