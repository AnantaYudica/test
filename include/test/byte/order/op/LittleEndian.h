#ifndef TEST_BYTE_ORDER_OP_LITTLEENDIAN_H_
#define TEST_BYTE_ORDER_OP_LITTLEENDIAN_H_

#include "../../../System.h"
#include "../../it/Operator.h"

namespace test::byte::order::op
{
class LittleEndian;
}

#ifndef TEST_BYTE_ORDER_OP_LITTLEENDIAN_DLEVEL

#define TEST_BYTE_ORDER_OP_LITTLEENDIAN_DLEVEL 2

#endif //!TEST_BYTE_ORDER_OP_LITTLEENDIAN_DLEVEL

TEST_SYS_DBG_TYPE_LEVEL_DEFINE(TEST_BYTE_ORDER_OP_LITTLEENDIAN_DLEVEL, 
    "test::byte::order::op::LittleEndian", test::byte::order::op::LittleEndian);


namespace test
{
namespace byte
{
namespace order
{
namespace op
{

class LittleEndian : public test::byte::it::Operator
{
private:
    typedef test::sys::Interface SystemType;
    typedef test::sys::dbg::Type<
        test::byte::order::op::LittleEndian> DebugType;
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
    inline LittleEndian();
public:
    virtual inline ~LittleEndian() = default;
public:
    inline LittleEndian(const LittleEndian& cpy) = delete;
    inline LittleEndian(LittleEndian&& mov) = delete;
public:
    inline LittleEndian& operator=(const LittleEndian& cpy) = delete;
    inline LittleEndian& operator=(LittleEndian&& mov) = delete;
};

inline std::size_t LittleEndian::_Addition(const std::size_t& i, 
    const std::size_t& a)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Addition(i=%zu, a=%zu)", i, a);

    return i + a;
}

inline std::size_t LittleEndian::_Subtraction(const std::size_t& i, 
    const std::size_t& s)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Subtraction(i=%zu, a=%zu)", i, s);
    
    return i - s;
}

inline std::size_t LittleEndian::_Begin(const std::size_t& off, 
    const std::size_t&, const std::size_t&)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_Begin(off=%zu, const std::size_t&, const std::size_t&)", off);
    
    return off;
}

inline std::size_t LittleEndian::_End(const std::size_t&, 
    const std::size_t& size, const std::size_t&)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 3, NULL, 
        "_End(const std::size_t&, size=%zu, const std::size_t&)", size);
    
    return size; 
}

inline LittleEndian::LittleEndian() :
    test::byte::it::Operator(_Addition, _Subtraction, _Begin, _End)
{
    TEST_SYS_DEBUG(SystemType, DebugType, 1, this, "Default Constructor");
    
}

} //!op

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_OP_LITTLEENDIAN_H_
