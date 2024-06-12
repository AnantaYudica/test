
#ifndef TEST_TRAIT_BINARY_DEFINITION_H_
#define TEST_TRAIT_BINARY_DEFINITION_H_

#include "../../System.h"

#include <cstdlib>
#include <cstdint>
#include <type_traits>


namespace test
{
namespace trait
{
namespace binary
{

template<std::size_t N, std::size_t W = 1>
struct Definition;

} //binary

} //!trait

} //!test

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS \
    test::sys::dbg::type::Value<std::size_t, N>,\
    test::sys::dbg::type::Value<std::size_t, W>

template<std::size_t N, std::size_t W>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::trait::binary::Definition", 
    test::trait::binary::Definition<N, W>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace trait
{
namespace binary
{

template<std::size_t N, std::size_t W>
struct Definition
{
    typedef typename Definition<((N + (W - 1)) / 8) * 8, 1>::ValueType 
        ValueType;
    static constexpr std::size_t IsImplemented = 
        Definition<((N + (W - 1)) / 8) * 8, 1>::IsImplemented;
    static constexpr std::size_t BitFloorIndex = 
        Definition<((N + (W - 1)) / 8) * 8, 1>::BitFloorIndex;
    static constexpr std::size_t AllocationSize = 
        Definition<((N + (W - 1)) / 8) * 8, 1>::AllocationSize;
    static constexpr std::size_t BitSize = W;
    static constexpr std::size_t BitBeginIndex = N;
    static constexpr std::size_t BitEndIndex = N + W;
    static constexpr ValueType Mask = 
        ValueType(ValueType(~0x0) >> ((sizeof(ValueType) * 8) - W)) << N;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 
        Definition<N + (W - 1)>::BitCarryIndex;
    static constexpr ValueType BitCarryMask = 
        Definition<N + (W - 1)>::BitCarryMask;
    Definition() = delete;
};


template<std::size_t N>
struct Definition<N, 0>
{
    static constexpr std::size_t IsImplemented = false;
    Definition() = delete;
};


template<std::size_t N>
struct Definition<N, 1>
{
    static constexpr std::size_t BitFloorIndex = 
        (((N / 8) & 0x80) == 0x80 ? 0x80 * 8 : 0) +
        (((N / 8) & 0xC0) == 0x40 ? 0x40 * 8 : 0) +
        (((N / 8) & 0xE0) == 0x20 ? 0x20 * 8 : 0) +
        (((N / 8) & 0xF0) == 0x10 ? 0x10 * 8 : 0) +
        (((N / 8) & 0xF8) == 0x08 ? 0x08 * 8 : 0) +
        (((N / 8) & 0xFC) == 0x04 ? 0x04 * 8 : 0) +
        (((N / 8) & 0xFE) == 0x02 ? 0x02 * 8 : 0) +
        (((N / 8) & 0xFF) == 0x01 ? 0x01 * 8 : 0);
    typedef typename Definition<BitFloorIndex, 1>::ValueType ValueType;
    static constexpr std::size_t IsImplemented =
         Definition<BitFloorIndex, 1>::IsImplemented;
    static constexpr std::size_t AllocationSize =
         Definition<BitFloorIndex, 1>::AllocationSize;
    static constexpr std::size_t BitSize = 1;
    static constexpr std::size_t BitBeginIndex = N;
    static constexpr std::size_t BitEndIndex = N + 1;
    static constexpr ValueType Mask = ValueType(0x01) << N;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 
        BitEndIndex % (AllocationSize * 8); 
    static constexpr ValueType BitCarryMask = 
        BitCarryIndex == 0 ? 0x01 : ValueType(Mask << 1);
    Definition() = delete;
};

template<>
struct Definition<0, 1>
{
    static constexpr bool IsImplemented = true;
    typedef std::uint8_t ValueType;
    static constexpr std::size_t BitFloorIndex = 0;
    static constexpr std::size_t AllocationSize = 1;
    static constexpr std::size_t BitSize = 1;
    static constexpr std::size_t BitBeginIndex = 0;
    static constexpr std::size_t BitEndIndex = 1;
    static constexpr ValueType Mask = 0x01;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 1;
    static constexpr ValueType BitCarryMask = 0x02;
    Definition() = delete;

};

template<>
struct Definition<8, 1>
{
    static constexpr bool IsImplemented = true;
    typedef std::uint16_t ValueType;
    static constexpr std::size_t BitFloorIndex = 8;
    static constexpr std::size_t AllocationSize = 2;
    static constexpr std::size_t BitSize = 1;
    static constexpr std::size_t BitBeginIndex = 8;
    static constexpr std::size_t BitEndIndex = 9;
    static constexpr ValueType Mask = 0x0100;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 9;
    static constexpr ValueType BitCarryMask = 0x0200;
    Definition() = delete;
};

template<>
struct Definition<16, 1>
{
    static constexpr bool IsImplemented = true;
    typedef std::uint32_t ValueType;
    static constexpr std::size_t BitFloorIndex = 16;
    static constexpr std::size_t AllocationSize = 4;
    static constexpr std::size_t BitSize = 1;
    static constexpr std::size_t BitBeginIndex = 16;
    static constexpr std::size_t BitEndIndex = 17;
    static constexpr ValueType Mask = 0x010000;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 17;
    static constexpr ValueType BitCarryMask = 0x020000;
    Definition() = delete;
};

template<>
struct Definition<32, 1>
{
    static constexpr bool IsImplemented = true;
    typedef std::uint64_t ValueType;
    static constexpr std::size_t BitFloorIndex = 32;
    static constexpr std::size_t AllocationSize = 8;
    static constexpr std::size_t BitSize = 1;
    static constexpr std::size_t BitBeginIndex = 32;
    static constexpr std::size_t BitEndIndex = 33;
    static constexpr ValueType Mask = 0x0100000000;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 33;
    static constexpr ValueType BitCarryMask = 0x0200000000;
    Definition() = delete;
};

template<>
struct Definition<64, 1>
{
    static constexpr bool IsImplemented = false;
    Definition() = delete;
};


} //!binary

} //!trait

} //!test

#endif //!TEST_TRAIT_BINARY_DEFINITION_H_
