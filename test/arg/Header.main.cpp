#ifdef DEBUG
#define TEST_SYS_DEBUG_ENABLE 1
#endif //!DEBUG

#define TEST_ARG_HEADER_DLEVEL 0x7f

#include "test/arg/Header.h"

#include <cassert>

struct Obj1
{
    int val;
    Obj1() : val(0) {}
    Obj1(const Obj1& cpy) : val(cpy.val) {}
};

int main()
{
    {
        test::arg::Header h1;

        assert(h1.IsGood() == false);
        assert(h1.IsBad() == true);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == 0);
        assert(h1.Size() == 0);
        assert((h1 == test::arg::Header()) == true);
        assert((h1 != test::arg::Header()) == false);
        
        test::arg::Header h2(sizeof(Obj1), Obj1());
        assert(h1.IsGood() == false);
        assert(h1.IsBad() == true);

    }
    {
        test::arg::Header h1(sizeof(char), char('a'));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == true);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == true);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineChar);
        assert(h1.Size() == sizeof(char));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);

        char v1 = 4;
        test::arg::Header h2(sizeof(char), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineChar);
        assert(h2.Size() == sizeof(char));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const char v2 = 6;
        test::arg::Header h3(sizeof(char), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineChar);
        assert(h3.Size() == sizeof(char));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);

    }
    {
        test::arg::Header h1(sizeof(wchar_t), wchar_t(0));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);
        
        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == true);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == true);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineWchar);
        assert(h1.Size() == sizeof(wchar_t));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        wchar_t v1 = 4;
        test::arg::Header h2(sizeof(wchar_t), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineWchar);
        assert(h2.Size() == sizeof(wchar_t));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const wchar_t v2 = 6;
        test::arg::Header h3(sizeof(wchar_t), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineWchar);
        assert(h3.Size() == sizeof(wchar_t));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(bool), false);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == true);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineBool);
        assert(h1.Size() == sizeof(bool));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        bool v1 = false;
        test::arg::Header h2(sizeof(bool), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineBool);
        assert(h2.Size() == sizeof(bool));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const bool v2 = true;
        test::arg::Header h3(sizeof(bool), v2); 
        assert(h3.Flag() == test::arg::Header::DefineBool);
        assert(h3.Size() == sizeof(bool));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(signed char), (signed char)-4);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == true);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineSignedChar);
        assert(h1.Size() == sizeof(signed char));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        signed char v1 = 4;
        test::arg::Header h2(sizeof(signed char), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineSignedChar);
        assert(h2.Size() == sizeof(signed char));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const signed char v2 = 6;
        test::arg::Header h3(sizeof(signed char), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineSignedChar);
        assert(h3.Size() == sizeof(signed char));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(short), short(-4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == true);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineShort);
        assert(h1.Size() == sizeof(short));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        short v1 = 4;
        test::arg::Header h2(sizeof(short), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineShort);
        assert(h2.Size() == sizeof(short));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const short v2 = 6;
        test::arg::Header h3(sizeof(short), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineShort);
        assert(h3.Size() == sizeof(short));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(int), int(-4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == true);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineInt);
        assert(h1.Size() == sizeof(int));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        int v1 = 4;
        test::arg::Header h2(sizeof(int), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineInt);
        assert(h2.Size() == sizeof(int));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const int v2 = 6;
        test::arg::Header h3(sizeof(int), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineInt);
        assert(h3.Size() == sizeof(int));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(long), long(-4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == true);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineLong);
        assert(h1.Size() == sizeof(long));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        long v1 = 4;
        test::arg::Header h2(sizeof(long), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineLong);
        assert(h2.Size() == sizeof(long));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const long v2 = 6;
        test::arg::Header h3(sizeof(long), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineLong);
        assert(h3.Size() == sizeof(long));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(long long), (long long)(-4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == true);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineLongLong);
        assert(h1.Size() == sizeof(long long));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        long long v1 = 4;
        test::arg::Header h2(sizeof(long long), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineLongLong);
        assert(h2.Size() == sizeof(long long));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const long long v2 = 6;
        test::arg::Header h3(sizeof(long long), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineLongLong);
        assert(h3.Size() == sizeof(long long));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(unsigned char), (unsigned char)(4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == true);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineUnsignedChar);
        assert(h1.Size() == sizeof(unsigned char));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        unsigned char v1 = 4;
        test::arg::Header h2(sizeof(unsigned char), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineUnsignedChar);
        assert(h2.Size() == sizeof(unsigned char));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const unsigned char v2 = 6;
        test::arg::Header h3(sizeof(unsigned char), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineUnsignedChar);
        assert(h3.Size() == sizeof(unsigned char));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(unsigned short), (unsigned short)(4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == true);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineUnsignedShort);
        assert(h1.Size() == sizeof(unsigned short));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        unsigned short v1 = 4;
        test::arg::Header h2(sizeof(unsigned short), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineUnsignedShort);
        assert(h2.Size() == sizeof(unsigned short));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const unsigned short v2 = 6;
        test::arg::Header h3(sizeof(unsigned short), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineUnsignedShort);
        assert(h3.Size() == sizeof(unsigned short));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(unsigned int), (unsigned int)(4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == true);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineUnsignedInt);
        assert(h1.Size() == sizeof(unsigned int));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        unsigned int v1 = 4;
        test::arg::Header h2(sizeof(unsigned int), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineUnsignedInt);
        assert(h2.Size() == sizeof(unsigned int));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const unsigned int v2 = 6;
        test::arg::Header h3(sizeof(unsigned int), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineUnsignedInt);
        assert(h3.Size() == sizeof(unsigned int));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(unsigned long), (unsigned long)(4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == true);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineUnsignedLong);
        assert(h1.Size() == sizeof(unsigned long));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        unsigned long v1 = 4;
        test::arg::Header h2(sizeof(unsigned long), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineUnsignedLong);
        assert(h2.Size() == sizeof(unsigned long));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const unsigned long v2 = 6;
        test::arg::Header h3(sizeof(unsigned long), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineUnsignedLong);
        assert(h3.Size() == sizeof(unsigned long));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(unsigned long long), 
            (unsigned long long)(4));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == true);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineUnsignedLongLong);
        assert(h1.Size() == sizeof(unsigned long long));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        unsigned long long v1 = 4;
        test::arg::Header h2(sizeof(unsigned long long), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineUnsignedLongLong);
        assert(h2.Size() == sizeof(unsigned long long));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const unsigned long long v2 = 6;
        test::arg::Header h3(sizeof(unsigned long long), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineUnsignedLongLong);
        assert(h3.Size() == sizeof(unsigned long long));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(float), float(3.14));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == true);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == true);

        assert(h1.Flag() == test::arg::Header::DefineFloat);
        assert(h1.Size() == sizeof(float));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        float v1 = 3.14;
        test::arg::Header h2(sizeof(float), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineFloat);
        assert(h2.Size() == sizeof(float));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const float v2 = 6.28;
        test::arg::Header h3(sizeof(float), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineFloat);
        assert(h3.Size() == sizeof(float));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(double), double(3.14));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == true);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == true);

        assert(h1.Flag() == test::arg::Header::DefineDouble);
        assert(h1.Size() == sizeof(double));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);

        double v1 = 3.14;
        test::arg::Header h2(sizeof(double), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineDouble);
        assert(h2.Size() == sizeof(double));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const double v2 = 6.28;
        test::arg::Header h3(sizeof(double), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineDouble);
        assert(h3.Size() == sizeof(double));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(long double), (long double)(3.14));
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == true);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == true);

        assert(h1.Flag() == test::arg::Header::DefineLongDouble);
        assert(h1.Size() == sizeof(long double));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        long double v1 = 3.14;
        test::arg::Header h2(sizeof(long double), v1); 
        
        assert(h2.Flag() == test::arg::Header::DefineLongDouble);
        assert(h2.Size() == sizeof(long double));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const long double v2 = 6.28;
        test::arg::Header h3(sizeof(long double), v2); 
        
        assert(h3.Flag() == test::arg::Header::DefineLongDouble);
        assert(h3.Size() == sizeof(long double));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(Obj1), Obj1());
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == true);

        assert(h1.IsDefinePointer() == false);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefineObject);
        assert(h1.Size() == sizeof(Obj1));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        Obj1 o1;
        test::arg::Header h2(sizeof(Obj1), o1); 
        
        assert(h2.Flag() == test::arg::Header::DefineObject);
        assert(h2.Size() == sizeof(Obj1));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const Obj1 o2;
        test::arg::Header h3(sizeof(Obj1), o2); 
        
        assert(h3.Flag() == test::arg::Header::DefineObject);
        assert(h3.Size() == sizeof(Obj1));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(char*), "test");
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == true);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == true);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert((h1.Flag() & test::arg::Header::DefineString) == h1.Flag());
        assert(h1.Size() == sizeof(char*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        char _v1[] = "v1";
        char* v1 =_v1;
        test::arg::Header h2(sizeof(char*), v1); 
        
        assert((h2.Flag() & test::arg::Header::DefineString) == h2.Flag());
        assert(h2.Size() == sizeof(char*));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const char* v2 = "v2";
        test::arg::Header h3(sizeof(char*), v2); 
        
        assert((h3.Flag() & test::arg::Header::DefineString) == h3.Flag());
        assert(h3.Size() == sizeof(char*));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        test::arg::Header h1(sizeof(wchar_t*), L"test");
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == true);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == true);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert((h1.Flag() & test::arg::Header::DefineString) == h1.Flag());
        assert(h1.Size() == sizeof(wchar_t*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        wchar_t _v1[] = L"v1";
        wchar_t* v1 = _v1;
        test::arg::Header h2(sizeof(wchar_t*), v1); 
        
        assert((h2.Flag() & test::arg::Header::DefineString) == h2.Flag());
        assert(h2.Size() == sizeof(wchar_t*));
        assert((h1 == h2) == true);
        assert((h1 != h2) == false);

        const wchar_t* v2 = L"v2";
        test::arg::Header h3(sizeof(wchar_t*), v2); 
        
        assert((h3.Flag() & test::arg::Header::DefineString) == h3.Flag());
        assert(h3.Size() == sizeof(wchar_t*));
        assert((h1 == h3) == true);
        assert((h1 != h3) == false);
    }
    {
        bool v0 = false;
        test::arg::Header h1(sizeof(void*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == true);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineBool));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const bool v1 = false;
        test::arg::Header h2(sizeof(void*), &v1);
        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineBool));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        signed char v0 = (signed char)1;
        test::arg::Header h1(sizeof(void*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == true);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineSignedChar));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const signed char v1 = (signed char)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineSignedChar));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        short v0 = (short)1;
        test::arg::Header h1(sizeof(void*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == true);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineShort));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const short v1 = (short)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineShort));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        int v0 = (int)1;
        test::arg::Header h1(sizeof(int*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == true);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineInt));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const int v1 = (int)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineInt));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        long v0 = (long)1;
        test::arg::Header h1(sizeof(long*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == true);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineLong));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const long v1 = (long)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineLong));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        long long v0 = (long long)1;
        test::arg::Header h1(sizeof(long long*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == true);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == true);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineLongLong));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const long long v1 = (long long)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineLongLong));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        unsigned char v0 = (unsigned char)1;
        test::arg::Header h1(sizeof(unsigned char*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == true);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedChar));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const unsigned char v1 = (unsigned char)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedChar));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        unsigned short v0 = (unsigned short)1;
        test::arg::Header h1(sizeof(unsigned short*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == true);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedShort));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const unsigned short v1 = (unsigned short)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedShort));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        unsigned int v0 = (unsigned int)1;
        test::arg::Header h1(sizeof(unsigned int*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == true);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedInt));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const unsigned int v1 = (unsigned int)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedInt));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        unsigned long v0 = (unsigned long)1;
        test::arg::Header h1(sizeof(unsigned long*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == true);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedLong));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const unsigned long v1 = (unsigned long)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedLong));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        unsigned long long v0 = (unsigned long long)1;
        test::arg::Header h1(sizeof(unsigned long long*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == true);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == true);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == true);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedLongLong));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const unsigned long long v1 = (unsigned long long)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineUnsignedLongLong));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        float v0 = (float)1;
        test::arg::Header h1(sizeof(float*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == true);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == true);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineFloat));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const float v1 = (float)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineFloat));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        double v0 = (double)1;
        test::arg::Header h1(sizeof(double*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == true);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == true);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineDouble));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const double v1 = (double)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineDouble));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        long double v0 = (long double)1;
        test::arg::Header h1(sizeof(long double*), &v0);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == true);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == true);

        assert(h1.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineLongDouble));
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const long double v1 = (long double)1;
        test::arg::Header h2(sizeof(void*), &v1);

        assert(h2.Flag() == (test::arg::Header::DefinePointer | 
            test::arg::Header::DefineLongDouble));
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
    }
    {
        Obj1 obj1;
        test::arg::Header h1(sizeof(Obj1*), &obj1);

        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == true);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == (test::arg::Header::DefinePointer |
            test::arg::Header::DefineObject));
        assert(h1.Size() == sizeof(Obj1*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);
        
        const Obj1 obj2;
        test::arg::Header h2(sizeof(Obj1*), &obj2);
        assert(h2.Flag() == (test::arg::Header::DefinePointer |
            test::arg::Header::DefineObject));
        assert(h2.Size() == sizeof(Obj1*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
        const Obj1 *const obj3 = &obj2;
        test::arg::Header h3(sizeof(void*), obj3);
        assert(h3.Flag() == (test::arg::Header::DefinePointer |
            test::arg::Header::DefineObject));
        assert(h3.Size() == sizeof(void*));
        assert((h3 == h1) == true);
        assert((h3 != h1) == false);
    }
    {

        Obj1 obj1;
        test::arg::Header h1(sizeof(void*), (void*)&obj1);
        
        assert(h1.IsGood() == true);
        assert(h1.IsBad() == false);

        assert(h1.IsDefineChar() == false);
        assert(h1.IsDefineWchar() == false);
        assert(h1.IsDefineBool() == false);
        assert(h1.IsDefineSignedChar() == false);
        assert(h1.IsDefineShort() == false);
        assert(h1.IsDefineInt() == false);
        assert(h1.IsDefineLong() == false);
        assert(h1.IsDefineLongLong() == false);
        assert(h1.IsDefineUnsignedChar() == false);
        assert(h1.IsDefineUnsignedShort() == false);
        assert(h1.IsDefineUnsignedInt() == false);
        assert(h1.IsDefineUnsignedLong() == false);
        assert(h1.IsDefineUnsignedLongLong() == false);
        assert(h1.IsDefineFloat() == false);
        assert(h1.IsDefineDouble() == false);
        assert(h1.IsDefineLongDouble() == false);
        assert(h1.IsDefineObject() == false);

        assert(h1.IsDefinePointer() == true);

        assert(h1.IsDefineString() == false);
        assert(h1.IsDefineCharacter() == false);
        assert(h1.IsDefineInteger() == false);
        assert(h1.IsDefineSigned() == false);
        assert(h1.IsDefineUnsigned() == false);
        assert(h1.IsDefineFloatingPoint() == false);

        assert(h1.Flag() == test::arg::Header::DefinePointer);
        assert(h1.Size() == sizeof(void*));
        assert((h1 == test::arg::Header()) == false);
        assert((h1 != test::arg::Header()) == true);

        const Obj1 obj2;
        test::arg::Header h2(sizeof(void*), (const void*)&obj2);
        assert(h2.Flag() == test::arg::Header::DefinePointer);
        assert(h2.Size() == sizeof(void*));
        assert((h2 == h1) == true);
        assert((h2 != h1) == false);
        
    }
    return 0;
}