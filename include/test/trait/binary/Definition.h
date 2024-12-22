
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

template<std::size_t NOff = 0, std::size_t N = 1>
struct Definition;

} //binary

} //!trait

} //!test

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS \
    test::sys::dbg::type::Value<std::size_t, NOff>,\
    test::sys::dbg::type::Value<std::size_t, N>

template<std::size_t NOff, std::size_t N>
TEST_SYS_DBG_TYPE_PARAMETER_DEFINE("test::trait::binary::Definition", 
    test::trait::binary::Definition<NOff, N>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace trait
{
namespace binary
{

template<std::size_t NOff, std::size_t N>
struct Definition
{
    typedef typename Definition<((NOff + (N - 1)) / 8) * 8, 1>::ValueType 
        ValueType;
    static constexpr std::size_t IsImplemented = 
        Definition<((NOff + (N - 1)) / 8) * 8, 1>::IsImplemented;
    static constexpr std::size_t BitFloorIndex = 
        Definition<((NOff + (N - 1)) / 8) * 8, 1>::BitFloorIndex;
    static constexpr std::size_t AllocationSize = 
        Definition<((NOff + (N - 1)) / 8) * 8, 1>::AllocationSize;
    static constexpr std::size_t BitSize = N;
    static constexpr std::size_t BitBeginIndex = NOff;
    static constexpr std::size_t BitEndIndex = NOff + N;
    static constexpr ValueType Mask = 
        ValueType(ValueType(~0x0) >> ((sizeof(ValueType) * 8) - N)) << NOff;
    static constexpr ValueType NegationMask = ValueType(~Mask);
    static constexpr std::size_t BitCarryIndex = 
        Definition<NOff + (N - 1)>::BitCarryIndex;
    static constexpr ValueType BitCarryMask = 
        Definition<NOff + (N - 1)>::BitCarryMask;
    Definition() = delete;
};


template<std::size_t NOff>
struct Definition<NOff, 0>
{
    static constexpr std::size_t IsImplemented = false;
    typedef void* ValueType;
    static constexpr std::size_t BitFloorIndex = 0;
    static constexpr std::size_t AllocationSize = 0;
    static constexpr std::size_t BitSize = 0;
    static constexpr std::size_t BitBeginIndex = 0;
    static constexpr std::size_t BitEndIndex = 0;
    static constexpr ValueType Mask = NULL;
    static constexpr ValueType NegationMask = NULL;
    static constexpr std::size_t BitCarryIndex = 0;
    static constexpr ValueType BitCarryMask = NULL;
    Definition() = delete;
};


template<std::size_t NOff>
struct Definition<NOff, 1>
{
    static constexpr std::size_t BitFloorIndex = 
        (((NOff / 8) & 0x80) == 0x80 ? 0x80 * 8 : 0) +
        (((NOff / 8) & 0xC0) == 0x40 ? 0x40 * 8 : 0) +
        (((NOff / 8) & 0xE0) == 0x20 ? 0x20 * 8 : 0) +
        (((NOff / 8) & 0xF0) == 0x10 ? 0x10 * 8 : 0) +
        (((NOff / 8) & 0xF8) == 0x08 ? 0x08 * 8 : 0) +
        (((NOff / 8) & 0xFC) == 0x04 ? 0x04 * 8 : 0) +
        (((NOff / 8) & 0xFE) == 0x02 ? 0x02 * 8 : 0) +
        (((NOff / 8) & 0xFF) == 0x01 ? 0x01 * 8 : 0);
    typedef typename Definition<BitFloorIndex, 1>::ValueType ValueType;
    static constexpr std::size_t IsImplemented =
         Definition<BitFloorIndex, 1>::IsImplemented;
    static constexpr std::size_t AllocationSize =
         Definition<BitFloorIndex, 1>::AllocationSize;
    static constexpr std::size_t BitSize = 1;
    static constexpr std::size_t BitBeginIndex = NOff;
    static constexpr std::size_t BitEndIndex = NOff + 1;
    static constexpr ValueType Mask = ValueType(0x01) << NOff;
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
    typedef void* ValueType;
    static constexpr std::size_t BitFloorIndex = 0;
    static constexpr std::size_t AllocationSize = 0;
    static constexpr std::size_t BitSize = 0;
    static constexpr std::size_t BitBeginIndex = 0;
    static constexpr std::size_t BitEndIndex = 0;
    static constexpr ValueType Mask = NULL;
    static constexpr ValueType NegationMask = NULL;
    static constexpr std::size_t BitCarryIndex = 0;
    static constexpr ValueType BitCarryMask = NULL;
    Definition() = delete;
};


} //!binary

} //!trait

} //!test

#endif //!TEST_TRAIT_BINARY_DEFINITION_H_
