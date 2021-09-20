#include "test/math/integer/Comparison.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

template<typename TElement, typename TExpand, typename TSize>
struct Bin
{
    typedef TElement ElementType;
    typedef TExpand ExpandType;
    typedef TSize SizeType;

    static TExpand ExpandSplit(const TExpand& expand);

    static TExpand ExpandNegationValue(const TExpand& expand,
        const TSize& i);

    static TElement ExpandElementValue(const TExpand& expand_split);

    static TElement ExpandCarryValue(const TExpand& expand_split);

    static TElement LogElementValue(const TElement& v);
};

template<>
struct Bin<std::uint8_t, std::uint16_t, std::size_t>
{
    typedef std::uint8_t ElementType;
    typedef std::uint16_t ExpandType;
    typedef std::size_t SizeType;

    static constexpr std::uint8_t ElementMaxExponent = 8;

    static std::uint16_t ExpandSplit(const std::uint16_t& expand)
    {
        return expand;
    }

    static std::uint16_t ExpandNegationValue(const std::uint16_t& expand,
        const std::size_t& at)
    {
        return at == 0 ? (0x00ff & (~expand)) + 1 : 0x00ff & ~expand;
    }

    static std::uint8_t ExpandElementValue(const std::uint16_t& expand_split)
    {
        return (expand_split & 0x00FF);
    }

    static std::uint8_t ExpandCarryValue(const std::uint16_t& expand_split)
    {
        return (expand_split >> 8);
    }
    
    static std::uint8_t LogElementValue(const std::uint8_t& v)
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
    

};

template<typename TElement, typename TExpand, typename TSize>
struct Dec
{
    typedef TElement ElementType;
    typedef TExpand ExpandType;
    typedef TSize SizeType;

    static TExpand ExpandSplit(const TExpand& expand);
    
    static TExpand ExpandNegationValue(const TExpand& expand,
        const TSize& i);

    static TElement ExpandElementValue(const TExpand& expand_split);

    static TElement ExpandCarryValue(const TExpand& expand_split);

    static TElement LogElementValue(const TElement& v);
};

template<>
struct Dec<std::uint8_t, std::uint16_t, std::size_t>
{
    typedef std::uint8_t ElementType;
    typedef std::uint16_t ExpandType;
    typedef std::size_t SizeType;

    static constexpr std::uint8_t ElementMaxExponent = 1;

    static std::uint16_t ExpandSplit(const std::uint16_t& expand)
    {
        std::uint16_t carry = expand / 10;
        return expand < 10 ? expand : (carry << 8) | (expand - (carry * 10));
    }
    
    static std::uint16_t ExpandNegationValue(const std::uint16_t& expand,
        const std::size_t& at)
    {
        return at == 0 ? (9 - expand) + 1 : (9 - expand);
    }

    static std::uint8_t ExpandElementValue(const std::uint16_t& expand_split)
    {
        return (expand_split & 0x00FF);
    }

    static std::uint8_t ExpandCarryValue(const std::uint16_t& expand_split)
    {
        return (expand_split >> 8);
    }
    
    static std::uint8_t LogElementValue(const std::uint8_t& v)
    {
        return 0;
    }

};

template<std::size_t N, template<typename, typename, typename>class TTag>
struct Format : public TTag<std::uint8_t, std::uint16_t, std::size_t>
{
    static constexpr std::size_t Size = N;
    std::uint8_t m_value[N];
    static std::uint8_t GetElement(const Format<N, TTag>& val,
        const std::size_t& at)
    {
        return val.m_value[at];
    }

    static std::uint8_t SetElement(Format<N, TTag>& val,
        const std::size_t& at, const std::uint8_t& set_val)
    {
        return (val.m_value[at] = set_val);
    }

    Format() :
        m_value{0}
    {}
    template<typename TArg, typename ... TArgs,
        typename _TArg = typename std::remove_cv<typename std::remove_pointer<
            typename std::remove_reference<TArg>::type>::type>::type,
        typename std::enable_if<!std::is_base_of<Format<N, TTag>, _TArg>::value, 
            int>::type = 1>
    constexpr Format(const TArg& arg, const TArgs& ... args) :
            m_value{static_cast<std::uint8_t>(arg), 
                static_cast<std::uint8_t>(args)...}
    {}

};

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