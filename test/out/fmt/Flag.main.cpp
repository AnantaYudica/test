#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#include "test/out/fmt/Flag.h"

#include <cassert>
#include <atomic>
#include <cstdint>

#include <cstdio>

int main()
{
    {
        test::out::fmt::Flag<> fl1;
        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == false);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.undefined);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.undefined);

        assert(fl1.GetSpecifier() == fl1.undefined);

        assert(fl1.IsSpecifierUndefined() == true);
        assert(fl1.IsSpecifierCharacter() == false);
        assert(fl1.IsSpecifierString() == false);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.undefined);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == false);
        assert(fl1.IsSpecifierSubPrecision() == false);
        assert(fl1.IsSpecifierSubLength() == false);

        assert(fl1.GetSpecifierSub() == fl1.undefined);
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);
        
        assert(fl1.HasInputValue() == false);
        assert(fl1.HasInputWidth() == false);
        assert(fl1.HasInputLength() == false);
        assert(fl1.HasInputPrecision() == false);
    }
    {
        test::out::fmt::Flag<std::atomic<std::uint32_t>> fl1;

        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == false);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.undefined);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.undefined);

        assert(fl1.GetSpecifier() == fl1.undefined);

        assert(fl1.IsSpecifierUndefined() == true);
        assert(fl1.IsSpecifierCharacter() == false);
        assert(fl1.IsSpecifierString() == false);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.undefined);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == false);
        assert(fl1.IsSpecifierSubPrecision() == false);
        assert(fl1.IsSpecifierSubLength() == false);

        assert(fl1.GetSpecifierSub() == fl1.undefined);
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);

        assert(fl1.HasInputValue() == false);
        assert(fl1.HasInputWidth() == false);
        assert(fl1.HasInputLength() == false);
        assert(fl1.HasInputPrecision() == false);
    }
    {
        const auto specifier1 = test::out::fmt::Flag<>::specifier_ch;
        test::out::fmt::Flag<> fl1{specifier1};
        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == false);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.undefined);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.undefined);

        assert(fl1.GetSpecifier() == fl1.specifier_ch);

        assert(fl1.IsSpecifierUndefined() == false);
        assert(fl1.IsSpecifierCharacter() == true);
        assert(fl1.IsSpecifierString() == false);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.specifier_ch);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == false);
        assert(fl1.IsSpecifierSubPrecision() == false);
        assert(fl1.IsSpecifierSubLength() == false);

        assert(fl1.GetSpecifierSub() == fl1.undefined);
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);

        assert(fl1.HasInputValue() == false);
        assert(fl1.HasInputWidth() == false);
        assert(fl1.HasInputLength() == false);
        assert(fl1.HasInputPrecision() == false);
    }
    {
        const auto specifier1 = 
            test::out::fmt::Flag<std::atomic<std::uint32_t>>::specifier_ch;
        test::out::fmt::Flag<std::atomic<std::uint32_t>> fl1{specifier1};
        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == false);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.undefined);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.undefined);

        assert(fl1.GetSpecifier() == fl1.specifier_ch);

        assert(fl1.IsSpecifierUndefined() == false);
        assert(fl1.IsSpecifierCharacter() == true);
        assert(fl1.IsSpecifierString() == false);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.specifier_ch);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == false);
        assert(fl1.IsSpecifierSubPrecision() == false);
        assert(fl1.IsSpecifierSubLength() == false);

        assert(fl1.GetSpecifierSub() == fl1.undefined);
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);
        
        assert(fl1.HasInputValue() == false);
        assert(fl1.HasInputWidth() == false);
        assert(fl1.HasInputLength() == false);
        assert(fl1.HasInputPrecision() == false);
    }
    {
        const auto specifier1 = test::out::fmt::Flag<>::specifier_str;
        test::out::fmt::Flag<> fl1{specifier1};
        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == false);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.undefined);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.undefined);

        assert(fl1.GetSpecifier() == fl1.specifier_str);

        assert(fl1.IsSpecifierUndefined() == false);
        assert(fl1.IsSpecifierCharacter() == false);
        assert(fl1.IsSpecifierString() == true);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.specifier_str);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == false);
        assert(fl1.IsSpecifierSubPrecision() == false);
        assert(fl1.IsSpecifierSubLength() == false);

        assert(fl1.GetSpecifierSub() == fl1.undefined);
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);

        assert(fl1.HasInputValue() == false);
        assert(fl1.HasInputWidth() == false);
        assert(fl1.HasInputLength() == false);
        assert(fl1.HasInputPrecision() == false);
    }
    {
        const auto specifier1 = 
            test::out::fmt::Flag<std::atomic<std::uint32_t>>::specifier_str;
        test::out::fmt::Flag<std::atomic<std::uint32_t>> fl1{specifier1};

        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == false);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.undefined);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.undefined);

        assert(fl1.GetSpecifier() == fl1.specifier_str);

        assert(fl1.IsSpecifierUndefined() == false);
        assert(fl1.IsSpecifierCharacter() == false);
        assert(fl1.IsSpecifierString() == true);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.specifier_str);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == false);
        assert(fl1.IsSpecifierSubPrecision() == false);
        assert(fl1.IsSpecifierSubLength() == false);

        assert(fl1.GetSpecifierSub() == fl1.undefined);
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);

        assert(fl1.HasInputValue() == false);
        assert(fl1.HasInputWidth() == false);
        assert(fl1.HasInputLength() == false);
        assert(fl1.HasInputPrecision() == false);
    }
    {
        test::out::fmt::Flag<> fl1{test::out::fmt::Flag<>::specifier_str, 
            test::out::fmt::flag::Define<char>{},
            test::out::fmt::flag::Value<char*>{nullptr},
            test::out::fmt::flag::Width{1},
            test::out::fmt::flag::Length{1}};
            
        assert(fl1.IsGood() == true);
        assert(fl1.IsBad() == false);

        assert(fl1.IsDefine() == true);
        assert(fl1.IsDefineSigned() == false);
        assert(fl1.IsDefineUnsigned() == false);

        assert(fl1.GetDefine() == fl1.define_char);
        assert(fl1.GetDefineSigned() == fl1.undefined);
        assert(fl1.GetDefineType() == fl1.define_char);

        assert(fl1.GetSpecifier() == (fl1.specifier_str | 
            fl1.specifier_sub_width | fl1.specifier_sub_length));

        assert(fl1.IsSpecifierUndefined() == false);
        assert(fl1.IsSpecifierCharacter() == false);
        assert(fl1.IsSpecifierString() == true);
        assert(fl1.IsSpecifierPointer() == false);
        assert(fl1.IsSpecifierInteger() == false);
        assert(fl1.IsSpecifierFloatingPoint() == false);
        assert(fl1.IsSpecifierBlank() == false);
        assert(fl1.IsSpecifierBoolean() == false);
        
        assert(fl1.GetSpecifierType() == fl1.specifier_str);

        assert(fl1.IsSpecifierFlagUndefined() == true);
        assert(fl1.IsSpecifierFlagPrefix() == false);
        assert(fl1.IsSpecifierFlagPrefixPlus() == false);
        assert(fl1.IsSpecifierFlagPrefixSpace() == false);
        assert(fl1.IsSpecifierFlagPrefixZero() == false);

        assert(fl1.GetSpecifierFlag() == fl1.undefined);

        assert(fl1.IsSpecifierSubWidth() == true);
        assert(fl1.IsSpecifierSubPrecision() == true);
        assert(fl1.IsSpecifierSubLength() == true);

        assert(fl1.GetSpecifierSub() == 
            (fl1.specifier_sub_width | fl1.specifier_sub_length));
        
        assert(fl1.IsSpecifierIntegerSigned() == false);
        assert(fl1.IsSpecifierIntegerUnsigned() == false);

        assert(fl1.GetSpecifierInteger() == fl1.undefined);

        assert(fl1.IsSpecifierFloatingPointFixed() == false);
        assert(fl1.IsSpecifierFloatingPointExponent() == false);
        assert(fl1.IsSpecifierFloatingPointShort() == false);
        
        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierBaseDecimal() == false);
        assert(fl1.IsSpecifierBaseOctal() == false);
        assert(fl1.IsSpecifierBaseHexadecimal() == false);

        assert(fl1.GetSpecifierFloatingPoint() == fl1.undefined);

        assert(fl1.IsSpecifierLowerCase() == false);
        assert(fl1.IsSpecifierUpperCase() == false);

        assert(fl1.GetSpecifierCase() == fl1.undefined);

        assert(fl1.HasInputValue() == true);
        assert(fl1.HasInputWidth() == true);
        assert(fl1.HasInputLength() == true);
        assert(fl1.HasInputPrecision() == true);
    }
    return 0;
}
