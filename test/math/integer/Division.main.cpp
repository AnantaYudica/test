#include "test/math/integer/Division.h"

#include <cstdint>
#include <cassert>
#include <type_traits>

#include "Format.test.h"

#ifdef EXTENDED_TEST
#include <cstdio>
#endif //!EXTENDED_TEST

int main()
{
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{2, 2, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 127);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 2);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }

    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{0};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{1};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{2};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{3};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{4};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{5};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{7};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{8};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 10);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{10};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 11);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{11};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 13);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{13};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 16);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{16};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 16);
    }     
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 17);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{17};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 17);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 19);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 9);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 19);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 19);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 19);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 19);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 19);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{19};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 19);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 32);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 16);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 10);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 15);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 32);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 32);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 32);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 32);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{32};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 32);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 63);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 31);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 21);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 15);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 12);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 15);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 12);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 31);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 63);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 63);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 63);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{63};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 63);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 64);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 32);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 21);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 16);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 12);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 4);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 9);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 12);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 64);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 64);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{64};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 64);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 127);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 63);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 42);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 31);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 25);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 18);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 15);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 12);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 11);
        assert(rem.m_value[0] == 6);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(rem.m_value[0] == 10);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 15);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 13);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 31);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 63);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 127);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{127};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 127);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 128);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 64);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 42);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 32);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 25);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 18);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 16);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 12);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 11);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(rem.m_value[0] == 11);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 9);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 14);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{128};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 128);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{0};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{1};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 255);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{2};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{3};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 85);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{4};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 63);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{5};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 51);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{7};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 36);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{8};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 31);
        assert(rem.m_value[0] == 7);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{10};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 25);
        assert(rem.m_value[0] == 5);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{11};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 23);
        assert(rem.m_value[0] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{13};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 19);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{16};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 15);
        assert(rem.m_value[0] == 15);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{17};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 15);
        assert(rem.m_value[0] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{19};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 13);
        assert(rem.m_value[0] == 8);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{32};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 31);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{63};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 3);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{64};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 63);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{127};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{128};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 127);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Bin> f1{255};
        Format<N, Bin> f2{255};
        Format<N, Bin> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    ////
#ifdef EXTENDED_TEST
    {
        for(std::size_t i = 1; i < 256; ++i)
        {
            for(std::size_t j = 2; j < 256; ++j)
            {
                typedef std::size_t SizeType;
                typedef test::math::integer::div::Flag DivFlagType;
                constexpr SizeType N = 1;
                SizeType v;
                Format<N, Bin> f1{i};
                Format<N, Bin> f2{j};
                Format<N, Bin> rem{0};
                DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

                std::uint8_t div = i / j;
                std::uint8_t mod = i % j;

                if (c1 != DivFlagType::Ok || f1.m_value[0] != div || 
                    rem.m_value[0] != mod)
                {
                    printf("f1 : %d, f2 : %d, div : %d, mod : %d, "
                        "status : %d, res_div %d, res_mod : %d\n", 
                            i, j, div, mod, c1, f1.m_value[0], rem.m_value[0]);
                }
                assert(c1 == DivFlagType::Ok);
                assert(f1.m_value[0] == div);
                assert(rem.m_value[0] == mod);
            }
        }
    }
#endif //EXTENDED_TEST
    ////
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{0, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{1, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{1, 0, 0, 0};
        Format<N, Bin> f2{1, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 1, 0, 0};
        Format<N, Bin> f2{1, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 1, 0};
        Format<N, Bin> f2{1, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 1};
        Format<N, Bin> f2{1, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 1);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{1, 1, 1, 1};
        Format<N, Bin> f2{1, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 1);
        assert(f1.m_value[1] == 1);
        assert(f1.m_value[2] == 1);
        assert(f1.m_value[3] == 1);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{2, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 0, 0, 0};
        Format<N, Bin> f2{2, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        Format<N, Bin> f2{2, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 128);
        assert(f1.m_value[1] == 127);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{2, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 128);
        assert(f1.m_value[2] == 127);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{2, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 128);
        assert(f1.m_value[3] == 127);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{2, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 255);
        assert(f1.m_value[2] == 255);
        assert(f1.m_value[3] == 127);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{0, 0, 2, 2};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 2);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        Format<N, Bin> f2{2, 2, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{2, 2, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 127);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 2);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{2, 2, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 255);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 127);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{2, 2, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 128);
        assert(f1.m_value[2] == 127);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{2, 2, 2, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{2, 2, 2, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 127);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 2);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{2, 2, 2, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 128);
        assert(f1.m_value[1] == 127);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 255);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{2, 2, 2, 2};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{2, 2, 2, 2};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 127);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 1);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 0};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 0, 0, 0};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 85);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 85);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 85);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 85);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 85);
        assert(f1.m_value[1] == 85);
        assert(f1.m_value[2] == 85);
        assert(f1.m_value[3] == 85);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 255, 0, 0};
        Format<N, Bin> f2{3, 3, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 84);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 4);
        assert(rem.m_value[1] == 2);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{3, 3, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 171);
        assert(f1.m_value[1] == 84);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 255);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{3, 3, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 84);
        assert(f1.m_value[1] == 171);
        assert(f1.m_value[2] == 84);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 4);
        assert(rem.m_value[1] == 2);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{3, 3, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 85);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 85);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 255, 0};
        Format<N, Bin> f2{3, 3, 3, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 84);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 4);
        assert(rem.m_value[1] == 3);
        assert(rem.m_value[2] == 2);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{3, 3, 3, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 171);
        assert(f1.m_value[1] == 84);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 255);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{3, 3, 3, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 85);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 255);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 0, 0, 255};
        Format<N, Bin> f2{3, 3, 3, 3};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 84);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 4);
        assert(rem.m_value[1] == 3);
        assert(rem.m_value[2] == 3);
        assert(rem.m_value[3] == 2);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{255, 255, 255, 255};
        Format<N, Bin> f2{3, 3, 3, 3};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 85);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 4;
        SizeType v;
        Format<N, Bin> f1{0, 172, 0, 172};
        Format<N, Bin> f2{3, 0, 0, 0};
        Format<N, Bin> rem{0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);
        
        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 170);
        assert(f1.m_value[1] == 142);
        assert(f1.m_value[2] == 85);
        assert(f1.m_value[3] == 57);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
    } 

    ////
#ifdef EXTENDED_TEST
    {
        constexpr int N_F1 = 9;
        std::uint8_t f1_pattern[N_F1][4]{
            1, 0, 0, 0,
            0, 1, 0, 0,
            1, 1, 0, 0,
            0, 0, 1, 0,
            1, 0, 1, 0,
            0, 0, 0, 1,
            0, 1, 0, 1,
            0, 0, 1, 1,
            1, 1, 1, 1
        };
        std::uint8_t n_f2_of_f1[N_F1][1]
        {
            1,
            2,
            2,
            3,
            3,
            4,
            4,
            4,
            4
        };
        constexpr int N_F2 = 5;
        std::uint8_t f2_pattern[N_F2][4]{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1,
            1, 1, 1, 1
        };

        for(std::size_t i = 0; i <= 255; ++i)
        {
            for(std::size_t j = 2; j <= i; ++j)
            {
                for (int k = 0; k < N_F1; ++k)
                {
                    for(int l = 0; l < (int)n_f2_of_f1[k][0]; ++l)
                    {
                        typedef std::size_t SizeType;
                        typedef test::math::integer::div::Flag DivFlagType;
                        constexpr SizeType N = 4;
                        SizeType v;
                        std::uint8_t f1_va[N] {
                            (std::uint8_t)(i * f1_pattern[k][0]),
                            (std::uint8_t)(i * f1_pattern[k][1]),
                            (std::uint8_t)(i * f1_pattern[k][2]),
                            (std::uint8_t)(i * f1_pattern[k][3])
                        };
                        std::uint8_t f2_va[N] {
                            (std::uint8_t)(j * f2_pattern[l][0]),
                            (std::uint8_t)(j * f2_pattern[l][1]),
                            (std::uint8_t)(j * f2_pattern[l][2]),
                            (std::uint8_t)(j * f2_pattern[l][3])
                        };

                        Format<N, Bin> f1{f1_va[0], f1_va[1], 
                            f1_va[2], f1_va[3]};
                        Format<N, Bin> f2{f2_va[0], f2_va[1], 
                            f2_va[2], f2_va[3]};
                        Format<N, Bin> rem{0, 0, 0, 0};

                        DivFlagType c1 = test::math::integer::Division(f1, 
                            f2, &rem);

                        std::uint32_t f1_v = 0;
                        std::uint32_t f2_v = 0;
                        for (int i = 1; i <= N; ++i)
                        {
                            f1_v <<= 8;
                            f2_v <<= 8;
                            f1_v |= f1_va[N - i];
                            f2_v |= f2_va[N - i];
                        }

                        std::uint32_t div = f1_v / f2_v;
                        std::uint32_t mod = f1_v % f2_v;

                        std::uint8_t div_res[N] {
                            (std::uint8_t)(div & 0x000000FF),
                            (std::uint8_t)((div & 0x0000FF00) >> 8),
                            (std::uint8_t)((div & 0x00FF0000) >> 16),
                            (std::uint8_t)((div & 0xFF000000) >> 24)
                        };
                        std::uint8_t mod_res[N] {
                            (std::uint8_t)(mod & 0x000000FF),
                            (std::uint8_t)((mod & 0x0000FF00) >> 8),
                            (std::uint8_t)((mod & 0x00FF0000) >> 16),
                            (std::uint8_t)((mod & 0xFF000000) >> 24)
                        };


                        if (c1 != DivFlagType::Ok || 
                            f1.m_value[0] != div_res[0] || 
                            f1.m_value[1] != div_res[1] || 
                            f1.m_value[2] != div_res[2] || 
                            f1.m_value[3] != div_res[3] || 
                            rem.m_value[0] != mod_res[0] || 
                            rem.m_value[1] != mod_res[1] || 
                            rem.m_value[2] != mod_res[2] || 
                            rem.m_value[3] != mod_res[3])
                        {
                            printf("f1 : [%d, %d, %d, %d](%lu), "
                                "f2 : [%d, %d, %d, %d](%lu), div : %lu, "
                                "mod : %lu, "
                                "status : %d, res_div : [%d, %d, %d, %d], "
                                "res_mod : [%d, %d, %d, %d]\n", 
                                f1_va[0], f1_va[1], f1_va[2], f1_va[3], f1_v, 
                                f2_va[0], f2_va[1], f2_va[2], f2_va[3], f2_v, 
                                div, mod, c1, f1.m_value[0], f1.m_value[1], 
                                f1.m_value[2], f1.m_value[3], rem.m_value[0],
                                rem.m_value[1], rem.m_value[2], 
                                rem.m_value[3]);
                        }
                        assert(c1 == DivFlagType::Ok);
                        assert(f1.m_value[0] == div_res[0]);
                        assert(f1.m_value[1] == div_res[1]);
                        assert(f1.m_value[2] == div_res[2]);
                        assert(f1.m_value[3] == div_res[3]);
                        assert(rem.m_value[0] == mod_res[0]);
                        assert(rem.m_value[1] == mod_res[1]);
                        assert(rem.m_value[2] == mod_res[2]);
                        assert(rem.m_value[3] == mod_res[3]);
                    }
                }
            }
        }
    }
#endif //EXTENDED_TEST
    ////
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{0};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 5);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 6);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 7);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 8);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{1};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 9);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{2};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{3};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{4};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 2);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{5};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{6};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{7};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{8};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{0};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{1};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{2};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 2);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{3};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 3);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{4};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 4);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{5};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 5);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{6};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 6);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{7};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 7);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{8};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(rem.m_value[0] == 8);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 1;
        SizeType v;
        Format<N, Dec> f1{9};
        Format<N, Dec> f2{9};
        Format<N, Dec> rem{0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 1);
        assert(rem.m_value[0] == 0);
    }
    ////
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByZero);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 9);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{1, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::DivByOne);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 9);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 1, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 1, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 1, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 1, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 9);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 9);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 9);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 8);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 1);
        assert(rem.m_value[4] == 1);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{1, 1, 1, 1, 1, 1};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 5);
        assert(f1.m_value[3] == 4);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 5);
        assert(f1.m_value[4] == 4);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 5);
        assert(f1.m_value[5] == 4);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{2, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 9);
        assert(f1.m_value[5] == 4);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 5);
        assert(f1.m_value[3] == 4);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 5);
        assert(f1.m_value[4] == 4);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 2, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 9);
        assert(f1.m_value[4] == 4);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 5);
        assert(f1.m_value[3] == 4);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 2, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 9);
        assert(f1.m_value[3] == 4);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 1);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 5);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 2, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 9);
        assert(f1.m_value[2] == 4);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 1);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 1);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 5);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 2, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 9);
        assert(f1.m_value[1] == 4);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 1);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 9);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{0, 0, 0, 0, 0, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 9);
        assert(rem.m_value[5] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 0, 0, 0, 0, 0};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 9);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 9, 0, 0, 0, 0};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 9);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 9, 0, 0, 0};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 9);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 9, 0, 0};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 9);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 9, 0};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 0);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 0);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 9);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 0, 0, 9};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 1);
        assert(rem.m_value[4] == 1);
        assert(rem.m_value[5] == 0);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{9, 9, 9, 9, 9, 9};
        Format<N, Dec> f2{2, 2, 2, 2, 2, 2};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 4);
        assert(f1.m_value[1] == 0);
        assert(f1.m_value[2] == 0);
        assert(f1.m_value[3] == 0);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 1);
        assert(rem.m_value[1] == 1);
        assert(rem.m_value[2] == 1);
        assert(rem.m_value[3] == 1);
        assert(rem.m_value[4] == 1);
        assert(rem.m_value[5] == 1);
    }
    {
        typedef std::size_t SizeType;
        typedef test::math::integer::div::Flag DivFlagType;
        constexpr SizeType N = 6;
        SizeType v;
        Format<N, Dec> f1{0, 0, 0, 8, 0, 0};
        Format<N, Dec> f2{6, 0, 0, 0, 0, 0};
        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};
        DivFlagType c1 = test::math::integer::Division(f1, f2, &rem);

        assert(c1 == DivFlagType::Ok);
        assert(f1.m_value[0] == 3);
        assert(f1.m_value[1] == 3);
        assert(f1.m_value[2] == 3);
        assert(f1.m_value[3] == 1);
        assert(f1.m_value[4] == 0);
        assert(f1.m_value[5] == 0);
        assert(rem.m_value[0] == 2);
        assert(rem.m_value[1] == 0);
        assert(rem.m_value[2] == 0);
        assert(rem.m_value[3] == 0);
        assert(rem.m_value[4] == 0);
        assert(rem.m_value[5] == 0);
    }
    ////
#ifdef EXTENDED_TEST
    {
        constexpr int N_F1 = 12;
        std::uint8_t f1_pattern[N_F1][6]{
            1, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0,
            2, 1, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0,
            2, 0, 1, 0, 0, 0,
            0, 0, 0, 1, 0, 0,
            0, 2, 0, 1, 0, 0,
            0, 0, 0, 0, 1, 0,
            0, 0, 2, 0, 1, 0,
            0, 0, 0, 0, 0, 1,
            0, 0, 0, 2, 0, 1,
            1, 2, 1, 3, 2, 4
        };
        std::uint8_t n_f2_of_f1[N_F1][1]
        {
            1,
            2,
            2,
            3,
            3,
            4,
            4,
            5,
            5,
            6,
            6,
            6
        };
        constexpr int N_F2 = 7;
        std::uint8_t f2_pattern[N_F2][6]{
            1, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0,
            0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1,
            1, 1, 1, 1, 1, 1
        };

        for(std::size_t i = 0; i <= 9; ++i)
        {
            for(std::size_t j = 2; j <= i; ++j)
            {
                for (int k = 0; k < N_F1; ++k)
                {
                    for(int l = 0; l < (int)n_f2_of_f1[k][0]; ++l)
                    {
                        typedef std::size_t SizeType;
                        typedef test::math::integer::div::Flag DivFlagType;
                        constexpr SizeType N = 6;
                        SizeType v;
                        std::uint8_t f1_va[N] {
                            (std::uint8_t)((i * f1_pattern[k][0]) % 10),
                            (std::uint8_t)((i * f1_pattern[k][1]) % 10),
                            (std::uint8_t)((i * f1_pattern[k][2]) % 10),
                            (std::uint8_t)((i * f1_pattern[k][3]) % 10),
                            (std::uint8_t)((i * f1_pattern[k][4]) % 10),
                            (std::uint8_t)((i * f1_pattern[k][5]) % 10)
                        };
                        std::uint8_t f2_va[N] {
                            (std::uint8_t)(j * f2_pattern[l][0]),
                            (std::uint8_t)(j * f2_pattern[l][1]),
                            (std::uint8_t)(j * f2_pattern[l][2]),
                            (std::uint8_t)(j * f2_pattern[l][3]),
                            (std::uint8_t)(j * f2_pattern[l][4]),
                            (std::uint8_t)(j * f2_pattern[l][5])
                        };

                        Format<N, Dec> f1{f1_va[0], f1_va[1], f1_va[2], 
                            f1_va[3], f1_va[4], f1_va[5]};
                        Format<N, Dec> f2{f2_va[0], f2_va[1], f2_va[2], 
                            f2_va[3], f2_va[4], f2_va[5]};
                        Format<N, Dec> rem{0, 0, 0, 0, 0, 0};

                        DivFlagType c1 = test::math::integer::Division(f1, 
                            f2, &rem);

                        std::uint32_t f1_v = 0;
                        std::uint32_t f2_v = 0;
                        for (int i = 1; i <= N; ++i)
                        {
                            f1_v *= 10;
                            f2_v *= 10;
                            f1_v += f1_va[N - i];
                            f2_v += f2_va[N - i];
                        }

                        std::uint32_t div = f1_v / f2_v;
                        std::uint32_t mod = f1_v % f2_v;

                        std::uint8_t div_res[N]{0, 0, 0, 0, 0, 0};
                        std::uint8_t mod_res[N]{0, 0, 0, 0, 0, 0};
                        std::uint32_t div_c = div;
                        std::uint32_t mod_c = mod;
                        for (int i = 0; i < N; i++)
                        {
                            div_res[i] = (std::uint8_t) (div_c % 10);
                            div_c /= 10;
                            mod_res[i] = (std::uint8_t) (mod_c % 10);
                            mod_c /= 10;
                        }


                        if (c1 != DivFlagType::Ok || 
                            f1.m_value[0] != div_res[0] || 
                            f1.m_value[1] != div_res[1] || 
                            f1.m_value[2] != div_res[2] || 
                            f1.m_value[3] != div_res[3] || 
                            f1.m_value[4] != div_res[4] || 
                            f1.m_value[4] != div_res[4] || 
                            rem.m_value[0] != mod_res[0] || 
                            rem.m_value[1] != mod_res[1] || 
                            rem.m_value[2] != mod_res[2] || 
                            rem.m_value[3] != mod_res[3] || 
                            rem.m_value[4] != mod_res[4] || 
                            rem.m_value[5] != mod_res[5])
                        {
                            printf("f1 : [%d, %d, %d, %d, %d, %d](%lu), "
                                "f2 : [%d, %d, %d, %d, %d, %d](%lu), "
                                "div : %lu, "
                                "mod : %lu, "
                                "status : %d, "
                                "res_div : [%d, %d, %d, %d, %d, %d], "
                                "res_mod : [%d, %d, %d, %d, %d, %d]\n", 
                                f1_va[0], f1_va[1], f1_va[2], f1_va[3], 
                                f1_va[4], f1_va[5], f1_v, 
                                f2_va[0], f2_va[1], f2_va[2], f2_va[3], 
                                f2_va[4], f2_va[5], f2_v, 
                                div, mod, c1, f1.m_value[0], f1.m_value[1], 
                                f1.m_value[2], f1.m_value[3], f1.m_value[4], 
                                f1.m_value[5], rem.m_value[0], rem.m_value[1], 
                                rem.m_value[2], rem.m_value[3], rem.m_value[4],
                                rem.m_value[5]);
                        }
                        assert(c1 == DivFlagType::Ok);
                        assert(f1.m_value[0] == div_res[0]);
                        assert(f1.m_value[1] == div_res[1]);
                        assert(f1.m_value[2] == div_res[2]);
                        assert(f1.m_value[3] == div_res[3]);
                        assert(f1.m_value[4] == div_res[4]);
                        assert(f1.m_value[5] == div_res[5]);
                        assert(rem.m_value[0] == mod_res[0]);
                        assert(rem.m_value[1] == mod_res[1]);
                        assert(rem.m_value[2] == mod_res[2]);
                        assert(rem.m_value[3] == mod_res[3]);
                        assert(rem.m_value[4] == mod_res[4]);
                        assert(rem.m_value[5] == mod_res[5]);
                    }
                }
            }
        }
    }
#endif //EXTENDED_TEST

    return 0;
}
