#include "test/math/integer/Logarithm.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

#include "Format.test.h"

int main()
{
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 2);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 3);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 2);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 3);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 16);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 24);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 23);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 31);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 14);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 22);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 30);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 16);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 24);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 1);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 2);
        assert(v == 23);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 3);
        assert(v == 31);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 1);
        assert(v == 14);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 2);
        assert(v == 22);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 3);
        assert(v == 30);
    }
    ////
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 3);
    }
    ////
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{1};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{2};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{3};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{127};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{255};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{1};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{2};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{3};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{255};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{127};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 6);
    }

    //
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{127};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{1};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{2};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{3};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{255};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1_upper{127};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 14);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0};
        Format<N, Bin> f1_lower{127};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 6);
    }
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{1};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{2};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{3};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{255};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{127};
        Format<N, Bin> f1_lower{255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 14);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{1, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 1, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 1, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 1};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{2, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 2, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 2, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 2};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{3, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 3, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 3, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 3};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{255, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 255, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 255, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 255};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{127, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 127, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 127, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 127};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{1, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 1, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 1, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 1};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{2, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 2, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 2, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 2};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{3, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 3, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 3, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 3};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{255, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 255, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 255, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 255};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{127, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 127, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 127, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 127};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 6);
    }



    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 16);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 24);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 23);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 31);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 14);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 22);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 30);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{1, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 32);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 1, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 40);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 1, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 48);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 1};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 56);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{2, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 33);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 2, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 41);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 2, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 49);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 2};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 57);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{3, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 33);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 3, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 41);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 3, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 49);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 3};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 57);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{255, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 39);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 255, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 47);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 255, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 55);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 255};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 63);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{127, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 38);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 127, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 46);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 127, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 54);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 127};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 62);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 16);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 24);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 23);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 31);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 14);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 22);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 0};
        Format<N, Bin> f1_lower{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 30);
    }
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{1, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 32);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 1, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 40);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 1, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 48);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 1};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 56);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{2, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 33);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 2, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 41);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 2, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 49);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 2};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 57);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{3, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 33);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 3, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 41);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 3, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 49);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 3};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 1);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 57);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{255, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 39);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 255, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 47);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 255, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 55);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 255};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 7);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 63);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{127, 0, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 38);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 127, 0, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 46);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 127, 0};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 54);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Bin> f1_upper{0, 0, 0, 127};
        Format<N, Bin> f1_lower{255, 255, 255, 255};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 6);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 62);
    }
    ////
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{1};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{2};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{3};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{9};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{6};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{1};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{2};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{3};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{9};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{6};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{6};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{1};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{2};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{3};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{9};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1_upper{6};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0};
        Format<N, Dec> f1_lower{6};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{1};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{2};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{3};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{9};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{6};
        Format<N, Dec> f1_lower{9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper, 
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{1, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 1, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 1, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 1};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{2, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 2, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 2, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 2};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{3, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 3, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 3, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 3};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{9, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 9, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 9, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 9};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{6, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 6, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 6, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 6};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper, 
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }


    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 0);
    }
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{1, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 1, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 1, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 1};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{2, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 2, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 2, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 2};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{3, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 3, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 3, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 3};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{9, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 9, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 9, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 9};
        Format<N, Dec> f1_lower{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{6, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 6, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 6, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 6};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm<0>(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{1, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 1, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 1, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 1};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{2, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 2, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 2, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 2};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{3, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 3, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 3, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 3};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{9, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 9, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 9, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 9};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{6, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 6, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 6, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 6};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::ZeroValue);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 1);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 1);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 1);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 0};
        Format<N, Dec> f1_lower{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 1);
        assert(v == 3);
    }
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{1, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 1, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 1, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 1};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{2, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 2, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 2, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 2};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{3, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 3, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 3, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 3};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{9, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 9, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 9, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 9};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{6, 0, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 0);
        assert(v_a == 0);
        assert(v == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 6, 0, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 1);
        assert(v_a == 0);
        assert(v == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 6, 0};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 2);
        assert(v_a == 0);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        std::uint8_t e = 0;
        SizeType a = 0;
        SizeType v_a = 0;
        SizeType v;
        Format<N, Dec> f1_upper{0, 0, 0, 6};
        Format<N, Dec> f1_lower{9, 9, 9, 9};
        LogFlagType c1 = test::math::integer::Logarithm(f1_upper,
            f1_lower, v, &e, &a, &v_a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v_a == 0);
        assert(v == 7);
    }
    return 0;
}