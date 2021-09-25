#include "test/math/integer/Shift.h"

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

    return 0;
}