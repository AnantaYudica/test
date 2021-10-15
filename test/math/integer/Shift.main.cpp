#include "test/math/integer/Shift.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

#include "Format.test.h"

int main()
{
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 8);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 11);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 8);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 11);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 106);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 53);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 6);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 8);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 11);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 0x65);
        assert(f1.m_value[1] == 0x32);
        assert(f1.m_value[2] == 0xca);
        assert(f1.m_value[3] == 0x4d);
        assert(f1.m_value[4] == 0x29);
        assert(f1.m_value[5] == 0x75);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 0x32);
        assert(f1.m_value[1] == 0x19);
        assert(f1.m_value[2] == 0xe5);
        assert(f1.m_value[3] == 0xa6);
        assert(f1.m_value[4] == 0x94);
        assert(f1.m_value[5] == 0x3a);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 0x26);
        assert(f1.m_value[1] == 0xa3);
        assert(f1.m_value[2] == 0xdc);
        assert(f1.m_value[3] == 0x94);
        assert(f1.m_value[4] == 0x52);
        assert(f1.m_value[5] == 0x07);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 8);

        assert(f1.m_value[0] == 0x32);
        assert(f1.m_value[1] == 0xca);
        assert(f1.m_value[2] == 0x4d);
        assert(f1.m_value[3] == 0x29);
        assert(f1.m_value[4] == 0x75);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 11);

        assert(f1.m_value[0] == 0x46);
        assert(f1.m_value[1] == 0xb9);
        assert(f1.m_value[2] == 0x29);
        assert(f1.m_value[3] == 0xa5);
        assert(f1.m_value[4] == 0x0e);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 16);

        assert(f1.m_value[0] == 0xca);
        assert(f1.m_value[1] == 0x4d);
        assert(f1.m_value[2] == 0x29);
        assert(f1.m_value[3] == 0x75);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 36);

        assert(f1.m_value[0] == 0x52);
        assert(f1.m_value[1] == 0x07);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 52);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 0, 0xff);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0x80);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0xf0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Right>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 0, 0xff);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0x80);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0xf0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Right>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 0, 0xff);

        assert(f1.m_value[0] == 106);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0xb5);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0xf6);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Right>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 0, 0xff);

        assert(f1.m_value[0] == 0x65);
        assert(f1.m_value[1] == 0x32);
        assert(f1.m_value[2] == 0xca);
        assert(f1.m_value[3] == 0x4d);
        assert(f1.m_value[4] == 0x29);
        assert(f1.m_value[5] == 0x75);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0x32);
        assert(f1.m_value[1] == 0x19);
        assert(f1.m_value[2] == 0xe5);
        assert(f1.m_value[3] == 0xa6);
        assert(f1.m_value[4] == 0x94);
        assert(f1.m_value[5] == 0xba);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0x26);
        assert(f1.m_value[1] == 0xa3);
        assert(f1.m_value[2] == 0xdc);
        assert(f1.m_value[3] == 0x94);
        assert(f1.m_value[4] == 0x52);
        assert(f1.m_value[5] == 0xf7);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0x32);
        assert(f1.m_value[1] == 0xca);
        assert(f1.m_value[2] == 0x4d);
        assert(f1.m_value[3] == 0x29);
        assert(f1.m_value[4] == 0x75);
        assert(f1.m_value[5] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0x46);
        assert(f1.m_value[1] == 0xb9);
        assert(f1.m_value[2] == 0x29);
        assert(f1.m_value[3] == 0xa5);
        assert(f1.m_value[4] == 0xee);
        assert(f1.m_value[5] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 16, 0xff);

        assert(f1.m_value[0] == 0xca);
        assert(f1.m_value[1] == 0x4d);
        assert(f1.m_value[2] == 0x29);
        assert(f1.m_value[3] == 0x75);
        assert(f1.m_value[4] == 0xff);
        assert(f1.m_value[5] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 36, 0xff);

        assert(f1.m_value[0] == 0x52);
        assert(f1.m_value[1] == 0xf7);
        assert(f1.m_value[2] == 0xff);
        assert(f1.m_value[3] == 0xff);
        assert(f1.m_value[4] == 0xff);
        assert(f1.m_value[5] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Right>(f1, 52, 0xff);

        assert(f1.m_value[0] == 0xff);
        assert(f1.m_value[1] == 0xff);
        assert(f1.m_value[2] == 0xff);
        assert(f1.m_value[3] == 0xff);
        assert(f1.m_value[4] == 0xff);
        assert(f1.m_value[5] == 0xff);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 4);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 0);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 7);
        assert(f1.m_value[4] == 8);
        assert(f1.m_value[5] == 3);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 1);

        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 7);
        assert(f1.m_value[3] == 8);
        assert(f1.m_value[4] == 3);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 4);

        assert(f1.m_value[0] == 8);
        assert(f1.m_value[1] == 3);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 8);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Right>(f1, 0, 9);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Right>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Right>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Right>(f1, 0, 9);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Right>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Right>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Right>(f1, 0, 9);

        assert(f1.m_value[0] == 4);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Right>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Right>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 0, 9);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 7);
        assert(f1.m_value[4] == 8);
        assert(f1.m_value[5] == 3);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 1, 9);

        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 7);
        assert(f1.m_value[3] == 8);
        assert(f1.m_value[4] == 3);
        assert(f1.m_value[5] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 4, 9);

        assert(f1.m_value[0] == 8);
        assert(f1.m_value[1] == 3);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Right>(f1, 8, 9);

        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 8);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 11);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 16);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 8);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 11);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 106);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 212);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 160);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 8);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 11);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 0x65);
        assert(f1.m_value[1] == 0x32);
        assert(f1.m_value[2] == 0xca);
        assert(f1.m_value[3] == 0x4d);
        assert(f1.m_value[4] == 0x29);
        assert(f1.m_value[5] == 0x75);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 0xca);
        assert(f1.m_value[1] == 0x64);
        assert(f1.m_value[2] == 0x94);
        assert(f1.m_value[3] == 0x9b);
        assert(f1.m_value[4] == 0x52);
        assert(f1.m_value[5] == 0xea);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 0x50);
        assert(f1.m_value[1] == 0x26);
        assert(f1.m_value[2] == 0xa3);
        assert(f1.m_value[3] == 0xdc);
        assert(f1.m_value[4] == 0x94);
        assert(f1.m_value[5] == 0x52);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 8);

        assert(f1.m_value[0] == 0x00);
        assert(f1.m_value[1] == 0x65);
        assert(f1.m_value[2] == 0x32);
        assert(f1.m_value[3] == 0xca);
        assert(f1.m_value[4] == 0x4d);
        assert(f1.m_value[5] == 0x29);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 11);

        assert(f1.m_value[0] == 0x00);
        assert(f1.m_value[1] == 0x28);
        assert(f1.m_value[2] == 0x93);
        assert(f1.m_value[3] == 0x51);
        assert(f1.m_value[4] == 0x6e);
        assert(f1.m_value[5] == 0x4a);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 16);

        assert(f1.m_value[0] == 0x00);
        assert(f1.m_value[1] == 0x00);
        assert(f1.m_value[2] == 0x65);
        assert(f1.m_value[3] == 0x32);
        assert(f1.m_value[4] == 0xca);
        assert(f1.m_value[5] == 0x4d);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 36);

        assert(f1.m_value[0] == 0x00);
        assert(f1.m_value[1] == 0x00);
        assert(f1.m_value[2] == 0x00);
        assert(f1.m_value[3] == 0x00);
        assert(f1.m_value[4] == 0x50);
        assert(f1.m_value[5] == 0x26);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 52);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 0, 0xff);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0x01);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0x0f);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{0};
        
        test::math::integer::Shift<Left>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 0, 0xff);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0x03);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0x1f);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{1};
        
        test::math::integer::Shift<Left>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 0, 0xff);

        assert(f1.m_value[0] == 106);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0xd5);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0xaf);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1{106};
        
        test::math::integer::Shift<Left>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 0, 0xff);

        assert(f1.m_value[0] == 0x65);
        assert(f1.m_value[1] == 0x32);
        assert(f1.m_value[2] == 0xca);
        assert(f1.m_value[3] == 0x4d);
        assert(f1.m_value[4] == 0x29);
        assert(f1.m_value[5] == 0x75);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 1, 0xff);

        assert(f1.m_value[0] == 0xcb);
        assert(f1.m_value[1] == 0x64);
        assert(f1.m_value[2] == 0x94);
        assert(f1.m_value[3] == 0x9b);
        assert(f1.m_value[4] == 0x52);
        assert(f1.m_value[5] == 0xea);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 4, 0xff);

        assert(f1.m_value[0] == 0x5f);
        assert(f1.m_value[1] == 0x26);
        assert(f1.m_value[2] == 0xa3);
        assert(f1.m_value[3] == 0xdc);
        assert(f1.m_value[4] == 0x94);
        assert(f1.m_value[5] == 0x52);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 8, 0xff);

        assert(f1.m_value[0] == 0xff);
        assert(f1.m_value[1] == 0x65);
        assert(f1.m_value[2] == 0x32);
        assert(f1.m_value[3] == 0xca);
        assert(f1.m_value[4] == 0x4d);
        assert(f1.m_value[5] == 0x29);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 11, 0xff);

        assert(f1.m_value[0] == 0xff);
        assert(f1.m_value[1] == 0x2f);
        assert(f1.m_value[2] == 0x93);
        assert(f1.m_value[3] == 0x51);
        assert(f1.m_value[4] == 0x6e);
        assert(f1.m_value[5] == 0x4a);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 16, 0xff);

        assert(f1.m_value[0] == 0xff);
        assert(f1.m_value[1] == 0xff);
        assert(f1.m_value[2] == 0x65);
        assert(f1.m_value[3] == 0x32);
        assert(f1.m_value[4] == 0xca);
        assert(f1.m_value[5] == 0x4d);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 36, 0xff);

        assert(f1.m_value[0] == 0xff);
        assert(f1.m_value[1] == 0xff);
        assert(f1.m_value[2] == 0xff);
        assert(f1.m_value[3] == 0xff);
        assert(f1.m_value[4] == 0x5f);
        assert(f1.m_value[5] == 0x26);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Bin> f1{0x65, 0x32, 0xca, 0x4d, 0x29, 0x75};
        
        test::math::integer::Shift<Left>(f1, 52, 0xff);

        assert(f1.m_value[0] == 0xff);
        assert(f1.m_value[1] == 0xff);
        assert(f1.m_value[2] == 0xff);
        assert(f1.m_value[3] == 0xff);
        assert(f1.m_value[4] == 0xff);
        assert(f1.m_value[5] == 0xff);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 4);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 0);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 7);
        assert(f1.m_value[4] == 8);
        assert(f1.m_value[5] == 3);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 1);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 7);
        assert(f1.m_value[5] == 8);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 4);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 4);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 8);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Left>(f1, 0, 9);

        assert(f1.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Left>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{0};
        
        test::math::integer::Shift<Left>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Left>(f1, 0, 9);

        assert(f1.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Left>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{1};
        
        test::math::integer::Shift<Left>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Left>(f1, 0, 9);

        assert(f1.m_value[0] == 4);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Left>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1{4};
        
        test::math::integer::Shift<Left>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 0, 9);

        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 7);
        assert(f1.m_value[4] == 8);
        assert(f1.m_value[5] == 3);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 1, 9);

        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 7);
        assert(f1.m_value[5] == 8);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 4, 9);

        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 4);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format<N, Dec> f1{0, 4, 9, 7, 8, 3};
        
        test::math::integer::Shift<Left>(f1, 8, 9);

        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 1);

        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 8);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 9);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 16);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 17);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0, 0xff);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0, 0xff);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 1, 0xff);

        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 128);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 8, 0xff);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 9, 0xff);

        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 16, 0xff);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 17, 0xff);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 255);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 1);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 2);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 3);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 4);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0, 9);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 0, 9);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 1, 9);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 2, 9);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 3, 9);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_up, f1_lo, 4, 9);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1);

        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 2);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 8);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 9);

        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 16);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 17);

        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 25);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0, 0xff);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1, 0xff);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0, 0xff);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1, 0xff);

        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 3);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 8, 0xff);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 9, 0xff);

        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 3);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 16, 0xff);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 17, 0xff);

        assert(f1_up.m_value[0] == 3);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 25, 0xff);

        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 3);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 2);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 3);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 4);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0, 9);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1, 9);

        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 0, 9);

        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 1, 9);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 2, 9);

        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 3, 9);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_up, f1_lo, 4, 9);

        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_of{0};
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{0, 0};
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 1);

        assert(f1_of.m_value[0] == 128);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 128);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 8);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 9);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 128);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 16);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 17);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_of{0};
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0, 0xff);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{0, 0};
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0, 0xff);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 1, 0xff);

        assert(f1_of.m_value[0] == 128);
        assert(f1_of.m_value[1] == 128);
        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 128);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 8, 0xff);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 255);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 9, 0xff);

        assert(f1_of.m_value[0] == 128);
        assert(f1_of.m_value[1] == 255);
        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 128);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 16, 0xff);

        assert(f1_of.m_value[0] == 255);
        assert(f1_of.m_value[1] == 255);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 17, 0xff);

        assert(f1_of.m_value[0] == 255);
        assert(f1_of.m_value[1] == 255);
        assert(f1_up.m_value[0] == 128);
        assert(f1_up.m_value[1] == 128);
        assert(f1_lo.m_value[0] == 128);
        assert(f1_lo.m_value[1] == 128);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_of{0};
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{0, 0};
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 1);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 2);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 3);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 4);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_of{0};
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0, 9);
        
        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{0, 0};
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 0, 9);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 1, 9);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 9);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 2, 9);

        assert(f1_of.m_value[0] == 9);
        assert(f1_of.m_value[1] == 9);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 3, 9);

        assert(f1_of.m_value[0] == 9);
        assert(f1_of.m_value[1] == 9);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Right>(f1_of, f1_up, f1_lo, 4, 9);
        
        assert(f1_of.m_value[0] == 9);
        assert(f1_of.m_value[1] == 9);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 1);
        assert(f1_lo.m_value[1] == 1);
    }
    ////
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_of{0};
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0);
        
        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_of{0};
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{0, 0};
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 2);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 8);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 9);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 16);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 17);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 25);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_of{0};
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0, 0xff);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Bin> f1_of{0};
        Format<N, Bin> f1_up{0};
        Format<N, Bin> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1, 0xff);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{0, 0};
        Format<N, Bin> f1_up{0, 0};
        Format<N, Bin> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0, 0xff);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1, 0xff);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 3);
        assert(f1_lo.m_value[1] == 2);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 8, 0xff);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 9, 0xff);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 2);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 3);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 16, 0xff);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 17, 0xff);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 3);
        assert(f1_up.m_value[1] == 2);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Bin> f1_of{1, 1};
        Format<N, Bin> f1_up{1, 1};
        Format<N, Bin> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 25, 0xff);

        assert(f1_of.m_value[0] == 2);
        assert(f1_of.m_value[1] == 2);
        assert(f1_up.m_value[0] == 255);
        assert(f1_up.m_value[1] == 3);
        assert(f1_lo.m_value[0] == 255);
        assert(f1_lo.m_value[1] == 255);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_of{0};
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_of{0};
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{0, 0};
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 2);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 3);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 4);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_of{0};
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0, 9);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format<N, Dec> f1_of{0};
        Format<N, Dec> f1_up{0};
        Format<N, Dec> f1_lo{0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1, 9);

        assert(f1_of.m_value[0] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_lo.m_value[0] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{0, 0};
        Format<N, Dec> f1_up{0, 0};
        Format<N, Dec> f1_lo{0, 0};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 0, 9);

        assert(f1_of.m_value[0] == 0);
        assert(f1_of.m_value[1] == 0);
        assert(f1_up.m_value[0] == 0);
        assert(f1_up.m_value[1] == 0);
        assert(f1_lo.m_value[0] == 0);
        assert(f1_lo.m_value[1] == 0);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 1, 9);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 1);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 2, 9);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 1);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 3, 9);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 1);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    {
        using namespace test::math::integer::shift;
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format<N, Dec> f1_of{1, 1};
        Format<N, Dec> f1_up{1, 1};
        Format<N, Dec> f1_lo{1, 1};
        
        test::math::integer::Shift<Left>(f1_of, f1_up, f1_lo, 4, 9);

        assert(f1_of.m_value[0] == 1);
        assert(f1_of.m_value[1] == 1);
        assert(f1_up.m_value[0] == 9);
        assert(f1_up.m_value[1] == 9);
        assert(f1_lo.m_value[0] == 9);
        assert(f1_lo.m_value[1] == 9);
    }
    return 0;
}