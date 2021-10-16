#include "test/math/integer/Multiplication.h"

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
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        Format<N, Bin> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        Format<N, Bin> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        Format<N, Bin> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        Format<N, Bin> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        Format<N, Bin> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1, 1, 0};
        Format<N2, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1, 1};
        Format<N2, Bin> f2{1, 1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 0, 0};
        Format<N2, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 254);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{255, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{0, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 0, 0};
        Format<N2, Bin> f2{0, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        Format<N, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 0, 0};
        Format<N2, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{255, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{0, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 255, 0, 0};
        Format<N2, Bin> f2{0, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 255, 0, 0};
        Format<N2, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{255, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 0, };
        Format<N2, Bin> f2{255, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{0, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 0, 0};
        Format<N2, Bin> f2{0, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255, 255, 0, 0};
        Format<N2, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 255);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0x0000};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint16_t f2{0x0001};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint16_t f2{0x0001};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint16_t f2{0x0001};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0x0100};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint16_t f2{0x0100};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint16_t f2{0x0100};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint16_t f2{0x0100};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0x0101};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint16_t f2{0x0101};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint16_t f2{0x0101};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint16_t f2{0x0101};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0x00FF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0xFF00};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 0, 0, 0};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 255, 0, 0};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 0, 0};
        std::uint16_t f2{0xFFFF};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 254);
        assert(f1.m_value[3] == 255);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        Format<N, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0, 1, 0};
        Format<N2, Dec> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0, 1, 0};
        Format<N2, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        Format<N, Dec> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        Format<N, Dec> f2{1, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        Format<N, Dec> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{1, 1, 0};
        Format<N2, Dec> f2{0, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        Format<N, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{1, 1};
        Format<N2, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        Format<N, Dec> f2{0, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        Format<N, Dec> f2{9, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        Format<N, Dec> f2{0, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 0, 0};
        Format<N2, Dec> f2{0, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        Format<N, Dec> f2{9, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 0, 0};
        Format<N2, Dec> f2{9, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        Format<N, Dec> f2{9, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0, 9, 0};
        Format<N2, Dec> f2{9, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        Format<N, Dec> f2{0, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0, 9, 0, 0};
        Format<N2, Dec> f2{0, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        Format<N, Dec> f2{9, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 0};
        Format<N2, Dec> f2{9, 0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        Format<N, Dec> f2{0, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 0, 0};
        Format<N2, Dec> f2{0, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        Format<N, Dec> f2{9, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 5;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9, 9, 0, 0, 0};
        Format<N2, Dec> f2{9, 9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{10};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{11};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{00};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{1};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{10};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{11};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{00};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{01};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{10};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{0, 1, 0};
        std::uint16_t f2{10};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{11};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{0, 1, 0};
        std::uint16_t f2{11};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{0};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{01};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{10};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{10};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{11};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{11};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(f1.m_value[2] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint16_t f2{00};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint16_t f2{9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint16_t f2{90};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{9, 0, 0};
        std::uint16_t f2{90};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint16_t f2{99};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{9, 0, 0};
        std::uint16_t f2{99};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{00};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 9, 0, 0};
        std::uint16_t f2{9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{90};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{90};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{99};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{99};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint16_t f2{00};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint16_t f2{9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{9, 9, 0};
        std::uint16_t f2{9};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint16_t f2{90};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 0, 0};
        std::uint16_t f2{90};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint16_t f2{99};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 5;
        Format<N, Dec> f1{9, 9, 0, 0, 0};
        std::uint16_t f2{99};
        test::math::integer::Multiplication(f1, f2);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 8);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{0};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{1};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{255};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1, 1};
        Format<N2, Bin> f2{1};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1, 1};
        Format<N2, Bin> f2{255};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{255, 1};
        Format<N2, Bin> f2{255};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 253);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{255};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{0, 0};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{0, 0};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{1, 0};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{0, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1, 0};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{0, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255};
        Format<N2, Bin> f2{255, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 253);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{255};
        Format<N2, Bin> f2{255, 255};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{1, 1, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1, 1, 0};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{0, 1, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1, 0, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1, 1, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255};
        Format<N2, Bin> f2{1, 1, 1};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 255);
        assert(o1.m_value[0] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{255};
        Format<N2, Bin> f2{255, 255, 255};
        Format<N1, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        Format<N, Bin> f2{0, 0};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        Format<N, Bin> f2{0, 1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        Format<N, Bin> f2{1, 1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        Format<N, Bin> f2{0, 255};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        Format<N, Bin> f2{255, 255};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Bin> f1{1, 1};
        Format<N2, Bin> f2{1, 1, 1, 1};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(o1.m_value[0] == 2);
        assert(o1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{255, 0, 0, 255};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{255, 0, 255, 0};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(o1.m_value[0] == 255);
        assert(o1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{0, 255, 255, 0};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{0, 255, 0, 255};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 255);
        assert(o1.m_value[1] == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Bin> f1{255, 255};
        Format<N2, Bin> f2{255, 255, 255, 255};
        Format<N1, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 255);
        assert(o1.m_value[1] == 255);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{0};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{1};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{9};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{0, 0};
        Format<N2, Dec> f2{0};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{1, 1};
        Format<N2, Dec> f2{1};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{1, 1};
        Format<N2, Dec> f2{9};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{9, 1};
        Format<N2, Dec> f2{9};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 7);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{9};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0};
        Format<N2, Dec> f2{0, 0};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{0, 0};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0};
        Format<N2, Dec> f2{1, 0};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{0};
        Format<N2, Dec> f2{0, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{1, 0};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{0, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{1, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9};
        Format<N2, Dec> f2{9, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 7);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Dec> f1{9};
        Format<N2, Dec> f2{9, 9};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{0};
        Format<N2, Dec> f2{1, 1, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{1, 1, 0};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{0, 1, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{1, 0, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{1};
        Format<N2, Dec> f2{1, 1, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9};
        Format<N2, Dec> f2{1, 1, 1};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 9);
        assert(o1.m_value[0] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Dec> f1{9};
        Format<N2, Dec> f2{9, 9, 9};
        Format<N1, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        Format<N, Dec> f2{0, 0};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        Format<N, Dec> f2{0, 1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        Format<N, Dec> f2{1, 1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        Format<N, Dec> f2{0, 9};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        Format<N, Dec> f2{9, 9};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Dec> f1{1, 1};
        Format<N2, Dec> f2{1, 1, 1, 1};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(o1.m_value[0] == 2);
        assert(o1.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{9, 0, 0, 9};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{9, 0, 9, 0};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(o1.m_value[0] == 9);
        assert(o1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{0, 9, 9, 0};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{0, 9, 0, 9};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 9);
        assert(o1.m_value[1] == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 4;
        Format<N1, Dec> f1{9, 9};
        Format<N2, Dec> f2{9, 9, 9, 9};
        Format<N1, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 9);
        assert(o1.m_value[1] == 9);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint16_t f2{0};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{0};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint16_t f2{1};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint16_t f2{1};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint16_t f2{255};
        Format<N, Bin> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint16_t f2{0};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint16_t f2{0};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint16_t f2{1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint16_t f2{1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint16_t f2{1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint16_t f2{0x0101};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint16_t f2{0x0101};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint16_t f2{0x0101};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint16_t f2{0x0101};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint16_t f2{255};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        std::uint16_t f2{255};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 254);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        std::uint16_t f2{255};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint16_t f2{0xffff};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 255);
        assert(o1.m_value[1] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        std::uint16_t f2{0xffff};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        std::uint16_t f2{0xffff};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 255);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint16_t f2{0};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{0};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint16_t f2{1};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint16_t f2{1};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint16_t f2{9};
        Format<N, Dec> o1{0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(o1.m_value[0] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{0};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{0};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{0};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint16_t f2{0x0101};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint16_t f2{11};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint16_t f2{11};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint16_t f2{11};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 2);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{9};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint16_t f2{9};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 8);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint16_t f2{9};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint16_t f2{99};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(o1.m_value[0] == 9);
        assert(o1.m_value[1] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint16_t f2{99};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint16_t f2{99};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1, f2, &o1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 9);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 254);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{255, 255};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2{0, 0};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        Format<N, Bin> f2{1, 1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 2);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{1, 1};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 254);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2{255, 255};
        Format<N, Bin> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
        assert(o1.m_value[0] == 254);
        assert(o1.m_value[1] == 255);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        Format<N, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 8);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{9, 9};
        test::math::integer::Multiplication(f1_up, f1_lo, f2);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2{0, 0};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        Format<N, Dec> f2{1, 1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 2);
        assert(o1.m_value[0] == 1);
        assert(o1.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{1, 1};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 8);
        assert(o1.m_value[0] == 0);
        assert(o1.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2{9, 9};
        Format<N, Dec> o1{0, 0};
        test::math::integer::Multiplication(f1_up, f1_lo, f2, &o1);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
        assert(o1.m_value[0] == 8);
        assert(o1.m_value[1] == 9);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2_up{0, 0};
        Format<N, Bin> f2_lo{0, 0};
        Format<N, Bin> of_up{0, 0};
        Format<N, Bin> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 0);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        Format<N, Bin> f2_up{1, 1};
        Format<N, Bin> f2_lo{1, 1};
        Format<N, Bin> of_up{0, 0};
        Format<N, Bin> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 0);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        Format<N, Bin> f2_up{0, 0};
        Format<N, Bin> f2_lo{0, 0};
        Format<N, Bin> of_up{0, 0};
        Format<N, Bin> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 0);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        Format<N, Bin> f2_up{1, 1};
        Format<N, Bin> f2_lo{1, 1};
        Format<N, Bin> of_up{0, 0};
        Format<N, Bin> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 3);
        assert(f1_up.m_value[1] == 4);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 2);
        assert(of_up.m_value[0] == 1);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 3);
        assert(of_lo.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2_up{1, 1};
        Format<N, Bin> f2_lo{1, 1};
        Format<N, Bin> of_up{0, 0};
        Format<N, Bin> of_lo{0, 0};
        
        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);
            
        assert(f1_up.m_value[0] == 254);
        assert(f1_up.m_value[1] == 254);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 254);
        assert(of_up.m_value[0] == 1);
        assert(of_up.m_value[1] == 1);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{255, 255};
        Format<N, Bin> f1_lo{255, 255};
        Format<N, Bin> f2_up{255, 255};
        Format<N, Bin> f2_lo{255, 255};
        Format<N, Bin> of_up{0, 0};
        Format<N, Bin> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 255);
        assert(of_up.m_value[1] == 255);
        assert(of_lo.m_value[0] == 254);
        assert(of_lo.m_value[1] == 255);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2_up{0, 0};
        Format<N, Dec> f2_lo{0, 0};
        Format<N, Dec> of_up{0, 0};
        Format<N, Dec> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 0);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        Format<N, Dec> f2_up{1, 1};
        Format<N, Dec> f2_lo{1, 1};
        Format<N, Dec> of_up{0, 0};
        Format<N, Dec> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 0);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        Format<N, Dec> f2_up{0, 0};
        Format<N, Dec> f2_lo{0, 0};
        Format<N, Dec> of_up{0, 0};
        Format<N, Dec> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 0);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        Format<N, Dec> f2_up{1, 1};
        Format<N, Dec> f2_lo{1, 1};
        Format<N, Dec> of_up{0, 0};
        Format<N, Dec> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 3);
        assert(f1_up.m_value[1] == 4);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 2);
        assert(of_up.m_value[0] == 1);
        assert(of_up.m_value[1] == 0);
        assert(of_lo.m_value[0] == 3);
        assert(of_lo.m_value[1] == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2_up{1, 1};
        Format<N, Dec> f2_lo{1, 1};
        Format<N, Dec> of_up{0, 0};
        Format<N, Dec> of_lo{0, 0};
        
        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);
            
        assert(f1_up.m_value[0] == 8);
        assert(f1_up.m_value[1] == 8);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 8);
        assert(of_up.m_value[0] == 1);
        assert(of_up.m_value[1] == 1);
        assert(of_lo.m_value[0] == 0);
        assert(of_lo.m_value[1] == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{9, 9};
        Format<N, Dec> f1_lo{9, 9};
        Format<N, Dec> f2_up{9, 9};
        Format<N, Dec> f2_lo{9, 9};
        Format<N, Dec> of_up{0, 0};
        Format<N, Dec> of_lo{0, 0};

        test::math::integer::Multiplication(f1_up, f1_lo, f2_up, f2_lo, 
            &of_up, &of_lo);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
        assert(of_up.m_value[0] == 9);
        assert(of_up.m_value[1] == 9);
        assert(of_lo.m_value[0] == 8);
        assert(of_lo.m_value[1] == 9);
    }
    return 0;
}