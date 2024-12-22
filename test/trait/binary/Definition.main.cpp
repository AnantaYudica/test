#include "test/trait/binary/Definition.h"

#include "test/System.h"

#include <cstdint>
#include <cassert>
#include <type_traits>


static test::sys::Status status;
static test::sys::Log<test::sys::Status> log(status);

int main()
{
    using namespace test::trait::binary;

    {
        assert(Definition<0>::AllocationSize == 1);
        assert((std::is_same<typename Definition<0>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<0>::BitSize == 1);
        assert(Definition<0>::BitBeginIndex == 0);
        assert(Definition<0>::BitEndIndex == 1);
        assert(Definition<0>::Mask == 0x01);
        assert(Definition<0>::NegationMask == 0xFE);
        assert(Definition<0>::BitCarryIndex == 1);
        assert(Definition<0>::BitCarryMask == 0x02);
    }
    {
        assert(Definition<1>::AllocationSize == 1);
        assert((std::is_same<typename Definition<1>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<1>::BitSize == 1);
        assert(Definition<1>::BitBeginIndex == 1);
        assert(Definition<1>::BitEndIndex == 2);
        assert(Definition<1>::Mask == 0x02);
        assert(Definition<1>::NegationMask == 0xFD);
        assert(Definition<1>::BitCarryIndex == 2);
        assert(Definition<1>::BitCarryMask == 0x04);
    }
    {
        assert(Definition<2>::AllocationSize == 1);
        assert((std::is_same<typename Definition<2>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<2>::BitSize == 1);
        assert(Definition<2>::BitBeginIndex == 2);
        assert(Definition<2>::BitEndIndex == 3);
        assert(Definition<2>::Mask == 0x04);
        assert(Definition<2>::NegationMask == 0xFB);
        assert(Definition<2>::BitCarryIndex == 3);
        assert(Definition<2>::BitCarryMask == 0x08);
    }
    {
        assert(Definition<3>::AllocationSize == 1);
        assert((std::is_same<typename Definition<3>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<3>::BitSize == 1);
        assert(Definition<3>::BitBeginIndex == 3);
        assert(Definition<3>::BitEndIndex == 4);
        assert(Definition<3>::Mask == 0x08);
        assert(Definition<3>::NegationMask == 0xF7);
        assert(Definition<3>::BitCarryIndex == 4);
        assert(Definition<3>::BitCarryMask == 0x10);
    }
    {
        assert(Definition<4>::AllocationSize == 1);
        assert((std::is_same<typename Definition<4>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<4>::BitSize == 1);
        assert(Definition<4>::BitBeginIndex == 4);
        assert(Definition<4>::BitEndIndex == 5);
        assert(Definition<4>::Mask == 0x10);
        assert(Definition<4>::NegationMask == 0xEF);
        assert(Definition<4>::BitCarryIndex == 5);
        assert(Definition<4>::BitCarryMask == 0x20);
    }
    {
        assert(Definition<5>::AllocationSize == 1);
        assert((std::is_same<typename Definition<5>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<5>::BitSize == 1);
        assert(Definition<5>::BitBeginIndex == 5);
        assert(Definition<5>::BitEndIndex == 6);
        assert(Definition<5>::Mask == 0x20);
        assert(Definition<5>::NegationMask == 0xDF);
        assert(Definition<5>::BitCarryIndex == 6);
        assert(Definition<5>::BitCarryMask == 0x40);
    }
    {
        assert(Definition<6>::AllocationSize == 1);
        assert((std::is_same<typename Definition<6>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<6>::BitSize == 1);
        assert(Definition<6>::BitBeginIndex == 6);
        assert(Definition<6>::BitEndIndex == 7);
        assert(Definition<6>::Mask == 0x40);
        assert(Definition<6>::NegationMask == 0xBF);
        assert(Definition<6>::BitCarryIndex == 7);
        assert(Definition<6>::BitCarryMask == 0x80);
    }
    {
        assert(Definition<7>::AllocationSize == 1);
        assert((std::is_same<typename Definition<7>::ValueType, 
            std::uint8_t>::value));
        assert(Definition<7>::BitSize == 1);
        assert(Definition<7>::BitBeginIndex == 7);
        assert(Definition<7>::BitEndIndex == 8);
        assert(Definition<7>::Mask == 0x80);
        assert(Definition<7>::NegationMask == 0x7F);
        assert(Definition<7>::BitCarryIndex == 0);
        assert(Definition<7>::BitCarryMask == 0x01);
    }

    {
        assert(Definition<8>::AllocationSize == 2);
        assert((std::is_same<typename Definition<8>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<8>::BitSize == 1);
        assert(Definition<8>::BitBeginIndex == 8);
        assert(Definition<8>::BitEndIndex == 9);
        assert(Definition<8>::Mask == 0x100);
        assert(Definition<8>::NegationMask == 0xFEFF);
        assert(Definition<8>::BitCarryIndex == 9);
        assert(Definition<8>::BitCarryMask == 0x200);
    }
    {
        assert(Definition<9>::AllocationSize == 2);
        assert((std::is_same<typename Definition<9>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<9>::BitSize == 1);
        assert(Definition<9>::BitBeginIndex == 9);
        assert(Definition<9>::BitEndIndex == 10);
        assert(Definition<9>::Mask == 0x200);
        assert(Definition<9>::NegationMask == 0xFDFF);
        assert(Definition<9>::BitCarryIndex == 10);
        assert(Definition<9>::BitCarryMask == 0x400);
    }
    {
        assert(Definition<10>::AllocationSize == 2);
        assert((std::is_same<typename Definition<10>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<10>::BitSize == 1);
        assert(Definition<10>::BitBeginIndex == 10);
        assert(Definition<10>::BitEndIndex == 11);
        assert(Definition<10>::Mask == 0x400);
        assert(Definition<10>::NegationMask == 0xFBFF);
        assert(Definition<10>::BitCarryIndex == 11);
        assert(Definition<10>::BitCarryMask == 0x800);
    }
    {
        assert(Definition<11>::AllocationSize == 2);
        assert((std::is_same<typename Definition<11>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<11>::BitSize == 1);
        assert(Definition<11>::BitBeginIndex == 11);
        assert(Definition<11>::BitEndIndex == 12);
        assert(Definition<11>::Mask == 0x800);
        assert(Definition<11>::NegationMask == 0xF7FF);
        assert(Definition<11>::BitCarryIndex == 12);
        assert(Definition<11>::BitCarryMask == 0x1000);
    }
    {
        assert(Definition<12>::AllocationSize == 2);
        assert((std::is_same<typename Definition<12>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<12>::BitSize == 1);
        assert(Definition<12>::BitBeginIndex == 12);
        assert(Definition<12>::BitEndIndex == 13);
        assert(Definition<12>::Mask == 0x1000);
        assert(Definition<12>::NegationMask == 0xEFFF);
        assert(Definition<12>::BitCarryIndex == 13);
        assert(Definition<12>::BitCarryMask == 0x2000);
    }
    {
        assert(Definition<13>::AllocationSize == 2);
        assert((std::is_same<typename Definition<13>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<13>::BitSize == 1);
        assert(Definition<13>::BitBeginIndex == 13);
        assert(Definition<13>::BitEndIndex == 14);
        assert(Definition<13>::Mask == 0x2000);
        assert(Definition<13>::NegationMask == 0xDFFF);
        assert(Definition<13>::BitCarryIndex == 14);
        assert(Definition<13>::BitCarryMask == 0x4000);
    }
    {
        assert(Definition<14>::AllocationSize == 2);
        assert((std::is_same<typename Definition<14>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<14>::BitSize == 1);
        assert(Definition<14>::BitBeginIndex == 14);
        assert(Definition<14>::BitEndIndex == 15);
        assert(Definition<14>::Mask == 0x4000);
        assert(Definition<14>::NegationMask == 0xBFFF);
        assert(Definition<14>::BitCarryIndex == 15);
        assert(Definition<14>::BitCarryMask == 0x8000);
    }
    {
        assert(Definition<15>::AllocationSize == 2);
        assert((std::is_same<typename Definition<15>::ValueType, 
            std::uint16_t>::value));
        assert(Definition<15>::BitSize == 1);
        assert(Definition<15>::BitBeginIndex == 15);
        assert(Definition<15>::BitEndIndex == 16);
        assert(Definition<15>::Mask == 0x8000);
        assert(Definition<15>::NegationMask == 0x7FFF);
        assert(Definition<15>::BitCarryIndex == 0);
        assert(Definition<15>::BitCarryMask == 0x01);
    }
    
    {
        assert(Definition<16>::AllocationSize == 4);
        assert((std::is_same<typename Definition<16>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<16>::BitSize == 1);
        assert(Definition<16>::BitBeginIndex == 16);
        assert(Definition<16>::BitEndIndex == 17);
        assert(Definition<16>::Mask == 0x10000);
        assert(Definition<16>::NegationMask == 0xFFFEFFFF);
        assert(Definition<16>::BitCarryIndex == 17);
        assert(Definition<16>::BitCarryMask == 0x20000);
    }
    {
        assert(Definition<17>::AllocationSize == 4);
        assert((std::is_same<typename Definition<17>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<17>::BitSize == 1);
        assert(Definition<17>::BitBeginIndex == 17);
        assert(Definition<17>::BitEndIndex == 18);
        assert(Definition<17>::Mask == 0x20000);
        assert(Definition<17>::NegationMask == 0xFFFDFFFF);
        assert(Definition<17>::BitCarryIndex == 18);
        assert(Definition<17>::BitCarryMask == 0x40000);
    }
    {
        assert(Definition<18>::AllocationSize == 4);
        assert((std::is_same<typename Definition<18>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<18>::BitSize == 1);
        assert(Definition<18>::BitBeginIndex == 18);
        assert(Definition<18>::BitEndIndex == 19);
        assert(Definition<18>::Mask == 0x40000);
        assert(Definition<18>::NegationMask == 0xFFFBFFFF);
        assert(Definition<18>::BitCarryIndex == 19);
        assert(Definition<18>::BitCarryMask == 0x80000);
    }
    {
        assert(Definition<19>::AllocationSize == 4);
        assert((std::is_same<typename Definition<19>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<19>::BitSize == 1);
        assert(Definition<19>::BitBeginIndex == 19);
        assert(Definition<19>::BitEndIndex == 20);
        assert(Definition<19>::Mask == 0x80000);
        assert(Definition<19>::NegationMask == 0xFFF7FFFF);
        assert(Definition<19>::BitCarryIndex == 20);
        assert(Definition<19>::BitCarryMask == 0x100000);
    }
    {
        assert(Definition<20>::AllocationSize == 4);
        assert((std::is_same<typename Definition<20>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<20>::BitSize == 1);
        assert(Definition<20>::BitBeginIndex == 20);
        assert(Definition<20>::BitEndIndex == 21);
        assert(Definition<20>::Mask == 0x100000);
        assert(Definition<20>::NegationMask == 0xFFEFFFFF);
        assert(Definition<20>::BitCarryIndex == 21);
        assert(Definition<20>::BitCarryMask == 0x200000);
    }
    {
        assert(Definition<21>::AllocationSize == 4);
        assert((std::is_same<typename Definition<21>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<21>::BitSize == 1);
        assert(Definition<21>::BitBeginIndex == 21);
        assert(Definition<21>::BitEndIndex == 22);
        assert(Definition<21>::Mask == 0x200000);
        assert(Definition<21>::NegationMask == 0xFFDFFFFF);
        assert(Definition<21>::BitCarryIndex == 22);
        assert(Definition<21>::BitCarryMask == 0x400000);
    }
    {
        assert(Definition<22>::AllocationSize == 4);
        assert((std::is_same<typename Definition<22>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<22>::BitSize == 1);
        assert(Definition<22>::BitBeginIndex == 22);
        assert(Definition<22>::BitEndIndex == 23);
        assert(Definition<22>::Mask == 0x400000);
        assert(Definition<22>::NegationMask == 0xFFBFFFFF);
        assert(Definition<22>::BitCarryIndex == 23);
        assert(Definition<22>::BitCarryMask == 0x800000);
    }
    {
        assert(Definition<23>::AllocationSize == 4);
        assert((std::is_same<typename Definition<23>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<23>::BitSize == 1);
        assert(Definition<23>::BitBeginIndex == 23);
        assert(Definition<23>::BitEndIndex == 24);
        assert(Definition<23>::Mask == 0x800000);
        assert(Definition<23>::NegationMask == 0xFF7FFFFF);
        assert(Definition<23>::BitCarryIndex == 24);
        assert(Definition<23>::BitCarryMask == 0x1000000);
    }
    
    {
        assert(Definition<24>::AllocationSize == 4);
        assert((std::is_same<typename Definition<24>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<24>::BitSize == 1);
        assert(Definition<24>::BitBeginIndex == 24);
        assert(Definition<24>::BitEndIndex == 25);
        assert(Definition<24>::Mask == 0x1000000);
        assert(Definition<24>::NegationMask == 0xFEFFFFFF);
        assert(Definition<24>::BitCarryIndex == 25);
        assert(Definition<24>::BitCarryMask == 0x2000000);
    }
    {
        assert(Definition<25>::AllocationSize == 4);
        assert((std::is_same<typename Definition<25>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<25>::BitSize == 1);
        assert(Definition<25>::BitBeginIndex == 25);
        assert(Definition<25>::BitEndIndex == 26);
        assert(Definition<25>::Mask == 0x2000000);
        assert(Definition<25>::NegationMask == 0xFDFFFFFF);
        assert(Definition<25>::BitCarryIndex == 26);
        assert(Definition<25>::BitCarryMask == 0x4000000);
    }
    {
        assert(Definition<26>::AllocationSize == 4);
        assert((std::is_same<typename Definition<26>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<26>::BitSize == 1);
        assert(Definition<26>::BitBeginIndex == 26);
        assert(Definition<26>::BitEndIndex == 27);
        assert(Definition<26>::Mask == 0x4000000);
        assert(Definition<26>::NegationMask == 0xFBFFFFFF);
        assert(Definition<26>::BitCarryIndex == 27);
        assert(Definition<26>::BitCarryMask == 0x8000000);
    }
    {
        assert(Definition<27>::AllocationSize == 4);
        assert((std::is_same<typename Definition<27>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<27>::BitSize == 1);
        assert(Definition<27>::BitBeginIndex == 27);
        assert(Definition<27>::BitEndIndex == 28);
        assert(Definition<27>::Mask == 0x8000000);
        assert(Definition<27>::NegationMask == 0xF7FFFFFF);
        assert(Definition<27>::BitCarryIndex == 28);
        assert(Definition<27>::BitCarryMask == 0x10000000);
    }
    {
        assert(Definition<28>::AllocationSize == 4);
        assert((std::is_same<typename Definition<28>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<28>::BitSize == 1);
        assert(Definition<28>::BitBeginIndex == 28);
        assert(Definition<28>::BitEndIndex == 29);
        assert(Definition<28>::Mask == 0x10000000);
        assert(Definition<28>::NegationMask == 0xEFFFFFFF);
        assert(Definition<28>::BitCarryIndex == 29);
        assert(Definition<28>::BitCarryMask == 0x20000000);
    }
    {
        assert(Definition<29>::AllocationSize == 4);
        assert((std::is_same<typename Definition<29>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<29>::BitSize == 1);
        assert(Definition<29>::BitBeginIndex == 29);
        assert(Definition<29>::BitEndIndex == 30);
        assert(Definition<29>::Mask == 0x20000000);
        assert(Definition<29>::NegationMask == 0xDFFFFFFF);
        assert(Definition<29>::BitCarryIndex == 30);
        assert(Definition<29>::BitCarryMask == 0x40000000);
    }
    {
        assert(Definition<30>::AllocationSize == 4);
        assert((std::is_same<typename Definition<30>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<30>::BitSize == 1);
        assert(Definition<30>::BitBeginIndex == 30);
        assert(Definition<30>::BitEndIndex == 31);
        assert(Definition<30>::Mask == 0x40000000);
        assert(Definition<30>::NegationMask == 0xBFFFFFFF);
        assert(Definition<30>::BitCarryIndex == 31);
        assert(Definition<30>::BitCarryMask == 0x80000000);
    }
    {
        assert(Definition<31>::AllocationSize == 4);
        assert((std::is_same<typename Definition<31>::ValueType, 
            std::uint32_t>::value));
        assert(Definition<31>::BitSize == 1);
        assert(Definition<31>::BitBeginIndex == 31);
        assert(Definition<31>::BitEndIndex == 32);
        assert(Definition<31>::Mask == 0x80000000);
        assert(Definition<31>::NegationMask == 0x7FFFFFFF);
        assert(Definition<31>::BitCarryIndex == 0);
        assert(Definition<31>::BitCarryMask == 0x1);
    }

    {
        assert(Definition<32>::AllocationSize == 8);
        assert((std::is_same<typename Definition<32>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<32>::BitSize == 1);
        assert(Definition<32>::BitBeginIndex == 32);
        assert(Definition<32>::BitEndIndex == 33);
        assert(Definition<32>::Mask == 0x100000000);
        assert(Definition<32>::NegationMask == 0xFFFFFFFEFFFFFFFF);
        assert(Definition<32>::BitCarryIndex == 33);
        assert(Definition<32>::BitCarryMask == 0x200000000);
    }
    {
        assert(Definition<33>::AllocationSize == 8);
        assert((std::is_same<typename Definition<33>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<33>::BitSize == 1);
        assert(Definition<33>::BitBeginIndex == 33);
        assert(Definition<33>::BitEndIndex == 34);
        assert(Definition<33>::Mask == 0x200000000);
        assert(Definition<33>::NegationMask == 0xFFFFFFFDFFFFFFFF);
        assert(Definition<33>::BitCarryIndex == 34);
        assert(Definition<33>::BitCarryMask == 0x400000000);
    }
    {
        assert(Definition<34>::AllocationSize == 8);
        assert((std::is_same<typename Definition<34>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<34>::BitSize == 1);
        assert(Definition<34>::BitBeginIndex == 34);
        assert(Definition<34>::BitEndIndex == 35);
        assert(Definition<34>::Mask == 0x400000000);
        assert(Definition<34>::NegationMask == 0xFFFFFFFBFFFFFFFF);
        assert(Definition<34>::BitCarryIndex == 35);
        assert(Definition<34>::BitCarryMask == 0x800000000);
    }
    {
        assert(Definition<35>::AllocationSize == 8);
        assert((std::is_same<typename Definition<35>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<35>::BitSize == 1);
        assert(Definition<35>::BitBeginIndex == 35);
        assert(Definition<35>::BitEndIndex == 36);
        assert(Definition<35>::Mask == 0x800000000);
        assert(Definition<35>::NegationMask == 0xFFFFFFF7FFFFFFFF);
        assert(Definition<35>::BitCarryIndex == 36);
        assert(Definition<35>::BitCarryMask == 0x1000000000);
    }
    {
        assert(Definition<36>::AllocationSize == 8);
        assert((std::is_same<typename Definition<36>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<36>::BitSize == 1);
        assert(Definition<36>::BitBeginIndex == 36);
        assert(Definition<36>::BitEndIndex == 37);
        assert(Definition<36>::Mask == 0x1000000000);
        assert(Definition<36>::NegationMask == 0xFFFFFFEFFFFFFFFF);
        assert(Definition<36>::BitCarryIndex == 37);
        assert(Definition<36>::BitCarryMask == 0x2000000000);
    }
    {
        assert(Definition<37>::AllocationSize == 8);
        assert((std::is_same<typename Definition<37>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<37>::BitSize == 1);
        assert(Definition<37>::BitBeginIndex == 37);
        assert(Definition<37>::BitEndIndex == 38);
        assert(Definition<37>::Mask == 0x2000000000);
        assert(Definition<37>::NegationMask == 0xFFFFFFDFFFFFFFFF);
        assert(Definition<37>::BitCarryIndex == 38);
        assert(Definition<37>::BitCarryMask == 0x4000000000);
    }
    {
        assert(Definition<38>::AllocationSize == 8);
        assert((std::is_same<typename Definition<38>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<38>::BitSize == 1);
        assert(Definition<38>::BitBeginIndex == 38);
        assert(Definition<38>::BitEndIndex == 39);
        assert(Definition<38>::Mask == 0x4000000000);
        assert(Definition<38>::NegationMask == 0xFFFFFFBFFFFFFFFF);
        assert(Definition<38>::BitCarryIndex == 39);
        assert(Definition<38>::BitCarryMask == 0x8000000000);
    }
    {
        assert(Definition<39>::AllocationSize == 8);
        assert((std::is_same<typename Definition<39>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<39>::BitSize == 1);
        assert(Definition<39>::BitBeginIndex == 39);
        assert(Definition<39>::BitEndIndex == 40);
        assert(Definition<39>::Mask == 0x8000000000);
        assert(Definition<39>::NegationMask == 0xFFFFFF7FFFFFFFFF);
        assert(Definition<39>::BitCarryIndex == 40);
        assert(Definition<39>::BitCarryMask == 0x10000000000);
    }
    
    {
        assert(Definition<40>::AllocationSize == 8);
        assert((std::is_same<typename Definition<40>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<40>::BitSize == 1);
        assert(Definition<40>::BitBeginIndex == 40);
        assert(Definition<40>::BitEndIndex == 41);
        assert(Definition<40>::Mask == 0x10000000000);
        assert(Definition<40>::NegationMask == 0xFFFFFEFFFFFFFFFF);
        assert(Definition<40>::BitCarryIndex == 41);
        assert(Definition<40>::BitCarryMask == 0x20000000000);
    }
    {
        assert(Definition<41>::AllocationSize == 8);
        assert((std::is_same<typename Definition<41>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<41>::BitSize == 1);
        assert(Definition<41>::BitBeginIndex == 41);
        assert(Definition<41>::BitEndIndex == 42);
        assert(Definition<41>::Mask == 0x20000000000);
        assert(Definition<41>::NegationMask == 0xFFFFFDFFFFFFFFFF);
        assert(Definition<41>::BitCarryIndex == 42);
        assert(Definition<41>::BitCarryMask == 0x40000000000);
    }
    {
        assert(Definition<42>::AllocationSize == 8);
        assert((std::is_same<typename Definition<42>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<42>::BitSize == 1);
        assert(Definition<42>::BitBeginIndex == 42);
        assert(Definition<42>::BitEndIndex == 43);
        assert(Definition<42>::Mask == 0x40000000000);
        assert(Definition<42>::NegationMask == 0xFFFFFBFFFFFFFFFF);
        assert(Definition<42>::BitCarryIndex == 43);
        assert(Definition<42>::BitCarryMask == 0x80000000000);
    }
    {
        assert(Definition<43>::AllocationSize == 8);
        assert((std::is_same<typename Definition<43>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<43>::BitSize == 1);
        assert(Definition<43>::BitBeginIndex == 43);
        assert(Definition<43>::BitEndIndex == 44);
        assert(Definition<43>::Mask == 0x80000000000);
        assert(Definition<43>::NegationMask == 0xFFFFF7FFFFFFFFFF);
        assert(Definition<43>::BitCarryIndex == 44);
        assert(Definition<43>::BitCarryMask == 0x100000000000);
    }
    {
        assert(Definition<44>::AllocationSize == 8);
        assert((std::is_same<typename Definition<44>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<44>::BitSize == 1);
        assert(Definition<44>::BitBeginIndex == 44);
        assert(Definition<44>::BitEndIndex == 45);
        assert(Definition<44>::Mask == 0x100000000000);
        assert(Definition<44>::NegationMask == 0xFFFFEFFFFFFFFFFF);
        assert(Definition<44>::BitCarryIndex == 45);
        assert(Definition<44>::BitCarryMask == 0x200000000000);
    }
    {
        assert(Definition<45>::AllocationSize == 8);
        assert((std::is_same<typename Definition<45>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<45>::BitSize == 1);
        assert(Definition<45>::BitBeginIndex == 45);
        assert(Definition<45>::BitEndIndex == 46);
        assert(Definition<45>::Mask == 0x200000000000);
        assert(Definition<45>::NegationMask == 0xFFFFDFFFFFFFFFFF);
        assert(Definition<45>::BitCarryIndex == 46);
        assert(Definition<45>::BitCarryMask == 0x400000000000);
    }
    {
        assert(Definition<46>::AllocationSize == 8);
        assert((std::is_same<typename Definition<46>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<46>::BitSize == 1);
        assert(Definition<46>::BitBeginIndex == 46);
        assert(Definition<46>::BitEndIndex == 47);
        assert(Definition<46>::Mask == 0x400000000000);
        assert(Definition<46>::NegationMask == 0xFFFFBFFFFFFFFFFF);
        assert(Definition<46>::BitCarryIndex == 47);
        assert(Definition<46>::BitCarryMask == 0x800000000000);
    }
    {
        assert(Definition<47>::AllocationSize == 8);
        assert((std::is_same<typename Definition<47>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<47>::BitSize == 1);
        assert(Definition<47>::BitBeginIndex == 47);
        assert(Definition<47>::BitEndIndex == 48);
        assert(Definition<47>::Mask == 0x800000000000);
        assert(Definition<47>::NegationMask == 0xFFFF7FFFFFFFFFFF);
        assert(Definition<47>::BitCarryIndex == 48);
        assert(Definition<47>::BitCarryMask == 0x1000000000000);
    }

    
    {
        assert(Definition<48>::AllocationSize == 8);
        assert((std::is_same<typename Definition<48>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<48>::BitSize == 1);
        assert(Definition<48>::BitBeginIndex == 48);
        assert(Definition<48>::BitEndIndex == 49);
        assert(Definition<48>::Mask == 0x1000000000000);
        assert(Definition<48>::NegationMask == 0xFFFEFFFFFFFFFFFF);
        assert(Definition<48>::BitCarryIndex == 49);
        assert(Definition<48>::BitCarryMask == 0x2000000000000);
    }
    {
        assert(Definition<49>::AllocationSize == 8);
        assert((std::is_same<typename Definition<49>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<49>::BitSize == 1);
        assert(Definition<49>::BitBeginIndex == 49);
        assert(Definition<49>::BitEndIndex == 50);
        assert(Definition<49>::Mask == 0x2000000000000);
        assert(Definition<49>::NegationMask == 0xFFFDFFFFFFFFFFFF);
        assert(Definition<49>::BitCarryIndex == 50);
        assert(Definition<49>::BitCarryMask == 0x4000000000000);
    }
    {
        assert(Definition<50>::AllocationSize == 8);
        assert((std::is_same<typename Definition<50>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<50>::BitSize == 1);
        assert(Definition<50>::BitBeginIndex == 50);
        assert(Definition<50>::BitEndIndex == 51);
        assert(Definition<50>::Mask == 0x4000000000000);
        assert(Definition<50>::NegationMask == 0xFFFBFFFFFFFFFFFF);
        assert(Definition<50>::BitCarryIndex == 51);
        assert(Definition<50>::BitCarryMask == 0x8000000000000);
    }
    {
        assert(Definition<51>::AllocationSize == 8);
        assert((std::is_same<typename Definition<51>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<51>::BitSize == 1);
        assert(Definition<51>::BitBeginIndex == 51);
        assert(Definition<51>::BitEndIndex == 52);
        assert(Definition<51>::Mask == 0x8000000000000);
        assert(Definition<51>::NegationMask == 0xFFF7FFFFFFFFFFFF);
        assert(Definition<51>::BitCarryIndex == 52);
        assert(Definition<51>::BitCarryMask == 0x10000000000000);
    }
    {
        assert(Definition<52>::AllocationSize == 8);
        assert((std::is_same<typename Definition<52>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<52>::BitSize == 1);
        assert(Definition<52>::BitBeginIndex == 52);
        assert(Definition<52>::BitEndIndex == 53);
        assert(Definition<52>::Mask == 0x10000000000000);
        assert(Definition<52>::NegationMask == 0xFFEFFFFFFFFFFFFF);
        assert(Definition<52>::BitCarryIndex == 53);
        assert(Definition<52>::BitCarryMask == 0x20000000000000);
    }
    {
        assert(Definition<53>::AllocationSize == 8);
        assert((std::is_same<typename Definition<53>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<53>::BitSize == 1);
        assert(Definition<53>::BitBeginIndex == 53);
        assert(Definition<53>::BitEndIndex == 54);
        assert(Definition<53>::Mask == 0x20000000000000);
        assert(Definition<53>::NegationMask == 0xFFDFFFFFFFFFFFFF);
        assert(Definition<53>::BitCarryIndex == 54);
        assert(Definition<53>::BitCarryMask == 0x40000000000000);
    }
    {
        assert(Definition<54>::AllocationSize == 8);
        assert((std::is_same<typename Definition<54>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<54>::BitSize == 1);
        assert(Definition<54>::BitBeginIndex == 54);
        assert(Definition<54>::BitEndIndex == 55);
        assert(Definition<54>::Mask == 0x40000000000000);
        assert(Definition<54>::NegationMask == 0xFFBFFFFFFFFFFFFF);
        assert(Definition<54>::BitCarryIndex == 55);
        assert(Definition<54>::BitCarryMask == 0x80000000000000);
    }
    {
        assert(Definition<55>::AllocationSize == 8);
        assert((std::is_same<typename Definition<55>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<55>::BitSize == 1);
        assert(Definition<55>::BitBeginIndex == 55);
        assert(Definition<55>::BitEndIndex == 56);
        assert(Definition<55>::Mask == 0x80000000000000);
        assert(Definition<55>::NegationMask == 0xFF7FFFFFFFFFFFFF);
        assert(Definition<55>::BitCarryIndex == 56);
        assert(Definition<55>::BitCarryMask == 0x100000000000000);
    }
    
    
    {
        assert(Definition<56>::AllocationSize == 8);
        assert((std::is_same<typename Definition<56>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<56>::BitSize == 1);
        assert(Definition<56>::BitBeginIndex == 56);
        assert(Definition<56>::BitEndIndex == 57);
        assert(Definition<56>::Mask == 0x100000000000000);
        assert(Definition<56>::NegationMask == 0xFEFFFFFFFFFFFFFF);
        assert(Definition<56>::BitCarryIndex == 57);
        assert(Definition<56>::BitCarryMask == 0x200000000000000);
    }
    {
        assert(Definition<57>::AllocationSize == 8);
        assert((std::is_same<typename Definition<57>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<57>::BitSize == 1);
        assert(Definition<57>::BitBeginIndex == 57);
        assert(Definition<57>::BitEndIndex == 58);
        assert(Definition<57>::Mask == 0x200000000000000);
        assert(Definition<57>::NegationMask == 0xFDFFFFFFFFFFFFFF);
        assert(Definition<57>::BitCarryIndex == 58);
        assert(Definition<57>::BitCarryMask == 0x400000000000000);
    }
    {
        assert(Definition<58>::AllocationSize == 8);
        assert((std::is_same<typename Definition<58>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<58>::BitSize == 1);
        assert(Definition<58>::BitBeginIndex == 58);
        assert(Definition<58>::BitEndIndex == 59);
        assert(Definition<58>::Mask == 0x400000000000000);
        assert(Definition<58>::NegationMask == 0xFBFFFFFFFFFFFFFF);
        assert(Definition<58>::BitCarryIndex == 59);
        assert(Definition<58>::BitCarryMask == 0x800000000000000);
    }
    {
        assert(Definition<59>::AllocationSize == 8);
        assert((std::is_same<typename Definition<59>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<59>::BitSize == 1);
        assert(Definition<59>::BitBeginIndex == 59);
        assert(Definition<59>::BitEndIndex == 60);
        assert(Definition<59>::Mask == 0x800000000000000);
        assert(Definition<59>::NegationMask == 0xF7FFFFFFFFFFFFFF);
        assert(Definition<59>::BitCarryIndex == 60);
        assert(Definition<59>::BitCarryMask == 0x1000000000000000);
    }
    {
        assert(Definition<60>::AllocationSize == 8);
        assert((std::is_same<typename Definition<60>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<60>::BitSize == 1);
        assert(Definition<60>::BitBeginIndex == 60);
        assert(Definition<60>::BitEndIndex == 61);
        assert(Definition<60>::Mask == 0x1000000000000000);
        assert(Definition<60>::NegationMask == 0xEFFFFFFFFFFFFFFF);
        assert(Definition<60>::BitCarryIndex == 61);
        assert(Definition<60>::BitCarryMask == 0x2000000000000000);
    }
    {
        assert(Definition<61>::AllocationSize == 8);
        assert((std::is_same<typename Definition<61>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<61>::BitSize == 1);
        assert(Definition<61>::BitBeginIndex == 61);
        assert(Definition<61>::BitEndIndex == 62);
        assert(Definition<61>::Mask == 0x2000000000000000);
        assert(Definition<61>::NegationMask == 0xDFFFFFFFFFFFFFFF);
        assert(Definition<61>::BitCarryIndex == 62);
        assert(Definition<61>::BitCarryMask == 0x4000000000000000);
    }
    {
        assert(Definition<62>::AllocationSize == 8);
        assert((std::is_same<typename Definition<62>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<62>::BitSize == 1);
        assert(Definition<62>::BitBeginIndex == 62);
        assert(Definition<62>::BitEndIndex == 63);
        assert(Definition<62>::Mask == 0x4000000000000000);
        assert(Definition<62>::NegationMask == 0xBFFFFFFFFFFFFFFF);
        assert(Definition<62>::BitCarryIndex == 63);
        assert(Definition<62>::BitCarryMask == 0x8000000000000000);
    }
    {
        assert(Definition<63>::AllocationSize == 8);
        assert((std::is_same<typename Definition<63>::ValueType, 
            std::uint64_t>::value));
        assert(Definition<63>::BitSize == 1);
        assert(Definition<63>::BitBeginIndex == 63);
        assert(Definition<63>::BitEndIndex == 64);
        assert(Definition<63>::Mask == 0x8000000000000000);
        assert(Definition<63>::NegationMask == 0x7FFFFFFFFFFFFFFF);
        assert(Definition<63>::BitCarryIndex == 0);
        assert(Definition<63>::BitCarryMask == 0x01);
    }
    ///////

    {
        assert((Definition<0, 2>::AllocationSize == 1));
        assert((std::is_same<typename Definition<0, 2>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<0, 2>::BitSize == 2));
        assert((Definition<0, 2>::BitBeginIndex == 0));
        assert((Definition<0, 2>::BitEndIndex == 2));
        assert((Definition<0, 2>::Mask == 0x03));
        assert((Definition<0, 2>::NegationMask == 0xFC));
        assert((Definition<0, 2>::BitCarryIndex == 2));
        assert((Definition<0, 2>::BitCarryMask == 0x04));
    }
    {
        assert((Definition<0, 4>::AllocationSize == 1));
        assert((std::is_same<typename Definition<0, 4>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<0, 4>::BitSize == 4));
        assert((Definition<0, 4>::BitBeginIndex == 0));
        assert((Definition<0, 4>::BitEndIndex == 4));
        assert((Definition<0, 4>::Mask == 0x0F));
        assert((Definition<0, 4>::NegationMask == 0xF0));
        assert((Definition<0, 4>::BitCarryIndex == 4));
        assert((Definition<0, 4>::BitCarryMask == 0x10));
    }
    {
        assert((Definition<0, 8>::AllocationSize == 1));
        assert((std::is_same<typename Definition<0, 8>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<0, 8>::BitSize == 8));
        assert((Definition<0, 8>::BitBeginIndex == 0));
        assert((Definition<0, 8>::BitEndIndex == 8));
        assert((Definition<0, 8>::Mask == 0xFF));
        assert((Definition<0, 8>::NegationMask == 0x00));
        assert((Definition<0, 8>::BitCarryIndex == 0));
        assert((Definition<0, 8>::BitCarryMask == 0x01));
    }
    {
        assert((Definition<0, 12>::AllocationSize == 2));
        assert((std::is_same<typename Definition<0, 12>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<0, 12>::BitSize == 12));
        assert((Definition<0, 12>::BitBeginIndex == 0));
        assert((Definition<0, 12>::BitEndIndex == 12));
        assert((Definition<0, 12>::Mask == 0x0FFF));
        assert((Definition<0, 12>::NegationMask == 0xF000));
        assert((Definition<0, 12>::BitCarryIndex == 12));
        assert((Definition<0, 12>::BitCarryMask == 0x1000));
    }
    {
        assert((Definition<0, 16>::AllocationSize == 2));
        assert((std::is_same<typename Definition<0, 16>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<0, 16>::BitSize == 16));
        assert((Definition<0, 16>::BitBeginIndex == 0));
        assert((Definition<0, 16>::BitEndIndex == 16));
        assert((Definition<0, 16>::Mask == 0xFFFF));
        assert((Definition<0, 16>::NegationMask == 0x00));
        assert((Definition<0, 16>::BitCarryIndex == 0));
        assert((Definition<0, 16>::BitCarryMask == 0x01));
    }
    {
        assert((Definition<0, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<0, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<0, 20>::BitSize == 20));
        assert((Definition<0, 20>::BitBeginIndex == 0));
        assert((Definition<0, 20>::BitEndIndex == 20));
        assert((Definition<0, 20>::Mask == 0x000FFFFF));
        assert((Definition<0, 20>::NegationMask == 0xFFF00000));
        assert((Definition<0, 20>::BitCarryIndex == 20));
        assert((Definition<0, 20>::BitCarryMask == 0x100000));
    }
    {
        assert((Definition<0, 24>::AllocationSize == 4));
        assert((std::is_same<typename Definition<0, 24>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<0, 24>::BitSize == 24));
        assert((Definition<0, 24>::BitBeginIndex == 0));
        assert((Definition<0, 24>::BitEndIndex == 24));
        assert((Definition<0, 24>::Mask == 0x00FFFFFF));
        assert((Definition<0, 24>::NegationMask == 0xFF000000));
        assert((Definition<0, 24>::BitCarryIndex == 24));
        assert((Definition<0, 24>::BitCarryMask == 0x1000000));
    }
    {
        assert((Definition<0, 28>::AllocationSize == 4));
        assert((std::is_same<typename Definition<0, 28>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<0, 28>::BitSize == 28));
        assert((Definition<0, 28>::BitBeginIndex == 0));
        assert((Definition<0, 28>::BitEndIndex == 28));
        assert((Definition<0, 28>::Mask == 0x0FFFFFFF));
        assert((Definition<0, 28>::NegationMask == 0xF0000000));
        assert((Definition<0, 28>::BitCarryIndex == 28));
        assert((Definition<0, 28>::BitCarryMask == 0x10000000));
    }
    {
        assert((Definition<0, 32>::AllocationSize == 4));
        assert((std::is_same<typename Definition<0, 32>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<0, 32>::BitSize == 32));
        assert((Definition<0, 32>::BitBeginIndex == 0));
        assert((Definition<0, 32>::BitEndIndex == 32));
        assert((Definition<0, 32>::Mask == 0xFFFFFFFF));
        assert((Definition<0, 32>::NegationMask == 0x0));
        assert((Definition<0, 32>::BitCarryIndex == 0));
        assert((Definition<0, 32>::BitCarryMask == 0x01));
    }
    {
        assert((Definition<0, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 36>::BitSize == 36));
        assert((Definition<0, 36>::BitBeginIndex == 0));
        assert((Definition<0, 36>::BitEndIndex == 36));
        assert((Definition<0, 36>::Mask == 0x0000000FFFFFFFFF));
        assert((Definition<0, 36>::NegationMask == 0xFFFFFFF000000000));
        assert((Definition<0, 36>::BitCarryIndex == 36));
        assert((Definition<0, 36>::BitCarryMask == 0x1000000000));
    }
    {
        assert((Definition<0, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 40>::BitSize == 40));
        assert((Definition<0, 40>::BitBeginIndex == 0));
        assert((Definition<0, 40>::BitEndIndex == 40));
        assert((Definition<0, 40>::Mask == 0x000000FFFFFFFFFF));
        assert((Definition<0, 40>::NegationMask == 0xFFFFFF0000000000));
        assert((Definition<0, 40>::BitCarryIndex == 40));
        assert((Definition<0, 40>::BitCarryMask == 0x10000000000));
    }
    {
        assert((Definition<0, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 44>::BitSize == 44));
        assert((Definition<0, 44>::BitBeginIndex == 0));
        assert((Definition<0, 44>::BitEndIndex == 44));
        assert((Definition<0, 44>::Mask == 0x00000FFFFFFFFFFF));
        assert((Definition<0, 44>::NegationMask == 0xFFFFF00000000000));
        assert((Definition<0, 44>::BitCarryIndex == 44));
        assert((Definition<0, 44>::BitCarryMask == 0x100000000000));
    }
    {
        assert((Definition<0, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 48>::BitSize == 48));
        assert((Definition<0, 48>::BitBeginIndex == 0));
        assert((Definition<0, 48>::BitEndIndex == 48));
        assert((Definition<0, 48>::Mask == 0x0000FFFFFFFFFFFF));
        assert((Definition<0, 48>::NegationMask == 0xFFFF000000000000));
        assert((Definition<0, 48>::BitCarryIndex == 48));
        assert((Definition<0, 48>::BitCarryMask == 0x1000000000000));
    }
    {
        assert((Definition<0, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 52>::BitSize == 52));
        assert((Definition<0, 52>::BitBeginIndex == 0));
        assert((Definition<0, 52>::BitEndIndex == 52));
        assert((Definition<0, 52>::Mask == 0x000FFFFFFFFFFFFF));
        assert((Definition<0, 52>::NegationMask == 0xFFF0000000000000));
        assert((Definition<0, 52>::BitCarryIndex == 52));
        assert((Definition<0, 52>::BitCarryMask == 0x10000000000000));
    }
    {
        assert((Definition<0, 56>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 56>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 56>::BitSize == 56));
        assert((Definition<0, 56>::BitBeginIndex == 0));
        assert((Definition<0, 56>::BitEndIndex == 56));
        assert((Definition<0, 56>::Mask == 0x00FFFFFFFFFFFFFF));
        assert((Definition<0, 56>::NegationMask == 0xFF00000000000000));
        assert((Definition<0, 56>::BitCarryIndex == 56));
        assert((Definition<0, 56>::BitCarryMask == 0x100000000000000));
    }
    {
        assert((Definition<0, 60>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 60>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 60>::BitSize == 60));
        assert((Definition<0, 60>::BitBeginIndex == 0));
        assert((Definition<0, 60>::BitEndIndex == 60));
        assert((Definition<0, 60>::Mask == 0x0FFFFFFFFFFFFFFF));
        assert((Definition<0, 60>::NegationMask == 0xF000000000000000));
        assert((Definition<0, 60>::BitCarryIndex == 60));
        assert((Definition<0, 60>::BitCarryMask == 0x1000000000000000));
    }
    {
        assert((Definition<0, 64>::AllocationSize == 8));
        assert((std::is_same<typename Definition<0, 64>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<0, 64>::BitSize == 64));
        assert((Definition<0, 64>::BitBeginIndex == 0));
        assert((Definition<0, 64>::BitEndIndex == 64));
        assert((Definition<0, 64>::Mask == 0xFFFFFFFFFFFFFFFF));
        assert((Definition<0, 64>::NegationMask == 0x0000000000000000));
        assert((Definition<0, 64>::BitCarryIndex == 0));
        assert((Definition<0, 64>::BitCarryMask == 0x01));
    }

    ////////

    {
        assert((Definition<1, 2>::AllocationSize == 1));
        assert((std::is_same<typename Definition<1, 2>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<1, 2>::BitSize == 2));
        assert((Definition<1, 2>::BitBeginIndex == 1));
        assert((Definition<1, 2>::BitEndIndex == 3));
        assert((Definition<1, 2>::Mask == 0x06));
        assert((Definition<1, 2>::NegationMask == 0xF9));
        assert((Definition<1, 2>::BitCarryIndex == 3));
        assert((Definition<1, 2>::BitCarryMask == 0x08));
    }
    {
        assert((Definition<1, 4>::AllocationSize == 1));
        assert((std::is_same<typename Definition<1, 4>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<1, 4>::BitSize == 4));
        assert((Definition<1, 4>::BitBeginIndex == 1));
        assert((Definition<1, 4>::BitEndIndex == 5));
        assert((Definition<1, 4>::Mask == 0x1E));
        assert((Definition<1, 4>::NegationMask == 0xE1));
        assert((Definition<1, 4>::BitCarryIndex == 5));
        assert((Definition<1, 4>::BitCarryMask == 0x20));
    }
    {
        assert((Definition<1, 8>::AllocationSize == 2));
        assert((std::is_same<typename Definition<1, 8>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<1, 8>::BitSize == 8));
        assert((Definition<1, 8>::BitBeginIndex == 1));
        assert((Definition<1, 8>::BitEndIndex == 9));
        assert((Definition<1, 8>::Mask == 0x01FE));
        assert((Definition<1, 8>::NegationMask == 0xFE01));
        assert((Definition<1, 8>::BitCarryIndex == 9));
        assert((Definition<1, 8>::BitCarryMask == 0x0200));
    }
    {
        assert((Definition<1, 12>::AllocationSize == 2));
        assert((std::is_same<typename Definition<1, 12>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<1, 12>::BitSize == 12));
        assert((Definition<1, 12>::BitBeginIndex == 1));
        assert((Definition<1, 12>::BitEndIndex == 13));
        assert((Definition<1, 12>::Mask == 0x1FFE));
        assert((Definition<1, 12>::NegationMask == 0xE001));
        assert((Definition<1, 12>::BitCarryIndex == 13));
        assert((Definition<1, 12>::BitCarryMask == 0x2000));
    }
    {
        assert((Definition<1, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<1, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<1, 16>::BitSize == 16));
        assert((Definition<1, 16>::BitBeginIndex == 1));
        assert((Definition<1, 16>::BitEndIndex == 17));
        assert((Definition<1, 16>::Mask == 0x0001FFFE));
        assert((Definition<1, 16>::NegationMask == 0xFFFE0001));
        assert((Definition<1, 16>::BitCarryIndex == 17));
        assert((Definition<1, 16>::BitCarryMask == 0x20000));
    }
    {
        assert((Definition<1, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<1, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<1, 20>::BitSize == 20));
        assert((Definition<1, 20>::BitBeginIndex == 1));
        assert((Definition<1, 20>::BitEndIndex == 21));
        assert((Definition<1, 20>::Mask == 0x001FFFFE));
        assert((Definition<1, 20>::NegationMask == 0xFFE00001));
        assert((Definition<1, 20>::BitCarryIndex == 21));
        assert((Definition<1, 20>::BitCarryMask == 0x200000));
    }
    {
        assert((Definition<1, 24>::AllocationSize == 4));
        assert((std::is_same<typename Definition<1, 24>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<1, 24>::BitSize == 24));
        assert((Definition<1, 24>::BitBeginIndex == 1));
        assert((Definition<1, 24>::BitEndIndex == 25));
        assert((Definition<1, 24>::Mask == 0x01FFFFFE));
        assert((Definition<1, 24>::NegationMask == 0xFE000001));
        assert((Definition<1, 24>::BitCarryIndex == 25));
        assert((Definition<1, 24>::BitCarryMask == 0x2000000));
    }
    {
        assert((Definition<1, 28>::AllocationSize == 4));
        assert((std::is_same<typename Definition<1, 28>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<1, 28>::BitSize == 28));
        assert((Definition<1, 28>::BitBeginIndex == 1));
        assert((Definition<1, 28>::BitEndIndex == 29));
        assert((Definition<1, 28>::Mask == 0x1FFFFFFE));
        assert((Definition<1, 28>::NegationMask == 0xE0000001));
        assert((Definition<1, 28>::BitCarryIndex == 29));
        assert((Definition<1, 28>::BitCarryMask == 0x20000000));
    }
    {
        assert((Definition<1, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 32>::BitSize == 32));
        assert((Definition<1, 32>::BitBeginIndex == 1));
        assert((Definition<1, 32>::BitEndIndex == 33));
        assert((Definition<1, 32>::Mask == 0x00000001FFFFFFFE));
        assert((Definition<1, 32>::NegationMask == 0xFFFFFFFE00000001));
        assert((Definition<1, 32>::BitCarryIndex == 33));
        assert((Definition<1, 32>::BitCarryMask == 0x200000000));
    }
    {
        assert((Definition<1, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 36>::BitSize == 36));
        assert((Definition<1, 36>::BitBeginIndex == 1));
        assert((Definition<1, 36>::BitEndIndex == 37));
        assert((Definition<1, 36>::Mask == 0x0000001FFFFFFFFE));
        assert((Definition<1, 36>::NegationMask == 0xFFFFFFE000000001));
        assert((Definition<1, 36>::BitCarryIndex == 37));
        assert((Definition<1, 36>::BitCarryMask == 0x2000000000));
    }
    {
        assert((Definition<1, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 40>::BitSize == 40));
        assert((Definition<1, 40>::BitBeginIndex == 1));
        assert((Definition<1, 40>::BitEndIndex == 41));
        assert((Definition<1, 40>::Mask == 0x000001FFFFFFFFFE));
        assert((Definition<1, 40>::NegationMask == 0xFFFFFE0000000001));
        assert((Definition<1, 40>::BitCarryIndex == 41));
        assert((Definition<1, 40>::BitCarryMask == 0x20000000000));
    }
    {
        assert((Definition<1, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 44>::BitSize == 44));
        assert((Definition<1, 44>::BitBeginIndex == 1));
        assert((Definition<1, 44>::BitEndIndex == 45));
        assert((Definition<1, 44>::Mask == 0x00001FFFFFFFFFFE));
        assert((Definition<1, 44>::NegationMask == 0xFFFFE00000000001));
        assert((Definition<1, 44>::BitCarryIndex == 45));
        assert((Definition<1, 44>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<1, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 48>::BitSize == 48));
        assert((Definition<1, 48>::BitBeginIndex == 1));
        assert((Definition<1, 48>::BitEndIndex == 49));
        assert((Definition<1, 48>::Mask == 0x0001FFFFFFFFFFFE));
        assert((Definition<1, 48>::NegationMask == 0xFFFE000000000001));
        assert((Definition<1, 48>::BitCarryIndex == 49));
        assert((Definition<1, 48>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<1, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 52>::BitSize == 52));
        assert((Definition<1, 52>::BitBeginIndex == 1));
        assert((Definition<1, 52>::BitEndIndex == 53));
        assert((Definition<1, 52>::Mask == 0x001FFFFFFFFFFFFE));
        assert((Definition<1, 52>::NegationMask == 0xFFE0000000000001));
        assert((Definition<1, 52>::BitCarryIndex == 53));
        assert((Definition<1, 52>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<1, 56>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 56>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 56>::BitSize == 56));
        assert((Definition<1, 56>::BitBeginIndex == 1));
        assert((Definition<1, 56>::BitEndIndex == 57));
        assert((Definition<1, 56>::Mask == 0x01FFFFFFFFFFFFFE));
        assert((Definition<1, 56>::NegationMask == 0xFE00000000000001));
        assert((Definition<1, 56>::BitCarryIndex == 57));
        assert((Definition<1, 56>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<1, 60>::AllocationSize == 8));
        assert((std::is_same<typename Definition<1, 60>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<1, 60>::BitSize == 60));
        assert((Definition<1, 60>::BitBeginIndex == 1));
        assert((Definition<1, 60>::BitEndIndex == 61));
        assert((Definition<1, 60>::Mask == 0x1FFFFFFFFFFFFFFE));
        assert((Definition<1, 60>::NegationMask == 0xE000000000000001));
        assert((Definition<1, 60>::BitCarryIndex == 61));
        assert((Definition<1, 60>::BitCarryMask == 0x2000000000000000));
    }

    ////////

    {
        assert((Definition<2, 2>::AllocationSize == 1));
        assert((std::is_same<typename Definition<2, 2>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<2, 2>::BitSize == 2));
        assert((Definition<2, 2>::BitBeginIndex == 2));
        assert((Definition<2, 2>::BitEndIndex == 4));
        assert((Definition<2, 2>::Mask == 0x0C));
        assert((Definition<2, 2>::NegationMask == 0xF3));
        assert((Definition<2, 2>::BitCarryIndex == 4));
        assert((Definition<2, 2>::BitCarryMask == 0x10));
    }
    {
        assert((Definition<2, 4>::AllocationSize == 1));
        assert((std::is_same<typename Definition<2, 4>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<2, 4>::BitSize == 4));
        assert((Definition<2, 4>::BitBeginIndex == 2));
        assert((Definition<2, 4>::BitEndIndex == 6));
        assert((Definition<2, 4>::Mask == 0x3C));
        assert((Definition<2, 4>::NegationMask == 0xC3));
        assert((Definition<2, 4>::BitCarryIndex == 6));
        assert((Definition<2, 4>::BitCarryMask == 0x40));
    }
    {
        assert((Definition<2, 8>::AllocationSize == 2));
        assert((std::is_same<typename Definition<2, 8>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<2, 8>::BitSize == 8));
        assert((Definition<2, 8>::BitBeginIndex == 2));
        assert((Definition<2, 8>::BitEndIndex == 10));
        assert((Definition<2, 8>::Mask == 0x03FC));
        assert((Definition<2, 8>::NegationMask == 0xFC03));
        assert((Definition<2, 8>::BitCarryIndex == 10));
        assert((Definition<2, 8>::BitCarryMask == 0x0400));
    }
    {
        assert((Definition<2, 12>::AllocationSize == 2));
        assert((std::is_same<typename Definition<2, 12>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<2, 12>::BitSize == 12));
        assert((Definition<2, 12>::BitBeginIndex == 2));
        assert((Definition<2, 12>::BitEndIndex == 14));
        assert((Definition<2, 12>::Mask == 0x3FFC));
        assert((Definition<2, 12>::NegationMask == 0xC003));
        assert((Definition<2, 12>::BitCarryIndex == 14));
        assert((Definition<2, 12>::BitCarryMask == 0x4000));
    }
    {
        assert((Definition<2, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<2, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<2, 16>::BitSize == 16));
        assert((Definition<2, 16>::BitBeginIndex == 2));
        assert((Definition<2, 16>::BitEndIndex == 18));
        assert((Definition<2, 16>::Mask == 0x0003FFFC));
        assert((Definition<2, 16>::NegationMask == 0xFFFC0003));
        assert((Definition<2, 16>::BitCarryIndex == 18));
        assert((Definition<2, 16>::BitCarryMask == 0x40000));
    }
    {
        assert((Definition<2, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<2, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<2, 20>::BitSize == 20));
        assert((Definition<2, 20>::BitBeginIndex == 2));
        assert((Definition<2, 20>::BitEndIndex == 22));
        assert((Definition<2, 20>::Mask == 0x003FFFFC));
        assert((Definition<2, 20>::NegationMask == 0xFFC00003));
        assert((Definition<2, 20>::BitCarryIndex == 22));
        assert((Definition<2, 20>::BitCarryMask == 0x400000));
    }
    {
        assert((Definition<2, 24>::AllocationSize == 4));
        assert((std::is_same<typename Definition<2, 24>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<2, 24>::BitSize == 24));
        assert((Definition<2, 24>::BitBeginIndex == 2));
        assert((Definition<2, 24>::BitEndIndex == 26));
        assert((Definition<2, 24>::Mask == 0x03FFFFFC));
        assert((Definition<2, 24>::NegationMask == 0xFC000003));
        assert((Definition<2, 24>::BitCarryIndex == 26));
        assert((Definition<2, 24>::BitCarryMask == 0x4000000));
    }
    {
        assert((Definition<2, 28>::AllocationSize == 4));
        assert((std::is_same<typename Definition<2, 28>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<2, 28>::BitSize == 28));
        assert((Definition<2, 28>::BitBeginIndex == 2));
        assert((Definition<2, 28>::BitEndIndex == 30));
        assert((Definition<2, 28>::Mask == 0x3FFFFFFC));
        assert((Definition<2, 28>::NegationMask == 0xC0000003));
        assert((Definition<2, 28>::BitCarryIndex == 30));
        assert((Definition<2, 28>::BitCarryMask == 0x40000000));
    }
    {
        assert((Definition<2, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 32>::BitSize == 32));
        assert((Definition<2, 32>::BitBeginIndex == 2));
        assert((Definition<2, 32>::BitEndIndex == 34));
        assert((Definition<2, 32>::Mask == 0x00000003FFFFFFFC));
        assert((Definition<2, 32>::NegationMask == 0xFFFFFFFC00000003));
        assert((Definition<2, 32>::BitCarryIndex == 34));
        assert((Definition<2, 32>::BitCarryMask == 0x400000000));
    }
    {
        assert((Definition<2, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 36>::BitSize == 36));
        assert((Definition<2, 36>::BitBeginIndex == 2));
        assert((Definition<2, 36>::BitEndIndex == 38));
        assert((Definition<2, 36>::Mask == 0x0000003FFFFFFFFC));
        assert((Definition<2, 36>::NegationMask == 0xFFFFFFC000000003));
        assert((Definition<2, 36>::BitCarryIndex == 38));
        assert((Definition<2, 36>::BitCarryMask == 0x4000000000));
    }
    {
        assert((Definition<2, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 40>::BitSize == 40));
        assert((Definition<2, 40>::BitBeginIndex == 2));
        assert((Definition<2, 40>::BitEndIndex == 42));
        assert((Definition<2, 40>::Mask == 0x000003FFFFFFFFFC));
        assert((Definition<2, 40>::NegationMask == 0xFFFFFC0000000003));
        assert((Definition<2, 40>::BitCarryIndex == 42));
        assert((Definition<2, 40>::BitCarryMask == 0x40000000000));
    }
    {
        assert((Definition<2, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 44>::BitSize == 44));
        assert((Definition<2, 44>::BitBeginIndex == 2));
        assert((Definition<2, 44>::BitEndIndex == 46));
        assert((Definition<2, 44>::Mask == 0x00003FFFFFFFFFFC));
        assert((Definition<2, 44>::NegationMask == 0xFFFFC00000000003));
        assert((Definition<2, 44>::BitCarryIndex == 46));
        assert((Definition<2, 44>::BitCarryMask == 0x400000000000));
    }
    {
        assert((Definition<2, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 48>::BitSize == 48));
        assert((Definition<2, 48>::BitBeginIndex == 2));
        assert((Definition<2, 48>::BitEndIndex == 50));
        assert((Definition<2, 48>::Mask == 0x0003FFFFFFFFFFFC));
        assert((Definition<2, 48>::NegationMask == 0xFFFC000000000003));
        assert((Definition<2, 48>::BitCarryIndex == 50));
        assert((Definition<2, 48>::BitCarryMask == 0x4000000000000));
    }
    {
        assert((Definition<2, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 52>::BitSize == 52));
        assert((Definition<2, 52>::BitBeginIndex == 2));
        assert((Definition<2, 52>::BitEndIndex == 54));
        assert((Definition<2, 52>::Mask == 0x003FFFFFFFFFFFFC));
        assert((Definition<2, 52>::NegationMask == 0xFFC0000000000003));
        assert((Definition<2, 52>::BitCarryIndex == 54));
        assert((Definition<2, 52>::BitCarryMask == 0x40000000000000));
    }
    {
        assert((Definition<2, 56>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 56>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 56>::BitSize == 56));
        assert((Definition<2, 56>::BitBeginIndex == 2));
        assert((Definition<2, 56>::BitEndIndex == 58));
        assert((Definition<2, 56>::Mask == 0x03FFFFFFFFFFFFFC));
        assert((Definition<2, 56>::NegationMask == 0xFC00000000000003));
        assert((Definition<2, 56>::BitCarryIndex == 58));
        assert((Definition<2, 56>::BitCarryMask == 0x400000000000000));
    }
    {
        assert((Definition<2, 60>::AllocationSize == 8));
        assert((std::is_same<typename Definition<2, 60>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<2, 60>::BitSize == 60));
        assert((Definition<2, 60>::BitBeginIndex == 2));
        assert((Definition<2, 60>::BitEndIndex == 62));
        assert((Definition<2, 60>::Mask == 0x3FFFFFFFFFFFFFFC));
        assert((Definition<2, 60>::NegationMask == 0xC000000000000003));
        assert((Definition<2, 60>::BitCarryIndex == 62));
        assert((Definition<2, 60>::BitCarryMask == 0x4000000000000000));
    }

    ////////

    {
        assert((Definition<3, 2>::AllocationSize == 1));
        assert((std::is_same<typename Definition<3, 2>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<3, 2>::BitSize == 2));
        assert((Definition<3, 2>::BitBeginIndex == 3));
        assert((Definition<3, 2>::BitEndIndex == 5));
        assert((Definition<3, 2>::Mask == 0x18));
        assert((Definition<3, 2>::NegationMask == 0xE7));
        assert((Definition<3, 2>::BitCarryIndex == 5));
        assert((Definition<3, 2>::BitCarryMask == 0x20));
    }
    {
        assert((Definition<3, 4>::AllocationSize == 1));
        assert((std::is_same<typename Definition<3, 4>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<3, 4>::BitSize == 4));
        assert((Definition<3, 4>::BitBeginIndex == 3));
        assert((Definition<3, 4>::BitEndIndex == 7));
        assert((Definition<3, 4>::Mask == 0x78));
        assert((Definition<3, 4>::NegationMask == 0x87));
        assert((Definition<3, 4>::BitCarryIndex == 7));
        assert((Definition<3, 4>::BitCarryMask == 0x80));
    }
    {
        assert((Definition<3, 8>::AllocationSize == 2));
        assert((std::is_same<typename Definition<3, 8>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<3, 8>::BitSize == 8));
        assert((Definition<3, 8>::BitBeginIndex == 3));
        assert((Definition<3, 8>::BitEndIndex == 11));
        assert((Definition<3, 8>::Mask == 0x07F8));
        assert((Definition<3, 8>::NegationMask == 0xF807));
        assert((Definition<3, 8>::BitCarryIndex == 11));
        assert((Definition<3, 8>::BitCarryMask == 0x0800));
    }
    {
        assert((Definition<3, 12>::AllocationSize == 2));
        assert((std::is_same<typename Definition<3, 12>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<3, 12>::BitSize == 12));
        assert((Definition<3, 12>::BitBeginIndex == 3));
        assert((Definition<3, 12>::BitEndIndex == 15));
        assert((Definition<3, 12>::Mask == 0x7FF8));
        assert((Definition<3, 12>::NegationMask == 0x8007));
        assert((Definition<3, 12>::BitCarryIndex == 15));
        assert((Definition<3, 12>::BitCarryMask == 0x8000));
    }
    {
        assert((Definition<3, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<3, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<3, 16>::BitSize == 16));
        assert((Definition<3, 16>::BitBeginIndex == 3));
        assert((Definition<3, 16>::BitEndIndex == 19));
        assert((Definition<3, 16>::Mask == 0x0007FFF8));
        assert((Definition<3, 16>::NegationMask == 0xFFF80007));
        assert((Definition<3, 16>::BitCarryIndex == 19));
        assert((Definition<3, 16>::BitCarryMask == 0x80000));
    }
    {
        assert((Definition<3, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<3, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<3, 20>::BitSize == 20));
        assert((Definition<3, 20>::BitBeginIndex == 3));
        assert((Definition<3, 20>::BitEndIndex == 23));
        assert((Definition<3, 20>::Mask == 0x007FFFF8));
        assert((Definition<3, 20>::NegationMask == 0xFF800007));
        assert((Definition<3, 20>::BitCarryIndex == 23));
        assert((Definition<3, 20>::BitCarryMask == 0x800000));
    }
    {
        assert((Definition<3, 24>::AllocationSize == 4));
        assert((std::is_same<typename Definition<3, 24>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<3, 24>::BitSize == 24));
        assert((Definition<3, 24>::BitBeginIndex == 3));
        assert((Definition<3, 24>::BitEndIndex == 27));
        assert((Definition<3, 24>::Mask == 0x07FFFFF8));
        assert((Definition<3, 24>::NegationMask == 0xF8000007));
        assert((Definition<3, 24>::BitCarryIndex == 27));
        assert((Definition<3, 24>::BitCarryMask == 0x8000000));
    }
    {
        assert((Definition<3, 28>::AllocationSize == 4));
        assert((std::is_same<typename Definition<3, 28>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<3, 28>::BitSize == 28));
        assert((Definition<3, 28>::BitBeginIndex == 3));
        assert((Definition<3, 28>::BitEndIndex == 31));
        assert((Definition<3, 28>::Mask == 0x7FFFFFF8));
        assert((Definition<3, 28>::NegationMask == 0x80000007));
        assert((Definition<3, 28>::BitCarryIndex == 31));
        assert((Definition<3, 28>::BitCarryMask == 0x80000000));
    }
    {
        assert((Definition<3, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 32>::BitSize == 32));
        assert((Definition<3, 32>::BitBeginIndex == 3));
        assert((Definition<3, 32>::BitEndIndex == 35));
        assert((Definition<3, 32>::Mask == 0x00000007FFFFFFF8));
        assert((Definition<3, 32>::NegationMask == 0xFFFFFFF800000007));
        assert((Definition<3, 32>::BitCarryIndex == 35));
        assert((Definition<3, 32>::BitCarryMask == 0x800000000));
    }
    {
        assert((Definition<3, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 36>::BitSize == 36));
        assert((Definition<3, 36>::BitBeginIndex == 3));
        assert((Definition<3, 36>::BitEndIndex == 39));
        assert((Definition<3, 36>::Mask == 0x0000007FFFFFFFF8));
        assert((Definition<3, 36>::NegationMask == 0xFFFFFF8000000007));
        assert((Definition<3, 36>::BitCarryIndex == 39));
        assert((Definition<3, 36>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<3, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 40>::BitSize == 40));
        assert((Definition<3, 40>::BitBeginIndex == 3));
        assert((Definition<3, 40>::BitEndIndex == 43));
        assert((Definition<3, 40>::Mask == 0x000007FFFFFFFFF8));
        assert((Definition<3, 40>::NegationMask == 0xFFFFF80000000007));
        assert((Definition<3, 40>::BitCarryIndex == 43));
        assert((Definition<3, 40>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<3, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 44>::BitSize == 44));
        assert((Definition<3, 44>::BitBeginIndex == 3));
        assert((Definition<3, 44>::BitEndIndex == 47));
        assert((Definition<3, 44>::Mask == 0x00007FFFFFFFFFF8));
        assert((Definition<3, 44>::NegationMask == 0xFFFF800000000007));
        assert((Definition<3, 44>::BitCarryIndex == 47));
        assert((Definition<3, 44>::BitCarryMask == 0x800000000000));
    }
    {
        assert((Definition<3, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 48>::BitSize == 48));
        assert((Definition<3, 48>::BitBeginIndex == 3));
        assert((Definition<3, 48>::BitEndIndex == 51));
        assert((Definition<3, 48>::Mask == 0x0007FFFFFFFFFFF8));
        assert((Definition<3, 48>::NegationMask == 0xFFF8000000000007));
        assert((Definition<3, 48>::BitCarryIndex == 51));
        assert((Definition<3, 48>::BitCarryMask == 0x8000000000000));
    }
    {
        assert((Definition<3, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 52>::BitSize == 52));
        assert((Definition<3, 52>::BitBeginIndex == 3));
        assert((Definition<3, 52>::BitEndIndex == 55));
        assert((Definition<3, 52>::Mask == 0x007FFFFFFFFFFFF8));
        assert((Definition<3, 52>::NegationMask == 0xFF80000000000007));
        assert((Definition<3, 52>::BitCarryIndex == 55));
        assert((Definition<3, 52>::BitCarryMask == 0x80000000000000));
    }
    {
        assert((Definition<3, 56>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 56>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 56>::BitSize == 56));
        assert((Definition<3, 56>::BitBeginIndex == 3));
        assert((Definition<3, 56>::BitEndIndex == 59));
        assert((Definition<3, 56>::Mask == 0x07FFFFFFFFFFFFF8));
        assert((Definition<3, 56>::NegationMask == 0xF800000000000007));
        assert((Definition<3, 56>::BitCarryIndex == 59));
        assert((Definition<3, 56>::BitCarryMask == 0x800000000000000));
    }
    {
        assert((Definition<3, 60>::AllocationSize == 8));
        assert((std::is_same<typename Definition<3, 60>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<3, 60>::BitSize == 60));
        assert((Definition<3, 60>::BitBeginIndex == 3));
        assert((Definition<3, 60>::BitEndIndex == 63));
        assert((Definition<3, 60>::Mask == 0x7FFFFFFFFFFFFFF8));
        assert((Definition<3, 60>::NegationMask == 0x8000000000000007));
        assert((Definition<3, 60>::BitCarryIndex == 63));
        assert((Definition<3, 60>::BitCarryMask == 0x8000000000000000));
    }

    ///////

    {
        assert((Definition<5, 2>::AllocationSize == 1));
        assert((std::is_same<typename Definition<5, 2>::ValueType, 
            std::uint8_t>::value));
        assert((Definition<5, 2>::BitSize == 2));
        assert((Definition<5, 2>::BitBeginIndex == 5));
        assert((Definition<5, 2>::BitEndIndex == 7));
        assert((Definition<5, 2>::Mask == 0x60));
        assert((Definition<5, 2>::NegationMask == 0x9F));
        assert((Definition<5, 2>::BitCarryIndex == 7));
        assert((Definition<5, 2>::BitCarryMask == 0x80));
    }
    {
        assert((Definition<5, 4>::AllocationSize == 2));
        assert((std::is_same<typename Definition<5, 4>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<5, 4>::BitSize == 4));
        assert((Definition<5, 4>::BitBeginIndex == 5));
        assert((Definition<5, 4>::BitEndIndex == 9));
        assert((Definition<5, 4>::Mask == 0x01E0));
        assert((Definition<5, 4>::NegationMask == 0xFE1F));
        assert((Definition<5, 4>::BitCarryIndex == 9));
        assert((Definition<5, 4>::BitCarryMask == 0x0200));
    }
    {
        assert((Definition<5, 8>::AllocationSize == 2));
        assert((std::is_same<typename Definition<5, 8>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<5, 8>::BitSize == 8));
        assert((Definition<5, 8>::BitBeginIndex == 5));
        assert((Definition<5, 8>::BitEndIndex == 13));
        assert((Definition<5, 8>::Mask == 0x1FE0));
        assert((Definition<5, 8>::NegationMask == 0xE01F));
        assert((Definition<5, 8>::BitCarryIndex == 13));
        assert((Definition<5, 8>::BitCarryMask == 0x2000));
    }
    {
        assert((Definition<5, 12>::AllocationSize == 4));
        assert((std::is_same<typename Definition<5, 12>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<5, 12>::BitSize == 12));
        assert((Definition<5, 12>::BitBeginIndex == 5));
        assert((Definition<5, 12>::BitEndIndex == 17));
        assert((Definition<5, 12>::Mask == 0x0001FFE0));
        assert((Definition<5, 12>::NegationMask == 0xFFFE001F));
        assert((Definition<5, 12>::BitCarryIndex == 17));
        assert((Definition<5, 12>::BitCarryMask == 0x00020000));
    }
    {
        assert((Definition<5, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<5, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<5, 16>::BitSize == 16));
        assert((Definition<5, 16>::BitBeginIndex == 5));
        assert((Definition<5, 16>::BitEndIndex == 21));
        assert((Definition<5, 16>::Mask == 0x001FFFE0));
        assert((Definition<5, 16>::NegationMask == 0xFFE0001F));
        assert((Definition<5, 16>::BitCarryIndex == 21));
        assert((Definition<5, 16>::BitCarryMask == 0x00200000));
    }
    {
        assert((Definition<5, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<5, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<5, 20>::BitSize == 20));
        assert((Definition<5, 20>::BitBeginIndex == 5));
        assert((Definition<5, 20>::BitEndIndex == 25));
        assert((Definition<5, 20>::Mask == 0x01FFFFE0));
        assert((Definition<5, 20>::NegationMask == 0xFE00001F));
        assert((Definition<5, 20>::BitCarryIndex == 25));
        assert((Definition<5, 20>::BitCarryMask == 0x02000000));
    }
    {
        assert((Definition<5, 24>::AllocationSize == 4));
        assert((std::is_same<typename Definition<5, 24>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<5, 24>::BitSize == 24));
        assert((Definition<5, 24>::BitBeginIndex == 5));
        assert((Definition<5, 24>::BitEndIndex == 29));
        assert((Definition<5, 24>::Mask == 0x1FFFFFE0));
        assert((Definition<5, 24>::NegationMask == 0xE000001F));
        assert((Definition<5, 24>::BitCarryIndex == 29));
        assert((Definition<5, 24>::BitCarryMask == 0x20000000));
    }
    {
        assert((Definition<5, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 28>::BitSize == 28));
        assert((Definition<5, 28>::BitBeginIndex == 5));
        assert((Definition<5, 28>::BitEndIndex == 33));
        assert((Definition<5, 28>::Mask == 0x1FFFFFFE0));
        assert((Definition<5, 28>::NegationMask == 0xFFFFFFFE0000001F));
        assert((Definition<5, 28>::BitCarryIndex == 33));
        assert((Definition<5, 28>::BitCarryMask == 0x200000000));
    }
    {
        assert((Definition<5, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 32>::BitSize == 32));
        assert((Definition<5, 32>::BitBeginIndex == 5));
        assert((Definition<5, 32>::BitEndIndex == 37));
        assert((Definition<5, 32>::Mask == 0x1FFFFFFFE0));
        assert((Definition<5, 32>::NegationMask == 0xFFFFFFE00000001F));
        assert((Definition<5, 32>::BitCarryIndex == 37));
        assert((Definition<5, 32>::BitCarryMask == 0x2000000000));
    }
    {
        assert((Definition<5, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 36>::BitSize == 36));
        assert((Definition<5, 36>::BitBeginIndex == 5));
        assert((Definition<5, 36>::BitEndIndex == 41));
        assert((Definition<5, 36>::Mask == 0x1FFFFFFFFE0));
        assert((Definition<5, 36>::NegationMask == 0xFFFFFE000000001F));
        assert((Definition<5, 36>::BitCarryIndex == 41));
        assert((Definition<5, 36>::BitCarryMask == 0x20000000000));
    }
    {
        assert((Definition<5, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 40>::BitSize == 40));
        assert((Definition<5, 40>::BitBeginIndex == 5));
        assert((Definition<5, 40>::BitEndIndex == 45));
        assert((Definition<5, 40>::Mask == 0x1FFFFFFFFFE0));
        assert((Definition<5, 40>::NegationMask == 0xFFFFE0000000001F));
        assert((Definition<5, 40>::BitCarryIndex == 45));
        assert((Definition<5, 40>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<5, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 44>::BitSize == 44));
        assert((Definition<5, 44>::BitBeginIndex == 5));
        assert((Definition<5, 44>::BitEndIndex == 49));
        assert((Definition<5, 44>::Mask == 0x1FFFFFFFFFFE0));
        assert((Definition<5, 44>::NegationMask == 0xFFFE00000000001F));
        assert((Definition<5, 44>::BitCarryIndex == 49));
        assert((Definition<5, 44>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<5, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 48>::BitSize == 48));
        assert((Definition<5, 48>::BitBeginIndex == 5));
        assert((Definition<5, 48>::BitEndIndex == 53));
        assert((Definition<5, 48>::Mask == 0x1FFFFFFFFFFFE0));
        assert((Definition<5, 48>::NegationMask == 0xFFE000000000001F));
        assert((Definition<5, 48>::BitCarryIndex == 53));
        assert((Definition<5, 48>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<5, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 52>::BitSize == 52));
        assert((Definition<5, 52>::BitBeginIndex == 5));
        assert((Definition<5, 52>::BitEndIndex == 57));
        assert((Definition<5, 52>::Mask == 0x1FFFFFFFFFFFFE0));
        assert((Definition<5, 52>::NegationMask == 0xFE0000000000001F));
        assert((Definition<5, 52>::BitCarryIndex == 57));
        assert((Definition<5, 52>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<5, 56>::AllocationSize == 8));
        assert((std::is_same<typename Definition<5, 56>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<5, 56>::BitSize == 56));
        assert((Definition<5, 56>::BitBeginIndex == 5));
        assert((Definition<5, 56>::BitEndIndex == 61));
        assert((Definition<5, 56>::Mask == 0x1FFFFFFFFFFFFFE0));
        assert((Definition<5, 56>::NegationMask == 0xE00000000000001F));
        assert((Definition<5, 56>::BitCarryIndex == 61));
        assert((Definition<5, 56>::BitCarryMask == 0x2000000000000000));
    }

    {
        assert((Definition<5, 60>::IsImplemented == false));
    }
    ///////
    
    {
        assert((Definition<7, 2>::AllocationSize == 2));
        assert((std::is_same<typename Definition<7, 2>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<7, 2>::BitSize == 2));
        assert((Definition<7, 2>::BitBeginIndex == 7));
        assert((Definition<7, 2>::BitEndIndex == 9));
        assert((Definition<7, 2>::Mask == 0x180));
        assert((Definition<7, 2>::NegationMask == 0xFE7F));
        assert((Definition<7, 2>::BitCarryIndex == 9));
        assert((Definition<7, 2>::BitCarryMask == 0x200));
    }
    {
        assert((Definition<7, 4>::AllocationSize == 2));
        assert((std::is_same<typename Definition<7, 4>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<7, 4>::BitSize == 4));
        assert((Definition<7, 4>::BitBeginIndex == 7));
        assert((Definition<7, 4>::BitEndIndex == 11));
        assert((Definition<7, 4>::Mask == 0x780));
        assert((Definition<7, 4>::NegationMask == 0xF87F));
        assert((Definition<7, 4>::BitCarryIndex == 11));
        assert((Definition<7, 4>::BitCarryMask == 0x800));
    }
    {
        assert((Definition<7, 8>::AllocationSize == 2));
        assert((std::is_same<typename Definition<7, 8>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<7, 8>::BitSize == 8));
        assert((Definition<7, 8>::BitBeginIndex == 7));
        assert((Definition<7, 8>::BitEndIndex == 15));
        assert((Definition<7, 8>::Mask == 0x7F80));
        assert((Definition<7, 8>::NegationMask == 0x807F));
        assert((Definition<7, 8>::BitCarryIndex == 15));
        assert((Definition<7, 8>::BitCarryMask == 0x8000));
    }
    {
        assert((Definition<7, 12>::AllocationSize == 4));
        assert((std::is_same<typename Definition<7, 12>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<7, 12>::BitSize == 12));
        assert((Definition<7, 12>::BitBeginIndex == 7));
        assert((Definition<7, 12>::BitEndIndex == 19));
        assert((Definition<7, 12>::Mask == 0x7FF80));
        assert((Definition<7, 12>::NegationMask == 0xFFF8007F));
        assert((Definition<7, 12>::BitCarryIndex == 19));
        assert((Definition<7, 12>::BitCarryMask == 0x80000));
    }
    {
        assert((Definition<7, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<7, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<7, 16>::BitSize == 16));
        assert((Definition<7, 16>::BitBeginIndex == 7));
        assert((Definition<7, 16>::BitEndIndex == 23));
        assert((Definition<7, 16>::Mask == 0x7FFF80));
        assert((Definition<7, 16>::NegationMask == 0xFF80007F));
        assert((Definition<7, 16>::BitCarryIndex == 23));
        assert((Definition<7, 16>::BitCarryMask == 0x800000));
    }
    {
        assert((Definition<7, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<7, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<7, 20>::BitSize == 20));
        assert((Definition<7, 20>::BitBeginIndex == 7));
        assert((Definition<7, 20>::BitEndIndex == 27));
        assert((Definition<7, 20>::Mask == 0x7FFFF80));
        assert((Definition<7, 20>::NegationMask == 0xF800007F));
        assert((Definition<7, 20>::BitCarryIndex == 27));
        assert((Definition<7, 20>::BitCarryMask == 0x8000000));
    }
    {
        assert((Definition<7, 24>::AllocationSize == 4));
        assert((std::is_same<typename Definition<7, 24>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<7, 24>::BitSize == 24));
        assert((Definition<7, 24>::BitBeginIndex == 7));
        assert((Definition<7, 24>::BitEndIndex == 31));
        assert((Definition<7, 24>::Mask == 0x7FFFFF80));
        assert((Definition<7, 24>::NegationMask == 0x8000007F));
        assert((Definition<7, 24>::BitCarryIndex == 31));
        assert((Definition<7, 24>::BitCarryMask == 0x80000000));
    }
    {
        assert((Definition<7, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 28>::BitSize == 28));
        assert((Definition<7, 28>::BitBeginIndex == 7));
        assert((Definition<7, 28>::BitEndIndex == 35));
        assert((Definition<7, 28>::Mask == 0x7FFFFFF80));
        assert((Definition<7, 28>::NegationMask == 0xFFFFFFF80000007F));
        assert((Definition<7, 28>::BitCarryIndex == 35));
        assert((Definition<7, 28>::BitCarryMask == 0x800000000));
    }
    {
        assert((Definition<7, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 32>::BitSize == 32));
        assert((Definition<7, 32>::BitBeginIndex == 7));
        assert((Definition<7, 32>::BitEndIndex == 39));
        assert((Definition<7, 32>::Mask == 0x7FFFFFFF80));
        assert((Definition<7, 32>::NegationMask == 0xFFFFFF800000007F));
        assert((Definition<7, 32>::BitCarryIndex == 39));
        assert((Definition<7, 32>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<7, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 36>::BitSize == 36));
        assert((Definition<7, 36>::BitBeginIndex == 7));
        assert((Definition<7, 36>::BitEndIndex == 43));
        assert((Definition<7, 36>::Mask == 0x7FFFFFFFF80));
        assert((Definition<7, 36>::NegationMask == 0xFFFFF8000000007F));
        assert((Definition<7, 36>::BitCarryIndex == 43));
        assert((Definition<7, 36>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<7, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 40>::BitSize == 40));
        assert((Definition<7, 40>::BitBeginIndex == 7));
        assert((Definition<7, 40>::BitEndIndex == 47));
        assert((Definition<7, 40>::Mask == 0x7FFFFFFFFF80));
        assert((Definition<7, 40>::NegationMask == 0xFFFF80000000007F));
        assert((Definition<7, 40>::BitCarryIndex == 47));
        assert((Definition<7, 40>::BitCarryMask == 0x800000000000));
    }
    {
        assert((Definition<7, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 44>::BitSize == 44));
        assert((Definition<7, 44>::BitBeginIndex == 7));
        assert((Definition<7, 44>::BitEndIndex == 51));
        assert((Definition<7, 44>::Mask == 0x7FFFFFFFFFF80));
        assert((Definition<7, 44>::NegationMask == 0xFFF800000000007F));
        assert((Definition<7, 44>::BitCarryIndex == 51));
        assert((Definition<7, 44>::BitCarryMask == 0x8000000000000));
    }
    {
        assert((Definition<7, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 48>::BitSize == 48));
        assert((Definition<7, 48>::BitBeginIndex == 7));
        assert((Definition<7, 48>::BitEndIndex == 55));
        assert((Definition<7, 48>::Mask == 0x7FFFFFFFFFFF80));
        assert((Definition<7, 48>::NegationMask == 0xFF8000000000007F));
        assert((Definition<7, 48>::BitCarryIndex == 55));
        assert((Definition<7, 48>::BitCarryMask == 0x80000000000000));
    }
    {
        assert((Definition<7, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 52>::BitSize == 52));
        assert((Definition<7, 52>::BitBeginIndex == 7));
        assert((Definition<7, 52>::BitEndIndex == 59));
        assert((Definition<7, 52>::Mask == 0x7FFFFFFFFFFFF80));
        assert((Definition<7, 52>::NegationMask == 0xF80000000000007F));
        assert((Definition<7, 52>::BitCarryIndex == 59));
        assert((Definition<7, 52>::BitCarryMask == 0x800000000000000));
    }
    {
        assert((Definition<7, 56>::AllocationSize == 8));
        assert((std::is_same<typename Definition<7, 56>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<7, 56>::BitSize == 56));
        assert((Definition<7, 56>::BitBeginIndex == 7));
        assert((Definition<7, 56>::BitEndIndex == 63));
        assert((Definition<7, 56>::Mask == 0x7FFFFFFFFFFFFF80));
        assert((Definition<7, 56>::NegationMask == 0x800000000000007F));
        assert((Definition<7, 56>::BitCarryIndex == 63));
        assert((Definition<7, 56>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<9, 2>::AllocationSize == 2));
        assert((std::is_same<typename Definition<9, 2>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<9, 2>::BitSize == 2));
        assert((Definition<9, 2>::BitBeginIndex == 9));
        assert((Definition<9, 2>::BitEndIndex == 11));
        assert((Definition<9, 2>::Mask == 0x600));
        assert((Definition<9, 2>::NegationMask == 0xF9FF));
        assert((Definition<9, 2>::BitCarryIndex == 11));
        assert((Definition<9, 2>::BitCarryMask == 0x800));
    }
    {
        assert((Definition<9, 4>::AllocationSize == 2));
        assert((std::is_same<typename Definition<9, 4>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<9, 4>::BitSize == 4));
        assert((Definition<9, 4>::BitBeginIndex == 9));
        assert((Definition<9, 4>::BitEndIndex == 13));
        assert((Definition<9, 4>::Mask == 0x1E00));
        assert((Definition<9, 4>::NegationMask == 0xE1FF));
        assert((Definition<9, 4>::BitCarryIndex == 13));
        assert((Definition<9, 4>::BitCarryMask == 0x2000));
    }
    {
        assert((Definition<9, 8>::AllocationSize == 4));
        assert((std::is_same<typename Definition<9, 8>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<9, 8>::BitSize == 8));
        assert((Definition<9, 8>::BitBeginIndex == 9));
        assert((Definition<9, 8>::BitEndIndex == 17));
        assert((Definition<9, 8>::Mask == 0x1FE00));
        assert((Definition<9, 8>::NegationMask == 0xFFFE01FF));
        assert((Definition<9, 8>::BitCarryIndex == 17));
        assert((Definition<9, 8>::BitCarryMask == 0x20000));
    }
    {
        assert((Definition<9, 12>::AllocationSize == 4));
        assert((std::is_same<typename Definition<9, 12>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<9, 12>::BitSize == 12));
        assert((Definition<9, 12>::BitBeginIndex == 9));
        assert((Definition<9, 12>::BitEndIndex == 21));
        assert((Definition<9, 12>::Mask == 0x1FFE00));
        assert((Definition<9, 12>::NegationMask == 0xFFE001FF));
        assert((Definition<9, 12>::BitCarryIndex == 21));
        assert((Definition<9, 12>::BitCarryMask == 0x200000));
    }
    {
        assert((Definition<9, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<9, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<9, 16>::BitSize == 16));
        assert((Definition<9, 16>::BitBeginIndex == 9));
        assert((Definition<9, 16>::BitEndIndex == 25));
        assert((Definition<9, 16>::Mask == 0x1FFFE00));
        assert((Definition<9, 16>::NegationMask == 0xFE0001FF));
        assert((Definition<9, 16>::BitCarryIndex == 25));
        assert((Definition<9, 16>::BitCarryMask == 0x2000000));
    }
    {
        assert((Definition<9, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<9, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<9, 20>::BitSize == 20));
        assert((Definition<9, 20>::BitBeginIndex == 9));
        assert((Definition<9, 20>::BitEndIndex == 29));
        assert((Definition<9, 20>::Mask == 0x1FFFFE00));
        assert((Definition<9, 20>::NegationMask == 0xE00001FF));
        assert((Definition<9, 20>::BitCarryIndex == 29));
        assert((Definition<9, 20>::BitCarryMask == 0x20000000));
    }
    {
        assert((Definition<9, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 24>::BitSize == 24));
        assert((Definition<9, 24>::BitBeginIndex == 9));
        assert((Definition<9, 24>::BitEndIndex == 33));
        assert((Definition<9, 24>::Mask == 0x1FFFFFE00));
        assert((Definition<9, 24>::NegationMask == 0xFFFFFFFE000001FF));
        assert((Definition<9, 24>::BitCarryIndex == 33));
        assert((Definition<9, 24>::BitCarryMask == 0x200000000));
    }
    {
        assert((Definition<9, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 28>::BitSize == 28));
        assert((Definition<9, 28>::BitBeginIndex == 9));
        assert((Definition<9, 28>::BitEndIndex == 37));
        assert((Definition<9, 28>::Mask == 0x1FFFFFFE00));
        assert((Definition<9, 28>::NegationMask == 0xFFFFFFE0000001FF));
        assert((Definition<9, 28>::BitCarryIndex == 37));
        assert((Definition<9, 28>::BitCarryMask == 0x2000000000));
    }
    {
        assert((Definition<9, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 32>::BitSize == 32));
        assert((Definition<9, 32>::BitBeginIndex == 9));
        assert((Definition<9, 32>::BitEndIndex == 41));
        assert((Definition<9, 32>::Mask == 0x1FFFFFFFE00));
        assert((Definition<9, 32>::NegationMask == 0xFFFFFE00000001FF));
        assert((Definition<9, 32>::BitCarryIndex == 41));
        assert((Definition<9, 32>::BitCarryMask == 0x20000000000));
    }
    {
        assert((Definition<9, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 36>::BitSize == 36));
        assert((Definition<9, 36>::BitBeginIndex == 9));
        assert((Definition<9, 36>::BitEndIndex == 45));
        assert((Definition<9, 36>::Mask == 0x1FFFFFFFFE00));
        assert((Definition<9, 36>::NegationMask == 0xFFFFE000000001FF));
        assert((Definition<9, 36>::BitCarryIndex == 45));
        assert((Definition<9, 36>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<9, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 40>::BitSize == 40));
        assert((Definition<9, 40>::BitBeginIndex == 9));
        assert((Definition<9, 40>::BitEndIndex == 49));
        assert((Definition<9, 40>::Mask == 0x1FFFFFFFFFE00));
        assert((Definition<9, 40>::NegationMask == 0xFFFE0000000001FF));
        assert((Definition<9, 40>::BitCarryIndex == 49));
        assert((Definition<9, 40>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<9, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 44>::BitSize == 44));
        assert((Definition<9, 44>::BitBeginIndex == 9));
        assert((Definition<9, 44>::BitEndIndex == 53));
        assert((Definition<9, 44>::Mask == 0x1FFFFFFFFFFE00));
        assert((Definition<9, 44>::NegationMask == 0xFFE00000000001FF));
        assert((Definition<9, 44>::BitCarryIndex == 53));
        assert((Definition<9, 44>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<9, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 48>::BitSize == 48));
        assert((Definition<9, 48>::BitBeginIndex == 9));
        assert((Definition<9, 48>::BitEndIndex == 57));
        assert((Definition<9, 48>::Mask == 0x1FFFFFFFFFFFE00));
        assert((Definition<9, 48>::NegationMask == 0xFE000000000001FF));
        assert((Definition<9, 48>::BitCarryIndex == 57));
        assert((Definition<9, 48>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<9, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<9, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<9, 52>::BitSize == 52));
        assert((Definition<9, 52>::BitBeginIndex == 9));
        assert((Definition<9, 52>::BitEndIndex == 61));
        assert((Definition<9, 52>::Mask == 0x1FFFFFFFFFFFFE00));
        assert((Definition<9, 52>::NegationMask == 0xE0000000000001FF));
        assert((Definition<9, 52>::BitCarryIndex == 61));
        assert((Definition<9, 52>::BitCarryMask == 0x2000000000000000));
    }

    ///////
    
    {
        assert((Definition<11, 2>::AllocationSize == 2));
        assert((std::is_same<typename Definition<11, 2>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<11, 2>::BitSize == 2));
        assert((Definition<11, 2>::BitBeginIndex == 11));
        assert((Definition<11, 2>::BitEndIndex == 13));
        assert((Definition<11, 2>::Mask == 0x1800));
        assert((Definition<11, 2>::NegationMask == 0xE7FF));
        assert((Definition<11, 2>::BitCarryIndex == 13));
        assert((Definition<11, 2>::BitCarryMask == 0x2000));
    }
    {
        assert((Definition<11, 4>::AllocationSize == 2));
        assert((std::is_same<typename Definition<11, 4>::ValueType, 
            std::uint16_t>::value));
        assert((Definition<11, 4>::BitSize == 4));
        assert((Definition<11, 4>::BitBeginIndex == 11));
        assert((Definition<11, 4>::BitEndIndex == 15));
        assert((Definition<11, 4>::Mask == 0x7800));
        assert((Definition<11, 4>::NegationMask == 0x87FF));
        assert((Definition<11, 4>::BitCarryIndex == 15));
        assert((Definition<11, 4>::BitCarryMask == 0x8000));
    }
    {
        assert((Definition<11, 8>::AllocationSize == 4));
        assert((std::is_same<typename Definition<11, 8>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<11, 8>::BitSize == 8));
        assert((Definition<11, 8>::BitBeginIndex == 11));
        assert((Definition<11, 8>::BitEndIndex == 19));
        assert((Definition<11, 8>::Mask == 0x7F800));
        assert((Definition<11, 8>::NegationMask == 0xFFF807FF));
        assert((Definition<11, 8>::BitCarryIndex == 19));
        assert((Definition<11, 8>::BitCarryMask == 0x80000));
    }
    {
        assert((Definition<11, 12>::AllocationSize == 4));
        assert((std::is_same<typename Definition<11, 12>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<11, 12>::BitSize == 12));
        assert((Definition<11, 12>::BitBeginIndex == 11));
        assert((Definition<11, 12>::BitEndIndex == 23));
        assert((Definition<11, 12>::Mask == 0x7FF800));
        assert((Definition<11, 12>::NegationMask == 0xFF8007FF));
        assert((Definition<11, 12>::BitCarryIndex == 23));
        assert((Definition<11, 12>::BitCarryMask == 0x800000));
    }
    {
        assert((Definition<11, 16>::AllocationSize == 4));
        assert((std::is_same<typename Definition<11, 16>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<11, 16>::BitSize == 16));
        assert((Definition<11, 16>::BitBeginIndex == 11));
        assert((Definition<11, 16>::BitEndIndex == 27));
        assert((Definition<11, 16>::Mask == 0x7FFF800));
        assert((Definition<11, 16>::NegationMask == 0xF80007FF));
        assert((Definition<11, 16>::BitCarryIndex == 27));
        assert((Definition<11, 16>::BitCarryMask == 0x8000000));
    }
    {
        assert((Definition<11, 20>::AllocationSize == 4));
        assert((std::is_same<typename Definition<11, 20>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<11, 20>::BitSize == 20));
        assert((Definition<11, 20>::BitBeginIndex == 11));
        assert((Definition<11, 20>::BitEndIndex == 31));
        assert((Definition<11, 20>::Mask == 0x7FFFF800));
        assert((Definition<11, 20>::NegationMask == 0x800007FF));
        assert((Definition<11, 20>::BitCarryIndex == 31));
        assert((Definition<11, 20>::BitCarryMask == 0x80000000));
    }
    {
        assert((Definition<11, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 24>::BitSize == 24));
        assert((Definition<11, 24>::BitBeginIndex == 11));
        assert((Definition<11, 24>::BitEndIndex == 35));
        assert((Definition<11, 24>::Mask == 0x7FFFFF800));
        assert((Definition<11, 24>::NegationMask == 0xFFFFFFF8000007FF));
        assert((Definition<11, 24>::BitCarryIndex == 35));
        assert((Definition<11, 24>::BitCarryMask == 0x800000000));
    }
    {
        assert((Definition<11, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 28>::BitSize == 28));
        assert((Definition<11, 28>::BitBeginIndex == 11));
        assert((Definition<11, 28>::BitEndIndex == 39));
        assert((Definition<11, 28>::Mask == 0x7FFFFFF800));
        assert((Definition<11, 28>::NegationMask == 0xFFFFFF80000007FF));
        assert((Definition<11, 28>::BitCarryIndex == 39));
        assert((Definition<11, 28>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<11, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 32>::BitSize == 32));
        assert((Definition<11, 32>::BitBeginIndex == 11));
        assert((Definition<11, 32>::BitEndIndex == 43));
        assert((Definition<11, 32>::Mask == 0x7FFFFFFF800));
        assert((Definition<11, 32>::NegationMask == 0xFFFFF800000007FF));
        assert((Definition<11, 32>::BitCarryIndex == 43));
        assert((Definition<11, 32>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<11, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 36>::BitSize == 36));
        assert((Definition<11, 36>::BitBeginIndex == 11));
        assert((Definition<11, 36>::BitEndIndex == 47));
        assert((Definition<11, 36>::Mask == 0x7FFFFFFFF800));
        assert((Definition<11, 36>::NegationMask == 0xFFFF8000000007FF));
        assert((Definition<11, 36>::BitCarryIndex == 47));
        assert((Definition<11, 36>::BitCarryMask == 0x800000000000));
    }
    {
        assert((Definition<11, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 40>::BitSize == 40));
        assert((Definition<11, 40>::BitBeginIndex == 11));
        assert((Definition<11, 40>::BitEndIndex == 51));
        assert((Definition<11, 40>::Mask == 0x7FFFFFFFFF800));
        assert((Definition<11, 40>::NegationMask == 0xFFF80000000007FF));
        assert((Definition<11, 40>::BitCarryIndex == 51));
        assert((Definition<11, 40>::BitCarryMask == 0x8000000000000));
    }
    {
        assert((Definition<11, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 44>::BitSize == 44));
        assert((Definition<11, 44>::BitBeginIndex == 11));
        assert((Definition<11, 44>::BitEndIndex == 55));
        assert((Definition<11, 44>::Mask == 0x7FFFFFFFFFF800));
        assert((Definition<11, 44>::NegationMask == 0xFF800000000007FF));
        assert((Definition<11, 44>::BitCarryIndex == 55));
        assert((Definition<11, 44>::BitCarryMask == 0x80000000000000));
    }
    {
        assert((Definition<11, 48>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 48>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 48>::BitSize == 48));
        assert((Definition<11, 48>::BitBeginIndex == 11));
        assert((Definition<11, 48>::BitEndIndex == 59));
        assert((Definition<11, 48>::Mask == 0x7FFFFFFFFFFF800));
        assert((Definition<11, 48>::NegationMask == 0xF8000000000007FF));
        assert((Definition<11, 48>::BitCarryIndex == 59));
        assert((Definition<11, 48>::BitCarryMask == 0x800000000000000));
    }
    {
        assert((Definition<11, 52>::AllocationSize == 8));
        assert((std::is_same<typename Definition<11, 52>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<11, 52>::BitSize == 52));
        assert((Definition<11, 52>::BitBeginIndex == 11));
        assert((Definition<11, 52>::BitEndIndex == 63));
        assert((Definition<11, 52>::Mask == 0x7FFFFFFFFFFFF800));
        assert((Definition<11, 52>::NegationMask == 0x80000000000007FF));
        assert((Definition<11, 52>::BitCarryIndex == 63));
        assert((Definition<11, 52>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<17, 2>::AllocationSize == 4));
        assert((std::is_same<typename Definition<17, 2>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<17, 2>::BitSize == 2));
        assert((Definition<17, 2>::BitBeginIndex == 17));
        assert((Definition<17, 2>::BitEndIndex == 19));
        assert((Definition<17, 2>::Mask == 0x60000));
        assert((Definition<17, 2>::NegationMask == 0xFFF9FFFF));
        assert((Definition<17, 2>::BitCarryIndex == 19));
        assert((Definition<17, 2>::BitCarryMask == 0x80000));
    }
    {
        assert((Definition<17, 4>::AllocationSize == 4));
        assert((std::is_same<typename Definition<17, 4>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<17, 4>::BitSize == 4));
        assert((Definition<17, 4>::BitBeginIndex == 17));
        assert((Definition<17, 4>::BitEndIndex == 21));
        assert((Definition<17, 4>::Mask == 0x1E0000));
        assert((Definition<17, 4>::NegationMask == 0xFFE1FFFF));
        assert((Definition<17, 4>::BitCarryIndex == 21));
        assert((Definition<17, 4>::BitCarryMask == 0x200000));
    }
    {
        assert((Definition<17, 8>::AllocationSize == 4));
        assert((std::is_same<typename Definition<17, 8>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<17, 8>::BitSize == 8));
        assert((Definition<17, 8>::BitBeginIndex == 17));
        assert((Definition<17, 8>::BitEndIndex == 25));
        assert((Definition<17, 8>::Mask == 0x1FE0000));
        assert((Definition<17, 8>::NegationMask == 0xFE01FFFF));
        assert((Definition<17, 8>::BitCarryIndex == 25));
        assert((Definition<17, 8>::BitCarryMask == 0x2000000));
    }
    {
        assert((Definition<17, 12>::AllocationSize == 4));
        assert((std::is_same<typename Definition<17, 12>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<17, 12>::BitSize == 12));
        assert((Definition<17, 12>::BitBeginIndex == 17));
        assert((Definition<17, 12>::BitEndIndex == 29));
        assert((Definition<17, 12>::Mask == 0x1FFE0000));
        assert((Definition<17, 12>::NegationMask == 0xE001FFFF));
        assert((Definition<17, 12>::BitCarryIndex == 29));
        assert((Definition<17, 12>::BitCarryMask == 0x20000000));
    }
    {
        assert((Definition<17, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 16>::BitSize == 16));
        assert((Definition<17, 16>::BitBeginIndex == 17));
        assert((Definition<17, 16>::BitEndIndex == 33));
        assert((Definition<17, 16>::Mask == 0x1FFFE0000));
        assert((Definition<17, 16>::NegationMask == 0xFFFFFFFE0001FFFF));
        assert((Definition<17, 16>::BitCarryIndex == 33));
        assert((Definition<17, 16>::BitCarryMask == 0x200000000));
    }
    {
        assert((Definition<17, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 20>::BitSize == 20));
        assert((Definition<17, 20>::BitBeginIndex == 17));
        assert((Definition<17, 20>::BitEndIndex == 37));
        assert((Definition<17, 20>::Mask == 0x1FFFFE0000));
        assert((Definition<17, 20>::NegationMask == 0xFFFFFFE00001FFFF));
        assert((Definition<17, 20>::BitCarryIndex == 37));
        assert((Definition<17, 20>::BitCarryMask == 0x2000000000));
    }
    {
        assert((Definition<17, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 24>::BitSize == 24));
        assert((Definition<17, 24>::BitBeginIndex == 17));
        assert((Definition<17, 24>::BitEndIndex == 41));
        assert((Definition<17, 24>::Mask == 0x1FFFFFE0000));
        assert((Definition<17, 24>::NegationMask == 0xFFFFFE000001FFFF));
        assert((Definition<17, 24>::BitCarryIndex == 41));
        assert((Definition<17, 24>::BitCarryMask == 0x20000000000));
    }
    {
        assert((Definition<17, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 28>::BitSize == 28));
        assert((Definition<17, 28>::BitBeginIndex == 17));
        assert((Definition<17, 28>::BitEndIndex == 45));
        assert((Definition<17, 28>::Mask == 0x1FFFFFFE0000));
        assert((Definition<17, 28>::NegationMask == 0xFFFFE0000001FFFF));
        assert((Definition<17, 28>::BitCarryIndex == 45));
        assert((Definition<17, 28>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<17, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 32>::BitSize == 32));
        assert((Definition<17, 32>::BitBeginIndex == 17));
        assert((Definition<17, 32>::BitEndIndex == 49));
        assert((Definition<17, 32>::Mask == 0x1FFFFFFFE0000));
        assert((Definition<17, 32>::NegationMask == 0xFFFE00000001FFFF));
        assert((Definition<17, 32>::BitCarryIndex == 49));
        assert((Definition<17, 32>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<17, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 36>::BitSize == 36));
        assert((Definition<17, 36>::BitBeginIndex == 17));
        assert((Definition<17, 36>::BitEndIndex == 53));
        assert((Definition<17, 36>::Mask == 0x1FFFFFFFFE0000));
        assert((Definition<17, 36>::NegationMask == 0xFFE000000001FFFF));
        assert((Definition<17, 36>::BitCarryIndex == 53));
        assert((Definition<17, 36>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<17, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 40>::BitSize == 40));
        assert((Definition<17, 40>::BitBeginIndex == 17));
        assert((Definition<17, 40>::BitEndIndex == 57));
        assert((Definition<17, 40>::Mask == 0x1FFFFFFFFFE0000));
        assert((Definition<17, 40>::NegationMask == 0xFE0000000001FFFF));
        assert((Definition<17, 40>::BitCarryIndex == 57));
        assert((Definition<17, 40>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<17, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<17, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<17, 44>::BitSize == 44));
        assert((Definition<17, 44>::BitBeginIndex == 17));
        assert((Definition<17, 44>::BitEndIndex == 61));
        assert((Definition<17, 44>::Mask == 0x1FFFFFFFFFFE0000));
        assert((Definition<17, 44>::NegationMask == 0xE00000000001FFFF));
        assert((Definition<17, 44>::BitCarryIndex == 61));
        assert((Definition<17, 44>::BitCarryMask == 0x2000000000000000));
    }

    ///////
    
    {
        assert((Definition<19, 2>::AllocationSize == 4));
        assert((std::is_same<typename Definition<19, 2>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<19, 2>::BitSize == 2));
        assert((Definition<19, 2>::BitBeginIndex == 19));
        assert((Definition<19, 2>::BitEndIndex == 21));
        assert((Definition<19, 2>::Mask == 0x180000));
        assert((Definition<19, 2>::NegationMask == 0xFFE7FFFF));
        assert((Definition<19, 2>::BitCarryIndex == 21));
        assert((Definition<19, 2>::BitCarryMask == 0x200000));
    }
    {
        assert((Definition<19, 4>::AllocationSize == 4));
        assert((std::is_same<typename Definition<19, 4>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<19, 4>::BitSize == 4));
        assert((Definition<19, 4>::BitBeginIndex == 19));
        assert((Definition<19, 4>::BitEndIndex == 23));
        assert((Definition<19, 4>::Mask == 0x780000));
        assert((Definition<19, 4>::NegationMask == 0xFF87FFFF));
        assert((Definition<19, 4>::BitCarryIndex == 23));
        assert((Definition<19, 4>::BitCarryMask == 0x800000));
    }
    {
        assert((Definition<19, 8>::AllocationSize == 4));
        assert((std::is_same<typename Definition<19, 8>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<19, 8>::BitSize == 8));
        assert((Definition<19, 8>::BitBeginIndex == 19));
        assert((Definition<19, 8>::BitEndIndex == 27));
        assert((Definition<19, 8>::Mask == 0x7F80000));
        assert((Definition<19, 8>::NegationMask == 0xF807FFFF));
        assert((Definition<19, 8>::BitCarryIndex == 27));
        assert((Definition<19, 8>::BitCarryMask == 0x8000000));
    }
    {
        assert((Definition<19, 12>::AllocationSize == 4));
        assert((std::is_same<typename Definition<19, 12>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<19, 12>::BitSize == 12));
        assert((Definition<19, 12>::BitBeginIndex == 19));
        assert((Definition<19, 12>::BitEndIndex == 31));
        assert((Definition<19, 12>::Mask == 0x7FF80000));
        assert((Definition<19, 12>::NegationMask == 0x8007FFFF));
        assert((Definition<19, 12>::BitCarryIndex == 31));
        assert((Definition<19, 12>::BitCarryMask == 0x80000000));
    }
    {
        assert((Definition<19, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 16>::BitSize == 16));
        assert((Definition<19, 16>::BitBeginIndex == 19));
        assert((Definition<19, 16>::BitEndIndex == 35));
        assert((Definition<19, 16>::Mask == 0x7FFF80000));
        assert((Definition<19, 16>::NegationMask == 0xFFFFFFF80007FFFF));
        assert((Definition<19, 16>::BitCarryIndex == 35));
        assert((Definition<19, 16>::BitCarryMask == 0x800000000));
    }
    {
        assert((Definition<19, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 20>::BitSize == 20));
        assert((Definition<19, 20>::BitBeginIndex == 19));
        assert((Definition<19, 20>::BitEndIndex == 39));
        assert((Definition<19, 20>::Mask == 0x7FFFF80000));
        assert((Definition<19, 20>::NegationMask == 0xFFFFFF800007FFFF));
        assert((Definition<19, 20>::BitCarryIndex == 39));
        assert((Definition<19, 20>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<19, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 24>::BitSize == 24));
        assert((Definition<19, 24>::BitBeginIndex == 19));
        assert((Definition<19, 24>::BitEndIndex == 43));
        assert((Definition<19, 24>::Mask == 0x7FFFFF80000));
        assert((Definition<19, 24>::NegationMask == 0xFFFFF8000007FFFF));
        assert((Definition<19, 24>::BitCarryIndex == 43));
        assert((Definition<19, 24>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<19, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 28>::BitSize == 28));
        assert((Definition<19, 28>::BitBeginIndex == 19));
        assert((Definition<19, 28>::BitEndIndex == 47));
        assert((Definition<19, 28>::Mask == 0x7FFFFFF80000));
        assert((Definition<19, 28>::NegationMask == 0xFFFF80000007FFFF));
        assert((Definition<19, 28>::BitCarryIndex == 47));
        assert((Definition<19, 28>::BitCarryMask == 0x800000000000));
    }
    {
        assert((Definition<19, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 32>::BitSize == 32));
        assert((Definition<19, 32>::BitBeginIndex == 19));
        assert((Definition<19, 32>::BitEndIndex == 51));
        assert((Definition<19, 32>::Mask == 0x7FFFFFFF80000));
        assert((Definition<19, 32>::NegationMask == 0xFFF800000007FFFF));
        assert((Definition<19, 32>::BitCarryIndex == 51));
        assert((Definition<19, 32>::BitCarryMask == 0x8000000000000));
    }
    {
        assert((Definition<19, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 36>::BitSize == 36));
        assert((Definition<19, 36>::BitBeginIndex == 19));
        assert((Definition<19, 36>::BitEndIndex == 55));
        assert((Definition<19, 36>::Mask == 0x7FFFFFFFF80000));
        assert((Definition<19, 36>::NegationMask == 0xFF8000000007FFFF));
        assert((Definition<19, 36>::BitCarryIndex == 55));
        assert((Definition<19, 36>::BitCarryMask == 0x80000000000000));
    }
    {
        assert((Definition<19, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 40>::BitSize == 40));
        assert((Definition<19, 40>::BitBeginIndex == 19));
        assert((Definition<19, 40>::BitEndIndex == 59));
        assert((Definition<19, 40>::Mask == 0x7FFFFFFFFF80000));
        assert((Definition<19, 40>::NegationMask == 0xF80000000007FFFF));
        assert((Definition<19, 40>::BitCarryIndex == 59));
        assert((Definition<19, 40>::BitCarryMask == 0x800000000000000));
    }
    {
        assert((Definition<19, 44>::AllocationSize == 8));
        assert((std::is_same<typename Definition<19, 44>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<19, 44>::BitSize == 44));
        assert((Definition<19, 44>::BitBeginIndex == 19));
        assert((Definition<19, 44>::BitEndIndex == 63));
        assert((Definition<19, 44>::Mask == 0x7FFFFFFFFFF80000));
        assert((Definition<19, 44>::NegationMask == 0x800000000007FFFF));
        assert((Definition<19, 44>::BitCarryIndex == 63));
        assert((Definition<19, 44>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<23, 2>::AllocationSize == 4));
        assert((std::is_same<typename Definition<23, 2>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<23, 2>::BitSize == 2));
        assert((Definition<23, 2>::BitBeginIndex == 23));
        assert((Definition<23, 2>::BitEndIndex == 25));
        assert((Definition<23, 2>::Mask == 0x1800000));
        assert((Definition<23, 2>::NegationMask == 0xFE7FFFFF));
        assert((Definition<23, 2>::BitCarryIndex == 25));
        assert((Definition<23, 2>::BitCarryMask == 0x2000000));
    }
    {
        assert((Definition<23, 4>::AllocationSize == 4));
        assert((std::is_same<typename Definition<23, 4>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<23, 4>::BitSize == 4));
        assert((Definition<23, 4>::BitBeginIndex == 23));
        assert((Definition<23, 4>::BitEndIndex == 27));
        assert((Definition<23, 4>::Mask == 0x7800000));
        assert((Definition<23, 4>::NegationMask == 0xF87FFFFF));
        assert((Definition<23, 4>::BitCarryIndex == 27));
        assert((Definition<23, 4>::BitCarryMask == 0x8000000));
    }
    {
        assert((Definition<23, 8>::AllocationSize == 4));
        assert((std::is_same<typename Definition<23, 8>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<23, 8>::BitSize == 8));
        assert((Definition<23, 8>::BitBeginIndex == 23));
        assert((Definition<23, 8>::BitEndIndex == 31));
        assert((Definition<23, 8>::Mask == 0x7F800000));
        assert((Definition<23, 8>::NegationMask == 0x807FFFFF));
        assert((Definition<23, 8>::BitCarryIndex == 31));
        assert((Definition<23, 8>::BitCarryMask == 0x80000000));
    }
    {
        assert((Definition<23, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 12>::BitSize == 12));
        assert((Definition<23, 12>::BitBeginIndex == 23));
        assert((Definition<23, 12>::BitEndIndex == 35));
        assert((Definition<23, 12>::Mask == 0x7FF800000));
        assert((Definition<23, 12>::NegationMask == 0xFFFFFFF8007FFFFF));
        assert((Definition<23, 12>::BitCarryIndex == 35));
        assert((Definition<23, 12>::BitCarryMask == 0x800000000));
    }
    {
        assert((Definition<23, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 16>::BitSize == 16));
        assert((Definition<23, 16>::BitBeginIndex == 23));
        assert((Definition<23, 16>::BitEndIndex == 39));
        assert((Definition<23, 16>::Mask == 0x7FFF800000));
        assert((Definition<23, 16>::NegationMask == 0xFFFFFF80007FFFFF));
        assert((Definition<23, 16>::BitCarryIndex == 39));
        assert((Definition<23, 16>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<23, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 20>::BitSize == 20));
        assert((Definition<23, 20>::BitBeginIndex == 23));
        assert((Definition<23, 20>::BitEndIndex == 43));
        assert((Definition<23, 20>::Mask == 0x7FFFF800000));
        assert((Definition<23, 20>::NegationMask == 0xFFFFF800007FFFFF));
        assert((Definition<23, 20>::BitCarryIndex == 43));
        assert((Definition<23, 20>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<23, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 24>::BitSize == 24));
        assert((Definition<23, 24>::BitBeginIndex == 23));
        assert((Definition<23, 24>::BitEndIndex == 47));
        assert((Definition<23, 24>::Mask == 0x7FFFFF800000));
        assert((Definition<23, 24>::NegationMask == 0xFFFF8000007FFFFF));
        assert((Definition<23, 24>::BitCarryIndex == 47));
        assert((Definition<23, 24>::BitCarryMask == 0x800000000000));
    }
    {
        assert((Definition<23, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 28>::BitSize == 28));
        assert((Definition<23, 28>::BitBeginIndex == 23));
        assert((Definition<23, 28>::BitEndIndex == 51));
        assert((Definition<23, 28>::Mask == 0x7FFFFFF800000));
        assert((Definition<23, 28>::NegationMask == 0xFFF80000007FFFFF));
        assert((Definition<23, 28>::BitCarryIndex == 51));
        assert((Definition<23, 28>::BitCarryMask == 0x8000000000000));
    }
    {
        assert((Definition<23, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 32>::BitSize == 32));
        assert((Definition<23, 32>::BitBeginIndex == 23));
        assert((Definition<23, 32>::BitEndIndex == 55));
        assert((Definition<23, 32>::Mask == 0x7FFFFFFF800000));
        assert((Definition<23, 32>::NegationMask == 0xFF800000007FFFFF));
        assert((Definition<23, 32>::BitCarryIndex == 55));
        assert((Definition<23, 32>::BitCarryMask == 0x80000000000000));
    }
    {
        assert((Definition<23, 36>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 36>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 36>::BitSize == 36));
        assert((Definition<23, 36>::BitBeginIndex == 23));
        assert((Definition<23, 36>::BitEndIndex == 59));
        assert((Definition<23, 36>::Mask == 0x7FFFFFFFF800000));
        assert((Definition<23, 36>::NegationMask == 0xF8000000007FFFFF));
        assert((Definition<23, 36>::BitCarryIndex == 59));
        assert((Definition<23, 36>::BitCarryMask == 0x800000000000000));
    }
    {
        assert((Definition<23, 40>::AllocationSize == 8));
        assert((std::is_same<typename Definition<23, 40>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<23, 40>::BitSize == 40));
        assert((Definition<23, 40>::BitBeginIndex == 23));
        assert((Definition<23, 40>::BitEndIndex == 63));
        assert((Definition<23, 40>::Mask == 0x7FFFFFFFFF800000));
        assert((Definition<23, 40>::NegationMask == 0x80000000007FFFFF));
        assert((Definition<23, 40>::BitCarryIndex == 63));
        assert((Definition<23, 40>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<29, 2>::AllocationSize == 4));
        assert((std::is_same<typename Definition<29, 2>::ValueType, 
            std::uint32_t>::value));
        assert((Definition<29, 2>::BitSize == 2));
        assert((Definition<29, 2>::BitBeginIndex == 29));
        assert((Definition<29, 2>::BitEndIndex == 31));
        assert((Definition<29, 2>::Mask == 0x60000000));
        assert((Definition<29, 2>::NegationMask == 0x9FFFFFFF));
        assert((Definition<29, 2>::BitCarryIndex == 31));
        assert((Definition<29, 2>::BitCarryMask == 0x80000000));
    }
    {
        assert((Definition<29, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 4>::BitSize == 4));
        assert((Definition<29, 4>::BitBeginIndex == 29));
        assert((Definition<29, 4>::BitEndIndex == 33));
        assert((Definition<29, 4>::Mask == 0x1E0000000));
        assert((Definition<29, 4>::NegationMask == 0xFFFFFFFE1FFFFFFF));
        assert((Definition<29, 4>::BitCarryIndex == 33));
        assert((Definition<29, 4>::BitCarryMask == 0x200000000));
    }
    {
        assert((Definition<29, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 8>::BitSize == 8));
        assert((Definition<29, 8>::BitBeginIndex == 29));
        assert((Definition<29, 8>::BitEndIndex == 37));
        assert((Definition<29, 8>::Mask == 0x1FE0000000));
        assert((Definition<29, 8>::NegationMask == 0xFFFFFFE01FFFFFFF));
        assert((Definition<29, 8>::BitCarryIndex == 37));
        assert((Definition<29, 8>::BitCarryMask == 0x2000000000));
    }
    {
        assert((Definition<29, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 12>::BitSize == 12));
        assert((Definition<29, 12>::BitBeginIndex == 29));
        assert((Definition<29, 12>::BitEndIndex == 41));
        assert((Definition<29, 12>::Mask == 0x1FFE0000000));
        assert((Definition<29, 12>::NegationMask == 0xFFFFFE001FFFFFFF));
        assert((Definition<29, 12>::BitCarryIndex == 41));
        assert((Definition<29, 12>::BitCarryMask == 0x20000000000));
    }
    {
        assert((Definition<29, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 16>::BitSize == 16));
        assert((Definition<29, 16>::BitBeginIndex == 29));
        assert((Definition<29, 16>::BitEndIndex == 45));
        assert((Definition<29, 16>::Mask == 0x1FFFE0000000));
        assert((Definition<29, 16>::NegationMask == 0xFFFFE0001FFFFFFF));
        assert((Definition<29, 16>::BitCarryIndex == 45));
        assert((Definition<29, 16>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<29, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 20>::BitSize == 20));
        assert((Definition<29, 20>::BitBeginIndex == 29));
        assert((Definition<29, 20>::BitEndIndex == 49));
        assert((Definition<29, 20>::Mask == 0x1FFFFE0000000));
        assert((Definition<29, 20>::NegationMask == 0xFFFE00001FFFFFFF));
        assert((Definition<29, 20>::BitCarryIndex == 49));
        assert((Definition<29, 20>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<29, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 24>::BitSize == 24));
        assert((Definition<29, 24>::BitBeginIndex == 29));
        assert((Definition<29, 24>::BitEndIndex == 53));
        assert((Definition<29, 24>::Mask == 0x1FFFFFE0000000));
        assert((Definition<29, 24>::NegationMask == 0xFFE000001FFFFFFF));
        assert((Definition<29, 24>::BitCarryIndex == 53));
        assert((Definition<29, 24>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<29, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 28>::BitSize == 28));
        assert((Definition<29, 28>::BitBeginIndex == 29));
        assert((Definition<29, 28>::BitEndIndex == 57));
        assert((Definition<29, 28>::Mask == 0x1FFFFFFE0000000));
        assert((Definition<29, 28>::NegationMask == 0xFE0000001FFFFFFF));
        assert((Definition<29, 28>::BitCarryIndex == 57));
        assert((Definition<29, 28>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<29, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<29, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<29, 32>::BitSize == 32));
        assert((Definition<29, 32>::BitBeginIndex == 29));
        assert((Definition<29, 32>::BitEndIndex == 61));
        assert((Definition<29, 32>::Mask == 0x1FFFFFFFE0000000));
        assert((Definition<29, 32>::NegationMask == 0xE00000001FFFFFFF));
        assert((Definition<29, 32>::BitCarryIndex == 61));
        assert((Definition<29, 32>::BitCarryMask == 0x2000000000000000));
    }

    ///////
    
    {
        assert((Definition<31, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 2>::BitSize == 2));
        assert((Definition<31, 2>::BitBeginIndex == 31));
        assert((Definition<31, 2>::BitEndIndex == 33));
        assert((Definition<31, 2>::Mask == 0x180000000));
        assert((Definition<31, 2>::NegationMask == 0xFFFFFFFE7FFFFFFF));
        assert((Definition<31, 2>::BitCarryIndex == 33));
        assert((Definition<31, 2>::BitCarryMask == 0x200000000));
    }
    {
        assert((Definition<31, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 4>::BitSize == 4));
        assert((Definition<31, 4>::BitBeginIndex == 31));
        assert((Definition<31, 4>::BitEndIndex == 35));
        assert((Definition<31, 4>::Mask == 0x780000000));
        assert((Definition<31, 4>::NegationMask == 0xFFFFFFF87FFFFFFF));
        assert((Definition<31, 4>::BitCarryIndex == 35));
        assert((Definition<31, 4>::BitCarryMask == 0x800000000));
    }
    {
        assert((Definition<31, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 8>::BitSize == 8));
        assert((Definition<31, 8>::BitBeginIndex == 31));
        assert((Definition<31, 8>::BitEndIndex == 39));
        assert((Definition<31, 8>::Mask == 0x7F80000000));
        assert((Definition<31, 8>::NegationMask == 0xFFFFFF807FFFFFFF));
        assert((Definition<31, 8>::BitCarryIndex == 39));
        assert((Definition<31, 8>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<31, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 12>::BitSize == 12));
        assert((Definition<31, 12>::BitBeginIndex == 31));
        assert((Definition<31, 12>::BitEndIndex == 43));
        assert((Definition<31, 12>::Mask == 0x7FF80000000));
        assert((Definition<31, 12>::NegationMask == 0xFFFFF8007FFFFFFF));
        assert((Definition<31, 12>::BitCarryIndex == 43));
        assert((Definition<31, 12>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<31, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 16>::BitSize == 16));
        assert((Definition<31, 16>::BitBeginIndex == 31));
        assert((Definition<31, 16>::BitEndIndex == 47));
        assert((Definition<31, 16>::Mask == 0x7FFF80000000));
        assert((Definition<31, 16>::NegationMask == 0xFFFF80007FFFFFFF));
        assert((Definition<31, 16>::BitCarryIndex == 47));
        assert((Definition<31, 16>::BitCarryMask == 0x800000000000));
    }
    {
        assert((Definition<31, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 20>::BitSize == 20));
        assert((Definition<31, 20>::BitBeginIndex == 31));
        assert((Definition<31, 20>::BitEndIndex == 51));
        assert((Definition<31, 20>::Mask == 0x7FFFF80000000));
        assert((Definition<31, 20>::NegationMask == 0xFFF800007FFFFFFF));
        assert((Definition<31, 20>::BitCarryIndex == 51));
        assert((Definition<31, 20>::BitCarryMask == 0x8000000000000));
    }
    {
        assert((Definition<31, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 24>::BitSize == 24));
        assert((Definition<31, 24>::BitBeginIndex == 31));
        assert((Definition<31, 24>::BitEndIndex == 55));
        assert((Definition<31, 24>::Mask == 0x7FFFFF80000000));
        assert((Definition<31, 24>::NegationMask == 0xFF8000007FFFFFFF));
        assert((Definition<31, 24>::BitCarryIndex == 55));
        assert((Definition<31, 24>::BitCarryMask == 0x80000000000000));
    }
    {
        assert((Definition<31, 28>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 28>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 28>::BitSize == 28));
        assert((Definition<31, 28>::BitBeginIndex == 31));
        assert((Definition<31, 28>::BitEndIndex == 59));
        assert((Definition<31, 28>::Mask == 0x7FFFFFF80000000));
        assert((Definition<31, 28>::NegationMask == 0xF80000007FFFFFFF));
        assert((Definition<31, 28>::BitCarryIndex == 59));
        assert((Definition<31, 28>::BitCarryMask == 0x800000000000000));
    }
    {
        assert((Definition<31, 32>::AllocationSize == 8));
        assert((std::is_same<typename Definition<31, 32>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<31, 32>::BitSize == 32));
        assert((Definition<31, 32>::BitBeginIndex == 31));
        assert((Definition<31, 32>::BitEndIndex == 63));
        assert((Definition<31, 32>::Mask == 0x7FFFFFFF80000000));
        assert((Definition<31, 32>::NegationMask == 0x800000007FFFFFFF));
        assert((Definition<31, 32>::BitCarryIndex == 63));
        assert((Definition<31, 32>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<37, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 2>::BitSize == 2));
        assert((Definition<37, 2>::BitBeginIndex == 37));
        assert((Definition<37, 2>::BitEndIndex == 39));
        assert((Definition<37, 2>::Mask == 0x6000000000));
        assert((Definition<37, 2>::NegationMask == 0xFFFFFF9FFFFFFFFF));
        assert((Definition<37, 2>::BitCarryIndex == 39));
        assert((Definition<37, 2>::BitCarryMask == 0x8000000000));
    }
    {
        assert((Definition<37, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 4>::BitSize == 4));
        assert((Definition<37, 4>::BitBeginIndex == 37));
        assert((Definition<37, 4>::BitEndIndex == 41));
        assert((Definition<37, 4>::Mask == 0x1E000000000));
        assert((Definition<37, 4>::NegationMask == 0xFFFFFE1FFFFFFFFF));
        assert((Definition<37, 4>::BitCarryIndex == 41));
        assert((Definition<37, 4>::BitCarryMask == 0x20000000000));
    }
    {
        assert((Definition<37, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 8>::BitSize == 8));
        assert((Definition<37, 8>::BitBeginIndex == 37));
        assert((Definition<37, 8>::BitEndIndex == 45));
        assert((Definition<37, 8>::Mask == 0x1FE000000000));
        assert((Definition<37, 8>::NegationMask == 0xFFFFE01FFFFFFFFF));
        assert((Definition<37, 8>::BitCarryIndex == 45));
        assert((Definition<37, 8>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<37, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 12>::BitSize == 12));
        assert((Definition<37, 12>::BitBeginIndex == 37));
        assert((Definition<37, 12>::BitEndIndex == 49));
        assert((Definition<37, 12>::Mask == 0x1FFE000000000));
        assert((Definition<37, 12>::NegationMask == 0xFFFE001FFFFFFFFF));
        assert((Definition<37, 12>::BitCarryIndex == 49));
        assert((Definition<37, 12>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<37, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 16>::BitSize == 16));
        assert((Definition<37, 16>::BitBeginIndex == 37));
        assert((Definition<37, 16>::BitEndIndex == 53));
        assert((Definition<37, 16>::Mask == 0x1FFFE000000000));
        assert((Definition<37, 16>::NegationMask == 0xFFE0001FFFFFFFFF));
        assert((Definition<37, 16>::BitCarryIndex == 53));
        assert((Definition<37, 16>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<37, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 20>::BitSize == 20));
        assert((Definition<37, 20>::BitBeginIndex == 37));
        assert((Definition<37, 20>::BitEndIndex == 57));
        assert((Definition<37, 20>::Mask == 0x1FFFFE000000000));
        assert((Definition<37, 20>::NegationMask == 0xFE00001FFFFFFFFF));
        assert((Definition<37, 20>::BitCarryIndex == 57));
        assert((Definition<37, 20>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<37, 24>::AllocationSize == 8));
        assert((std::is_same<typename Definition<37, 24>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<37, 24>::BitSize == 24));
        assert((Definition<37, 24>::BitBeginIndex == 37));
        assert((Definition<37, 24>::BitEndIndex == 61));
        assert((Definition<37, 24>::Mask == 0x1FFFFFE000000000));
        assert((Definition<37, 24>::NegationMask == 0xE000001FFFFFFFFF));
        assert((Definition<37, 24>::BitCarryIndex == 61));
        assert((Definition<37, 24>::BitCarryMask == 0x2000000000000000));
    }

    ///////
    
    {
        assert((Definition<41, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<41, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<41, 2>::BitSize == 2));
        assert((Definition<41, 2>::BitBeginIndex == 41));
        assert((Definition<41, 2>::BitEndIndex == 43));
        assert((Definition<41, 2>::Mask == 0x60000000000));
        assert((Definition<41, 2>::NegationMask == 0xFFFFF9FFFFFFFFFF));
        assert((Definition<41, 2>::BitCarryIndex == 43));
        assert((Definition<41, 2>::BitCarryMask == 0x80000000000));
    }
    {
        assert((Definition<41, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<41, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<41, 4>::BitSize == 4));
        assert((Definition<41, 4>::BitBeginIndex == 41));
        assert((Definition<41, 4>::BitEndIndex == 45));
        assert((Definition<41, 4>::Mask == 0x1E0000000000));
        assert((Definition<41, 4>::NegationMask == 0xFFFFE1FFFFFFFFFF));
        assert((Definition<41, 4>::BitCarryIndex == 45));
        assert((Definition<41, 4>::BitCarryMask == 0x200000000000));
    }
    {
        assert((Definition<41, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<41, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<41, 8>::BitSize == 8));
        assert((Definition<41, 8>::BitBeginIndex == 41));
        assert((Definition<41, 8>::BitEndIndex == 49));
        assert((Definition<41, 8>::Mask == 0x1FE0000000000));
        assert((Definition<41, 8>::NegationMask == 0xFFFE01FFFFFFFFFF));
        assert((Definition<41, 8>::BitCarryIndex == 49));
        assert((Definition<41, 8>::BitCarryMask == 0x2000000000000));
    }
    {
        assert((Definition<41, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<41, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<41, 12>::BitSize == 12));
        assert((Definition<41, 12>::BitBeginIndex == 41));
        assert((Definition<41, 12>::BitEndIndex == 53));
        assert((Definition<41, 12>::Mask == 0x1FFE0000000000));
        assert((Definition<41, 12>::NegationMask == 0xFFE001FFFFFFFFFF));
        assert((Definition<41, 12>::BitCarryIndex == 53));
        assert((Definition<41, 12>::BitCarryMask == 0x20000000000000));
    }
    {
        assert((Definition<41, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<41, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<41, 16>::BitSize == 16));
        assert((Definition<41, 16>::BitBeginIndex == 41));
        assert((Definition<41, 16>::BitEndIndex == 57));
        assert((Definition<41, 16>::Mask == 0x1FFFE0000000000));
        assert((Definition<41, 16>::NegationMask == 0xFE0001FFFFFFFFFF));
        assert((Definition<41, 16>::BitCarryIndex == 57));
        assert((Definition<41, 16>::BitCarryMask == 0x200000000000000));
    }
    {
        assert((Definition<41, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<41, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<41, 20>::BitSize == 20));
        assert((Definition<41, 20>::BitBeginIndex == 41));
        assert((Definition<41, 20>::BitEndIndex == 61));
        assert((Definition<41, 20>::Mask == 0x1FFFFE0000000000));
        assert((Definition<41, 20>::NegationMask == 0xE00001FFFFFFFFFF));
        assert((Definition<41, 20>::BitCarryIndex == 61));
        assert((Definition<41, 20>::BitCarryMask == 0x2000000000000000));
    }

    ///////
    
    {
        assert((Definition<43, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<43, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<43, 2>::BitSize == 2));
        assert((Definition<43, 2>::BitBeginIndex == 43));
        assert((Definition<43, 2>::BitEndIndex == 45));
        assert((Definition<43, 2>::Mask == 0x0000180000000000));
        assert((Definition<43, 2>::NegationMask == 0xFFFFE7FFFFFFFFFF));
        assert((Definition<43, 2>::BitCarryIndex == 45));
        assert((Definition<43, 2>::BitCarryMask == 0x0000200000000000));
    }
    {
        assert((Definition<43, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<43, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<43, 4>::BitSize == 4));
        assert((Definition<43, 4>::BitBeginIndex == 43));
        assert((Definition<43, 4>::BitEndIndex == 47));
        assert((Definition<43, 4>::Mask == 0x0000780000000000));
        assert((Definition<43, 4>::NegationMask == 0xFFFF87FFFFFFFFFF));
        assert((Definition<43, 4>::BitCarryIndex == 47));
        assert((Definition<43, 4>::BitCarryMask == 0x0000800000000000));
    }
    {
        assert((Definition<43, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<43, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<43, 8>::BitSize == 8));
        assert((Definition<43, 8>::BitBeginIndex == 43));
        assert((Definition<43, 8>::BitEndIndex == 51));
        assert((Definition<43, 8>::Mask == 0x0007F80000000000));
        assert((Definition<43, 8>::NegationMask == 0xFFF807FFFFFFFFFF));
        assert((Definition<43, 8>::BitCarryIndex == 51));
        assert((Definition<43, 8>::BitCarryMask == 0x0008000000000000));
    }
    {
        assert((Definition<43, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<43, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<43, 12>::BitSize == 12));
        assert((Definition<43, 12>::BitBeginIndex == 43));
        assert((Definition<43, 12>::BitEndIndex == 55));
        assert((Definition<43, 12>::Mask == 0x007FF80000000000));
        assert((Definition<43, 12>::NegationMask == 0xFF8007FFFFFFFFFF));
        assert((Definition<43, 12>::BitCarryIndex == 55));
        assert((Definition<43, 12>::BitCarryMask == 0x0080000000000000));
    }
    {
        assert((Definition<43, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<43, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<43, 16>::BitSize == 16));
        assert((Definition<43, 16>::BitBeginIndex == 43));
        assert((Definition<43, 16>::BitEndIndex == 59));
        assert((Definition<43, 16>::Mask == 0x07FFF80000000000));
        assert((Definition<43, 16>::NegationMask == 0xF80007FFFFFFFFFF));
        assert((Definition<43, 16>::BitCarryIndex == 59));
        assert((Definition<43, 16>::BitCarryMask == 0x0800000000000000));
    }
    {
        assert((Definition<43, 20>::AllocationSize == 8));
        assert((std::is_same<typename Definition<43, 20>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<43, 20>::BitSize == 20));
        assert((Definition<43, 20>::BitBeginIndex == 43));
        assert((Definition<43, 20>::BitEndIndex == 63));
        assert((Definition<43, 20>::Mask == 0x7FFFF80000000000));
        assert((Definition<43, 20>::NegationMask == 0x800007FFFFFFFFFF));
        assert((Definition<43, 20>::BitCarryIndex == 63));
        assert((Definition<43, 20>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<47, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<47, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<47, 2>::BitSize == 2));
        assert((Definition<47, 2>::BitBeginIndex == 47));
        assert((Definition<47, 2>::BitEndIndex == 49));
        assert((Definition<47, 2>::Mask == 0x0001800000000000));
        assert((Definition<47, 2>::NegationMask == 0xFFFE7FFFFFFFFFFF));
        assert((Definition<47, 2>::BitCarryIndex == 49));
        assert((Definition<47, 2>::BitCarryMask == 0x0002000000000000));
    }
    {
        assert((Definition<47, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<47, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<47, 4>::BitSize == 4));
        assert((Definition<47, 4>::BitBeginIndex == 47));
        assert((Definition<47, 4>::BitEndIndex == 51));
        assert((Definition<47, 4>::Mask == 0x0007800000000000));
        assert((Definition<47, 4>::NegationMask == 0xFFF87FFFFFFFFFFF));
        assert((Definition<47, 4>::BitCarryIndex == 51));
        assert((Definition<47, 4>::BitCarryMask == 0x0008000000000000));
    }
    {
        assert((Definition<47, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<47, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<47, 8>::BitSize == 8));
        assert((Definition<47, 8>::BitBeginIndex == 47));
        assert((Definition<47, 8>::BitEndIndex == 55));
        assert((Definition<47, 8>::Mask == 0x007F800000000000));
        assert((Definition<47, 8>::NegationMask == 0xFF807FFFFFFFFFFF));
        assert((Definition<47, 8>::BitCarryIndex == 55));
        assert((Definition<47, 8>::BitCarryMask == 0x0080000000000000));
    }
    {
        assert((Definition<47, 12>::AllocationSize == 8));
        assert((std::is_same<typename Definition<47, 12>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<47, 12>::BitSize == 12));
        assert((Definition<47, 12>::BitBeginIndex == 47));
        assert((Definition<47, 12>::BitEndIndex == 59));
        assert((Definition<47, 12>::Mask == 0x07FF800000000000));
        assert((Definition<47, 12>::NegationMask == 0xF8007FFFFFFFFFFF));
        assert((Definition<47, 12>::BitCarryIndex == 59));
        assert((Definition<47, 12>::BitCarryMask == 0x0800000000000000));
    }
    {
        assert((Definition<47, 16>::AllocationSize == 8));
        assert((std::is_same<typename Definition<47, 16>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<47, 16>::BitSize == 16));
        assert((Definition<47, 16>::BitBeginIndex == 47));
        assert((Definition<47, 16>::BitEndIndex == 63));
        assert((Definition<47, 16>::Mask == 0x7FFF800000000000));
        assert((Definition<47, 16>::NegationMask == 0x80007FFFFFFFFFFF));
        assert((Definition<47, 16>::BitCarryIndex == 63));
        assert((Definition<47, 16>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<53, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<53, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<53, 2>::BitSize == 2));
        assert((Definition<53, 2>::BitBeginIndex == 53));
        assert((Definition<53, 2>::BitEndIndex == 55));
        assert((Definition<53, 2>::Mask == 0x0060000000000000));
        assert((Definition<53, 2>::NegationMask == 0xFF9FFFFFFFFFFFFF));
        assert((Definition<53, 2>::BitCarryIndex == 55));
        assert((Definition<53, 2>::BitCarryMask == 0x0080000000000000));
    }
    {
        assert((Definition<53, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<53, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<53, 4>::BitSize == 4));
        assert((Definition<53, 4>::BitBeginIndex == 53));
        assert((Definition<53, 4>::BitEndIndex == 57));
        assert((Definition<53, 4>::Mask == 0x01E0000000000000));
        assert((Definition<53, 4>::NegationMask == 0xFE1FFFFFFFFFFFFF));
        assert((Definition<53, 4>::BitCarryIndex == 57));
        assert((Definition<53, 4>::BitCarryMask == 0x0200000000000000));
    }
    {
        assert((Definition<53, 8>::AllocationSize == 8));
        assert((std::is_same<typename Definition<53, 8>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<53, 8>::BitSize == 8));
        assert((Definition<53, 8>::BitBeginIndex == 53));
        assert((Definition<53, 8>::BitEndIndex == 61));
        assert((Definition<53, 8>::Mask == 0x1FE0000000000000));
        assert((Definition<53, 8>::NegationMask == 0xE01FFFFFFFFFFFFF));
        assert((Definition<53, 8>::BitCarryIndex == 61));
        assert((Definition<53, 8>::BitCarryMask == 0x2000000000000000));
    }

    ///////
    
    {
        assert((Definition<59, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<59, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<59, 2>::BitSize == 2));
        assert((Definition<59, 2>::BitBeginIndex == 59));
        assert((Definition<59, 2>::BitEndIndex == 61));
        assert((Definition<59, 2>::Mask == 0x1800000000000000));
        assert((Definition<59, 2>::NegationMask == 0xE7FFFFFFFFFFFFFF));
        assert((Definition<59, 2>::BitCarryIndex == 61));
        assert((Definition<59, 2>::BitCarryMask == 0x2000000000000000));
    }
    {
        assert((Definition<59, 4>::AllocationSize == 8));
        assert((std::is_same<typename Definition<59, 4>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<59, 4>::BitSize == 4));
        assert((Definition<59, 4>::BitBeginIndex == 59));
        assert((Definition<59, 4>::BitEndIndex == 63));
        assert((Definition<59, 4>::Mask == 0x7800000000000000));
        assert((Definition<59, 4>::NegationMask == 0x87FFFFFFFFFFFFFF));
        assert((Definition<59, 4>::BitCarryIndex == 63));
        assert((Definition<59, 4>::BitCarryMask == 0x8000000000000000));
    }

    ///////
    
    {
        assert((Definition<61, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<61, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<61, 2>::BitSize == 2));
        assert((Definition<61, 2>::BitBeginIndex == 61));
        assert((Definition<61, 2>::BitEndIndex == 63));
        assert((Definition<61, 2>::Mask == 0x6000000000000000));
        assert((Definition<61, 2>::NegationMask == 0x9FFFFFFFFFFFFFFF));
        assert((Definition<61, 2>::BitCarryIndex == 63));
        assert((Definition<61, 2>::BitCarryMask == 0x8000000000000000));
    }
    {
        assert((Definition<62, 2>::AllocationSize == 8));
        assert((std::is_same<typename Definition<62, 2>::ValueType, 
            std::uint64_t>::value));
        assert((Definition<62, 2>::BitSize == 2));
        assert((Definition<62, 2>::BitBeginIndex == 62));
        assert((Definition<62, 2>::BitEndIndex == 64));
        assert((Definition<62, 2>::Mask == 0xC000000000000000));
        assert((Definition<62, 2>::NegationMask == 0x3FFFFFFFFFFFFFFF));
        assert((Definition<62, 2>::BitCarryIndex == 0));
        assert((Definition<62, 2>::BitCarryMask == 0x01));
    }

    return 0;
}
