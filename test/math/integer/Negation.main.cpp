#include "test/math/integer/Negation.h"

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

    static TElement ShiftRightElementValue(const TElement& v, const TSize& n);
    
    static TElement ShiftLeftElementValue(const TElement& v, const TSize& n);
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

    static std::uint8_t ShiftRightElementValue(const std::uint8_t& v, 
        const std::size_t& n)
    {
        return v >> n;
    }
    
    static std::uint8_t ShiftLeftElementValue(const std::uint8_t& v, 
        const std::size_t& n)
    {
        return v << n;
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
    
    static TElement ShiftRightElementValue(const TElement& v, const TSize& n);
    
    static TElement ShiftLeftElementValue(const TElement& v, const TSize& n);
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
    
    static std::uint8_t ShiftRightElementValue(const std::uint8_t& v, 
        const std::size_t& n)
    {
        if (n >= 1) return 0;
        return v;
    }
    
    static std::uint8_t ShiftLeftElementValue(const std::uint8_t& v, 
        const std::size_t& n)
    {
        if (n >= 1) return 0;
        return v;
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
        
        assert(v1 == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 1;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        assert(v1 == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 255;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        assert(v1 == 2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 60;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Bin>>(v1, 1);
        assert(v1 == 197);
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
        assert(v1 == 1);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 1;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 0);
        assert(c1 == 1);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 9;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 2);
        assert(c1 == 0);
    }
    {
        typedef std::size_t SizeType;
        std::uint16_t v1 = 5;
        std::uint8_t c1 = test::math::integer::Negation<Format<1, Dec>>(v1, 1);
        assert(v1 == 6);
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
