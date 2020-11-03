#include "test/out/print/fp/Precision.h"

#include <cassert>
#include <cstring>

#include <cmath>

int main()
{
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr1[0] == '0' || (cstr1[0] >= '5' && cstr1[0] <= '9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == '0' || (cstr3[0] >= '5' && cstr3[0] <= '9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == '0' || (cstr4[0] >= '5' && cstr4[0] <= '9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == '0' || (cstr5[0] >= '5' && cstr5[0] <= '9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0' || (cstr[0] >= '5' && cstr[0] <= '9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == '0' || (cstr3[0] >= '5' && cstr3[0] <= '9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == '0' || (cstr4[0] >= '5' && cstr4[0] <= '9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == '0' || (cstr5[0] >= '5' && cstr5[0] <= '9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '4' || cstr[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0' || (cstr[0] >= '5' && cstr[0] <= '9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == '0' || (cstr3[0] >= '5' && cstr3[0] <= '9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == '0' || (cstr4[0] >= '5' && cstr4[0] <= '9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == '0' || (cstr5[0] >= '5' && cstr5[0] <= '9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0' || (cstr[0] >= '5' && cstr[0] <= '9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == '0' || (cstr3[0] >= '5' && cstr3[0] <= '9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == '0' || (cstr4[0] >= '5' && cstr4[0] <= '9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == '0' || (cstr5[0] >= '5' && cstr5[0] <= '9'));
        assert(cstr5.Size() == 100);
        
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '4' || cstr[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0' || (cstr[0] >= '5' && cstr[0] <= '9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == '0' || (cstr3[0] >= '5' && cstr3[0] <= '9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == '0' || (cstr4[0] >= '5' && cstr4[0] <= '9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == '0' || (cstr5[0] >= '5' && cstr5[0] <= '9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0' || (cstr[0] >= '5' && cstr[0] <= '9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == '0' || (cstr3[0] >= '5' && cstr3[0] <= '9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == '0' || (cstr4[0] >= '5' && cstr4[0] <= '9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == '0' || (cstr5[0] >= '5' && cstr5[0] <= '9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '4' || cstr[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '4' || cstr[0] == '3');
        if (cstr[0] == '3') assert(cstr[1] >= '5' && cstr[1] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '3');
        assert(cstr[1] == '1');
        assert(cstr[2] == '4' || cstr[2] == '3');
        if (cstr[2] == '3') assert(cstr[3] >= '5' && cstr[3] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == '0');
        assert(cstr[1] == '3');
        assert(cstr[2] == '1');
        assert(cstr[3] == '4' || cstr[3] == '3');
        if (cstr[3] == '3') assert(cstr[4] >= '5' && cstr[4] <= '9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>());
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == '1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == '1');
        assert(cstr[1] == '4' || cstr[1] == '3');
        if (cstr[1] == '3') assert(cstr[2] >= '5' && cstr[2] <= '9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'a');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'a');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'a');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == 'f');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'f');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'f');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'f');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'e');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'e');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'e');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'a');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'a');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'a');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == 'f');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'f');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'f');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'f');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'e');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'e');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'e');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'a');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'a');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'a');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == 'f');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'f');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'f');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'f');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'e');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'e');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'e');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == 'F');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'F');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'F');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == 'F');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'F');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'F');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == 'F');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'F');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'F');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '8');
        assert(cstr[1] == '8');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '8');
        assert(cstr4[1] == '8');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '8');
        assert(cstr5[1] == '8');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '3');
        assert(cstr[1] == 'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '3');
        assert(cstr4[1] == 'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '3');
        assert(cstr5[1] == 'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == 'F');
        assert(cstr[1] == '6');
        assert(cstr[2] == '6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == 'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == 'F');
        assert(cstr4[1] == '6');
        assert(cstr4[2] == '6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == 'F');
        assert(cstr5[1] == '6');
        assert(cstr5[2] == '6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '9');
        assert(cstr[1] == '1');
        assert(cstr[2] == 'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '9');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == 'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '9');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == 'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '4');
        assert(cstr[1] == '1');
        assert(cstr[2] == '8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '4');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '4');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == '0');
        assert(cstr[1] == '1');
        assert(cstr[2] == '3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == '0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == '0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == '0');
        assert(cstr4[1] == '1');
        assert(cstr4[2] == '3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<char, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == '0');
        assert(cstr5[1] == '1');
        assert(cstr5[2] == '3');
        assert(cstr5.Size() == 100);
    }
    /// WCHAR
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr1 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr1[0] == L'0' || (cstr1[0] >= L'5' && cstr1[0] <= L'9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == L'0' || (cstr3[0] >= L'5' && cstr3[0] <= L'9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == L'0' || (cstr4[0] >= L'5' && cstr4[0] <= L'9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == L'0' || (cstr5[0] >= L'5' && cstr5[0] <= L'9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0' || (cstr[0] >= L'5' && cstr[0] <= L'9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == L'0' || (cstr3[0] >= L'5' && cstr3[0] <= L'9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == L'0' || (cstr4[0] >= L'5' && cstr4[0] <= L'9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == L'0' || (cstr5[0] >= L'5' && cstr5[0] <= L'9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0' || (cstr[0] >= L'5' && cstr[0] <= L'9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == L'0' || (cstr3[0] >= L'5' && cstr3[0] <= L'9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == L'0' || (cstr4[0] >= L'5' && cstr4[0] <= L'9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == L'0' || (cstr5[0] >= L'5' && cstr5[0] <= L'9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0' || (cstr[0] >= L'5' && cstr[0] <= L'9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == L'0' || (cstr3[0] >= L'5' && cstr3[0] <= L'9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == L'0' || (cstr4[0] >= L'5' && cstr4[0] <= L'9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == L'0' || (cstr5[0] >= L'5' && cstr5[0] <= L'9'));
        assert(cstr5.Size() == 100);
        
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0' || (cstr[0] >= L'5' && cstr[0] <= L'9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == L'0' || (cstr3[0] >= L'5' && cstr3[0] <= L'9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == L'0' || (cstr4[0] >= L'5' && cstr4[0] <= L'9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == L'0' || (cstr5[0] >= L'5' && cstr5[0] <= L'9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0' || (cstr[0] >= L'5' && cstr[0] <= L'9'));

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr3[0] == L'0' || (cstr3[0] >= L'5' && cstr3[0] <= L'9'));
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr4[0] == L'0' || (cstr4[0] >= L'5' && cstr4[0] <= L'9'));
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr5[0] == L'0' || (cstr5[0] >= L'5' && cstr5[0] <= L'9'));
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'4' || cstr[0] == L'3');
        if (cstr[0] == L'3') assert(cstr[1] >= L'5' && cstr[1] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'4' || cstr[2] == L'3');
        if (cstr[2] == L'3') assert(cstr[3] >= L'5' && cstr[3] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        
        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 1);
        assert(cstr[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 10);
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, false>(), 100);
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'3');
        assert(cstr[2] == L'1');
        assert(cstr[3] == L'4' || cstr[3] == L'3');
        if (cstr[3] == L'3') assert(cstr[4] >= L'5' && cstr[4] <= L'9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>());
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 1);
        assert(cstr[0] == L'1');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 10);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<10, true>(), 100);
        assert(cstr[0] == L'1');
        assert(cstr[1] == L'4' || cstr[1] == L'3');
        if (cstr[1] == L'3') assert(cstr[2] >= L'5' && cstr[2] <= L'9');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'a');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'a');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'a');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'f');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'f');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'f');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'f');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'e');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'e');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'e');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'a');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'a');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'a');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'f');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'f');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'f');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'f');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'e');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'e');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'e');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'a');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'a');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'a');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'f');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'f');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'f');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'f');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'e');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'e');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'e');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<float> fp1{3140.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{314.0f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{31.4f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'F');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'F');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'F');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{3.14f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<float> fp1{0.0314f};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'F');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'F');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'F');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<double> fp1{3140.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{314.0};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{31.4};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'F');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'F');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'F');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{3.14};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<double> fp1{0.0314};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    ///
    {
        test::FloatingPoint<long double> fp1{3140.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'8');
        assert(cstr[1] == L'8');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'8');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'8');
        assert(cstr4[1] == L'8');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'8');
        assert(cstr5[1] == L'8');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{314.0L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'3');
        assert(cstr[1] == L'A');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'3');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'3');
        assert(cstr4[1] == L'A');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'3');
        assert(cstr5[1] == L'A');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{31.4L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'F');
        assert(cstr[1] == L'6');
        assert(cstr[2] == L'6');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'F');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'F');
        assert(cstr4[1] == L'6');
        assert(cstr4[2] == L'6');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'F');
        assert(cstr5[1] == L'6');
        assert(cstr5[2] == L'6');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{3.14L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'9');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'E');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'9');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'9');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'E');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'9');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'E');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'4');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'8');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'4');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'4');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'8');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'4');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'8');
        assert(cstr5.Size() == 100);
    }
    {
        test::FloatingPoint<long double> fp1{0.0314L};
        auto cstr = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>());
        assert(cstr[0] == L'0');
        assert(cstr[1] == L'1');
        assert(cstr[2] == L'3');

        auto cstr2 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 0);
        assert(cstr2[0] == L'0');
        assert(cstr2.Size() == 1);

        auto cstr3 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 1);
        assert(cstr3[0] == L'0');
        assert(cstr3.Size() == 1);

        auto cstr4 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 10);
        assert(cstr4[0] == L'0');
        assert(cstr4[1] == L'1');
        assert(cstr4[2] == L'3');
        assert(cstr4.Size() == 10);

        auto cstr5 = test::out::print::fp::Precision::
            CStr<wchar_t, false>(fp1.GetBase<2, true>(), 100);
        assert(cstr5[0] == L'0');
        assert(cstr5[1] == L'1');
        assert(cstr5[2] == L'3');
        assert(cstr5.Size() == 100);
    }
    return 0;
}