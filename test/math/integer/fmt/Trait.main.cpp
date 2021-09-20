#include "test/math/integer/fmt/Trait.h"

#include <type_traits>
#include <cstdint>
#include <cassert>

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
        typedef Format<2, Bin> Format1Type;
        typedef test::math::integer::fmt::Trait<Format1Type> Trait1;
        Format1Type f1;

        assert((std::is_same<typename Format1Type::ElementType, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<typename Format1Type::ExpandType, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<typename Format1Type::SizeType, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::Has == true));

        assert((Trait1::HasElementType == true));
        assert((Trait1::HasExpandType == true));
        assert((Trait1::HasSizeType == true));

        assert((Trait1::HasConstantSize == true));
        assert((Trait1::HasConstantElementMaxExponent == true));

        assert((Trait1::HasExpandSplitFunction == true));
        assert((Trait1::HasExpandNegationValueFunction == true));
        assert((Trait1::HasExpandElementValueFunction == true));
        assert((Trait1::HasExpandCarryValueFunction == true));
        assert((Trait1::HasLogElementValueFunction == true));
        assert((Trait1::HasGetElementFunction == true));
        assert((Trait1::HasSetElementFunction == true));

        assert((Trait1::IsSame == true));

        assert((Trait1::IsSameElementType == true));
        assert((Trait1::IsSameExpandType == true));
        assert((Trait1::IsSameSizeType == true));

        assert((Trait1::IsSameConstantElementMaxExponent == true));

        assert((Trait1::IsSameExpandSplitFunction == true));
        assert((Trait1::IsSameExpandNegationValueFunction == true));
        assert((Trait1::IsSameExpandElementValueFunction == true));
        assert((Trait1::IsSameExpandCarryValueFunction == true));
        assert((Trait1::IsSameLogElementValueFunction == true));

        assert((Trait1::Size == Format1Type::Size));
        assert((Trait1::ElementMaxExponent == Format1Type::ElementMaxExponent));

        assert(Trait1::ExpandSplit(0) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(0)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(0)) == 0);
        
        assert(Trait1::ExpandSplit(255) == 255);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(255)) == 255);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(255)) == 0);
        
        assert(Trait1::ExpandSplit(65280) == 65280);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(65280)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(65280)) == 255);

        assert(Trait1::ExpandNegationValue(1, 0) == 255);
        assert(Trait1::ExpandNegationValue(1, 1) == 254);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 6);
        assert(Trait1::LogElementValue(255) == 7);

        assert(Trait1::Size == 2);

        assert(Trait1::GetElement(f1, 0) == 0);
        assert(Trait1::GetElement(f1, 1) == 0);
        
        assert(Trait1::SetElement(f1, 0, 1) == 1);
        assert(Trait1::SetElement(f1, 1, 2) == 2);
        
        assert(Trait1::GetElement(f1, 0) == 1);
        assert(Trait1::GetElement(f1, 1) == 2);
    }
    { 
        typedef Format<2, Dec> Format1Type;
        typedef test::math::integer::fmt::Trait<Format1Type> Trait1;
        Format1Type f1;

        assert((std::is_same<typename Format1Type::ElementType, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<typename Format1Type::ExpandType, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<typename Format1Type::SizeType, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::Has == true));

        assert((Trait1::HasElementType == true));
        assert((Trait1::HasExpandType == true));
        assert((Trait1::HasSizeType == true));

        assert((Trait1::HasConstantSize == true));
        assert((Trait1::HasConstantElementMaxExponent == true));

        assert((Trait1::HasExpandSplitFunction == true));
        assert((Trait1::HasExpandNegationValueFunction == true));
        assert((Trait1::HasExpandElementValueFunction == true));
        assert((Trait1::HasExpandCarryValueFunction == true));
        assert((Trait1::HasLogElementValueFunction == true));
        assert((Trait1::HasGetElementFunction == true));
        assert((Trait1::HasSetElementFunction == true));

        assert((Trait1::IsSame == true));

        assert((Trait1::IsSameElementType == true));
        assert((Trait1::IsSameExpandType == true));
        assert((Trait1::IsSameSizeType == true));

        assert((Trait1::IsSameConstantElementMaxExponent == true));

        assert((Trait1::IsSameExpandSplitFunction == true));
        assert((Trait1::IsSameExpandNegationValueFunction == true));
        assert((Trait1::IsSameExpandElementValueFunction == true));
        assert((Trait1::IsSameExpandCarryValueFunction == true));
        assert((Trait1::IsSameLogElementValueFunction == true));

        assert((Trait1::Size == Format1Type::Size));
        assert((Trait1::ElementMaxExponent == Format1Type::ElementMaxExponent));

        assert(Trait1::ExpandSplit(0) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(0)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(0)) == 0);
        
        assert(Trait1::ExpandSplit(4) == 4);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(4)) == 4);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(4)) == 0);
        
        assert(Trait1::ExpandSplit(16) == 0x0106);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(16)) == 6);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(16)) == 1);

        assert(Trait1::ExpandNegationValue(1, 0) == 9);
        assert(Trait1::ExpandNegationValue(1, 1) == 8);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(4) == 0);
        assert(Trait1::LogElementValue(9) == 0);

        assert(Trait1::Size == 2);

        assert(Trait1::GetElement(f1, 0) == 0);
        assert(Trait1::GetElement(f1, 1) == 0);
        
        assert(Trait1::SetElement(f1, 0, 1) == 1);
        assert(Trait1::SetElement(f1, 1, 2) == 2);
        
        assert(Trait1::GetElement(f1, 0) == 1);
        assert(Trait1::GetElement(f1, 1) == 2);
    }
    return 0;
}
