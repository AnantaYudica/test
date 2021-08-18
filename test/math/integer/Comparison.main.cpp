#include "test/math/integer/Comparison.h"

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
        typename std::enable_if<!std::is_base_of<Format1<N>, _TArg>::value ||
            !std::is_same<Format1<N>, _TArg>::value, int>::type = 1>
    constexpr Format1(const TArg& arg, const TArgs& ... args) :
            Value{static_cast<std::uint8_t>(arg), 
                static_cast<std::uint8_t>(args)...}
    {}
    template<typename TArg, typename ... TArgs,
        typename _TArg = typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<std::is_base_of<Format1<N>, _TArg>::value ||
            std::is_same<Format1<N>, _TArg>::value, int>::type = 1>
    Format1(const TArg& arg) :
            Value{0}
    {
        const Format1<N>& cpy = static_cast<const Format1<N>&>(arg);
        for (std::size_t i = 0; i < N; ++i)
        {
            Value[i] = cpy.Value[i];
        }
    }
};

template<std::size_t N>
static std::uint16_t GetValueF1(const Format1<N>& val, 
    const std::size_t& index)
{
    return static_cast<std::uint16_t>(val.Value[index]);
}

int main()
{
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0};
        Format1<N2> f2{0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0, 0};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0, 0};
        Format1<N2> f2{0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{1};
        Format1<N2> f2{0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{1, 0};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 1};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{1, 1};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{1, 0, 0};
        Format1<N2> f2{0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 1, 0};
        Format1<N2> f2{0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0, 1};
        Format1<N2> f2{0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{1, 0, 0};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 1, 0};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 0, 1};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{1, 0, 0};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 1, 0};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0, 1};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{1};
        Format1<N2> f2{0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{1};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{1, 0};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 1};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{1, 1};
        Format1<N2> f2{0, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0};
        Format1<N2> f2{1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{0, 0, 0};
        Format1<N2> f2{1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0};
        Format1<N2> f2{1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0};
        Format1<N2> f2{0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0};
        Format1<N2> f2{1, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{1, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0};
        Format1<N2> f2{0, 0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0, 0};
        Format1<N2> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0, 0};
        Format1<N2> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0, 0};
        Format1<N2> f2{0, 0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == -1);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{1};
        Format1<N2> f2{1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 1;
        Format1<N1> f1{1, 0};
        Format1<N2> f2{1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 1;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{1};
        Format1<N2> f2{1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{1, 0};
        Format1<N2> f2{1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 2;
        Format1<N1> f1{0, 1};
        Format1<N2> f2{0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{1, 0};
        Format1<N2> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 2;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 1};
        Format1<N2> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{1, 0, 0};
        Format1<N2> f2{1, 0, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 1, 0};
        Format1<N2> f2{0, 1, 0};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        constexpr SizeType N1 = 3;
        constexpr SizeType N2 = 3;
        Format1<N1> f1{0, 0, 1};
        Format1<N2> f2{0, 0, 1};
        int c1 = test::math::integer::Comparison<std::uint8_t,
            Format1<N1>, Format1<N2>, std::uint16_t, std::size_t, N1, N2,
            GetValueF1<N1>, GetValueF1<N2>>(f1, f2);
        assert(c1 == 0);
    }
    return 0;
}