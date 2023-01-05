#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_INTEGER_FMT_CAST_DLEVEL 0x7f

#include "test/integer/fmt/Cast.h"

#include <cstdint>
#include <cassert>
#include <type_traits>
#include <utility>
#include <limits>

int main()
{
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xff);
        assert(CastType::To<std::uint32_t>(b1) == 0xff);
        assert(CastType::To<std::uint64_t>(b1) == 0xff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == 0xff);
        assert(CastType::To<std::int32_t>(b1) == 0xff);
        assert(CastType::To<std::int64_t>(b1) == 0xff);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xff);
        assert(CastType::To<std::uint32_t>(b2) == 0xff);
        assert(CastType::To<std::uint64_t>(b2) == 0xff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == 0xff);
        assert(CastType::To<std::int32_t>(b2) == 0xff);
        assert(CastType::To<std::int64_t>(b2) == 0xff);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xff);
        assert(CastType::To<std::uint32_t>(b3) == 0xff);
        assert(CastType::To<std::uint64_t>(b3) == 0xff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == 0xff);
        assert(CastType::To<std::int32_t>(b3) == 0xff);
        assert(CastType::To<std::int64_t>(b3) == 0xff);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xff);
        assert(CastType::To<std::uint32_t>(b4) == 0xff);
        assert(CastType::To<std::uint64_t>(b4) == 0xff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == 0xff);
        assert(CastType::To<std::int32_t>(b4) == 0xff);
        assert(CastType::To<std::int64_t>(b4) == 0xff);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xff);
        assert(CastType::To<std::uint32_t>(b5) == 0xff);
        assert(CastType::To<std::uint64_t>(b5) == 0xff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == 0xff);
        assert(CastType::To<std::int32_t>(b5) == 0xff);
        assert(CastType::To<std::int64_t>(b5) == 0xff);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xff);
        assert(CastType::To<std::uint32_t>(b6) == 0xff);
        assert(CastType::To<std::uint64_t>(b6) == 0xff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == 0xff);
        assert(CastType::To<std::int32_t>(b6) == 0xff);
        assert(CastType::To<std::int64_t>(b6) == 0xff);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xff);
        assert(CastType::To<std::uint32_t>(b7) == 0xff);
        assert(CastType::To<std::uint64_t>(b7) == 0xff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == 0xff);
        assert(CastType::To<std::int32_t>(b7) == 0xff);
        assert(CastType::To<std::int64_t>(b7) == 0xff);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == 0xffff);
        assert(CastType::To<std::int64_t>(b2) == 0xffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == 0xffff);
        assert(CastType::To<std::int64_t>(b3) == 0xffff);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == 0xffff);
        assert(CastType::To<std::int64_t>(b4) == 0xffff);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == 0xffff);
        assert(CastType::To<std::int64_t>(b5) == 0xffff);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == 0xffff);
        assert(CastType::To<std::int64_t>(b6) == 0xffff);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == 0xffff);
        assert(CastType::To<std::int64_t>(b7) == 0xffff);

    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == 0xffffffff);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == 0xffffffff);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == 0xffffffff);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == 0xffffffff);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == 0xffffffff);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == 0xffff);
        assert(CastType::To<std::int64_t>(b2) == 0xffff);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == 0xffff);
        assert(CastType::To<std::int64_t>(b3) == 0xffff);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == 0xffff);
        assert(CastType::To<std::int64_t>(b4) == 0xffff);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == 0xffff);
        assert(CastType::To<std::int64_t>(b5) == 0xffff);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == 0xffff);
        assert(CastType::To<std::int64_t>(b6) == 0xffff);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == 0xffff);
        assert(CastType::To<std::int64_t>(b7) == 0xffff);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == 0xffffffff);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == 0xffffffff);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == 0xffffffff);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == 0xffffffff);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == 0xffffffff);

    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == 0xffffffff);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == 0xffffffff);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == 0xffffffff);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == 0xffffffff);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == 0xffffffff);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::uint64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::uint64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::uint64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xffff);
        assert(CastType::To<std::uint32_t>(b0) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b0) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == -1);
        assert(CastType::To<std::int32_t>(b0) == -1);
        assert(CastType::To<std::int64_t>(b0) == -1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == -1);
        assert(CastType::To<std::int64_t>(b1) == -1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == -1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int8_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int8_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0xff80);
        assert(CastType::To<std::uint32_t>(b0) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b0) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == -128);
        assert(CastType::To<std::int32_t>(b0) == -128);
        assert(CastType::To<std::int64_t>(b0) == -128);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == -1);
        assert(CastType::To<std::int64_t>(b1) == -1);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == -1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b1) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0xffff8000);
        assert(CastType::To<std::int64_t>(b1) == 0xffffffffffff8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == -1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int8_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int8_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == -1);
        assert(CastType::To<std::int64_t>(b1) == -1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == -1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int16_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int16_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b1) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0xffff8000);
        assert(CastType::To<std::int64_t>(b1) == 0xffffffffffff8000);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == -1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int16_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int16_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == -1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int32_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int32_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff80000000);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int32_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int32_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    ////
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        const std::size_t NNinSize = test::integer::fmt::
            Definition<std::int64_t, 2>::NMinSize;
        const std::size_t AllocSize = NNinSize * test::integer::fmt::
            Definition<std::int64_t, 2>::ElementAllocSize;

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 2;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 4;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);

    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 8;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0;
        std::uint16_t v_u16 = 0;
        std::uint32_t v_u32 = 0;
        std::uint64_t v_u64 = 0;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0);
        assert(CastType::To<std::uint16_t>(b0) == 0);
        assert(CastType::To<std::uint32_t>(b0) == 0);
        assert(CastType::To<std::uint64_t>(b0) == 0);
        assert(CastType::To<std::int8_t>(b0) == 0);
        assert(CastType::To<std::int16_t>(b0) == 0);
        assert(CastType::To<std::int32_t>(b0) == 0);
        assert(CastType::To<std::int64_t>(b0) == 0);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0);
        assert(CastType::To<std::uint32_t>(b1) == 0);
        assert(CastType::To<std::uint64_t>(b1) == 0);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == 0);
        assert(CastType::To<std::int32_t>(b1) == 0);
        assert(CastType::To<std::int64_t>(b1) == 0);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0);
        assert(CastType::To<std::uint64_t>(b2) == 0);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == 0);
        assert(CastType::To<std::int64_t>(b2) == 0);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0);

        std::int8_t v_i8 = 0;
        std::int16_t v_i16 = 0;
        std::int32_t v_i32 = 0;
        std::int64_t v_i64 = 0;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0);
        assert(CastType::To<std::uint16_t>(b4) == 0);
        assert(CastType::To<std::uint32_t>(b4) == 0);
        assert(CastType::To<std::uint64_t>(b4) == 0);
        assert(CastType::To<std::int8_t>(b4) == 0);
        assert(CastType::To<std::int16_t>(b4) == 0);
        assert(CastType::To<std::int32_t>(b4) == 0);
        assert(CastType::To<std::int64_t>(b4) == 0);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0);
        assert(CastType::To<std::uint32_t>(b5) == 0);
        assert(CastType::To<std::uint64_t>(b5) == 0);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == 0);
        assert(CastType::To<std::int32_t>(b5) == 0);
        assert(CastType::To<std::int64_t>(b5) == 0);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0);
        assert(CastType::To<std::uint64_t>(b6) == 0);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == 0);
        assert(CastType::To<std::int64_t>(b6) == 0);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0);
        assert(CastType::To<std::uint16_t>(b7) == 0);
        assert(CastType::To<std::uint32_t>(b7) == 0);
        assert(CastType::To<std::uint64_t>(b7) == 0);
        assert(CastType::To<std::int8_t>(b7) == 0);
        assert(CastType::To<std::int16_t>(b7) == 0);
        assert(CastType::To<std::int32_t>(b7) == 0);
        assert(CastType::To<std::int64_t>(b7) == 0);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 1;
        std::uint16_t v_u16 = 1;
        std::uint32_t v_u32 = 1;
        std::uint64_t v_u64 = 1;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 1);
        assert(CastType::To<std::uint16_t>(b0) == 1);
        assert(CastType::To<std::uint32_t>(b0) == 1);
        assert(CastType::To<std::uint64_t>(b0) == 1);
        assert(CastType::To<std::int8_t>(b0) == 1);
        assert(CastType::To<std::int16_t>(b0) == 1);
        assert(CastType::To<std::int32_t>(b0) == 1);
        assert(CastType::To<std::int64_t>(b0) == 1);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 1);
        assert(CastType::To<std::uint16_t>(b1) == 1);
        assert(CastType::To<std::uint32_t>(b1) == 1);
        assert(CastType::To<std::uint64_t>(b1) == 1);
        assert(CastType::To<std::int8_t>(b1) == 1);
        assert(CastType::To<std::int16_t>(b1) == 1);
        assert(CastType::To<std::int32_t>(b1) == 1);
        assert(CastType::To<std::int64_t>(b1) == 1);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 1);
        assert(CastType::To<std::uint16_t>(b2) == 1);
        assert(CastType::To<std::uint32_t>(b2) == 1);
        assert(CastType::To<std::uint64_t>(b2) == 1);
        assert(CastType::To<std::int8_t>(b2) == 1);
        assert(CastType::To<std::int16_t>(b2) == 1);
        assert(CastType::To<std::int32_t>(b2) == 1);
        assert(CastType::To<std::int64_t>(b2) == 1);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 1);
        assert(CastType::To<std::uint16_t>(b3) == 1);
        assert(CastType::To<std::uint32_t>(b3) == 1);
        assert(CastType::To<std::uint64_t>(b3) == 1);
        assert(CastType::To<std::int8_t>(b3) == 1);
        assert(CastType::To<std::int16_t>(b3) == 1);
        assert(CastType::To<std::int32_t>(b3) == 1);
        assert(CastType::To<std::int64_t>(b3) == 1);

        std::int8_t v_i8 = 1;
        std::int16_t v_i16 = 1;
        std::int32_t v_i32 = 1;
        std::int64_t v_i64 = 1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 1);
        assert(CastType::To<std::uint16_t>(b4) == 1);
        assert(CastType::To<std::uint32_t>(b4) == 1);
        assert(CastType::To<std::uint64_t>(b4) == 1);
        assert(CastType::To<std::int8_t>(b4) == 1);
        assert(CastType::To<std::int16_t>(b4) == 1);
        assert(CastType::To<std::int32_t>(b4) == 1);
        assert(CastType::To<std::int64_t>(b4) == 1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 1);
        assert(CastType::To<std::uint16_t>(b5) == 1);
        assert(CastType::To<std::uint32_t>(b5) == 1);
        assert(CastType::To<std::uint64_t>(b5) == 1);
        assert(CastType::To<std::int8_t>(b5) == 1);
        assert(CastType::To<std::int16_t>(b5) == 1);
        assert(CastType::To<std::int32_t>(b5) == 1);
        assert(CastType::To<std::int64_t>(b5) == 1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 1);
        assert(CastType::To<std::uint16_t>(b6) == 1);
        assert(CastType::To<std::uint32_t>(b6) == 1);
        assert(CastType::To<std::uint64_t>(b6) == 1);
        assert(CastType::To<std::int8_t>(b6) == 1);
        assert(CastType::To<std::int16_t>(b6) == 1);
        assert(CastType::To<std::int32_t>(b6) == 1);
        assert(CastType::To<std::int64_t>(b6) == 1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 1);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == 1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0xff;
        std::uint16_t v_u16 = 0xffff;
        std::uint32_t v_u32 = 0xffffffff;
        std::uint64_t v_u64 = 0xffffffffffffffff;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0xff);
        assert(CastType::To<std::uint16_t>(b0) == 0xff);
        assert(CastType::To<std::uint32_t>(b0) == 0xff);
        assert(CastType::To<std::uint64_t>(b0) == 0xff);
        assert(CastType::To<std::int8_t>(b0) == -1);
        assert(CastType::To<std::int16_t>(b0) == 0xff);
        assert(CastType::To<std::int32_t>(b0) == 0xff);
        assert(CastType::To<std::int64_t>(b0) == 0xff);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0xff);
        assert(CastType::To<std::uint16_t>(b1) == 0xffff);
        assert(CastType::To<std::uint32_t>(b1) == 0xffff);
        assert(CastType::To<std::uint64_t>(b1) == 0xffff);
        assert(CastType::To<std::int8_t>(b1) == -1);
        assert(CastType::To<std::int16_t>(b1) == -1);
        assert(CastType::To<std::int32_t>(b1) == 0xffff);
        assert(CastType::To<std::int64_t>(b1) == 0xffff);

        auto b2 = CastType::From<N>(v_u32);

        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0xff);
        assert(CastType::To<std::uint16_t>(b2) == 0xffff);
        assert(CastType::To<std::uint32_t>(b2) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b2) == 0xffffffff);
        assert(CastType::To<std::int8_t>(b2) == -1);
        assert(CastType::To<std::int16_t>(b2) == -1);
        assert(CastType::To<std::int32_t>(b2) == -1);
        assert(CastType::To<std::int64_t>(b2) == 0xffffffff);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0xff);
        assert(CastType::To<std::uint16_t>(b3) == 0xffff);
        assert(CastType::To<std::uint32_t>(b3) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b3) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b3) == -1);
        assert(CastType::To<std::int16_t>(b3) == -1);
        assert(CastType::To<std::int32_t>(b3) == -1);
        assert(CastType::To<std::int64_t>(b3) == -1);

        std::int8_t v_i8 = -1;
        std::int16_t v_i16 = -1;
        std::int32_t v_i32 = -1;
        std::int64_t v_i64 = -1;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0xff);
        assert(CastType::To<std::uint16_t>(b4) == 0xffff);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b4) == -1);
        assert(CastType::To<std::int16_t>(b4) == -1);
        assert(CastType::To<std::int32_t>(b4) == -1);
        assert(CastType::To<std::int64_t>(b4) == -1);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0xff);
        assert(CastType::To<std::uint16_t>(b5) == 0xffff);
        assert(CastType::To<std::uint32_t>(b5) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b5) == -1);
        assert(CastType::To<std::int16_t>(b5) == -1);
        assert(CastType::To<std::int32_t>(b5) == -1);
        assert(CastType::To<std::int64_t>(b5) == -1);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0xff);
        assert(CastType::To<std::uint16_t>(b6) == 0xffff);
        assert(CastType::To<std::uint32_t>(b6) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b6) == -1);
        assert(CastType::To<std::int16_t>(b6) == -1);
        assert(CastType::To<std::int32_t>(b6) == -1);
        assert(CastType::To<std::int64_t>(b6) == -1);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 0xff);
        assert(CastType::To<std::uint16_t>(b7) == 0xffff);
        assert(CastType::To<std::uint32_t>(b7) == 0xffffffff);
        assert(CastType::To<std::uint64_t>(b7) == 0xffffffffffffffff);
        assert(CastType::To<std::int8_t>(b7) == -1);
        assert(CastType::To<std::int16_t>(b7) == -1);
        assert(CastType::To<std::int32_t>(b7) == -1);
        assert(CastType::To<std::int64_t>(b7) == -1);
    }
    {
        typedef test::integer::fmt::Cast<std::int64_t, 2> CastType;
        constexpr std::size_t N = 15;
        const std::size_t AllocSize = test::integer::fmt::
            Definition<std::int64_t, 2>::AllocationSize(N);

        std::uint8_t v_u8 = 0x80;
        std::uint16_t v_u16 = 0x8000;
        std::uint32_t v_u32 = 0x80000000;
        std::uint64_t v_u64 = 0x8000000000000000;

        auto b0 = CastType::From<N>(v_u8);

        assert(b0.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b0) == 0x80);
        assert(CastType::To<std::uint16_t>(b0) == 0x80);
        assert(CastType::To<std::uint32_t>(b0) == 0x80);
        assert(CastType::To<std::uint64_t>(b0) == 0x80);
        assert(CastType::To<std::int8_t>(b0) == -128);
        assert(CastType::To<std::int16_t>(b0) == 0x80);
        assert(CastType::To<std::int32_t>(b0) == 0x80);
        assert(CastType::To<std::int64_t>(b0) == 0x80);

        auto b1 = CastType::From<N>(v_u16);
        
        assert(b1.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b1) == 0);
        assert(CastType::To<std::uint16_t>(b1) == 0x8000);
        assert(CastType::To<std::uint32_t>(b1) == 0x8000);
        assert(CastType::To<std::uint64_t>(b1) == 0x8000);
        assert(CastType::To<std::int8_t>(b1) == 0);
        assert(CastType::To<std::int16_t>(b1) == -32768);
        assert(CastType::To<std::int32_t>(b1) == 0x8000);
        assert(CastType::To<std::int64_t>(b1) == 0x8000);

        auto b2 = CastType::From<N>(v_u32);
        
        assert(b2.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b2) == 0);
        assert(CastType::To<std::uint16_t>(b2) == 0);
        assert(CastType::To<std::uint32_t>(b2) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b2) == 0x80000000);
        assert(CastType::To<std::int8_t>(b2) == 0);
        assert(CastType::To<std::int16_t>(b2) == 0);
        assert(CastType::To<std::int32_t>(b2) == -2147483648l);
        assert(CastType::To<std::int64_t>(b2) == 0x80000000);

        auto b3 = CastType::From<N>(v_u64);
        
        assert(b3.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b3) == 0);
        assert(CastType::To<std::uint16_t>(b3) == 0);
        assert(CastType::To<std::uint32_t>(b3) == 0);
        assert(CastType::To<std::uint64_t>(b3) == 0x8000000000000000);
        assert(CastType::To<std::int8_t>(b3) == 0);
        assert(CastType::To<std::int16_t>(b3) == 0);
        assert(CastType::To<std::int32_t>(b3) == 0);
        assert(CastType::To<std::int64_t>(b3) == 0x8000000000000000);

        std::int8_t v_i8 = -128;
        std::int16_t v_i16 = -32768;
        std::int32_t v_i32 = -2147483648l;
        std::int64_t v_i64 = -9223372036854775807ll;
        
        auto b4 = CastType::From<N>(v_i8);
        
        assert(b4.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b4) == 0x80);
        assert(CastType::To<std::uint16_t>(b4) == 0xff80);
        assert(CastType::To<std::uint32_t>(b4) == 0xffffff80);
        assert(CastType::To<std::uint64_t>(b4) == 0xffffffffffffff80);
        assert(CastType::To<std::int8_t>(b4) == -128);
        assert(CastType::To<std::int16_t>(b4) == -128);
        assert(CastType::To<std::int32_t>(b4) == -128);
        assert(CastType::To<std::int64_t>(b4) == -128);

        auto b5 = CastType::From<N>(v_i16);
        
        assert(b5.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b5) == 0);
        assert(CastType::To<std::uint16_t>(b5) == 0x8000);
        assert(CastType::To<std::uint32_t>(b5) == 0xffff8000);
        assert(CastType::To<std::uint64_t>(b5) == 0xffffffffffff8000);
        assert(CastType::To<std::int8_t>(b5) == 0);
        assert(CastType::To<std::int16_t>(b5) == -32768);
        assert(CastType::To<std::int32_t>(b5) == -32768);
        assert(CastType::To<std::int64_t>(b5) == -32768);

        auto b6 = CastType::From<N>(v_i32);

        assert(b6.Raw().Size() == AllocSize);

        assert(CastType::To<std::uint8_t>(b6) == 0);
        assert(CastType::To<std::uint16_t>(b6) == 0);
        assert(CastType::To<std::uint32_t>(b6) == 0x80000000);
        assert(CastType::To<std::uint64_t>(b6) == 0xffffffff80000000);
        assert(CastType::To<std::int8_t>(b6) == 0);
        assert(CastType::To<std::int16_t>(b6) == 0);
        assert(CastType::To<std::int32_t>(b6) == -2147483648l);
        assert(CastType::To<std::int64_t>(b6) == -2147483648l);

        auto b7 = CastType::From<N>(v_i64);

        assert(b7.Raw().Size() == AllocSize);
        
        assert(CastType::To<std::uint8_t>(b7) == 1);
        assert(CastType::To<std::uint16_t>(b7) == 1);
        assert(CastType::To<std::uint32_t>(b7) == 1);
        assert(CastType::To<std::uint64_t>(b7) == 0x8000000000000001);
        assert(CastType::To<std::int8_t>(b7) == 1);
        assert(CastType::To<std::int16_t>(b7) == 1);
        assert(CastType::To<std::int32_t>(b7) == 1);
        assert(CastType::To<std::int64_t>(b7) == -9223372036854775807ll);
    }
    return 0;
}

