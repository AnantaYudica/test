#include "test/math/integer/Subtraction.h"

#include <cstddef>
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
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        Format<N, Bin> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        Format<N, Bin> f2{1, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 0, 1, 0};
        Format<N, Bin> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{0, 0, 1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 0, 0, 1};
        Format<N, Bin> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{0, 0, 0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0, 0, 1, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0001;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(f1.m_value[4] == 255);
        assert(f1.m_value[5] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0xFF00;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 255);
        assert(f1.m_value[5] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{1, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 1, 0};
        Format<N, Dec> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 0, 1};
        Format<N, Dec> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 0, 1};
        Format<N, Dec> f2{0, 0, 1, 1};
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 0, 1, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0001;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 0, 0, 1, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x000A;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 0, 1, 0, 0, 0};
        std::uint16_t f2 = 0x000B;
        std::uint8_t c1 = test::math::integer::Subtraction(f1, f2, 0, 2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
        assert(c1 == 0);
    }

    return 0;
}
