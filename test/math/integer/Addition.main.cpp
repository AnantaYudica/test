#include "test/math/integer/Addition.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

#include "Format.test.h"

int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{255, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        Format<N, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        Format<N, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 254);
        assert(f1.m_value[1] == 255);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 255, 0};
        Format<N, Bin> f2{255, 255, 0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 0, 0};
        Format<N, Bin> f2{255, 255, 255, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 1, 0};
        Format<N, Bin> f2{255, 255, 255, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 255, 0};
        Format<N, Bin> f2{255, 255, 1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 1, 0};
        Format<N, Bin> f2{255, 255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{255, 255, 1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 255);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{255, 255, 1, 1, 1, 1};
        std::uint16_t f2{0x0000};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{255, 255, 0, 0, 0, 0};
        std::uint16_t f2{0x0201};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 2);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{255, 255, 1, 255, 0, 0};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{255, 255, 1, 255, 255, 0};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{255, 255, 1, 255, 255, 255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{9, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{9, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        Format<N, Dec> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        Format<N, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 8);
        assert(f1.m_value[1] == 9);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 9, 0};
        Format<N, Dec> f2{9, 9, 0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 0, 0};
        Format<N, Dec> f2{9, 9, 9, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 1, 0};
        Format<N, Dec> f2{9, 9, 9, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 9, 0};
        Format<N, Dec> f2{9, 9, 1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 0, 1};
        Format<N, Dec> f2{9, 9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 1, 0};
        Format<N, Dec> f2{9, 9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 9, 9};
        Format<N, Dec> f2{9, 9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 9);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 1, 0, 0, 0};
        std::uint16_t f2{0x0000};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 0, 0, 0, 0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 1, 0, 0, 0};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 0, 1, 0, 0};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 1, 0, 0, 0};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 1, 0, 9, 9};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{255, 0};
        Format<N2, Bin> f2{0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1, 0};
        Format<N2, Bin> f2{255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 1};
        Format<N2, Bin> f2{255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 254);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 255, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 0, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 1, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 255, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 1, 1};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 255, 255};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 255);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 255, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 0, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 1, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 255, 0};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 1, 1};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 255, 255};
        Format<N2, Bin> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 255, 0, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 0, 0, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(f1.m_value[4] == 255);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 1, 0, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 255, 1, 0, 255};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 1, 1, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 255, 255, 255, 255};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 255);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 255, 0, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 255);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 0, 0, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 255);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 1, 0, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 255);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 255, 255, 0, 255};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 1, 255, 255, 0};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255, 255, 255, 255, 255, 255};
        Format<N2, Bin> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{0, 0};
        Format<N2, Dec> f2{0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{9, 0};
        Format<N2, Dec> f2{0};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{0, 0};
        Format<N2, Dec> f2{9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{1, 1};
        Format<N2, Dec> f2{9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{9, 0};
        Format<N2, Dec> f2{1};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{1, 0};
        Format<N2, Dec> f2{9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{0, 1};
        Format<N2, Dec> f2{9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 8);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 9, 0};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 0, 0};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 1, 0};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 9, 0};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 0, 1};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 1, 0};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 9, 9};
        Format<N2, Dec> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 9);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 9, 0, 9, 0};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 0, 0, 9, 0};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 1, 0, 9, 0};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 9, 0, 9, 9};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 0, 1, 9, 9};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 1, 0, 9, 8};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 9, 0, 9, 0};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 0, 0, 9, 0};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 1, 0, 9, 0};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 9, 9, 0, 9};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 1);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 0, 1, 9, 9};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 1, 9, 9, 8};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N2, Dec> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 2, 1, 2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 254);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint16_t f2{0x0100};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{0x0100};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{0x01FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x0100};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x01FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 254);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0xFFFF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 254);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 1);
        assert(c1 == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 255);
        assert(c1 == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 1 , 2);
        assert(f1.m_value[0] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint16_t f2{0x0101};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint16_t f2{0xFFFF};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 254);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 8);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint16_t f2{0x000A};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{0x000A};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{0x0013};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x000A};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0013};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 8);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0063};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2);
        assert(f1.m_value[0] == 8);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 1);
        assert(c1 == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 1);
        assert(f1.m_value[0] == 9);
        assert(c1 == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0 , 2);
        assert(f1.m_value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 1 , 2);
        assert(f1.m_value[0] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{0x000B};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{0x0063};
        std::uint8_t c1 = test::math::integer::Addition(f1, f2, 0, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 8);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{1, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 1};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 0};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 1};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2, 1);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 0};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{254, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 254};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2);
            
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3);
            
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 4);
            
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 8);
            
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{254, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 254};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2);
            
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3);
            
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 4);
            
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 8);
            
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 1);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 1, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 1, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 1, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 1, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 1, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 1, 1);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 2, 2);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
        assert(c1 == 1);
    }////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{1, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 1};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 0};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 1};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2, 1);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 0};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Addition(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{8, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 8};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2);
            
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3);
            
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 4);
            
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 8);
            
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{8, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 8};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2);
            
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3);
            
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 4);
            
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 8);
            
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 1);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 1, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 1, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 1, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 1, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 2, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 0, 3, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 1, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 1, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 1, 1);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 1, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 2, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::
            Addition(f1_up, f1_lo, f2, 1, 3, 2, 2);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
        assert(c1 == 1);
    }
    return 0;
}
