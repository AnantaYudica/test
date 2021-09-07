#include "test/math/integer/Logarithm.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

template<std::size_t N>
struct Format1
{
    std::uint8_t Value[N];
    constexpr Format1() :
        Value{0}
    {}
    template<typename TArg, typename ... TArgs,
        typename _TArg = typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<!std::is_base_of<Format1<N>, _TArg>::value, 
            int>::type = 1>
    constexpr Format1(const TArg& arg, const TArgs& ... args) :
            Value{static_cast<std::uint8_t>(arg), 
                static_cast<std::uint8_t>(args)...}
    {}
};

template<std::size_t N>
static std::uint16_t GetValueF1(const Format1<N>& val, 
    const std::size_t& index)
{
    return static_cast<std::uint16_t>(val.Value[index]);
}

static std::uint8_t LogF1Base2(const std::uint8_t& v)
{
    if (v & 0x80) return 7;
    else if (v & 0x40) return 6;
    else if (v & 0x20) return 5;
    else if (v & 0x10) return 4;
    else if (v & 0x8) return 3;
    else if (v & 0x4) return 2;
    else if (v & 0x2) return 1;
    return 0;
}

static std::uint8_t LogF1Base10(const std::uint8_t& v)
{
    return 0;
}


int main()
{
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 16);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 24);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 9);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 25);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 15);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 23);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 31);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 14);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 22);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{255, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 255, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 255, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 255};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{127, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 127, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 127, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 127};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base2, 8>(f1, v, &e, &a);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 0>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format1<N> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
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
        Format1<N> f1{0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::ZeroValue);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
        assert(c1 == LogFlagType::Ok);
        assert(v == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::log::Flag LogFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format1<N> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v);
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
        Format1<N> f1{0, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{1, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 1, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 1, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 1};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{2, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 2, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 2, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 2};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{3, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 3, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 3, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 3};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{9, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 9, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 9, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 9};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{6, 0, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 6, 0, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 6, 0};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
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
        Format1<N> f1{0, 0, 0, 6};
        LogFlagType c1 = test::math::integer::Logarithm<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            GetValueF1<N>, LogF1Base10, 1>(f1, v, &e, &a);
        assert(c1 == LogFlagType::Ok);
        assert(e == 0);
        assert(a == 3);
        assert(v == 3);
    }
    return 0;
}