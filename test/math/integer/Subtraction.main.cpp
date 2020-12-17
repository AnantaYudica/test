#include "test/math/integer/Subtraction.h"

#include <cstddef>
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
static std::uint8_t SetValueF1(Format1<N>& val, const std::size_t& index,
    const std::uint8_t& setval)
{
    return (val.Value[index] = setval);
}

template<std::size_t N>
static std::uint16_t GetValueF1(const Format1<N>& val, 
    const std::size_t& index)
{
    return static_cast<std::uint16_t>(val.Value[index]);
}

template<std::size_t N>
static std::uint16_t NegationValueF1Base2(const Format1<N>& val, 
    const std::size_t& index)
{
    return ~val.Value[index] & 0xFF;
}

static std::uint16_t NegationValueF1Base2(const std::uint16_t& val)
{
    return ~val;
}

static std::uint16_t SplitValueF1Base2(const std::uint16_t& diff)
{
    return diff;
}

static std::uint8_t ElementValueF1Base2(const std::uint16_t& diff)
{
    return (diff & 0x00FF);
}

static std::uint8_t CarryValueF1Base2(const std::uint16_t& diff)
{
    return (diff >> 8);
}

template<std::size_t N>
static std::uint16_t NegationValueF1Base10(const Format1<N>& val, 
    const std::size_t& index)
{
    return 9 - val.Value[index];
}

static std::uint16_t NegationValueF1Base10(const std::uint16_t& val)
{
    return 99 - val;
}

static std::uint16_t SplitValueF1Base10(const std::uint16_t& diff)
{
    std::uint16_t carry = diff / 10;
    return diff < 10 ? diff : (carry << 8) | (diff - (carry * 10));
}

static std::uint8_t ElementValueF1Base10(const std::uint16_t& diff)
{
    return diff & 0x00FF;
}

static std::uint8_t CarryValueF1Base10(const std::uint16_t& diff)
{
    return diff >> 8;
}

int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        Format1<N> f2{1, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 0};
        Format1<N> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 1, 0};
        Format1<N> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 0};
        Format1<N> f2{0, 0, 1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 1};
        Format1<N> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 0};
        Format1<N> f2{0, 0, 0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2, 0xFF>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 1, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2, 0xFF>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0001;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2,
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2, 0xFF>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(f1.Value[4] == 255);
        assert(f1.Value[5] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0xFF00;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base2, 
            SplitValueF1Base2, ElementValueF1Base2, 
            CarryValueF1Base2, 0xFF>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 255);
        assert(f1.Value[5] == 255);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 1);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
            Format1<N> f1{0, 1};
            Format1<N> f2{1, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 0};
        Format1<N> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 1, 0};
        Format1<N> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 0};
        Format1<N> f2{0, 0, 1, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 1};
        Format1<N> f2{0, 0, 0, 0};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 0};
        Format1<N> f2{0, 0, 0, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{0, 0, 0, 1};
        Format1<N> f2{0, 0, 1, 1};
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10<N>, 
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10,
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10, 9>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 1, 0, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10,
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10, 9>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x0001;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10,
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10, 9>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 1, 0, 0};
        std::uint16_t f2 = 0x0000;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10,
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10, 9>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 0, 0, 0, 0};
        std::uint16_t f2 = 0x000A;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10,
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10, 9>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{0, 0, 1, 0, 0, 0};
        std::uint16_t f2 = 0x000B;
        std::uint8_t c1 = test::math::integer::Subtraction<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, NegationValueF1Base10,
            SplitValueF1Base10, ElementValueF1Base10, 
            CarryValueF1Base10, 9>(f1, f2, 2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 9);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    
    return 0;
}
