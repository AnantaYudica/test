#include "test/out/print/fp/Integer.h"

#include <cassert>
#include <cstring>
#include <cwchar>

int main()
{
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        if (cstr1[2] == '3') assert(cstr1[3] >= '5' && cstr1[3] <= '9');
        else assert(cstr1[3] == '0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        if (cstr2[2] == '3') assert(cstr2[3] >= '5' && cstr2[3] <= '9');
        else assert(cstr2[3] == '0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1[2] == '4' || cstr1[2] == '3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2[2] == '4' || cstr2[2] == '3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1[1] == '1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2[1] == '1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3[i + 1] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == '3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == '3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == '1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == '1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<char, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == '0');
        assert(cstr3[i] == '1');
        assert(cstr3.Size() == 10);
    }
    /// WCHAR
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            true>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        if (cstr1[2] == L'3') assert(cstr1[3] >= L'5' && cstr1[3] <= L'9');
        else assert(cstr1[3] == L'0');
        assert(cstr1.Size() == 4);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        if (cstr2[2] == L'3') assert(cstr2[3] >= L'5' && cstr2[3] <= L'9');
        else assert(cstr2[3] == L'0');
        assert(cstr2.Size() == 4);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1[2] == L'4' || cstr1[2] == L'3');
        assert(cstr1.Size() == 3);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2[2] == L'4' || cstr2[2] == L'3');
        assert(cstr2.Size() == 3);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
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
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1[1] == L'1');
        assert(cstr1.Size() == 2);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2[1] == L'1');
        assert(cstr2.Size() == 2);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 2); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3[i + 1] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 1);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, false>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'0');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>());
        assert(cstr1[0] == L'3');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 1);
        assert(cstr2[0] == L'3');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<10, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'3');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr1 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>());
        assert(cstr1[0] == L'1');
        assert(cstr1.Size() == 1);

        auto cstr2 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 1);
        assert(cstr2[0] == L'1');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Integer<wchar_t, 
            false>(fp1.GetBase<2, true>(), 10);
        std::size_t i = 0;
        for(; i < (10 - 1); ++i)
            assert(cstr3[i] == L'0');
        assert(cstr3[i] == L'1');
        assert(cstr3.Size() == 10);
    }
    return 0;
}