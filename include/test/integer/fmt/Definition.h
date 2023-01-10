#ifndef TEST_INTEGER_FMT_DEFINITION_H_
#define TEST_INTEGER_FMT_DEFINITION_H_

#include "../../System.h"
#include "../Flag.h"

#include <cstddef>
#include <cstdint>

namespace test::integer::fmt
{

template<typename TInt, std::size_t NBase>
struct Definition;

}

#ifndef TEST_INTEGER_FMT_DEFINITION_DLEVEL

#define TEST_INTEGER_FMT_DEFINITION_DLEVEL 2

#endif //!TEST_INTEGER_FMT_DEFINITION_DLEVEL

#define TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS\
    test::sys::dbg::Type<TInt>,\
    test::sys::dbg::type::Value<std::size_t , NBase>

template<typename TInt, std::size_t NBase>
TEST_SYS_DBG_TYPE_PARAMETER_LEVEL_DEFINE(
    TEST_INTEGER_FMT_DEFINITION_DLEVEL, 
    "test::integer::fmt::Definition", 
    test::integer::fmt::Definition<TInt, NBase>);

#undef TEST_SYS_DBG_TYPE_PARAMETER_DEFINE_ARGS

namespace test
{
namespace integer
{
namespace fmt
{

template<typename TInt, std::size_t NBase>
struct Definition
{};

template<>
struct Definition<std::uint8_t, 2>
{
    typedef std::uint8_t ElementType;
    typedef std::uint16_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint8_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = true;
    static constexpr bool HasOrOp = true;
    static constexpr bool HasXorOp = true;
    static constexpr bool HasNotOp = true;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 8;
    static constexpr ElementType ElementMaxValue = 0xff;
    static constexpr SizeType ElementAllocBitSize = 8;
    static constexpr SizeType BitSize = 8;

    static constexpr test::integer::Flag Flag();

    static std::uint16_t ExpandSplit(const std::uint16_t& expand);

    static std::uint16_t ExpandNegationValue(const std::uint16_t& expand);

    static std::uint8_t ExpandElementValue(const std::uint16_t& expand_split);

    static std::uint8_t ExpandCarryValue(const std::uint16_t& expand_split);

    static std::uint8_t LogElementValue(const std::uint8_t& v);

    static std::uint8_t ShiftRightElementValue(const std::uint8_t& v, 
        const std::size_t& n);
    
    static std::uint8_t ShiftLeftElementValue(const std::uint8_t& v, 
        const std::size_t& n);
    
    static std::uint8_t DigitElementValue(const std::uint8_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);
    
    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint8_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint8_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint8_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint8_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int8_t, 2> :
    Definition<std::uint8_t, 2>
{  
    static constexpr bool Signed = true;

    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint16_t, 2>
{
    typedef std::uint16_t ElementType;
    typedef std::uint32_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint16_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = true;
    static constexpr bool HasOrOp = true;
    static constexpr bool HasXorOp = true;
    static constexpr bool HasNotOp = true;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 16;
    static constexpr ElementType ElementMaxValue = 0xffff;
    static constexpr SizeType ElementAllocBitSize = 16;
    static constexpr SizeType BitSize = 16;

    static constexpr test::integer::Flag Flag();

    static std::uint32_t ExpandSplit(const std::uint32_t& expand);

    static std::uint32_t ExpandNegationValue(const std::uint32_t& expand);

    static std::uint16_t ExpandElementValue(const std::uint32_t& expand_split);

    static std::uint16_t ExpandCarryValue(const std::uint32_t& expand_split);

    static std::uint16_t LogElementValue(const std::uint16_t& v);

    static std::uint16_t ShiftRightElementValue(const std::uint16_t& v, 
        const std::size_t& n);
    
    static std::uint16_t ShiftLeftElementValue(const std::uint16_t& v, 
        const std::size_t& n);
    
    static std::uint16_t DigitElementValue(const std::uint16_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint16_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint16_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint16_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint16_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int16_t, 2> :
    Definition<std::uint16_t, 2>
{  
    static constexpr bool Signed = true;
    
    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint32_t, 2>
{
    typedef std::uint32_t ElementType;
    typedef std::uint64_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint32_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = true;
    static constexpr bool HasOrOp = true;
    static constexpr bool HasXorOp = true;
    static constexpr bool HasNotOp = true;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 32;
    static constexpr ElementType ElementMaxValue = 0xffffffff;
    static constexpr SizeType ElementAllocBitSize = 32;
    static constexpr SizeType BitSize = 32;

    static constexpr test::integer::Flag Flag();
    
    static std::uint64_t ExpandSplit(const std::uint64_t& expand);

    static std::uint64_t ExpandNegationValue(const std::uint64_t& expand);

    static std::uint32_t ExpandElementValue(const std::uint64_t& expand_split);

    static std::uint32_t ExpandCarryValue(const std::uint64_t& expand_split);

    static std::uint32_t LogElementValue(const std::uint32_t& v);

    static std::uint32_t ShiftRightElementValue(const std::uint32_t& v, 
        const std::size_t& n);
    
    static std::uint32_t ShiftLeftElementValue(const std::uint32_t& v, 
        const std::size_t& n);
    
    static std::uint32_t DigitElementValue(const std::uint32_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint32_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint32_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint32_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint32_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int32_t, 2> :
    Definition<std::uint32_t, 2>
{  
    static constexpr bool Signed = true;
    
    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint64_t, 2> :
    Definition<std::uint32_t, 2>
{
    static constexpr SizeType NMinSize = 2;
    static constexpr SizeType BitSize = 64;

    static constexpr std::size_t AllocationSize(std::size_t n);
};

template<>
struct Definition<std::int64_t, 2> :
    Definition<std::int32_t, 2>
{  
    static constexpr SizeType NMinSize = 2;
    static constexpr SizeType BitSize = 64;

    static constexpr std::size_t AllocationSize(std::size_t n);
};

template<>
struct Definition<std::uint8_t, 8>
{
    typedef std::uint8_t ElementType;
    typedef std::uint16_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint8_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = false;
    static constexpr bool HasOrOp = false;
    static constexpr bool HasXorOp = false;
    static constexpr bool HasNotOp = false;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 2;
    static constexpr ElementType ElementMaxValue = 0x3f;
    static constexpr SizeType ElementAllocBitSize = 6;
    static constexpr SizeType BitSize = 6;
    
    static constexpr test::integer::Flag Flag();

    static std::uint16_t ExpandSplit(const std::uint16_t& expand);

    static std::uint16_t ExpandNegationValue(const std::uint16_t& expand);

    static std::uint8_t ExpandElementValue(const std::uint16_t& expand_split);

    static std::uint8_t ExpandCarryValue(const std::uint16_t& expand_split);

    static std::uint8_t LogElementValue(const std::uint8_t& v);

    static std::uint8_t ShiftRightElementValue(const std::uint8_t& v, 
        const std::size_t& n);

    static std::uint8_t ShiftLeftElementValue(const std::uint8_t& v, 
        const std::size_t& n);
    
    static std::uint8_t DigitElementValue(const std::uint8_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint8_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint8_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint8_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint8_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int8_t, 8> :
    Definition<std::uint8_t, 8>
{
    static constexpr bool Signed = true;
    
    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint16_t, 8>
{
    typedef std::uint16_t ElementType;
    typedef std::uint32_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint16_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = false;
    static constexpr bool HasOrOp = false;
    static constexpr bool HasXorOp = false;
    static constexpr bool HasNotOp = false;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 5;
    static constexpr ElementType ElementMaxValue = 0x7fff;
    static constexpr SizeType ElementAllocBitSize = 15;
    static constexpr SizeType BitSize = 15;
    
    static constexpr test::integer::Flag Flag();

    static std::uint32_t ExpandSplit(const std::uint32_t& expand);

    static std::uint32_t ExpandNegationValue(const std::uint32_t& expand);

    static std::uint16_t ExpandElementValue(const std::uint32_t& expand_split);

    static std::uint16_t ExpandCarryValue(const std::uint32_t& expand_split);

    static std::uint16_t LogElementValue(const std::uint16_t& v);

    static std::uint16_t ShiftRightElementValue(const std::uint16_t& v, 
        const std::size_t& n);
    
    static std::uint16_t ShiftLeftElementValue(const std::uint16_t& v, 
        const std::size_t& n);
    
    static std::uint16_t DigitElementValue(const std::uint16_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint16_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint16_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint16_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint16_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int16_t, 8> :
    Definition<std::uint16_t, 8>
{
    static constexpr bool Signed = true;
    
    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint32_t, 8>
{
    typedef std::uint32_t ElementType;
    typedef std::uint64_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint32_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = false;
    static constexpr bool HasOrOp = false;
    static constexpr bool HasXorOp = false;
    static constexpr bool HasNotOp = false;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 10;
    static constexpr ElementType ElementMaxValue = 0x3fffffff;
    static constexpr SizeType ElementAllocBitSize = 30;
    static constexpr SizeType BitSize = 30;
    
    static constexpr test::integer::Flag Flag();

    static std::uint64_t ExpandSplit(const std::uint64_t& expand);

    static std::uint64_t ExpandNegationValue(const std::uint64_t& expand);

    static std::uint32_t ExpandElementValue(const std::uint64_t& expand_split);

    static std::uint32_t ExpandCarryValue(const std::uint64_t& expand_split);

    static std::uint32_t LogElementValue(const std::uint32_t& v);

    static std::uint32_t ShiftRightElementValue(const std::uint32_t& v, 
        const std::size_t& n);
    
    static std::uint32_t ShiftLeftElementValue(const std::uint32_t& v, 
        const std::size_t& n);
    
    static std::uint32_t DigitElementValue(const std::uint32_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint32_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint32_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint32_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint32_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int32_t, 8> :
    Definition<std::uint32_t, 8>
{
    static constexpr bool Signed = true;

    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint64_t, 8> :
    Definition<std::uint32_t, 8>
{
    static constexpr SizeType NMinSize = 2;
    static constexpr SizeType BitSize = 60;

    static constexpr std::size_t AllocationSize(std::size_t n);
};

template<>
struct Definition<std::int64_t, 8> :
    Definition<std::int32_t, 8>
{  
    static constexpr SizeType NMinSize = 2;
    static constexpr SizeType BitSize = 60;

    static constexpr std::size_t AllocationSize(std::size_t n);
};

template<>
struct Definition<std::uint8_t, 10>
{
    typedef std::uint8_t ElementType;
    typedef std::uint16_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint8_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = false;
    static constexpr bool HasOrOp = false;
    static constexpr bool HasXorOp = false;
    static constexpr bool HasNotOp = false;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 2;
    static constexpr ElementType ElementMaxValue = 99;
    static constexpr SizeType ElementAllocBitSize = 7;
    static constexpr SizeType BitSize = 7;
    
    static constexpr test::integer::Flag Flag();

    static std::uint16_t ExpandSplit(const std::uint16_t& expand);

    static std::uint16_t ExpandNegationValue(const std::uint16_t& expand);

    static std::uint8_t ExpandElementValue(const std::uint16_t& expand_split);

    static std::uint8_t ExpandCarryValue(const std::uint16_t& expand_split);

    static std::uint8_t LogElementValue(const std::uint8_t& v);

    static std::uint8_t ShiftRightElementValue(const std::uint8_t& v, 
        const std::size_t& n);
    
    static std::uint8_t ShiftLeftElementValue(const std::uint8_t& v, 
        const std::size_t& n);

    static std::uint8_t DigitElementValue(const std::uint8_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint8_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint8_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint8_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint8_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int8_t, 10> :
    Definition<std::uint8_t, 10>
{
    static constexpr bool Signed = true;

    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint16_t, 10>
{
    typedef std::uint16_t ElementType;
    typedef std::uint32_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint16_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = false;
    static constexpr bool HasOrOp = false;
    static constexpr bool HasXorOp = false;
    static constexpr bool HasNotOp = false;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 4;
    static constexpr ElementType ElementMaxValue = 9999;
    static constexpr SizeType ElementAllocBitSize = 14;
    static constexpr SizeType BitSize = 14;
    
    static constexpr test::integer::Flag Flag();

    static std::uint32_t ExpandSplit(const std::uint32_t& expand);

    static std::uint32_t ExpandNegationValue(const std::uint32_t& expand);

    static std::uint16_t ExpandElementValue(const std::uint32_t& expand_split);

    static std::uint16_t ExpandCarryValue(const std::uint32_t& expand_split);

    static std::uint16_t LogElementValue(const std::uint16_t& v);

    static std::uint16_t ShiftRightElementValue(const std::uint16_t& v, 
        const std::size_t& n);
    
    static std::uint16_t ShiftLeftElementValue(const std::uint16_t& v, 
        const std::size_t& n);
    
    static std::uint16_t DigitElementValue(const std::uint16_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint16_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint16_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint16_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint16_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int16_t, 10> :
    Definition<std::uint16_t, 10>
{
    static constexpr bool Signed = true;

    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint32_t, 10>
{
    typedef std::uint32_t ElementType;
    typedef std::uint64_t ExpandType;
    typedef std::size_t SizeType;
    typedef std::uint32_t DigitType; 

    static constexpr bool HasAdditionOp = true;
    static constexpr bool HasSubtractionOp = true;
    static constexpr bool HasMultiplicationOp = true;
    static constexpr bool HasDivisionOp = true;
    static constexpr bool HasShiftOp = true;
    static constexpr bool HasNegationOp = true;
    static constexpr bool HasAndOp = false;
    static constexpr bool HasOrOp = false;
    static constexpr bool HasXorOp = false;
    static constexpr bool HasNotOp = false;

    static constexpr bool Signed = false;
    static constexpr SizeType NMinSize = 1;
    static constexpr SizeType ElementAllocSize = sizeof(ElementType);
    static constexpr ElementType ElementMaxExponent = 9;
    static constexpr ElementType ElementMaxValue = 999999999ul;
    static constexpr SizeType ElementAllocBitSize = 30;
    static constexpr SizeType BitSize = 30;
    
    static constexpr test::integer::Flag Flag();

    static std::uint64_t ExpandSplit(const std::uint64_t& expand);

    static std::uint64_t ExpandNegationValue(const std::uint64_t& expand);

    static std::uint32_t ExpandElementValue(const std::uint64_t& expand_split);

    static std::uint32_t ExpandCarryValue(const std::uint64_t& expand_split);

    static std::uint32_t LogElementValue(const std::uint32_t& v);

    static std::uint32_t ShiftRightElementValue(const std::uint32_t& v, 
        const std::size_t& n);
    
    static std::uint32_t ShiftLeftElementValue(const std::uint32_t& v, 
        const std::size_t& n);
    
    static std::uint32_t DigitElementValue(const std::uint32_t& v, 
        const std::size_t& off, const std::size_t& n = 1);

    static constexpr std::size_t AllocationSize(std::size_t n);

    template<typename TElement>
    static constexpr SizeType ElementResize(const std::size_t& n);

    static constexpr std::uint32_t ElementMaxValueAt(const std::uint8_t&, 
        const SizeType& at);
        
    static constexpr std::uint32_t ElementMaxValueAt(const std::uint16_t&, 
        const SizeType& at);
    
    static constexpr std::uint32_t ElementMaxValueAt(const std::uint32_t&, 
        const SizeType& at);
    
    template<typename TElement>
    static std::uint32_t ElementValueAt(const TElement& element, 
        const SizeType& at);
        
    template<std::size_t NToBase>
    static constexpr SizeType ElementBaseResize(const std::size_t& n);
};

template<>
struct Definition<std::int32_t, 10> :
    Definition<std::uint32_t, 10>
{
    static constexpr bool Signed = true;

    static constexpr test::integer::Flag Flag();
};

template<>
struct Definition<std::uint64_t, 10> :
    Definition<std::uint32_t, 10>
{
    static constexpr SizeType NMinSize = 2;
    static constexpr SizeType BitSize = 60;

    static constexpr std::size_t AllocationSize(std::size_t n);
};

template<>
struct Definition<std::int64_t, 10> :
    Definition<std::int32_t, 10>
{  
    static constexpr SizeType NMinSize = 2;
    static constexpr SizeType BitSize = 60;

    static constexpr std::size_t AllocationSize(std::size_t n);
};

constexpr test::integer::Flag Definition<std::uint8_t, 2>::Flag()
{
    return {test::integer::Flag::kBinaryFormat};
}

std::uint16_t Definition<std::uint8_t, 2>::
    ExpandSplit(const std::uint16_t& expand)
{
    return expand;
}

std::uint16_t Definition<std::uint8_t, 2>::
    ExpandNegationValue(const std::uint16_t& expand)
{
    return 0x00ff & ~expand;
}

std::uint8_t Definition<std::uint8_t, 2>::
    ExpandElementValue(const std::uint16_t& expand_split)
{
    return 0x00ff & expand_split;
}

std::uint8_t Definition<std::uint8_t, 2>::
    ExpandCarryValue(const std::uint16_t& expand_split)
{
    return expand_split >> 8;
}

std::uint8_t Definition<std::uint8_t, 2>::
    LogElementValue(const std::uint8_t& v)
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

std::uint8_t Definition<std::uint8_t, 2>::
    ShiftRightElementValue(const std::uint8_t& v, const std::size_t& n)
{
    return v >> n;
}

std::uint8_t Definition<std::uint8_t, 2>::
    ShiftLeftElementValue(const std::uint8_t& v, const std::size_t& n)
{
    return v << n;
}

std::uint8_t Definition<std::uint8_t, 2>::
    DigitElementValue(const std::uint8_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 8) return 0;
    else if (n > 8) _n = 8;
    return (v & ((0xff >> (8 - _n)) << off)) >> off;
}

constexpr std::size_t Definition<std::uint8_t, 2>::
    AllocationSize(std::size_t n)
{
    return n * test::integer::fmt::Definition<std::uint8_t, 2>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint8_t, 2>::
        NMinSize;
}

template<typename TElement>
constexpr typename Definition<std::uint8_t, 2>::SizeType 
Definition<std::uint8_t, 2>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint8_t, 2>::ElementMaxExponent) / 
            Definition<TElement, 2>::ElementMaxExponent) + 
        (((Definition<std::uint8_t, 2>::ElementMaxExponent * n) % 
             Definition<TElement, 2>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint8_t Definition<std::uint8_t, 2>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at == 0 ? Definition<std::uint8_t, 2>::ElementMaxValue : 0;
}
        
constexpr std::uint8_t Definition<std::uint8_t, 2>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 1 ? Definition<std::uint8_t, 2>::ElementMaxValue : 0;
}
    
constexpr std::uint8_t Definition<std::uint8_t, 2>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 3 ? Definition<std::uint8_t, 2>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint8_t Definition<std::uint8_t, 2>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    return (std::uint8_t)(element >> at);
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint8_t, 2>::SizeType 
Definition<std::uint8_t, 2>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? n :
        NToBase == 8 ? ((134 * n) / 100) + ((134 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 10 ? ((121 * n) / 100) + ((121 * n) % 100 == 0 ? 0 : 1) : 0;
}

constexpr test::integer::Flag Definition<std::int8_t, 2>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kBinaryFormat};
}

constexpr test::integer::Flag Definition<std::uint16_t, 2>::Flag()
{
    return {test::integer::Flag::kBinaryFormat};
}

std::uint32_t Definition<std::uint16_t, 2>::
    ExpandSplit(const std::uint32_t& expand)
{
    return expand;
}

std::uint32_t Definition<std::uint16_t, 2>::
    ExpandNegationValue(const std::uint32_t& expand)
{
    return 0x0000ffff & ~expand;
}

std::uint16_t Definition<std::uint16_t, 2>::
    ExpandElementValue(const std::uint32_t& expand_split)
{
    return 0x0000ffff & expand_split;
}

std::uint16_t Definition<std::uint16_t, 2>::
    ExpandCarryValue(const std::uint32_t& expand_split)
{
    return expand_split >> 16;
}

std::uint16_t Definition<std::uint16_t, 2>::
    LogElementValue(const std::uint16_t& v)
{
    if (v & 0x8000) return 15;
    else if (v & 0x4000) return 14;
    else if (v & 0x2000) return 13;
    else if (v & 0x1000) return 12;
    else if (v & 0x800) return 11;
    else if (v & 0x400) return 10;
    else if (v & 0x200) return 9;
    else if (v & 0x100) return 8;
    return Definition<std::uint8_t, 2>::LogElementValue(v);
}

std::uint16_t Definition<std::uint16_t, 2>::
    ShiftRightElementValue(const std::uint16_t& v, const std::size_t& n)
{
    return v >> n;
}

std::uint16_t Definition<std::uint16_t, 2>::
    ShiftLeftElementValue(const std::uint16_t& v, const std::size_t& n)
{
    return v << n;
}

std::uint16_t Definition<std::uint16_t, 2>::
    DigitElementValue(const std::uint16_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 16) return 0;
    else if (n > 16) _n = 16;
    return (v & ((0xffff >> (16 - _n)) << off)) >> off;
}

constexpr std::size_t Definition<std::uint16_t, 2>::
    AllocationSize(std::size_t n)
{
    return n * test::integer::fmt::Definition<std::uint16_t, 2>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint16_t, 2>::
        NMinSize;
}

template<typename TElement>
constexpr typename Definition<std::uint16_t, 2>::SizeType 
Definition<std::uint16_t, 2>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint16_t, 2>::ElementMaxExponent) /
            Definition<TElement, 2>::ElementMaxExponent) + 
        (((Definition<std::uint16_t, 2>::ElementMaxExponent * n) % 
            Definition<TElement, 2>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint16_t Definition<std::uint16_t, 2>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 2>::ElementMaxValue : 0;
}
        
constexpr std::uint16_t Definition<std::uint16_t, 2>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint16_t, 2>::ElementMaxValue : 0;
}
    
constexpr std::uint16_t Definition<std::uint16_t, 2>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 1 ? Definition<std::uint16_t, 2>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint16_t Definition<std::uint16_t, 2>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    return (std::uint16_t)(element >> at);
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint16_t, 2>::SizeType 
Definition<std::uint16_t, 2>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? n :
        NToBase == 8 ? ((107 * n) / 100) + ((107 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 10 ? ((121 * n) / 100) + ((121 * n) % 100 == 0 ? 0 : 1) : 0;
}

constexpr test::integer::Flag Definition<std::int16_t, 2>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kBinaryFormat};
}

constexpr test::integer::Flag Definition<std::uint32_t, 2>::Flag()
{
    return {test::integer::Flag::kBinaryFormat};
}

std::uint64_t Definition<std::uint32_t, 2>::
    ExpandSplit(const std::uint64_t& expand)
{
    return expand;
}

std::uint64_t Definition<std::uint32_t, 2>::
    ExpandNegationValue(const std::uint64_t& expand)
{
    return 0x00000000ffffffff & ~expand;
}

std::uint32_t Definition<std::uint32_t, 2>::
    ExpandElementValue(const std::uint64_t& expand_split)
{
    return 0x00000000ffffffff & expand_split;
}

std::uint32_t Definition<std::uint32_t, 2>::
    ExpandCarryValue(const std::uint64_t& expand_split)
{
    return expand_split >> 32;
}

std::uint32_t Definition<std::uint32_t, 2>::
    LogElementValue(const std::uint32_t& v)
{
    if (v & 0x80000000) return 31;
    else if (v & 0x40000000) return 30;
    else if (v & 0x20000000) return 29;
    else if (v & 0x10000000) return 28;
    else if (v & 0x8000000) return 27;
    else if (v & 0x4000000) return 26;
    else if (v & 0x2000000) return 25;
    else if (v & 0x1000000) return 24;
    else if (v & 0x800000) return 23;
    else if (v & 0x400000) return 22;
    else if (v & 0x200000) return 21;
    else if (v & 0x100000) return 20;
    else if (v & 0x80000) return 19;
    else if (v & 0x40000) return 18;
    else if (v & 0x20000) return 17;
    else if (v & 0x10000) return 16;
    return Definition<std::uint16_t, 2>::LogElementValue(v);
}

std::uint32_t Definition<std::uint32_t, 2>::
    ShiftRightElementValue(const std::uint32_t& v, const std::size_t& n)
{
    return v >> n;
}

std::uint32_t Definition<std::uint32_t, 2>::
    ShiftLeftElementValue(const std::uint32_t& v, const std::size_t& n)
{
    return v << n;
}

std::uint32_t Definition<std::uint32_t, 2>::
    DigitElementValue(const std::uint32_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 32) return 0;
    else if (n > 32) _n = 32;
    return (v & ((0xffffffff >> (32 - _n)) << off)) >> off;
}

constexpr std::size_t Definition<std::uint32_t, 2>::
    AllocationSize(std::size_t n)
{
    return n * test::integer::fmt::Definition<std::uint32_t, 2>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint32_t, 2>::
        NMinSize;
}

template<typename TElement>
constexpr typename Definition<std::uint32_t, 2>::SizeType 
Definition<std::uint32_t, 2>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint32_t, 2>::ElementMaxExponent) /
            Definition<TElement, 2>::ElementMaxExponent) + 
        (((Definition<std::uint32_t, 2>::ElementMaxExponent * n) % 
            Definition<TElement, 2>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint32_t Definition<std::uint32_t, 2>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at == 0 ?  Definition<std::uint8_t, 2>::ElementMaxValue : 0;
}
        
constexpr std::uint32_t Definition<std::uint32_t, 2>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at == 0 ?  Definition<std::uint16_t, 2>::ElementMaxValue : 0;
}
    
constexpr std::uint32_t Definition<std::uint32_t, 2>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at == 0 ?  Definition<std::uint32_t, 2>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint32_t Definition<std::uint32_t, 2>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    return (std::uint32_t)(element >> at);
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint32_t, 2>::SizeType 
Definition<std::uint32_t, 2>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? n :
        NToBase == 8 ? ((107 * n) / 100) + ((107 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 10 ? ((108 * n) / 100) + ((108 * n) % 100 == 0 ? 0 : 1) : 0;
}

constexpr test::integer::Flag Definition<std::int32_t, 2>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kBinaryFormat};
}

constexpr test::integer::Flag Definition<std::uint8_t, 8>::Flag()
{
    return {test::integer::Flag::kOctalFormat};
}

std::uint16_t Definition<std::uint8_t, 8>::
    ExpandSplit(const std::uint16_t& expand)
{
    std::uint16_t carry = expand / 64;
    return expand < 64 ? expand : (carry << 8) | (expand - (carry * 64));
}

std::uint16_t Definition<std::uint8_t, 8>::
    ExpandNegationValue(const std::uint16_t& expand)
{
    return 0x3f - expand;
}

std::uint8_t Definition<std::uint8_t, 8>::
    ExpandElementValue(const std::uint16_t& expand_split)
{
    return (expand_split & 0x00ff);
}

std::uint8_t Definition<std::uint8_t, 8>::
    ExpandCarryValue(const std::uint16_t& expand_split)
{
    return (expand_split >> 8);
}

std::uint8_t Definition<std::uint8_t, 8>::
    LogElementValue(const std::uint8_t& v)
{
    if (v & 0x38) return 1;
    return 0;
}

constexpr std::size_t Definition<std::uint64_t, 2>::
    AllocationSize(std::size_t n)
{
    return n * test::integer::fmt::Definition<std::uint64_t, 2>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint64_t, 2>::
        NMinSize;
}

constexpr std::size_t Definition<std::int64_t, 2>::
    AllocationSize(std::size_t n)
{
    return n * test::integer::fmt::Definition<std::int64_t, 2>::
        ElementAllocSize * test::integer::fmt::Definition<std::int64_t, 2>::
        NMinSize;
}

std::uint8_t Definition<std::uint8_t, 8>::
    ShiftRightElementValue(const std::uint8_t& v, const std::size_t& n)
{
    return v >> (n * 3);
}

std::uint8_t Definition<std::uint8_t, 8>::
    ShiftLeftElementValue(const std::uint8_t& v, const std::size_t& n)
{
    return (v << (n * 3)) & 0x3f;
}

std::uint8_t Definition<std::uint8_t, 8>::
    DigitElementValue(const std::uint8_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 2) return 0;
    else if (n > 2) _n = 2;
    return (v & ((0x3f >> (6 - (_n * 3))) << (off * 3))) >> (off * 3);
}

constexpr std::size_t Definition<std::uint8_t, 8>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint8_t, 8>::ElementAllocSize *
        test::integer::fmt::Definition<std::uint8_t, 8>::NMinSize * n;
}

template<typename TElement>
constexpr typename Definition<std::uint8_t, 8>::SizeType 
Definition<std::uint8_t, 8>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint8_t, 8>::ElementMaxExponent) /
            Definition<TElement, 8>::ElementMaxExponent) + 
        (((Definition<std::uint8_t, 8>::ElementMaxExponent * n) % 
            Definition<TElement, 8>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint8_t Definition<std::uint8_t, 8>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 8>::ElementMaxValue : 0;
}
        
constexpr std::uint8_t Definition<std::uint8_t, 8>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 1 ? Definition<std::uint8_t, 8>::ElementMaxValue : 
        at == 2 ? 7 : 0;
}
    
constexpr std::uint8_t Definition<std::uint8_t, 8>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 4 ? Definition<std::uint8_t, 8>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint8_t Definition<std::uint8_t, 8>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    constexpr ExpandType max = 
        Definition<std::uint8_t, 8>::ElementMaxValue + 1;
    const ExpandType rshift1 = at <= 1 ? 1 : (at - 1) * max;
    const ExpandType rshift = at == 0 ? 1 : at * max;
    const ExpandType lshift = at == 0 ? 0 : max;
    return (std::uint8_t)((element / rshift1) - ((element / rshift) * lshift));
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint8_t, 8>::SizeType 
Definition<std::uint8_t, 8>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? ((76 * n) / 100) + ((76 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 8 ? n :
        NToBase == 10 ? ((91 * n) / 100) + ((91 * n) % 100 == 0 ? 0 : 1) : 0;
}

constexpr test::integer::Flag Definition<std::int8_t, 8>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kOctalFormat};
}

constexpr test::integer::Flag Definition<std::uint16_t, 8>::Flag()
{
    return {test::integer::Flag::kOctalFormat};
}

std::uint32_t Definition<std::uint16_t, 8>::
    ExpandSplit(const std::uint32_t& expand)
{
    std::uint32_t carry = expand / 0x8000;
    return expand < 0x8000 ? expand : (carry << 16) | 
        (expand - (carry * 0x8000));
}

std::uint32_t Definition<std::uint16_t, 8>::
    ExpandNegationValue(const std::uint32_t& expand)
{
    return 0x7fff - expand;
}

std::uint16_t Definition<std::uint16_t, 8>::
    ExpandElementValue(const std::uint32_t& expand_split)
{
    return (expand_split & 0x0000ffff);
}

std::uint16_t Definition<std::uint16_t, 8>::
    ExpandCarryValue(const std::uint32_t& expand_split)
{
    return (expand_split >> 16);
}

std::uint16_t Definition<std::uint16_t, 8>::
    LogElementValue(const std::uint16_t& v)
{
    if (v & 0x7000) return 4;
    else if (v & 0xe00) return 3;
    else if (v & 0x1c0) return 2;
    return Definition<std::uint8_t, 8>::LogElementValue(v);
}

std::uint16_t Definition<std::uint16_t, 8>::
    ShiftRightElementValue(const std::uint16_t& v, const std::size_t& n)
{
    return v >> (n * 3);
}

std::uint16_t Definition<std::uint16_t, 8>::
    ShiftLeftElementValue(const std::uint16_t& v, const std::size_t& n)
{
    return (v << (n * 3)) & 0x7fff;
}

std::uint16_t Definition<std::uint16_t, 8>::
    DigitElementValue(const std::uint16_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 5) return 0;
    else if (n > 5) _n = 5;
    return (v & ((0x7fff >> (15 - (_n * 3))) << (off * 3))) >> (off * 3);
}

constexpr std::size_t Definition<std::uint16_t, 8>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint16_t, 8>::ElementAllocSize *
        test::integer::fmt::Definition<std::uint16_t, 8>::NMinSize * n;
}

template<typename TElement>
constexpr typename Definition<std::uint16_t, 8>::SizeType 
Definition<std::uint16_t, 8>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint16_t, 8>::ElementMaxExponent) /
            Definition<TElement, 8>::ElementMaxExponent) + 
        (((Definition<std::uint16_t, 8>::ElementMaxExponent * n) % 
            Definition<TElement, 8>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint16_t Definition<std::uint16_t, 8>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 8>::ElementMaxValue : 0;
}
        
constexpr std::uint16_t Definition<std::uint16_t, 8>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint16_t, 8>::ElementMaxValue : 0;
}
    
constexpr std::uint16_t Definition<std::uint16_t, 8>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 1 ? Definition<std::uint16_t, 8>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint16_t Definition<std::uint16_t, 8>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    constexpr ExpandType max = 
        Definition<std::uint16_t, 8>::ElementMaxValue + 1;
    const ExpandType rshift1 = at <= 1 ? 1 : (at - 1) * max;
    const ExpandType rshift = at == 0 ? 1 : at * max;
    const ExpandType lshift = at == 0 ? 0 : max;
    return (std::uint16_t)((element / rshift1) - ((element / rshift) * lshift));
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint16_t, 8>::SizeType 
Definition<std::uint16_t, 8>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? ((94 * n) / 100) + ((94 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 8 ? n :
        NToBase == 10 ? ((113* n) / 100) + ((113 * n) % 100 == 0 ? 0 : 1) : 0;
}

constexpr test::integer::Flag Definition<std::int16_t, 8>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kOctalFormat};
}

constexpr test::integer::Flag Definition<std::uint32_t, 8>::Flag()
{
    return {test::integer::Flag::kOctalFormat};
}

std::uint64_t Definition<std::uint32_t, 8>::
    ExpandSplit(const std::uint64_t& expand)
{
    std::uint64_t carry = expand / 0x40000000;
    return expand < 0x40000000 ? expand : (carry << 32) | 
        (expand - (carry * 0x40000000));
}

std::uint64_t Definition<std::uint32_t, 8>::
    ExpandNegationValue(const std::uint64_t& expand)
{
    return 0x3fffffff - expand;
}

std::uint32_t Definition<std::uint32_t, 8>::
    ExpandElementValue(const std::uint64_t& expand_split)
{
    return (expand_split & 0x00000000ffffffff);
}

std::uint32_t Definition<std::uint32_t, 8>::
    ExpandCarryValue(const std::uint64_t& expand_split)
{
    return (expand_split >> 32);
}

std::uint32_t Definition<std::uint32_t, 8>::
    LogElementValue(const std::uint32_t& v)
{
    if (v & 0x38000000) return 9;
    else if (v & 0x7000000) return 8;
    else if (v & 0xe00000) return 7;
    else if (v & 0x1c0000) return 6;
    else if (v & 0x38000) return 5;
    return Definition<std::uint16_t, 8>::LogElementValue(v);
}

std::uint32_t Definition<std::uint32_t, 8>::
    ShiftRightElementValue(const std::uint32_t& v, const std::size_t& n)
{
    return v >> (n * 3);
}

std::uint32_t Definition<std::uint32_t, 8>::
    ShiftLeftElementValue(const std::uint32_t& v, const std::size_t& n)
{
    return (v << (n * 3)) & 0x3fffffff;
}

std::uint32_t Definition<std::uint32_t, 8>::
    DigitElementValue(const std::uint32_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 10) return 0;
    else if (n > 10) _n = 10;
    return (v & ((0x3fffffff >> (30 - (_n * 3))) << (off * 3))) >> (off * 3);
}

constexpr std::size_t Definition<std::uint32_t, 8>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint32_t, 8>::ElementAllocSize *
        test::integer::fmt::Definition<std::uint32_t, 8>::NMinSize * n;
}

template<typename TElement>
constexpr typename Definition<std::uint32_t, 8>::SizeType 
Definition<std::uint32_t, 8>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint32_t, 8>::ElementMaxExponent) /
            Definition<TElement, 8>::ElementMaxExponent) + 
        (((Definition<std::uint32_t, 8>::ElementMaxExponent * n) % 
            Definition<TElement, 8>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint32_t Definition<std::uint32_t, 8>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 8>::ElementMaxValue : 0;
}
        
constexpr std::uint32_t Definition<std::uint32_t, 8>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint16_t, 8>::ElementMaxValue : 0;
}
    
constexpr std::uint32_t Definition<std::uint32_t, 8>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint32_t, 8>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint32_t Definition<std::uint32_t, 8>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    constexpr ExpandType max = 
        Definition<std::uint32_t, 8>::ElementMaxValue + 1;
    const ExpandType rshift1 = at <= 1 ? 1 : (at - 1) * max;
    const ExpandType rshift = at == 0 ? 1 : at * max;
    const ExpandType lshift = at == 0 ? 0 : max;
    return (std::uint32_t)((element / rshift1) - ((element / rshift) * lshift));
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint32_t, 8>::SizeType 
Definition<std::uint32_t, 8>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? ((94 * n) / 100) + ((94 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 8 ? n :
        NToBase == 10 ? ((101* n) / 100) + ((101 * n) % 100 == 0 ? 0 : 1) : 0;
}

constexpr test::integer::Flag Definition<std::int32_t, 8>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kOctalFormat};
}

constexpr std::size_t Definition<std::uint64_t, 8>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint64_t, 8>::ElementAllocSize *
        test::integer::fmt::Definition<std::uint64_t, 8>::NMinSize * n;
}

constexpr std::size_t Definition<std::int64_t, 8>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::int64_t, 8>::ElementAllocSize *
        test::integer::fmt::Definition<std::int64_t, 8>::NMinSize * n;
}

constexpr test::integer::Flag Definition<std::uint8_t, 10>::Flag()
{
    return {test::integer::Flag::kDecimalFormat};
}

std::uint16_t Definition<std::uint8_t, 10>::
    ExpandSplit(const std::uint16_t& expand)
{
    std::uint16_t carry = expand / 100;
    return expand < 100 ? expand : (carry << 8) | (expand - (carry * 100));
}

std::uint16_t Definition<std::uint8_t, 10>::
    ExpandNegationValue(const std::uint16_t& expand)
{
    return (99 - expand);
}

std::uint8_t Definition<std::uint8_t, 10>::
    ExpandElementValue(const std::uint16_t& expand_split)
{
    return (expand_split & 0x00ff);
}

std::uint8_t Definition<std::uint8_t, 10>::
    ExpandCarryValue(const std::uint16_t& expand_split)
{
    return (expand_split >> 8);
}

std::uint8_t Definition<std::uint8_t, 10>::
    LogElementValue(const std::uint8_t& v)
{
    if (v > 9) return 1;
    return 0;
}

std::uint8_t Definition<std::uint8_t, 10>::
    ShiftRightElementValue(const std::uint8_t& v, const std::size_t& n)
{
    if (n >= 2) return 0;
    else if (n == 0) return v;
    std::uint8_t div = v;
    for (std::size_t i = 0; i < n; ++i) div /= 10;
    return div;
}

std::uint8_t Definition<std::uint8_t, 10>::
    ShiftLeftElementValue(const std::uint8_t& v, const std::size_t& n)
{
    if (n >= 2) return 0;
    else if (n == 0) return v;
    std::uint16_t mul = v;
    for (std::size_t i = 0; i < n; ++i) mul *= 10;
    if (mul > 99) return mul - ((mul / 100) * 100);
    return mul;
}

std::uint8_t Definition<std::uint8_t, 10>::
    DigitElementValue(const std::uint8_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 2) return 0;
    else if (n > 2) _n = 2 - off;
    std::uint16_t div = v, pwr = 1;
    for (std::size_t i = 0; i < off; ++i) div /= 10;
    for (std::size_t i = 0; i < _n; ++i) pwr *= 10;
    if (div > (pwr - 1)) return div - ((div / pwr) * pwr);
    return div;
}

constexpr std::size_t Definition<std::uint8_t, 10>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint8_t, 10>::ElementAllocSize *
        test::integer::fmt::Definition<std::uint8_t, 10>::NMinSize * n;
}

template<typename TElement>
constexpr typename Definition<std::uint8_t, 10>::SizeType 
Definition<std::uint8_t, 10>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint8_t, 10>::ElementMaxExponent) /
            Definition<TElement, 10>::ElementMaxExponent) + 
        (((Definition<std::uint8_t, 10>::ElementMaxExponent * n) % 
            Definition<TElement, 10>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint8_t Definition<std::uint8_t, 10>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 10>::ElementMaxValue : 0;
}
        
constexpr std::uint8_t Definition<std::uint8_t, 10>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 1 ? Definition<std::uint8_t, 10>::ElementMaxValue : 0;
}
    
constexpr std::uint8_t Definition<std::uint8_t, 10>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 3 ? Definition<std::uint8_t, 10>::ElementMaxValue : 
        at == 4 ? 9 : 0;
}
    
template<typename TElement>
std::uint8_t Definition<std::uint8_t, 10>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    constexpr ExpandType max = 
        Definition<std::uint8_t, 10>::ElementMaxValue + 1;
    const ExpandType rshift1 = at <= 1 ? 1 : (at - 1) * max;
    const ExpandType rshift = at == 0 ? 1 : at * max;
    const ExpandType lshift = at == 0 ? 0 : max;
    return (std::uint8_t)((element / rshift1) - ((element / rshift) * lshift));
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint8_t, 10>::SizeType 
Definition<std::uint8_t, 10>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? ((84 * n) / 100) + ((84 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 8 ? ((111* n) / 100) + ((111 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 10 ? n : 0;
}

constexpr test::integer::Flag Definition<std::int8_t, 10>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kDecimalFormat};
}

constexpr test::integer::Flag Definition<std::uint16_t, 10>::Flag()
{
    return {test::integer::Flag::kDecimalFormat};
}

std::uint32_t Definition<std::uint16_t, 10>::
    ExpandSplit(const std::uint32_t& expand)
{
    std::uint32_t carry = expand / 10000;
    return expand < 10000 ? expand : (carry << 16) | 
        (expand - (carry * 10000));
}

std::uint32_t Definition<std::uint16_t, 10>::
    ExpandNegationValue(const std::uint32_t& expand)
{
    return (9999 - expand);
}

std::uint16_t Definition<std::uint16_t, 10>::
    ExpandElementValue(const std::uint32_t& expand_split)
{
    return (expand_split & 0x0000ffff);
}

std::uint16_t Definition<std::uint16_t, 10>::
    ExpandCarryValue(const std::uint32_t& expand_split)
{
    return (expand_split >> 16);
}

std::uint16_t Definition<std::uint16_t, 10>::
    LogElementValue(const std::uint16_t& v)
{
    if (v > 999) return 3;
    else if (v > 99) return 2;
    return Definition<std::uint8_t, 10>::LogElementValue(v);
}

std::uint16_t Definition<std::uint16_t, 10>::
    ShiftRightElementValue(const std::uint16_t& v, const std::size_t& n)
{
    if (n >= 4) return 0;
    else if (n == 0) return v;
    std::uint16_t div = v;
    for (std::size_t i = 0; i < n; ++i) div /= 10;
    return div;
}

std::uint16_t Definition<std::uint16_t, 10>::
    ShiftLeftElementValue(const std::uint16_t& v, const std::size_t& n)
{
    if (n >= 4) return 0;
    else if (n == 0) return v;
    std::uint32_t mul = v;
    for (std::size_t i = 0; i < n; ++i) mul *= 10;
    if (mul > 9999) return mul - ((mul / 10000) * 10000);
    return mul;
}

std::uint16_t Definition<std::uint16_t, 10>::
    DigitElementValue(const std::uint16_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 4) return 0;
    else if (n > 4) _n = 4 - off;
    std::uint32_t div = v, pwr = 1;
    for (std::size_t i = 0; i < off; ++i) div /= 10;
    for (std::size_t i = 0; i < _n; ++i) pwr *= 10;
    if (div > (pwr - 1)) return div - ((div / pwr) * pwr);
    return div;
}

constexpr std::size_t Definition<std::uint16_t, 10>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint16_t, 10>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint16_t, 10>::
        NMinSize * n;
}

template<typename TElement>
constexpr typename Definition<std::uint16_t, 10>::SizeType 
Definition<std::uint16_t, 10>::ElementResize(const std::size_t& n)
{
    return ((n * Definition<std::uint16_t, 10>::ElementMaxExponent) /
            Definition<TElement, 10>::ElementMaxExponent) + 
        (((Definition<std::uint16_t, 10>::ElementMaxExponent * n) % 
            Definition<TElement, 10>::ElementMaxExponent) == 0 ? 0 : 1);
}

constexpr std::uint16_t Definition<std::uint16_t, 10>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 10>::ElementMaxValue : 0;
}
        
constexpr std::uint16_t Definition<std::uint16_t, 10>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint16_t, 10>::ElementMaxValue : 0;
}
    
constexpr std::uint16_t Definition<std::uint16_t, 10>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 1 ? Definition<std::uint16_t, 10>::ElementMaxValue : 
        at == 2 ? 9 : 0;
}
    
template<typename TElement>
std::uint16_t Definition<std::uint16_t, 10>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    constexpr ExpandType max = 
        Definition<std::uint16_t, 10>::ElementMaxValue + 1;
    const ExpandType rshift1 = at <= 1 ? 1 : (at - 1) * max;
    const ExpandType rshift = at == 0 ? 1 : at * max;
    const ExpandType lshift = at == 0 ? 0 : max;
    return (std::uint16_t)((element / rshift1) - ((element / rshift) * lshift));
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint16_t, 10>::SizeType 
Definition<std::uint16_t, 10>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? ((84 * n) / 100) + ((84 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 8 ? ((89* n) / 100) + ((89 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 10 ? n : 0;
}

constexpr test::integer::Flag Definition<std::int16_t, 10>::Flag()
{   
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kDecimalFormat};
}

constexpr test::integer::Flag Definition<std::uint32_t, 10>::Flag()
{
    return {test::integer::Flag::kDecimalFormat};
}

std::uint64_t Definition<std::uint32_t, 10>::
    ExpandSplit(const std::uint64_t& expand)
{
    std::uint64_t carry = expand / 1000000000ul;
    return expand < 1000000000ul ? expand : (carry << 32) | 
        (expand - (carry * 1000000000ul));
}

std::uint64_t Definition<std::uint32_t, 10>::
    ExpandNegationValue(const std::uint64_t& expand)
{
    return (999999999ul - expand);
}

std::uint32_t Definition<std::uint32_t, 10>::
    ExpandElementValue(const std::uint64_t& expand_split)
{
    return (expand_split & 0x00000000ffffffff);
}

std::uint32_t Definition<std::uint32_t, 10>::
    ExpandCarryValue(const std::uint64_t& expand_split)
{
    return (expand_split >> 32);
}

std::uint32_t Definition<std::uint32_t, 10>::
    LogElementValue(const std::uint32_t& v)
{
    if (v > 99999999ul) return 8;
    else if (v > 9999999ul) return 7;
    else if (v > 999999ul) return 6;
    else if (v > 99999ul) return 5;
    else if (v > 9999ul) return 4;
    return Definition<std::uint16_t, 10>::LogElementValue(std::uint16_t(v));
}

std::uint32_t Definition<std::uint32_t, 10>::
    ShiftRightElementValue(const std::uint32_t& v, const std::size_t& n)
{
    if (n >= 9) return 0;
    else if (n == 0) return v;
    std::uint32_t div = v;
    for (std::size_t i = 0; i < n; ++i) div /= 10;
    return div;
}

std::uint32_t Definition<std::uint32_t, 10>::
    ShiftLeftElementValue(const std::uint32_t& v, const std::size_t& n)
{
    if (n >= 9) return 0;
    else if (n == 0) return v;
    std::uint64_t mul = v;
    for (std::size_t i = 0; i < n; ++i) mul *= 10;
    if (mul > 999999999ull) return mul - ((mul / 1000000000) * 1000000000);
    return mul;
}

std::uint32_t Definition<std::uint32_t, 10>::
    DigitElementValue(const std::uint32_t& v, const std::size_t& off, 
        const std::size_t& n)
{
    std::size_t _n = n;
    if (n == 0 || off >= 9) return 0;
    else if (n > 9) _n = 9 - off;
    std::uint64_t div = v, pwr = 1;
    for (std::size_t i = 0; i < off; ++i) div /= 10;
    for (std::size_t i = 0; i < _n; ++i) pwr *= 10;
    if (div > (pwr - 1)) return div - ((div / pwr) * pwr);
    return div;
}

constexpr std::size_t Definition<std::uint32_t, 10>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint32_t, 10>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint32_t, 10>::
        NMinSize * n;
}

template<typename TElement>
constexpr typename Definition<std::uint32_t, 10>::SizeType 
Definition<std::uint32_t, 10>::ElementResize(const std::size_t& n)
{
    return (((n * Definition<std::uint32_t, 10>::ElementMaxExponent) /
            Definition<TElement, 10>::ElementMaxExponent) + 
        (((Definition<std::uint32_t, 10>::ElementMaxExponent * n) % 
            Definition<TElement, 10>::ElementMaxExponent) == 0 ? 0 : 1));
}

constexpr std::uint32_t Definition<std::uint32_t, 10>::
    ElementMaxValueAt(const std::uint8_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint8_t, 10>::ElementMaxValue : 0;
}
        
constexpr std::uint32_t Definition<std::uint32_t, 10>::
    ElementMaxValueAt(const std::uint16_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint16_t, 10>::ElementMaxValue : 0;
}
    
constexpr std::uint32_t  Definition<std::uint32_t, 10>::
    ElementMaxValueAt(const std::uint32_t&, const SizeType& at)
{
    return at <= 0 ? Definition<std::uint32_t, 10>::ElementMaxValue : 0;
}
    
template<typename TElement>
std::uint32_t Definition<std::uint32_t, 10>::
    ElementValueAt(const TElement& element, const SizeType& at)
{
    constexpr ExpandType max = 
        Definition<std::uint32_t, 10>::ElementMaxValue + 1;
    const ExpandType rshift1 = at <= 1 ? 1 : (at - 1) * max;
    const ExpandType rshift = at == 0 ? 1 : at * max;
    const ExpandType lshift = at == 0 ? 0 : max;
    return (std::uint32_t)((element / rshift1) - ((element / rshift) * lshift));
}

template<std::size_t NToBase>
constexpr typename Definition<std::uint32_t, 10>::SizeType 
Definition<std::uint32_t, 10>::ElementBaseResize(const std::size_t& n)
{
    static_assert((NToBase == 2 || NToBase == 8 || NToBase == 10),
        "Require base implementation");
    return NToBase == 2 ? ((94 * n) / 100) + ((94 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 8 ? ((100* n) / 100) + ((100 * n) % 100 == 0 ? 0 : 1) :
        NToBase == 10 ? n : 0;
}

constexpr test::integer::Flag Definition<std::int32_t, 10>::Flag()
{
    return {test::integer::Flag::kSigned | 
        test::integer::Flag::kDecimalFormat};
}

constexpr std::size_t Definition<std::uint64_t, 10>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::uint64_t, 10>::
        ElementAllocSize * test::integer::fmt::Definition<std::uint64_t, 10>::
        NMinSize * n;
}

constexpr std::size_t Definition<std::int64_t, 10>::
    AllocationSize(std::size_t n)
{
    return test::integer::fmt::Definition<std::int64_t, 10>::ElementAllocSize *
        test::integer::fmt::Definition<std::int64_t, 10>::NMinSize * n;
}

} //!fmt

} //!integer

} //!test

#endif //!TEST_INTEGER_FMT_DEFINITION_H_
