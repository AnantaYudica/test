#include "test/math/integer/fmt/Trait.h"

#include <type_traits>
#include <cstdint>
#include <cassert>

#include "../Format.test.h"

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

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == false));

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
        assert((Trait1::HasShiftRightElementValueFunction == true));
        assert((Trait1::HasShiftLeftElementValueFunction == true));
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
        assert((Trait1::IsSameShiftRightElementValueFunction == true));
        assert((Trait1::IsSameShiftLeftElementValueFunction == true));

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

        assert(Trait1::ExpandNegationValue(1) == 254);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 6);
        assert(Trait1::LogElementValue(255) == 7);

        assert(Trait1::ShiftRightElementValue(128, 1) == 64);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 2);

        assert(Trait1::Size == 2);

        assert(Trait1::GetElement(f1, 0) == 0);
        assert(Trait1::GetElement(f1, 1) == 0);
        
        assert(Trait1::SetElement(f1, 0, 1) == 1);
        assert(Trait1::SetElement(f1, 1, 2) == 2);
        
        assert(Trait1::GetElement(f1, 0) == 1);
        assert(Trait1::GetElement(f1, 1) == 2);
    }
    { 
        typedef Format<2, Bin> Format1Type;
        typedef Format<3, Bin> Format2Type;
        typedef Format<4, Bin> Format3Type;
        typedef Format<5, Bin> Format4Type;
        typedef test::math::integer::fmt::Trait<Format1Type,
            Format2Type, Format3Type, Format4Type> Trait1;
        Format1Type f1;

        assert((std::is_same<typename Format1Type::ElementType, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<typename Format1Type::ExpandType, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<typename Format1Type::SizeType, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == false));

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
        assert((Trait1::HasShiftRightElementValueFunction == true));
        assert((Trait1::HasShiftLeftElementValueFunction == true));
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
        assert((Trait1::IsSameShiftRightElementValueFunction == true));
        assert((Trait1::IsSameShiftLeftElementValueFunction == true));

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

        assert(Trait1::ExpandNegationValue(1) == 254);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 6);
        assert(Trait1::LogElementValue(255) == 7);

        assert(Trait1::ShiftRightElementValue(128, 1) == 64);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 2);

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

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == false));

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
        assert((Trait1::HasShiftRightElementValueFunction == true));
        assert((Trait1::HasShiftLeftElementValueFunction == true));
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
        assert((Trait1::IsSameShiftRightElementValueFunction == true));
        assert((Trait1::IsSameShiftLeftElementValueFunction == true));

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

        assert(Trait1::ExpandNegationValue(1) == 8);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(4) == 0);
        assert(Trait1::LogElementValue(9) == 0);
        
        assert(Trait1::ShiftRightElementValue(2, 1) == 0);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 0);

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
        typedef Format<3, Dec> Format2Type;
        typedef Format<4, Dec> Format3Type;
        typedef Format<5, Dec> Format4Type;
        typedef test::math::integer::fmt::Trait<Format1Type,
            Format2Type, Format3Type, Format4Type> Trait1;
        Format1Type f1;

        assert((std::is_same<typename Format1Type::ElementType, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<typename Format1Type::ExpandType, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<typename Format1Type::SizeType, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == false));

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
        assert((Trait1::HasShiftRightElementValueFunction == true));
        assert((Trait1::HasShiftLeftElementValueFunction == true));
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
        assert((Trait1::IsSameShiftRightElementValueFunction == true));
        assert((Trait1::IsSameShiftLeftElementValueFunction == true));

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

        assert(Trait1::ExpandNegationValue(1) == 8);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(4) == 0);
        assert(Trait1::LogElementValue(9) == 0);
        
        assert(Trait1::ShiftRightElementValue(2, 1) == 0);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 0);

        assert(Trait1::Size == 2);

        assert(Trait1::GetElement(f1, 0) == 0);
        assert(Trait1::GetElement(f1, 1) == 0);
        
        assert(Trait1::SetElement(f1, 0, 1) == 1);
        assert(Trait1::SetElement(f1, 1, 2) == 2);
        
        assert(Trait1::GetElement(f1, 0) == 1);
        assert(Trait1::GetElement(f1, 1) == 2);
    }    
    { 
        typedef test::math::integer::fmt::Trait<void> Trait1;
        
        assert((std::is_same<int, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == true));

        assert((Trait1::Has == false));

        assert((Trait1::HasElementType == false));
        assert((Trait1::HasExpandType == false));
        assert((Trait1::HasSizeType == false));

        assert((Trait1::HasConstantSize == false));
        assert((Trait1::HasConstantElementMaxExponent == false));

        assert((Trait1::HasExpandSplitFunction == false));
        assert((Trait1::HasExpandNegationValueFunction == false));
        assert((Trait1::HasExpandElementValueFunction == false));
        assert((Trait1::HasExpandCarryValueFunction == false));
        assert((Trait1::HasLogElementValueFunction == false));
        assert((Trait1::HasShiftRightElementValueFunction == false));
        assert((Trait1::HasShiftLeftElementValueFunction == false));
        assert((Trait1::HasGetElementFunction == false));
        assert((Trait1::HasSetElementFunction == false));

        assert((Trait1::IsSame == false));

        assert((Trait1::IsSameElementType == false));
        assert((Trait1::IsSameExpandType == false));
        assert((Trait1::IsSameSizeType == false));

        assert((Trait1::IsSameConstantElementMaxExponent == false));

        assert((Trait1::IsSameExpandSplitFunction == false));
        assert((Trait1::IsSameExpandNegationValueFunction == false));
        assert((Trait1::IsSameExpandElementValueFunction == false));
        assert((Trait1::IsSameExpandCarryValueFunction == false));
        assert((Trait1::IsSameLogElementValueFunction == false));
        assert((Trait1::IsSameShiftRightElementValueFunction == false));
        assert((Trait1::IsSameShiftLeftElementValueFunction == false));

        assert((Trait1::Size == 0));
        assert((Trait1::ElementMaxExponent == 0));

        assert(Trait1::ExpandSplit(0) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(0)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(0)) == 0);
        
        assert(Trait1::ExpandSplit(255) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(255)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(255)) == 0);
        
        assert(Trait1::ExpandSplit(65280) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(65280)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(65280)) == 0);

        assert(Trait1::ExpandNegationValue(1) == 0);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 0);
        assert(Trait1::LogElementValue(255) == 0);

        assert(Trait1::ShiftRightElementValue(128, 1) == 0);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 0);

        assert(Trait1::Size == 0);

        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
        
        assert(Trait1::SetElement(0, 0, 1) == 0);
        assert(Trait1::SetElement(0, 1, 2) == 0);
        
        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
    }   
    { 
        typedef test::math::integer::fmt::Trait<void, void> Trait1;
        
        
        assert((std::is_same<int, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == true));

        assert((Trait1::Has == false));

        assert((Trait1::HasElementType == false));
        assert((Trait1::HasExpandType == false));
        assert((Trait1::HasSizeType == false));

        assert((Trait1::HasConstantSize == false));
        assert((Trait1::HasConstantElementMaxExponent == false));

        assert((Trait1::HasExpandSplitFunction == false));
        assert((Trait1::HasExpandNegationValueFunction == false));
        assert((Trait1::HasExpandElementValueFunction == false));
        assert((Trait1::HasExpandCarryValueFunction == false));
        assert((Trait1::HasLogElementValueFunction == false));
        assert((Trait1::HasShiftRightElementValueFunction == false));
        assert((Trait1::HasShiftLeftElementValueFunction == false));
        assert((Trait1::HasGetElementFunction == false));
        assert((Trait1::HasSetElementFunction == false));

        assert((Trait1::IsSame == false));

        assert((Trait1::IsSameElementType == false));
        assert((Trait1::IsSameExpandType == false));
        assert((Trait1::IsSameSizeType == false));

        assert((Trait1::IsSameConstantElementMaxExponent == false));

        assert((Trait1::IsSameExpandSplitFunction == false));
        assert((Trait1::IsSameExpandNegationValueFunction == false));
        assert((Trait1::IsSameExpandElementValueFunction == false));
        assert((Trait1::IsSameExpandCarryValueFunction == false));
        assert((Trait1::IsSameLogElementValueFunction == false));
        assert((Trait1::IsSameShiftRightElementValueFunction == false));
        assert((Trait1::IsSameShiftLeftElementValueFunction == false));

        assert((Trait1::Size == 0));
        assert((Trait1::ElementMaxExponent == 0));

        assert(Trait1::ExpandSplit(0) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(0)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(0)) == 0);
        
        assert(Trait1::ExpandSplit(255) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(255)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(255)) == 0);
        
        assert(Trait1::ExpandSplit(65280) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(65280)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(65280)) == 0);

        assert(Trait1::ExpandNegationValue(1) == 0);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 0);
        assert(Trait1::LogElementValue(255) == 0);

        assert(Trait1::ShiftRightElementValue(128, 1) == 0);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 0);

        assert(Trait1::Size == 0);

        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
        
        assert(Trait1::SetElement(0, 0, 1) == 0);
        assert(Trait1::SetElement(0, 1, 2) == 0);
        
        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
    }
    { 
        typedef Format<2, Bin> Format1Type;
        typedef test::math::integer::fmt::Trait<Format1Type, void> Trait1;
        
        
        assert((std::is_same<int, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == true));

        assert((Trait1::Has == false));

        assert((Trait1::HasElementType == false));
        assert((Trait1::HasExpandType == false));
        assert((Trait1::HasSizeType == false));

        assert((Trait1::HasConstantSize == false));
        assert((Trait1::HasConstantElementMaxExponent == false));

        assert((Trait1::HasExpandSplitFunction == false));
        assert((Trait1::HasExpandNegationValueFunction == false));
        assert((Trait1::HasExpandElementValueFunction == false));
        assert((Trait1::HasExpandCarryValueFunction == false));
        assert((Trait1::HasLogElementValueFunction == false));
        assert((Trait1::HasShiftRightElementValueFunction == false));
        assert((Trait1::HasShiftLeftElementValueFunction == false));
        assert((Trait1::HasGetElementFunction == false));
        assert((Trait1::HasSetElementFunction == false));

        assert((Trait1::IsSame == false));

        assert((Trait1::IsSameElementType == false));
        assert((Trait1::IsSameExpandType == false));
        assert((Trait1::IsSameSizeType == false));

        assert((Trait1::IsSameConstantElementMaxExponent == false));

        assert((Trait1::IsSameExpandSplitFunction == false));
        assert((Trait1::IsSameExpandNegationValueFunction == false));
        assert((Trait1::IsSameExpandElementValueFunction == false));
        assert((Trait1::IsSameExpandCarryValueFunction == false));
        assert((Trait1::IsSameLogElementValueFunction == false));
        assert((Trait1::IsSameShiftRightElementValueFunction == false));
        assert((Trait1::IsSameShiftLeftElementValueFunction == false));

        assert((Trait1::Size == 0));
        assert((Trait1::ElementMaxExponent == 0));

        assert(Trait1::ExpandSplit(0) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(0)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(0)) == 0);
        
        assert(Trait1::ExpandSplit(255) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(255)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(255)) == 0);
        
        assert(Trait1::ExpandSplit(65280) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(65280)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(65280)) == 0);

        assert(Trait1::ExpandNegationValue(1) == 0);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 0);
        assert(Trait1::LogElementValue(255) == 0);

        assert(Trait1::ShiftRightElementValue(128, 1) == 0);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 0);

        assert(Trait1::Size == 0);

        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
        
        assert(Trait1::SetElement(0, 0, 1) == 0);
        assert(Trait1::SetElement(0, 1, 2) == 0);
        
        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
    }
    { 
        typedef Format<2, Bin> Format1Type;
        typedef Format<2, Dec> Format2Type;
        typedef test::math::integer::fmt::Trait<Format1Type, Format2Type> Trait1;
        
        
        assert((std::is_same<int, 
            typename Trait1::ElementType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::ExpandType>::value) == true);
        assert((std::is_same<int, 
            typename Trait1::SizeType>::value) == true);

        assert((Trait1::IsDefault == false));
        assert((Trait1::IsInvalid == true));

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
        assert((Trait1::HasShiftRightElementValueFunction == true));
        assert((Trait1::HasShiftLeftElementValueFunction == true));
        assert((Trait1::HasGetElementFunction == true));
        assert((Trait1::HasSetElementFunction == true));

        assert((Trait1::IsSame == false));

        assert((Trait1::IsSameElementType == true));
        assert((Trait1::IsSameExpandType == true));
        assert((Trait1::IsSameSizeType == true));

        assert((Trait1::IsSameConstantElementMaxExponent == false));

        assert((Trait1::IsSameExpandSplitFunction == false));
        assert((Trait1::IsSameExpandNegationValueFunction == false));
        assert((Trait1::IsSameExpandElementValueFunction == false));
        assert((Trait1::IsSameExpandCarryValueFunction == false));
        assert((Trait1::IsSameLogElementValueFunction == false));
        assert((Trait1::IsSameShiftRightElementValueFunction == false));
        assert((Trait1::IsSameShiftLeftElementValueFunction == false));

        assert((Trait1::Size == 0));
        assert((Trait1::ElementMaxExponent == 0));

        assert(Trait1::ExpandSplit(0) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(0)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(0)) == 0);
        
        assert(Trait1::ExpandSplit(255) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(255)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(255)) == 0);
        
        assert(Trait1::ExpandSplit(65280) == 0);
        assert(Trait1::ExpandElementValue(Trait1::ExpandSplit(65280)) == 0);
        assert(Trait1::ExpandCarryValue(Trait1::ExpandSplit(65280)) == 0);

        assert(Trait1::ExpandNegationValue(1) == 0);

        assert(Trait1::LogElementValue(1) == 0);
        assert(Trait1::LogElementValue(127) == 0);
        assert(Trait1::LogElementValue(255) == 0);

        assert(Trait1::ShiftRightElementValue(128, 1) == 0);
        assert(Trait1::ShiftLeftElementValue(1, 1) == 0);

        assert(Trait1::Size == 0);

        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
        
        assert(Trait1::SetElement(0, 0, 1) == 0);
        assert(Trait1::SetElement(0, 1, 2) == 0);
        
        assert(Trait1::GetElement(0, 0) == 0);
        assert(Trait1::GetElement(0, 1) == 0);
    }
    return 0;
}
