#ifndef TEST_BYTE_ORDER_OP_BIGENDIAN_H_
#define TEST_BYTE_ORDER_OP_BIGENDIAN_H_

#include "../../../System.h"
#include "../../it/Operator.h"

namespace test::byte::order::op
{
class BigEndian;
}

#ifndef TEST_BYTE_ORDER_OP_BIGENDIAN_DLEVEL

#define TEST_BYTE_ORDER_OP_BIGENDIAN_DLEVEL 2

#endif //!TEST_BYTE_ORDER_OP_BIGENDIAN_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_BYTE_ORDER_OP_BIGENDIAN_DLEVEL, 
    "test::byte::order::op::BigEndian", test::byte::order::op::BigEndian);

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
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<test::byte::order::op::BigEndian> DebugType;
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
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Addition(i=%zu, a=%zu)", i, a);

    return i - a;
}

inline std::size_t BigEndian::_Subtraction(const std::size_t& i, 
    const std::size_t& s)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Subtraction(i=%zu, a=%zu)", i, s);
    
    return i + s;
}

inline std::size_t BigEndian::_Begin(const std::size_t& off, 
    const std::size_t& size, const std::size_t& tsize)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Begin(off=%zu, size=%zu, tsize=%zu)", off, size, tsize);
    
    return (off + size) - tsize;
}

inline std::size_t BigEndian::_End(const std::size_t& off, 
    const std::size_t& size, const std::size_t& tsize)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_End(off=%zu, size=%zu, tsize=%zu)", off, size, tsize);
    
    return (off == 0 ? size : off - tsize); 
}

inline BigEndian::BigEndian() :
    test::byte::it::Operator(_Addition, _Subtraction, _Begin, _End)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
    
}

} //!op

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_OP_BIGENDIAN_H_
