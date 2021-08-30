#include "test/math/integer/Addition.h"

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


int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{255, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 0};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 255};
        Format1<N> f2{0, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        Format1<N> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{1, 0};
        Format1<N> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 1};
        Format1<N> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{255, 255};
        Format1<N> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 254);
        assert(f1.Value[1] == 255);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 255, 0};
        Format1<N> f2{255, 255, 0, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 0, 0};
        Format1<N> f2{255, 255, 255, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 1, 0};
        Format1<N> f2{255, 255, 255, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 255, 0};
        Format1<N> f2{255, 255, 1, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 1, 0};
        Format1<N> f2{255, 255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{255, 255, 255, 255};
        Format1<N> f2{255, 255, 1, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 255);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{255, 255, 1, 1, 1, 1};
        std::uint16_t f2{0x0000};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{255, 255, 0, 0, 0, 0};
        std::uint16_t f2{0x0201};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 2);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{255, 255, 1, 255, 0, 0};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{255, 255, 1, 255, 255, 0};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{255, 255, 1, 255, 255, 255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{0, 0};
         Format1<N> f2{0, 0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{9, 0};
         Format1<N> f2{0, 0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{0, 0};
         Format1<N> f2{9, 0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{1, 0};
         Format1<N> f2{9, 0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{9, 0};
         Format1<N> f2{1, 0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{1, 0};
         Format1<N> f2{9, 9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{0, 1};
         Format1<N> f2{9, 9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
         Format1<N> f1{9, 9};
         Format1<N> f2{9, 9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 8);
        assert(f1.Value[1] == 9);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 9, 0};
        Format1<N> f2{9, 9, 0, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 0, 0};
        Format1<N> f2{9, 9, 9, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 1, 0};
        Format1<N> f2{9, 9, 9, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 9, 0};
        Format1<N> f2{9, 9, 1, 0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 0, 1};
        Format1<N> f2{9, 9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 1, 0};
        Format1<N> f2{9, 9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 4;
        Format1<N> f1{9, 9, 9, 9};
        Format1<N> f2{9, 9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, Format1<N>, std::uint16_t, std::size_t, N, N,
            SetValueF1<N>, GetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 9);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 1, 0, 0, 0};
        std::uint16_t f2{0x0000};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 0, 0, 0, 0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 1);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 1, 0, 0, 0};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 0, 1, 0, 0};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 1, 0, 0, 0};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 1, 0, 9, 9};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 6;
        Format1<N> f1{9, 9, 9, 9, 9, 9};
        std::uint16_t f2 = 99;
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 9);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{255, 0};
        Format1<N2> f2{0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{255, 255};
        Format1<N2> f2{0};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{1, 0};
        Format1<N2> f2{255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 1};
        Format1<N2> f2{255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{255, 255};
        Format1<N2> f2{255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 254);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 255, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 0, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 1, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 255, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 1, 1};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 255, 255};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 255);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 255, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 0, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 1, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 255, 0};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 1, 1};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{255, 255, 255, 255};
        Format1<N2> f2{255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 255, 0, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 0, 0, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 255);
        assert(f1.Value[4] == 255);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 1, 0, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 255, 1, 0, 255};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 1, 1, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 255, 255, 255, 255};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 255);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 255, 0, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 255);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 0, 0, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 255);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 255);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 1, 0, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 255);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 255, 255, 0, 255};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 1, 255, 255, 0};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{255, 255, 255, 255, 255, 255};
        Format1<N2> f2{255, 255, 255};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 255);
        assert(f1.Value[1] == 255);
        assert(f1.Value[2] == 254);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{0, 0};
         Format1<N2> f2{0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{9, 0};
         Format1<N2> f2{0};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{0, 0};
         Format1<N2> f2{9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{1, 1};
         Format1<N2> f2{9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{9, 0};
         Format1<N2> f2{1};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{1, 0};
         Format1<N2> f2{9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{0, 1};
         Format1<N2> f2{9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
         Format1<N1> f1{9, 9};
         Format1<N2> f2{9};
         std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 8);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 9, 0};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 0, 0};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 1, 0};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 9, 0};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 0, 1};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 1, 0};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 4;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{9, 9, 9, 9};
        Format1<N2> f2{9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 9);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 9, 0, 9, 0};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 0, 0, 9, 0};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 9);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 1, 0, 9, 0};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 9, 0, 9, 9};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 0, 1, 9, 9};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 1, 0, 9, 8};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 9, 9, 9, 9};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 9);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 9, 0, 9, 0};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 0, 0, 9, 0};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 1, 0, 9, 0};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 9, 9, 0, 9};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 1);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 0, 1, 9, 9};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 9);
        assert(f1.Value[3] == 1);
        assert(f1.Value[4] == 9);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 1, 9, 9, 8};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 0);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 6;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{9, 9, 9, 9, 9, 9};
        Format1<N2> f2{9, 9, 9};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            SetValueF1<N1>, GetValueF1<N1>, GetValueF1<N2>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 2, 1, 2);
        assert(f1.Value[0] == 9);
        assert(f1.Value[1] == 9);
        assert(f1.Value[2] == 8);
        assert(f1.Value[3] == 0);
        assert(f1.Value[4] == 0);
        assert(f1.Value[5] == 0);
        assert(c1 == 1);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 254);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0100};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0100};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x01FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x0100};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 255);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x01FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 254);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0xFFFF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2);
        assert(f1.Value[0] == 254);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 1);
        assert(c1 == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 255);
        assert(c1 == 255);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{255};
        std::uint16_t f2{0x00FF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 1 , 2);
        assert(f1.Value[0] == 255);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 255};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 255};
        std::uint16_t f2{0x0101};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 255};
        std::uint16_t f2{0xFFFF};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base2, 
            ElementValueF1Base2, CarryValueF1Base2>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 254);
        assert(c1 == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 8);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x000A};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x000A};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0013};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x000A};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 9);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0013};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 8);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0063};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2);
        assert(f1.Value[0] == 8);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 1);
        assert(c1 == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 1);
        assert(f1.Value[0] == 9);
        assert(c1 == 9);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 0);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{1};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0 , 2);
        assert(f1.Value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 1;
        Format1<N> f1{9};
        std::uint16_t f2{0x0009};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 1 , 2);
        assert(f1.Value[0] == 9);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 0};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 1);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 9};
        std::uint16_t f2{0x0001};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 9};
        std::uint16_t f2{0x000B};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 0);
        assert(c1 == 2);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N = 2;
        Format1<N> f1{0, 9};
        std::uint16_t f2{0x0063};
        std::uint8_t c1 = test::math::integer::Addition<std::uint8_t,
            Format1<N>, std::uint16_t, std::size_t, N,
            SetValueF1<N>, GetValueF1<N>, SplitValueF1Base10, 
            ElementValueF1Base10, CarryValueF1Base10>(f1, f2, 0, 1);
        assert(f1.Value[0] == 0);
        assert(f1.Value[1] == 8);
        assert(c1 == 0);
    }
    return 0;
}
