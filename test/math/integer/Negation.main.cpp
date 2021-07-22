#include "test/math/integer/Negation.h"

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
static std::uint8_t SetValueF1(Format1<N>& val, 
    const std::size_t& index, const std::uint8_t& setval)
{
    return (val.Value[index] = setval);
}

template<std::size_t N>
static std::uint16_t GetValueF1(const Format1<N>& val, 
    const std::size_t& index)
{
    return static_cast<std::uint16_t>(val.Value[index]);
}

static std::uint16_t SplitValueF1Base2(const std::uint16_t& sum)
{
    return sum;
}

static std::uint8_t ElementValueF1Base2(const std::uint16_t& sum)
{
    return (sum & 0x00FF);
}

static std::uint8_t CarryValueF1Base2(const std::uint16_t& sum)
{
    return (sum >> 8);
}

static std::uint16_t NegationValueF1Base2(const std::uint16_t& sum,
    const std::size_t& i)
{
    return i == 0 ? (0x00ff & (~sum)) + 1 : 0x00ff & ~sum;
}

static std::uint16_t SplitValueF1Base10(const std::uint16_t& sum)
{
    std::uint16_t carry = sum / 10;
    return sum < 10 ? sum : (carry << 8) | (sum - (carry * 10));
}

static std::uint8_t ElementValueF1Base10(const std::uint16_t& sum)
{
    return sum & 0x00FF;
}

static std::uint8_t CarryValueF1Base10(const std::uint16_t& sum)
{
    return (sum >> 8);
}

static std::uint16_t NegationValueF1Base10(const std::uint16_t& sum,
    const std::size_t& i)
{
    return i == 0 ? (9 - sum) + 1 : (9 - sum);
}

int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{60};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 254);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{60, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 196);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 60};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{60, 60};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 196);
        assert(f1.Value[1] == 195);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }

    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{60, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 60);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 60};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{60, 60};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 60);
        assert(f1.Value[1] == 196);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{1, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{1, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{60, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 60);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 60, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 196);
        assert(f1.Value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{60, 60, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 60);
        assert(f1.Value[1] == 196);
        assert(f1.Value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{255, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 255, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{255, 255, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 255);
        assert(c1 == 0);
    }

    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{1, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 1, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{1, 1, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{60, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 60);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 60, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 196);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{60, 60, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 60);
        assert(f1.Value[1] == 196);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 0, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 255, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 0, 255};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, 1, 1, 3);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{5};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 8);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{5, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 5};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{5, 5};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 4);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{9, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{9, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }

    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 1};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{5, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 5};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{5, 5};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 5);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{9, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{9, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{1, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{1, 1, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{5, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 5, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 5);
        assert(f1.Value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{5, 5, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 5);
        assert(f1.Value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{9, 0, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{0, 9, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 3;
        Format1<N> f1{9, 9, 0};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 9);
        assert(c1 == 0);
    }
    
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{1, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 1, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{1, 1, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{5, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 5, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 5);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{5, 5, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 5);
        assert(f1.Value[1] == 5);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 0, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 9, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 0, 9};
        std::uint8_t c1 = test::math::integer::Negation<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10, 
            SplitValueF1Base10, ElementValueF1Base10, CarryValueF1Base10>(f1, 1, 1, 3);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 1);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    return 0;
}
