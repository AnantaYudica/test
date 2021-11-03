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

        assert(raw[0] == 0);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

        raw = test::Byte<1>(0xf8);

        test::integer::Raw<1> raw_1(raw);
        assert(raw_1[0] == 0xf8);
        assert(flag.Format() == raw_1.Flag().Format());

        test::integer::Raw<1> raw_2(std::move(raw_1));
        assert(raw_1[0] == 0);
        assert(raw_2[0] == 0xf8);
        assert(flag.Format() == raw_2.Flag().Format());

        raw_1 = raw_2;
        assert(raw_1[0] == 0xf8);
        assert(flag.Format() == raw_1.Flag().Format());

        raw_2 = std::move(raw_1);
        assert(raw_1[0] == 0);
        assert(raw_2[0] == 0xf8);
        assert(flag.Format() == raw_2.Flag().Format());
    }
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::integer::Raw<1> raw(test::integer::Flag::kBinaryFormat);
        const test::integer::Raw<1>& raw_c = raw;

        assert(raw[0] == 0);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());
        
        raw = test::Byte<1>(0x68);
        assert(raw[0] == 0x68);
    }
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::Byte<2> b0(0xfffe);
        test::integer::Raw<4> raw(flag, b0);
        const test::integer::Raw<4>& raw_c = raw;

        assert(raw[0] == 0xfe);
        assert(raw[1] == 0xff);
        assert(raw[2] == 0);
        assert(raw[3] == 0);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

        raw = test::Byte<4>(0x01020304);
        assert(raw[0] == 0x04);
        assert(raw[1] == 0x03);
        assert(raw[2] == 0x02);
        assert(raw[3] == 0x01);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

    }
    
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::integer::Raw<4> raw(flag, test::Byte<4>(0x12340506));
        const test::integer::Raw<4>& raw_c = raw;

        assert(raw[0] == 0x06);
        assert(raw[1] == 0x05);
        assert(raw[2] == 0x34);
        assert(raw[3] == 0x12);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());
        
        test::Byte<2> b0(0x2236);
        raw = b0;
        assert(raw[0] == 0x36);
        assert(raw[1] == 0x22);
        assert(raw[2] == 0x34);
        assert(raw[3] == 0x12);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

    }
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::Byte<2> b0(0xfffe);
        test::integer::Raw<4> raw(test::integer::Flag::kBinaryFormat, b0);
        const test::integer::Raw<4>& raw_c = raw;

        assert(raw[0] == 0xfe);
        assert(raw[1] == 0xff);
        assert(raw[2] == 0);
        assert(raw[3] == 0);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

        raw = test::Byte<4>(0x01020304);
        assert(raw[0] == 0x04);
        assert(raw[1] == 0x03);
        assert(raw[2] == 0x02);
        assert(raw[3] == 0x01);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

    }
    {
        test::integer::Flag flag(test::integer::Flag::kBinaryFormat);
        test::integer::Raw<4> raw(test::integer::Flag::kBinaryFormat, 
            test::Byte<4>(0x12340506));
        const test::integer::Raw<4>& raw_c = raw;

        assert(raw[0] == 0x06);
        assert(raw[1] == 0x05);
        assert(raw[2] == 0x34);
        assert(raw[3] == 0x12);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());
        
        test::Byte<2> b0(0x2236);
        raw = b0;
        assert(raw[0] == 0x36);
        assert(raw[1] == 0x22);
        assert(raw[2] == 0x34);
        assert(raw[3] == 0x12);
        assert(flag.Format() == raw.Flag().Format());
        assert(flag.Format() == raw_c.Flag().Format());

    }
    return 0;
}
