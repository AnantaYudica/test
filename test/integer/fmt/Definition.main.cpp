#include "test/integer/fmt/Definition.h"

#include <cstdint>
#include <cassert>
#include <type_traits>
#include <utility>

int main()
{
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint8_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint8_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint16_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint8_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint8_t));
        assert(DefType::ElementMaxExponent == 8);
        assert(DefType::ElementMaxValue == 0xff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == false);

        assert(DefType::ExpandSplit(0xffff) == 0xffff);
        assert(DefType::ExpandSplit(0x00ff) == 0x00ff);
        assert(DefType::ExpandSplit(0xff00) == 0xff00);
        assert(DefType::ExpandSplit(0x0ff0) == 0x0ff0);

        assert(DefType::ExpandNegationValue(0x00ff) == 0);
        assert(DefType::ExpandNegationValue(0x0001) == 0x00fe);
        assert(DefType::ExpandNegationValue(0x0080) == 0x007f);

        assert(DefType::ExpandElementValue(0xffff) == 0xff);
        assert(DefType::ExpandElementValue(0xff00) == 0x00);
        assert(DefType::ExpandElementValue(0x0ff0) == 0xf0);

        assert(DefType::ExpandCarryValue(0xffff) == 0xff);
        assert(DefType::ExpandCarryValue(0xff00) == 0xff);
        assert(DefType::ExpandCarryValue(0x0ff0) == 0x0f);
        
        assert(DefType::LogElementValue(0x00) == 0);
        assert(DefType::LogElementValue(0x01) == 0);
        assert(DefType::LogElementValue(0x0f) == 3);
        assert(DefType::LogElementValue(0xff) == 7);
        
        assert(DefType::ShiftRightElementValue(0x00, 1) == 0);
        assert(DefType::ShiftRightElementValue(0x0f, 2) == 3);
        assert(DefType::ShiftRightElementValue(0xf0, 2) == 0x3c);
        assert(DefType::ShiftRightElementValue(0xf0, 4) == 0x0f);

        assert(DefType::ShiftLeftElementValue(0x00, 1) == 0);
        assert(DefType::ShiftLeftElementValue(0x0f, 2) == 0x3c);
        assert(DefType::ShiftLeftElementValue(0xf0, 2) == 0xc0);
        assert(DefType::ShiftLeftElementValue(0xf0, 4) == 0);

        assert(DefType::DigitElementValue(0xf1, 0) == 1);
        assert(DefType::DigitElementValue(0x7e, 1, 4) == 0x0f);
        assert(DefType::DigitElementValue(0x08, 3) == 1);
        assert(DefType::DigitElementValue(0x17, 4) == 1);
        assert(DefType::DigitElementValue(0x70, 3, 4) == 0x0e);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int8_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint8_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint16_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint8_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint8_t));
        assert(DefType::ElementMaxExponent == 8);
        assert(DefType::ElementMaxValue == 0xff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint8_t, 2> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint16_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint16_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint32_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint16_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint16_t));
        assert(DefType::ElementMaxExponent == 16);
        assert(DefType::ElementMaxValue == 0xffff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        assert(DefType::ExpandSplit(0xffffffff) == 0xffffffff);
        assert(DefType::ExpandSplit(0x0000ffff) == 0x0000ffff);
        assert(DefType::ExpandSplit(0xffff0000) == 0xffff0000);
        assert(DefType::ExpandSplit(0x00ffff00) == 0x00ffff00);
        
        assert(DefType::ExpandNegationValue(0x0000ffff) == 0);
        assert(DefType::ExpandNegationValue(0x00000001) == 0x00fffe);
        assert(DefType::ExpandNegationValue(0x00008000) == 0x007fff);

        assert(DefType::ExpandElementValue(0xffffffff) == 0xffff);
        assert(DefType::ExpandElementValue(0xffff0000) == 0x00);
        assert(DefType::ExpandElementValue(0x00ffff00) == 0xff00);

        assert(DefType::ExpandCarryValue(0xffffffff) == 0xffff);
        assert(DefType::ExpandCarryValue(0xffff0000) == 0xffff);
        assert(DefType::ExpandCarryValue(0x00ffff00) == 0x00ff);
        
        assert(DefType::LogElementValue(0x0100) == 8);
        assert(DefType::LogElementValue(0x0200) == 9);
        assert(DefType::LogElementValue(0x0f00) == 11);
        assert(DefType::LogElementValue(0xffff) == 15);
        
        assert(DefType::ShiftRightElementValue(0x0000, 1) == 0);
        assert(DefType::ShiftRightElementValue(0xff00, 2) == 0x3fc0);
        assert(DefType::ShiftRightElementValue(0x0f00, 2) == 0x03c0);
        assert(DefType::ShiftRightElementValue(0x0f00, 4) == 0x00f0);

        assert(DefType::ShiftLeftElementValue(0x0000, 1) == 0);
        assert(DefType::ShiftLeftElementValue(0x0ff0, 2) == 0x3fc0);
        assert(DefType::ShiftLeftElementValue(0xf0f0, 2) == 0xc3c0);
        assert(DefType::ShiftLeftElementValue(0x0ff0, 4) == 0xff00);

        assert(DefType::DigitElementValue(0xfff1, 0) == 1);
        assert(DefType::DigitElementValue(0x0fff, 8, 4) == 0xf);
        assert(DefType::DigitElementValue(0xf7fe, 1, 8) == 0xff);
        assert(DefType::DigitElementValue(0xf200, 9) == 1);
        assert(DefType::DigitElementValue(0x8f00, 15) == 1);
        assert(DefType::DigitElementValue(0xff00, 5, 4) == 0x8);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int16_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint16_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint32_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint16_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint16_t));
        assert(DefType::ElementMaxExponent == 16);
        assert(DefType::ElementMaxValue == 0xffff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint16_t, 2> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint32_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 32);
        assert(DefType::ElementMaxValue == 0xffffffff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        assert(DefType::ExpandSplit(0xffffffffffffffff) == 0xffffffffffffffff);
        assert(DefType::ExpandSplit(0x00000000ffffffff) == 0x00000000ffffffff);
        assert(DefType::ExpandSplit(0xffffffff00000000) == 0xffffffff00000000);
        assert(DefType::ExpandSplit(0x0000ffffffff0000) == 0x0000ffffffff0000);

        
        assert(DefType::ExpandNegationValue(0x00000000ffffffff) == 0);
        assert(DefType::ExpandNegationValue(0x0000000000000001) == 
            0x00000000fffffffe);
        assert(DefType::ExpandNegationValue(0x0000000080000000) == 
            0x000000007fffffff);

        assert(DefType::ExpandElementValue(0xffffffffffffffff) == 0xffffffff);
        assert(DefType::ExpandElementValue(0xffffffff00000000) == 0x00);
        assert(DefType::ExpandElementValue(0x0000ffffffff0000) == 0xffff0000);

        assert(DefType::ExpandCarryValue(0xffffffffffffffff) == 0xffffffff);
        assert(DefType::ExpandCarryValue(0xffffffff00000000) == 0xffffffff);
        assert(DefType::ExpandCarryValue(0x0000ffffffff0000) == 0x0000ffff);
        
        assert(DefType::LogElementValue(0x00010000) == 16);
        assert(DefType::LogElementValue(0x00020000) == 17);
        assert(DefType::LogElementValue(0x00f00000) == 23);
        assert(DefType::LogElementValue(0xffff0000) == 31);
        
        assert(DefType::ShiftRightElementValue(0x00000000, 1) == 0);
        assert(DefType::ShiftRightElementValue(0xffff0000, 2) == 0x3fffc000);
        assert(DefType::ShiftRightElementValue(0x0ff00000, 2) == 0x03fc0000);
        assert(DefType::ShiftRightElementValue(0xf0f00000, 4) == 0x0f0f0000);

        assert(DefType::ShiftLeftElementValue(0x00000000, 1) == 0);
        assert(DefType::ShiftLeftElementValue(0x00ffff00, 2) == 0x03fffc00);
        assert(DefType::ShiftLeftElementValue(0x0f0f0000, 2) == 0x3c3c0000);
        assert(DefType::ShiftLeftElementValue(0x0fff0000, 4) == 0xfff00000);

        assert(DefType::DigitElementValue(0xfff00001, 0) == 1);
        assert(DefType::DigitElementValue(0x0f0f0000, 16, 4) == 0xf);
        assert(DefType::DigitElementValue(0xf7fe0000, 17, 8) == 0xff);
        assert(DefType::DigitElementValue(0xf2000000, 25) == 1);
        assert(DefType::DigitElementValue(0x8f000000, 31) == 1);
        assert(DefType::DigitElementValue(0xff000000, 21, 4) == 0x8);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int32_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 32);
        assert(DefType::ElementMaxValue == 0xffffffff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint32_t, 2> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint64_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 2);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 32);
        assert(DefType::ElementMaxValue == 0xffffffff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        typedef Definition<std::uint32_t, 2> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int64_t, 2> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 2);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 32);
        assert(DefType::ElementMaxValue == 0xffffffff);

        assert(DefType::Flag().IsBinaryFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint64_t, 2> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    ////
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint8_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint8_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint16_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint8_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint8_t));
        assert(DefType::ElementMaxExponent == 2);
        assert(DefType::ElementMaxValue == 0x3f);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);

        assert(DefType::ExpandSplit(00177) == 0x013f);
        assert(DefType::ExpandSplit(07007) == 0x3807);
        assert(DefType::ExpandSplit(07700) == 0x3f00);
        assert(DefType::ExpandSplit(00077) == 0x003f);

        assert(DefType::ExpandNegationValue(0) == 077);
        assert(DefType::ExpandNegationValue(001) == 076);
        assert(DefType::ExpandNegationValue(060) == 017);

        assert(DefType::ExpandElementValue(0x3f3f) == 0x3f);
        assert(DefType::ExpandElementValue(0x3f00) == 0x00);
        assert(DefType::ExpandElementValue(0x0738) == 0x38);

        assert(DefType::ExpandCarryValue(0x3f3f) == 0x3f);
        assert(DefType::ExpandCarryValue(0x3f00) == 0x3f);
        assert(DefType::ExpandCarryValue(0x0738) == 0x07);
        
        assert(DefType::LogElementValue(000) == 0);
        assert(DefType::LogElementValue(007) == 0);
        assert(DefType::LogElementValue(070) == 1);
        
        assert(DefType::ShiftRightElementValue(000, 1) == 0);
        assert(DefType::ShiftRightElementValue(007, 0) == 007);
        assert(DefType::ShiftRightElementValue(070, 1) == 007);
        assert(DefType::ShiftRightElementValue(070, 2) == 000);

        assert(DefType::ShiftLeftElementValue(000, 1) == 0);
        assert(DefType::ShiftLeftElementValue(070, 0) == 070);
        assert(DefType::ShiftLeftElementValue(007, 1) == 070);
        assert(DefType::ShiftLeftElementValue(070, 1) == 0);
        assert(DefType::ShiftLeftElementValue(007, 2) == 0);

        assert(DefType::DigitElementValue(001, 0) == 1);
        assert(DefType::DigitElementValue(071, 0, 2) == 071);
        assert(DefType::DigitElementValue(062, 1) == 6);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int8_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint8_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint16_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint8_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint8_t));
        assert(DefType::ElementMaxExponent == 2);
        assert(DefType::ElementMaxValue == 0x3f);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint8_t, 8> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint16_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint16_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint32_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint16_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint16_t));
        assert(DefType::ElementMaxExponent == 5);
        assert(DefType::ElementMaxValue == 0x7fff);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        assert(DefType::ExpandSplit(00000177777) == 0x17fff);
        assert(DefType::ExpandSplit(00000077777) == 0x7fff);
        assert(DefType::ExpandSplit(07777700000) == 0x7fff0000);
        assert(DefType::ExpandSplit(00077777000) == 0x01ff7e00);
        
        assert(DefType::ExpandNegationValue(0) == 077777);
        assert(DefType::ExpandNegationValue(1) == 077776);
        assert(DefType::ExpandNegationValue(050000) == 027777);

        assert(DefType::ExpandElementValue(0x7fff7fff) == 0x7fff);
        assert(DefType::ExpandElementValue(0x7fff0000) == 0x00);
        assert(DefType::ExpandElementValue(0x01ff7e00) == 0x7e00);

        assert(DefType::ExpandCarryValue(0x7fff7fff) == 0x7fff);
        assert(DefType::ExpandCarryValue(0x7fff0000) == 0x7fff);
        assert(DefType::ExpandCarryValue(0x01ff7e00) == 0x01ff);
        
        assert(DefType::LogElementValue(000000) == 0);
        assert(DefType::LogElementValue(000700) == 2);
        assert(DefType::LogElementValue(001700) == 3);
        assert(DefType::LogElementValue(041700) == 4);
        assert(DefType::LogElementValue(077777) == 4);
        
        assert(DefType::ShiftRightElementValue(000000, 1) == 0);
        assert(DefType::ShiftRightElementValue(007000, 3) == 000007);
        assert(DefType::ShiftRightElementValue(017600, 2) == 000176);
        assert(DefType::ShiftRightElementValue(017600, 4) == 000001);

        assert(DefType::ShiftLeftElementValue(000000, 1) == 0);
        assert(DefType::ShiftLeftElementValue(000070, 3) == 070000);
        assert(DefType::ShiftLeftElementValue(000671, 2) == 067100);
        assert(DefType::ShiftLeftElementValue(000671, 4) == 010000);

        assert(DefType::DigitElementValue(000001, 0) == 1);
        assert(DefType::DigitElementValue(012700, 2, 3) == 0127);
        assert(DefType::DigitElementValue(012340, 1, 4) == 01234);
        assert(DefType::DigitElementValue(050123, 4) == 05);
        assert(DefType::DigitElementValue(023400, 3, 3) == 0023);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int16_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint16_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint32_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint16_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint16_t));
        assert(DefType::ElementMaxExponent == 5);
        assert(DefType::ElementMaxValue == 0x7fff);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint16_t, 8> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint32_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 10);
        assert(DefType::ElementMaxValue == 0x3fffffff);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        assert(DefType::ExpandSplit(000000000017777777777) == 
            0x000000013fffffff);
        assert(DefType::ExpandSplit(000000000007777777777) == 
            0x000000003fffffff);
        assert(DefType::ExpandSplit(077777777770000000000) == 
            0x3fffffff00000000);
        assert(DefType::ExpandSplit(000000777777777700000) == 
            0x00007fff3fff8000);

        assert(DefType::ExpandNegationValue(0) == 07777777777);
        assert(DefType::ExpandNegationValue(1) == 07777777776);
        assert(DefType::ExpandNegationValue(05000010000) == 02777767777);

        assert(DefType::ExpandElementValue(0x3fffffff3fffffff) == 0x3fffffff);
        assert(DefType::ExpandElementValue(0x3fffffff00000000) == 0x00);
        assert(DefType::ExpandElementValue(0x00007fff3fff8000) == 0x3fff8000);

        assert(DefType::ExpandCarryValue(0x3fffffff3fffffff) == 0x3fffffff);
        assert(DefType::ExpandCarryValue(0x3fffffff00000000) == 0x3fffffff);
        assert(DefType::ExpandCarryValue(0x00007fff3fff8000) == 0x00007fff);
        
        assert(DefType::LogElementValue(00000200000) == 5);
        assert(DefType::LogElementValue(00001200000) == 6);
        assert(DefType::LogElementValue(00201200000) == 8);
        assert(DefType::LogElementValue(01201200000) == 9);
        
        assert(DefType::ShiftRightElementValue(00000000000, 1) == 0);
        assert(DefType::ShiftRightElementValue(00707070000, 2) == 00007070700);
        assert(DefType::ShiftRightElementValue(00000070770, 2) == 00000000707);
        assert(DefType::ShiftRightElementValue(07007000000, 9) == 00000000007);

        assert(DefType::ShiftLeftElementValue(00000000000, 1) == 0);
        assert(DefType::ShiftLeftElementValue(00000070770, 2) == 00007077000);
        assert(DefType::ShiftLeftElementValue(00707070000, 2) == 00707000000);
        assert(DefType::ShiftLeftElementValue(00000070777, 9) == 07000000000);

        assert(DefType::DigitElementValue(00000000001, 0) == 1);
        assert(DefType::DigitElementValue(07124000001, 6, 4) == 07124);
        assert(DefType::DigitElementValue(07124732001, 3, 5) == 024732);
        assert(DefType::DigitElementValue(00234232001, 8) == 2);
        assert(DefType::DigitElementValue(01700000000, 9) == 1);
        assert(DefType::DigitElementValue(00710100000, 5, 8) == 07101);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int32_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 10);
        assert(DefType::ElementMaxValue == 0x3fffffff);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint32_t, 8> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint64_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 2);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 10);
        assert(DefType::ElementMaxValue == 0x3fffffff);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        typedef Definition<std::uint32_t, 8> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int64_t, 8> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 2);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 10);
        assert(DefType::ElementMaxValue == 0x3fffffff);

        assert(DefType::Flag().IsOctalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint64_t, 8> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    ////
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint8_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint8_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint16_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint8_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint8_t));
        assert(DefType::ElementMaxExponent == 2);
        assert(DefType::ElementMaxValue == 99);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);

        assert(DefType::ExpandSplit(199) == 0x0163);
        assert(DefType::ExpandSplit(9009) == 0x5a09);
        assert(DefType::ExpandSplit(9900) == 0x6300);
        assert(DefType::ExpandSplit(99) == 0x0063);

        assert(DefType::ExpandNegationValue(0) == 99);
        assert(DefType::ExpandNegationValue(1) == 98);
        assert(DefType::ExpandNegationValue(60) == 39);

        assert(DefType::ExpandElementValue(0x6363) == 0x63);
        assert(DefType::ExpandElementValue(0x6300) == 0x00);
        assert(DefType::ExpandElementValue(0x095a) == 0x5a);

        assert(DefType::ExpandCarryValue(0x6363) == 0x63);
        assert(DefType::ExpandCarryValue(0x6300) == 0x63);
        assert(DefType::ExpandCarryValue(0x095a) == 0x09);
        
        assert(DefType::LogElementValue(0) == 0);
        assert(DefType::LogElementValue(8) == 0);
        assert(DefType::LogElementValue(11) == 1);
        
        assert(DefType::ShiftRightElementValue(0, 1) == 0);
        assert(DefType::ShiftRightElementValue(8, 0) == 8);
        assert(DefType::ShiftRightElementValue(60, 1) == 6);
        assert(DefType::ShiftRightElementValue(87, 2) == 0);

        assert(DefType::ShiftLeftElementValue(0, 1) == 0);
        assert(DefType::ShiftLeftElementValue(77, 0) == 77);
        assert(DefType::ShiftLeftElementValue(8, 1) == 80);
        assert(DefType::ShiftLeftElementValue(63, 1) == 30);
        assert(DefType::ShiftLeftElementValue(84, 2) == 0);

        assert(DefType::DigitElementValue(1, 0) == 1);
        assert(DefType::DigitElementValue(84, 0, 2) == 84);
        assert(DefType::DigitElementValue(62, 1) == 6);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int8_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint8_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint16_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint8_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint8_t));
        assert(DefType::ElementMaxExponent == 2);
        assert(DefType::ElementMaxValue == 99);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint8_t, 10> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint16_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint16_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint32_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint16_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint16_t));
        assert(DefType::ElementMaxExponent == 4);
        assert(DefType::ElementMaxValue == 9999);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        assert(DefType::ExpandSplit(19999) == 0x1270f);
        assert(DefType::ExpandSplit(9999) == 0x270f);
        assert(DefType::ExpandSplit(99990000) == 0x270f0000);
        assert(DefType::ExpandSplit(999900) == 0x006326ac);
        
        assert(DefType::ExpandNegationValue(0) == 9999);
        assert(DefType::ExpandNegationValue(1) == 9998);
        assert(DefType::ExpandNegationValue(4899) == 5100);

        assert(DefType::ExpandElementValue(0x270f270f) == 0x270f);
        assert(DefType::ExpandElementValue(0x270f0000) == 0x00);
        assert(DefType::ExpandElementValue(0x006326ac) == 0x26ac);

        assert(DefType::ExpandCarryValue(0x270f270f) == 0x270f);
        assert(DefType::ExpandCarryValue(0x270f0000) == 0x270f);
        assert(DefType::ExpandCarryValue(0x006326ac) == 0x0063);
        
        assert(DefType::LogElementValue(0) == 0);
        assert(DefType::LogElementValue(987) == 2);
        assert(DefType::LogElementValue(1009) == 3);
        assert(DefType::LogElementValue(9) == 0);
        assert(DefType::LogElementValue(11) == 1);
        
        assert(DefType::ShiftRightElementValue(0, 1) == 0);
        assert(DefType::ShiftRightElementValue(9123, 3) == 9);
        assert(DefType::ShiftRightElementValue(1234, 2) == 12);
        assert(DefType::ShiftRightElementValue(2134, 4) == 0);

        assert(DefType::ShiftLeftElementValue(0, 1) == 0);
        assert(DefType::ShiftLeftElementValue(1234, 3) == 4000);
        assert(DefType::ShiftLeftElementValue(23, 2) == 2300);
        assert(DefType::ShiftLeftElementValue(1234, 4) == 0);

        assert(DefType::DigitElementValue(1, 0) == 1);
        assert(DefType::DigitElementValue(1234, 1, 3) == 123);
        assert(DefType::DigitElementValue(3456, 2, 4) == 34);
        assert(DefType::DigitElementValue(2423, 3) == 2);
        assert(DefType::DigitElementValue(4248, 2, 3) == 42);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int16_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint16_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint32_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint16_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint16_t));
        assert(DefType::ElementMaxExponent == 4);
        assert(DefType::ElementMaxValue == 9999);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint16_t, 10> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint32_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 9);
        assert(DefType::ElementMaxValue == 999999999ul);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        assert(DefType::ExpandSplit(1999999999ull) == 0x000000013b9ac9ff);
        assert(DefType::ExpandSplit(999999999ull) == 0x000000003b9ac9ff);
        assert(DefType::ExpandSplit(999999999000000000ull) == 
            0x3b9ac9ff00000000);
        assert(DefType::ExpandSplit(9999999990000ull) == 
            0x0000270f3b9aa2f0);

        assert(DefType::ExpandNegationValue(0) == 999999999ul);
        assert(DefType::ExpandNegationValue(1) == 999999998ul);
        assert(DefType::ExpandNegationValue(989234123ul) == 10765876ul);

        assert(DefType::ExpandElementValue(0x3b9ac9ff3b9ac9ff) == 0x3b9ac9ff);
        assert(DefType::ExpandElementValue(0x3b9ac9ff00000000) == 0x00);
        assert(DefType::ExpandElementValue(0x0000270f3b9aa2f0) == 0x3b9aa2f0);

        assert(DefType::ExpandCarryValue(0x3b9ac9ff3b9ac9ff) == 0x3b9ac9ff);
        assert(DefType::ExpandCarryValue(0x3b9ac9ff00000000) == 0x3b9ac9ff);
        assert(DefType::ExpandCarryValue(0x0000270f3b9aa2f0) == 0x0000270f);
        
        assert(DefType::LogElementValue(0) == 0);
        assert(DefType::LogElementValue(123456ul) == 5);
        assert(DefType::LogElementValue(9012345ul) == 6);
        assert(DefType::LogElementValue(112345670ul) == 8);
        
        assert(DefType::ShiftRightElementValue(0, 1) == 0);
        assert(DefType::ShiftRightElementValue(990090000ul, 2) == 9900900ul);
        assert(DefType::ShiftRightElementValue(120090000ul, 7) == 12ul);
        assert(DefType::ShiftRightElementValue(800000123ul, 8) == 8ul);

        assert(DefType::ShiftLeftElementValue(0, 1) == 0);
        assert(DefType::ShiftLeftElementValue(90990ul, 2) == 9099000ul);
        assert(DefType::ShiftLeftElementValue(120090709ul, 7) == 90000000ul);
        assert(DefType::ShiftLeftElementValue(123456782ul, 8) == 200000000ul);

        assert(DefType::DigitElementValue(1, 0) == 1);
        assert(DefType::DigitElementValue(123456789, 5, 4) == 1234);
        assert(DefType::DigitElementValue(123456789, 3, 5) == 23456);
        assert(DefType::DigitElementValue(123456789, 8) == 1);
        assert(DefType::DigitElementValue(123456789, 9) == 0);
        assert(DefType::DigitElementValue(123456789, 6, 8) == 123);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int32_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 1);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 9);
        assert(DefType::ElementMaxValue == 999999999ul);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint32_t, 10> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::uint64_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == false);
        assert(DefType::NMinSize == 2);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 9);
        assert(DefType::ElementMaxValue == 999999999ul);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == false);
        
        typedef Definition<std::uint32_t, 10> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    {
        using namespace test::integer::fmt;
        typedef Definition<std::int64_t, 10> DefType;

        assert((std::is_same<DefType::ElementType, std::uint32_t>::value));
        assert((std::is_same<DefType::ExpandType, std::uint64_t>::value));
        assert((std::is_same<DefType::SizeType, std::size_t>::value));
        assert((std::is_same<DefType::DigitType, std::uint32_t>::value));

        assert(DefType::Signed == true);
        assert(DefType::NMinSize == 2);
        assert(DefType::ElementAllocSize == sizeof(std::uint32_t));
        assert(DefType::ElementMaxExponent == 9);
        assert(DefType::ElementMaxValue == 999999999ul);

        assert(DefType::Flag().IsDecimalFormat() == true);
        assert(DefType::Flag().IsSigned() == true);
        
        typedef Definition<std::uint64_t, 10> UnsignedDefType;

        assert(&DefType::ExpandSplit == &UnsignedDefType::ExpandSplit);
        assert(&DefType::ExpandNegationValue == 
            &UnsignedDefType::ExpandNegationValue);
        assert(&DefType::ExpandElementValue == 
            &UnsignedDefType::ExpandElementValue);
        assert(&DefType::ExpandCarryValue == 
            &UnsignedDefType::ExpandCarryValue);
        assert(&DefType::LogElementValue == 
            &UnsignedDefType::LogElementValue);
        assert(&DefType::ShiftRightElementValue == 
            &UnsignedDefType::ShiftRightElementValue);
        assert(&DefType::ShiftLeftElementValue ==
            &UnsignedDefType::ShiftLeftElementValue);
        assert(&DefType::DigitElementValue == 
            &UnsignedDefType::DigitElementValue);
    }
    return 0;
}
