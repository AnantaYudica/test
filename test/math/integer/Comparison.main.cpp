#include "test/math/integer/Comparison.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

#include "Format.test.h"

int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0, 0};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0, 0};
        Format<N2, Bin> f2{0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1, 0};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 1};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1, 1};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1, 0, 0};
        Format<N2, Bin> f2{0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 1, 0};
        Format<N2, Bin> f2{0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0, 1};
        Format<N2, Bin> f2{0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1, 0, 0};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 1, 0};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 0, 1};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1, 0, 0};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 1, 0};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0, 1};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1, 0};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 1};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1, 1};
        Format<N2, Bin> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{0, 0, 0};
        Format<N2, Bin> f2{1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0};
        Format<N2, Bin> f2{1, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{1, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0};
        Format<N2, Bin> f2{0, 0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0, 0};
        Format<N2, Bin> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0, 0};
        Format<N2, Bin> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0, 0};
        Format<N2, Bin> f2{0, 0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format<N1, Bin> f1{1, 0};
        Format<N2, Bin> f2{1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1};
        Format<N2, Bin> f2{1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{1, 0};
        Format<N2, Bin> f2{1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format<N1, Bin> f1{0, 1};
        Format<N2, Bin> f2{0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1, 0};
        Format<N2, Bin> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 1};
        Format<N2, Bin> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{1, 0, 0};
        Format<N2, Bin> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 1, 0};
        Format<N2, Bin> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format<N1, Bin> f1{0, 0, 1};
        Format<N2, Bin> f2{0, 0, 1};
        int c1 = test::math::integer::Comparison(f1, f2);
        assert(c1 == 0);
    }
    return 0;
}