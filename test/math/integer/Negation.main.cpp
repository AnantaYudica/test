#include "test/math/integer/Negation.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

#include "Format.test.h"

int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{60};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{255};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 254);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{60, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 196);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 60};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{60, 60};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 196);
        assert(f1.m_value[1] == 195);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }

    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{60, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 60);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 60};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{60, 60};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 60);
        assert(f1.m_value[1] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1{255, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{0, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{1, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{0, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{1, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{60, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 60);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{0, 60, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 196);
        assert(f1.m_value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{60, 60, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 60);
        assert(f1.m_value[1] == 196);
        assert(f1.m_value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{255, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{0, 255, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Bin> f1{255, 255, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(c1 == 0);
    }

    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{1, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 1, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{1, 1, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{60, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 60);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 60, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 196);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{60, 60, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 60);
        assert(f1.m_value[1] == 196);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{0, 255, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Bin> f1{255, 255, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{5};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{9};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 8);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{5, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 5};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{5, 5};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 4);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(c1 == 0);
    }

    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{5, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 5};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{5, 5};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1{9, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 1);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{0, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{1, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{0, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{1, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{5, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{0, 5, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{5, 5, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{9, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{0, 9, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format<N, Dec> f1{9, 9, 0};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{1, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 1, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{1, 1, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{5, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 5, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{5, 5, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{0, 9, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format<N, Dec> f1{9, 9, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation(f1, 1, 1, 3);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 0;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1);
        assert(v1 == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 1;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1);
        assert(v1 == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 255;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1);
        assert(v1 == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 60;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1);
        assert(v1 == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 0;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        
        assert(v1 == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 1;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        assert(v1 == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 255;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        assert(v1 == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 60;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        assert(v1 == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 0;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 0, 1);
        assert(v1 == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 255;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 0, 1);
        assert(v1 == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 60;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 0, 1);
        assert(v1 == 195);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 0;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1);
        assert(v1 == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 1;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1);
        assert(v1 == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 9;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1);
        assert(v1 == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 5;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1);
        assert(v1 == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 0;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 1;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 9;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 5;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 0;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 0, 1);
        assert(v1 == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 9;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 0, 1);
        assert(v1 == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 5;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 0, 1);
        assert(v1 == 4);
        assert(c1 == 0);
    }
    return 0;
}
