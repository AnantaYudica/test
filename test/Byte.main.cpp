#include "test/Byte.h"
#include "test/byte/Order.h"
#include "test/byte/off/Make.h"
#include "test/byte/order/BigEndian.h"
#include "test/byte/order/LittleEndian.h"

#include <cassert>

template<typename T>
union Obj1
{
    T val;
    test::Byte<sizeof(T)> byte;
}; 

int main()
{
    {
        test::Byte<1> b1;

        assert(b1.Size() == 1);
        assert(b1.CastTo<std::uint8_t>() == 0);

        {
            std::size_t i = 0;
            for (auto it = b1.Begin(); it != b1.End(); ++it)
            {
                assert(*it == 0);
                ++i;
            }
            assert(i == 1);
        }

        {
            std::size_t i = 0;
            for (auto it = b1.ReverseBegin(); it != b1.ReverseEnd(); ++it)
            {
                assert(*it == 0);
                ++i;
            }
            assert(i == 1);
        }

        auto b2 = b1.GetBlock();
        
        assert(b2.Size() == 1);
        assert(b2.CastTo<std::uint8_t>() == 0);

    }
    {
        test::Byte<1> b1{0xF0};

        assert(b1.Size() == 1);
        assert(b1.CastTo<std::uint8_t>() == 0xF0);
        
        auto b2 = b1.GetBlock();
        
        assert(b2.Size() == 1);
        assert(b2.CastTo<std::uint8_t>() == 0xF0);
    }
    {
        std::uint8_t bin[1] = {0x0F};
        test::Byte<1> b1{test::byte::Order(bin)};

        assert(b1.Size() == 1);
        assert(b1.CastTo<std::uint8_t>() == 0x0F);

    }
    {
        test::Byte<1> b1{0x32};
        test::Byte<1> b2{b1.Begin(), b1.End()};

        assert(b1.Size() == 1);
        assert(b1.CastTo<std::uint8_t>() == 0x32);
        assert(b2.Size() == 1);
        assert(b2.CastTo<std::uint8_t>() == 0x32);

    }
    {
        test::Byte<1> b1{test::byte::Offset<std::uint8_t>{0, 0x02}};

        assert(b1.Size() == 1);
        assert(b1.CastTo<std::uint8_t>() == 0x02);

    }
    {
        test::Byte<1> b1{test::byte::off::Make(0, 0x12)};
        
        assert(b1.Size() == 1);
        assert(b1.CastTo<std::uint8_t>() == 0x12);
    }
    {
        test::Byte<2> b1;

        assert(b1.Size() == 2);
        assert(b1.CastTo<std::uint8_t>(0) == 0x0);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0);
        
        {
            std::size_t i = 0;
            for (auto it = b1.Begin(); it != b1.End(); ++it)
            {
                assert(*it == 0);
                ++i;
            }
            assert(i == 2);
        }

        {
            std::size_t i = 0;
            for (auto it = b1.ReverseBegin(); it != b1.ReverseEnd(); ++it)
            {
                assert(*it == 0);
                ++i;
            }
            assert(i == 2);
        }

    }
    {
        test::Byte<2> b1{0x0100};

        assert(b1.Size() == 2);
        assert(b1.CastTo<std::uint8_t>(0) == 0x0);
        assert(b1.CastTo<std::uint8_t>(1) == 0x01);

        {
            std::uint8_t res[]{0x0, 0x01};
            std::size_t i = 0;
            for (auto it = b1.Begin(); it != b1.End(); ++it)
            {
                assert(*it == res[i]);
                ++i;
            }
            assert(i == 2);
        }

        {
            std::uint8_t res[]{0x01, 0x0};
            std::size_t i = 0;
            for (auto it = b1.ReverseBegin(); it != b1.ReverseEnd(); ++it)
            {
                assert(*it == res[i]);
                ++i;
            }
            assert(i == 2);
        }

        auto b2 = b1.GetBlock();
        
        assert(b2.Size() == 2);
        assert(b2.CastTo<std::uint8_t>(0) == 0x0);
        assert(b2.CastTo<std::uint8_t>(1) == 0x01);

        auto b3 = b1.GetBlock<1>(0);

        assert(b3.Size() == 1);
        assert(b3.CastTo<std::uint8_t>(0) == 0x0);

        auto b4 = b1.GetBlock<1>(1);

        assert(b4.Size() == 1);
        assert(b4.CastTo<std::uint8_t>(0) == 0x01);
    }
    
    {
        std::uint8_t bin[] {0xFF, 0x00};
        test::Byte<2> b1{bin};

        assert(b1.Size() == 2);
        assert(b1.CastTo<std::uint8_t>(0) == 0x0);
        assert(b1.CastTo<std::uint8_t>(1) == 0xFF);

    }
    {
        std::uint8_t bin[] {0x00, 0xFF, 0x00, 0xF8};

        assert(test::byte::Order::GetDefaultEndian() == 
            test::byte::Order::big_endian);
        test::Byte<2> b1{test::byte::Order(bin + 2, 2)};

        assert(b1.Size() == 2);
        assert(b1.CastTo<std::uint8_t>(0) == 0xF8);
        assert(b1.CastTo<std::uint8_t>(1) == 0);

    }
    {
        test::Byte<5> b1{test::byte::order::BigEndian(0x00, 0x02, 0x04, 0x06, 0x07)};
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x07);
        assert(b1.CastTo<std::uint8_t>(1) == 0x06);
        assert(b1.CastTo<std::uint8_t>(2) == 0x04);
        assert(b1.CastTo<std::uint8_t>(3) == 0x02);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        assert(b1.CastTo<std::uint16_t>(0) == 0x0607);
        assert(b1.CastTo<std::uint16_t>(1) == 0x0406);
        assert(b1.CastTo<std::uint16_t>(2) == 0x0204);
        assert(b1.CastTo<std::uint16_t>(3) == 0x0002);
        assert(b1.CastTo<std::uint16_t>(4) == 0x0000);
    }
    {
        test::Byte<5> b1{test::byte::order::LittleEndian(0x00, 0x02, 0x04, 0x06, 0x07)};
        
        {
            std::size_t i = 0;
            std::uint8_t res[] {0x00, 0x02, 0x04, 0x06, 0x07};
            for (auto it = b1.Begin(); it != b1.End(); ++it)
            {
                assert(*it == res[i]);
                ++i;
            }
            assert(i == 5);
        }
        {
            std::size_t i = 0;
            std::uint8_t res[] {0x07, 0x06, 0x04, 0x02, 0x00};
            for (auto it = b1.ReverseBegin(); it != b1.ReverseEnd(); ++it)
            {
                assert(*it == res[i]);
                ++i;
            }
            assert(i == 5);
        }
    }
    {
        test::Byte<5> b1{test::byte::off::Make<std::uint8_t>(2, 0xFF)};
        
        assert(b1.CastTo<std::uint8_t>(0) == 0);
        assert(b1.CastTo<std::uint8_t>(1) == 0);
        assert(b1.CastTo<std::uint8_t>(2) == 0xFF);
        assert(b1.CastTo<std::uint8_t>(3) == 0);
        assert(b1.CastTo<std::uint8_t>(4) == 0);
    }
    {
        test::Byte<5> b1{test::byte::off::Make<std::uint8_t>(2, 0xFF)};
        
        assert(b1.CastTo<std::uint8_t>(0) == 0);
        assert(b1.CastTo<std::uint8_t>(1) == 0);
        assert(b1.CastTo<std::uint8_t>(2) == 0xFF);
        assert(b1.CastTo<std::uint8_t>(3) == 0);
        assert(b1.CastTo<std::uint8_t>(4) == 0);

        test::Byte<3> b2{b1};
        
        assert(b2.CastTo<std::uint8_t>(0) == 0);
        assert(b2.CastTo<std::uint8_t>(1) == 0);
        assert(b2.CastTo<std::uint8_t>(2) == 0xFF);
        
        test::Byte<5> b3{std::move(b2)};
        
        assert(b3.CastTo<std::uint8_t>(0) == 0);
        assert(b3.CastTo<std::uint8_t>(1) == 0);
        assert(b3.CastTo<std::uint8_t>(2) == 0xFF);
        assert(b3.CastTo<std::uint8_t>(3) == 0);
        assert(b3.CastTo<std::uint8_t>(4) == 0);

        assert(b2.CastTo<std::uint8_t>(0) == 0);
        assert(b2.CastTo<std::uint8_t>(1) == 0);
        assert(b2.CastTo<std::uint8_t>(2) == 0);
        
        test::Byte<5> b4{test::byte::off::Make(2, b1)};
        assert(b4.CastTo<std::uint8_t>(0) == 0);
        assert(b4.CastTo<std::uint8_t>(1) == 0);
        assert(b4.CastTo<std::uint8_t>(2) == 0);
        assert(b4.CastTo<std::uint8_t>(3) == 0);
        assert(b4.CastTo<std::uint8_t>(4) == 0xFF);

        auto b5 = b4.GetBlock<1>(4);
        assert(b5.Size() == 1);
        assert(b5.CastTo<std::uint8_t>() == 0xFF);
    }
    {
        test::Byte<5> b1;

        b1 = 0xFE00FF;
        assert(b1.CastTo<std::uint8_t>(0) == 0xFF);
        assert(b1.CastTo<std::uint8_t>(1) == 0);
        assert(b1.CastTo<std::uint8_t>(2) == 0xFE);
        assert(b1.CastTo<std::uint8_t>(3) == 0);
        assert(b1.CastTo<std::uint8_t>(4) == 0);

        b1 = test::byte::order::BigEndian(0x01, 0x0, 0xF1, 0x04);
        assert(b1.CastTo<std::uint8_t>(0) == 0x04);
        assert(b1.CastTo<std::uint8_t>(1) == 0xF1);
        assert(b1.CastTo<std::uint8_t>(2) == 0x0);
        assert(b1.CastTo<std::uint8_t>(3) == 0x01);
        assert(b1.CastTo<std::uint8_t>(4) == 0);

        b1 = test::byte::order::LittleEndian(0x01, 0x0, 0xF1, 0x04);
        assert(b1.CastTo<std::uint8_t>(0) == 0x01);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0);
        assert(b1.CastTo<std::uint8_t>(2) == 0xF1);
        assert(b1.CastTo<std::uint8_t>(3) == 0x04);
        assert(b1.CastTo<std::uint8_t>(4) == 0);

        b1 = test::byte::off::Make(4, 0xEE);
        assert(b1.CastTo<std::uint8_t>(0) == 0x01);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0);
        assert(b1.CastTo<std::uint8_t>(2) == 0xF1);
        assert(b1.CastTo<std::uint8_t>(3) == 0x04);
        assert(b1.CastTo<std::uint8_t>(4) == 0xEE);
    }
    {
        test::Byte<5> b1;

        test::Byte<3> b2{0x0ff00f};
        assert(b2.CastTo<std::uint8_t>(0) == 0x0f);
        assert(b2.CastTo<std::uint8_t>(1) == 0xf0);
        assert(b2.CastTo<std::uint8_t>(2) == 0x0f);

        b1 = b2;
        assert(b1.CastTo<std::uint8_t>(0) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(1) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(2) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
        
        test::Byte<3> b3{0x0fffff};
        assert(b3.CastTo<std::uint8_t>(0) == 0xff);
        assert(b3.CastTo<std::uint8_t>(1) == 0xff);
        assert(b3.CastTo<std::uint8_t>(2) == 0x0f);

        b1 = std::move(b3);
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
        
        assert(b3.CastTo<std::uint8_t>(0) == 0);
        assert(b3.CastTo<std::uint8_t>(1) == 0);
        assert(b3.CastTo<std::uint8_t>(2) == 0);
        
        b1 = test::byte::off::Make(3, b2);
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0xf0);
    }
    {
        test::Byte<5> b1{0x00ff00ffff};

        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 &= test::byte::off::Make(3, 0xff0f);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 &= (std::uint8_t)0xf0;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
        
        b1 &= test::byte::order::BigEndian(0x0f, 0xff);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        test::Byte<2> b2{0xff00};
        b1 &= b2;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 &= test::byte::off::Make(3, b2);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

    }
    {
        test::Byte<5> b1{0x000f00ffff};

        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 |= test::byte::off::Make(3, 0xff0f);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        b1 |= (std::uint8_t)0x0f;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);
        
        b1 |= test::byte::order::BigEndian(0x0f, 0xff, 0xf0);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        test::Byte<3> b2{0xff0000};
        b1 |= b2;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        b1 |= test::byte::off::Make(1, b2);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

    }
    
    {
        test::Byte<5> b1{0x000f00ffff};

        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 ^= test::byte::off::Make(3, 0xff0f);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        b1 ^= (std::uint8_t)0x0f;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);
        
        b1 ^= test::byte::order::BigEndian(0x0f, 0xff, 0xf0);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        test::Byte<3> b2{0xff0f0f};
        b1 ^= b2;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(1) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(2) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        b1 ^= test::byte::off::Make(1, b2);
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

    }
    {
        test::Byte<5> b1{0x000f00ffff};
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x0f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 <<= 8;

        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x0f);
        
        b1 <<= 2;

        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0xfc);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0x03);
        assert(b1.CastTo<std::uint8_t>(4) == 0x3c);
        
        b1 <<= 15;

        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0xfe);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        b1 <<= -22;

        assert(b1.CastTo<std::uint8_t>(0) == 0xf8);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x03);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
    }
    {
        test::Byte<5> b1{0xf0ff00ffff};
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0xf0);

        b1 >>= 8;

        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
        
        b1 >>= 2;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x3f);
        assert(b1.CastTo<std::uint8_t>(1) == 0xc0);
        assert(b1.CastTo<std::uint8_t>(2) == 0x3f);
        assert(b1.CastTo<std::uint8_t>(3) == 0x3c);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
        
        b1 >>= 15;

        assert(b1.CastTo<std::uint8_t>(0) == 0x7f);
        assert(b1.CastTo<std::uint8_t>(1) == 0x78);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);
        
        b1 >>= -22;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0xc0);
        assert(b1.CastTo<std::uint8_t>(3) == 0x1f);
        assert(b1.CastTo<std::uint8_t>(4) == 0x1e);
        
    }
    {
        test::Byte<5, true> b1{0xf0ff00ffff};
        
        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0xf0);

        b1 >>= 8;

        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0xf0);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);
        
        b1 >>= 2;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x3f);
        assert(b1.CastTo<std::uint8_t>(1) == 0xc0);
        assert(b1.CastTo<std::uint8_t>(2) == 0x3f);
        assert(b1.CastTo<std::uint8_t>(3) == 0xfc);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);
        
        b1 >>= 15;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x7f);
        assert(b1.CastTo<std::uint8_t>(1) == 0xf8);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);
        
        b1 >>= -22;
        
        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0xc0);
        assert(b1.CastTo<std::uint8_t>(3) == 0x1f);
        assert(b1.CastTo<std::uint8_t>(4) == 0xfe);
        
    }
    {
        test::Byte<5, true> b1;

        assert(b1.CastTo<std::uint8_t>(0) == 0x00);
        assert(b1.CastTo<std::uint8_t>(1) == 0x00);
        assert(b1.CastTo<std::uint8_t>(2) == 0x00);
        assert(b1.CastTo<std::uint8_t>(3) == 0x00);
        assert(b1.CastTo<std::uint8_t>(4) == 0x00);

        b1 = ~b1;

        assert(b1.CastTo<std::uint8_t>(0) == 0xff);
        assert(b1.CastTo<std::uint8_t>(1) == 0xff);
        assert(b1.CastTo<std::uint8_t>(2) == 0xff);
        assert(b1.CastTo<std::uint8_t>(3) == 0xff);
        assert(b1.CastTo<std::uint8_t>(4) == 0xff);

        test::Byte<5, true> b2{0xfe1fc00000};
        
        assert(b2.CastTo<std::uint8_t>(0) == 0x00);
        assert(b2.CastTo<std::uint8_t>(1) == 0x00);
        assert(b2.CastTo<std::uint8_t>(2) == 0xc0);
        assert(b2.CastTo<std::uint8_t>(3) == 0x1f);
        assert(b2.CastTo<std::uint8_t>(4) == 0xfe);

        b2 = ~b2;
        
        assert(b2[0] == 0xff);
        assert(b2[1] == 0xff);
        assert(b2[2] == 0x3f);
        assert(b2[3] == 0xe0);
        assert(b2[4] == 0x01);

    }
    {
        Obj1<int> obj1{.val=0x10c01104};
        {
            std::uint8_t res[]{0x04, 0x11, 0xc0, 0x10};
            std::size_t i = 0;
            for(auto it = obj1.byte.Begin(); it != obj1.byte.End(); ++it)
            {
                assert(*it == res[i]);
                ++i;
            }
            assert(i == 4);
        }
        
    }
    return 0;
}
