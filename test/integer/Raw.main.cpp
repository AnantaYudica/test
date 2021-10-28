#include "test/integer/Raw.h"

#include <cstdint>
#include <cassert>
#include <type_traits>
#include <utility>

int main()
{
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::integer::Raw<1> raw(flag);
        const test::integer::Raw<1>& raw_c = raw;

        assert(raw.Get<std::uint8_t>(0) == 0);

        raw.Get<std::uint8_t>(0) = 255;

        assert(raw_c.Get<std::uint8_t>(0) == 255);

        auto old = raw.Set<std::uint8_t>(0, 127);

        assert(old == 255);
        assert(raw_c.Get<std::uint8_t>(0) == 127);

        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

        test::integer::Raw<1> raw_1(raw);
        assert(raw_1.Get<std::uint8_t>(0) == 127);

        test::integer::Raw<1> raw_2(std::move(raw_1));
        assert(raw_1.Get<std::uint8_t>(0) == 0);
        assert(raw_2.Get<std::uint8_t>(0) == 127);

        raw_1 = raw_2;
        assert(raw_1.Get<std::uint8_t>(0) == 127);

        raw_2 = std::move(raw_1);
        assert(raw_1.Get<std::uint8_t>(0) == 0);
        assert(raw_2.Get<std::uint8_t>(0) == 127);
    }
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::integer::Raw<4> raw(flag);
        const test::integer::Raw<4>& raw_c = raw;

        assert(raw.Get<std::uint8_t>(0) == 0);
        assert(raw.Get<std::uint8_t>(1) == 0);
        assert(raw.Get<std::uint8_t>(2) == 0);
        assert(raw.Get<std::uint8_t>(3) == 0);

        raw.Get<std::uint8_t>(0) = 1;
        raw.Get<std::uint8_t>(1) = 2;
        raw.Get<std::uint8_t>(2) = 3;
        raw.Get<std::uint8_t>(3) = 4;

        assert(raw_c.Get<std::uint8_t>(0) == 1);
        assert(raw_c.Get<std::uint8_t>(1) == 2);
        assert(raw_c.Get<std::uint8_t>(2) == 3);
        assert(raw_c.Get<std::uint8_t>(3) == 4);


        auto old_1 = raw.Set<std::uint8_t>(0, 5);
        auto old_2 = raw.Set<std::uint8_t>(1, 6);
        auto old_3 = raw.Set<std::uint8_t>(2, 7);
        auto old_4 = raw.Set<std::uint8_t>(3, 8);

        assert(old_1 == 1);
        assert(old_2 == 2);
        assert(old_3 == 3);
        assert(old_4 == 4);
        assert(raw_c.Get<std::uint8_t>(0) == 5);
        assert(raw_c.Get<std::uint8_t>(1) == 6);
        assert(raw_c.Get<std::uint8_t>(2) == 7);
        assert(raw_c.Get<std::uint8_t>(3) == 8);

        raw.Get<std::uint16_t>(0) = 0x00ff;
        raw.Get<std::uint16_t>(1) = 0xff00;

        
        assert(raw_c.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_c.Get<std::uint16_t>(1) == 0xff00);

        
        test::integer::Raw<8> raw_1(raw);
        assert(raw_1.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_1.Get<std::uint16_t>(1) == 0xff00);
        assert(raw_1.Get<std::uint16_t>(2) == 0);
        assert(raw_1.Get<std::uint16_t>(3) == 0);

        test::integer::Raw<4> raw_a(raw);
        test::integer::Raw<8> raw_2(std::move(raw_a));
        assert(raw_a.Get<std::uint16_t>(0) == 0);
        assert(raw_a.Get<std::uint16_t>(1) == 0);
        
        assert(raw_2.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_2.Get<std::uint16_t>(1) == 0xff00);
        assert(raw_2.Get<std::uint16_t>(2) == 0);
        assert(raw_2.Get<std::uint16_t>(3) == 0);

        raw_1 = raw;
        assert(raw_1.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_1.Get<std::uint16_t>(1) == 0xff00);
        assert(raw_1.Get<std::uint16_t>(2) == 0);
        assert(raw_1.Get<std::uint16_t>(3) == 0);

        raw_a = raw;
        assert(raw_a.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_a.Get<std::uint16_t>(1) == 0xff00);
        raw_2 = std::move(raw_a);
        assert(raw_a.Get<std::uint16_t>(0) == 0);
        assert(raw_a.Get<std::uint16_t>(1) == 0);
        
        assert(raw_2.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_2.Get<std::uint16_t>(1) == 0xff00);
        assert(raw_2.Get<std::uint16_t>(2) == 0);
        assert(raw_2.Get<std::uint16_t>(3) == 0);

        test::integer::Raw<2> raw_3(raw);
        assert(raw_3.Get<std::uint16_t>(0) == 0x00ff);

        raw_a = raw;
        assert(raw_a.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_a.Get<std::uint16_t>(1) == 0xff00);
        test::integer::Raw<2> raw_4(std::move(raw_a));
        assert(raw_a.Get<std::uint16_t>(0) == 0);
        assert(raw_a.Get<std::uint16_t>(1) == 0);

        assert(raw_4.Get<std::uint16_t>(0) == 0x00ff);

        raw_3 = raw;
        assert(raw_3.Get<std::uint16_t>(0) == 0x00ff);

        raw_a = raw;
        assert(raw_a.Get<std::uint16_t>(0) == 0x00ff);
        assert(raw_a.Get<std::uint16_t>(1) == 0xff00);
        raw_4 = std::move(raw_a);
        assert(raw_a.Get<std::uint16_t>(0) == 0);
        assert(raw_a.Get<std::uint16_t>(1) == 0);

        assert(raw_4.Get<std::uint16_t>(0) == 0x00ff);
        

    }
    return 0;
}
