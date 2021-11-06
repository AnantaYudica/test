#ifndef TEST_BYTE_ORDER_OP_LITTLEENDIAN_H_
#define TEST_BYTE_ORDER_OP_LITTLEENDIAN_H_

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
    return i + a;
}

inline std::size_t LittleEndian::_Subtraction(const std::size_t& i, 
    const std::size_t& s)
{
    return i - s;
}

inline std::size_t LittleEndian::_Begin(const std::size_t& off, 
    const std::size_t&, const std::size_t&)
{
    return off;
}

inline std::size_t LittleEndian::_End(const std::size_t&, 
    const std::size_t& size, const std::size_t&)
{
    return size; 
}

inline LittleEndian::LittleEndian() :
    test::byte::it::Operator(_Addition, _Subtraction, _Begin, _End)
{}

} //!op

} //!order

} //!byte

} //!test

#endif //!TEST_BYTE_ORDER_OP_LITTLEENDIAN_H_
