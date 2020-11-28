#include "test/out/print/fp/Integer.h"

#include <cassert>
#include <cstring>
#include <cwchar>

int main()
{
    {
        test::FloatingPoint<float> fp1{3.0f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{3.4f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{3.5f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{3.9f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{0.3f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{0.34f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{0.35f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{0.39f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<float> fp1{0.3f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<float> fp1{0.34f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<float> fp1{0.35f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<float> fp1{0.39f};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<float, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        if (is_round) assert(int1 == 2);
        else assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }

    // double Round
    {
        test::FloatingPoint<double> fp1{3.0};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{3.4};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{3.5};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{3.9};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{0.3};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{0.34};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{0.35};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{0.39};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<double> fp1{0.3};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<double> fp1{0.34};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<double> fp1{0.35};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<double> fp1{0.39};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        if (is_round) assert(int1 == 2);
        else assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    
    // long double Round
    
    {
        test::FloatingPoint<long double> fp1{3.0L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{3.4L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{3.5L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{3.9L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, false>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{0.3L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{0.34L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{0.35L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{0.39L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 10>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 0);
        if (is_round) assert(int1 == 4);
        else assert(int1 == 3);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 1);
        assert(int2 == 3);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<10, true>(), 10);
        assert(int3 == 3);
    }
    {
        test::FloatingPoint<long double> fp1{0.3L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<long double> fp1{0.34L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<long double> fp1{0.35L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }
    {
        test::FloatingPoint<long double> fp1{0.39L};
        const auto is_round = 
            test::def::out::cstr::fp::Precision::IsRound<long double, 2>();
        auto int1 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 0);
        if (is_round) assert(int1 == 2);
        else assert(int1 == 1);
        
        auto int2 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 1);
        assert(int2 == 1);
            
        auto int3 = test::out::print::fp::Integer::
            Round(fp1.GetBase<2, true>(), 10);
        assert(int3 == 1);
    }

    // float CStr

    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr3[i + 2] == '3');
        if (cstr3[i + 2] == '3') 
            assert(cstr3[i + 3] >= '5' && cstr3[i + 3] <= '9');
        else assert(cstr3[i + 3] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr2[i + 2] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr3[i + 2] == '3');
        if (cstr3[i + 2] == '3') 
            assert(cstr3[i + 3] >= '5' && cstr3[i + 3] <= '9');
        else assert(cstr3[i + 3] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr2[i + 2] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr3[i + 2] == '3');
        if (cstr3[i + 2] == '3') 
            assert(cstr3[i + 3] >= '5' && cstr3[i + 3] <= '9');
        else assert(cstr3[i + 3] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr2[i + 2] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr3[i + 2] == '3');
        if (cstr3[i + 2] == '3') 
            assert(cstr3[i + 3] >= '5' && cstr3[i + 3] <= '9');
        else assert(cstr3[i + 3] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr2[i + 2] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr3[i + 2] == '3');
        if (cstr3[i + 2] == '3') 
            assert(cstr3[i + 3] >= '5' && cstr3[i + 3] <= '9');
        else assert(cstr3[i + 3] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr2[i + 2] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr3[i + 2] == '3');
        if (cstr3[i + 2] == '3') 
            assert(cstr3[i + 3] >= '5' && cstr3[i + 3] <= '9');
        else assert(cstr3[i + 3] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3[i + 2] == '4' || cstr2[i + 2] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    /// WCHAR
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr3[i + 2] == L'3');
        if (cstr3[i + 2] == L'3') 
            assert(cstr3[i + 3] >= L'5' && cstr3[i + 3] <= L'9');
        else assert(cstr3[i + 3] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr2[i + 2] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr3[i + 2] == L'3');
        if (cstr3[i + 2] == L'3') 
            assert(cstr3[i + 3] >= L'5' && cstr3[i + 3] <= L'9');
        else assert(cstr3[i + 3] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr2[i + 2] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr3[i + 2] == L'3');
        if (cstr3[i + 2] == L'3') 
            assert(cstr3[i + 3] >= L'5' && cstr3[i + 3] <= L'9');
        else assert(cstr3[i + 3] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr2[i + 2] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, true>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr3[i + 2] == L'3');
        if (cstr3[i + 2] == L'3') 
            assert(cstr3[i + 3] >= L'5' && cstr3[i + 3] <= L'9');
        else assert(cstr3[i + 3] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr2[i + 2] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr3[i + 2] == L'3');
        if (cstr3[i + 2] == L'3') 
            assert(cstr3[i + 3] >= L'5' && cstr3[i + 3] <= L'9');
        else assert(cstr3[i + 3] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr2[i + 2] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 4); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr3[i + 2] == L'3');
        if (cstr3[i + 2] == L'3') 
            assert(cstr3[i + 3] >= L'5' && cstr3[i + 3] <= L'9');
        else assert(cstr3[i + 3] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3[i + 2] == L'4' || cstr2[i + 2] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        if (cstr1[1] == '4') assert(cstr1[2] >= '5' && cstr1[2] <= '9');
        else assert(cstr1[2] == '0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        if (cstr2[1] == '4') assert(cstr2[2] >= '5' && cstr2[2] <= '9');
        else assert(cstr2[2] == '0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        if (cstr3[i + 1] == '4') assert(cstr3[i + 2] >= '5' && 
            cstr3[i + 2] <= '9');
        else assert(cstr3[i + 2] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        if (cstr1[1] == '4') assert(cstr1[2] >= '5' && cstr1[2] <= '9');
        else assert(cstr1[2] == '0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        if (cstr2[1] == '4') assert(cstr2[2] >= '5' && cstr2[2] <= '9');
        else assert(cstr2[2] == '0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        if (cstr3[i + 1] == '4') assert(cstr3[i + 2] >= '5' && 
            cstr3[i + 2] <= '9');
        else assert(cstr3[i + 2] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    /// long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        if (cstr1[1] == '4') assert(cstr1[2] >= '5' && cstr1[2] <= '9');
        else assert(cstr1[2] == '0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        if (cstr2[1] == '4') assert(cstr2[2] >= '5' && cstr2[2] <= '9');
        else assert(cstr2[2] == '0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        if (cstr3[i + 1] == '4') assert(cstr3[i + 2] >= '5' && 
            cstr3[i + 2] <= '9');
        else assert(cstr3[i + 2] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    /// double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    // long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    /// double
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    /// long double
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        if (cstr1[1] == '4') assert(cstr1[2] >= '5' && cstr1[2] <= '9');
        else assert(cstr1[2] == '0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        if (cstr2[1] == '4') assert(cstr2[2] >= '5' && cstr2[2] <= '9');
        else assert(cstr2[2] == '0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        if (cstr3[i + 1] == '4') assert(cstr3[i + 2] >= '5' && 
            cstr3[i + 2] <= '9');
        else assert(cstr3[i + 2] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        if (cstr1[1] == '4') assert(cstr1[2] >= '5' && cstr1[2] <= '9');
        else assert(cstr1[2] == '0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        if (cstr2[1] == '4') assert(cstr2[2] >= '5' && cstr2[2] <= '9');
        else assert(cstr2[2] == '0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        if (cstr3[i + 1] == '4') assert(cstr3[i + 2] >= '5' && 
            cstr3[i + 2] <= '9');
        else assert(cstr3[i + 2] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    /// long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        if (cstr1[1] == '4') assert(cstr1[2] >= '5' && cstr1[2] <= '9');
        else assert(cstr1[2] == '0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        if (cstr2[1] == '4') assert(cstr2[2] >= '5' && cstr2[2] <= '9');
        else assert(cstr2[2] == '0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        if (cstr3[i + 1] == '4') assert(cstr3[i + 2] >= '5' && 
            cstr3[i + 2] <= '9');
        else assert(cstr3[i + 2] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '5' || cstr1[1] == '4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '5' || cstr2[1] == '4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '5' || cstr3[i + 1] == '4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    /// double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    // long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == '4');
        else assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == '4');
        else assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == '4');
        else assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    /// double
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    /// long double
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == '2');
        else assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == '2');
        else assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == '2');
        else assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<char, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    
    /// wchar_t
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        if (cstr1[1] == L'4') assert(cstr1[2] >= L'5' && cstr1[2] <= L'9');
        else assert(cstr1[2] == L'0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        if (cstr2[1] == L'4') assert(cstr2[2] >= L'5' && cstr2[2] <= L'9');
        else assert(cstr2[2] == L'0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        if (cstr3[i + 1] == L'4') assert(cstr3[i + 2] >= L'5' && 
            cstr3[i + 2] <= L'9');
        else assert(cstr3[i + 2] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        if (cstr1[1] == L'4') assert(cstr1[2] >= L'5' && cstr1[2] <= L'9');
        else assert(cstr1[2] == L'0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        if (cstr2[1] == L'4') assert(cstr2[2] >= L'5' && cstr2[2] <= L'9');
        else assert(cstr2[2] == L'0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        if (cstr3[i + 1] == L'4') assert(cstr3[i + 2] >= L'5' && 
            cstr3[i + 2] <= L'9');
        else assert(cstr3[i + 2] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    /// long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        if (cstr1[1] == L'4') assert(cstr1[2] >= L'5' && cstr1[2] <= L'9');
        else assert(cstr1[2] == L'0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        if (cstr2[1] == L'4') assert(cstr2[2] >= L'5' && cstr2[2] <= L'9');
        else assert(cstr2[2] == L'0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        if (cstr3[i + 1] == L'4') assert(cstr3[i + 2] >= L'5' && 
            cstr3[i + 2] <= L'9');
        else assert(cstr3[i + 2] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    /// double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    // long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    /// double
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    /// long double
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        if (cstr1[1] == L'4') assert(cstr1[2] >= L'5' && cstr1[2] <= L'9');
        else assert(cstr1[2] == L'0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        if (cstr2[1] == L'4') assert(cstr2[2] >= L'5' && cstr2[2] <= L'9');
        else assert(cstr2[2] == L'0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        if (cstr3[i + 1] == L'4') assert(cstr3[i + 2] >= L'5' && 
            cstr3[i + 2] <= L'9');
        else assert(cstr3[i + 2] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        if (cstr1[1] == L'4') assert(cstr1[2] >= L'5' && cstr1[2] <= L'9');
        else assert(cstr1[2] == L'0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        if (cstr2[1] == L'4') assert(cstr2[2] >= L'5' && cstr2[2] <= L'9');
        else assert(cstr2[2] == L'0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        if (cstr3[i + 1] == L'4') assert(cstr3[i + 2] >= L'5' && 
            cstr3[i + 2] <= L'9');
        else assert(cstr3[i + 2] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    /// long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        if (cstr1[1] == L'4') assert(cstr1[2] >= L'5' && cstr1[2] <= L'9');
        else assert(cstr1[2] == L'0');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        if (cstr2[1] == L'4') assert(cstr2[2] >= L'5' && cstr2[2] <= L'9');
        else assert(cstr2[2] == L'0');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 3); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        if (cstr3[i + 1] == L'4') assert(cstr3[i + 2] >= L'5' && 
            cstr3[i + 2] <= L'9');
        else assert(cstr3[i + 2] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'5' || cstr1[1] == L'4');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'5' || cstr2[1] == L'4');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'5' || cstr3[i + 1] == L'4');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0);
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, false>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    /// double
    
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    // long double
    
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr1[0] == L'4');
        else assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr2[0] == L'4');
        else assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<10, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 10>())
            assert(cstr3[i] == L'4');
        else assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    
    ///
    {
        test::FloatingPoint<float> fp1{350.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{35.0f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.50f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<float, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0350f};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    /// double
    {
        test::FloatingPoint<double> fp1{350.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{35.0};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.50};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0350};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    /// long double
    {
        test::FloatingPoint<long double> fp1{350.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{35.0L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.50L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr1[0] == L'2');
        else assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr2[0] == L'2');
        else assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        if (test::def::out::cstr::fp::Precision::IsRound<long double, 2>())
            assert(cstr3[i] == L'2');
        else assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0350L};
        auto cstr1 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0, 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    return 0;
}