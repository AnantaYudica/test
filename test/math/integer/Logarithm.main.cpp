#include "test/math/integer/Logarithm.h"

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
    return 0;
}